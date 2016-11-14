/*
 * adapter.cpp
 *
 *  Created on: Nov 14, 2016
 *      Author: liu
 */
/* http://www.codeproject.com/Tips/595716/Adapter-Design-Pattern-in-Cplusplus */

/* An adapter pattern converts the interface of a class into another interface
 * the clients expect. Adapter lets classes work together that couldn't
 * otherwise because of incompatible interfaces. */
/* It comprises three components: */
/* . Target: This is the interface with which the client interacts. */
/* . Adaptee: This is the interface the client wants to interact with, but
 * can’t interact without the help of the Adapter. */
/* Adapter: This is derived from Target and contains the object of Adaptee. */

#include <iostream>

using namespace std;

// abstract target
class AbstractPlug {
public:
	virtual ~AbstractPlug() {}
	void virtual RoundPin() = 0;
	void virtual PinCount() = 0;
};

// concrete target
class Plug : public AbstractPlug {
public:
	void RoundPin() {cout << "Plug I have round pin" << endl;}
	void PinCount() {cout << "Plug I have 2 pins" << endl;}
};

// abstract adaptee
class AbstractSwitchBoard {
public:
	virtual ~AbstractSwitchBoard() {}
	void virtual FlatPin() = 0;
	void virtual PinCount() = 0;
};

// concrete adaptee
class SwitchBoard : public AbstractSwitchBoard {
public:
	void FlatPin() {cout << "SwitchBoard I have flat pin" << endl;}
	void PinCount() {cout << "SwitchBoard I have 3 pins" << endl;}
};

// adapter
class Adapter : public AbstractPlug {
private:
	AbstractSwitchBoard *T;
public:
	Adapter (AbstractSwitchBoard *TT) {
		T = TT;
	}
	void RoundPin () { // convert round pin to flat pin
		T->FlatPin();
	}
	void PinCount () { // convert 2 pins to 3 pins
		T->PinCount();
	}
};

int main ()
{
	SwitchBoard *mySwitchBoard = new SwitchBoard();
	AbstractPlug *adapter = new Adapter(mySwitchBoard);

	adapter->PinCount();
	adapter->RoundPin();

	return 0;
}

