#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

int main()
{
	using namespace Graph_lib;

	//make window
	Simple_window win {Point{100,100}, 800, 1000, "Canvas"};

	//grid measurements
	int x_size = 800;
	int y_size = 800;
	int x_grid = 100;
	int y_grid = 100;

	//draw grid
	Lines grid;
	for (int x = x_grid; x < x_size; x += x_grid)
		grid.add(Point{x, 0}, Point{x, y_size});
	for (int y = y_grid; y < y_size; y += y_grid)
		grid.add(Point{0, y}, Point{x_size, y});
	win.attach(grid);

	//draw red rectangles
	Vector_ref<Rectangle> rect;
	  for (int i = 0; i < x_size; i += x_grid) 
	  	{
        	rect.push_back(new Rectangle{Point{i,i}, Point{i+x_grid,i+x_grid}});
        	rect[rect.size() - 1].set_color(Color::invisible);
        	rect[rect.size() - 1].set_fill_color(Color::red);
        	win.attach(rect[rect.size() - 1]);
        }

    //attach same picture 3 times
    Image pic1 {Point{500, 0}, "coffee.jpg"};
    Image pic2 {Point{0, 300}, "coffee.jpg"};
    Image pic3 {Point{200, 500}, "coffee.jpg"};
    win.attach(pic1);
    win.attach(pic2);
    win.attach(pic3);

	win.wait_for_button();

	//attach 100x100 picture that moves 
	Image spongebob {Point{0,0}, "bob.jpg"};  //attach pic at 0,0, wait for button
	win.attach(spongebob);
	win.wait_for_button();

	//start moving
	for (int i = 0; i < 8; ++i) 				//??does some weird things??
	{
        for (int j = 0; j < 8; ++j) 
        {
            spongebob.move(100, 0);
            win.wait_for_button();
        }
        spongebob.move(-700, 100);
        win.wait_for_button();
    }

    win.wait_for_button();


}