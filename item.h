#pragma once


class Character;

// Classe générale Item

class Item {
    friend class Gold;
    friend class Potion;
    public :

    bool inventory_compatible;
    char symbol;
    int* position();
    void assign(Character* charac);
    virtual void do_effect()=0;
    void affiche();
    bool is(int a, int b);

    protected :

    Item(int x,int y,bool IC,char symbol);

    private :
    Character* carrier;
    int pos [2];

};

// Classe fille Gold

class Gold : public Item {
    public :
    void do_effect();
    int coin_value;
    Gold(int x,int y,int coin_value);

    private :

};

// Classe potion 


class Potion : public Item {
    public:

    Potion(int x, int y);
    int HP_to_add=5;
    void do_effect();
    private:

};
