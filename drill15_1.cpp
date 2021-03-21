#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{
	using namespace Graph_lib;

	Simple_window win {Point{100,100}, 600, 600, "Function graphs"};

	Axis x {Axis::x, Point{100, 300}, 400, 20, "1 == 20 pixels"};
	Axis y {Axis::y, Point{300, 500}, 400, 20, "1 == 20 pixels"};

	x.set_color(Color::red);
	y.set_color(Color::red);

	win.attach(x);
	win.attach(y);

	constexpr int range_min = -10;
	constexpr int range_max = 11;
	const Point origo {300, 300};
	constexpr int points = 400;
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;

	Function f1 {one, range_min, range_max, origo, points, x_scale, y_scale};
	Function f2 {slope, range_min, range_max, origo, points, x_scale, y_scale};
	Function f3 {square, range_min, range_max, origo, points, x_scale, y_scale};
	Function f4 {cos, range_min, range_max, origo, points, x_scale, y_scale};
	Function f5 {sloping_cos, range_min, range_max, origo, points, x_scale, y_scale};

	
	f4.set_color(Color::blue);
	Text t {Point{100, 380}, "x/2"};

	win.attach(f1);
	win.attach(f2);
	win.attach(t);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);

	win.wait_for_button();
}