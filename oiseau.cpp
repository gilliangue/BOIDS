#include "oiseau.hpp"

Oiseau::Oiseau(){
    int x1 = std::rand()%3 - 1;
    int y1 = std::rand()%3 - 1;
    int x2 = std::rand()%3 - 1;
    int y2 = std::rand()%3 - 1;
    Vecteur pos(x1,y2);
    Vecteur vit(x2,y2);
    this->position = pos;
    this->vitesse = vit;
}

Oiseau::Oiseau(Vecteur position, Vecteur vitesse, double f_max, double v_max)
    : position(position), vitesse(vitesse),f_max(f_max), v_max(v_max)
{}

Vecteur Oiseau::getPosition(){
    return this->position;
}

Vecteur Oiseau::getVitesse(){
    return this->vitesse;
}
double Oiseau::getVmax(){
    return this->v_max;
}
double Oiseau::getFmax(){
    return this->f_max;
}

double Oiseau::getDist(Oiseau o){
    Vecteur w = this->position - o.getPosition();
    return sqrt(w[0]*w[0] + w[1]*w[1]);
}

void Oiseau::setFmax(double f_max){
    this->f_max = f_max;
}

void Oiseau::setVmax(double v_max){
    this->v_max = v_max;
}

void Oiseau::setForce(Vecteur force){
    this->force = force;
}

void Oiseau::update(int largeur, int hauteur){
    this->vitesse = this->vitesse + this->force;
    if(this->vitesse.norme() > this->v_max && this->vitesse.norme() != 0){
        this->vitesse = this->vitesse * (1/this->vitesse.norme());
        this->vitesse = this->vitesse * this->v_max;
    }
    
    this->position = this->position + this->vitesse;
    if(this->position[0] >= largeur){
        this->position[0] = -largeur + (this->position[0] - largeur);
    }
    if(this->position[1] >= hauteur){
        this->position[1] = -hauteur + (this->position[1] - hauteur);
    }
    if(this->position[0] <= -largeur){
        this->position[0] = largeur + (this->position[0] + largeur);
    }
    if(this->position[1] <= -hauteur){
        this->position[1] = hauteur + (this->position[1] + hauteur);
    }
    
}
