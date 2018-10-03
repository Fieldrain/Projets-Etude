unit save_chargement;

interface

uses SysUtils, Windows, personnage, gestion_inventaire, montype;

var
  save: text;
  nom, chapitre: machaine;
  pv, max_pv, max_energie, level, xp_levelup, esquive, resistance, argent,
    energie, vitesse, force, concentration, precision, discretion, checkpoint,
    sous_checkpoint, xp: smallint;
  argent_v: smallint;
  quantite_objet_1_perso, quantite_objet_2_perso,
    quantite_objet_3_perso: smallint;
  quantite_objet_1_v, quantite_objet_2_v, quantite_objet_3_v: smallint;
  id_arme_principale, id_arme_cac, id_armure: shortint;
  amelioration_pompe, amelioration_rev, amelioration_fusil: smallint;

procedure sauvegarde;

procedure save_objet;

procedure chargement;

procedure chargement_combat;

implementation

procedure sauvegarde;
begin
  nom := get_nom_perso;
  pv := get_pv_perso;
  max_pv := get_max_pv;
  energie := get_energie_perso;
  max_energie := get_max_energie;
  argent := get_argent_perso;
  level := get_level_perso;
  xp := get_xp_perso;
  xp_levelup := get_xp_levelup;
  checkpoint := get_checkpoint;
  sous_checkpoint := get_sous_checkpoint;
  chapitre := get_chapitre;
  concentration := get_concentration_perso;
  discretion := get_discretion_perso;
  esquive := get_esquive_perso;
  force := get_force_perso;
  precision := get_precision_perso;
  resistance := get_resistance_perso;

  // equipement&sac
  quantite_objet_1_perso := get_quantite_objet_1_perso;
  quantite_objet_2_perso := get_quantite_objet_2_perso;
  quantite_objet_3_perso := get_quantite_objet_3_perso;
  quantite_arme_1_perso := get_quantite_arme_1_perso;
  quantite_arme_2_perso := get_quantite_arme_2_perso;
  quantite_arme_3_perso := get_quantite_arme_3_perso;
  quantite_arme_4_perso := get_quantite_arme_4_perso;
  quantite_arme_5_perso := get_quantite_arme_5_perso;
  id_arme_principale := get_id_arme_principale;
  id_arme_cac := get_id_arme_cac;
  id_armure := get_id_armure;
  amelioration_pompe := get_amelioration_pompe;
  amelioration_rev := get_amelioration_pompe;
  amelioration_fusil := get_amelioration_pompe;

  // vendeur
  quantite_arme_1_v := get_quantite_arme_1_v;
  quantite_arme_2_v := get_quantite_arme_2_v;
  quantite_arme_3_v := get_quantite_arme_3_v;
  quantite_arme_4_v := get_quantite_arme_4_v;
  quantite_arme_5_v := get_quantite_arme_5_v;
  quantite_objet_1_v := get_quantite_objet_1_v;
  quantite_objet_2_v := get_quantite_objet_2_v;
  quantite_objet_3_v := get_quantite_objet_3_v;
  argent_v := get_argent_v;

  writeln(save, nom);
  writeln(save, pv);
  writeln(save, max_pv);
  writeln(save, energie);
  writeln(save, max_energie);
  writeln(save, argent);
  writeln(save, level);
  writeln(save, xp);
  writeln(save, xp_levelup);
  writeln(save, checkpoint);
  writeln(save, sous_checkpoint);
  writeln(save, chapitre);
  writeln(save, concentration);
  writeln(save, discretion);
  writeln(save, esquive);
  writeln(save, force);
  writeln(save, precision);
  writeln(save, resistance);
  writeln(save, quantite_objet_1_perso);
  writeln(save, quantite_objet_2_perso);
  writeln(save, quantite_objet_3_perso);
  writeln(save, quantite_arme_1_perso);
  writeln(save, quantite_arme_2_perso);
  writeln(save, quantite_arme_3_perso);
  writeln(save, quantite_arme_4_perso);
  writeln(save, quantite_arme_5_perso);
  writeln(save, id_arme_principale);
  writeln(save, id_arme_cac);
  writeln(save, id_armure);
  writeln(save, amelioration_pompe);
  writeln(save, amelioration_rev);
  writeln(save, amelioration_fusil);
  writeln(save, quantite_objet_1_v);
  writeln(save, quantite_objet_2_v);
  writeln(save, quantite_objet_3_v);
  writeln(save, quantite_arme_1_v);
  writeln(save, quantite_arme_2_v);
  writeln(save, quantite_arme_3_v);
  writeln(save, quantite_arme_4_v);
  writeln(save, quantite_arme_5_v);
  writeln(save, argent_v);

  close(save);
end;

procedure chargement;
begin
  reset(save);

  readln(save, nom);
  modif_nom_perso(nom);

  readln(save, pv);
  modif_pv_perso(pv, 0);

  readln(save, max_pv);
  modif_max_pv(max_pv);

  readln(save, energie);
  modif_energie_perso(energie);

  readln(save, max_energie);
  modif_max_energie(max_energie);

  readln(save, argent);
  modif_argent_perso(argent);

  readln(save, level);
  modif_level_perso(level);

  readln(save, xp);
  modif_xp_perso(xp);

  readln(save, xp_levelup);
  modif_xp_levelup(xp_levelup);

  readln(save, checkpoint);
  modif_checkpoint(checkpoint);

  readln(save, sous_checkpoint);
  modif_sous_checkpoint(sous_checkpoint);

  readln(save, chapitre);
  modif_chapitre(chapitre);

  readln(save, concentration);
  modif_concentration_perso(concentration);

  readln(save, discretion);
  modif_discretion_perso(discretion, 0);

  readln(save, esquive);
  modif_esquive_perso(esquive);

  readln(save, force);
  modif_force_perso(force);

  readln(save, precision);
  modif_precision_perso(precision, 0);

  readln(save, resistance);
  modif_resistance_perso(resistance, 0);

  readln(save, quantite_objet_1_perso);
  modif_quantite_objet_1_perso(quantite_objet_1_perso);

  readln(save, quantite_objet_2_perso);
  modif_quantite_objet_2_perso(quantite_objet_2_perso);

  readln(save, quantite_objet_3_perso);
  modif_quantite_objet_3_perso(quantite_objet_3_perso);

  readln(save, quantite_arme_1_perso);
  modif_quantite_arme_1_perso(quantite_arme_1_perso);

  readln(save, quantite_arme_2_perso);
  modif_quantite_arme_2_perso(quantite_arme_2_perso);

  readln(save, quantite_arme_3_perso);
  modif_quantite_arme_3_perso(quantite_arme_3_perso);

  readln(save, quantite_arme_4_perso);
  modif_quantite_arme_4_perso(quantite_arme_4_perso);

  readln(save, quantite_arme_5_perso);
  modif_quantite_arme_5_perso(quantite_arme_5_perso);

  readln(save, id_arme_principale);
  modif_id_arme_principale(id_arme_principale);

  readln(save, id_arme_cac);
  modif_id_arme_cac(id_arme_cac);

  readln(save, id_armure);
  modif_id_armure(id_armure);

  readln(save, amelioration_pompe);
  modif_amelioration_pompe(amelioration_pompe);

  readln(save, amelioration_rev);
  modif_amelioration_rev(amelioration_rev);

  readln(save, amelioration_fusil);
  modif_amelioration_fusil(amelioration_fusil);

  readln(save, quantite_objet_1_v);
  modif_quantite_objet_1_v(quantite_objet_1_v);

  readln(save, quantite_objet_2_v);
  modif_quantite_objet_2_v(quantite_objet_2_v);

  readln(save, quantite_objet_3_v);
  modif_quantite_objet_3_v(quantite_objet_3_v);

  readln(save, quantite_arme_1_v);
  modif_quantite_arme_1_v(quantite_arme_1_v);

  readln(save, quantite_arme_2_v);
  modif_quantite_arme_2_v(quantite_arme_2_v);

  readln(save, quantite_arme_3_v);
  modif_quantite_arme_3_v(quantite_arme_3_v);

  readln(save, quantite_arme_4_v);
  modif_quantite_arme_4_v(quantite_arme_4_v);

  readln(save, quantite_arme_5_v);
  modif_quantite_arme_5_v(quantite_arme_5_v);

  readln(save, argent_v);
  modif_argent_v(argent_v);

  close(save);
end;

procedure chargement_combat;
begin
  reset(save);

  readln(save, nom);
  modif_nom_perso(nom);

  readln(save, pv);

  readln(save, max_pv);
  modif_max_pv(max_pv);

  readln(save, energie);
  modif_energie_perso(energie);

  readln(save, max_energie);
  modif_max_energie(max_energie);

  readln(save, argent);
  modif_argent_perso(argent);

  readln(save, level);
  modif_level_perso(level);

  readln(save, xp);
  modif_xp_perso(xp);

  readln(save, xp_levelup);
  modif_xp_levelup(xp_levelup);

  readln(save, checkpoint);
  modif_checkpoint(checkpoint);

  readln(save, sous_checkpoint);
  modif_sous_checkpoint(sous_checkpoint);

  readln(save, chapitre);
  modif_chapitre(chapitre);

  readln(save, concentration);
  modif_concentration_perso(concentration);

  readln(save, discretion);
  modif_discretion_perso(discretion, 0);

  readln(save, esquive);
  modif_esquive_perso(esquive);

  readln(save, force);
  modif_force_perso(force);

  readln(save, precision);
  modif_precision_perso(precision, 0);

  readln(save, resistance);
  modif_resistance_perso(resistance, 0);

  readln(save, quantite_objet_1_perso);
  modif_quantite_objet_1_perso(quantite_objet_1_perso);

  readln(save, quantite_objet_2_perso);
  modif_quantite_objet_2_perso(quantite_objet_2_perso);

  readln(save, quantite_objet_3_perso);
  modif_quantite_objet_3_perso(quantite_objet_3_perso);

  readln(save, quantite_arme_1_perso);
  modif_quantite_arme_1_perso(quantite_arme_1_perso);

  readln(save, quantite_arme_2_perso);
  modif_quantite_arme_2_perso(quantite_arme_2_perso);

  readln(save, quantite_arme_3_perso);
  modif_quantite_arme_3_perso(quantite_arme_3_perso);

  readln(save, quantite_arme_4_perso);
  modif_quantite_arme_4_perso(quantite_arme_4_perso);

  readln(save, quantite_arme_5_perso);
  modif_quantite_arme_5_perso(quantite_arme_5_perso);

  readln(save, id_arme_principale);
  modif_id_arme_principale(id_arme_principale);

  readln(save, id_arme_cac);
  modif_id_arme_cac(id_arme_cac);

  readln(save, id_armure);
  modif_id_armure(id_armure);

  readln(save, amelioration_pompe);
  modif_amelioration_pompe(amelioration_pompe);

  readln(save, amelioration_rev);
  modif_amelioration_rev(amelioration_rev);

  readln(save, amelioration_fusil);
  modif_amelioration_fusil(amelioration_fusil);

  close(save);
end;

procedure save_objet;
begin
  nom := get_nom_perso;
  pv := get_pv_perso;
  max_pv := get_max_pv;
  energie := get_energie_perso;
  max_energie := get_max_energie;
  argent := get_argent_perso;
  level := get_level_perso;
  xp := get_xp_perso;
  xp_levelup := get_xp_levelup;
  checkpoint := get_checkpoint;
  sous_checkpoint := get_sous_checkpoint;
  chapitre := get_chapitre;
  concentration := get_concentration_perso;
  discretion := get_discretion_perso;
  esquive := get_esquive_perso;
  force := get_force_perso;
  precision := get_precision_perso;
  resistance := get_resistance_perso;

  // equipement&sac
  quantite_objet_1_perso := get_quantite_objet_1_perso;
  quantite_objet_2_perso := get_quantite_objet_2_perso;
  quantite_objet_3_perso := get_quantite_objet_3_perso;
  quantite_arme_1_perso := get_quantite_arme_1_perso;
  quantite_arme_2_perso := get_quantite_arme_2_perso;
  quantite_arme_3_perso := get_quantite_arme_3_perso;
  quantite_arme_4_perso := get_quantite_arme_4_perso;
  quantite_arme_5_perso := get_quantite_arme_5_perso;
  id_arme_principale := get_id_arme_principale;
  id_arme_cac := get_id_arme_cac;
  id_armure := get_id_armure;
  amelioration_pompe := get_amelioration_pompe;
  amelioration_rev := get_amelioration_pompe;
  amelioration_fusil := get_amelioration_pompe;

  // vendeur
  quantite_arme_1_v := get_quantite_arme_1_v;
  quantite_arme_2_v := get_quantite_arme_2_v;
  quantite_arme_3_v := get_quantite_arme_3_v;
  quantite_arme_4_v := get_quantite_arme_4_v;
  quantite_arme_5_v := get_quantite_arme_5_v;
  quantite_objet_1_v := get_quantite_objet_1_v;
  quantite_objet_2_v := get_quantite_objet_2_v;
  quantite_objet_3_v := get_quantite_objet_3_v;
  argent_v := get_argent_v;

  writeln(save, nom);
  writeln(save, pv);
  writeln(save, max_pv);
  writeln(save, max_energie);
  writeln(save, max_energie);
  writeln(save, argent);
  writeln(save, level);
  writeln(save, xp);
  writeln(save, xp_levelup);
  writeln(save, checkpoint);
  writeln(save, sous_checkpoint);
  writeln(save, chapitre);
  writeln(save, concentration);
  writeln(save, discretion);
  writeln(save, esquive);
  writeln(save, force);
  writeln(save, precision);
  writeln(save, resistance);
  writeln(save, quantite_objet_1_perso);
  writeln(save, quantite_objet_2_perso);
  writeln(save, quantite_objet_3_perso);
  writeln(save, quantite_arme_1_perso);
  writeln(save, quantite_arme_2_perso);
  writeln(save, quantite_arme_3_perso);
  writeln(save, quantite_arme_4_perso);
  writeln(save, quantite_arme_5_perso);
  writeln(save, id_arme_principale);
  writeln(save, id_arme_cac);
  writeln(save, id_armure);
  writeln(save, amelioration_pompe);
  writeln(save, amelioration_rev);
  writeln(save, amelioration_fusil);
  writeln(save, quantite_objet_1_v);
  writeln(save, quantite_objet_2_v);
  writeln(save, quantite_objet_3_v);
  writeln(save, quantite_arme_1_v);
  writeln(save, quantite_arme_2_v);
  writeln(save, quantite_arme_3_v);
  writeln(save, quantite_arme_4_v);
  writeln(save, quantite_arme_5_v);
  writeln(save, argent_v);

  close(save);
end;

end.
