#pragma once
#include "class_character.h"
// Classe générale Item


class Item {
    public :

    Item(int x,int y,bool IC,char symbol);
    bool inventory_compatible;
    char symbol;
    int* position();

    protected :


    private :

    int pos [2];

};

// Classe fille Gold

class Gold : public Item {
    public :

    int value;
    Gold(int x,int y,int value);

    private :

};

// Classe fille Potion

class Potion : public Item {
    public:

    Potion(int x,int y);
    void assign(Character* charac);
    int HP_to_add = 5;
    private:
    Character* carrier;
    
};
