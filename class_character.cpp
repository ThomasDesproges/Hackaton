#include<iostream>
#include<ncurses.h>
#include"item.h"

#pragma once

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
    int i_up,i_right,i_down,i_left;
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
    int ch = mvwinch(stdscr,position_y+i_up-i_down,position_x+i_right-i_left);
    if ((ch = ERR) or (ch=' ')){
        return true;
    }
    else{
        return false;
    }
}

void Character::move_up(){
    wmove(stdscr,position_y,position_x);
    addch(' ');
    wmove(stdscr,position_y+1,position_x);
    addch('@');
    position_y++;
}

void Character::move_right(){
    position_x++;
}

void Character::move_down(){
    position_y--;
}

void Character::move_left(){
    position_x--;
}

void Character::add_gold(int amount_of_gold){
    bourse += amount_of_gold;
}

void Character::affiche_caracteristiques_heros(){

}

void Character::add_PV(int amount){
    PV += amount;
}


class Monster{
public :
Monster(int PV, char symbol) : {}


};

