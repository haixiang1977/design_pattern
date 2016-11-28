/*
 * iterateor.cpp
 *
 *  Created on: Nov 28, 2016
 *      Author: liu
 */

/* the iterator pattern is a design pattern in which an iterator is used to
 * traverse a container and access the container's elements. */
/* To implement the iterator pattern for a container in STL fashion, need to consider */
/* How to define the begin() member function of the container */
/* How to define the end() member function of the container */
/* How to define these operators '==' '!=' for iterators */

/* example: https://sourcemaking.com/design_patterns/iterator/cpp/1 */
/* http://blog.csdn.net/lovelion/article/details/9992243 */

#include <iostream>

using namespace std;

class StackIter;

/* define data structure and use iterator to browse */
class Stack {
private:
	int items[10];
	int sp;
public:
	/* This gives all of the members of the friend class access to the private
	 * members of the other class. */
	friend class StackIter;

	Stack() {
		sp = -1;
	}
	void push(int in) {
		items[++sp] = in;
	}
	int pop () {
		return items[sp--];
	}
	bool isEmpty() {
		return (sp == -1);
	}
	StackIter *createIterator();
};

/* class StackIter can access class Stack private member because of friend */
class StackIter {
private:
	const Stack *stk;
	int index;
public:
	StackIter(const Stack *s) {
		stk = s;
		index = 0;
	}
	void first() {
		index = 0;
	}
	void next() {
		index ++;
	}
	bool isDone() {
		/* can access class Stack private member directly because friend */
		return index == stk->sp + 1;
	}
	int currentItem() {
		return stk->items[index];
	}
};

StackIter* Stack::createIterator() {
	return new StackIter(this);
}

int main()
{
	Stack *s;
	int i;

	s = new Stack();

	for (i = 0; i < 5; i++) {
		s->push(i);
	}

	/* use iterator to pop and print */
	StackIter *it = s->createIterator();
	for (it->first(); !it->isDone(); it->next()) {
		cout << "it current value " << it->currentItem() << endl;
	}

	return 0;
}
