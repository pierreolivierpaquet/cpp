/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:25:59 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/05 14:59:00 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

#ifndef		SEP
# define	SEP \
"------------------------------------------------------------------------------"
#endif	/*	SEP	*/

void	print_sep( std::string title = "", bool nl = true) {
	std::cout << SEP ;
	if (title.size() != 0){
		std::cout << "[ \033[1;38;5;208m" << title << " \033[0m]";
	}
	if (nl == true){
		std::cout << std::endl;
	}
	return ;
}

/******************************************************************************/

void	test_mutant( void ) {
	print_sep( "MUTANTSTACK" );

	typedef MutantStack< int, std::deque<int> > Mutant;
	Mutant mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	mstack.push(0);

	Mutant::iterator it = mstack.begin();
	Mutant::iterator ite = mstack.end();
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite){
	std::cout << *it << std::endl;
	++it;
	}

	std::stack<int> s(mstack);
	return ;
}

/******************************************************************************/

int	main ( int argc, char **argv ) {
	static_cast< void >( argc );
	static_cast< void >( argv );

	test_mutant();

	return ( EXIT_SUCCESS ) ;
}
