package Metier;

import java.util.List;

public interface Bloc<T> {
	
	abstract T GetData(String s);
	abstract List<T> GetDatas();
	abstract int GetEspaceLibre();
	abstract boolean AddData(List<T> list);
}
