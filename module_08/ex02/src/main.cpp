/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 08:25:59 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/05 12:55:24 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"

int	main ( int argc, char **argv ) {
	static_cast< void >( argc );
	static_cast< void >( argv );

	typedef MutantStack< int, std::deque<int> > Mutant;

	Mutant test;

	test.push(1);
	test.push(2);
	test.push(3);
	test.push(4);
	test.push(5);
	test.push(6);

	Mutant::iterator it;
	for (it = test.begin(); it != test.end(); it++){
		std::cout << *it << std::endl;
	}

	return ( EXIT_SUCCESS ) ;
}
