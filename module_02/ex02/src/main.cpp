/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:35:19 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/17 14:08:32 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl; // Is equal to 0.

	std::cout << ++a << std::endl; // Shows incremented value.
	std::cout << a << std::endl; // Shows value of a.
	std::cout << a++ << std::endl; // Shows a before incrementation.
	std::cout << a << std::endl; // Shows value of a.

	std::cout << b << std::endl;

	std::cout << Fixed::max_( a, b ) << std::endl;
	// std::cout << Fixed::min_( a, b ) << std::endl;

	// std::cout << "[ TEST ]\n" << std::endl;
	// Fixed one( 4 );

	// one = one / 2;
	// std::cout << one << std::endl;
	// one = one - 0.5f;
	// std::cout << one << std::endl;

	return ( 0 );
}
