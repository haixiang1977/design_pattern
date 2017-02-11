/*
 * state.cpp
 *
 *  Created on: Feb 11, 2017
 *      Author: liu
 */

// The state pattern is a behavioral software design pattern that implements a state machine in an
// object-oriented way.
// With the state pattern, a state machine is implemented by implementing each individual state as a
// derived class of the state pattern interface, and implementing state transitions by invoking methods
// defined by the pattern's superclass.
// https://en.wikipedia.org/wiki/State_pattern

#include <iostream>

using namespace std;

class TLNetTraffic;

class TLState {
public:
	virtual ~TLState() {}
	virtual void Handle() = 0;
};

class TLNetTraffic {
private:
	TLState* _state;
public:
	TLNetTraffic();
	void setState (TLState* state);
	void Handle();
};

class TLRed : public TLState {
private:
	TLNetTraffic* _context;
public:
	TLRed(TLNetTraffic* context);
	void Handle();
};

class TLYellow : public TLState {
private:
	TLNetTraffic* _context;
public:
	TLYellow(TLNetTraffic* context);
	void Handle();
};

class TLGreen : public TLState {
private:
	TLNetTraffic* _context;
public:
	TLGreen(TLNetTraffic* context);
	void Handle();
};

TLNetTraffic::TLNetTraffic() {
	_state = new TLRed (this);
}

void TLNetTraffic::setState(TLState* state) {
	_state = state;
	return;
}

void TLNetTraffic::Handle() {
	_state->Handle();
	return;
}

TLRed::TLRed(TLNetTraffic* context) {
	_context = context;
}

TLYellow::TLYellow(TLNetTraffic* context) {
	_context = context;
}

TLGreen::TLGreen(TLNetTraffic* context) {
	_context = context;
}

void TLRed::Handle() {
	cout << "RED Light" << endl;
	_context->setState(new TLGreen(_context));
	return;
}

void TLYellow::Handle() {
	cout << "Yellow Light" << endl;
	_context->setState(new TLRed(_context));
	return;
}

void TLGreen::Handle() {
	cout << "Green Light" << endl;
	_context->setState(new TLYellow(_context));
	return;
}

int main() {
	TLNetTraffic netTraffic;

	netTraffic.Handle();
	netTraffic.Handle();
	netTraffic.Handle();
	netTraffic.Handle();
	netTraffic.Handle();
	netTraffic.Handle();

	return 0;
}
