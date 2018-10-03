package Metier;

import java.util.ArrayList;
import java.util.Hashtable;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.Set;

/*
 * T sera toujours de type Map<String,Object>
 */

public class BlocMemoire<T> implements Bloc<T> {
	
	private List<T> data;
	private LinkedHashMap<String,TypeAttribut> attributDefinition;
	private int octetLibre;
	
	public BlocMemoire(BlocPhysique<String> b,LinkedHashMap<String,TypeAttribut> attributDef){
		data = new ArrayList<T>();
		octetLibre = b.GetEspaceLibre();
		attributDefinition = attributDef;
		
		for(int i=0; i < b.GetDatas().size();i++){
			List<String> valeurs = b.ChargeTuple(i);
			LinkedHashMap<String,Object> valTuple = new LinkedHashMap<String,Object>();
			Set<String> nomAttribut = attributDef.keySet();
			
			for(int j=0; j < nomAttribut.size();j++){
				String nomAt = nomAttribut.toArray(new String[0])[j];
				String chaineValeur = "";
				
				if(j<valeurs.size()){
					chaineValeur = valeurs.get(j);
				}
				
				Object valeur = null;
				
				switch (attributDef.get(nomAt)){
					case Int:
						valeur = Integer.parseInt(chaineValeur);
						break;
					case Varchar:
						valeur = chaineValeur;
						break;
					case Bool:
						valeur = Boolean.parseBoolean(chaineValeur);
						break;
				}
						
				valTuple.put(nomAt, valeur);
			}

			data.add((T) valTuple);
		}
	}

	@Override
	public T GetData(String s) {
		return null;
	}

	@Override
	public List<T> GetDatas() {
		return data;
	}

	@Override
	public int GetEspaceLibre() {
		return octetLibre;
	}

	@Override
	public boolean AddData(List<T> list) {
		// TODO Auto-generated method stub
		return false;
	}
	
	public int GetInt(int tuple,String nom){
		return 0;
	}
	
	public String GetString(int tuple,String nom){
		return "";
	}
	
	public Boolean GetBool(int tuple,String nom){
		return false;
	}
	
	public int GetNbTuple(){
		return data.size();
	}
	
	public TypeAttribut GetType(String nom){
		return attributDefinition.get(nom);
	}
	
	public String toString(){
		String result = "Bloc :\n";
		
		result += "\t Octets Libres : "+octetLibre+"\n";
		result += "\t " + "Données : \n";
		
		for(T t : data){
			LinkedHashMap<String,Object> tuple = (LinkedHashMap<String,Object>) t;
			result += "\t \t Tuple : \n";
			for(String att : tuple.keySet()){
				result += "\t \t \t "+ att+" : "+tuple.get(att)+"\n";
			}
		}
		
		return result;
	}

}
