package Jointure;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;

import javax.swing.JTextArea;

import Metier.Bloc;
import Metier.BlocMemoire;
import Metier.BlocPhysique;
import Metier.Table;
import Metier.TypeAttribut;

public abstract class Jointure {

	protected JTextArea sortieTexte = null;
	abstract public List<Bloc> Joindre(Table table1,Table table2, List<String> condition,JTextArea zone);
	
	protected List<String> MapToList(LinkedHashMap<String,Object> tuple){
		List<String> result = new ArrayList<String>();
		
		for(Object o : tuple.values()){
			result.add(o.toString());
		}
		
		return result;
	}
	
	protected LinkedHashMap<String,Object> JoindreTuple(LinkedHashMap<String,Object> tuple1, LinkedHashMap<String,Object> tuple2){
		LinkedHashMap<String,Object> result = (LinkedHashMap<String, Object>) tuple1.clone();
		
		for(String att : tuple2.keySet()){
			Object val = tuple2.get(att);
			
			if(result.containsKey(att)){
				att += "_2";
			}
			result.put(att, val);
		}
		
		return result;
		
	}
	
	protected boolean TestCondition(LinkedHashMap<String,Object> tuple1, LinkedHashMap<String,Object> tuple2, List<String> condition, TypeAttribut type){
		String nomAttribut1 = condition.get(0);
		Object valeurAtt1 = tuple1.get(nomAttribut1);
			
		String operateur = condition.get(1);
		
		String nomAttribut2 = condition.get(2);
		Object valeurAtt2 = tuple2.get(nomAttribut2);
		
		boolean isValid = false;
		
		switch(TypeCondition.Get(operateur)){
			case Sup:
				if(type == TypeAttribut.Int){
					isValid = (int)valeurAtt1>(int)valeurAtt2;
				}else if(type == TypeAttribut.Varchar){
					isValid = Long.parseLong((String)valeurAtt1)>Long.parseLong((String)valeurAtt2);
				}
			break;
			case SupE:
				if(type == TypeAttribut.Int){
					isValid = (int)valeurAtt1>=(int)valeurAtt2;
				}else if(type == TypeAttribut.Varchar){
					isValid = Long.parseLong((String)valeurAtt1)>=Long.parseLong((String)valeurAtt2);
				}else if(type == TypeAttribut.Bool){
					isValid = (boolean)valeurAtt1==(boolean)valeurAtt2;
				}
			break;
			case Inf:
				if(type == TypeAttribut.Int){
					isValid = (int)valeurAtt1<(int)valeurAtt2;
				}else if(type == TypeAttribut.Varchar){
					isValid = Long.parseLong((String)valeurAtt1)<Long.parseLong((String)valeurAtt2);
				}
			break;
			case InfE:
				if(type == TypeAttribut.Int){
					isValid = (int)valeurAtt1<=(int)valeurAtt2;
				}else if(type == TypeAttribut.Varchar){
					isValid = Long.parseLong((String)valeurAtt1)<=Long.parseLong((String)valeurAtt2);
				}else if(type == TypeAttribut.Bool){
					isValid = (boolean)valeurAtt1==(boolean)valeurAtt2;
				}
			break;
			case E:
				if(type == TypeAttribut.Int){
					isValid = (int)valeurAtt1==(int)valeurAtt2;
				}else if(type == TypeAttribut.Varchar){
					isValid = valeurAtt1.equals(valeurAtt2);
				}else if(type == TypeAttribut.Bool){
					isValid = (boolean)valeurAtt1==(boolean)valeurAtt2;
				}
			break;
			case Diff:
				if(type == TypeAttribut.Int){
					isValid = (int)valeurAtt1!=(int)valeurAtt2;
				}else if(type == TypeAttribut.Varchar){
					isValid = !valeurAtt1.equals(valeurAtt2);
				}else if(type == TypeAttribut.Bool){
					isValid = (boolean)valeurAtt1!=(boolean)valeurAtt2;
				}
			break;
			case Inconnu:
				return false;
		}
		
		Affiche(tuple1,tuple2,isValid);
		return isValid;
	}
	
	protected List<LinkedHashMap<String,Object>> JointureBlocMemoire(BlocMemoire<LinkedHashMap<String,Object>> bloc1, BlocMemoire<LinkedHashMap<String,Object>> bloc2 , List<String> condition){
		
		List<LinkedHashMap<String,Object>> result = new ArrayList<LinkedHashMap<String,Object>>();
		
		//verification que les deux attributs sont du même type
		if(bloc1.GetType(condition.get(0)) == bloc2.GetType(condition.get(2))){
			
			for(LinkedHashMap<String,Object> tuple1 : bloc1.GetDatas()){
				for(LinkedHashMap<String,Object> tuple2 : bloc2.GetDatas()){
					
					if(TestCondition(tuple1,tuple2,condition,bloc1.GetType(condition.get(0)))){
						result.add(JoindreTuple(tuple1,tuple2));
					}
				}
			}
		}

		return result;
		
	}
	
	protected void Affiche(LinkedHashMap<String,Object> tuple1, LinkedHashMap<String,Object> tuple2,Boolean isValid){
		
		String result = sortieTexte.getText()+"\n";
		
		result += "----------------------------------\n";
		
		result += "Tuple 1 : \n";
		
		for(String att : tuple1.keySet()){
			result += "\t "+ att +" = "+ tuple1.get(att);
		}
		
		result += "\nTuple 2 : \n";
		
		for(String att : tuple2.keySet()){
			result += "\t "+ att +" = "+ tuple2.get(att);
		}
		
		result += "\nValide condition : "+isValid+"\n";
		
		sortieTexte.setText(result);
		
	}
	
	protected List<Bloc> AjouteResultat(List<Bloc> resultat, List<LinkedHashMap<String,Object>> listTuple){
		BlocPhysique<String> lastBloc;
		
		if(!listTuple.isEmpty()){
			if(resultat.isEmpty()){
				lastBloc = new BlocPhysique<String>(listTuple.get(0).keySet());
				resultat.add(lastBloc);
			}else{
				lastBloc = (BlocPhysique<String>) resultat.get(resultat.size()-1);
			}
			
			while(!listTuple.isEmpty()){
				List<String> tuple = MapToList(listTuple.get(0));
				
				if(!lastBloc.AddData(tuple)){
					lastBloc = new BlocPhysique<String>(listTuple.get(0).keySet());
					resultat.add(lastBloc);
					
					lastBloc.AddData(tuple);
				}
				
				listTuple.remove(0);
			}
		}
		
		return resultat;
	}
	
	
}
