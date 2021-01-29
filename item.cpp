#include "item.h"
#include <ncurses.h>

int* Item::position(){
        return(pos);
    }

Item::Item(int x,int y,bool IC,char symbol):symbol(symbol){
        pos[0]=x;
        pos[1]=y;
        inventory_compatible=IC;
}

void Item::affiche(){
    wmove(stdscr,pos[0],pos[1]);
    addch(symbol);
}

Gold::Gold(int x,int y,int value):Item(x,y,false,'o'),value(value){
}

void Gold::do_effect(){}


Potion::Potion(int x, int y):Item(x,y,true,'&'){   
}

void Potion::assign(Character* charac){
    carrier=charac;}

void Potion::do_effect(){  
    if (carrier!=nullptr){
            (*carrier).add_PV(HP_to_add);
        }
}