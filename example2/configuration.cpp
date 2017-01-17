/*
 * configuration.cpp
 *
 *  Created on: Jan 14, 2017
 *      Author: liu
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include "configuration.h"

OpcConfiguration* OpcConfiguration::m_instance = NULL;

OpcConfiguration* OpcConfiguration::get_instance() {
	if (m_instance == NULL) {
		m_instance = new OpcConfiguration();
	}

	return m_instance;
}

int OpcConfiguration::parse() {
	// associate the file and open the file
	std::ifstream cfgfile ("opcclient.cfg", std::ifstream::in);

	if (cfgfile.good() == false) {
		return -1;
	}

	for (std::string line; std::getline(cfgfile, line);) {
		std::string id, val;
		std::size_t found;

		//std::cout << "line " << line << std::endl;
		if (line[0] == '#') {
			continue;
		}

		found = line.find('=', 0);
		if (found != std::string::npos) {
			//std::cout << "found '=' at " << line.find('=', 0) << std::endl;
			id = line.substr(0, found);
			val = line.substr(found + 1, std::string::npos);
			options[id] = val;
		}
	}

#if 0
	// dump the configuration options
	for (std::map<std::string, std::string>::iterator it = options.begin(); it != options.end(); it++) {
		std::cout << it->first << " => " << it->second << std::endl;
	}
#endif
	return 0;
}

int OpcConfiguration::get_integer(const std::string &key, int &val) {
	std::map <std::string, std::string>::iterator it;

	it = options.find(key);
	if (it != options.end()) {
		val = atoi(options.find(key)->second.c_str());
	} else {
		return -1;
	}

	return 0;
}

int OpcConfiguration::get_string(const std::string &key, std::string &val) {
	std::map <std::string, std::string>::iterator it;

	it = options.find(key);
	if (it != options.end()) {
		val = options.find(key)->second;
	} else {
		return -1;
	}

	return 0;
}
