/*
 * bridge.cpp
 *
 *  Created on: Nov 22, 2016
 *      Author: liu
 */

/* bridge design pattern: decouple an abstraction from its implementation so
 * that the two can vary independently. the client code can access only the
 * Abstraction part without being concerned about the Implementation part. */

/* http://notes4programs.blogspot.sg/2013/06/bridge-design-pattern.html */

#include <iostream>

using namespace std;

class Switch {
public:
	virtual ~Switch() {}
	virtual void turnOn() = 0;
	virtual void turnOff() = 0;
};

class IAppliance {
public:
	virtual ~IAppliance() {}
	virtual void run() = 0;
	virtual void off() = 0;
};

class BridgeSwitch : public Switch {
protected:
	IAppliance* iAppliance;
public:
	BridgeSwitch (IAppliance* backend) {iAppliance = backend;}
	void turnOn () {
		cout << "BridgeSwitch On" << endl;
		iAppliance->run();
	}
	void turnOff() {
		cout << "BridgeSwitch Off" << endl;
		iAppliance->off();
	}
};

class RemoteControl : public BridgeSwitch {
public:
	RemoteControl (IAppliance* i) : BridgeSwitch(i) {}
	void turnOn () {
		cout << "RemoteControl On" << endl;
		iAppliance->run();
	}
	void turnOff () {
		cout << "RemoteControl Off" << endl;
		iAppliance->off();
	}
};

class TV : public IAppliance {
private:
	string name;
public:
	TV (string n) {
		name = n;
	}
	void run () {
		cout << "TV " << name << " is switch on" << endl;
	}
	void off () {
		cout << "TV " << name << " is switch off" << endl;
	}
};

class Radio : public IAppliance {
private:
	string name;
public:
	Radio (string n) {
		name = n;
	}
	void run () {
		cout << "Radio " << name << " is switch on" << endl;
	}
	void off () {
		cout << "Radio " << name << " is switch off" << endl;
	}
};

int main() {
	Switch *s;

	IAppliance *tv = new TV ("samsung");
	IAppliance *radio = new Radio ("Huawei");

	s = new RemoteControl (tv);
	s->turnOn();
	s->turnOff();

	s = new RemoteControl (radio);
	s->turnOn();
	s->turnOff();

	return 0;
}
