#pragma once

// Classe générale Item
class Character;

class Item {
    public :

    bool inventory_compatible;
    char symbol;
    int* position();

    protected :

    Item(int x,int y,bool IC,char symbol);

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
/*
class Potion : public Item {
    public:


    private:
    
};

*/