#include <iostream>
#include <ctime>

#include "vecteur.hpp"
#include "boids.hpp"
#include "simulation.hpp"
#include "affichage.hpp"

int main(){
	Simulation<Proies,Predateur, 256, 10> s(2,0.05,25,20,1);
	s.start(400,400);

	return 0;
}