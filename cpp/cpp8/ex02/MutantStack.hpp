#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >
{

	public:

		MutantStack();
		MutantStack( MutantStack const & src );
		~MutantStack();

		MutantStack &		operator=( MutantStack const & rhs );

		typedef typename std::deque<T>::iterator iterator;
		iterator begin();
		iterator end();

	private:

};


#endif /* ***************************************************** MUTANTSTACK_H */
