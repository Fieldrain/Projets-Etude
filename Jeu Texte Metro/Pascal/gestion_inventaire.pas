unit gestion_inventaire;

interface

uses montype;

var
  argent_v: smallint;
  quantite_objet_1_perso, quantite_objet_2_perso, quantite_objet_3_perso,
    quantite_arme_1_perso, quantite_arme_2_perso, quantite_arme_3_perso,
    quantite_arme_4_perso, quantite_arme_5_perso: smallint;
  quantite_objet_1_v, quantite_objet_2_v, quantite_objet_3_v,
    quantite_arme_1_v, quantite_arme_2_v, quantite_arme_3_v,
    quantite_arme_4_v, quantite_arme_5_v: smallint;
  prix_objet_1_v, prix_objet_2_v, prix_objet_3_v, prix_arme_1_v, prix_arme_2_v,
    prix_arme_3_v, prix_arme_4_v, prix_arme_5_v, prix_amelioration_1,
    prix_amelioration_2, prix_amelioration_3: smallint;
  id_arme_principale, id_arme_cac, id_armure: shortint;
  arme_principale: machaine;
  degat_arme_principale: smallint;
  arme_cac: machaine;
  degat_arme_cac: smallint;
  armure: machaine;
  degat_arme_selectionner: smallint;
  amelioration_pompe, amelioration_rev, amelioration_fusil: smallint;
  amelioration_degat, amelioration_PV, amelioration_vitesse,
    amelioration_precision, amelioration_discretion, resitance_armure: smallint;

  // consomable

function get_quantite_objet_1_perso: smallint;

procedure modif_quantite_objet_1_perso(n: smallint);

function get_quantite_objet_2_perso: smallint;

procedure modif_quantite_objet_2_perso(n: smallint);

function get_quantite_objet_3_perso: smallint;

procedure modif_quantite_objet_3_perso(n: smallint);

function get_argent_v: smallint;

procedure modif_argent_v(n: smallint);

function get_quantite_objet_1_v: smallint;

procedure modif_quantite_objet_1_v(n: smallint);

function get_prix_objet_1_v: smallint;

procedure modif_prix_objet_1_v(n: smallint);

function get_quantite_objet_2_v: smallint;

procedure modif_quantite_objet_2_v(n: smallint);

function get_prix_objet_2_v: smallint;

procedure modif_prix_objet_2_v(n: smallint);

function get_quantite_objet_3_v: smallint;

procedure modif_quantite_objet_3_v(n: smallint);

function get_prix_objet_3_v: smallint;

procedure modif_prix_objet_3_v(n: smallint);

function get_nom_objet_1: machaine;

function get_nom_objet_2: machaine;

function get_nom_objet_3: machaine;

function get_description_objet_1: machaine;

function get_description_objet_2: machaine;

function get_description_objet_3: machaine;

// arme et equipement

function get_prix_amelioration_1_v: smallint;

procedure modif_prix_amelioration_1_v(n: smallint);

function get_prix_amelioration_2_v: smallint;

procedure modif_prix_amelioration_2_v(n: smallint);

function get_prix_amelioration_3_v: smallint;

procedure modif_prix_amelioration_3_v(n: smallint);

function get_quantite_arme_1_perso: smallint;

procedure modif_quantite_arme_1_perso(n: smallint);

function get_quantite_arme_2_perso: smallint;

procedure modif_quantite_arme_2_perso(n: smallint);

function get_quantite_arme_3_perso: smallint;

procedure modif_quantite_arme_3_perso(n: smallint);

function get_quantite_arme_4_perso: smallint;

procedure modif_quantite_arme_4_perso(n: smallint);

function get_quantite_arme_5_perso: smallint;

procedure modif_quantite_arme_5_perso(n: smallint);

function get_nom_arme_1: machaine;

function get_nom_arme_2: machaine;

function get_nom_arme_3: machaine;

function get_nom_arme_4: machaine;

function get_nom_arme_5: machaine;

function get_quantite_arme_1_v: smallint;

procedure modif_quantite_arme_1_v(n: smallint);

function get_quantite_arme_2_v: smallint;

procedure modif_quantite_arme_2_v(n: smallint);

function get_quantite_arme_3_v: smallint;

procedure modif_quantite_arme_3_v(n: smallint);

function get_quantite_arme_4_v: smallint;

procedure modif_quantite_arme_4_v(n: smallint);

function get_quantite_arme_5_v: smallint;

procedure modif_quantite_arme_5_v(n: smallint);

function get_prix_arme_1_v: smallint;

procedure modif_prix_arme_1_v(n: smallint);

function get_prix_arme_2_v: smallint;

procedure modif_prix_arme_2_v(n: smallint);

function get_prix_arme_3_v: smallint;

procedure modif_prix_arme_3_v(n: smallint);

function get_prix_arme_4_v: smallint;

procedure modif_prix_arme_4_v(n: smallint);

function get_prix_arme_5_v: smallint;

procedure modif_prix_arme_5_v(n: smallint);

procedure arme;

function get_degat_arme: smallint;

procedure selec_arme_cac;

procedure selec_arme_principale;

procedure selec_armure;

procedure equipement;

function get_id_arme_principale: smallint;

procedure modif_id_arme_principale(n: smallint);

function get_id_arme_cac: smallint;

procedure modif_id_arme_cac(n: smallint);

function get_id_armure: smallint;

procedure modif_id_armure(n: smallint);

function get_amelioration_PV: smallint;

procedure modif_amelioration_PV(n: smallint);

function get_amelioration_discretion: smallint;

procedure modif_amelioration_discretion(n: smallint);

function get_amelioration_vitesse: smallint;

procedure modif_amelioration_vitesse(n: smallint);

function get_amelioration_precision: smallint;

procedure modif_amelioration_precision(n: smallint);

function get_amelioration_degat: smallint;

procedure modif_amelioration_degat(n: smallint);

procedure modif_amelioration_pompe(n: smallint);

procedure modif_amelioration_rev(n: smallint);

procedure modif_amelioration_fusil(n: smallint);

function get_amelioration_pompe: smallint;

function get_amelioration_rev: smallint;

function get_amelioration_fusil: smallint;

function get_resistance_armure: smallint;

implementation

// consomable

function get_quantite_objet_1_perso: smallint;
begin
  get_quantite_objet_1_perso := quantite_objet_1_perso;
end;

procedure modif_quantite_objet_1_perso(n: smallint);
begin
  quantite_objet_1_perso := n;
end;

function get_quantite_objet_2_perso: smallint;
begin
  get_quantite_objet_2_perso := quantite_objet_2_perso;
end;

procedure modif_quantite_objet_2_perso(n: smallint);
begin
  quantite_objet_2_perso := n;
end;

function get_quantite_objet_3_perso: smallint;
begin
  get_quantite_objet_3_perso := quantite_objet_3_perso;
end;

procedure modif_quantite_objet_3_perso(n: smallint);
begin
  quantite_objet_3_perso := n;
end;

function get_argent_v: smallint;
begin
  get_argent_v := argent_v;
end;

procedure modif_argent_v(n: smallint);
begin
  argent_v := n;
end;

function get_nom_objet_1: machaine;
begin
  get_nom_objet_1 := 'Médipack';
end;

function get_nom_objet_2: machaine;
begin
  get_nom_objet_2 := 'Viande';
end;

function get_nom_objet_3: machaine;
begin
  get_nom_objet_3 := 'Thé';
end;

function get_description_objet_1: machaine;
begin
  get_description_objet_1 := ' +50 PV';
end;

function get_description_objet_2: machaine;
begin
  get_description_objet_2 := ' +30 Energie';
end;

function get_description_objet_3: machaine;
begin
  get_description_objet_3 := ' +10 Vitesse';
end;

function get_quantite_objet_1_v: smallint;
begin
  get_quantite_objet_1_v := quantite_objet_1_v;
end;

procedure modif_quantite_objet_1_v(n: smallint);
begin
  quantite_objet_1_v := n;
end;

function get_prix_objet_1_v: smallint;
begin
  get_prix_objet_1_v := prix_objet_1_v;
end;

procedure modif_prix_objet_1_v(n: smallint);
begin
  prix_objet_1_v := n;
end;

function get_quantite_objet_2_v: smallint;
begin
  get_quantite_objet_2_v := quantite_objet_2_v;
end;

procedure modif_quantite_objet_2_v(n: smallint);
begin
  quantite_objet_2_v := n;
end;

function get_prix_objet_2_v: smallint;
begin
  get_prix_objet_2_v := prix_objet_2_v;
end;

procedure modif_prix_objet_2_v(n: smallint);
begin
  prix_objet_2_v := n;
end;

function get_quantite_objet_3_v: smallint;
begin
  get_quantite_objet_3_v := quantite_objet_3_v;
end;

procedure modif_quantite_objet_3_v(n: smallint);
begin
  quantite_objet_3_v := n;
end;

function get_prix_objet_3_v: smallint;
begin
  get_prix_objet_3_v := prix_objet_3_v;
end;

procedure modif_prix_objet_3_v(n: smallint);
begin
  prix_objet_3_v := n;
end;

// arme et equipement

function get_prix_amelioration_1_v: smallint;
begin
  get_prix_amelioration_1_v := prix_amelioration_1;
end;

procedure modif_prix_amelioration_1_v(n: smallint);
begin
  prix_amelioration_1 := n;
end;

function get_prix_amelioration_2_v: smallint;
begin
  get_prix_amelioration_2_v := prix_amelioration_2;
end;

procedure modif_prix_amelioration_2_v(n: smallint);
begin
  prix_amelioration_2 := n;
end;

function get_prix_amelioration_3_v: smallint;
begin
  get_prix_amelioration_3_v := prix_amelioration_3;
end;

procedure modif_prix_amelioration_3_v(n: smallint);
begin
  prix_amelioration_3 := n;
end;

function get_quantite_arme_1_perso: smallint;
begin
  get_quantite_arme_1_perso := quantite_arme_1_perso;
end;

procedure modif_quantite_arme_1_perso(n: smallint);
begin
  quantite_arme_1_perso := n;
end;

function get_quantite_arme_2_perso: smallint;
begin
  get_quantite_arme_2_perso := quantite_arme_2_perso;
end;

procedure modif_quantite_arme_2_perso(n: smallint);
begin
  quantite_arme_2_perso := n;
end;

function get_quantite_arme_3_perso: smallint;
begin
  get_quantite_arme_3_perso := quantite_arme_3_perso;
end;

procedure modif_quantite_arme_3_perso(n: smallint);
begin
  quantite_arme_3_perso := n;
end;

function get_quantite_arme_4_perso: smallint;
begin
  get_quantite_arme_4_perso := quantite_arme_4_perso;
end;

procedure modif_quantite_arme_4_perso(n: smallint);
begin
  quantite_arme_4_perso := n;
end;

function get_quantite_arme_5_perso: smallint;
begin
  get_quantite_arme_5_perso := quantite_arme_5_perso;
end;

procedure modif_quantite_arme_5_perso(n: smallint);
begin
  quantite_arme_5_perso := n;
end;

function get_nom_arme_1: machaine;
begin
  get_nom_arme_1 := 'Couteau';
end;

function get_nom_arme_2: machaine;
begin
  get_nom_arme_2 := 'Machette';
end;

function get_nom_arme_3: machaine;
begin
  get_nom_arme_3 := 'Fusil à pompe';
end;

function get_nom_arme_4: machaine;
begin
  get_nom_arme_4 := 'Révolver';
end;

function get_nom_arme_5: machaine;
begin
  get_nom_arme_5 := 'Fusil d''assault';
end;

function get_quantite_arme_1_v: smallint;
begin
  get_quantite_arme_1_v := quantite_arme_1_v;
end;

procedure modif_quantite_arme_1_v(n: smallint);
begin
  quantite_arme_1_v := n;
end;

function get_quantite_arme_2_v: smallint;
begin
  get_quantite_arme_2_v := quantite_arme_2_v;
end;

procedure modif_quantite_arme_2_v(n: smallint);
begin
  quantite_arme_2_v := n;
end;

function get_quantite_arme_3_v: smallint;
begin
  get_quantite_arme_3_v := quantite_arme_3_v;
end;

procedure modif_quantite_arme_3_v(n: smallint);
begin
  quantite_arme_3_v := n;
end;

function get_quantite_arme_4_v: smallint;
begin
  get_quantite_arme_4_v := quantite_arme_4_v;
end;

procedure modif_quantite_arme_4_v(n: smallint);
begin
  quantite_arme_4_v := n;
end;

function get_quantite_arme_5_v: smallint;
begin
  get_quantite_arme_5_v := quantite_arme_5_v;
end;

procedure modif_quantite_arme_5_v(n: smallint);
begin
  quantite_arme_5_v := n;
end;

function get_prix_arme_1_v: smallint;
begin
  get_prix_arme_1_v := prix_arme_1_v;
end;

procedure modif_prix_arme_1_v(n: smallint);
begin
  prix_arme_1_v := n;
end;

function get_prix_arme_2_v: smallint;
begin
  get_prix_arme_2_v := prix_arme_2_v;
end;

procedure modif_prix_arme_2_v(n: smallint);
begin
  prix_arme_2_v := n;
end;

function get_prix_arme_3_v: smallint;
begin
  get_prix_arme_3_v := prix_arme_3_v;
end;

procedure modif_prix_arme_3_v(n: smallint);
begin
  prix_arme_3_v := n;
end;

function get_prix_arme_4_v: smallint;
begin
  get_prix_arme_4_v := prix_arme_4_v;
end;

procedure modif_prix_arme_4_v(n: smallint);
begin
  prix_arme_4_v := n;
end;

function get_prix_arme_5_v: smallint;
begin
  get_prix_arme_5_v := prix_arme_5_v;
end;

procedure modif_prix_arme_5_v(n: smallint);
begin
  prix_arme_5_v := n;
end;

procedure arme;

begin
  if (get_id_arme_principale > 0) then
  begin
    selec_arme_principale;
    degat_arme_selectionner := degat_arme_principale
  end
  Else
  begin
    selec_arme_cac;
    degat_arme_selectionner := degat_arme_cac;
  end;
end;

function get_degat_arme: smallint;
begin
  arme;
  get_degat_arme := degat_arme_selectionner + get_amelioration_degat;
end;

procedure selec_arme_cac;
begin
  if (id_arme_cac = 1) then
  begin
    arme_cac := 'Poing';
    degat_arme_cac := 5;
  end
  Else if (id_arme_cac = 2) then
  begin
    arme_cac := 'Couteau';
    degat_arme_cac := 10;
  end
  Else if (id_arme_cac = 3) then
  begin
    arme_cac := 'Machette';
    degat_arme_cac := 16;
  end;
end;

procedure selec_arme_principale;
begin
  if (id_arme_principale = 1) then
  begin
    arme_principale := 'Fusil a pompe';
    degat_arme_principale := 50;
    if (amelioration_pompe = 1) then
      amelioration_degat := 15; // degat
  end
  Else if (id_arme_principale = 2) then
  begin
    arme_principale := 'Revolver';
    degat_arme_principale := 25;
    if (amelioration_rev = 1) then
      amelioration_vitesse := 10; // vitesse
  end
  Else if (id_arme_principale = 3) then
  begin
    arme_principale := 'Fusil d''assaut';
    degat_arme_principale := 45;
    if (amelioration_fusil = 1) then
      amelioration_precision := 15; // precision
  end
  Else
  begin
    modif_amelioration_vitesse(0);
    modif_amelioration_degat(0);
    modif_amelioration_precision(0);
  end;
end;

procedure selec_armure;
begin
  if (id_armure = 1) then
  begin
    armure := 'Legere';
    amelioration_discretion := 40; // discretion
    resitance_armure := 30;
  end
  Else if (id_armure = 2) then
  begin
    armure := 'Lourde';
    amelioration_PV := 60; // PV
    resitance_armure := 50;
  end;
end;

procedure equipement;
begin
  selec_armure;
end;

function get_id_arme_principale: smallint;
begin
  get_id_arme_principale := id_arme_principale;
end;

procedure modif_id_arme_principale(n: smallint);
begin
  id_arme_principale := n;
end;

function get_id_arme_cac: smallint;
begin
  get_id_arme_cac := id_arme_cac;
end;

procedure modif_id_arme_cac(n: smallint);
begin
  id_arme_cac := n;
end;

function get_id_armure: smallint;
begin
  get_id_armure := id_armure;
end;

procedure modif_id_armure(n: smallint);
begin
  id_armure := n;
end;

function get_amelioration_PV: smallint;
begin
  equipement;
  get_amelioration_PV := amelioration_PV;
end;

procedure modif_amelioration_PV(n: smallint);
begin
  amelioration_PV := n;
end;

function get_amelioration_discretion: smallint;
begin
  equipement;
  get_amelioration_discretion := amelioration_discretion;
end;

procedure modif_amelioration_discretion(n: smallint);
begin
  amelioration_discretion := n;
end;

function get_resistance_armure: smallint;
begin
  equipement;
  get_resistance_armure := resitance_armure;
end;

function get_amelioration_vitesse: smallint;
begin
  arme;
  get_amelioration_vitesse := amelioration_vitesse;
end;

procedure modif_amelioration_vitesse(n: smallint);
begin
  amelioration_vitesse := n;
end;

function get_amelioration_precision: smallint;
begin
  arme;
  get_amelioration_precision := amelioration_precision;
end;

procedure modif_amelioration_precision(n: smallint);
begin
  amelioration_precision := n;
end;

function get_amelioration_degat: smallint;
begin
  arme;
  get_amelioration_degat := amelioration_degat;
end;

procedure modif_amelioration_degat(n: smallint);
begin
  amelioration_degat := n;
end;

procedure modif_amelioration_pompe(n: smallint);
begin
  amelioration_pompe := n
end;

procedure modif_amelioration_rev(n: smallint);
begin
  amelioration_rev := n
end;

procedure modif_amelioration_fusil(n: smallint);
begin
  amelioration_fusil := n
end;

function get_amelioration_pompe: smallint;
begin
  get_amelioration_pompe := amelioration_pompe;
end;

function get_amelioration_rev: smallint;
begin
  get_amelioration_rev := amelioration_rev;
end;

function get_amelioration_fusil: smallint;
begin
  get_amelioration_fusil := amelioration_fusil;
end;

end.
