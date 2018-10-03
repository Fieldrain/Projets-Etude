unit GestionEcran;

interface

uses SysUtils, Windows, personnage, ennemi, gestion_inventaire,
  save_chargement, montype;

// représente une coordonnée à l'écran (0,0 = coin haut-gauche)
type
  coordonnees = record
    x: integer;
    y: integer;
  end;

  // permet d'indiquer si l'on souhaite une bordure simple ou double
  // pour les cadres
type
  typeBordure = (simple, double);

  // supprime tous les caractères de l'écran mais ne change pas les couleurs
  // de fond
procedure effacerEcran;

// déplace le curseur à la position donnée
procedure deplacerCurseur(position: coordonnees);

// déplace le curseur aux coordonnées X, Y
procedure deplacerCurseurXY(x, y: integer);

// retourne la position actuelle du curseur
function positionCurseur(): coordonnees;

// change la ligne du curseur sans changer la colonne
procedure changerLigneCurseur(position: integer);

// change la colonne du curseur sans changer la ligne
procedure changerColonneCurseur(position: integer);

// affiche le texte à la position donnée
procedure ecrireEnPosition(position: coordonnees; texte: machaine);

procedure ecrireNbEnPosition(position: coordonnees; nb: smallint);

// dessine un cadre à partir des coordonnées des points haut-gauche
// et bas-droite, du type de bordure, de la couleur de trait et de
// la couleur de fond
procedure dessinerCadreXY(x, y, x2, y2: integer; t: typeBordure;
  coulTrait, coulFond: byte);

// attends le nombre de ms indiqué
procedure attendre(millisecondes: integer);

// change la couleur de fond actuelle
procedure couleurFond(couleur: byte);

// change la couleur de texte actuelle
procedure couleurTexte(couleur: byte);

// change la couleur de texte et de fond
procedure couleurs(ct, cf: byte);

function accent(s: machaine): machaine;

procedure accueil;

procedure bestiaire;

procedure credit;

procedure menu;

procedure affichage_ajout_stat(n: smallint);

// combat
procedure affichage_stat;

procedure affichage_info;

procedure affichage_stat_e;

procedure affichage_info_e;

procedure ecran_combat;

procedure nom_texte(nom: machaine; texte: machaine);

procedure nom_texte_combat(nom: machaine; texte: machaine);

procedure texte_choix_2(choix1, choix2: machaine);

procedure texte_choix_4(choix1, choix2, choix3, choix4: machaine);

procedure texte_combat(texte: machaine);

procedure texte_nb_texte_combat(texte: machaine; nb: smallint;
  texte2: machaine);

procedure nom_texte_nb_texte(nom: machaine; texte: machaine; nb: smallint;
  texte2: machaine);

// inventaire

procedure ecran_inventaire;

procedure choix_4;

procedure choix_2;

procedure choix_6;

procedure texte_inventaire(texte: machaine);

// histoire

procedure affichage_stat_perso;

procedure affichage_info_perso;

procedure ecran_histoire;

procedure texte_choix_2_histoire(choix1, choix2: machaine);

procedure texte_choix_3_histoire(choix1, choix2, choix3: machaine);

procedure texte_choix_4_histoire(choix1, choix2, choix3, choix4: machaine);

procedure texte(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7, ligne8,
  ligne9, ligne10, ligne11, ligne12, ligne13: machaine);

procedure texte_nom(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7,
  ligne8, ligne9, ligne10, ligne11, ligne12, ligne13, ligne14, nom: machaine);

procedure texte_nom_nom(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7,
  ligne8, ligne9, ligne10, ligne11, ligne12, ligne13, ligne14, ligne15,
  ligne16, nom: machaine);

procedure texte_nom_nom_2(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6,
  ligne7, ligne8, ligne9, ligne10, ligne11, ligne12, ligne13, ligne14,
  nom: machaine);

// vendeur

procedure ecran_vendeur;

procedure ecran_vendeur_arme;

procedure achat_vente;

procedure affichage_achat_objet;

procedure affichage_achat_arme;

procedure affichage_achat_amelioration;

procedure affichage_vente;

procedure affichage_inventaire;

procedure affichage_equipement;

procedure affichage_vendeur;

procedure texte_nom_v(texte: machaine);

procedure texte_nom_nb_objet_v(texte: machaine; texte2: machaine; nb: smallint;
  objet: machaine);

procedure texte_v(texte: machaine);

procedure texte_objet_v(objet: machaine; nb: smallint; prix: smallint);

procedure validation_achat(nb: smallint);

procedure validation_vente(nb: smallint);

procedure validation_amelioration(texte: machaine);

procedure nb_achat;

procedure choix_3_v(texte1, texte2, texte3: machaine);

procedure choix_4_v(texte1, texte2, texte3, texte4: machaine);

procedure choix_6_v(texte1, texte2, texte3, texte4, texte5, texte6: machaine);

const
  // Codes des couleurs
  Black = 0;
  Blue = 1;
  Green = 2;
  Cyan = 3;
  Red = 4;
  Magenta = 5;
  Brown = 6;
  LightGray = 7;
  DarkGray = 8;
  LightBlue = 9;
  LightGreen = 10;
  LightCyan = 11;
  LightRed = 12;
  LightMagenta = 13;
  Yellow = 14;
  White = 15;

implementation

procedure effacerEcran;
var
  stdOutputHandle: Cardinal;
  cursorPos: TCoord;
  width, height: Cardinal;
  nbChars: Cardinal;
  TextAttr: byte;
begin
  stdOutputHandle := GetStdHandle(STD_OUTPUT_HANDLE);
  cursorPos := GetLargestConsoleWindowSize(stdOutputHandle);
  width := cursorPos.x;
  height := cursorPos.y;
  cursorPos.x := 0;
  cursorPos.y := 0;
  TextAttr := $0;
  FillConsoleOutputCharacter(stdOutputHandle, ' ', width * height, cursorPos,
    nbChars);
  FillConsoleOutputAttribute(stdOutputHandle, TextAttr, width * height,
    cursorPos, nbChars);
  cursorPos.x := 0;
  cursorPos.y := 0;
  SetConsoleCursorPosition(stdOutputHandle, cursorPos);
end;

procedure deplacerCurseur(position: coordonnees);
var
  stdOutputHandle: Cardinal;
  cursorPos: TCoord;
begin
  stdOutputHandle := GetStdHandle(STD_OUTPUT_HANDLE);
  cursorPos.x := position.x;
  cursorPos.y := position.y;
  SetConsoleCursorPosition(stdOutputHandle, cursorPos);
end;

procedure deplacerCurseurXY(x, y: integer);
var
  c: coordonnees;
begin
  c.x := x;
  c.y := y;
  deplacerCurseur(c);
end;

function positionCurseur(): coordonnees;
var
  stdOutputHandle: Cardinal;
  CSBI: TConsoleScreenBufferInfo;
  pos: TCoord;
  res: coordonnees;
begin
  stdOutputHandle := GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleScreenBufferInfo(stdOutputHandle, CSBI);
  pos := CSBI.dwCursorPosition;
  res.x := pos.x;
  res.y := pos.y;
  positionCurseur := res;
end;

procedure changerLigneCurseur(position: integer);
var
  c: coordonnees;
begin
  c := positionCurseur();
  c.y := position;
  deplacerCurseur(c);
end;

procedure changerColonneCurseur(position: integer);
var
  c: coordonnees;
begin
  c := positionCurseur();
  c.x := position;
  deplacerCurseur(c);
end;

procedure ecrireEnPosition(position: coordonnees; texte: machaine);
begin
  texte := accent(texte);
  deplacerCurseur(position);
  write(texte);
end;

procedure ecrireNbEnPosition(position: coordonnees; nb: smallint);
begin
  deplacerCurseur(position);
  write(nb);
end;

procedure dessinerCadre(c1, c2: coordonnees; t: typeBordure; ct, cf: byte);
type
  typeBords = (CHG, H, CHD, V, CBG, CBD);
type
  tabBordures = array [typeBords] of char;
const
  bordsSimples: tabBordures = (#218, #196, #191, #179, #192, #217);
  bordsDoubles: tabBordures = (#201, #205, #187, #186, #200, #188);
var
  bords: tabBordures;
  i, j: integer;
begin
  // changement de couleur
  couleurs(ct, cf);

  // on choisit la bordure
  if t = simple then
    bords := bordsSimples
  else
    bords := bordsDoubles;

  // on dessine la ligne du haut
  deplacerCurseur(c1);
  write(bords[CHG]);
  for i := c1.x + 1 to c2.x - 1 do
    write(bords[H]);
  write(bords[CHD]);

  // on dessine les lignes intermédiaires
  for i := c1.y + 1 to c2.y - 1 do
  begin
    deplacerCurseurXY(c1.x, i);
    write(bords[V]);
    for j := c1.x + 1 to c2.x - 1 do
      write(' ');
    write(bords[V]);
  end;

  // on dessine la ligne du bas
  deplacerCurseurXY(c1.x, c2.y);
  write(bords[CBG]);
  for i := c1.x + 1 to c2.x - 1 do
    write(bords[H]);
  write(bords[CBD]);

end;

procedure dessinerCadreXY(x, y, x2, y2: integer; t: typeBordure;
  coulTrait, coulFond: byte);
var
  c1, c2: coordonnees;
begin
  c1.x := x;
  c1.y := y;
  c2.x := x2;
  c2.y := y2;
  dessinerCadre(c1, c2, t, coulTrait, coulFond);
end;

procedure attendre(millisecondes: integer);
begin
  sleep(millisecondes);
end;

procedure couleurs(ct, cf: byte);
begin
  couleurTexte(ct);
  couleurFond(cf);
end;

procedure couleurTexte(couleur: byte);
var
  LastMode: Word;
  Buffer: CONSOLE_SCREEN_BUFFER_INFO;
  TextAttr: byte;
begin
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), Buffer);
  LastMode := Buffer.wAttributes;
  TextAttr := (LastMode and $F0) or (couleur and $0F);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TextAttr);
end;

procedure couleurFond(couleur: byte);
var
  LastMode: Word;
  Buffer: CONSOLE_SCREEN_BUFFER_INFO;
  TextAttr: byte;
begin
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), Buffer);
  LastMode := Buffer.wAttributes;
  TextAttr := (LastMode and $0F) or ((couleur shl 4) and $F0);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), TextAttr);
end;

function accent(s: machaine): machaine;
var
  i: byte;
begin
  for i := 0 to Length(s) do
  begin
    if s[i] = 'é' then
      accent[i] := #130

    Else if s[i] = 'è' then
      accent[i] := #138

    Else if s[i] = 'ê' then
      accent[i] := #136

    Else if s[i] = 'à' then
      accent[i] := #133

    Else if s[i] = 'â' then
      accent[i] := #131

    Else if s[i] = 'î' then
      accent[i] := #140

    Else if s[i] = 'ï' then
      accent[i] := #139

    Else if s[i] = 'ù' then
      accent[i] := #151

    Else if s[i] = 'ç' then
      accent[i] := #135

    Else
      accent[i] := s[i];
  end;
end;

procedure accueil;
var
  c: coordonnees;
begin
  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  deplacerCurseurXY(0, 0);
  couleurTexte(4);
  //M
  c.x := 6;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 6;
  c.y := 6;
  ecrireEnPosition(c, 'I');
  c.x := 6;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 6;
  c.y := 8;
  ecrireEnPosition(c, 'I');
  c.x := 6;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 7;
  c.y := 6;
  ecrireEnPosition(c, 'I');
  c.x := 8;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 9;
  c.y := 8;
  ecrireEnPosition(c, 'I');
  c.x := 10;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 11;
  c.y := 6;
  ecrireEnPosition(c, 'I');
  c.x := 12;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 12;
  c.y := 6;
  ecrireEnPosition(c, 'I');
  c.x := 12;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 12;
  c.y := 8;
  ecrireEnPosition(c, 'I');
  c.x := 12;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  //E
  c.x := 15;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 15;
  c.y := 6;
  ecrireEnPosition(c, 'I');
  c.x := 15;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 15;
  c.y := 8;
  ecrireEnPosition(c, 'I');
  c.x := 15;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 16;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 17;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 18;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 15;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 16;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 17;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 18;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 15;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 16;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 17;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 18;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  //T
  c.x := 20;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 21;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 22;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 23;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 24;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 25;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 26;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 23;
  c.y := 6;
  ecrireEnPosition(c, 'I');
  c.x := 23;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 23;
  c.y := 8;
  ecrireEnPosition(c, 'I');
  c.x := 23;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  //R
  c.x := 29;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 29;
  c.y := 6;
  ecrireEnPosition(c, 'I');
  c.x := 29;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 29;
  c.y := 8;
  ecrireEnPosition(c, 'I');
  c.x := 29;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 30;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 31;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 32;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 32;
  c.y := 6;
  ecrireEnPosition(c, 'I');
  c.x := 32;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 32;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 31;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 30;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 29;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 30;
  c.y := 8;
  ecrireEnPosition(c, 'I');
  c.x := 31;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  //O
  c.x := 34;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 35;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 36;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 37;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 38;
  c.y := 5;
  ecrireEnPosition(c, 'I');
  c.x := 38;
  c.y := 6;
  ecrireEnPosition(c, 'I');
  c.x := 38;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 38;
  c.y := 8;
  ecrireEnPosition(c, 'I');
  c.x := 38;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 34;
  c.y := 6;
  ecrireEnPosition(c, 'I');
  c.x := 34;
  c.y := 7;
  ecrireEnPosition(c, 'I');
  c.x := 34;
  c.y := 8;
  ecrireEnPosition(c, 'I');
  c.x := 34;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 35;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 36;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 37;
  c.y := 9;
  ecrireEnPosition(c, 'I');
  c.x := 38;
  c.y := 9;
  ecrireEnPosition(c, 'I');
end;

procedure bestiaire;
var
  c: coordonnees;
begin
  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  deplacerCurseurXY(0, 0);
  couleurTexte(4);
  c.x := 3;
  c.y := 2;
  ecrireEnPosition(c, 'Rats');
  c.x := 3;
  c.y := 3;
  ecrireEnPosition(c, 'Nosalis');
  c.x := 3;
  c.y := 4;
  ecrireEnPosition(c, 'Rodeurs');
  c.x := 3;
  c.y := 5;
  ecrireEnPosition(c, 'Chef de meute nosalis');
  c.x := 3;
  c.y := 6;
  ecrireEnPosition(c, 'Démon');
  c.x := 3;
  c.y := 7;
  ecrireEnPosition(c, 'Milice');
  c.x := 3;
  c.y := 8;
  ecrireEnPosition(c, 'Bandits');
  c.x := 3;
  c.y := 9;
  ecrireEnPosition(c, 'Fachos');
  c.x := 3;
  c.y := 10;
  ecrireEnPosition(c, 'Rouge');
end;

procedure credit;
var
  c: coordonnees;
begin
  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  deplacerCurseurXY(0, 0);
  couleurTexte(4);
  c.x := 23;
  c.y := 10;
  ecrireEnPosition(c, 'Développement Adrien Bonfils');
  c.x := 23;
  c.y := 11;
  ecrireEnPosition(c, 'Histoire Donovan Broquin');
  c.x := 23;
  c.y := 12;
  ecrireEnPosition(c, 'Testeur ');
  c.x := 23;
  c.y := 13;
  ecrireEnPosition(c, 'Merci d''avoir joué à notre jeu ♥');
end;

procedure menu;
var
  c: coordonnees;
begin
  couleurTexte(4);
  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  dessinerCadreXY(2, 1, 25, 12, double, 0, 7);
  dessinerCadreXY(53, 1, 77, 12, double, 0, 7);
  dessinerCadreXY(17, 15, 62, 20, double, 0, 7);
  deplacerCurseurXY(0, 0);
  couleurTexte(4);
  c.x := 3;
  c.y := 2;
  ecrireEnPosition(c, '1. Nouvelle partie !');
  c.x := 54;
  c.y := 2;
  ecrireEnPosition(c, '2. Continuer ?');
  if (FileExists('sav.txt') = TRUE) then
  begin
    chargement;
    c.x := 54;
    c.y := 4;
    ecrireEnPosition(c, 'Nom : ');
    ecrireEnPosition(positionCurseur, get_nom_perso);
    c.x := 54;
    c.y := 5;
    ecrireEnPosition(c, 'PV : ');
    ecrireNbEnPosition(positionCurseur, get_PV_perso);
    c.x := 54;
    c.y := 6;
    ecrireEnPosition(c, 'Energie : ');
    ecrireNbEnPosition(positionCurseur, get_energie_perso);
    c.x := 54;
    c.y := 7;
    ecrireEnPosition(c, 'Balles : ');
    ecrireNbEnPosition(positionCurseur, get_argent_perso);
    c.x := 54;
    c.y := 8;
    ecrireEnPosition(c, 'Level : ');
    ecrireNbEnPosition(positionCurseur, get_level_perso);
    c.x := 54;
    c.y := 10;
    ecrireEnPosition(c, 'Chapitre : ');
    c.x := 54;
    c.y := 11;
    ecrireEnPosition(c, get_chapitre);
  end;
  c.x := 18;
  c.y := 16;
  ecrireEnPosition(c, '3. Bestaire');
  c.x := 32;
  c.y := 17;
  ecrireEnPosition(c, '4. Credits');
  c.x := 44;
  c.y := 18;
  ecrireEnPosition(c, '5. Quitter');
  deplacerCurseurXY(34, 19);
end;

procedure affichage_ajout_stat(n: smallint);
var
  c: coordonnees;
begin
  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  dessinerCadreXY(20, 1, 58, 7, double, 0, 7);
  dessinerCadreXY(12, 9, 67, 23, double, 0, 7);
  deplacerCurseurXY(0, 0);
  couleurTexte(4);
  c.x := 13;
  c.y := 10;
  ecrireEnPosition(c, '1. PV : ');
  ecrireNbEnPosition(positionCurseur, get_PV_perso);
  ecrireEnPosition(positionCurseur, ' + 10');
  c.x := 13;
  c.y := 11;
  ecrireEnPosition(c, '2. Energie : ');
  ecrireNbEnPosition(positionCurseur, get_energie_perso);
  ecrireEnPosition(positionCurseur, ' + 10');
  c.x := 13;
  c.y := 12;
  ecrireEnPosition(c, '3. Concentration : ');
  ecrireNbEnPosition(positionCurseur, get_concentration_perso);
  ecrireEnPosition(positionCurseur, ' + 1');
  c.x := 13;
  c.y := 13;
  ecrireEnPosition(c, '4. Discretion : ');
  ecrireNbEnPosition(positionCurseur, get_discretion_perso);
  ecrireEnPosition(positionCurseur, ' + 1');
  c.x := 13;
  c.y := 14;
  ecrireEnPosition(c, '5. Esquive : ');
  ecrireNbEnPosition(positionCurseur, get_esquive_perso);
  ecrireEnPosition(positionCurseur, ' + 1');
  c.x := 13;
  c.y := 15;
  ecrireEnPosition(c, '6. Force : ');
  ecrireNbEnPosition(positionCurseur, get_force_perso);
  ecrireEnPosition(positionCurseur, ' + 1');
  c.x := 13;
  c.y := 16;
  ecrireEnPosition(c, '7. Precision : ');
  ecrireNbEnPosition(positionCurseur, get_precision_perso);
  ecrireEnPosition(positionCurseur, ' + 1');
  c.x := 13;
  c.y := 17;
  ecrireEnPosition(c, '8. Resistance : ');
  ecrireNbEnPosition(positionCurseur, get_resistance_perso);
  ecrireEnPosition(positionCurseur, ' + 1');
  c.x := 21;
  c.y := 2;
  ecrireEnPosition(c, 'Selectionner les stats a augmenter');
  c.x := 21;
  c.y := 4;
  ecrireEnPosition(c, 'Nombre de points : ');
  ecrireNbEnPosition(positionCurseur, n);
  deplacerCurseurXY(21, 5);
end;

// combat

procedure affichage_stat;
begin
  affichage_stat_perso;

  affichage_stat_e;
end;

procedure affichage_info;
begin
  affichage_info_perso;

  affichage_info_e;
end;

procedure affichage_stat_e;
var
  c: coordonnees;
begin
  dessinerCadreXY(54, 14, 78, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 56;
  c.y := 15;
  ecrireEnPosition(c, 'Concentration : ');
  ecrireNbEnPosition(positionCurseur, get_concentration_e);
  c.x := 56;
  c.y := 16;
  ecrireEnPosition(c, 'Dégat : ');
  ecrireNbEnPosition(positionCurseur, get_degat_arme_e);
  c.x := 56;
  c.y := 17;
  ecrireEnPosition(c, 'Esquive : ');
  ecrireNbEnPosition(positionCurseur, get_esquive_e);
  c.x := 56;
  c.y := 18;
  ecrireEnPosition(c, 'Force : ');
  ecrireNbEnPosition(positionCurseur, get_force_e);
  c.x := 56;
  c.y := 19;
  ecrireEnPosition(c, 'Précision : ');
  ecrireNbEnPosition(positionCurseur, get_precision_e);
  c.x := 56;
  c.y := 20;
  ecrireEnPosition(c, 'Résistance : ');
  ecrireNbEnPosition(positionCurseur, get_resistance_e);
  c.x := 56;
  c.y := 21;
  ecrireEnPosition(c, 'Vitesse : ');
  ecrireNbEnPosition(positionCurseur, get_vitesse_e);
end;

procedure affichage_info_e;
var
  c: coordonnees;
begin
  dessinerCadreXY(54, 1, 78, 6, double, 0, 7);
  couleurTexte(4);
  c.x := 56;
  c.y := 2;
  ecrireEnPosition(c, 'Nom : ');
  ecrireEnPosition(positionCurseur, get_nom_e);
  c.x := 56;
  c.y := 3;
  ecrireEnPosition(c, 'PV : ');
  ecrireNbEnPosition(positionCurseur, get_PV_e);
  c.x := 56;
  c.y := 4;
  ecrireEnPosition(c, 'Energie : ');
  ecrireNbEnPosition(positionCurseur, get_energie_e);
end;

procedure ecran_combat;

begin
  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  dessinerCadreXY(26, 1, 52, 7, double, 0, 7);

  affichage_info;
  affichage_stat;

  deplacerCurseurXY(0, 0);
end;

procedure nom_texte(nom: machaine; texte: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 12;
  ecrireEnPosition(c, nom);
  ecrireEnPosition(positionCurseur, texte);
end;

procedure nom_texte_combat(nom: machaine; texte: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 13;
  ecrireEnPosition(c, nom);
  ecrireEnPosition(positionCurseur, texte);
end;

procedure texte_choix_2(choix1, choix2: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 2;
  ecrireEnPosition(c, choix1);
  c.x := 27;
  c.y := 3;
  ecrireEnPosition(c, choix2);
  deplacerCurseurXY(27, 4);
end;

procedure texte_choix_4(choix1, choix2, choix3, choix4: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 2;
  ecrireEnPosition(c, choix1);
  c.x := 27;
  c.y := 3;
  ecrireEnPosition(c, choix2);
  c.x := 27;
  c.y := 4;
  ecrireEnPosition(c, choix3);
  c.x := 27;
  c.y := 5;
  ecrireEnPosition(c, choix4);
  deplacerCurseurXY(27, 6);
end;

procedure texte_combat(texte: machaine);
var
  c: coordonnees;
begin
  couleurTexte(4);
  c.x := 27;
  c.y := 13;
  ecrireEnPosition(c, texte);
end;

procedure texte_nb_texte_combat(texte: machaine; nb: smallint;
  texte2: machaine);
var
  c: coordonnees;
begin
  couleurTexte(4);
  c.x := 27;
  c.y := 14;
  ecrireEnPosition(c, texte);
  ecrireNbEnPosition(positionCurseur, nb);
  ecrireEnPosition(positionCurseur, texte2);
end;

procedure nom_texte_nb_texte(nom: machaine; texte: machaine; nb: smallint;
  texte2: machaine);
var
  c: coordonnees;
begin
  couleurTexte(4);
  c.x := 27;
  c.y := 12;
  ecrireEnPosition(c, nom);
  ecrireEnPosition(positionCurseur, texte);
  ecrireNbEnPosition(positionCurseur, nb);
  ecrireEnPosition(positionCurseur, texte2);
end;

// inventaire

procedure ecran_inventaire;
begin
  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  dessinerCadreXY(26, 1, 52, 7, double, 0, 7);

  affichage_info;
  affichage_stat;

  deplacerCurseurXY(0, 0);
end;

procedure ecran_inventaire_arme;
begin
  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  dessinerCadreXY(26, 1, 52, 7, double, 0, 7);

  affichage_info;
  affichage_stat;

  deplacerCurseurXY(0, 0);
end;

procedure choix_2;
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 2;
  ecrireEnPosition(c, '1. Objets');
  c.x := 27;
  c.y := 3;
  ecrireEnPosition(c, '2. Armes');
  c.x := 27;
  c.y := 4;
  ecrireEnPosition(c, '3. Retour');
  deplacerCurseurXY(27, 5);
end;

procedure choix_4;
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 2;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_1);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_1_perso);
  ecrireEnPosition(positionCurseur, get_description_objet_1);
  c.x := 27;
  c.y := 3;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_2);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_2_perso);
  ecrireEnPosition(positionCurseur, get_description_objet_2);
  c.x := 27;
  c.y := 4;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_3);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_3_perso);
  ecrireEnPosition(positionCurseur, get_description_objet_3);
  c.x := 27;
  c.y := 5;
  ecrireEnPosition(c, '4. Retour');
  deplacerCurseurXY(27, 6);
end;

procedure choix_6;
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 9, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 2;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_1);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_1_perso);
  c.x := 27;
  c.y := 3;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_2);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_2_perso);
  c.x := 27;
  c.y := 4;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_3);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_3_perso);
  c.x := 27;
  c.y := 5;
  ecrireEnPosition(c, '4. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_4);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_4_perso);
  c.x := 27;
  c.y := 6;
  ecrireEnPosition(c, '5. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_5);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_5_perso);
  c.x := 27;
  c.y := 7;
  ecrireEnPosition(c, '6. Retour');
  deplacerCurseurXY(27, 8);
end;

procedure texte_inventaire(texte: machaine);
var
  c: coordonnees;
begin
  couleurTexte(4);
  c.x := 27;
  c.y := 13;
  ecrireEnPosition(c, texte);
end;

// histoire

procedure affichage_stat_perso;
var
  c: coordonnees;
begin
  dessinerCadreXY(1, 14, 24, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 3;
  c.y := 15;
  ecrireEnPosition(c, 'Concentration : ');
  ecrireNbEnPosition(positionCurseur, get_concentration_perso);
  c.x := 3;
  c.y := 16;
  ecrireEnPosition(c, 'Dégat de l''arme : ');
  ecrireNbEnPosition(positionCurseur, get_degat_arme_perso);
  c.x := 3;
  c.y := 17;
  ecrireEnPosition(c, 'Discrétion : ');
  ecrireNbEnPosition(positionCurseur, get_discretion_perso);
  c.x := 3;
  c.y := 18;
  ecrireEnPosition(c, 'Esquive : ');
  ecrireNbEnPosition(positionCurseur, get_esquive_perso);
  c.x := 3;
  c.y := 19;
  ecrireEnPosition(c, 'Force : ');
  ecrireNbEnPosition(positionCurseur, get_force_perso);
  c.x := 3;
  c.y := 20;
  ecrireEnPosition(c, 'Précision : ');
  ecrireNbEnPosition(positionCurseur, get_precision_perso);
  c.x := 3;
  c.y := 21;
  ecrireEnPosition(c, 'Résistance : ');
  ecrireNbEnPosition(positionCurseur, get_resistance_perso);
  c.x := 3;
  c.y := 22;
  ecrireEnPosition(c, 'Vitesse : ');
  ecrireNbEnPosition(positionCurseur, get_vitesse_perso);
end;

procedure affichage_info_perso;
var
  c: coordonnees;
begin
  dessinerCadreXY(1, 1, 24, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 3;
  c.y := 2;
  ecrireEnPosition(c, 'Nom : ');
  ecrireEnPosition(positionCurseur, get_nom_perso);
  c.x := 3;
  c.y := 3;
  ecrireEnPosition(c, 'PV : ');
  ecrireNbEnPosition(positionCurseur, get_PV_perso);
  c.x := 3;
  c.y := 4;
  ecrireEnPosition(c, 'Energie : ');
  ecrireNbEnPosition(positionCurseur, get_energie_perso);
  c.x := 3;
  c.y := 5;
  ecrireEnPosition(c, 'Balles : ');
  ecrireNbEnPosition(positionCurseur, get_argent_perso);
  c.x := 3;
  c.y := 6;
  ecrireEnPosition(c, 'Level : ');
  ecrireNbEnPosition(positionCurseur, get_level_perso);
end;

procedure affichage_chapitre;
var
  c: coordonnees;
begin
  dessinerCadreXY(1, 9, 23, 12, double, 0, 7);
  couleurTexte(4);
  c.x := 2;
  c.y := 10;
  ecrireEnposition(c,get_chapitre);
end;

procedure ecran_histoire;
begin

  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  dessinerCadreXY(27, 1, 77, 7, double, 0, 7);

  affichage_info_perso;
  affichage_stat_perso;
  affichage_chapitre;

  deplacerCurseurXY(0, 0);
end;

procedure texte_choix_2_histoire(choix1, choix2: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(26, 1, 77, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 28;
  c.y := 2;
  ecrireEnPosition(c, choix1);
  c.x := 28;
  c.y := 3;
  ecrireEnPosition(c, choix2);
  deplacerCurseurXY(28, 4);
end;

procedure texte_choix_3_histoire(choix1, choix2, choix3: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(26, 1, 77, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 28;
  c.y := 2;
  ecrireEnPosition(c, choix1);
  c.x := 28;
  c.y := 3;
  ecrireEnPosition(c, choix2);
  c.x := 28;
  c.y := 4;
  ecrireEnPosition(c, choix3);
  deplacerCurseurXY(28, 5);
end;

procedure texte_choix_4_histoire(choix1, choix2, choix3, choix4: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(26, 1, 77, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 28;
  c.y := 2;
  ecrireEnPosition(c, choix1);
  c.x := 28;
  c.y := 3;
  ecrireEnPosition(c, choix2);
  c.x := 28;
  c.y := 4;
  ecrireEnPosition(c, choix3);
  c.x := 28;
  c.y := 5;
  ecrireEnPosition(c, choix4);
  deplacerCurseurXY(28, 6);
end;

procedure texte(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7, ligne8,
  ligne9, ligne10, ligne11, ligne12, ligne13: machaine);
var
  c: coordonnees;
begin
  ecran_histoire;
  dessinerCadreXY(26, 9, 77, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 10;
  ecrireEnPosition(c, ligne1);
  c.x := 27;
  c.y := 11;
  ecrireEnPosition(c, ligne2);
  c.x := 27;
  c.y := 12;
  ecrireEnPosition(c, ligne3);
  c.x := 27;
  c.y := 13;
  ecrireEnPosition(c, ligne4);
  c.x := 27;
  c.y := 14;
  ecrireEnPosition(c, ligne5);
  c.x := 27;
  c.y := 15;
  ecrireEnPosition(c, ligne6);
  c.x := 27;
  c.y := 16;
  ecrireEnPosition(c, ligne7);
  c.x := 27;
  c.y := 17;
  ecrireEnPosition(c, ligne8);
  c.x := 27;
  c.y := 18;
  ecrireEnPosition(c, ligne9);
  c.x := 27;
  c.y := 19;
  ecrireEnPosition(c, ligne10);
  c.x := 27;
  c.y := 20;
  ecrireEnPosition(c, ligne11);
  c.x := 27;
  c.y := 21;
  ecrireEnPosition(c, ligne12);
  c.x := 27;
  c.y := 22;
  ecrireEnPosition(c, ligne13);
end;

procedure texte_nom(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7,
  ligne8, ligne9, ligne10, ligne11, ligne12, ligne13, ligne14, nom: machaine);
var
  c: coordonnees;
begin
  ecran_histoire;
  dessinerCadreXY(26, 9, 77, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 10;
  ecrireEnPosition(c, ligne1);
  ecrireEnPosition(positionCurseur, nom);
  ecrireEnPosition(positionCurseur, ligne2);
  c.x := 27;
  c.y := 11;
  ecrireEnPosition(c, ligne3);
  c.x := 27;
  c.y := 12;
  ecrireEnPosition(c, ligne4);
  c.x := 27;
  c.y := 13;
  ecrireEnPosition(c, ligne5);
  c.x := 27;
  c.y := 14;
  ecrireEnPosition(c, ligne6);
  c.x := 27;
  c.y := 15;
  ecrireEnPosition(c, ligne7);
  c.x := 27;
  c.y := 16;
  ecrireEnPosition(c, ligne8);
  c.x := 27;
  c.y := 17;
  ecrireEnPosition(c, ligne9);
  c.x := 27;
  c.y := 18;
  ecrireEnPosition(c, ligne10);
  c.x := 27;
  c.y := 19;
  ecrireEnPosition(c, ligne11);
  c.x := 27;
  c.y := 20;
  ecrireEnPosition(c, ligne12);
  c.x := 27;
  c.y := 21;
  ecrireEnPosition(c, ligne13);
  c.x := 27;
  c.y := 22;
  ecrireEnPosition(c, ligne14);
end;

procedure texte_nom_nom(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6, ligne7,
  ligne8, ligne9, ligne10, ligne11, ligne12, ligne13, ligne14, ligne15,
  ligne16, nom: machaine);
var
  c: coordonnees;
begin
  ecran_histoire;
  dessinerCadreXY(26, 9, 77, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 10;
  ecrireEnPosition(c, ligne1);
  ecrireEnPosition(positionCurseur, nom);
  ecrireEnPosition(positionCurseur, ligne2);
  ecrireEnPosition(positionCurseur, nom);
  ecrireEnPosition(positionCurseur, ligne3);
  c.x := 27;
  c.y := 11;
  ecrireEnPosition(c, ligne4);
  c.x := 27;
  c.y := 12;
  ecrireEnPosition(c, ligne5);
  c.x := 27;
  c.y := 13;
  ecrireEnPosition(c, ligne6);
  c.x := 27;
  c.y := 14;
  ecrireEnPosition(c, ligne7);
  c.x := 27;
  c.y := 15;
  ecrireEnPosition(c, ligne8);
  ecrireEnPosition(positionCurseur, nom);
  ecrireEnPosition(positionCurseur, ligne9);
  c.x := 27;
  c.y := 16;
  ecrireEnPosition(c, ligne10);
  c.x := 27;
  c.y := 17;
  ecrireEnPosition(c, ligne11);
  c.x := 27;
  c.y := 18;
  ecrireEnPosition(c, ligne12);
  c.x := 27;
  c.y := 19;
  ecrireEnPosition(c, ligne13);
  c.x := 27;
  c.y := 20;
  ecrireEnPosition(c, ligne14);
  c.x := 27;
  c.y := 21;
  ecrireEnPosition(c, ligne15);
  c.x := 27;
  c.y := 22;
  ecrireEnPosition(c, ligne16);
end;

procedure texte_nom_nom_2(ligne1, ligne2, ligne3, ligne4, ligne5, ligne6,
  ligne7, ligne8, ligne9, ligne10, ligne11, ligne12, ligne13, ligne14,
  nom: machaine);
var
  c: coordonnees;
begin
  ecran_histoire;
  dessinerCadreXY(26, 9, 77, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 10;
  ecrireEnPosition(c, ligne1);
  c.x := 27;
  c.y := 11;
  ecrireEnPosition(c, ligne2);
  c.x := 27;
  c.y := 12;
  ecrireEnPosition(c, ligne3);
  c.x := 27;
  c.y := 13;
  ecrireEnPosition(c, ligne4);
  c.x := 27;
  c.y := 14;
  ecrireEnPosition(c, nom);
  ecrireEnPosition(positionCurseur, ligne5);
  ecrireEnPosition(positionCurseur, nom);
  ecrireEnPosition(positionCurseur, ligne6);
  c.x := 27;
  c.y := 15;
  ecrireEnPosition(c, ligne7);
  c.x := 27;
  c.y := 16;
  ecrireEnPosition(c, ligne8);
  c.x := 27;
  c.y := 17;
  ecrireEnPosition(c, ligne9);
  c.x := 27;
  c.y := 18;
  ecrireEnPosition(c, ligne10);
  c.x := 27;
  c.y := 19;
  ecrireEnPosition(c, ligne11);
  c.x := 27;
  c.y := 20;
  ecrireEnPosition(c, ligne12);
  c.x := 27;
  c.y := 21;
  ecrireEnPosition(c, ligne13);
  c.x := 27;
  c.y := 22;
  ecrireEnPosition(c, ligne14);
end;

// vendeur

procedure ecran_vendeur;
begin
  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  dessinerCadreXY(26, 1, 52, 7, double, 0, 7);
  deplacerCurseurXY(0, 0);
  affichage_info_perso;
  affichage_stat_perso;
  affichage_inventaire;
  affichage_vendeur;
end;

procedure ecran_vendeur_arme;
begin
  dessinerCadreXY(0, 0, 79, 24, double, 0, 8);
  dessinerCadreXY(26, 1, 52, 7, double, 0, 7);
  deplacerCurseurXY(0, 0);
  affichage_info_perso;
  affichage_stat_perso;
  affichage_equipement;
  affichage_vendeur;
end;

procedure affichage_inventaire;
var
  c: coordonnees;
begin
  dessinerCadreXY(54, 1, 78, 6, double, 0, 7);
  couleurTexte(4);
  c.x := 55;
  c.y := 2;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_1);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_1_perso);
  c.x := 55;
  c.y := 3;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_2);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_2_perso);
  c.x := 55;
  c.y := 4;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_3);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_3_perso);
end;

procedure affichage_equipement;
var
  c: coordonnees;
begin
  dessinerCadreXY(54, 1, 78, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 55;
  c.y := 2;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_1);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_1_perso);
  c.x := 55;
  c.y := 3;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_2);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_2_perso);
  c.x := 55;
  c.y := 4;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_3);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_3_perso);
  c.x := 55;
  c.y := 5;
  ecrireEnPosition(c, '4. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_4);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_4_perso);
  c.x := 55;
  c.y := 6;
  ecrireEnPosition(c, '5. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_5);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_5_perso);
end;

procedure affichage_vendeur;
var
  c: coordonnees;
begin
  dessinerCadreXY(27, 11, 77, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 28;
  c.y := 12;
  if (get_checkpoint < 6) then
  begin
    ecrireEnPosition(c, 'Bonjour ... ');
    ecrireEnPosition(positionCurseur, get_nom_perso);
    ecrireEnPosition(positionCurseur, ' ravis de vous rencontrer !');
  end
  Else
  begin
    ecrireEnPosition(c, 'Bonjour ');
    ecrireEnPosition(positionCurseur, get_nom_perso);
    ecrireEnPosition(positionCurseur, ' ravis de te revoir !');
  end;
  achat_vente;
  deplacerCurseurXY(26, 5);
end;

procedure achat_vente;
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 2;
  ecrireEnPosition(c, '1. Acheter');
  c.x := 27;
  c.y := 3;
  ecrireEnPosition(c, '2. Vendre');
  c.x := 27;
  c.y := 4;
  ecrireEnPosition(c, '3. Partir');
end;

procedure affichage_achat_objet;
var
  c: coordonnees;
begin
  c.x := 28;
  c.y := 14;
  ecrireEnPosition(c, 'Voilà ce que j''ai à vendre ');
  couleurTexte(4);
  c.x := 28;
  c.y := 15;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_1);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_1_v);
  ecrireEnPosition(positionCurseur, get_description_objet_1);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_objet_1_v);
  c.x := 28;
  c.y := 16;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_2);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_2_v);
  ecrireEnPosition(positionCurseur, get_description_objet_2);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_objet_2_v);
  c.x := 28;
  c.y := 17;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_3);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_3_v);
  ecrireEnPosition(positionCurseur, get_description_objet_3);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_objet_3_v);
end;

procedure affichage_achat_arme;
var
  c: coordonnees;
begin
  c.x := 28;
  c.y := 14;
  ecrireEnPosition(c, 'Voila ce que j''ai à vendre ');
  couleurTexte(4);
  c.x := 28;
  c.y := 15;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_1);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_1_v);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_arme_1_v);
  c.x := 28;
  c.y := 16;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_2);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_2_v);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_arme_2_v);
  c.x := 28;
  c.y := 17;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_3);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_3_v);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_arme_3_v);
  c.x := 28;
  c.y := 18;
  ecrireEnPosition(c, '4. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_4);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_4_v);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_arme_4_v);
  c.x := 28;
  c.y := 19;
  ecrireEnPosition(c, '5. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_5);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_arme_5_v);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_arme_5_v);
end;

procedure affichage_achat_amelioration;
var
  c: coordonnees;
begin
  c.x := 28;
  c.y := 14;
  ecrireEnPosition(c, 'Voilà ce que j''ai comme amélioration ');
  couleurTexte(4);
  c.x := 28;
  c.y := 15;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_3);
  ecrireEnPosition(positionCurseur, '+ 15 dégat');
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_amelioration_1_v);
  c.x := 28;
  c.y := 16;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_4);
  ecrireEnPosition(positionCurseur, '+ 10 vitesse');
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_amelioration_2_v);
  c.x := 28;
  c.y := 17;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, get_nom_arme_5);
  ecrireEnPosition(positionCurseur, '+ 15 précision');
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_amelioration_3_v);

end;

procedure affichage_vente;
var
  c: coordonnees;
begin
  couleurTexte(4);
  c.x := 28;
  c.y := 14;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_1);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_1_perso);
  ecrireEnPosition(positionCurseur, get_description_objet_1);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_objet_1_v);
  c.x := 28;
  c.y := 15;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_2);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_2_perso);
  ecrireEnPosition(positionCurseur, get_description_objet_2);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_objet_2_v);
  c.x := 28;
  c.y := 16;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, get_nom_objet_3);
  ecrireEnPosition(positionCurseur, ' x');
  ecrireNbEnPosition(positionCurseur, get_quantite_objet_3_perso);
  ecrireEnPosition(positionCurseur, get_description_objet_3);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, get_prix_objet_3_v);
end;

procedure texte_v(texte: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(27, 11, 77, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 28;
  c.y := 13;
  ecrireEnPosition(c, texte);
  ecrireEnPosition(positionCurseur, ' ');
  ecrireEnPosition(positionCurseur, get_nom_perso);
end;

procedure texte_nom_v(texte: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(27, 11, 77, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 28;
  c.y := 13;
  ecrireEnPosition(c, texte);
end;

procedure texte_nom_nb_objet_v(texte: machaine; texte2: machaine; nb: smallint;
  objet: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(27, 11, 77, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 28;
  c.y := 13;
  ecrireEnPosition(c, texte);
  ecrireEnPosition(positionCurseur, ' ');
  ecrireEnPosition(positionCurseur, get_nom_perso);
  ecrireEnPosition(positionCurseur, ' ');
  ecrireEnPosition(positionCurseur, texte2);
  ecrireEnPosition(positionCurseur, ' ');
  ecrireNbEnPosition(positionCurseur, nb);
  ecrireEnPosition(positionCurseur, ' ');
  ecrireEnPosition(positionCurseur, objet);
end;

procedure texte_objet_v(objet: machaine; nb: smallint; prix: smallint);
var
  c: coordonnees;
begin
  dessinerCadreXY(27, 11, 77, 23, double, 0, 7);
  couleurTexte(4);
  c.x := 28;
  c.y := 14;
  ecrireEnPosition(c, objet);
  ecrireEnPosition(positionCurseur, ' : ');
  ecrireNbEnPosition(positionCurseur, nb);
  ecrireEnPosition(positionCurseur, ' Prix : ');
  ecrireNbEnPosition(positionCurseur, prix);
end;

procedure validation_achat(nb: smallint);
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 26;
  c.y := 3;
  ecrireEnPosition(c, 'Vous en voulez ');
  ecrireNbEnPosition(positionCurseur, nb);
  ecrireEnPosition(positionCurseur, ' ?');
  c.x := 26;
  c.y := 4;
  ecrireEnPosition(c, '1. OUI /2. NON');
  deplacerCurseurXY(26, 5);
end;

procedure validation_vente(nb: smallint);
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 26;
  c.y := 3;
  ecrireEnPosition(c, 'Vous voulez en vendre ');
  ecrireNbEnPosition(positionCurseur, nb);
  ecrireEnPosition(positionCurseur, ' ?');
  c.x := 26;
  c.y := 4;
  ecrireEnPosition(c, '1. OUI /2. NON');
  deplacerCurseurXY(26, 5);
end;

procedure validation_amelioration(texte: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 26;
  c.y := 3;
  ecrireEnPosition(c, 'Vous voulez améliorer ');
  c.x := 26;
  c.y := 4;
  ecrireEnPosition(c, texte);
  ecrireEnPosition(positionCurseur, ' ?');
  c.x := 26;
  c.y := 5;
  ecrireEnPosition(c, '1. OUI /2. NON');
  deplacerCurseurXY(26, 6);
end;

procedure nb_achat;
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 26;
  c.y := 2;
  ecrireEnPosition(c, 'Quantitée :');
end;

procedure choix_3_v(texte1, texte2, texte3: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 2;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, texte1);
  c.x := 27;
  c.y := 3;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, texte2);
  c.x := 27;
  c.y := 4;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, texte3);
  deplacerCurseurXY(27, 5);
end;

procedure choix_4_v(texte1, texte2, texte3, texte4: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 7, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 2;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, texte1);
  c.x := 27;
  c.y := 3;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, texte2);
  c.x := 27;
  c.y := 4;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, texte3);
  c.x := 27;
  c.y := 5;
  ecrireEnPosition(c, '4. ');
  ecrireEnPosition(positionCurseur, texte4);
  deplacerCurseurXY(27, 6);
end;

procedure choix_6_v(texte1, texte2, texte3, texte4, texte5, texte6: machaine);
var
  c: coordonnees;
begin
  dessinerCadreXY(25, 1, 53, 9, double, 0, 7);
  couleurTexte(4);
  c.x := 27;
  c.y := 2;
  ecrireEnPosition(c, '1. ');
  ecrireEnPosition(positionCurseur, texte1);
  c.x := 27;
  c.y := 3;
  ecrireEnPosition(c, '2. ');
  ecrireEnPosition(positionCurseur, texte2);
  c.x := 27;
  c.y := 4;
  ecrireEnPosition(c, '3. ');
  ecrireEnPosition(positionCurseur, texte3);
  c.x := 27;
  c.y := 5;
  ecrireEnPosition(c, '4. ');
  ecrireEnPosition(positionCurseur, texte4);
  c.x := 27;
  c.y := 6;
  ecrireEnPosition(c, '5. ');
  ecrireEnPosition(positionCurseur, texte5);
  c.x := 27;
  c.y := 7;
  ecrireEnPosition(c, '6. ');
  ecrireEnPosition(positionCurseur, texte6);
  deplacerCurseurXY(27, 8);
end;

end.
