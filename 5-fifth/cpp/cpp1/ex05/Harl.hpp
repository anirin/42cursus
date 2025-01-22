#ifndef _HARL_H_
#define _HARL_H_

#include <iostream>
#include <string>

class Harl {
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	public:
		void complain( std::string level ); 
};

typedef void(Harl::*FuncLevel)(void);

#endif