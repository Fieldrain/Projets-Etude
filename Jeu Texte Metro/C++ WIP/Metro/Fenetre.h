#pragma once

enum ECouleur
{
	black = 0,
	dark_blue = 1,
	dark_green = 2,
	dark_aqua, dark_cyan = 3,
	dark_red = 4,
	dark_purple = 5, dark_pink = 5, dark_magenta = 5,
	dark_yellow = 6,
	dark_white = 7,
	gray = 8,
	blue = 9,
	green = 10,
	aqua = 11, cyan = 11,
	red = 12,
	purple = 13, pink = 13, magenta = 13,
	yellow = 14,
	white = 15
};

struct Coordonne {
	uint8_t X;
	uint8_t Y;
};

class IFenetre
{
public:

	virtual ~IFenetre() {}

	// supprime tous les caractères de l'écran mais ne change pas les couleurs de fond
	virtual void EffacerEcran() =0;

	// déplace le curseur à la position donnée
	virtual void DeplacerCurseur(Coordonne position)=0;

	// déplace le curseur aux coordonnées X, Y
	virtual void DeplacerCurseurXY(uint8_t x, uint8_t y)=0;

	// retourne la position actuelle du curseur
	virtual Coordonne PositionCurseur()=0;

	// change la ligne du curseur sans changer la colonne
	virtual void ChangerLigneCurseur(uint8_t line)=0;

	// change la colonne du curseur sans changer la ligne
	virtual void ChangerColonneCurseur(uint8_t row)=0;

	// affiche le texte à la position donnée
	virtual void EcrireEnPosition(Coordonne position, string texte)=0;

	// affiche le nombre à la position donnée
	virtual void EcrireNbEnPosition(Coordonne position, uint8_t nb)=0;

	// dessine un cadre à partir des coordonnées des points haut-gauche
	// et bas-droite, du type de bordure, de la couleur de trait et de
	// la couleur de fond
	virtual void DessinerCadreXY(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool bordureDouble = false, ECouleur coulTrait = ECouleur(15), ECouleur coulFond = ECouleur(0))=0;

	virtual void DessinerCadre(Coordonne x, Coordonne y, bool bordureDouble = false, ECouleur coulTrait = ECouleur(15), ECouleur coulFond = ECouleur(0))=0;

	// attends le nombre de ms indiqué
	virtual void Attendre(uint16_t temps)=0;

	// change la couleur de fond actuelle
	virtual void CouleurFond(ECouleur couleur)=0;

	// change la couleur de texte actuelle
	virtual void CouleurTexte(ECouleur couleur)=0;

	// change la couleur de texte et de fond
	virtual void Couleurs(ECouleur couleurTexte, ECouleur couleurFond)=0;

	// renvoie les caractere saisie par l'utilisateur
	virtual string RetourSaisi() = 0;

};