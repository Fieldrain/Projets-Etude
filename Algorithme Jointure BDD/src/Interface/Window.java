package Interface;
import java.awt.EventQueue;

import javax.swing.JFrame;
import java.awt.GridLayout;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JPasswordField;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

import Jointure.TypeCondition;
import Jointure.TypeJointure;

import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.util.HashMap;
import java.util.LinkedHashMap;
import java.util.Map;
import java.awt.event.ActionEvent;
import javax.swing.JTabbedPane;
import javax.swing.JPanel;

import Metier.BDD;
import Metier.Memoire;
import Metier.Modele;
import Metier.Table;
import Metier.TypeAttribut;

import java.util.List;
import javax.swing.SwingConstants;
import javax.swing.JScrollPane;
import javax.swing.JComboBox;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import javax.swing.JTextPane;
import javax.swing.JTextArea;
import java.awt.event.ItemListener;
import java.awt.event.ItemEvent;
import javax.swing.JCheckBox;

public class Window implements Observateur{

	private JFrame frame;
	private JTextField textFieldNomUtilisateur;
	private JPasswordField passwordField;
	private JTable tablePropriete;
	private JTabbedPane tabbedPane;
	private JPanel panelInitialisation;
	private JPanel panelApplication;
	private JButton btnConfirmer;
	private Modele modele;
	private Controleur controleur;
	private JLabel lblTableDansLa;
	private JTable tableListTableBd;
	private JLabel lblJointure;
	private JComboBox<String> comboBoxListTableCharger;
	private JComboBox<String> comboBoxListTableCharger_1;
	private JComboBox<String> comboBoxListTableNoCharg;
	private JButton btnJoindre;
	private JComboBox<TypeJointure> comboBoxTypeJointure;
	private JLabel lblTable;
	private JLabel lblTable_1;
	private JLabel lblType;
	private JPanel panelAffichage;
	private JTextArea textAreaAffichage;
	private JButton btnAfficher;
	private JComboBox<String> comboBoxTableAffichable;
	private JComboBox<String> comboBoxAttributTable1;
	private JComboBox<String> comboBoxAttributTable2;
	private JComboBox<String> comboBoxOperation;
	private boolean MAJ = false;
	private JLabel labelValidJointure;
	private JTextPane textPaneExplication;
	private JPanel panelResultat;
	private JTable tableResultat;
	private JScrollPane scrollPane_2;
	private JPanel panelMemoire;
	private JTextArea textAreaSortieMemoire;
	private JTextArea textAreaSortieJointure;
	private JPanel panelSortieJointure;
	private JScrollPane scrollPane_4;
	private JCheckBox chckbxExterieur;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Window window = new Window();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Window() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosed(WindowEvent arg0) {
				BDD bd = BDD.Get();
				if(bd != null){
					bd.Close();
				}
				
			}
		});
		frame.setBounds(100, 100, 699, 500);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.getContentPane().setLayout(new GridLayout(1, 0, 0, 0));
		
		tabbedPane = new JTabbedPane(JTabbedPane.TOP);
		frame.getContentPane().add(tabbedPane);
		
		panelInitialisation = new JPanel();
		tabbedPane.addTab("Initialisation", null, panelInitialisation, null);
		
		JLabel lblNomDutilisateur = new JLabel("Nom d'Utilisateur");
		lblNomDutilisateur.setBounds(155, 12, 109, 14);
		
		textFieldNomUtilisateur = new JTextField();
		textFieldNomUtilisateur.setBounds(333, 9, 102, 20);
		textFieldNomUtilisateur.setColumns(10);
		
		JLabel lblMotDePasse = new JLabel("Mot de Passe");
		lblMotDePasse.setBounds(155, 37, 109, 14);
		
		passwordField = new JPasswordField();
		passwordField.setBounds(333, 35, 102, 20);
		passwordField.setColumns(10);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(137, 91, 321, 173);
		
		tablePropriete = new JTable();
		scrollPane.setViewportView(tablePropriete);
		tablePropriete.setModel(new DefaultTableModel(
			new Object[][] {
				{"Taille Bloc", new Integer(512)},
				{"Taille M\u00E9moire (Nb Bloc)", new Integer(10)},
			},
			new String[] {
				"Propri\u00E9t\u00E9s", "Valeur"
			}
		) {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;
			Class[] columnTypes = new Class[] {
				String.class, Integer.class
			};
			public Class<?> getColumnClass(int columnIndex) {
				return columnTypes[columnIndex];
			}
			boolean[] columnEditables = new boolean[] {
				false, true
			};
			public boolean isCellEditable(int row, int column) {
				return columnEditables[column];
			}
		});
		tablePropriete.getColumnModel().getColumn(0).setPreferredWidth(144);
		
		btnConfirmer = new JButton("Confirmer");
		btnConfirmer.setBounds(250, 304, 109, 23);
		btnConfirmer.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				tabbedPane.setEnabledAt(1, true);
				tabbedPane.setEnabledAt(2, true);
				tabbedPane.setEnabledAt(3, true);
				tabbedPane.setEnabledAt(4, true);
				tabbedPane.setEnabledAt(5, true);
				tabbedPane.setSelectedIndex(1);
				tabbedPane.setEnabledAt(0, false);
				
				BDD.Password = String.valueOf(passwordField.getPassword());
				BDD.Utilisateur = textFieldNomUtilisateur.getText();
				BDD.Exterieur = chckbxExterieur.isSelected();
				
				Map<String,Integer> donnes = new HashMap<String,Integer>();
				for(int i = 0;i<tablePropriete.getRowCount();i++){
					String nom = (String)tablePropriete.getModel().getValueAt(i, 0);
					int val = (Integer)tablePropriete.getModel().getValueAt(i, 1);
					
					donnes.put(nom,val);
				}
			
				modele = new Modele(donnes);
				Memoire.sortieTexte = textAreaSortieMemoire;
				controleur = new Controleur(modele);
				controleur.Abonne(Window.this);
				MiseAJour(controleur);
			}
		});
		
		panelInitialisation.setLayout(null);
		panelInitialisation.add(btnConfirmer);
		panelInitialisation.add(lblMotDePasse);
		panelInitialisation.add(lblNomDutilisateur);
		panelInitialisation.add(textFieldNomUtilisateur);
		panelInitialisation.add(passwordField);
		panelInitialisation.add(scrollPane);
		
		chckbxExterieur = new JCheckBox("Exterieur");
		chckbxExterieur.setSelected(true);
		chckbxExterieur.setBounds(223, 58, 97, 23);
		panelInitialisation.add(chckbxExterieur);
		
		panelApplication = new JPanel();
		tabbedPane.addTab("App", null, panelApplication, null);
		panelApplication.setLayout(null);
		
		lblTableDansLa = new JLabel("Table dans la base");
		lblTableDansLa.setBounds(49, 11, 121, 14);
		panelApplication.add(lblTableDansLa);
		lblTableDansLa.setHorizontalAlignment(SwingConstants.LEFT);
		
		JScrollPane scrollPaneListTable = new JScrollPane();
		scrollPaneListTable.setBounds(49, 36, 141, 225);
		panelApplication.add(scrollPaneListTable);
		
		
		tableListTableBd = new JTable();
		scrollPaneListTable.setViewportView(tableListTableBd);
		tableListTableBd.setModel(new DefaultTableModel(
			new Object[][] {
			},
			new String[] {
				"Nom Table", "Statut"
			}
		) {
			/**
			 * 
			 */
			private static final long serialVersionUID = 1L;
			Class[] columnTypes = new Class[] {
				String.class, String.class
			};
			public Class<?> getColumnClass(int columnIndex) {
				return columnTypes[columnIndex];
			}
			boolean[] columnEditables = new boolean[] {
				false, false
			};
			public boolean isCellEditable(int row, int column) {
				return columnEditables[column];
			}
		});
		
		comboBoxListTableNoCharg = new JComboBox<String>();
		comboBoxListTableNoCharg.setBounds(49, 303, 121, 20);
		panelApplication.add(comboBoxListTableNoCharg);
		
		JLabel lblChargerLaTable = new JLabel("Charger la table");
		lblChargerLaTable.setBounds(49, 278, 121, 14);
		panelApplication.add(lblChargerLaTable);
		
		JButton btnNewButton = new JButton("Charger");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				modele.ChargeTable((String)comboBoxListTableNoCharg.getSelectedItem());
				MiseAJour(controleur);
			}
		});
		btnNewButton.setBounds(49, 334, 121, 23);
		panelApplication.add(btnNewButton);
		
		lblJointure = new JLabel("Jointure");
		lblJointure.setBounds(227, 11, 71, 14);
		panelApplication.add(lblJointure);
		
		
		comboBoxListTableCharger = new JComboBox<String>();
		comboBoxListTableCharger.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent arg0) {
				if(!MAJ){
					if(comboBoxListTableCharger.getSelectedIndex() != -1){
						MAJ = true;
						comboBoxAttributTable1.removeAllItems();
						//recupere la table dans la premiere combobox puis on recupere ces attributs
						for(String a : modele.GetTable((String)comboBoxListTableCharger.getSelectedItem()).GetAttributDefinition().keySet()){
							comboBoxAttributTable1.addItem(a);
						}
						comboBoxAttributTable1.setSelectedItem(-1);
						MAJ = false;
					}
				}
			}
		});
		comboBoxListTableCharger.setBounds(283, 40, 99, 20);
		panelApplication.add(comboBoxListTableCharger);
		
		comboBoxListTableCharger_1 = new JComboBox<String>();
		comboBoxListTableCharger_1.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent arg0) {
				if(!MAJ){
					if(comboBoxListTableCharger_1.getSelectedIndex() != -1){
						MAJ = true;
						comboBoxAttributTable2.removeAllItems();
						//recupere la table dans la deuxieme combobox puis on recupere ces attributs
						for(String a : modele.GetTable((String)comboBoxListTableCharger_1.getSelectedItem()).GetAttributDefinition().keySet()){
							comboBoxAttributTable2.addItem(a);
						}
						comboBoxAttributTable2.setSelectedItem(-1);
						MAJ = false;
					}
				}
			}
		});
		comboBoxListTableCharger_1.setBounds(283, 71, 99, 20);
		panelApplication.add(comboBoxListTableCharger_1);
		
		btnJoindre = new JButton("Joindre");
		btnJoindre.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				if(comboBoxListTableCharger.getSelectedIndex() == -1){
					labelValidJointure.setText("Invalide");
					textPaneExplication.setText("Première table non selectionnée");
				}else
				if(comboBoxAttributTable1.getSelectedIndex() == -1){
					labelValidJointure.setText("Invalide");
					textPaneExplication.setText("Premier attribut non selectionné");
				}else
				if(comboBoxListTableCharger_1.getSelectedIndex() == -1){
					labelValidJointure.setText("Invalide");
					textPaneExplication.setText("Deuxième table non selectionnée");
				}else
				if(comboBoxAttributTable2.getSelectedIndex() == -1){
					labelValidJointure.setText("Invalide");
					textPaneExplication.setText("Deuxième attribut non selectionné");
				}else{
					TypeAttribut t1 = modele.GetTable((String)comboBoxListTableCharger.getSelectedItem()).GetTypeAttribut((String)comboBoxAttributTable1.getSelectedItem());
					TypeAttribut t2 = modele.GetTable((String)comboBoxListTableCharger_1.getSelectedItem()).GetTypeAttribut((String)comboBoxAttributTable2.getSelectedItem());
					
					if(t1 != t2){
						labelValidJointure.setText("Invalide");
						textPaneExplication.setText("Type d'attribut non compatible");
					}else{
						Memoire.sortieTexte.setText("");
						textAreaSortieJointure.setText("");
						textPaneExplication.setText("");
						
						List<LinkedHashMap<String,String>> result = controleur.Joindre((String)comboBoxListTableCharger.getSelectedItem(), (String)comboBoxAttributTable1.getSelectedItem(),
								(String)comboBoxListTableCharger_1.getSelectedItem(), (String)comboBoxAttributTable2.getSelectedItem(),
								(String)comboBoxOperation.getSelectedItem(),(TypeJointure)comboBoxTypeJointure.getSelectedItem(),
								textAreaSortieJointure);
						
						tableResultat.removeAll();
						if(!result.isEmpty()){
							String header[] = result.get(0).keySet().toArray(new String[0]);
							
							DefaultTableModel model = new DefaultTableModel(new Object[][] {},header);
							
							for(LinkedHashMap<String,String> tuple : result){
								Object row[] = tuple.values().toArray(new Object[0]);
								model.addRow(row);
								
							}
							tableResultat.setModel(model);
						}
						
						textPaneExplication.setText("Jointure terminée.\nRésultat affiché dans l'onglet résultat");
						labelValidJointure.setText("");
						
					}
				}
			}
		});
		btnJoindre.setBounds(356, 133, 99, 23);
		panelApplication.add(btnJoindre);
		
		comboBoxTypeJointure = new JComboBox<TypeJointure>();
		comboBoxTypeJointure.addItemListener(new ItemListener() {
			public void itemStateChanged(ItemEvent arg0) {
				if(!MAJ){
					if((TypeJointure)comboBoxTypeJointure.getSelectedItem() == TypeJointure.Hash){
						comboBoxOperation.removeAllItems();
						comboBoxOperation.addItem(TypeCondition.ToString(TypeCondition.E));
					}else{
						comboBoxOperation.removeAllItems();
						for(TypeCondition t : TypeCondition.values()){
							comboBoxOperation.addItem(TypeCondition.ToString(t));
						}
					}
				}
			}
		});
		comboBoxTypeJointure.setBounds(283, 102, 99, 20);
		panelApplication.add(comboBoxTypeJointure);
		
		lblTable = new JLabel("Table 1");
		lblTable.setBounds(227, 43, 46, 14);
		panelApplication.add(lblTable);
		
		lblTable_1 = new JLabel("Table 2");
		lblTable_1.setBounds(227, 74, 46, 14);
		panelApplication.add(lblTable_1);
		
		lblType = new JLabel("Type");
		lblType.setBounds(227, 105, 46, 14);
		panelApplication.add(lblType);
		
		JLabel lblConditionJointure = new JLabel("Condition Jointure");
		lblConditionJointure.setBounds(417, 11, 107, 14);
		panelApplication.add(lblConditionJointure);
		
		JLabel lblAttribut = new JLabel("Attribut");
		lblAttribut.setBounds(417, 43, 53, 14);
		panelApplication.add(lblAttribut);
		
		JLabel lblAttribut_1 = new JLabel("Attribut");
		lblAttribut_1.setBounds(417, 74, 53, 14);
		panelApplication.add(lblAttribut_1);
		
		JLabel lblOperation = new JLabel("Operation");
		lblOperation.setBounds(417, 105, 53, 14);
		panelApplication.add(lblOperation);
		
		comboBoxAttributTable1 = new JComboBox<String>();
		comboBoxAttributTable1.setBounds(496, 40, 99, 20);
		panelApplication.add(comboBoxAttributTable1);
		
		comboBoxAttributTable2 = new JComboBox<String>();
		comboBoxAttributTable2.setBounds(496, 71, 99, 20);
		panelApplication.add(comboBoxAttributTable2);
		
		comboBoxOperation = new JComboBox<String>();
		comboBoxOperation.setBounds(496, 102, 99, 20);
		panelApplication.add(comboBoxOperation);
		
		labelValidJointure = new JLabel("");
		labelValidJointure.setBounds(283, 173, 99, 14);
		panelApplication.add(labelValidJointure);
		
		textPaneExplication = new JTextPane();
		textPaneExplication.setEditable(false);
		textPaneExplication.setBounds(283, 198, 172, 63);
		panelApplication.add(textPaneExplication);
		tabbedPane.setEnabledAt(1, false);
		
		panelAffichage = new JPanel();
		tabbedPane.addTab("Affichage", null, panelAffichage, null);
		tabbedPane.setEnabledAt(2, false);
		panelAffichage.setLayout(null);
		
		comboBoxTableAffichable = new JComboBox<String>();
		comboBoxTableAffichable.setBounds(171, 375, 91, 20);
		panelAffichage.add(comboBoxTableAffichable);
		
		btnAfficher = new JButton("Afficher");
		btnAfficher.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				modele.GetTable((String)comboBoxTableAffichable.getSelectedItem()).Affiche(textAreaAffichage);
			}
		});
		btnAfficher.setBounds(308, 374, 91, 23);
		panelAffichage.add(btnAfficher);
		
		JScrollPane scrollPane_1 = new JScrollPane();
		scrollPane_1.setBounds(0, 0, 676, 364);
		panelAffichage.add(scrollPane_1);
		
		textAreaAffichage = new JTextArea();
		scrollPane_1.setViewportView(textAreaAffichage);
		textAreaAffichage.setRows(20);
		textAreaAffichage.setColumns(84);
		
		JLabel lblLgende = new JLabel("L\u00E9gende :");
		lblLgende.setBounds(25, 408, 74, 14);
		panelAffichage.add(lblLgende);
		
		JLabel lblX = new JLabel("X = Taille de la valeur Y");
		lblX.setBounds(222, 408, 140, 14);
		panelAffichage.add(lblX);
		
		JLabel lblXy = new JLabel("X************Y ");
		lblXy.setBounds(91, 408, 97, 14);
		panelAffichage.add(lblXy);
		
		panelResultat = new JPanel();
		tabbedPane.addTab("Resultat", null, panelResultat, null);
		tabbedPane.setEnabledAt(3, false);
		panelResultat.setLayout(null);
		
		scrollPane_2 = new JScrollPane();
		scrollPane_2.setBounds(10, 11, 658, 411);
		panelResultat.add(scrollPane_2);
		
		tableResultat = new JTable();
		scrollPane_2.setViewportView(tableResultat);
		
		panelMemoire = new JPanel();
		tabbedPane.addTab("Sortie Memoire", null, panelMemoire, null);
		tabbedPane.setEnabledAt(4, false);
		panelMemoire.setLayout(null);
		
		JScrollPane scrollPane_3 = new JScrollPane();
		scrollPane_3.setBounds(10, 11, 658, 411);
		panelMemoire.add(scrollPane_3);
		
		textAreaSortieMemoire = new JTextArea();
		scrollPane_3.setViewportView(textAreaSortieMemoire);
		
		panelSortieJointure = new JPanel();
		tabbedPane.addTab("Sortie Jointure", null, panelSortieJointure, null);
		tabbedPane.setEnabledAt(5, false);
		panelSortieJointure.setLayout(null);
		
		scrollPane_4 = new JScrollPane();
		scrollPane_4.setBounds(10, 5, 658, 417);
		panelSortieJointure.add(scrollPane_4);
		
		textAreaSortieJointure = new JTextArea();
		scrollPane_4.setViewportView(textAreaSortieJointure);
		
	}

	@Override
	public void MiseAJour(Sujet s) {

			MAJ = true;
			Map<String,String> tables = modele.GetTablesBD();
			
			DefaultTableModel model = new DefaultTableModel(new Object[][] {
															},
															new String[] {
																"Nom Table", "Statut"
															});
			
			for(String t : tables.keySet()){
				model.addRow(new Object[]{t, tables.get(t)});
			}
			
			tableListTableBd.setModel(model);
			
			comboBoxListTableCharger.removeAllItems();
			comboBoxListTableCharger_1.removeAllItems();
			comboBoxTableAffichable.removeAllItems();
			
			for(String t : modele.GetTableCharger()){
				comboBoxListTableCharger.addItem(t);
				comboBoxListTableCharger_1.addItem(t);
				comboBoxTableAffichable.addItem(t);
			}
			
			comboBoxListTableCharger.setSelectedIndex(-1);
			comboBoxListTableCharger_1.setSelectedIndex(-1);
			
			comboBoxListTableNoCharg.removeAllItems();
			for(String t : modele.GetTableNonCharger()){
				comboBoxListTableNoCharg.addItem(t);
			}
			
			if(comboBoxTypeJointure.getItemCount() != TypeJointure.values().length){
				comboBoxTypeJointure.removeAllItems();
				for(TypeJointure t : TypeJointure.values()){
					comboBoxTypeJointure.addItem(t);
				}
			}
			
			if(comboBoxOperation.getItemCount() != TypeCondition.values().length){
				comboBoxOperation.removeAllItems();
				for(TypeCondition t : TypeCondition.values()){
					comboBoxOperation.addItem(TypeCondition.ToString(t));
				}
			}

			if(comboBoxListTableCharger.getSelectedIndex()!=-1){
				comboBoxAttributTable1.removeAllItems();
				//recupere la table dans la premiere combobox puis on recupere ces attributs
				for(String a : modele.GetTable((String)comboBoxListTableCharger.getSelectedItem()).GetAttributDefinition().keySet()){
					comboBoxAttributTable1.addItem(a);
				}
				comboBoxAttributTable1.setSelectedIndex(-1);
			}
			
			
			if(comboBoxListTableCharger_1.getSelectedIndex()!=-1){
				comboBoxAttributTable2.removeAllItems();
				//recupere la table dans la deuxieme combobox puis on recupere ces attributs
				for(String a : modele.GetTable((String)comboBoxListTableCharger_1.getSelectedItem()).GetAttributDefinition().keySet()){
					comboBoxAttributTable2.addItem(a);
				}
				comboBoxAttributTable2.setSelectedIndex(-1);
			}
			
			MAJ = false;
			
	}
}
