/*
 * decorator.cpp
 *
 *  Created on: Jan 30, 2017
 *      Author: liu
 */

// In object-oriented programming, the decorator pattern (also known as Wrapper,
// an alternative naming shared with the Adapter pattern) is a design pattern
// that allows behavior to be added to an individual object, either statically
// or dynamically, without affecting the behavior of other objects from the
// same class.

// https://en.wikipedia.org/wiki/Decorator_pattern
// https://sourcemaking.com/design_patterns/decorator

// 1. Subclass the original Component class into a Decorator class
// 2. In the Decorator class, add a Component pointer as a field;
// 3. In the Decorator class, pass a Component to the Decorator constructor to
// initialize the Component pointer;
// 4. In the Decorator class, forward all Component methods to the Component
// pointer; and
// 5. In the ConcreteDecorator class, override any Component method(s) whose
// behavior needs to be modified.
// This pattern is designed so that multiple decorators can be stacked on top
// of each other, each time adding a new functionality to the overridden
// method(s).
// Use aggregation instead of inheritance to implement embellishments to a
// "core" object. Client can dynamically compose permutations, instead of the
// architect statically wielding multiple inheritance.


#include <iostream>

using namespace std;

// use aggregation not inheritance
class I {
public:
	virtual ~I() {}
	virtual void do_it() = 0;
};

class A: public I {
public:
	~A() {
		cout << "A De-structor"<< endl;
	}
	void do_it() {
		cout << "A do_it" << endl;
	}
};

class D: public I {
public:
	D (I* inner) {
		m_wrapper = inner;
	}
	~D () {
		delete m_wrapper;
		cout << "D De-structor"<< endl;
	}
	void do_it() {
		m_wrapper->do_it();
		cout << "D do_it" << endl;
	}
private:
	I* m_wrapper;
};

class X: public D {
public:
	X(I* core) : D(core){} // D(core) constructor and return Class D object
	~X() {
		cout << "X De-structor"<< endl;
	}
	void do_it() {
		D::do_it(); // call parent class function
		cout << "X do_it" << endl;
	}
};

class Y: public D {
public:
	Y(I* core) : D(core){}
	~Y() {
		cout << "Y De-structor"<< endl;
	}
	void do_it() {
		D::do_it();
		cout << "Y do_it" << endl;
	}
};

class Z: public D {
public:
	Z(I* core) : D(core){}
	~Z() {
		cout << "Z De-structor"<< endl;
	}
	void do_it() {
		D::do_it();
		cout << "Z do_it" << endl;
	}
};

int main() {
	I *anX = new X(new A);
	I *anXY = new Y(new X(new A));
	I *anXYZ = new Z(new Y(new X(new A)));

	anX->do_it();
	cout << endl;
	anXY->do_it();
	cout << endl;
	anXYZ->do_it();
	cout << endl;

	delete anX;
	delete anXY;
	delete anXYZ;

	return 0;
}

