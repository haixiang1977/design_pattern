/*
 * strategy.cpp
 *
 *  Created on: Dec 25, 2016
 *      Author: liu
 */

// strategy pattern: enables an algorithm's behavior to be selected at runtime
// it defines: 1. defines a family of algorithms
//             2. encapsulates each algorithm, and
//             3. makes the algorithms interchangeable within that family.
// https://en.wikipedia.org/wiki/Strategy_pattern

#include <iostream>

using namespace std;

class StrategyInterface {
public:
	virtual ~StrategyInterface() {}
	virtual void execute() = 0;
};

class ConcreteStrategyA: public StrategyInterface {
public:
	~ConcreteStrategyA() {}
	void execute() {
		cout << "Called ConcreteStrategyA execute method" << endl;
	}
};

class ConcreteStrategyB: public StrategyInterface {
public:
	~ConcreteStrategyB() {}
	void execute() {
		cout << "Called ConcreteStrategyB execute method" << endl;
	}
};

class ConcreteStrategyC: public StrategyInterface {
public:
	~ConcreteStrategyC() {}
	void execute() {
		cout << "Called ConcreteStrategyC execute method" << endl;
	}
};

class Context {
private:
	StrategyInterface *_strategy;
public:
	Context(StrategyInterface *strategy): _strategy(strategy) {}
	void set_strategy(StrategyInterface *strategy) {
		_strategy = strategy;
	}
	void execute() {
		_strategy->execute();
	}
};

int main() {
	ConcreteStrategyA concreteStrategyA;
	ConcreteStrategyB concreteStrategyB;
	ConcreteStrategyC concreteStrategyC;

	Context contextA(&concreteStrategyA);
	Context contextB(&concreteStrategyB);
	Context contextC(&concreteStrategyC);

	contextA.execute();
	contextB.execute();
	contextC.execute();

	contextA.set_strategy(&concreteStrategyB);
	contextA.execute();
	contextA.set_strategy(&concreteStrategyC);
	contextA.execute();

	return 0;
}
