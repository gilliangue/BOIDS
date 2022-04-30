#include "boids.hpp"

Proies::Proies()
: Oiseau()
{}
Predateur::Predateur()
: Oiseau()
{}

Proies::Proies(Vecteur position, Vecteur vitesse, double f_max, double v_max)
    : Oiseau(position,vitesse,f_max,v_max)
{}
Predateur::Predateur(Vecteur position, Vecteur vitesse, double f_max, double v_max)
    : Oiseau(position,vitesse,f_max,v_max)
{}

Vecteur Proies::getForce(Oiseau* predateurs, Oiseau* proies, int np, int nb, double da, double ds, double res){
    
    Vecteur f_a; 
    Vecteur f_s;
    Vecteur f_c;
    int nb_voisins_da = 0;
    for(int i = 0; i < nb; i++){
        /* Calcule de la force d'alignement */
        if(this->getDist(proies[i]) < da && this->getDist(proies[i]) != 0){
            f_a = f_a + (proies[i].getVitesse());
            nb_voisins_da++;
        }
        /* Calcule de la force de séparation */
        if(this->getDist(proies[i]) < ds && this->getDist(proies[i]) != 0){
            f_s = f_s + (this->getPosition() - proies[i].getPosition())*(1/this->getDist(proies[i]));
        }
        if (this->getDist(proies[i]) < da && this->getDist(proies[i]) != 0)
        {
            f_c = f_c + proies[i].getPosition();
        }
    }
    if(nb_voisins_da != 0){
        f_a = f_a*(1/nb_voisins_da);
    }
    if(f_a.norme()!=0){
        f_a = f_a * (1/f_a.norme());
    }
    f_a = f_a * this->getVmax();
    f_a = f_a - this->getVitesse();
    if(f_a.norme()> this->getFmax()){
        f_a = f_a * (1/f_a.norme());
        f_a = f_a * this->getFmax();
    }

    
    //normalisation 
    if(f_s.norme() != 0){
        f_s = f_s * (1/f_s.norme());
    }
    f_s = f_s * this->getVmax();
    f_s = f_s - this->getVitesse();
    if(f_s.norme()> this->getFmax()){
        f_s = f_s * (1/f_s.norme());
        f_s = f_s * this->getFmax();
    }

    //force de cohésion 
   
    nb_voisins_da = 0;
    for (int i = 0; i < nb; i++)
    {
        
    }
    if(nb_voisins_da != 0){
        f_c = (f_c*(1/nb_voisins_da) - this->getPosition())* (1/res);
    }

    //normalisation 
    if(f_c.norme() != 0){
        f_c = f_c * (1/f_c.norme());
    }
    f_c = f_c * this->getVmax();
    f_c = f_c - this->getVitesse();
    if(f_c.norme()> this->getFmax()){
        f_c = f_c * (1/f_c.norme());
        f_c = f_c * this->getFmax();
    }


    // force de dispersion 
    Vecteur f_d; 
    for (int i = 0; i < np; i++)
    {
        if (this->getDist(predateurs[i]) < da && this->getDist(predateurs[i]) !=0)
        {
            f_d = f_d + (1/(this->getDist(predateurs[i]))*(this->getDist(predateurs[i]))) * (this->getPosition() - predateurs[i].getPosition());
        }
    }

    //normalisation 
    if(f_d.norme() != 0){
        f_d = f_d * (1/f_d.norme());
    }
    f_d = f_d * this->getVmax();
    f_d = f_d - this->getVitesse();
    if(f_d.norme()> this->getFmax()){
        f_d = f_d * (1/f_d.norme());
        f_d = f_d * this->getFmax();
    }

    // force totale 

    
    Vecteur f_tot = f_a + 3*((f_s + f_d)*(1/4)) + f_c;
    
    this->setForce(f_tot);
    return f_tot; 
}


Vecteur Predateur::getForce(Oiseau* predateurs, Oiseau* proies, int np, int nb, double da, double ds, double res){
    /* Calcule de la force d'attraction */
    Vecteur f_a;
    for(int i = 0; i < nb; i++){
        if(this->getDist(proies[i])){
            double dist = this->getDist(proies[i]);
            f_a = f_a + (proies[i].getPosition() - this->getPosition())* (1/(dist*dist));
        }
    }
    f_a = f_a * (1/f_a.norme());
    f_a = f_a * this->getVmax();
    f_a = f_a - this->getVitesse();
    if(f_a.norme()> this->getFmax()){
        f_a = f_a * (1/f_a.norme());
        f_a = f_a * this->getFmax();
    }

    /* Calcule de la force de répulsion */
    Vecteur f_r;
    for(int i = 0; i<np; i++){
        if(this->getDist(predateurs[i])){
            double dist = this->getDist(predateurs[i]);
            f_r = f_r + (this->getPosition() - predateurs[i].getPosition()) * (1/dist);
        }
    }
    f_r = f_r * (1/f_r.norme());
    f_r = f_r * this->getVmax();
    f_r = f_r - this->getVitesse();
    if(f_r.norme()> this->getFmax()){
        f_r = f_r * (1/f_r.norme());
        f_r = f_r * this->getFmax();
    }

    Vecteur f_tot = f_r + f_a;
    this->setForce(f_tot);
    
    return f_tot; 
}   
    