/*
 * command.cpp
 *
 *  Created on: Nov 17, 2016
 *      Author: liu
 */
/* http://www.codeproject.com/Articles/343676/Understanding-and-Implementing-the-Command-Pattern */
/* In object-oriented programming, the command pattern is a behavioral design
 * pattern in which an object is used to encapsulate all information needed to
 * perform an action or trigger an event at a later time. This information
 * includes the method name, the object that owns the method and values for the
 * method parameters
 */

/* Command: This is an interface for executing an action. */
/* ConcreteCommand: This object specifies the binding between a Receiver/action
 * taker and an action invoker. */
/* Client: Creates a ConcreteCommand object and sets its receiver. */
/* Invoker: It will use the Command object to carry out the request. */
/* Receiver: It contains the real operational logic that needs to be performed
 * on the data. */

#include <iostream>

using namespace std;

enum ACTION_LIST {
	ADD,
	SUBSTRACT,
	MULTIPLY,
	NONE
};

class IReceiver {
public:
	virtual ~IReceiver() {}
	virtual void SetAction(ACTION_LIST action) = 0;
	virtual int GetResult() = 0;
};

class ACommand {
protected:
	IReceiver *pReceiver_;

public:
	ACommand (IReceiver *receiver): pReceiver_(receiver) {}
	virtual ~ACommand() {}
	virtual int Execute() = 0;
};

class AddCommand : public ACommand {
public:
	AddCommand (IReceiver *receiver): ACommand (receiver) {}
	int Execute() {
		pReceiver_->SetAction(ADD);
		return pReceiver_->GetResult();
	}
};

class SubCommand : public ACommand {
public:
	SubCommand (IReceiver *receiver): ACommand (receiver) {}
	int Execute() {
		pReceiver_->SetAction(SUBSTRACT);
		return pReceiver_->GetResult();
	}
};

class MultiplyCommand : public ACommand {
public:
	MultiplyCommand (IReceiver *receiver): ACommand (receiver) {}
	int Execute() {
		pReceiver_->SetAction(MULTIPLY);
		return pReceiver_->GetResult();
	}
};

class Caculator : public IReceiver {
private:
	int x_;
	int y_;
	ACTION_LIST current_action;

public:
	Caculator (int x, int y) : x_(x), y_(y), current_action(NONE) {}
	void SetAction (ACTION_LIST action) { current_action = action;}
	int GetResult() {
		int result;

		switch (current_action) {
		case (ADD):
			result = x_ + y_;
			break;
		case (SUBSTRACT):
			result = x_ - y_;
			break;
		case (MULTIPLY):
			result = x_ * y_;
			break;
		default:
			result = 0xFFFFFFFF;
			break;
		}

		return result;
	}
};

int main ()
{
	Caculator c = Caculator(30, 20);

	AddCommand* addcmd = new AddCommand(&c);
	SubCommand* subcmd = new SubCommand(&c);
	MultiplyCommand* multicmd = new MultiplyCommand(&c);

	cout << "add result " << addcmd->Execute() << endl;
	cout << "sun result " << subcmd->Execute() << endl;
	cout << "multi result " << multicmd->Execute() << endl;

	return 0;
}
