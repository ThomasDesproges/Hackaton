#pragma once
#include <iostream>
#include <string>
#include <ncurses.h>

class playground { //delimite l'espace de jeu
public:
	playground(){
		int limite_right;
		int limite_bottom;
	
		getmaxyx(stdscr, limite_bottom , limite_right);
		right= limite_right-1;
		bottom = limite_bottom-1;
		left=1;
		top=1;

	}


int left;//x_min
int right;//x_max
int top;//y_min
int bottom;//y_max


};

class room {
public:

room(int x_min, int x_max, int y_min, int y_max): x_min(x_min), x_max(x_max), y_min(y_min), y_max(y_max) {}

void display(){//afficher la salle on utilise | pour les murs verticaux, _ pour les murs horizontaux
	for(int i=x_min; i<x_max; ++i){
		move(i,y_min);
		addch('|');
		move(i,y_max);
		addch('|');
		refresh();
	}
	for (int j=y_min; j<y_max+1;++j){
		move(x_min,j);
		addch('-');
		move(x_max,j);
		addch('-');
		refresh();
	}


}




private:
const int x_min;
const int x_max;
const int y_min;
const int y_max;





};