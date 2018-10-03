package Jointure;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;

import javax.swing.JTextArea;

import Metier.Bloc;
import Metier.BlocMemoire;
import Metier.BlocPhysique;
import Metier.Memoire;
import Metier.Table;
import Metier.TypeAttribut;

public class Hash extends Jointure {

	@SuppressWarnings("static-access")
	@Override
	public List<Bloc> Joindre(Table table1, Table table2, List<String> condition,JTextArea zone) {
		sortieTexte = zone;
		Memoire memoire = Memoire.Get();
		List<Bloc> resultat = new ArrayList<Bloc>();
		//applique la fonction de hashage sur table1 et table 2
		
		LinkedHashMap<Integer,LinkedList<BlocPhysique<String>>> hashTable1 = Hash(table1,condition.get(0),(Memoire.nbBloc-1));
		
		LinkedHashMap<Integer,LinkedList<BlocPhysique<String>>> hashTable2 = Hash(table2,condition.get(2),(Memoire.nbBloc-1));
		
		for(int i : hashTable1.keySet()){
			List<BlocPhysique<String>> R = (List<BlocPhysique<String>>) hashTable1.get(i).clone();
			
			while(!R.isEmpty()){
				R = memoire.Charger(R, table1.GetAttributDefinition(),1);
				int nbBlocChargerT = memoire.nbBlocCharger;
				for(int j=(nbBlocChargerT-1);j>=0;j--){
					
					if(hashTable2.containsKey(i)){
						List<BlocPhysique<String>> S = (List<BlocPhysique<String>>) hashTable2.get(i).clone();
						BlocMemoire<LinkedHashMap<String,Object>> blocT = memoire.GetBloc(j);
						
						while(!S.isEmpty()){
							int nbBlocChargerS = S.size();
							S = memoire.Charger(S, table2.GetAttributDefinition(),0);
							nbBlocChargerS -= S.size();
							
							for(int k=nbBlocChargerT;k<(memoire.nbBlocCharger);k++){
								BlocMemoire<LinkedHashMap<String,Object>> blocS = memoire.GetBloc(k);		
								List<LinkedHashMap<String,Object>> listTupleResult = JointureBlocMemoire(blocT,blocS,condition);
								resultat = AjouteResultat(resultat,listTupleResult);
							}
							memoire.Decharger(nbBlocChargerS, false);
						}
					}
					
				}
				memoire.DechargerTout();
			}
		}
		
		return resultat;
	}
	
	//applique fonction de hashage
	private LinkedHashMap<Integer,LinkedList<BlocPhysique<String>>> Hash(Table table,String att,int modulo){
		LinkedHashMap<Integer,LinkedList<BlocPhysique<String>>> result = new LinkedHashMap<Integer,LinkedList<BlocPhysique<String>>>();
		Memoire memoire = Memoire.Get();
		
		// pour chaque bloc de la table
		for(BlocPhysique<String> blocP : table.GetBlocs()){
			memoire.Charger(blocP, table.GetAttributDefinition(), 0);
			
			//pour chaque tuple applique fonction de hash
			for(LinkedHashMap<String,Object> tuple : memoire.GetBloc(0).GetDatas()){
				
				int hashVal = f(tuple.get(att),table.GetTypeAttribut(att),modulo);
				
				if(hashVal != -100000000){
					LinkedList<BlocPhysique<String>> listBloc = new LinkedList<BlocPhysique<String>>();
					BlocPhysique<String> bloc = null;
					
					if(result.containsKey(hashVal)){
						listBloc = result.get(hashVal);
					}else{
						result.put(hashVal, listBloc);
					}
					
					List<String> data = MapToList(tuple);
					if(!listBloc.isEmpty()){
						bloc = listBloc.getLast();
					}else{
						bloc = new BlocPhysique<String>(table.GetAttributDefinition().keySet());
						listBloc.add(bloc);
					}
					
					if(!bloc.AddData(data)){
						bloc = new BlocPhysique<String>(table.GetAttributDefinition().keySet());
						bloc.AddData(data);
						listBloc.add(bloc);
					}
					
					result.replace(hashVal, listBloc);
				}
			}
			
			memoire.DechargerTout();
		}
		
		return result;
	}
	
	private int f(Object val,TypeAttribut type, int modulo){
		int valHash = -100000000;
		
		switch (type){
			case Varchar:
					String valeurS = (String) val;
					valHash = valeurS.hashCode() % modulo;
				break;
			case Int:
					int valeurI = (int) val;
					valHash = Integer.hashCode(valeurI) % modulo;
				break;
			case Bool:
					boolean valeurB = (Boolean) val;
					valHash = Boolean.hashCode(valeurB) % modulo;
				break;
		}

		
		return valHash;
	}

}
