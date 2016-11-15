/*
 * observer.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: liu
 */

/* http://www.codeproject.com/Articles/328365/Understanding-and-Implementing-Observer-Pattern */
/* subject:
 * This class keeps track of all the observers and provides the facility to add
 * or remove the observers. Also it is the class that is responsible for
 * updating the observers when any change occurs.
 */
/* ConcreteSubject:
 * This class is the real class that implements the Subject.
 */
/* Observer:
 * This represents an interface that defines the method that should be called
 * whenever there is change.
 */
/* ConcreteObserver:
 * This is the class which needs to keep itself updated with the change. This
 * class just needs to implement the Observer and register itself with the
 * ConcreteSubject and it is all set to receive the updates.
 */

#include <iostream>
#include <vector>

using namespace std;

/* example here: product price is changed, all shops will get notified */
/* shop is observer and product is subject */

// define observer class
class AObserver {
public:
	virtual ~AObserver() {}
	virtual void update (int price) = 0;
};

// define observer concrete implementation
class Shop : public AObserver {
private:
	string name;
	int price;
public:
	Shop (string name);
	string get_name() {return this->name;}
	void update (int price);
};

Shop::Shop(string name) {
	this->name = name;
	this->price = 0;
}

void Shop::update (int price) {
	this->price = price;
	cout << "Price at " << this->name << " is now " << this->price << endl;
}

// define Subject
class ASubject {
private:
	/* keep all the observers here */
	vector <Shop*> list;
public:
	void attach (Shop* shop);
	void detach (Shop* shop);
	void notify (int price);
};

void ASubject::attach(Shop* shop) {
	/* put shop into the observer list */
	cout << "register shop name " << shop->get_name() << endl;
	list.push_back(shop);
	return;
}

void ASubject::detach(Shop* shop) {
	vector <Shop* >::iterator it;
	for (it = list.begin(); it != list.end(); ++it) {
		if ((*it) == shop) {
			cout << "un-register shop name " << shop->get_name() << endl;
			list.erase(it);
			break;
		}
	}
	return;
}

void ASubject::notify(int price) {
	vector <Shop* >::iterator it;
	for (it = list.begin(); it != list.end(); ++it) {
		(*it)->update(price);
	}
	return;
}

class Product : public ASubject {
public:
	void change_price (int price);
};

void Product::change_price (int price) {
	this->notify(price);
}

int main()
{
	Product p;
	Shop shop1 ("shop 1");
	Shop shop2 ("shop 2");

	p.attach(&shop1);
	p.attach(&shop2);

	p.change_price(10);

	p.detach(&shop1);

	p.change_price(20);

	p.detach(&shop2);
	p.attach(&shop1);

	p.change_price(30);

	return 0;
}
