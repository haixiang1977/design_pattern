/*
 * factory.cpp
 *
 *  Created on: Nov 10, 2016
 *      Author: liu
 */

/* the factory method pattern is a creational pattern that uses factory methods
 * to deal with the problem of creating objects without having to specify the
 * exact class of the object that will be created.
 */

/* This is done by creating objects by calling a factory method:
 * either specified in an interface and implemented by child classes
 * or implemented in a base class and optionally overridden by derived
 * classes—rather than by calling a constructor.
 */

/* http://simplestcodings.blogspot.sg/2013/12/factory-method-design-pattern-in-cplusplus.html */

#include <iostream>

using namespace std;

/* factory items */
enum item_e{CAT,DOG, DUCK, INVALID};

/* base class */
class Animal {
public:
	virtual ~Animal() {};
	virtual void wow() = 0;
};

/* derived class */
class Cat: public Animal {
public:
	virtual ~Cat() {};
	virtual void wow() {cout << "Cat: miao" << endl;}
};

class Dog: public Animal {
public:
	virtual ~Dog() {};
	virtual void wow() {cout << "Dog: wong" << endl;}
};

class Duck: public Animal {
public:
	virtual ~Duck() {};
	virtual void wow() {cout << "Duck: ga" << endl;}
};

/* Factory class */
class AnimalFactory {
public:
	Animal* Get_Animal(item_e it) { //return pointer, then can overrider
		Animal* animal = NULL;

		switch (it) {
		case CAT:
			animal = new Cat();
			break;
		case DOG:
			animal = new Dog();
			break;
		case DUCK:
			animal = new Duck();
			break;
		case INVALID:
			break;
		}

		return animal;
	}
};

int main ()
{
	/* create a factory */
	AnimalFactory *factory = new AnimalFactory();

	/* create a instance from factory with item enum */
	Animal* cat = factory->Get_Animal(CAT);

	Animal* dog = factory->Get_Animal(DOG);

	/* all animal type but override different behavior */
	cat->wow();
	dog->wow();

	return 0;
}
