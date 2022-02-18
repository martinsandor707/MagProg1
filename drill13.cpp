#include "./GUI/Graph.h"
#include "./GUI/Simple_window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){
	try {
		Point t1(300,50);
		Simple_window win(t1, 1000, 800, "My window");
		win.wait_for_button();
		
		Lines grid;
		int x_size=800;
		int y_size=800;
		for(int i=100; i<=x_size; i+=100){
			grid.add(Point(i,0), Point(i, y_size));
			grid.add(Point(0,i), Point(x_size, i));
		}
		win.attach(grid);
		win.wait_for_button();
		
		//Feladat: az átlóban jelenjenek meg piros négyzetek
		
		Vector_ref <Graph_lib::Rectangle> rectangles;
		for (int i=0; i<8; i++)
		{
		rectangles.push_back(new Graph_lib::Rectangle(Point{i*100,i*100}, 100, 100));
		rectangles[i].set_fill_color(Color::red);
		win.attach(rectangles[i]);
		}
		win.wait_for_button();
		
		Image i1 {Point{100,50}, "GUI/badge.jpg"}; //400*400-pixel jpg
		i1.set_mask(Point{100,100}, 200, 200);
		win.attach(i1);
		i1.move(100,-50);
		
		Image i2 {Point{100,50}, "GUI/badge.jpg"}; //400*400-pixel jpg
		i2.set_mask(Point{100,100}, 200, 200);
		win.attach(i2);
		i2.move(400,50);
		
		Image i3 {Point{100,50}, "GUI/badge.jpg"}; //400*400-pixel jpg
		i3.set_mask(Point{100,100}, 200, 200);
		win.attach(i3);
		i3.move(100,450);
		win.wait_for_button();
		
		
		Image i4 {Point{0, 0}, "GUI/badge.jpg"};
		i4.set_mask(Point{100,100}, 100, 100);
		win.attach(i4);
		win.wait_for_button();
		
		while (true){
		for (int i=0; i<8; i++){
			for (int j=0; j<7; j++){
				i4.move(100,0);
				win.wait_for_button();
			}
			i4.move(-700,100);
			win.wait_for_button();
		}
		i4.move(0,-700);
		win.wait_for_button();
		}
	}
	
	
	
	catch (exception& e){
		cerr << "exception: " << e.what() <<endl;
		return 1;
	} catch (...) {
		cerr << "exception\n";
		return 2;
	}
}
