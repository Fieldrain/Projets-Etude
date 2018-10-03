package Jointure;

public enum TypeCondition {
	Sup,
	SupE,
	Inf,
	InfE,
	E,
	Diff,
	Inconnu;
	
	public static TypeCondition Get(String nom){
		if(nom == ">"){
			return Sup;
		}
		if(nom == ">="){
			return SupE;
		}
		if(nom == "<"){
			return Inf;
		}
		if(nom == "<="){
			return InfE;
		}
		if(nom == "="){
			return E;
		}
		if(nom == "!="){
			return Diff;
		}
		return Inconnu;
	}
	
	public static String ToString(TypeCondition t){
		switch (t){
			case Sup:
				return ">";
			case SupE:
				return ">=";
			case Inf:
				return "<";
			case InfE:
				return "<=";
			case E:
				return "=";
			case Diff:
				return "!=";
		}
		return "";
	}
}
