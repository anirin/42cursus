#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <iostream>
#include <string>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

class Zombie {
	private :
		std::string name_;
	public :
		Zombie();
		Zombie(std::string);
		~Zombie();
		void anounce(void);
		void set_name(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif