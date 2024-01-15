/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:40:43 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/15 14:26:06 by ppaquet          ###   ########.fr       */
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
	
	std::cout << a.getRawBits_() << std::endl;
	std::cout << b.getRawBits_() << std::endl;
	std::cout << c.getRawBits_() << std::endl;

	return ( 0 );
}
