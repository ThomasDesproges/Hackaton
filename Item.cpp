#include "Item.h"


int* Item::position(){
        return(pos);
    }

Item::Item(int x,int y,bool IC,char symbol):symbol(symbol){
        pos[0]=x;
        pos[1]=y;
        inventory_compatible=IC;
    }



Gold::Gold(int x,int y,int value):Item(x,y,false,'o'),value(value){
}
