#include<iostream>

#pragma once




class Character{
    public :
    Character(int position_x,int position_y, int point_de_vie, char* controls) : position_x(position_x),position_y(position_y),PV(point_de_vie), controls(controls) {
    }

    void move(char entree){ 
        //Méthode permettant de déplacer le personnage d'une case suivant la commande d'entrée.
        //La méthode déplace le personnage si cela est possible. N'attaque
        //on tourne dans le sens horaire, on commence en haut.
        if (entree == controls[0]){
            if (movement_possible(controls[0])){
                move_up();
            }    
        }
        if (entree == controls[1]){
            if (movement_possible()){
                move_right();
            }
        }
        if (entree == controls[2]){
            if (movement_possible()){
                move_down();
            }
        }
        if (entree == controls[3]){
            if (movement_possible()){
                move_left();
            }
        }
        return;
    }

    bool movement_possible(char entree){
        if (){
            return true;
        }
        else{
            return false;
        }
    }

    void move_up(){
        position_y++;
    }

    void move_right(){
        position_x++;
    }

    void move_down(){
        position_y--;
    }

    void move_left(){
        position_x--;
    }

    void add_gold(int amount_of_gold){
        bourse += amount_of_gold;
    }

    void affiche_caracteristiques_heros(){

    }

    void add_PV(int amount){
        PV += amount;
    }

    private : 
    int position_x,position_y;
    int PV;
    int bourse;
    Item* inventaire;
    char* controls;

};