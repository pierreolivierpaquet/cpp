/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:40:48 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/13 14:47:58 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CastConversion.hpp"

#ifndef		EXIT_SUCCESS
# define	EXIT_SUCCESS	0
#endif	/*	EXIT_SUCCESS	*/

int	main( int argc, char **argv ) {
	( void ) argc;
	( void ) argv;

	// Conversion Test( "+.f" ); // OK FALSE
	// Conversion Test( ".f" ); // OK FALSE
	Conversion Test( "+-++-0.f" ); // TRUE FLOAT
	// Conversion Test( "+-++-0.43+f" ); // OK FALSE
	// Conversion Test( "4.43+f" ); // OK FALSE
	// Conversion Test( ".43+f" ); // OK FALSE
	// Conversion Test( "   777.434235f   " ); // OK FALSE

	return ( EXIT_SUCCESS );
}
