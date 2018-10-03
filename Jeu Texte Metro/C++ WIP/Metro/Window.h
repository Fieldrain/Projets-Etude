#pragma once
#include <windows.h>
#include "Fenetre.h"
class Window :
	public IFenetre
{
private:
	HANDLE console;
	SMALL_RECT rectWindow;
	COORD size;

	COORD CoordonneToCOORD(Coordonne cor);

	Coordonne COORDToCoordonne(COORD cor);

	void resizeWindow();

	// supprime tous les caractères de l'écran mais ne change pas les couleurs de fond
	void EffacerEcran();

	// déplace le curseur à la position donnée
	void DeplacerCurseur(Coordonne position);

	// déplace le curseur aux coordonnées X, Y
	void DeplacerCurseurXY(uint8_t x, uint8_t y);

	// retourne la position actuelle du curseur
	Coordonne PositionCurseur();

	// change la ligne du curseur sans changer la colonne
	void ChangerLigneCurseur(uint8_t line);

	// change la colonne du curseur sans changer la ligne
	void ChangerColonneCurseur(uint8_t row);

	// affiche le texte à la position donnée
	void EcrireEnPosition(Coordonne position, string texte);

	// affiche le nombre à la position donnée
	void EcrireNbEnPosition(Coordonne position, uint8_t nb);

	// dessine un cadre à partir des coordonnées des points haut-gauche
	// et bas-droite, du type de bordure, de la couleur de trait et de
	// la couleur de fond
	void DessinerCadreXY(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, bool bordureDouble = false, ECouleur coulTrait = ECouleur(15), ECouleur coulFond = ECouleur(0));

	void DessinerCadre(Coordonne x, Coordonne y, bool bordureDouble = false, ECouleur coulTrait = ECouleur(15), ECouleur coulFond = ECouleur(0));

	// attends le nombre de ms indiqué
	void Attendre(uint16_t temps);

	// change la couleur de fond actuelle
	void CouleurFond(ECouleur couleur);

	// change la couleur de texte actuelle
	void CouleurTexte(ECouleur couleur);

	// change la couleur de texte et de fond
	void Couleurs(ECouleur couleurTexte, ECouleur couleurFond);

	// renvoie les caractere saisie par l'utilisateur
	string RetourSaisi();

public:
	Window();
	~Window();
};

