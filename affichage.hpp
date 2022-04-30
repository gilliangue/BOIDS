#ifndef _AFFICHAGE_HPP_
#define _AFFICHAGE_HPP_

#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include "vecteur.hpp"

class Fenetre{

    public:
        Fenetre(int largeur, int hauteur);
        bool etatFenetre();
        void clearFenetre();
        void dessinerFenetre(Vecteur position, Vecteur vitesse, int espece);
        void afficherFenetre();

    private:
        sf::RenderWindow window;
    

};

#endif