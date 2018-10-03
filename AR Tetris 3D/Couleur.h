#pragma once
class Couleur
{
private:
	// couleur r, v et b
	float red;
	float green;
	float blue;

public:
	// Getters
	float GetRed();
	float GetGreen();
	float GetBlue();
	void  GetColor(float *color);

	// Setters

	void SetRed(float r);
	void SetGreen(float g);
	void SetBlue(float b);
	void SetColor(float *color);

	Couleur();
	Couleur(float r, float g, float b);
	~Couleur();
};

