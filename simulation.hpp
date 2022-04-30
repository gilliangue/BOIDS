#ifndef _SIMULATION_HPP_
#define _SIMULATION_HPP_

#include "affichage.hpp"
#include "boids.hpp"
#include "oiseau.hpp"

/* On pourra remplacer les proies et les prédateurs par d'autres classes qui possèdent les même propritétés */
/* On précise les valeurs par défaut des paramètres de la simulation */
template<class Pro, class Pre, int nombre_proies = 256, int nombre_preda = 8>
class Simulation{
    Pro proies[nombre_proies];
    Pre predateurs[nombre_preda];
    int nb = nombre_proies;
    int np = nombre_preda;
    double v_max;
    double f_max;
    double da;
    double ds;
    double res;

    public:
        Simulation(double v_max = 2, double f_max = 0.05, double da = 25, double ds = 20, double res = 1)
        : v_max(v_max), f_max(f_max), da(da), ds(ds), res(res)
        {
            for(int i = 0 ; i < nb ; i++){
                proies[i].setFmax(f_max);
                proies[i].setVmax(v_max);
            }

            for(int i = 0 ; i < np ; i++){
                predateurs[i].setFmax(f_max);
                predateurs[i].setVmax(v_max);
            }
        }
        void start(int largeur, int hauteur){
            Fenetre fenetre(largeur,hauteur);
            while(fenetre.etatFenetre()){
                for(int i = 0; i < nb ; i++){
                    proies[i].getForce(predateurs,proies,np,nb,da,ds,res);
                    
                }
                for(int i = 0; i < np ; i++){
                   predateurs[i].getForce(predateurs,proies,np,nb,da,ds,res);
                }
                fenetre.clearFenetre();
                for(int i = 0; i < nb ; i++){
                    proies[i].update(largeur/2, hauteur/2);
                    fenetre.dessinerFenetre(proies[i].getPosition(),proies[i].getVitesse(),0);
                }
                for(int i = 0; i < np ; i++){
                    predateurs[i].update(largeur/2, hauteur/2);
                    fenetre.dessinerFenetre(predateurs[i].getPosition(),predateurs[i].getVitesse(),1);
                }
                fenetre.afficherFenetre();


            }
        }
        
};


#endif