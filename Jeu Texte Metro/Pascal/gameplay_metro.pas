unit gameplay_metro;

interface

uses SysUtils, Windows, personnage, ennemi, GestionEcran, gestion_inventaire,
  save_chargement, montype;

var
  esquive, resistance, energie, degat_arme, concentration, force,
    precision: smallint;
  energie_ad, esquive_ad, reduction_degat, reduction_vitesse,
    reduction_concentration, reduction_force, reduction_precision,
    concentration_ad, vitesse_ad, force_ad, precision_ad: smallint;
  degat: smallint;
  selection_attaque: shortint;
  selection_attaque_precise_n: smallint;
  selection_attaque_precise: char;
  nb_objet: smallint;
  validation: smallint;
  nom_ad, nom: machaine;
  victoire: smallint;
  selection, selection_1: smallint;

function aleatoire(nb_1, nb_2: smallint): smallint;

procedure inventaire;

procedure gestion_coups;

procedure tour_perso;

procedure tour_e;

procedure combat(nb_combat, forcer: smallint);

function get_victoire: smallint;

procedure modif_victoire (n:smallint);

procedure vendeur;

procedure level;

procedure ajout_stat(n: smallint);

procedure drop;

implementation

function aleatoire(nb_1, nb_2: smallint): smallint; // permet de choisir un nombre aleatoire entre 2 bornes definit

begin

  randomize;
  aleatoire := random((nb_2 - nb_1) + 1) + (nb_1);

end;

procedure inventaire;
var
selection,selection_1 : smallint;
begin
  selection_1 := 0;
  while (selection_1 <> 3) do
  begin
    ecran_inventaire;
    choix_2;
    readln(selection_1);
    while (selection_1 <> 1) and (selection_1 <> 2) and (selection_1 <> 3)do
    begin
      choix_2;
      readln(selection_1);
    end;
    if selection_1 = 1 then
    begin
      choix_4;
      readln(selection);
      while (selection <> 1) and (selection <> 2) and (selection <> 3) and
        (selection <> 4) do
      begin
        choix_4;
        readln(selection);
      end;
      if (selection = 1) and (get_quantite_objet_1_perso >= 1) then
      begin
        modif_PV_perso(max(get_PV_perso + 50, get_max_pv), 0);
        modif_quantite_objet_1_perso(get_quantite_objet_1_perso - 1);
      end
      Else if (selection = 2) and (get_quantite_objet_2_perso >= 1) then
      begin
        modif_energie_perso(max(get_energie_perso + 30, get_max_energie));
        modif_quantite_objet_2_perso(get_quantite_objet_2_perso - 1);
      end
      Else if (selection = 3) and (get_quantite_objet_3_perso >= 1) then
      begin
        modif_vitesse_perso(get_vitesse_perso + 10, 0);
        modif_quantite_objet_3_perso(get_quantite_objet_3_perso - 1);
      end
      Else if selection = 4 then
      begin
      end
      Else
      begin
        texte_inventaire('Vous ne trouvez pas l''objet dans votre sac');
        attendre(1500);
      end;
    end
    Else if selection_1 = 2 then
    begin
      choix_6;
      readln(selection);
      while (selection <> 1) and (selection <> 2) and (selection <> 3) and
        (selection <> 4) and (selection <> 5) and (selection <> 6) do
      begin
        choix_6;
        readln(selection);
      end;
      if (selection = 1) and (get_quantite_arme_1_perso >= 1) then
      begin
        modif_id_arme_principale(0);
        modif_id_arme_cac(2);
      end
      Else if (selection = 2) and (get_quantite_arme_2_perso >= 1) then
      begin
        modif_id_arme_principale(0);
        modif_id_arme_cac(3);
      end
      Else if (selection = 3) and (get_quantite_arme_3_perso >= 1) then
      begin
        modif_id_arme_cac(0);
        modif_id_arme_principale(1);
      end
      Else if (selection = 4) and (get_quantite_arme_4_perso >= 1) then
      begin
        modif_id_arme_cac(0);
        modif_id_arme_principale(2);
      end
      Else if (selection = 5) and (get_quantite_arme_5_perso >= 1) then
      begin
        modif_id_arme_cac(0);
        modif_id_arme_principale(3);
      end
      Else if selection = 4 then
      begin
      end
      Else
      begin
        texte_inventaire('Vous ne trouvez pas l''objet dans votre sac');
        attendre(1500);
      end;
    end
    Else if selection_1=3 then
    begin
    end;
    affichage_info;
    affichage_stat;
  end;
end;

procedure gestion_coups;

var
  chance_reussite: smallint;
  degat_supp,esquive: smallint;

begin

  degat := 0;
  esquive := aleatoire(1, 100);
  if (esquive <= esquive_ad) and (energie_ad >= 10) then
  begin
    energie_ad := energie_ad - 10;
    energie := energie - 2;
    nom_texte_combat(nom_ad, ' esquive l''attaque');
  end
  Else if (selection_attaque = 2) and (energie >= 5) then

  begin

    while degat = 0 do

    begin

      reduction_degat := aleatoire(round(reduction_degat / 10), resistance);
      chance_reussite := aleatoire(1, 100);
      degat := degat_arme - round(reduction_degat / 10);
      degat_supp := aleatoire(force, force + 20);
      degat_supp := round(degat_supp / 5);
      degat := degat + degat_supp;

      if (chance_reussite <= precision) and (energie >= 5) then

      begin
        if (chance_reussite <= concentration) and (energie >= 10) then

        begin

          energie := energie - 10;
          degat_supp := aleatoire(force + 20, force + 40);
          degat_supp := round(degat_supp / 5);
          degat := degat + degat_supp;
          texte_combat('Dégat critique');
          attendre(1000);

        end;

        if (selection_attaque_precise = 't') or
          (selection_attaque_precise = 'T') then

        begin

          reduction_concentration := round(concentration_ad / 10);
          if reduction_concentration = 0 then
            reduction_concentration := 1;
          energie := energie - 5;
          texte_combat('En ciblant la tête');
          texte_nb_texte_combat('- ', reduction_concentration,
            ' de concentration');

        end

        Else if (selection_attaque_precise = 'p') or
          (selection_attaque_precise = 'P') then

        begin

          reduction_force := round(force_ad / 10);
          if reduction_force = 0 then
            reduction_force := 1;
          energie := energie - 5;
          texte_combat('En ciblant la poitrine');
          texte_nb_texte_combat('- ', reduction_force, ' de force');

        end

        Else if (selection_attaque_precise = 'b') or
          (selection_attaque_precise = 'B') then

        begin

          reduction_precision := round(precision_ad / 10);
          if reduction_precision = 0 then
            reduction_precision := 1;
          energie := energie - 5;
          texte_combat('En ciblant les bras');
          texte_nb_texte_combat('- ', reduction_precision, ' de précision');

        end

        Else if (selection_attaque_precise = 'j') or
          (selection_attaque_precise = 'J') then

        begin

          reduction_vitesse := round(vitesse_ad / 10);
          if reduction_vitesse = 0 then
            reduction_vitesse := 1;
          energie := energie - 5;
          texte_combat('En ciblant les jambes');
          texte_nb_texte_combat('- ', reduction_vitesse, ' de vitesse');

        end;

      end

      Else

        energie := energie - 2;

    end;

  end

  Else if (energie >= 2) then

  begin

    degat := degat_arme - (round(reduction_degat / 10));
    chance_reussite := aleatoire(1, 150);

    if (chance_reussite <= concentration) and (energie >= 10) then

    begin

      energie := energie - 10;
      degat_supp := aleatoire(force + 20, force + 40);
      degat_supp := round(degat_supp / 5);
      degat := degat + degat_supp;
      texte_combat('Dégat critique');

    end

    Else

    begin

      energie := energie - 2;
      degat_supp := aleatoire(force, force + 20);
      degat_supp := round(degat_supp / 5);
      degat := degat + degat_supp;

    end;

  end

  Else

  begin

    nom_texte_combat(nom, ' se repose');
    energie := energie + 3;
    degat := 0;

  end;

end;

procedure tour_perso;

begin

  nom_texte(get_nom_perso, ' attaque');
  texte_choix_2('1. Attaque normale', '2. Attaque ciblée');
  readln(selection_attaque);

  selection_attaque_precise := 'z';
  resistance := get_resistance_perso;
  energie := get_energie_perso;
  degat_arme := get_degat_arme_perso;
  concentration := get_concentration_perso;
  force := get_force_perso;
  precision := get_precision_perso;
  reduction_vitesse := 0;
  reduction_concentration := 0;
  reduction_force := 0;
  reduction_precision := 0;
  concentration_ad := get_concentration_e;
  vitesse_ad := get_vitesse_e;
  force_ad := get_force_e;
  precision_ad := get_precision_e;
  energie_ad := get_energie_e;
  esquive_ad := get_esquive_e;
  nom_ad := get_nom_e;
  nom := get_nom_perso;

  while (selection_attaque <> 1) and (selection_attaque <> 2) do

  begin

    nom_texte(get_nom_perso, ' attaque');
    texte_choix_2('1. Attaque normale', '2. Attaque ciblée');
    readln(selection_attaque);

  end;

  if selection_attaque = 2 then

  begin

    texte_choix_4('T. Cibler la tête', 'P. Cibler la poitrine',
      'B. Cibler les bras', 'J. Cibler les jambes');
    readln(selection_attaque_precise);

    while (selection_attaque_precise <> 't') and
      (selection_attaque_precise <> 'p') and
      (selection_attaque_precise <> 'b') and
      (selection_attaque_precise <> 'j') and
      (selection_attaque_precise <> 'T') and
      (selection_attaque_precise <> 'P') and
      (selection_attaque_precise <> 'B') and
      (selection_attaque_precise <> 'J') do

    begin

      texte_choix_4('T. Cibler la tête', 'P. Cibler la poitrine',
        'B. Cibler les bras', 'J. Cibler les jambes');
      readln(selection_attaque_precise);

    end;

  end;

  gestion_coups;
  modif_energie_perso(energie);
  modif_energie_e(energie_ad);
  modif_vitesse_e(get_vitesse_e - reduction_vitesse);
  modif_concentration_e(get_concentration_e - reduction_concentration);
  modif_force_e(get_force_e - reduction_force);
  modif_precision_e(get_precision_e - reduction_precision);
  modif_PV_e(get_PV_e - degat);
  min(get_PV_e);
  modif_energie_perso(get_energie_perso + 1);
  min(get_energie_perso);
  nom_texte_nb_texte(get_nom_e, ' à perdu ', degat, ' PV');

  // fin tour affichage resultat

  attendre(1500);
  ecran_combat;

end;

procedure tour_e;

begin

  nom_texte(get_nom_e, ' attaque');
  attendre(1000);
  selection_attaque_precise := 'z';
  resistance := get_resistance_e;
  energie := get_energie_e;
  degat_arme := get_degat_arme_e;
  concentration := get_concentration_e;
  force := get_force_e;
  precision := get_precision_e;
  reduction_vitesse := 0;
  reduction_concentration := 0;
  reduction_force := 0;
  reduction_precision := 0;
  concentration_ad := get_concentration_perso;
  vitesse_ad := get_vitesse_perso;
  force_ad := get_force_perso;
  precision_ad := get_precision_perso;
  energie_ad := get_energie_perso;
  esquive_ad := get_esquive_perso;
  nom_ad := get_nom_perso;
  nom := get_nom_e;
  selection_attaque := aleatoire(1, 2);

  if selection_attaque = 2 then

  begin

    selection_attaque_precise_n := aleatoire(1, 4);
    if selection_attaque_precise_n = 1 then
      selection_attaque_precise := 't';
    if selection_attaque_precise_n = 2 then
      selection_attaque_precise := 'p';
    if selection_attaque_precise_n = 3 then
      selection_attaque_precise := 'b';
    if selection_attaque_precise_n = 4 then
      selection_attaque_precise := 'j';

  end;

  gestion_coups;
  modif_energie_e(energie);
  modif_energie_perso(energie_ad);
  modif_vitesse_perso(get_vitesse_perso - reduction_vitesse, 0);
  modif_concentration_perso(get_concentration_perso - reduction_concentration);
  modif_force_perso(get_force_perso - reduction_force);
  modif_precision_perso(get_precision_perso - reduction_precision, 0);
  modif_PV_perso(get_PV_perso - degat, 0);
  min(get_PV_perso);
  modif_energie_e(get_energie_e + 1);
  min(get_energie_e);
  nom_texte_nb_texte(get_nom_perso, ' à perdu ', degat, ' PV');

  // fin tour

  attendre(1500);
  ecran_combat;

end;

procedure combat(nb_combat, forcer: smallint);

var
  selection: char;
  chance_combat: smallint;

begin
  if (forcer = 0) then
  begin
    chance_combat := aleatoire(1, 100);
  end
  Else
    chance_combat := 100;
  if (chance_combat <= get_discretion_perso) then

  begin

    nom_texte(get_nom_perso, ' ne recontre pas d''énnemis');

  end

  Else
  begin
    while nb_combat > 0 do
    begin
      chargement_combat;
      select_e;
      ecran_combat;

      while (get_PV_perso > 0) and (get_PV_e > 0) do

      begin
        selection:='z';
        texte_choix_2('A. Attaque', 'I. Inventaire');
        readln(selection);

        while (selection <> 'a') and (selection <> 'i') and (selection <> 'A')
          and (selection <> 'I') do

        begin

          texte_choix_2('A. Attaque', 'I. Inventaire');
          readln(selection);

        end;

        if (selection = 'a') or (selection = 'A') then

        begin

          if (get_vitesse_perso < get_vitesse_e) then

          begin
            // attaque ennemi

            tour_e;

            // attaque perso
            if (get_PV_perso > 0) then
            begin

              tour_perso;
              attendre(500);
            end;

          end

          Else

          begin
            // attaque perso

            tour_perso;

            // attaque ennemi
            if (get_PV_e > 0) then
            begin

              tour_e;
              attendre(500);
            end;

          end;

        end

        Else if (selection = 'i') or (selection = 'I') then

        begin

          inventaire;
          ecran_combat;

        end;

      end;
      if (get_PV_perso >= 0) then
      begin
        victoire := 1;
        modif_xp_perso(get_xp_perso + get_xp_gagner);
        level;
        drop;
        nb_combat := nb_combat - 1;
      end
      Else
      begin
        nb_combat := 0;
        victoire := 0;
      end;
    end;
  end;

end;

function get_victoire: smallint;
begin
  get_victoire := victoire;
end;

procedure modif_victoire (n:smallint);
begin
  victoire:=n;
end;
procedure vendeur;
var
  selection_1: smallint;
begin
  selection_1 := 0;
  while (selection_1 <> 3) do
  begin
    ecran_vendeur;
    readln(selection_1);
    while (selection_1 <> 1) and (selection_1 <> 2) and (selection_1 <> 3) do
    begin
      ecran_vendeur;
      readln(selection_1);
    end;

    // achat
    if (selection_1 = 1) then
    begin
      choix_4_v('Objet', 'Arme', 'Amélioration', 'Retour');
      readln(selection);
      while (selection <> 1) and (selection <> 2) and (selection <> 3) and
        (selection <> 4) do
      begin
        choix_4_v('Objet', 'Arme', 'Amélioration', 'Retour');
        readln(selection);
      end;

      // achat d'objet
      if selection = 1 then
      begin
        affichage_achat_objet;
        choix_4_v(get_nom_objet_1, get_nom_objet_2, get_nom_objet_3, 'Retour');
        readln(selection);
        while (selection <> 1) and (selection <> 2) and (selection <> 3) and
          (selection <> 4) do
        begin
          choix_4_v(get_nom_objet_1, get_nom_objet_2, get_nom_objet_3,
            'Retour');
          readln(selection);
        end;

        // objet 1
        if (selection = 1) then
        begin
          texte_v('Combien en voulez-vous ?');
          texte_objet_v(get_nom_objet_1, get_quantite_objet_1_v,
            get_prix_objet_1_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_objet_1_v) then
          begin
            texte_v('Désolé mais j''en ai pas autant !');
            attendre(1500);
          end
          Else
          begin
            validation_achat(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_perso >= get_prix_objet_1_v * nb_objet) then
            begin
              modif_quantite_objet_1_v(get_quantite_objet_1_v - nb_objet);
              modif_argent_perso
                (get_argent_perso - (get_prix_objet_1_v * nb_objet));
              modif_quantite_objet_1_perso
                (get_quantite_objet_1_perso + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''avoir acheter', nb_objet,
                get_nom_objet_1);
              attendre(1500);
            end
            Else
            begin
              texte_v('Désolé mais t''a pas l''argent pour mon gars !');
              attendre(1500);
            end;
          end;
        end

        // objet 2
        Else if (selection = 2) then
        begin
          texte_v('T''en veux combien ?');
          texte_objet_v(get_nom_objet_2, get_quantite_objet_2_v,
            get_prix_objet_2_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_objet_2_v) then
          begin
            texte_v('Désolé mais j''en ai pas autant !');
            attendre(1500);
          end
          Else
          begin
            validation_achat(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_perso >= get_prix_objet_2_v * nb_objet) then
            begin
              modif_quantite_objet_2_v(get_quantite_objet_2_v - nb_objet);
              modif_argent_perso
                (get_argent_perso - (get_prix_objet_2_v * nb_objet));
              modif_quantite_objet_2_perso
                (get_quantite_objet_2_perso + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''avoir acheter', nb_objet,
                get_nom_objet_2);
              attendre(1500);
            end
            Else
            begin
              texte_v('Désolé mais t''a pas l''argent pour mon gars !');
              attendre(1500);
            end;
          end;
        end

        // objet 3
        Else if (selection = 3) then
        begin
          texte_v('T''en veux combien ?');
          texte_objet_v(get_nom_objet_3, get_quantite_objet_3_v,
            get_prix_objet_3_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_objet_3_v) then
          begin
            texte_v('Désolé mais j''en ai pas autant !');
            attendre(1500);
          end
          Else
          begin
            validation_achat(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_perso >= get_prix_objet_3_v * nb_objet) then
            begin
              modif_quantite_objet_3_v(get_quantite_objet_3_v - nb_objet);
              modif_argent_perso
                (get_argent_perso - (get_prix_objet_3_v * nb_objet));
              modif_quantite_objet_3_perso
                (get_quantite_objet_3_perso + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''avoir acheter', nb_objet,
                get_nom_objet_3);
              attendre(1500);
            end
            Else
            begin
              texte_v('Désolé mais t''a pas l''argent pour mon gars !');
              attendre(1500);
            end;
          end;
        end;
      end

      // achat d'arme
      Else if selection = 2 then
      begin
        ecran_vendeur_arme;
        affichage_achat_arme;
        choix_6_v(get_nom_arme_1, get_nom_arme_2, get_nom_arme_3,
          get_nom_arme_4, get_nom_arme_5, 'Retour');
        readln(selection);
        while (selection <> 1) and (selection <> 2) and (selection <> 3) and
          (selection <> 4) and (selection <> 5) and (selection <> 6) do
        begin
          choix_6_v(get_nom_arme_1, get_nom_arme_2, get_nom_arme_3,
            get_nom_arme_4, get_nom_arme_5, 'Retour');
          readln(selection);
        end;

        // arme 1
        if selection = 1 then
        begin
          ecran_vendeur_arme;
          texte_v('T''en veux combien ?');
          texte_objet_v(get_nom_arme_1, get_quantite_arme_1_v,
            get_prix_arme_1_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_arme_1_v) then
          begin
            texte_v('Désolé mais j''en ai pas autant !');
            attendre(1500);
          end
          Else
          begin
            validation_achat(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_perso >= get_prix_arme_1_v * nb_objet) then
            begin
              modif_quantite_arme_1_v(get_quantite_arme_1_v - nb_objet);
              modif_argent_perso
                (get_argent_perso - (get_prix_arme_1_v * nb_objet));
              modif_quantite_arme_1_perso(get_quantite_arme_1_perso + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''avoir acheter', nb_objet,
                get_nom_arme_1);
              attendre(1500);
            end
            Else
            begin
              texte_v('Désolé mais t''a pas l''argent pour mon gars !');
              attendre(1500);
            end;
          end;
        end

        // arme 2
        Else if (selection = 2) then
        begin
          ecran_vendeur_arme;
          texte_v('T''en veux combien ?');
          texte_objet_v(get_nom_arme_2, get_quantite_arme_2_v,
            get_prix_arme_2_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_arme_2_v) then
          begin
            texte_v('Désolé mais j''en ai pas autant !');
            attendre(1500);
          end
          Else
          begin
            validation_achat(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_perso >= get_prix_arme_2_v * nb_objet) then
            begin
              modif_quantite_arme_2_v(get_quantite_arme_2_v - nb_objet);
              modif_argent_perso
                (get_argent_perso - (get_prix_arme_2_v * nb_objet));
              modif_quantite_arme_2_perso(get_quantite_arme_2_perso + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''avoir acheter', nb_objet,
                get_nom_arme_2);
              attendre(1500);
            end
            Else
            begin
              texte_v('Désolé mais t''a pas l''argent pour mon gars !');
              attendre(1500);
            end;
          end;
        end

        // arme 3
        Else if (selection = 3) then
        begin
          ecran_vendeur_arme;
          texte_v('T''en veux combien ?');
          texte_objet_v(get_nom_arme_3, get_quantite_arme_3_v,
            get_prix_arme_3_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_arme_3_v) then
          begin
            texte_v('Désolé mais j''en ai pas autant !');
            attendre(1500);
          end
          Else
          begin
            validation_achat(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_perso >= get_prix_arme_3_v * nb_objet) then
            begin
              modif_quantite_arme_3_v(get_quantite_arme_3_v - nb_objet);
              modif_argent_perso
                (get_argent_perso - (get_prix_arme_3_v * nb_objet));
              modif_quantite_arme_3_perso(get_quantite_arme_3_perso + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''avoir acheter', nb_objet,
                get_nom_arme_3);
              attendre(1500);
            end
            Else
            begin
              texte_v('Désolé mais t''a pas l''argent pour mon gars !');
              attendre(1500);
            end;
          end;
        end

        // arme 4
        Else if (selection = 4) then
        begin
          ecran_vendeur_arme;
          texte_v('T''en veux combien ?');
          texte_objet_v(get_nom_arme_4, get_quantite_arme_4_v,
            get_prix_arme_4_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_arme_4_v) then
          begin
            texte_v('Désolé mais j''en ai pas autant !');
            attendre(1500);
          end
          Else
          begin
            validation_achat(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_perso >= get_prix_arme_4_v * nb_objet) then
            begin
              modif_quantite_arme_4_v(get_quantite_arme_4_v - nb_objet);
              modif_argent_perso
                (get_argent_perso - (get_prix_arme_4_v * nb_objet));
              modif_quantite_arme_4_perso(get_quantite_arme_4_perso + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''avoir acheter', nb_objet,
                get_nom_arme_4);
              attendre(1500);
            end
            Else
            begin
              texte_v('Désolé mais t''a pas l''argent pour mon gars !');
              attendre(1500);
            end;
          end;
        end

        // arme 5
        Else if (selection = 5) then
        begin
          ecran_vendeur_arme;
          texte_v('T''en veux combien ?');
          texte_objet_v(get_nom_arme_5, get_quantite_arme_5_v,
            get_prix_arme_5_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_arme_5_v) then
          begin
            texte_v('Désolé mais j''en ai pas autant !');
            attendre(1500);
          end
          Else
          begin
            validation_achat(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_perso >= get_prix_arme_5_v * nb_objet) then
            begin
              modif_quantite_arme_5_v(get_quantite_arme_5_v - nb_objet);
              modif_argent_perso
                (get_argent_perso - (get_prix_arme_5_v * nb_objet));
              modif_quantite_arme_5_perso(get_quantite_arme_5_perso + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''avoir acheter', nb_objet,
                get_nom_arme_5);
              attendre(1500);
            end
            Else
            begin
              texte_v('Désolé mais t''a pas l''argent pour mon gars !!');
              attendre(1500);
            end;
          end;
        end
        Else if (selection = 6) then
        begin
          // retour fin achat arme
        end;
      end

      // amelioration
      Else if selection = 3 then
      begin
        ecran_vendeur_arme;
        affichage_achat_amelioration;
        texte_v('Choisir l''arme à améliorer');
        choix_4_v(get_nom_arme_3, get_nom_arme_4, get_nom_arme_5, 'Retour');
        readln(selection);
        while (selection <> 1) and (selection <> 2) and (selection <> 3) and
          (selection <> 4) do
        begin
          choix_4_v(get_nom_arme_3, get_nom_arme_4, get_nom_arme_5, 'Retour');
          readln(selection);
        end;

        // amelioration fusil a pompe
        if selection = 1 then
        begin
          if (get_quantite_arme_3_perso > 0) then
          begin
            validation_amelioration(get_nom_arme_3);
            readln(validation);
            if (validation = 1) and (get_argent_perso >=
                get_prix_amelioration_1_v) then
            begin
              modif_argent_perso(get_argent_perso - (get_prix_amelioration_1_v)
                );
              modif_amelioration_pompe(1);
              modif_degat_arme_perso;
              texte_v('Merci');
              attendre(1500);
            end;
          end
          Else
            texte_v('Sans arme j''peux rien faire');
          attendre(2000);
        end

        // amelioration revolver
        Else if selection = 2 then
        begin
          if (get_quantite_arme_4_perso > 0) then
          begin
            validation_amelioration(get_nom_arme_4);
            readln(validation);
            if (validation = 1) and (get_argent_perso >=
                get_prix_amelioration_2_v) then
            begin
              modif_argent_perso(get_argent_perso - (get_prix_amelioration_2_v)
                );
              modif_amelioration_rev(1);
              modif_vitesse_perso(0, 1);
              texte_v('Merci');
              attendre(1500);
            end;
          end
          Else
            texte_v('Sans arme j''peux rien faire');
          attendre(2000);
        end

        // amelioration fusil d'assault
        Else if selection = 3 then
        begin
          if (get_quantite_arme_5_perso > 0) then
          begin
            validation_amelioration(get_nom_arme_5);
            readln(validation);
            if (validation = 1) and (get_argent_perso >=
                get_prix_amelioration_3_v) then
            begin
              modif_argent_perso(get_argent_perso - (get_prix_amelioration_3_v)
                );
              modif_amelioration_fusil(1);
              modif_precision_perso(0, 1);
              texte_v('Merci');
              attendre(1500);
            end;
          end
          Else
            texte_v('Sans arme j''peux rien faire');
          attendre(2000);
        end
        Else if selection = 4 then
        begin
          // retour fin amelioration arme
        end;
      end
      Else if selection = 4 then
      begin
        // retour fin achat
      end;
    end

    // vente
    Else if (selection_1 = 2) then
    begin
      choix_3_v('Objet', 'Arme', 'Retour');
      readln(selection);
      while (selection <> 1) and (selection <> 2) and (selection <> 3) do
      begin
        choix_3_v('Objet', 'Arme', 'Retour');
        readln(selection);
      end;

      // vente d'objet
      if (selection = 1) then
      begin
        texte_v('Qu''avez vous à vendre ?');
        affichage_vente;
        choix_4_v(get_nom_objet_1, get_nom_objet_2, get_nom_objet_3, 'Retour');
        readln(selection);
        while (selection <> 1) and (selection <> 2) and (selection <> 3) and
          (selection <> 4) do
        begin
          choix_4_v(get_nom_objet_1, get_nom_objet_2, get_nom_objet_3,
            'Retour');
          readln(selection);
        end;

        // objet 1
        if (selection = 1) then
        begin
          texte_v('T''en as combien à vendre ?');
          texte_objet_v(get_nom_objet_1, get_quantite_objet_1_perso,
            get_prix_objet_1_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_objet_1_perso) then
          begin
            texte_v('Désolé mais t''en as pas assez !');
            attendre(1500);
          end
          Else
          begin
            validation_vente(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_v >= get_prix_objet_1_v * nb_objet) then
            begin
              modif_quantite_objet_1_perso
                (get_quantite_objet_1_perso - nb_objet);
              modif_argent_v(get_argent_v - (get_prix_objet_1_v * nb_objet));
              modif_argent_perso
                (get_argent_perso + (get_prix_objet_1_v * nb_objet));
              modif_quantite_objet_1_v(get_quantite_objet_1_v + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''m''avoir vendu', nb_objet,
                get_nom_objet_1);
              attendre(1500);
            end
            Else
            begin
              texte_v('J''ai pas assez pour !');
              attendre(1500);
            end;
          end;
        end

        // objet 2
        Else if (selection = 2) then
        begin
          texte_v('T''en as combien à vendre ?');
          texte_objet_v(get_nom_objet_2, get_quantite_objet_2_perso,
            get_prix_objet_2_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_objet_2_perso) then
          begin
            texte_v('Désolé mais vous n''en avez pas assez !');
            attendre(1500);
          end
          Else
          begin
            validation_vente(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_v >= get_prix_objet_2_v * nb_objet) then
            begin
              modif_quantite_objet_2_perso
                (get_quantite_objet_2_perso - nb_objet);
              modif_argent_v(get_argent_v - (get_prix_objet_2_v * nb_objet));
              modif_argent_perso
                (get_argent_perso + (get_prix_objet_2_v * nb_objet));
              modif_quantite_objet_2_v(get_quantite_objet_2_v + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''m''avoir vendu', nb_objet,
                get_nom_objet_2);
              attendre(1500);
            end
            Else
            begin
              texte_v('J''ai pas assez pour !');
              attendre(1500);
            end;
          end;
        end

        // objet 3
        Else if (selection = 3) then
        begin
          texte_v('T''en as combien à vendre ?');
          texte_objet_v(get_nom_objet_3, get_quantite_objet_3_perso,
            get_prix_objet_3_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_objet_3_perso) then
          begin
            texte_v('Désolé mais vous t''en as pas assez !');
            attendre(1500);
          end
          Else
          begin
            validation_vente(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_v >= get_prix_objet_3_v * nb_objet) then
            begin
              modif_quantite_objet_3_perso
                (get_quantite_objet_3_perso - nb_objet);
              modif_argent_v(get_argent_v - (get_prix_objet_3_v * nb_objet));
              modif_argent_perso
                (get_argent_perso + (get_prix_objet_3_v * nb_objet));
              modif_quantite_objet_3_v(get_quantite_objet_3_v + nb_objet);
              texte_nom_nb_objet_v('Merci', 'de m''avoir vendu', nb_objet,
                get_nom_objet_3);
              attendre(1500);
            end
            Else
            begin
              texte_v('J''ai pas assez pour !');
              attendre(1500);
            end;
          end;
        end
        Else if selection = 4 then
        begin
          // retour
        end;
      end

      // vente d'arme
      Else if selection = 2 then
      begin
        texte_v('Qu''avez vous à vendre ?');
        ecran_vendeur_arme;
        choix_6_v(get_nom_arme_1, get_nom_arme_2, get_nom_arme_3,
          get_nom_arme_4, get_nom_arme_5, 'Retour');
        readln(selection);
        while (selection <> 1) and (selection <> 2) and (selection <> 3) and
          (selection <> 4) and (selection <> 5) and (selection <> 6) do
        begin
          choix_6_v(get_nom_arme_1, get_nom_arme_2, get_nom_arme_3,
            get_nom_arme_4, get_nom_arme_5, 'Retour');
          readln(selection);
        end;

        // arme 1
        if (selection = 1) then
        begin
          ecran_vendeur_arme;
          texte_v('T''en as combien à vendre ?');
          texte_objet_v(get_nom_arme_1, get_quantite_arme_1_perso,
            get_prix_arme_1_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_arme_1_perso) then
          begin
            texte_v('Désolé mais t''en as pas assez !');
            attendre(1500);
          end
          Else
          begin
            validation_vente(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_v >= get_prix_arme_1_v * nb_objet) then
            begin
              modif_quantite_arme_1_perso(get_quantite_arme_1_perso - nb_objet);
              modif_argent_v(get_argent_v - (get_prix_arme_1_v * nb_objet));
              modif_argent_perso
                (get_argent_perso + (get_prix_arme_1_v * nb_objet));
              modif_quantite_arme_1_v(get_quantite_arme_1_v + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''m''avoir vendu', nb_objet,
                get_nom_arme_1);
              attendre(1500);
            end
            Else
            begin
              texte_v('J''ai pas assez pour !');
              attendre(1500);
            end;
          end;
        end

        // arme 2
        Else if (selection = 2) then
        begin
          ecran_vendeur_arme;
          texte_v('T''en as combien à vendre ?');
          texte_objet_v(get_nom_arme_2, get_quantite_arme_2_perso,
            get_prix_arme_2_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_arme_2_perso) then
          begin
            texte_v('Désolé mais vous n''en avez pas assez !');
            attendre(1500);
          end
          Else
          begin
            validation_vente(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_v >= get_prix_arme_2_v * nb_objet) then
            begin
              modif_quantite_arme_2_perso(get_quantite_arme_2_perso - nb_objet);
              modif_argent_v(get_argent_v - (get_prix_arme_2_v * nb_objet));
              modif_argent_perso
                (get_argent_perso + (get_prix_arme_2_v * nb_objet));
              modif_quantite_arme_2_v(get_quantite_arme_2_v + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''m''avoir vendu', nb_objet,
                get_nom_arme_2);
              attendre(1500);
            end
            Else
            begin
              texte_v('J''ai pas assez pour !');
              attendre(1500);
            end;
          end;
        end

        // arme 3
        Else if (selection = 3) then
        begin
          texte_v('T''en as combien à vendre ?');
          texte_objet_v(get_nom_arme_3, get_quantite_arme_3_perso,
            get_prix_arme_3_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_arme_3_perso) then
          begin
            texte_v('Désolé mais vous t''en as pas assez !');
            attendre(1500);
          end
          Else
          begin
            validation_vente(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_v >= get_prix_arme_3_v * nb_objet) then
            begin
              modif_quantite_arme_3_perso(get_quantite_arme_3_perso - nb_objet);
              modif_argent_v(get_argent_v - (get_prix_arme_3_v * nb_objet));
              modif_argent_perso
                (get_argent_perso + (get_prix_arme_3_v * nb_objet));
              modif_quantite_arme_3_v(get_quantite_arme_3_v + nb_objet);
              texte_nom_nb_objet_v('Merci', 'de m''avoir vendu', nb_objet,
                get_nom_arme_3);
              attendre(1500);
            end
            Else
            begin
              texte_v('J''ai pas assez pour !');
              attendre(1500);
            end;
          end;
        end

        // arme 4
        Else if (selection = 4) then
        begin
          ecran_vendeur_arme;
          texte_v('T''en as combien à vendre ?');
          texte_objet_v(get_nom_arme_4, get_quantite_arme_4_perso,
            get_prix_arme_4_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_arme_4_perso) then
          begin
            texte_v('Désolé mais vous n''en avez pas assez !');
            attendre(1500);
          end
          Else
          begin
            validation_vente(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_v >= get_prix_arme_4_v * nb_objet) then
            begin
              modif_quantite_arme_4_perso(get_quantite_arme_4_perso - nb_objet);
              modif_argent_v(get_argent_v - (get_prix_arme_4_v * nb_objet));
              modif_argent_perso
                (get_argent_perso + (get_prix_arme_4_v * nb_objet));
              modif_quantite_arme_4_v(get_quantite_arme_4_v + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''m''avoir vendu', nb_objet,
                get_nom_arme_4);
              attendre(1500);
            end
            Else
            begin
              texte_v('J''ai pas assez pour !');
              attendre(1500);
            end;
          end;
        end

        // arme 5
        Else if (selection = 5) then
        begin
          ecran_vendeur_arme;
          texte_v('T''en as combien à vendre ?');
          texte_objet_v(get_nom_arme_5, get_quantite_arme_5_perso,
            get_prix_arme_5_v);
          nb_achat;
          readln(nb_objet);
          if (nb_objet > get_quantite_arme_5_perso) then
          begin
            texte_v('Désolé mais vous n''en avez pas assez !');
            attendre(1500);
          end
          Else
          begin
            validation_vente(nb_objet);
            readln(validation);
            if (validation = 1) and
              (get_argent_v >= get_prix_arme_5_v * nb_objet) then
            begin
              modif_quantite_arme_5_perso(get_quantite_arme_5_perso - nb_objet);
              modif_argent_v(get_argent_v - (get_prix_arme_5_v * nb_objet));
              modif_argent_perso
                (get_argent_perso + (get_prix_arme_5_v * nb_objet));
              modif_quantite_arme_5_v(get_quantite_arme_5_v + nb_objet);
              texte_nom_nb_objet_v('Merci', 'd''m''avoir vendu', nb_objet,
                get_nom_arme_5);
              attendre(1500);
            end
            Else
            begin
              texte_v('J''ai pas assez pour !');
              attendre(1500);
            end;
          end;
        end
        Else if selection = 6 then
        begin
          // retour
        end;
      end
      Else if selection = 3 then
      begin
        // retour fin achat
      end;

    end
    // partir
    Else if (selection_1 = 3) then
    begin
      texte_v('Salut et à la prochaine !');
      attendre(1500);
    end;
  end;
end;

procedure level;
begin
  if (get_xp_perso >= get_xp_levelup) then
  begin
    nom_texte_combat(get_nom_perso, ' a monté un level !!!');
    attendre(2000);
    modif_level_perso(get_level_perso + 1);
    modif_xp_levelup(get_xp_levelup + round(get_xp_levelup / 20));
    modif_xp_perso(0);
    chargement;
    ajout_stat(16);
  end;
end;

procedure ajout_stat(n: smallint);
var
  points: smallint;
begin
  points := n;
  while points > 0 do
  begin
    affichage_ajout_stat(points);
    readln(selection);
    if selection = 1 then
    begin
      modif_PV_perso(get_PV_perso + 10, 0);
      modif_max_pv(get_PV_perso);
    end
    Else if selection = 2 then
    begin
      modif_energie_perso(get_energie_perso + 10);
      modif_max_energie(get_energie_perso);
    end
    Else if selection = 3 then
    begin
      modif_concentration_perso(get_concentration_perso + 1);
    end
    Else if selection = 4 then
    begin
      modif_discretion_perso(get_discretion_perso + 1, 0);
    end
    Else if selection = 5 then
    begin
      modif_esquive_perso(get_esquive_perso + 1);
    end
    Else if selection = 6 then
    begin
      modif_force_perso(get_force_perso + 1);
    end
    Else if selection = 7 then
    begin
      modif_precision_perso(get_precision_perso + 1, 0);
    end
    Else if selection = 8 then
    begin
      modif_resistance_perso(get_resistance_perso + 1, 0);
    end;
    points := (points - 1);
  end;
  rewrite(save);
  sauvegarde;
end;

procedure drop;
var
  nb_balles: smallint;
  nb_objets: smallint;
  objets: smallint;
begin
  nb_balles := aleatoire(1, 50);
  texte_nb_texte_combat('Vous ramassez ', nb_balles, ' Balles');
  modif_argent_perso(get_argent_perso + nb_balles);
  attendre(2000);
  objets := aleatoire(1, 100);
  nb_objets := aleatoire(4, 8);
  if objets < 50 then
  begin
    modif_quantite_objet_1_perso(get_quantite_objet_1_perso + nb_objets);
    texte_nb_texte_combat('Vous ramassez ', nb_objets, ' Médipacks');
  end
  Else if (objets > 50) and (objets < 75) then
  begin
    modif_quantite_objet_2_perso(get_quantite_objet_2_perso + nb_objets);
    texte_nb_texte_combat('Vous ramassez ', nb_objets, ' Viandes');
  end
  Else
  begin
    modif_quantite_objet_3_perso(get_quantite_objet_3_perso + nb_objets);
    texte_nb_texte_combat('Vous ramassez ', nb_objets, ' Thés');
  end;
  rewrite(save);
  save_objet;
  attendre(2000);
end;

end.
