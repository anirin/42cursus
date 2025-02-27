#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <cstdlib>
#include <cerrno>
#include <stdexcept>

class Data
{
private:
	size_t _year;
	size_t _month;
	size_t _day;

public:
	Data();
	Data(std::string data);
	Data(const Data &other);
	~Data();

	Data &operator=(const Data &other);

	bool operator<(const Data &other) const;
	bool operator>(const Data &other) const;
	bool operator==(const Data &other) const;

	size_t getYear() const;
	size_t getMonth() const;
	size_t getDate() const;
};

void get_data(std::string data, std::map<Data, double> &dataMap);
void logic(std::map<Data, double> &dataMap, std::ifstream &input_file);
void printMap(std::map<Data, double> data);

std::ostream &operator<<(std::ostream& os, const Data& other);