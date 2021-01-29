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

void Item::assign(Character* charac){
    carrier=charac;
}

bool Item::is(int a, int b){ // permet de regarder si cet item est celui aux coordonées (a,b)
    return((a==pos[0] and b== pos[1]));
}

Gold::Gold(int x,int y,int coin_value):Item(x,y,false,'o'),coin_value(coin_value){
}

void Gold::do_effect(){ // ajoute l'argent au porteur
    if (carrier!=nullptr){
        (*carrier).add_gold(coin_value);
    }

}


Potion::Potion(int x, int y):Item(x,y,true,'&'){   
}



void Potion::do_effect(){  // ajoute les PV au porteur
    if (carrier!=nullptr){
            (*carrier).add_PV(HP_to_add);
        }
}