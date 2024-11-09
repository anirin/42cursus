#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 4) {
    std::cout << "arg number is invalid" << std::endl;
    return 1;
  }
  std::string filename = argv[1];
  std::string s1 = argv[2];
  std::string s2 = argv[3];
  if (s1 == s2) {
    std::cout << "s1 and s2 is same" << std::endl;
    return 1;
  }

  std::ifstream input_file(filename);
  if (!input_file) {
    std::cout << "Error: Could not open file " << filename << std::endl;
    return 1;
  }
  std::ofstream output_file(filename + ".replace");
  if (!output_file) {
    std::cout << "Error: Could not open file " << filename << std::endl;
    return 1;
  }

  std::string oneline;
  std::string tmp;
  std::string output;
  size_t find;
  size_t pos;

  while (std::getline(input_file, oneline)) {
    tmp = oneline;
    pos = 0;
    output = "";
    while (1) {
      find = tmp.find(s1);
      if (find == std::string::npos) {
        output += tmp;
        break;
      }
      output += oneline.substr(pos, find) + s2;
      pos += find + s1.length();
      tmp = oneline.substr(pos);
    }
    output_file << output << '\n';
  }

  input_file.close();
  output_file.close();
  return 0;
}