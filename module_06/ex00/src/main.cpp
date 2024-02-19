/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:40:48 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/19 09:20:07 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CastConversion.hpp"

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
	// Conversion Test( "17976931348623157081452742373170435679807056752584499659891747680315726078002853876058955863276687817154045895351438246423432132688946418276846754670353751698604991057655128207624549009038932894407586850845513394230458323690322294816580855933212334827479782620414472316873817718091929988125040402618412485836899999.f" );
	// Conversion Test( "2147483648999465874655563569.87878f" );
	Conversion Test( "34.34.0f" );
	Test.printConvertedSet();
	return ( EXIT_SUCCESS );
}
