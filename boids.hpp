#ifndef _BOIDS_HPP_
#define _BOIDS_HPP_

#include "oiseau.hpp"


/* Problème de dépendance circulaire entre les fichiers proies.hpp et predateur.hpp donc on les met ensemble dans le fichier boids */
class Proies : public Oiseau{
    public:
        Proies();
        Proies(Vecteur position, Vecteur vitesse, double f_max, double v_max);
        /* On met Oiseau a la place de proies et predateur car c'est la classe mère donc on peut les remplacer et faire un cast (Proies) pour manipuler nos objets */
        Vecteur getForce(Oiseau* predateurs, Oiseau* proies, int np, int nb, double da, double ds, double res);
        void setPosition(Vecteur position);
};

class Predateur : public Oiseau{
    public:
        Predateur();
        Predateur(Vecteur position, Vecteur vitesse, double f_max, double v_max);
        Vecteur getForce(Oiseau* predateurs, Oiseau* proies, int np, int nb, double da, double ds, double res);
};

#endif

