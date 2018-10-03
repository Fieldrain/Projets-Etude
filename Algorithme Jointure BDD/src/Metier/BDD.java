package Metier;
import java.sql.*;
import java.util.ArrayList;
import java.util.LinkedHashMap;
import java.util.List;

public class BDD {
	
	private static BDD Instance = null;
	public static Boolean Exterieur = true;
	public static String Utilisateur = "";
	public static String Password = "";
	private Connection connect;
	private DatabaseMetaData dbmd;
	private Statement stmt;

	private BDD(){
		try{
			Class.forName("oracle.jdbc.driver.OracleDriver");
			if(!Exterieur){
				connect = DriverManager.getConnection("jdbc:oracle:thin:@toto",Utilisateur,Password);
			}else{
				connect = DriverManager.getConnection("jdbc:oracle:thin:@toto",Utilisateur,Password);
			}
			
			dbmd = connect.getMetaData();
			dbmd.getDefaultTransactionIsolation();
			connect.setTransactionIsolation(Connection.TRANSACTION_SERIALIZABLE);
			
			stmt = connect.createStatement();
			
		}catch (Exception e){
			System.err.print(e);
			System.err.print("Connection");
		}
		
	}
	
	public static BDD Get(){
		if(Instance == null){
			if(Utilisateur == "" || Password == ""){
				
			}else{
				Instance = new BDD();
			}
		}
		return Instance;
	}
	
	@SuppressWarnings("finally")
	public Table GetTable(String nom){
		String req = "Select * FROM "+nom;
		ResultSet res = Select(req);
		Table table = null;

		try{
			int columnCount = res.getMetaData().getColumnCount();
			List<List<String>> listTuple = new ArrayList<List<String>>();
			
			while(res.next()){
				List<String> tuple = new ArrayList<String>();
				
				for(int i=1; i < columnCount+1; i++){
					tuple.add(res.getString(i));
				}
				
				listTuple.add(tuple);
				
			}
			res.close();
			
			req = "Select COLUMN_NAME,DATA_TYPE FROM USER_TAB_COLUMNS WHERE TABLE_NAME ='"+nom+"'";
			res = Select(req);
			
			LinkedHashMap<String,TypeAttribut> list = new LinkedHashMap<String,TypeAttribut>();
			
			while(res.next()){
				String nomColonne = res.getString(1);
				String type = res.getString(2);
				
				list.put(nomColonne,TypeAttribut.Get(type));
			}
			
			table = new Table(nom,listTuple,list);
			
		}catch (Exception e){
			System.err.print(e);
			System.err.print("GetTable");
		}finally{
			return table;
		}

	}
	
	@SuppressWarnings("finally")
	public List<String> GetListTableBase(){
		String req = "Select TABLE_NAME FROM USER_TABLES";
		ResultSet res = Select(req);
		
		List<String> list = new ArrayList<String>(); 
		try{
			while(res.next()){
				list.add(res.getString(1));
			}
			
			res.close();
		}catch (Exception e){
			System.err.print(e);
			System.err.print("GetListTableBase");
		}finally{
			return list;
		}
		
	}
	
	public void UpdateTableCharger(String nom,Table t){
		Table temp = GetTable(nom);
		
		t.SetBlocs(temp.GetBlocs());
	}
	
	@SuppressWarnings("finally")
	private ResultSet Select(String s){
		ResultSet rset = null;
		try{
			System.out.println(s);
			rset = stmt.executeQuery(s);
			
		}catch (Exception e){
			System.err.print(e);
			System.err.print("Select");
		} finally{
			return rset;
		}
		
	}
	
	public void Close(){
		try {
			stmt.close();
			connect.close();
		} catch (Exception e) {
			System.err.print(e);
			System.err.print("Close");
		}
	}
	
}
