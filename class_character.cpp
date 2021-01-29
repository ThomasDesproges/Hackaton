#include <iostream>
#include <ncurses.h>
#include "class_character.h"


Character::Character(int position_x,int position_y, int point_de_vie, char controls[4]) : position_x(position_x),position_y(position_y),PV(point_de_vie), controls(controls) {
}

void Character::affiche(){
    wmove(stdscr,position_y,position_x);
    addch('@');
}

void Character::movement(char entree){ 
    //Méthode permettant de déplacer le personnage d'une case suivant la commande d'entrée.
    //La méthode déplace le personnage si cela est possible.
    //on tourne dans le sens horaire, on commence en haut.
    int dx,dy = 0;0;
    if (entree == controls[0]){
        dy = -1;
    }
    if (entree == controls[1]){
        dx = 1;
    }
    if (entree == controls[2]){
        dy = 1;
    }
    if (entree == controls[3]){
        dx = -1;
    }
    if ((mvwinch(stdscr,position_y+dy,position_x+dx) != '|') and (mvwinch(stdscr,position_y+dy,position_x+dx) != '-')){
        wmove(stdscr,position_y,position_x);
        addch(' ');
        wmove(stdscr,position_y+dy,position_x+dx);
        addch('@');
        position_x = position_x+dx;
        position_y = position_y+dy;
        wmove(stdscr,position_y+5,position_x+5);
        addch('y');
        wmove(stdscr,position_y+5,position_x+6);
        addch(mvwinch(stdscr,position_y+dy,position_x+dx));
    }
    return;
}


void Character::add_gold(int amount_of_gold){
    bourse += amount_of_gold;
}

void Character::affiche_caracteristiques_heros(){

}

void Character::add_PV(int amount){
    PV += amount;
}

