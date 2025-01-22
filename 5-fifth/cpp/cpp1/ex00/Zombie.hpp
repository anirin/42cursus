#ifndef ZOMBIE_HPP_
#define ZOMBIE_HPP_

#include <iostream>
#include <string>

class Zombie {
	private :
		std::string name_;
	public :
		Zombie(std::string);
		~Zombie();
		void anounce(void);
};

Zombie *newZombie( std::string name );
void randomChump( std::string name);

#endif