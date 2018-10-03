package Metier;

import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

import javax.swing.JTextArea;


/*
 * T sera toujours de type String
 */
public class BlocPhysique<T> implements Bloc<T>, Cloneable {
	
	private LinkedList<String> attribut;
	private List<T> data;
	private int octetLibre;
	
	public BlocPhysique(LinkedList<String> att){
		attribut = att;
		data = new ArrayList<T>();
		octetLibre = Memoire.tailleBloc;
	}
	
	public BlocPhysique(Set<String> att){
		attribut = new LinkedList<String>();
		for(String a : att){
			attribut.add(a);
		}
		
		data = new ArrayList<T>();
		octetLibre = Memoire.tailleBloc;
	}

	@Override
	public T GetData(String s) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public List<T> GetDatas() {
		return data;
	}
	
	public List<String> ChargeTuple(int i){
		List<String> tuple = new ArrayList<String>();
		
		String val = (String) data.get(i);
		
		int characterLu = 0;
		
		while(characterLu<val.length()){
			String chaineTaille = val.substring(characterLu, characterLu+Integer.SIZE);
			
			int tailleVal = Integer.parseInt(chaineTaille.replace("*", ""));
			characterLu += chaineTaille.length();
			
			String valeur = val.substring(characterLu, characterLu+tailleVal);
			characterLu += valeur.length();
			
			tuple.add(valeur);
		}
		
		return tuple;
	}
	
	public BlocPhysique<T> clone(){
		BlocPhysique<T> bP = null;
		
		try {
			bP = (BlocPhysique<T>) super.clone();
		} catch(CloneNotSupportedException cnse) {
			cnse.printStackTrace(System.err);
		}

		return bP;
	}
	
	private T Concatenation(List<T> list){
		String tuple = "";
		
		// concatenation = tailleAttribut sizeInt + valeurAttribut
		for(T val : list){
			String s = (String) val;
			String tailleAttribut = String.valueOf(s.length());
			
			while(tailleAttribut.length() < Integer.SIZE){
				tailleAttribut += '*';
			}
			
			tuple += tailleAttribut + s;
		}
		
		return (T) tuple;
	}
	
	public boolean AddData(List<T> list){
		String s = (String) Concatenation(list);

		int tailleS = s.length();
		if(tailleS > octetLibre){
			return false;
		}else{
			data.add((T) s);
			octetLibre -= tailleS;
			return true;
		}
	}

	@Override
	public int GetEspaceLibre() {
		return octetLibre;
	}
	
	public void Affichage(JTextArea zone){
		for(T s : data){
			String texte = (String)s +"\n";
			zone.append(texte);
		}
	}
	
	public LinkedList<String> GetNomAttribut(){
		return attribut;
	}

}
