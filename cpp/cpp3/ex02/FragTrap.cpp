#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap() : ClapTrap() {
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name) {
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
	std::cout << "FragTrap name constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap& FragTrap::operator=(FragTrap const& rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		std::cout << "ScavTrap assignation operator called" << std::endl;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys() {
	std::cout << "High Five Guys!!" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */