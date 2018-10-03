package Metier;

import java.util.ArrayList;
import java.util.List;
import java.util.LinkedHashMap;

import javax.swing.JTextArea;
import javax.xml.crypto.Data;

public class Memoire {

	public static int nbBloc = 4;
	public static int tailleBloc = 512;
	private static Memoire instance = null;
	public static int nbBlocCharger = 0;
	public static JTextArea sortieTexte = null;
	
	private List<BlocMemoire<LinkedHashMap<String,Object>>> blocs;
	private int blocLibre;
	
	private Memoire(){
		blocs = new ArrayList<BlocMemoire<LinkedHashMap<String,Object>>>();
		blocLibre = nbBloc;
	}
	
	public static Memoire Get(){
		if(instance == null)
			instance = new Memoire();
		
		return instance;
	}
	
	public BlocMemoire<LinkedHashMap<String,Object>> GetBloc(int i){
		return blocs.get(i);
	}
	
	public int GetTailleBloc(){
		return tailleBloc;
	}
	
	
	/*
	 * Charge la list des bloc physique bloc p et renvoie les bloc non charger
	 */
	public List<BlocPhysique<String>> Charger(List<BlocPhysique<String>> blocP, LinkedHashMap<String,TypeAttribut> attributDef, int espaceLibre){
		List<BlocPhysique<String>> blocNonCharger = blocP;
		
		// laisse des blocs libres
		int blocCharger = (nbBlocCharger-1)+espaceLibre;
		
		while(blocCharger<(nbBloc-1) && !blocNonCharger.isEmpty()){
			BlocPhysique<String> b = blocNonCharger.get(0);
			
			blocs.add(new BlocMemoire<LinkedHashMap<String,Object>>(b,attributDef));
			
			blocNonCharger.remove(0);
			nbBlocCharger++;
			blocCharger++;
			blocLibre--;
		}
		
		Affiche();
		return blocNonCharger;
	}
	
	public boolean Charger(BlocPhysique<String> blocP, LinkedHashMap<String,TypeAttribut> attributDef, int espaceLibre){
		boolean charger = false;
		
		if(blocLibre>=espaceLibre+1){
			charger = true;
			blocs.add(new BlocMemoire<LinkedHashMap<String,Object>>(blocP,attributDef));
			blocLibre--;
			nbBlocCharger++;
		}
		Affiche();
		return charger;
	}
	
	public void Decharger(int nbBlocADecharger, boolean debut){
		
		int i = debut?0:(nbBlocCharger-1);
		int blocDecharger = 0;
		
		while(nbBlocCharger!=0 && blocDecharger!=nbBlocADecharger){
			blocs.remove(i);
			blocLibre++;
			blocDecharger++;
			nbBlocCharger--;
			i = debut?i++:i--;
		}
		
	}
	
	public void DechargerTout(){
		Decharger(nbBlocCharger,true);
	}
	
	private void Affiche(){
		if(sortieTexte!=null){
			String info = "";
			
			info += "-----------------------------------------------\n";
			for(BlocMemoire<LinkedHashMap<String,Object>> bloc : blocs){
				info += bloc.toString() + "\n";
			}
			
			sortieTexte.append(info);
		}
	}
	
	
}
