/*
 * configuration.h
 *
 *  Created on: Jan 14, 2017
 *      Author: liu
 */

#ifndef CONFIGURATION_H_
#define CONFIGURATION_H_

#include <map>
#include <string>

class OpcConfiguration {
public:
	static OpcConfiguration* get_instance();

	// parse configuration file
	int parse();
	// get integer parameter
	int get_integer(const std::string &key, int &val);
	// get string parameter
	int get_string(const std::string &key, std::string &val);
private:
	// put Constructor and De-Constructor into private
	OpcConfiguration() {};
	~OpcConfiguration() {};

	static OpcConfiguration* m_instance;
	std::map <std::string, std::string> options;
};

#endif /* CONFIGURATION_H_ */
