package Metier;

import java.util.ArrayList;
import java.util.Hashtable;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

import javax.swing.JTextArea;

import Jointure.FabriqueJointure;
import Jointure.TypeJointure;

public class Modele {

	Map<String,Table> tables;
	FabriqueJointure fabrique;
	
	public Modele(Map<String,Integer> donnees){
		tables = new Hashtable<String,Table>();
		fabrique = new FabriqueJointure();
		Memoire.nbBloc = donnees.get("Taille Mémoire (Nb Bloc)");
		Memoire.tailleBloc = donnees.get("Taille Bloc");
	}
	
	/*
	 * Récupére une table dans la bd
	 */
	public void ChargeTable(String nom){
		BDD bd = BDD.Get();
		
		if(bd != null){
			if(!tables.containsKey(nom)){
				Table t = bd.GetTable(nom);
				tables.put(nom,t);
			}else{
				Table t = tables.get(nom);
				bd.UpdateTableCharger(nom, t);
			}
		}
	}
	
	/*
	 * Récupére le nom des tables déjà prisent dans la bd
	 */
	public Set<String> GetTableCharger(){
		return tables.keySet();
	}
	
	public Map<String,String> GetTablesBD(){
		Map<String,String> list = new Hashtable<String,String>();
		
		BDD bd = BDD.Get();
		
		if(bd!=null){
			List<String> listTable = bd.GetListTableBase();
			
			for(String s : listTable){
				if(tables.containsKey(s)){
					list.put(s, "Chargée");
				}else{
					list.put(s, "Non Chargée");
				}
				
			}
		}
		
		return list;
	}
	
	public List<String> GetTableNonCharger(){
		BDD bd = BDD.Get();
		List<String> list = new ArrayList<String>();
		
		if(bd!=null){
			List<String> listTable = bd.GetListTableBase();
			
			for(String s: listTable){
				if(!tables.containsKey(s)){
					list.add(s);
				}
			}
		}
		
		return list;
	}
	
	public Table GetTable(String nom){
		return tables.get(nom);
	}
	
	public List<LinkedHashMap<String,String>> Joindre(Table table1,Table table2,List<String> conditions, TypeJointure typeJointure, JTextArea zone){
		List<LinkedHashMap<String,String>> result = new ArrayList<LinkedHashMap<String,String>>();
		
		List<Bloc> jointure= fabrique.Construit(typeJointure).Joindre(table1, table2, conditions,zone);
		
		for(Bloc b:jointure){
			BlocPhysique<String> bloc = (BlocPhysique<String>) b;
			
			for(int i=0; i < bloc.GetDatas().size();i++){
				List<String> valeurs = bloc.ChargeTuple(i);
				LinkedHashMap<String,String> valTuple = new LinkedHashMap<String,String>();
				LinkedList<String> nomAttribut = bloc.GetNomAttribut();
				
				for(int j=0; j < nomAttribut.size();j++){
					String nomAt = nomAttribut.get(j);
					String valeur = "";
					
					if(j<valeurs.size()){
						valeur = valeurs.get(j);
					}
					
					valTuple.put(nomAt, valeur);
				}

				result.add(valTuple);
			}
			
		}
		
		return result;
	}

}
