#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	Simple_window win {Point{100,100}, 600, 400, "My window"};

	Axis x {Axis::x, Point{20, 300}, 560, 18, "x"};
	Axis y {Axis::y, Point{300, 380}, 360, 12, "y"};

	Rectangle r {Point{100, 100}, 100, 50};
	r.set_fill_color(Color::red);
	r.set_style(Line_style(Line_style::dot, 4));

	Text t {Point{100, 200}, "Programozni jo :)"};
	t.set_font(Font::times_bold);
	t.set_font_size(40);

	Function sine {sin, 0, 100, Point{20, 150}, 1000, 50, 50};
	sine.set_color(Color::dark_green);

	Polygon poly;
	poly.add(Point{300, 200});
	poly.add(Point{350, 100});
	poly.add(Point{400, 200});
	poly.set_fill_color(Color::yellow);
	poly.set_style(Line_style::dash);

	Closed_polyline rect;
	rect.add(Point{100, 50});
	rect.add(Point{200, 50});
	rect.add(Point{200, 100});
	rect.add(Point{100, 100});
	rect.add(Point{50, 75});
	rect.set_fill_color(Color::white);

	Circle c {Point{300, 400}, 200};
	c.set_fill_color(Color::dark_red);

	Image ii {Point{100, 50}, "image.jpg"};


	win.attach(ii);
	win.attach(c);
	win.attach(rect);
	win.attach(poly);
	win.attach(sine);
	win.attach(t);
	win.attach(r);
	win.attach(x);
	win.attach(y);
	
	win.wait_for_button();
}