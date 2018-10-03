package Metier;

public enum TypeAttribut {
	Int,
	Varchar,
	Bool,
	Inconnu;
	
	public static TypeAttribut Get(String nom){
		
		if(nom.contains("VARCHAR") || nom.contains("CHAR")){
			return Varchar;
		}
		if(nom.contains("INTEGER") || nom.contains("NUMBER")){
			return Int;
		}
		if(nom.contains("BOOLEAN")){
			return Bool;
		}
		
		return Inconnu;
	}
}
