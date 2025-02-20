#include "BitcoinExchange.hpp"

const size_t month_days_common[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const size_t month_days_leap[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

Data::Data() {
	_year = 0;
	_month = 0;
	_day = 0;
}

Data::Data(std::string data) {
	// Date format: yyyy-mm-dd
	std::string separator = "-";
	std::stringstream ss;
	size_t pos;
	std::string yearStr, monthStr, dateStr;

	// year
	pos = data.find(separator);
	yearStr = data.substr(0, pos);
	if (yearStr.size() != 4) {
		throw std::invalid_argument("Invalid year yyyy format");
	}
	ss << yearStr;
	ss >> _year;
	if (ss.fail()) {
		throw std::invalid_argument("Invalid year");
	}

	// month
	data = data.substr(pos + separator.size());
	pos = data.find(separator);
	monthStr = data.substr(0, pos);
	if (monthStr.size() != 2) {
		throw std::invalid_argument("Invalid month mm format");
	}
	ss.clear();
	ss << monthStr;
	ss >> _month;
	if (ss.fail()) {
		throw std::invalid_argument("Invalid month");
	}
	if (_month < 1 || _month > 12) {
		throw std::invalid_argument("Invalid month 01-12");
	}

	// day
	dateStr = data.substr(pos + separator.size());
	if (dateStr.size() != 2) {
		throw std::invalid_argument("Invalid day dd format");
	}
	ss.clear();
	ss << dateStr;
	ss >> _day;
	if (ss.fail()) {
		throw std::invalid_argument("Invalid day");
	}
	if (_day < 1) {
		throw std::invalid_argument("Invalid day is positive number");
	}
	if (_year % 4 == 0) {
		if (_day > month_days_leap[_month - 1]) {
			throw std::invalid_argument("Invalid day for leap year");
		}
	} else {
		if (_day > month_days_common[_month - 1]) {
			throw std::invalid_argument("Invalid day for common year");
		}
	}
}

Data::Data(const Data& other) {
	if (this == &other)
		return;
	// switch
	_year = other._year;
	_month = other._month;
	_day = other._day;
}

Data::~Data() {}

Data& Data::operator=(const Data& other) {
	if (this == &other)
		return *this;
	// switch
	_year = other._year;
	_month = other._month;
	_day = other._day;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Data& other) {
	os << other.getYear() << "-" << other.getMonth() << "-" << other.getDate();
	return os;
}

bool Data::operator<(const Data& other) const {
	if (_year < other._year)
		return true;
	if (_year == other._year && _month < other._month)
		return true;
	if (_year == other._year && _month == other._month && _day < other._day)
		return true;
	return false;
}

bool Data::operator>(const Data& other) const {
	if (_year > other._year)
		return true;
	if (_year == other._year && _month > other._month)
		return true;
	if (_year == other._year && _month == other._month && _day > other._day)
		return true;
	return false;
}

bool Data::operator==(const Data& other) const {
	if (_year == other._year && _month == other._month && _day == other._day)
		return true;
	return false;
}

// getter

size_t Data::getYear() const {
	return _year;
}
size_t Data::getMonth() const {
	return _month;
}
size_t Data::getDate() const {
	return _day;
}

// bitcoin methods

void get_data(std::string data, std::map<Data, double>& dataMap) {
	std::string separator = ",";
	std::string str_date, str_value;
	std::stringstream ss;
	double value;
	size_t pos;

	pos = data.find(separator);
	str_date = data.substr(0, pos);
	str_value = data.substr(pos + separator.size());
	ss << str_value;
	ss >> value;
	if (ss.fail()) {
		throw std::invalid_argument("[data.csv] Invalid value");
		return;
	}

	try {
		Data date(str_date);
		dataMap.insert(std::pair<Data, double>(date, value));
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		throw std::invalid_argument("[data.csv] Invalid date");
		return;
	}

	return;
}

void logic(std::map<Data, double>& dataMap, std::ifstream& input_file) {
	std::string separator = "|";
	std::string line;
	std::string str_date, str_value;
	std::stringstream ss;
	size_t pos;
	double value;

	std::getline(input_file, line);	 // skip header
	while (std::getline(input_file, line)) {
		pos = line.find(separator);
		if (pos == std::string::npos) {
			std::cerr << "Error: invalid data" << std::endl;
			continue;
		}
		str_date = line.substr(0, pos);

		if (str_date[str_date.size() - 1] == ' ')
			str_date = str_date.substr(0, str_date.size() - 1);

		str_value = line.substr(pos + separator.size());
		if (str_value[0] == ' ')
			str_value = str_value.substr(1);

		// ========== value part ==========
		ss.clear();
		ss << str_value;
		ss >> value;
		if (ss.fail()) {
			std::cerr << "Error: bad input value" << std::endl;
			continue;
		}
		if (value < 0) {
			std::cerr << "Error: not a positive number" << std::endl;
			continue;
		}
		if (value > 1000) {
			std::cerr << "Error: too large number" << std::endl;
			continue;
		}

		// ========== date part ==========
		Data input_data;
		try {
			Data date(str_date);
			input_data = date;
		} catch (std::exception& e) {
			std::cerr << "Error: " << e.what() << std::endl;
			continue;
		}

		std::map<Data, double>::iterator itr = dataMap.find(input_data);
		if (itr != dataMap.end()) {
			std::cout << input_data << " => " << value << " = " << itr->second * value << std::endl;
			continue;
		}
		for (std::map<Data, double>::iterator it = dataMap.begin(); it != dataMap.end(); it++) {
			if (input_data < it->first) {
				if (it == dataMap.begin()) {
					std::cerr << "Error: no data before the date" << std::endl;
					break;
				}
				it--;
				std::cout << input_data.getYear() << "-" << input_data.getMonth() << "-" << input_data.getDate()
					<< " => " << value << " = " << it->second * value << std::endl;
				break;
			}
		}
	}

	return;
}

// debug

void printMap(std::map<Data, double> data) {
	std::ofstream ofs("output.txt");
	if (!ofs) {
		std::cerr << "Error : can not open output file" << std::endl;
		return;
	}

	for (std::map<Data, double>::iterator it = data.begin(); it != data.end(); ++it) {
		Data dates = it->first;
		ofs << dates << " = " << it->second << std::endl;
	}
}