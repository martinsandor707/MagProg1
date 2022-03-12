////g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill15_graph.cpp `fltk-config --ldflags --use-images` -o a2.out
#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

double one(double x) { return 1;}
double slope(double x) { return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x){ return x/2+cos(x);}

int main(){
	try {
	int constexpr xmax=600, ymax=600, originx=xmax/2, originy=ymax/2;
	Point tl{100, 100};
	Simple_window win{tl, xmax, ymax, "My window"};
	Point origin{originx, originy};
	Axis xa(Axis::x, Point{100, originy}, 400, 20, "1 == 20 pixels");
	xa.set_color(Color::red);
	Axis ya(Axis::y, Point{originx, 500}, 400, 20, "1 == 20 pixels");
	ya.set_color(Color::red);
	
	win.attach(xa);
	win.attach(ya);	//Tengelyek eddig
	win.wait_for_button();
	
	int constexpr r_min=-10, r_max=11, xscale=20, yscale=20, points=400;
	
	Function constant{one, r_min, r_max, origin, points, xscale, yscale };
	Function linear{slope, r_min, r_max, origin, points, xscale, yscale }; Text label{Point{100, originy+85}, "x/2"};
	Function quadratic{square, r_min, r_max, origin, points, xscale, yscale };
	Function cosine{cos, r_min, r_max, origin, points, xscale, yscale }; cosine.set_color(Color::blue);
	Function coslinear{sloping_cos, r_min, r_max, origin, points, xscale, yscale };
	
	win.attach(constant);
	win.attach(linear); win.attach(label);
	win.attach(quadratic);
	win.attach(cosine);
	win.attach(coslinear);
	
	win.wait_for_button();
	
	}
	
	catch (exception& e){
		cerr << "exception: " << e.what() <<endl;
		return 1;
	} catch (...) {
		cerr << "exception\n";
		return 2;
	}
}
