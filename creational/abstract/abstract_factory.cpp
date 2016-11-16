/*
 * abstract_factory.cpp
 *
 *  Created on: Nov 16, 2016
 *      Author: liu
 */

/* The abstract factory pattern provides a way to encapsulate a group of
 * individual factories that have a common theme without specifying their
 * concrete classes.
 */
/* In normal usage, the client software creates a concrete implementation of
 * the abstract factory and then uses the generic interface of the factory to
 * create the concrete objects that are part of the theme. The client doesn't
 * know (or care) which concrete objects it gets from each of these internal
 * factories, since it uses only the generic interfaces of their products.
 */
/* This pattern separates the details of implementation of a set of objects
 * from their general usage and relies on object composition, as object
 * creation is implemented in methods exposed in the factory interface.
 */

/* http://www.codeproject.com/Articles/331304/Understanding-and-Implementing-Abstract-Factory */
#include <iostream>

using namespace std;

/* Abstract factory: declares an interface for operations that create abstract products */
/* ConcreteFactory: implement the operations to create concrete products */
/* AbstractProduct: declares an interface for a type of product object */
/* Product: defines a product object to be created by the corresponding concrete factory implements the AbstractProduct interface */
/* Client: uses interfaces declared by AbstractFactory and AbstractProduct classes */

/* Abstract products 2G abd 4G phones */
class Phone_2G {
public:
	virtual ~Phone_2G() {}
	virtual string name() = 0;
};

/* Product */
class Phone_4G {
public:
	virtual ~Phone_4G() {}
	virtual string name() = 0;
};

class Samsung_2G : public Phone_2G {
	string name() {return "Samsung 2G Phone";}
};

class Samsung_4G : public Phone_4G {
	string name() {return "Samsung 4G Phone";}
};

class Huawei_2G : public Phone_2G {
	string name() {return "Huawei 2G Phone";}
};

class Huawei_4G : public Phone_4G {
	string name() {return "Huawei 4G Phone";}
};

/* Abstract Factory */
class APhoneFactory {
public:
	enum PHONE_FACTORIES {
		SAMSUNG,
		HUAWEI
	};

	virtual ~APhoneFactory() {}
	virtual Phone_2G* get_2G_phone() = 0;
	virtual Phone_4G* get_4G_phone() = 0;

	static APhoneFactory* CreateFactory(PHONE_FACTORIES factory);
};

/* ConcreteFactory */
class SAMSUNG_Factory : public APhoneFactory {
public:
	Phone_2G* get_2G_phone() {return new Samsung_2G();}
	Phone_4G* get_4G_phone() {return new Samsung_4G();}
};

class HUAWEI_Factory : public APhoneFactory {
public:
	Phone_2G* get_2G_phone() {return new Huawei_2G();}
	Phone_4G* get_4G_phone() {return new Huawei_4G();}
};

APhoneFactory* APhoneFactory::CreateFactory (PHONE_FACTORIES factory) {
	if (factory == SAMSUNG) {
		return new SAMSUNG_Factory();
	}

	if (factory == HUAWEI) {
		return new HUAWEI_Factory();
	}

	return (APhoneFactory* )NULL;
}

/* the client only know the brand of phone but not know the name of the phone */
int main ()
{
	/* create Samsung Factory */
	APhoneFactory* factory = APhoneFactory::CreateFactory(APhoneFactory::SAMSUNG);
	/* Get 2G from Samsung Factory */
	Phone_2G* phone_2g = factory->get_2G_phone();
	cout << "2G phone name " << phone_2g->name() << endl;

	delete phone_2g;
	delete factory;

	/* create Huawei Factory */
	factory = APhoneFactory::CreateFactory(APhoneFactory::HUAWEI);
	/* Get 4G from Huawei Factory */
	Phone_4G* phone_4g = factory->get_4G_phone();
	cout << "4G phone name " << phone_4g->name() << endl;

	delete phone_4g;
	delete factory;

	return 0;
}
