/*
 * facade.cpp
 *
 *  Created on: Jan 16, 2017
 *      Author: liu
 */

// A facade is an object that provides a simplified interface to a larger body
// of code, such as a class library.
// A facade can:
// make a software library easier to use, understand and test, since the facade
// has convenient methods for common tasks,
// make the library more readable, for the same reason
// reduce dependencies of outside code on the inner workings of a library
// wrap a poorly designed collection of APIs with a single well-designed API

// The Facade design pattern is often used when a system is very complex or
// difficult to understand because the system has a large number of interdependent
// classes or its source code is unavailable. This pattern hides the complexities
// of the larger system and provides a simpler interface to the client. It
// typically involves a single wrapper class that contains a set of members
// required by client. These members access the system on behalf of the facade
// client and hide the implementation details.

#include <iostream>

using namespace std;

class Camera {
public:
	void turn_on() {
		cout << "Turning on the camera" << endl;
	}
	void turn_off() {
		cout << "Turning off the camera" << endl;
	}
	void rotate(int degree) {
		cout << "Camera rotate " << degree << endl;
	}
};

class Light {
public:
	void turn_on() {
		cout << "Turning on the Light" << endl;
	}
	void turn_off() {
		cout << "Turning off the Light" << endl;
	}
	void change_bubble() {
		cout << "changing the light bubble" << endl;
	}
};

class Sensor {
public:
	void turn_on() {
		cout << "Turning on the Sensor" << endl;
	}
	void turn_off() {
		cout << "Turning off the Sensor" << endl;
	}
	void trigger() {
		cout << "trigger the sensor" << endl;
	}
};

class Alarm {
public:
	void turn_on() {
		cout << "Turning on the Alarm" << endl;
	}
	void turn_off() {
		cout << "Turning off the Alarm" << endl;
	}
	void Ring() {
		cout << "Ringing the alarm" << endl;
	}
	void StopRing() {
		cout << "Stop the alarm" << endl;
	}
};

class SimpleFacade {
private:
	Camera *camera1, *camera2;
	Light *light1, *light2, *light3;
	Sensor *sensor;
	Alarm *alarm;
public:
	SimpleFacade () {
		camera1 = new Camera();
		camera2 = new Camera();
		light1 = new Light();
		light2 = new Light();
		light3 = new Light();
		sensor = new Sensor();
		alarm = new Alarm();
	}
	void Activate () {
		camera1->turn_on();
		camera2->turn_on();
		light1->turn_on();
		light2->turn_on();
		light3->turn_on();
		sensor->turn_on();
		alarm->turn_on();
	}
	void DeActivate () {
		camera1->turn_off();
		camera2->turn_off();
		light1->turn_off();
		light2->turn_off();
		light3->turn_off();
		sensor->turn_off();
		alarm->turn_off();
	}
};

int main () {

	SimpleFacade *security = new SimpleFacade();

	security->Activate();
	cout << "------------------" << endl;
	security->DeActivate();

	return 0;
}
