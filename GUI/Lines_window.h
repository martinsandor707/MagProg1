#include "GUI.h"

using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
private:
	// data:
	Open_polyline lines;

	// widgets:
	Button next_button; // add (next_x,next_y) to lines
	Button quit_button; // end program
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button menu_button;
	
	Menu style_menu;
	Button style_button;

	void change(Color c) { lines.set_color(c); }
	
	void changeStyle(Line_style s) { lines.set_style(s);}
	
	void hide_menu() { color_menu.hide(); menu_button.show(); }
	
	void hide_style_menu() { style_menu.hide(); style_button.show(); }
	
	// actions invoked by callbacks:
	void red_pressed() { change(Color::red); hide_menu(); }
	void blue_pressed() { change(Color::blue); hide_menu(); }
	void black_pressed() { change(Color::black); hide_menu(); }
	void menu_pressed() { menu_button.hide(); color_menu.show(); }
	void next();
	void quit();
	
	void style_menu_pressed() { style_button.hide(); style_menu.show(); }
	void normal_pressed() { changeStyle(Line_style::solid); hide_style_menu(); }
	void dotted_pressed() { changeStyle(Line_style::dot); hide_style_menu(); }
	void dashed_pressed() { changeStyle(Line_style::dash); hide_style_menu(); }
	// callback functions:
	static void cb_red(Address, Address);
	static void cb_blue(Address, Address);
	static void cb_black(Address, Address);
	static void cb_menu(Address, Address);
	static void cb_next(Address, Address);
	static void cb_quit(Address, Address);
	
};

