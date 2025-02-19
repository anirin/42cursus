#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: invalid arguments" << std::endl;
		return 1;
	}

	const char *filename = "data.csv";
	const char *input_name = argv[1];

	std::ifstream file(filename);
	std::ifstream input_file(input_name);
	std::string line;
	std::map<Data, double> data;

	if (!file.is_open())
	{
		std::cerr << "Error: data.csv file not found" << std::endl;
		return 1;
	}
	if (!input_file.is_open())
	{
		std::cerr << "Error: input file not found" << std::endl;
		file.close();
		return 1;
	}

	std::getline(file, line); // skip header

	data.clear();
	int count = 1;
	while (std::getline(file, line))
	{
		count++;
		try {
			get_data(line, data);
		} catch (std::exception& e) {
			std::cout << "line : " << count << " "<< e.what() << std::endl;
			return 1;
		}
	}
	logic(data, input_file);

	file.close();
	input_file.close();
	return 0;
}