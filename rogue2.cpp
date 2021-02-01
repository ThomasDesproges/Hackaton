#include <iostream>
#include <string>
#include <vector>
#include <ncurses.h>

#include "message.h"
#include "generateur_salle_v2.h"
#include "generateur_niveau_v1.h"
#include "class_character.cpp"
#include "item.cpp"
#include "search_item.h"



// LES TOUCHES DE DÉPLACEMENT
// ==========================
// On décide des 4 touches pour déplacer le héro (ici les 4 flèches en
// bas et à droite de votre clavier)
constexpr int left_arrow = 4;
constexpr int right_arrow = 5;
constexpr int top_arrow = 3;
constexpr int bottom_arrow = 2;
// On crée (ici par une énumération) un ensemble des 4 directions de
// déplacement.
enum DIRECTION {
	LEFT = left_arrow,
	RIGHT = right_arrow,
	TOP = top_arrow,
	BOTTOM = bottom_arrow,
};

constexpr int left_arrow2 = 'd';
constexpr int right_arrow2 = 'g';
constexpr int top_arrow2 = 'r';
constexpr int bottom_arrow2 = 'f';

enum DIRECTION2 {
	d = left_arrow2,
	g = right_arrow2,
	r = top_arrow2,
	f = bottom_arrow2,
};


// LE HÉRO
// =======

// la position du '@' qui est aussi la position du curseur de votre terminal
int xcursor = 3; // ligne
int ycursor = 4; // colonne

// J'essaie d'implémanter le code de Thomas
int pv1 = 100 ;
int pv2 = 100 ;
char commands1[4] = {TOP, RIGHT, BOTTOM, LEFT} ;
char commands2[4] = {r, g, f, d} ;
std::vector<Item*> p_liste_items [100];
Character Hero1(xcursor, ycursor, pv1, commands1,p_liste_items) ;
Character Hero2(xcursor+2, ycursor+2, pv2, commands2,p_liste_items) ;



// INITIALISATION DU TERMINAL
// ==========================
void init () {
    // on initialise le terminal en mode curses
    initscr();
    
    clear();
    // on efface le stdscr (le terminal, the standard screen)

    // Comme nous allons taper des caractères pour les commandes du
    // héro, on ne veut pas qu'ils s'affichent (i.e. qu'ils aient un
    // écho sur le standard screen. noecho() switchs off echoing
    noecho();  

    // Par défaut, les caractères entrés sont stockés dans une mémoire
    // tampon (buffer) jusqu'au prochain retour à la ligne (enter). Pour
    // obtenir les caractères dès que nous les tapons, nous devons
    // désactiver la mise en mémoire tampon de la ligne.
    // Nous passons en mode brut (raw), cela empêche les
    // caractères de contrôle (CTRL-C) de générer leur signal (genre
    // tuer l'exécutable). Donc vous ne pouvez pas quitter le programme
    // avec CTRL-C ni le suspendre avec CTRL-Z.
    cbreak(); // or raw();

    // On active les clés F1, F2... et les flêches (puisqu'on veut
    // déplacer notre héro avec).
    keypad(stdscr, TRUE);
    refresh();

    int limite_right ;
    int limite_bottom ;
    getmaxyx(stdscr,limite_bottom, limite_right);
    limite_bottom=limite_bottom-1;
    limite_right=limite_right-1;
    // room piece(1,limite_bottom,1,limite_right);
    // piece.display();
    level niveau ;
    niveau.generate() ;
}

bool is_direction1 (char c) {
    return ((c == LEFT) or (c == RIGHT) or (c == BOTTOM) or (c == TOP));
}

bool is_direction2 (char c) {
    return ((c == d) or (c == g) or (c == f) or (c == r));
}

void play () {
    // On initialise le terminal en ncurses.
    init();

    // On affiche les items :
    Gold gold(5,7,10) ;
    gold.affiche();

    Gold gold2(15,21,10) ;
    gold2.affiche();

    Potion pot1(20,12) ;
    pot1.affiche();

    (*p_liste_items).push_back(&gold);
    (*p_liste_items).push_back(&gold2);
    (*p_liste_items).push_back(&pot1);

    // On affiche le héro.
    Hero1.affiche();
    Hero2.affiche();

    std::string str = "Welcome brave hero!";
    const char* cstr = str.c_str() ;
    message msg (cstr) ;
    msg.print() ;

    char c = '\0';
    // On entre dans une boucle sans fin sauf si le caractère 'q' est
    // entré.
    while (c != 'q') {
        // On récupère le caractère tapé.
        c = getch();
        if (is_direction1(c)) {
            // Si le caractère est une direction en bouge le héro.
            Hero1.movement(c);
        }
        if (is_direction2(c)) {
            // Si le caractère est une direction en bouge le héro.
            Hero2.movement(c);
        }
    }
    // Vous devez terminer curses proprement sinon votre terminal sera
    // dans un état tout bizarre...
    endwin();
}

int main () {
  play();
  return 0;
}