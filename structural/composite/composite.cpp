/*
 * composite.cpp
 *
 *  Created on: Jan 2, 2017
 *      Author: liu
 */

/* The composite pattern describes that a group of objects is to be treated
 * in the same way as a single instance of an object. The intent of a composite
 * is to "compose" objects into tree structures to represent part-whole hierarchies.
 * Implementing the composite pattern lets clients treat individual objects and
 * compositions uniformly
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graphic {
public:
	virtual ~Graphic() {}
	virtual void draw() = 0;
};

class Line: public Graphic {
public:
	void draw() {
		cout << "Line draw" << endl;
	}
};

class Rectangle: public Graphic {
public:
	void draw() {
		cout << "Rectangle draw" << endl;
	}
};

class Text: public Graphic {
public:
	void draw() {
		cout << "Text draw" << endl;
	}
};

// Composite
class Picture: public Graphic {
private:
	vector <Graphic *> gList;
public:
	void draw() {
		// std::mem_fun convert member function to function object (function pointer
		for_each(gList.begin(), gList.end(), mem_fun(&Graphic::draw));
	}

	void add_graphic(Graphic* g) {
		gList.push_back(g);
	}
};

int main ()
{
	Line line;
	Rectangle rect;
	Text text;

	line.draw();
	rect.draw();
	text.draw();

	Picture pic;
	pic.add_graphic(&line);
	pic.add_graphic(&rect);
	pic.add_graphic(&text);

	pic.draw();

	return 0;
}
