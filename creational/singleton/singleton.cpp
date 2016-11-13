/*
 * singleton.cpp
 *
 *  Created on: Nov 13, 2016
 *      Author: liu
 */

/* https://en.wikipedia.org/wiki/Singleton_pattern */
/* http://www.yolinux.com/TUTORIALS/C++Singleton.html */

/* the singleton pattern is a design pattern that restricts the instantiation
 * of a class to one object.
 */
/* This is useful when exactly one object is needed to coordinate actions
 * across the system. The concept is sometimes generalized to systems that
 * operate more efficiently when only one object exists, or that restrict the
 * instantiation to a certain number of objects.
 */
/* Implementation */
/* An implementation of the singleton pattern must: */
/* . ensure that only one instance of the singleton class ever exists; and */
/* . provide global access to that instance. */
/* Typically, this is done by: */
/* declaring all constructors of the class to be private; and */
/* providing a static method that returns a reference to the instance. */
/* The instance is usually stored as a private static variable;
 * the instance is created when the variable is initialized,
 * at some point before the static method is first called.
 */

#include <iostream>

using namespace std;

/* That the instance function returns a pointer to a static variable and thus
 * is declared static. */

/* The constructor, copy constructor and assignment operator are all private
 * to ensure that the programmer using the singleton class can only create a
 * single instance of the class using only the Instance() function. */

/* Only the class function Instance can call the constructor. Public access
 * to the constructor is denied. */
class Logger {
public:
	static Logger* Instance();
	void open_file();
	void close_file();
private:
	Logger() {} // constructor is private
	Logger(Logger const&){}; // copy constructor is private
	Logger& operator=(Logger const&){}; // assignment operator is private

	static Logger* m_instance;
};

/* Global static pointer used to ensure a single instance of the class. */
Logger* Logger::m_instance = NULL;

/* This function is called to create an instance of the class. */
/* Calling the constructor publicly is not allowed. The constructor is private
 * and is only called by this Instance function.*/
/* static member function can neither access non-static data memebers nor
 * call non-static member functions because it has no this pointer
 */
Logger* Logger::Instance() {
	if (m_instance == NULL) {
		m_instance = new Logger();
	}

	return m_instance;
}

void Logger::open_file() {
	cout << "Logger::open file" << endl;
}

void Logger::close_file() {
	cout << "Logger::close file" << endl;
}

int main ()
{
	Logger::Instance()->open_file();

	Logger::Instance()->close_file();

	return 0;
}
