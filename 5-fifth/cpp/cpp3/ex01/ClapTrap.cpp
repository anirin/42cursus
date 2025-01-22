#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() : name_(""), hit_points_(10), energy_points_(10), attack_damage_(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name_(name), hit_points_(10), energy_points_(10), attack_damage_(0) {
	std::cout << "Name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src) {
	name_ = src.name_;
	hit_points_ = src.hit_points_;
	energy_points_ = src.energy_points_;
	attack_damage_ = src.attack_damage_;
	std::cout << "Copy constructor called" << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap& ClapTrap::operator=(ClapTrap const& rhs) {
	if (this != &rhs) {
		this->name_ = rhs.name_;
		this->hit_points_ = rhs.hit_points_;
		this->energy_points_ = rhs.energy_points_;
		this->attack_damage_ = rhs.attack_damage_;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::attack(const std::string& target) {
	if (hit_points_ == 0) {
		std::cout << name_ << " has dead!!" << std::endl;
		return;
	}
	if (energy_points_ == 0) {
		std::cout << name_ << " has no energy!!" << std::endl;
		return;
	}

	std::cout << name_ << " attacks " << target << ", causing " << attack_damage_ << " points of damage!" << std::endl;
	--energy_points_;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (hit_points_ == 0) {
		std::cout << name_ << " has dead!!" << std::endl;
		return;
	}

	if (amount >= hit_points_) {
		hit_points_ = 0;
		std::cout << name_ << " takes " << amount << " points of damage and dies!" << std::endl;
	} else {
		hit_points_ -= amount;
		std::cout << name_ << " takes " << amount << " points of damage!" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (hit_points_ == 0) {
		std::cout << name_ << " has dead!!" << std::endl;
		return;
	}
	if (energy_points_ == 0) {
		std::cout << name_ << " has no energy!!" << std::endl;
		return;
	}
	std::cout << name_ << " has repaired " << amount << " points of hit points!" << std::endl;
	hit_points_ += amount;
	--energy_points_;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */