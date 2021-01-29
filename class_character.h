#pragma once

#include<iostream>
#include<ncurses.h>

class Item;

class Character{
    public :
    Character(int position_x,int position_y, int point_de_vie, char controls[4]);

    void affiche();

    void movement(char entree);

    bool movement_possible(char entree);

    void move_up();
    
    void move_right();

    void move_down();

    void move_left();

    void add_gold(int amount_of_gold);

    void affiche_caracteristiques_heros();

    void add_PV(int amount);

    private : 
    int position_x,position_y;
    int PV;
    int bourse;
    Item* inventaire[5];
    char* controls;
    bool remettre_la_porte;

};
