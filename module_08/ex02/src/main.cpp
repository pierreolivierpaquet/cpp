/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:25:59 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/19 14:45:58 by ppaquet          ###   ########.fr       */
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
	std::cout << "\t\t\t\t\t\t\t\t\t\033[1mMUTANT\033[0m" << std::endl;
	typedef MutantStack< int > Mutant;
	
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

	// std::deque<int>::iterator it = mstack.begin(); // **typedef added to class.
	// std::deque<int>::iterator ite = mstack.end(); // **typedef added to class.
	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();
	Mutant::iterator it = mstack.begin();
	Mutant::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite){
	std::cout << *it << std::endl;
	++it;
	}

	std::stack<int> s(mstack);
	return ;
}

void	test_list( void ) {
	print_sep();
	std::cout << "\t\t\t\t\t\t\t\t\t\033[1mLIST\033[0m" << std::endl;
	typedef std::list< int > Alternate;

	Alternate  lst;
	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);

	lst.push_back(0);

	Alternate::iterator it2 = lst.begin();
	Alternate::iterator ite2 = lst.end();

	++it2;
	--it2;

	while (it2 != ite2){
	std::cout << *it2 << std::endl;
	++it2;
	}

	return ;
}

void	test_string_list( void ) {
	print_sep( "MUTANTSTACK - STRING - LIST" );
	typedef MutantStack< std::string, std::list<std::string> > Mutant;

	Mutant mstack;

	mstack.push( "1. First" );
	mstack.push( "2. Second" );
	mstack.push( "2. Third" );

	Mutant::iterator it1 = mstack.begin();
	Mutant::iterator ite1 = mstack.end();

	while (it1 != ite1){
		std::cout << *it1 << std::endl;
		it1++;
	}
	print_sep();
	for (it1 = mstack.begin(); it1 != ite1; it1++){
		*it1 = "* suppressed *";
	}

	for (it1 = mstack.begin(); it1 != ite1; it1++){
		std::cout << *it1 << std::endl;
	}
	print_sep();
	it1 = ++mstack.begin();
	*it1 = "123456789";
	it1--;

	Mutant::const_iterator c_it1 = mstack.begin();
	for (c_it1 = mstack.begin(); c_it1 != ite1; c_it1++){
		std::cout << *c_it1 << std::endl;
	}

	return ;
}

/******************************************************************************/

int	main ( int argc, char **argv ) {
	static_cast< void >( argc );
	static_cast< void >( argv );

	test_mutant();
	test_list();
	test_string_list();

	return ( EXIT_SUCCESS ) ;
}
