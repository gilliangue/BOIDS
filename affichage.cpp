#include "affichage.hpp"

Fenetre::Fenetre(int largeur, int hauteur){
    this->window.create(sf::VideoMode(largeur, hauteur), "Simulation BOIDS!");
    this->window.setVerticalSyncEnabled(true);
}

bool Fenetre::etatFenetre(){
    sf::Event event;
    if(this->window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            this->window.close();
        }
    }

    return this->window.isOpen();
}

void Fenetre::clearFenetre(){
    this->window.clear(sf::Color::Black);
}

void Fenetre::afficherFenetre(){
    this->window.display();
}

void Fenetre::dessinerFenetre(Vecteur position, Vecteur vitesse, int espece){
    int p1x = floor(position[0]);
    int p1y = floor(position[1]);
    Vecteur v = vitesse;
    if(v.norme() != 0){
        v = v *(1/v.norme());
    }
    v = v * 2;
    int p2x = p1x + floor(v[0]);
    int p2y = p1y + floor(v[1]);
    
    sf::VertexArray lines(sf::LinesStrip, 2);
    lines[0].position = sf::Vector2f(200 + p1x, 200 + p1y);
    lines[1].position = sf::Vector2f(200 + p2x, 200 + p2y);
    if(espece == 0){
        lines[0].color  = sf::Color::Blue;
        lines[1].color = sf::Color::Blue;
    }else{
        lines[0].color  = sf::Color::Red;
        lines[1].color = sf::Color::Red;
    }
    this->window.draw(lines);

}