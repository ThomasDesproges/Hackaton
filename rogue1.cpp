#include <iostream>
#include <string>
#include <ncurses.h>

#include "message.h"
#include "generateur_salle_v2.h"
#include "generateur_niveau_v1.h"
#include "class_character.cpp"
#include "item.cpp"



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


// LE HÉRO
// =======

// la position du '@' qui est aussi la position du curseur de votre terminal
int xcursor = 3; // ligne
int ycursor = 4; // colonne

// J'essaie d'implémanter le code de Thomas
int pv = 100 ;
char commands[4] = {TOP, RIGHT, BOTTOM, LEFT} ;
Character Hero(xcursor, ycursor, pv, commands) ;


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

bool is_direction (char c) {
    return ((c == LEFT) or (c == RIGHT) or (c == BOTTOM) or (c == TOP));
}

void play () {
    // On initialise le terminal en ncurses.
    init();

    // On affiche les items :
    Gold gold(5,7,10) ;
    gold.affiche();

    // On affiche le héro.
    Hero.affiche();
    
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
        if (is_direction(c)) {
            // Si le caractère est une direction en bouge le héro.
            Hero.movement(c);
        }
        // else {
        //     // Et là le caractère peut être des tas d'autres choses !
        //     // monstres qu'il faut combattre, objet magique qu'il faut
        //     // ramasser etc.
        //     print_char_error_message(c);
        // }
    }
    // Vous devez terminer curses proprement sinon votre terminal sera
    // dans un état tout bizarre...
    endwin();
}

int main () {
  play();
  return 0;
}