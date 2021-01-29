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
    //La méthode déplace le personnage si cela est possible. N'attaque
    //on tourne dans le sens horaire, on commence en haut.
    if (entree == controls[0]){
        if (movement_possible(controls[0])){
            move_up();
        }    
    }
    if (entree == controls[1]){
        if (movement_possible(controls[1])){
            move_right();
        }
    }
    if (entree == controls[2]){
        if (movement_possible(controls[2])){
            move_down();
        }
    }
    if (entree == controls[3]){
        if (movement_possible(controls[3])){
            move_left();
        }
    }
    return;
}

bool Character::movement_possible(char entree){
    int i_up,i_right,i_down,i_left = 0;0;0;0;
    if (entree == controls[0]){
        i_up = 1;
    }
    if (entree == controls[1]){
        i_right = 1;
    }
    if (entree == controls[2]){
        i_down = 1;
    }
    if (entree == controls[3]){
        i_left = 1;
    }
    int ch = mvwinch(stdscr,position_y+i_down-i_up,position_x+i_right-i_left);
    if ((ch=='|')or(ch=='-')){
        return false;
    }
    else{
        return true;
    }
    wmove(stdscr, 5,5);
    addch(ch);
}

void Character::move_up(){
    wmove(stdscr,position_y,position_x);
    addch(' ');
    wmove(stdscr,position_y-1,position_x);
    addch('@');
    position_y--;
}

void Character::move_right(){
    wmove(stdscr,position_y,position_x);
    addch(' ');
    wmove(stdscr,position_y,position_x+1);
    addch('@');
    position_y++;
}

void Character::move_down(){
    wmove(stdscr,position_y,position_x);
    addch(' ');
    wmove(stdscr,position_y++,position_x);
    addch('@');
    position_y++;
}

void Character::move_left(){
    wmove(stdscr,position_y,position_x);
    addch(' ');
    wmove(stdscr,position_y,position_x-1);
    addch('@');
    position_y--;
}

void Character::add_gold(int amount_of_gold){
    bourse += amount_of_gold;
}

void Character::affiche_caracteristiques_heros(){

}

void Character::add_PV(int amount){
    PV += amount;
}

