unit ennemi;

interface

uses SysUtils, Windows, personnage, montype;

var
  nom_e: machaine;
  PV_e: smallint;
  esquive_e, energie_e, degat_arme_e, vitesse_e, force_e, concentration_e,
    precision_e, resistance_e: smallint;
  xp_gagner: smallint;

function aleatoire(nb_1, nb_2: smallint): smallint;

procedure select_e;

function get_nom_e: machaine;

function get_PV_e: smallint;

procedure modif_PV_e(n: smallint);

function get_energie_e: smallint;

procedure modif_energie_e(n: smallint);

function get_esquive_e: smallint;

function get_vitesse_e: smallint;

procedure modif_vitesse_e(n: smallint);

function get_force_e: smallint;

procedure modif_force_e(n: smallint);

function get_concentration_e: smallint;

procedure modif_concentration_e(n: smallint);

function get_precision_e: smallint;

procedure modif_precision_e(n: smallint);

function get_resistance_e: smallint;

function get_degat_arme_e: smallint;

function get_xp_gagner: smallint;

implementation

function aleatoire(nb_1, nb_2: smallint): smallint; // permet de choisir un nombre aleatoire entre 2 bornes definit

begin

  randomize;
  aleatoire := random((nb_2 - nb_1) + 1) + (nb_1);

end;

procedure select_e;
var
  id_e: shortint;

begin
  // selection de l'ennemi
  if (get_checkpoint = 1) then
    id_e := 1
  Else if (get_checkpoint = 2) then
    id_e := 2
  Else if (get_checkpoint = 3) then
    id_e := 3
  Else if (get_checkpoint = 4) and (get_sous_checkpoint = 2) then
    id_e := 3
  Else if (get_checkpoint = 5) and (get_sous_checkpoint = 2) then
    id_e := 10
  Else if (get_checkpoint = 6) and (get_sous_checkpoint = 3) then
    id_e := 4
  Else if (get_checkpoint = 7) then
    id_e := 12
  Else if (get_checkpoint = 8) and (get_sous_checkpoint = 2) then
    id_e := aleatoire(1, 4)
  Else if (get_checkpoint = 8) and (get_sous_checkpoint = 3) then
    id_e := 3
  Else if (get_checkpoint = 8) and (get_sous_checkpoint = 4) then
    id_e := 5
  Else if (get_checkpoint = 11) and (get_sous_checkpoint = 2) then
    id_e := 4
  Else if (get_checkpoint = 11) and (get_sous_checkpoint = 3) then
    id_e := 6
  Else if (get_checkpoint = 11) and (get_sous_checkpoint = 4) then
    id_e := 3
  Else if (get_checkpoint = 12) and (get_sous_checkpoint = 2) then
    id_e := 3
  Else if (get_checkpoint = 13) and (get_sous_checkpoint = 3) then
    id_e := 3
  Else if (get_checkpoint = 14) and (get_sous_checkpoint = 4) then
    id_e := 4
  Else if (get_checkpoint = 14) and (get_sous_checkpoint = 5) then
    id_e := 4
  Else if (get_checkpoint = 14) and (get_sous_checkpoint = 7) then
    id_e := 3
  Else if (get_checkpoint = 15) and (get_sous_checkpoint = 2) then
    id_e := 13
  Else if (get_checkpoint = 16) and (get_sous_checkpoint = 2) then
    id_e := 13
  Else if (get_checkpoint = 16) and (get_sous_checkpoint = 3) then
    id_e := 13
  Else if (get_checkpoint = 16) and (get_sous_checkpoint = 5) then
    id_e := 13
  Else if (get_checkpoint = 16) and (get_sous_checkpoint = 7) then
    id_e := 13
  Else if (get_checkpoint = 16) and (get_sous_checkpoint = 8) then
    id_e := 14
  Else if (get_checkpoint = 16) and (get_sous_checkpoint = 9) then
    id_e := 14
  Else if (get_checkpoint = 16) and (get_sous_checkpoint = 11) then
    id_e := 14
  Else if (get_checkpoint = 16) and (get_sous_checkpoint = 14) then
    id_e := 14
  Else if (get_checkpoint = 17) and (get_sous_checkpoint = 3) then
    id_e := 14
  Else if (get_checkpoint = 17) and (get_sous_checkpoint = 4) then
    id_e := 14
  Else if (get_checkpoint = 18) and (get_sous_checkpoint = 1) then
    id_e := 3
  Else if (get_checkpoint = 19) and (get_sous_checkpoint = 2) then
    id_e := 3
  Else if (get_checkpoint = 19) and (get_sous_checkpoint = 5) then
    id_e := 10
  Else if (get_checkpoint = 19) and (get_sous_checkpoint = 6) then
    id_e := 4
  Else if (get_checkpoint = 19) and (get_sous_checkpoint = 7) then
    id_e := 4
  Else if (get_checkpoint = 19) and (get_sous_checkpoint = 8) then
    id_e := 4
  Else if (get_checkpoint = 20) and (get_sous_checkpoint = 2) then
    id_e := 14
  Else if (get_checkpoint = 20) and (get_sous_checkpoint = 3) then
    id_e := 14
  Else if (get_checkpoint = 21) and (get_sous_checkpoint = 1) then
    id_e := 14
  Else if (get_checkpoint = 21) and (get_sous_checkpoint = 3) then
    id_e := 14
  Else if (get_checkpoint = 21) and (get_sous_checkpoint = 4) then
    id_e := 14
  Else

    id_e := 0;

  // betes

  if id_e = 1 then
  begin
    nom_e := 'Rats';
    PV_e := 50;
    degat_arme_e := 10;
    vitesse_e := 85;
    precision_e := 20;
    concentration_e := 5;
    force_e := 15;
    esquive_e := 15;
    energie_e := 10;
    resistance_e := 5;
    xp_gagner := 5;
  end
  Else if id_e = 2 then
  begin
    nom_e := 'Nosalis';
    PV_e := 100;
    degat_arme_e := 20;
    vitesse_e := 45;
    precision_e := 40;
    concentration_e := 30;
    force_e := 20;
    esquive_e := 25;
    energie_e := 30;
    resistance_e := 25;
    xp_gagner := 12;
  end
  Else if id_e = 3 then
  begin
    nom_e := 'Nosalis';
    PV_e := 400;
    degat_arme_e := 30;
    vitesse_e := 55;
    precision_e := 50;
    concentration_e := 40;
    force_e := 30;
    esquive_e := 35;
    energie_e := 30;
    resistance_e := 25;
    xp_gagner := 12;
  end
  Else if id_e = 4 then
  begin
    nom_e := 'Rodeurs';
    PV_e := 300;
    degat_arme_e := 20;
    vitesse_e := 65;
    precision_e := 30;
    concentration_e := 10;
    force_e := 20;
    esquive_e := 40;
    energie_e := 15;
    resistance_e := 15;
    xp_gagner := 20;
  end
  Else if id_e = 5 then
  begin
    nom_e := 'Chef de meute';
    PV_e := 575;
    degat_arme_e := 45;
    vitesse_e := 60;
    precision_e := 60;
    concentration_e := 60;
    force_e := 40;
    esquive_e := 35;
    energie_e := 40;
    resistance_e := 35;
    xp_gagner := 34;
  end
  Else if id_e = 6 then
  begin
    nom_e := 'Demons';
    PV_e := 666;
    degat_arme_e := 55;
    vitesse_e := 75;
    precision_e := 75;
    concentration_e := 75;
    force_e := 45;
    esquive_e := 45;
    energie_e := 60;
    resistance_e := 45;
    xp_gagner := 46;
  end
  Else if id_e = 7 then
  begin
    nom_e := 'Lianes';
    PV_e := 50;
    degat_arme_e := 15;
    vitesse_e := 5;
    precision_e := 50;
    concentration_e := 1;
    force_e := 20;
    esquive_e := 5;
    energie_e := 10;
    resistance_e := 5;
    xp_gagner := 15;
  end
  Else if id_e = 8 then
  begin
    nom_e := 'Amibes Geantes';
    PV_e := 350;
    degat_arme_e := 40;
    vitesse_e := 70;
    precision_e := 80;
    concentration_e := 20;
    force_e := 20;
    esquive_e := 10;
    energie_e := 30;
    resistance_e := 20;
    xp_gagner := 30;
  end
  Else if id_e = 9 then
  begin
    nom_e := 'Biomass';
    PV_e := 1963;
    degat_arme_e := 75;
    vitesse_e := 80;
    precision_e := 95;
    concentration_e := 60;
    force_e := 70;
    esquive_e := 50;
    energie_e := 80;
    resistance_e := 60;
    xp_gagner := 2500;
  end

  // humains

  Else if id_e = 10 then
  begin
    nom_e := 'Milice Local';
    PV_e := 400;
    degat_arme_e := 30;
    vitesse_e := 30;
    precision_e := 20;
    concentration_e := 30;
    force_e := 30;
    esquive_e := 20;
    energie_e := 30;
    resistance_e := 30;
    xp_gagner := 50;
  end
  Else if id_e = 11 then
  begin
    nom_e := 'Milice de Polis';
    PV_e := 950;
    degat_arme_e := 60;
    vitesse_e := 50;
    precision_e := 75;
    concentration_e := 75;
    force_e := 60;
    esquive_e := 60;
    energie_e := 60;
    resistance_e := 40;
    xp_gagner := 68;
  end
  Else if id_e = 12 then
  begin
    nom_e := 'Bandits';
    PV_e := 450;
    degat_arme_e := 35;
    vitesse_e := 30;
    precision_e := 30;
    concentration_e := 30;
    force_e := 30;
    esquive_e := 20;
    energie_e := 30;
    resistance_e := 30;
    xp_gagner := 45;
  end
  Else if id_e = 13 then
  begin
    nom_e := 'Rouges';
    PV_e := 800;
    degat_arme_e := 55;
    vitesse_e := 45;
    precision_e := 70;
    concentration_e := 65;
    force_e := 50;
    esquive_e := 50;
    energie_e := 55;
    resistance_e := 35;
    xp_gagner := 67;
  end
  Else if id_e = 14 then
  begin
    nom_e := 'Fachos';
    PV_e := 800;
    degat_arme_e := 55;
    vitesse_e := 45;
    precision_e := 70;
    concentration_e := 65;
    force_e := 50;
    esquive_e := 50;
    energie_e := 55;
    resistance_e := 35;
    xp_gagner := 67;
  end
end;

function get_nom_e: machaine;
begin
  get_nom_e := nom_e;
end;

function get_PV_e: smallint;
begin
  get_PV_e := PV_e;
end;

procedure modif_PV_e(n: smallint);
begin
  PV_e := n;
end;

function get_energie_e: smallint;
begin
  get_energie_e := energie_e;
end;

procedure modif_energie_e(n: smallint);
begin
  energie_e := n;
end;

function get_esquive_e: smallint;
begin
  get_esquive_e := esquive_e;
end;

function get_vitesse_e: smallint;
begin
  get_vitesse_e := vitesse_e;
end;

procedure modif_vitesse_e(n: smallint);
begin
  vitesse_e := n;
end;

function get_force_e: smallint;
begin
  get_force_e := force_e;
end;

procedure modif_force_e(n: smallint);
begin
  force_e := n;
end;

function get_concentration_e: smallint;
begin
  get_concentration_e := concentration_e;
end;

procedure modif_concentration_e(n: smallint);
begin
  concentration_e := n;
end;

function get_precision_e: smallint;
begin
  get_precision_e := precision_e;
end;

procedure modif_precision_e(n: smallint);
begin
  precision_e := n;
end;

function get_resistance_e: smallint;
begin
  get_resistance_e := resistance_e;
end;

function get_degat_arme_e: smallint;
begin
  get_degat_arme_e := degat_arme_e;
end;

function get_xp_gagner: smallint;
begin
  get_xp_gagner := xp_gagner;
end;

end.
