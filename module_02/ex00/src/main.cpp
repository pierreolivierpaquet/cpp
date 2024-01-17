/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:40:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/17 10:26:37 by ppaquet          ###   ########.fr       */
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
	Fixed b( a );
	Fixed c;

	c = b;
	
	// a.setRawBits(123);
	// b.setRawBits(456);
	// c.setRawBits(789);
	
	std::cout << a.getRawBits_() << std::endl;
	std::cout << b.getRawBits_() << std::endl;
	std::cout << c.getRawBits_() << std::endl;

	return ( 0 );
}

