#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Data
{

	public:

		Data();
		Data( Data const & src );
		~Data();

		Data &		operator=( Data const & rhs );

	private:

};

#endif /* ************************************************************ DATA_H */