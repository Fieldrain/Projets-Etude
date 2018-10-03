package Metier;

import java.util.List;
import java.util.Set;

import javax.swing.JTextArea;

import java.util.ArrayList;
import java.util.LinkedHashMap;

public class Table {

	private String nom;
	private List<BlocPhysique<String>> blocs;
	private LinkedHashMap<String,TypeAttribut> attributs;
	
	public Table(String nomTable,List<List<String>> listTuples, LinkedHashMap<String,TypeAttribut> listAttribut){
		blocs = new ArrayList<BlocPhysique<String>>();
		nom = nomTable;
		attributs = listAttribut;
		BlocPhysique<String> b = new BlocPhysique<String>(listAttribut.keySet());
		blocs.add(b);
		for(List<String> list : listTuples){
			if(!b.AddData(list)){
				b = new BlocPhysique<String>(attributs.keySet());
				blocs.add(b);
				b.AddData(list);
			}
		}
		
		
		
	}

	public BlocPhysique<String> GetBloc(int i) {
		return blocs.get(i);
	}
	
	public List<BlocPhysique<String>> GetBlocs() {
		List<BlocPhysique<String>> retour =new ArrayList<BlocPhysique<String>>();
		
		for(BlocPhysique<String> b : blocs){
			retour.add(b.clone());
		}
		
		return retour;
	}
	
	public String GetNom(){
		return nom;
	}

	public void AddBlocs(BlocPhysique<String> Bloc) {
		blocs.add(Bloc);
	}
	
	public void SetBlocs(List<BlocPhysique<String>> Blocs) {
		blocs = Blocs;
	}
	
	public Set<String> GetNomAttribut(){
		return attributs.keySet();
	}
	
	public TypeAttribut GetTypeAttribut(String nom){
		return attributs.get(nom);
	}
	
	public LinkedHashMap<String,TypeAttribut> GetAttributDefinition(){
		return attributs;
	}
	
	public void Affiche(JTextArea zoneTexte){
		zoneTexte.setText("");
		for(BlocPhysique<String> b : blocs){
			b.Affichage(zoneTexte);
		}
	}
}
