#include <iostream>
#include <ncurses.h>
#include "class_character.h"
#include "item.h"

Character::Character(int position_x,int position_y, int point_de_vie, char controls[4],std::vector<Item*>* p_liste_items) : position_x(position_x),position_y(position_y),PV(point_de_vie), controls(controls), p_liste_items(p_liste_items) {
remettre_la_porte = false;
}

void Character::affiche(){
    wmove(stdscr,position_y,position_x);
    addch('@');
}

void Character::movement(char entree){ 
    //Méthode permettant de déplacer le personnage d'une case suivant la commande d'entrée.
    //La méthode déplace le personnage si cela est possible.
    //on tourne dans le sens horaire, on commence en haut.
    int dx = 0 ;
    int dy = 0 ;
    if (entree == controls[0]){ // TOP
        dy = -1;
    }
    else if (entree == controls[1]){ // RIGHT
        dx = 1;
    }
    else if (entree == controls[2]){ // BOTTOM
        dy = 1;
    }
    else if (entree == controls[3]){ // LEFT
        dx = -1;
    }
    switch (mvwinch(stdscr,position_y+dy,position_x+dx)){
        // case 'o' :
        //     wmove(stdscr,position_y,position_x);
        //     addch(' ');
        //     wmove(stdscr,position_y+dy,position_x+dx);
        //     addch('@');
        //     position_x = position_x+dx;
        //     position_y = position_y+dy;
        //     if (remettre_la_porte){
        //         wmove(stdscr,position_y-dy,position_x-dx);
        //         addch('+');
        //         remettre_la_porte = false;
        //     }
        //     add_PV(10);
        //    break;
        case '|' :
            break;
        case '-' :
            break;
        case '+' :
            wmove(stdscr,position_y,position_x);
            addch(' ');
            wmove(stdscr,position_y+dy,position_x+dx);
            addch('@');
            position_x = position_x+dx;
            position_y = position_y+dy;
            if (remettre_la_porte){
                wmove(stdscr,position_y-dy,position_x-dx);
                addch('+');
                remettre_la_porte = false;
            }
            remettre_la_porte = true;
            break;
        default :
            Item* p_item = search_item(p_liste_items,position_y+dy,position_x+dx);
            if (p_item != nullptr){
                (*p_item).assign(this);
                (*p_item).do_effect();
            }
            wmove(stdscr,position_y,position_x);
            addch(' ');
            wmove(stdscr,position_y+dy,position_x+dx);
            addch('@');
            position_x = position_x+dx;
            position_y = position_y+dy;
            if (remettre_la_porte){
                wmove(stdscr,position_y-dy,position_x-dx);
                addch('+');
                remettre_la_porte = false;
            }
            affiche_caracteristiques_heros();
    }
    return;
}


void Character::add_gold(int amount_of_gold){
    bourse += amount_of_gold;
}

void Character::affiche_caracteristiques_heros(){
    std::string str_1 = std::to_string(PV);
    std::string str_2 = std::to_string(bourse);
    std::string str = "PV : " + str_1 + " Or :" + str_2;
    const char* cstr = str.c_str() ;
    message msg (cstr) ;
    msg.print();
}

void Character::add_PV(int amount){
    PV += amount;
}

void Character::assault(){
    
}

