/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:59:05 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 08:59:02 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Identity.hpp"

void	randomized_test( void ) {
	Base *ptr = idt::generate();
	idt::identify( ptr );
	delete ptr;
	return ;
}

/******************************************************************************/

void	fixed_reference_test( void ) {
	std::cout << "---------------------------------------- [ Derived A 'Baa' ]" << std::endl;
	A		Baa;
	Base	&Bara = Baa;

	idt::identify( Bara );
	std::cout << std::endl;

	std::cout << "---------------------------------------- [ Derived B 'Bbb' ]" << std::endl;
	B		Bbb;
	Base	&Barb = Bbb;

	idt::identify( Barb );
	std::cout << std::endl;

	std::cout << "---------------------------------------- [ Derived B 'Bcc' ]" << std::endl;
	C		Bcc;
	Base	&Barc = Bcc;

	idt::identify( Barc );
	std::cout << std::endl;

	return ;
}

void	not_found_test( void ) {
	Base	one;
	Base	*one_ptr = &one;

	idt::identify( one_ptr );

	Base two;
	idt::identify(two);
	
	return ;
}

/******************************************************************************/

int	main( int argc, char **argv ) {

	static_cast<void>( argc );
	static_cast<void>( argv );

	randomized_test();
	// fixed_reference_test();
	// not_found_test();

	return ( EXIT_SUCCESS );
}
