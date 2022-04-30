#ifndef _OISEAU_HPP_
#define _OISEAU_HPP_

#include "vecteur.hpp"
#include <cmath>
#include <cstdlib>
#include <iostream>

class Oiseau{
	public:
		Oiseau();
		Oiseau(Vecteur position, Vecteur vitesse, double f_max, double v_max);
		Vecteur getPosition();
		Vecteur getVitesse();
		double getVmax();
		double getFmax();
		double getDist(Oiseau o);
		double getForce();
		void setFmax(double f_max);
		void setVmax(double v_max);
		void setForce(Vecteur force);
		void update(int largeur, int hauteur);
	private: // En privé, les classes filles ne peuvent pas y accéder par exemple this->v_max (il faudrait mettre en protected)
		Vecteur position;
		Vecteur vitesse;
		Vecteur force;
		double f_max;
		double v_max;

};
#endif