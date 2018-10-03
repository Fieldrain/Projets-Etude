package Interface;

import java.util.ArrayList;
import java.util.List;

public class Sujet {
	
	private List<Observateur> observateurs;
	
	public Sujet(){
		observateurs = new ArrayList<Observateur>();
	}
	
	public void Abonne(Observateur o){
		observateurs.add(o);
	}
	
	public void Notifie(){
		for(Observateur o : observateurs){
			o.MiseAJour(this);
		}
	}
	
}
