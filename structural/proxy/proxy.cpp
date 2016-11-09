/*
 * proxy.cpp
 *
 *  Created on: Nov 9, 2016
 *      Author: liu
 */
/* https://en.wikipedia.org/wiki/Proxy_pattern */
/*  a proxy is a wrapper or agent object that is being called by the client
 *  to access the real serving object behind the scenes
 */
/* Design:                                                 */
/* 1. Design an "extra level of indirection" wrapper class */
/* 2. The wrapper class holds a pointer to the real class  */
/* 3. The pointer is initialized to null                   */
/* 4. When a request comes in, the real object is created
 * "on first use" (aka lazy initialization)
 */
/* 5. The request is always delegated to real class */

#include <iostream>

using namespace std;

// pure virtual base
class ICAR {
public:
	virtual ~ICAR() {}
	virtual void drive_car() = 0;
};

class CAR : public ICAR {
public:
	virtual ~CAR() {}
	virtual void drive_car () {cout << "CAR Driving" << endl;}
};

class CAR_PROXY : public ICAR { // Design an "extra level of indirection" wrapper class
private:
	ICAR* realcar; // The wrapper class holds a pointer to the real class
	int driver_age;
public:
	virtual ~CAR_PROXY() {}
	CAR_PROXY (int age) : realcar (NULL), driver_age (age) {}
	virtual void drive_car () {
		if (driver_age < 16) {
			cout << driver_age << " not able to drive" << endl;
		} else {
			realcar = new CAR(); // When a request comes in, the real object is created
			realcar->drive_car();
		}
	}
};

int main ()
{
	CAR_PROXY car1(10);
	CAR_PROXY car2(25);

	car1.drive_car();
	car2.drive_car();

	return 0;
}

