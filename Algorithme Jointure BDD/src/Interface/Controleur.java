package Interface;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;

import javax.swing.JTextArea;

import Jointure.TypeCondition;
import Jointure.TypeJointure;
import Metier.Modele;
import Metier.Table;

public class Controleur extends Sujet {
	Modele modele;
	
	public Controleur(){
		super();
	}
	
	Controleur(Modele m){
		modele = m;
	};
	
	public List<LinkedHashMap<String,String>> Joindre(String table1, String attribut1, String table2,String attribut2, String typeCondition, TypeJointure typeJointure, JTextArea zone){
		
		
		Table t1 = modele.GetTable(table1);
		Table t2 = modele.GetTable(table2);
		
		List<String> conditions = new ArrayList<String>();
		conditions.add(attribut1);
		conditions.add(typeCondition);
		conditions.add(attribut2);
		
		return modele.Joindre(t1, t2, conditions, typeJointure,zone);
		
	}

}
