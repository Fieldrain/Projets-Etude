package Jointure;

import java.util.ArrayList;
import java.util.List;

import javax.swing.JTextArea;

import java.util.LinkedHashMap;

import Metier.Bloc;
import Metier.BlocMemoire;
import Metier.BlocPhysique;
import Metier.Memoire;
import Metier.Table;
import Metier.TypeAttribut;

public class Cartesien extends Jointure {

	@Override
	public List<Bloc> Joindre(Table table1, Table table2,List<String> condition,JTextArea zone) {
		sortieTexte = zone;
		Memoire memoire = Memoire.Get();
		List<Bloc> resultat = new ArrayList<Bloc>();
		
		sortieTexte.setText("Condition Jointure : "+table1.GetNom()+"."+condition.get(0)+" "+condition.get(1)+" "+table2.GetNom()+"."+condition.get(2)+"\n");
		
		if(memoire!=null){
			List<BlocPhysique<String>> blocAChargerTable1 = table1.GetBlocs();
			
			//charger tout les blocs de la table1
			while(!blocAChargerTable1.isEmpty()){
				blocAChargerTable1 = memoire.Charger(blocAChargerTable1, table1.GetAttributDefinition(),1);
				
				//parcours tout les blocs charger sauf le dernier
				for(int i=(memoire.nbBlocCharger-1);i>=0;i--){
					BlocMemoire<LinkedHashMap<String,Object>> blocTable1 = memoire.GetBloc(i);
					
					List<BlocPhysique<String>> blocAChargerTable2 = table2.GetBlocs();
					
					//parcours tout les blocs de la table 2
					for(BlocPhysique<String> bp : blocAChargerTable2){
						
						//charge le bloc
						if(memoire.Charger(bp, table2.GetAttributDefinition(),0)){
							//recupere bloc charger
							BlocMemoire<LinkedHashMap<String,Object>> blocTable2 = memoire.GetBloc(memoire.nbBlocCharger-1);
							
							//recupere les tuples qui valide la condition
							List<LinkedHashMap<String,Object>> listTupleResultat = JointureBlocMemoire(blocTable1,blocTable2,condition);
							
							//ajoute les tuples au resultat final
							resultat = AjouteResultat(resultat,listTupleResultat);
							
							//decharge le dernier bloc
							memoire.Decharger(1, false);
						}else{
							// probleme lors du chargement on decharge tout et renvoie null
							memoire.DechargerTout();
							return null;
						}
					}

				}
				memoire.DechargerTout();
			}
		}
		memoire.DechargerTout();
		return resultat;
	}

}
