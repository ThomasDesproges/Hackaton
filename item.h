#pragma once
#include "class_character.h"
// Classe générale Item

class Item {
    public :

    bool inventory_compatible;
    char symbol;
    int* position();
    virtual void do_effect()=0;

    protected :

    Item(int x,int y,bool IC,char symbol);

    private :

    int pos [2];

};

// Classe fille Gold

class Gold : public Item {
    public :
    void do_effect();
    int value;
    Gold(int x,int y,int value);

    private :

};

// Classe potion 


class Potion : public Item {
    public:

    Potion(int x, int y);
    void assign(Character* charac);
    int HP_to_add=5;
    void do_effect();
    private:
    Character* carrier;
};
