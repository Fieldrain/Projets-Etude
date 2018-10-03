package Jointure;

import java.util.HashMap;
import java.util.Map;

public class FabriqueJointure {
	
	private Map<TypeJointure,ConstructeurJointure> constructeurs = new HashMap<TypeJointure,ConstructeurJointure>();
	
	public FabriqueJointure(){
		constructeurs.put(TypeJointure.Cartesien, new ConstructeurCartesien());
		constructeurs.put(TypeJointure.Hash, new ConstructeurHash());
	}
	
	public Jointure Construit(TypeJointure t){
		return constructeurs.get(t).Construit();
	}
	
	
}
