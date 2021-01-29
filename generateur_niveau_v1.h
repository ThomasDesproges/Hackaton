#pragma once
#include <iostream>
#include <string>
#include <ncurses.h>
#include "generateur_salle_v2.h"

class level {
	public:
	level(){
		int limite_bottom;
		int limite_right;
		getmaxyx(stdscr, limite_bottom , limite_right);
		x_max = limite_bottom -1;
		y_max = limite_right -1;
		x_min=1;
		y_min=1;
	}
	
	void add_room(int rx_min, int rx_max, int ry_min, int ry_max){//ajoute une piece au niveau
		room piece(rx_min, rx_max, ry_min, ry_max);
		piece.display();
	}
	
	void add_h_corridor(int cx_min, int cy_min, int cy_max){//ajoute un corridor horizontal
		h_corridor couloir(cx_min,cy_min, cy_max);
		couloir.display();
	}
	
	void add_v_corridor(int cx_min,int cx_max, int cy_min){//ajoute un corridor vertical
		v_corridor couloir(cx_min,cx_max,cy_min);
		couloir.display();
	}
	
	void generate(){//genere le niveau
		int dixieme_x = x_max /10;
		int vingtieme_x = x_max/20;
		int dixieme_y = y_max/10;
		int vingtieme_y = y_max/20;
	
		add_room(dixieme_x,3*dixieme_x, 1, 2*dixieme_y);
		add_room(4*dixieme_x, 8*dixieme_x, 1, 2*dixieme_y);
		add_room(9*dixieme_x, x_max , 3*dixieme_y, 5*dixieme_y);
		add_room(5*dixieme_x,8*dixieme_x,3*dixieme_y,5*dixieme_y);
		add_room(dixieme_x,2*dixieme_x,4*dixieme_y,9*dixieme_y);
		add_room(3*dixieme_x,5*dixieme_x,6*dixieme_y,9*dixieme_y);
		add_room(6*dixieme_x,9*dixieme_x,6*dixieme_y,9*dixieme_y);
		add_room(1, x_max,1,y_max);
	
		add_h_corridor(3*vingtieme_x,2*dixieme_y,4*dixieme_y);
		add_v_corridor(3*dixieme_x,4*dixieme_x,dixieme_y);
		add_h_corridor(7*dixieme_x,2*dixieme_y,3*dixieme_y);
		add_v_corridor(2*dixieme_x,3*dixieme_x,7*dixieme_y);
		add_v_corridor(5*dixieme_x,6*dixieme_x,7*dixieme_y);
		add_v_corridor(8*dixieme_x,9*dixieme_x,4*dixieme_y);
		add_h_corridor(7*dixieme_x,5*dixieme_y,6*dixieme_y);
	
	}
	
	
	int x_min;
	int x_max;
	int y_min;
	int y_max;

};