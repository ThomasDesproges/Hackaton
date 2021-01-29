#pragma once
#include <iostream>
#include <string>
#include <ncurses.h>





class message {
	public:
	message(const char* contenu): contenu(contenu), x_msg(0),y_msg(0) {
		
		int limit_bottom;
		int limit_right;
		getmaxyx(stdscr,limit_right,limit_bottom);
		char* whiteline = new char [ limit_right ];
		for (int i=0; i<limit_right-1; ++i){
			whiteline[i]+=' ';
		}
		whiteline[limit_right -1] ='\0';
	
	
	}
	
	~message(){};
	
	void print(){
		move(x_msg,y_msg);
		addstr(whiteline);
		move(x_msg,y_msg);
		addstr(contenu);
	}
	void erase(){
		move(x_msg,y_msg);
		addstr(whiteline);
	}
	
	
	private:
	const char* contenu;
	const int x_msg;
	const int y_msg;
	const char* whiteline;

};