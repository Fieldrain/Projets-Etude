unit personnage;

interface

uses SysUtils, Windows, gestion_inventaire, montype;

var
  nom_perso, chapitre: machaine;
  PV_perso, max_pv: smallint;
  max_energie, level_perso, xp_levelup, esquive_perso, resistance_perso,
    argent_perso, energie_perso, degat_arme, vitesse_perso, force_perso,
    concentration_perso, precision_perso, discretion_perso, checkpoint,
    sous_checkpoint, xp: smallint;

procedure initialisation;

function get_chapitre: machaine;

procedure modif_chapitre(n: machaine);

function get_nom_perso: machaine;

procedure modif_nom_perso(n: machaine);

function get_argent_perso: smallint;

procedure modif_argent_perso(n: smallint);

function get_resistance_perso: smallint;

procedure modif_resistance_perso(n, c: smallint);

function get_esquive_perso: smallint;

procedure modif_esquive_perso(n: smallint);

function get_PV_perso: smallint;

procedure modif_PV_perso(n, c: smallint);

function get_energie_perso: smallint;

procedure modif_energie_perso(n: smallint);

function get_vitesse_perso: smallint;

procedure modif_vitesse_perso(n, c: smallint);

function get_force_perso: smallint;

procedure modif_force_perso(n: smallint);

function get_concentration_perso: smallint;

procedure modif_concentration_perso(n: smallint);

function get_precision_perso: smallint;

procedure modif_precision_perso(n, c: smallint);

function get_discretion_perso: smallint;

procedure modif_discretion_perso(n, c: smallint);

function get_checkpoint: smallint;

procedure modif_checkpoint(n: smallint);

function get_sous_checkpoint: smallint;

procedure modif_sous_checkpoint(n: smallint);

function get_degat_arme_perso: smallint;

function get_xp_perso: smallint;

procedure modif_xp_perso(n: smallint);

function get_xp_levelup: smallint;

procedure modif_xp_levelup(n: smallint);

function get_level_perso: smallint;

procedure modif_level_perso(n: smallint);

function get_max_pv: smallint;

procedure modif_max_pv(n: smallint);

function get_max_energie: smallint;

procedure modif_max_energie(n: smallint);

function min(nb1: smallint): smallint;

function max(nb1, nb2: smallint): smallint;

procedure modif_degat_arme_perso;

implementation

procedure initialisation;
begin
  // initialisation vendeur
  modif_quantite_objet_1_v(0);
  modif_quantite_objet_2_v(0);
  modif_quantite_objet_3_v(0);
  modif_prix_objet_1_v(25);
  modif_prix_objet_2_v(5);
  modif_prix_objet_3_v(4);
  modif_quantite_arme_1_v(0);
  modif_quantite_arme_2_v(0);
  modif_quantite_arme_3_v(0);
  modif_quantite_arme_4_v(0);
  modif_quantite_arme_5_v(0);
  modif_prix_arme_1_v(3);
  modif_prix_arme_2_v(6);
  modif_prix_arme_3_v(35);
  modif_prix_arme_4_v(15);
  modif_prix_arme_5_v(25);
  modif_prix_amelioration_1_v(20);
  modif_prix_amelioration_2_v(10);
  modif_prix_amelioration_3_v(15);
  modif_argent_v(1000);
  // initialisation perso
  nom_perso := '';
  modif_amelioration_pompe(0);
  modif_amelioration_rev(0);
  modif_amelioration_fusil(0);
  modif_id_armure(0);
  modif_id_arme_principale(0);
  modif_id_arme_cac(1);
  modif_quantite_objet_1_perso(0);
  modif_quantite_objet_2_perso(0);
  modif_quantite_objet_3_perso(0);
  modif_xp_levelup(100);
  max_pv := 250;
  max_energie := 100;
  argent_perso := 35;
  checkpoint := 0;
  sous_checkpoint := 0;
  chapitre := '';
  PV_perso := 250;
  energie_perso := 100;
  concentration_perso := 50;
  force_perso := 45;
  esquive_perso := 20;
  precision_perso := 50;
  vitesse_perso := 40;
  discretion_perso := 20;
  degat_arme := get_degat_arme;
  resistance_perso := 40;
  xp := 0;
  level_perso := 1;
end;

function get_chapitre: machaine;
begin
  get_chapitre := chapitre;
end;

procedure modif_chapitre(n: machaine);
begin
  chapitre := n;
end;

function get_nom_perso: machaine;
begin
  get_nom_perso := nom_perso;
end;

procedure modif_nom_perso(n: machaine);
begin
  nom_perso := n;
end;

function get_argent_perso: smallint;
begin
  get_argent_perso := argent_perso;
end;

procedure modif_argent_perso(n: smallint);
begin
  argent_perso := n;
end;

function get_resistance_perso: smallint;
begin
  get_resistance_perso := resistance_perso;
end;

procedure modif_resistance_perso(n, c: smallint);
begin
  if c = 0 then
    resistance_perso := n
  Else
    resistance_perso := get_resistance_perso + get_resistance_armure;
end;

function get_esquive_perso: smallint;
begin
  get_esquive_perso := esquive_perso;
end;

procedure modif_esquive_perso(n: smallint);
begin
  esquive_perso := n;
end;

function get_PV_perso: smallint;
begin
  get_PV_perso := PV_perso;
end;

procedure modif_PV_perso(n, c: smallint);
begin
  if c = 0 then
    PV_perso := n
  Else
    PV_perso := get_PV_perso + get_amelioration_PV;
end;

function get_energie_perso: smallint;
begin
  get_energie_perso := energie_perso;
end;

procedure modif_energie_perso(n: smallint);
begin
  energie_perso := n;
end;

function get_vitesse_perso: smallint;
begin
  get_vitesse_perso := vitesse_perso;
end;

procedure modif_vitesse_perso(n, c: smallint);
begin
  if c = 0 then
    vitesse_perso := n
  Else
    vitesse_perso := get_vitesse_perso + get_amelioration_vitesse;
end;

function get_force_perso: smallint;
begin
  get_force_perso := force_perso;
end;

procedure modif_force_perso(n: smallint);
begin
  force_perso := n;
end;

function get_concentration_perso: smallint;
begin
  get_concentration_perso := concentration_perso;
end;

procedure modif_concentration_perso(n: smallint);
begin
  concentration_perso := n;
end;

function get_precision_perso: smallint;
begin
  get_precision_perso := precision_perso;
end;

procedure modif_precision_perso(n, c: smallint);
begin
  if c = 0 then
    precision_perso := n
  Else
    precision_perso := get_precision_perso + get_amelioration_precision;
end;

function get_discretion_perso: smallint;
begin
  get_discretion_perso := discretion_perso;
end;

procedure modif_discretion_perso(n, c: smallint);
begin
  if c = 0 then
    discretion_perso := n
  Else
    discretion_perso := get_discretion_perso + get_amelioration_discretion;
end;

function get_checkpoint: smallint;
begin
  get_checkpoint := checkpoint;
end;

procedure modif_checkpoint(n: smallint);
begin
  checkpoint := n;
end;

function get_sous_checkpoint: smallint;
begin
  get_sous_checkpoint := sous_checkpoint;
end;

procedure modif_sous_checkpoint(n: smallint);
begin
  sous_checkpoint := n;
end;

function get_degat_arme_perso: smallint;
begin
  get_degat_arme_perso := get_degat_arme;
end;

procedure modif_degat_arme_perso;
begin
  degat_arme := get_degat_arme;
end;

function get_xp_perso: smallint;
begin
  get_xp_perso := xp;
end;

procedure modif_xp_perso(n: smallint);
begin
  xp := n;
end;

function get_xp_levelup: smallint;
begin
  get_xp_levelup := xp_levelup;
end;

procedure modif_xp_levelup(n: smallint);
begin
  xp_levelup := n;
end;

function get_level_perso: smallint;
begin
  get_level_perso := level_perso;
end;

procedure modif_level_perso(n: smallint);
begin
  level_perso := n;
end;

function get_max_pv: smallint;
begin
  get_max_pv := max_pv;
end;

procedure modif_max_pv(n: smallint);
begin
  max_pv := n;
end;

function get_max_energie: smallint;
begin
  get_max_energie := max_energie;
end;

procedure modif_max_energie(n: smallint);
begin
  max_energie := n;
end;

function min(nb1: smallint): smallint;
begin
  if nb1 < 0 then
  begin
    min := 0;
  end
  Else
  begin
    min := nb1;
  end;
end;

function max(nb1, nb2: smallint): smallint;
begin
  if nb1 > nb2 then
  begin
    max := nb2;
  end
  Else
  begin
    max := nb1;
  end;
end;

end.
