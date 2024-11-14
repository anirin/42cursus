#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap() : ClapTrap() {
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name) {
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
	std::cout << "ScavTrap name constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& src) : ClapTrap(src) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap& ScavTrap::operator=(ScavTrap const& rhs) {
	if (this != &rhs) {
		ClapTrap::operator=(rhs);
		std::cout << "ScavTrap assignation operator called" << std::endl;
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ScavTrap::attack(const std::string& target) {
	if (hit_points_ == 0) {
		std::cout << name_ << " has dead!!" << std::endl;
		return;
	}
	if (energy_points_ == 0) {
		std::cout << name_ << " has no energy!!" << std::endl;
		return;
	}

	std::cout << "Scav " << name_ << " attacks " << target << ", causing " << attack_damage_ << " points of damage!" << std::endl;
	--energy_points_;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */