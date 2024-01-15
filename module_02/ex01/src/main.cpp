/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:35:19 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/15 16:16:15 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/// ---
/// @brief
/// 
int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt_() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt_() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt_() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt_() << " as integer" << std::endl;

	return ( 0 );
}
