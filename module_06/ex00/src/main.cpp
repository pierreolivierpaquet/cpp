/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:40:48 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/14 15:05:40 by ppaquet          ###   ########.fr       */
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
	// Conversion Test( "+-++-0.f" ); // TRUE FLOAT
	// Conversion Test( "+-++-0.43+f" ); // OK FALSE
	// Conversion Test( "4.43+f" ); // OK FALSE
	// Conversion Test( ".43+f" ); // OK FALSE
	// Conversion Test( "   777.434235f   " ); // OK FALSE
	
	// Conversion Test( "H" ); // OK CHAR
	// Conversion Test( "0" ); // OK INT
	// Conversion Test( "+--++---+-0245745363634236345653" ); // OK INT
	// Conversion Test( "246782456f" ); // OK FLOAT
	// Conversion Test( "24678257456.34634" );// OK DOUBLE
	// Conversion Test( "123456.34" );// OK DOUBLE
	// Conversion Test( "24678257456.34634d" ); // OK UNDEFINED
	// Conversion Test( "\\" ); // OK CHAR
	// Conversion Test( "-4" ); // OK INT
	// Conversion Test( "-+++++----++++-+-+++--+-" ); // OK ERROR
	// Conversion Test( "-45.+" ); // OK ERROR SAME FLAG AS OVER
	// Conversion Test( "-+" ); // OK ERROR SAME ERROR AS OVER
	// Conversion Test( "." ); // OK CHAR
	// Conversion Test( "+++.7652" ); // OK DOUBLE
	// Conversion Test( "+++.7652ff" ); // OK UNDEFINED
	// Conversion Test( "+inff" ); // OK UNDEFINED
	Conversion Test( "50+50" );

	return ( EXIT_SUCCESS );
}
