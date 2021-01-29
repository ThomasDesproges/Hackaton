#include "item.h"
#include "class_character.h"


Item::Item(int x,int y,bool IC,char symbol):symbol(symbol){
        pos[0]=x;
        pos[1]=y;
        inventory_compatible=IC;
    }

int* Item::position(){
        return(pos);
    }




Gold::Gold(int x,int y,int value):Item(x,y,false,'o'),value(value){
}

Potion::Potion(int x, int y):Item(x,y,true,'&'){}

void Potion::assign(Character* charac){carrier=charac;}