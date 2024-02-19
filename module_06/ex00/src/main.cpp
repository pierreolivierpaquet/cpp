/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:40:48 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/19 15:09:01 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CastConversion.hpp"

void	test( int ac, char **av, std::string conversion ) {
	( void )ac;
	( void )av;

	Conversion Test( conversion );
	Test.printConvertedSet();
	return ;
}

void	convert( int ac, char **av) {
	if (ac == 2){
		Conversion Test( av[ 1 ] );
		Test.printConvertedSet();
	} else {
		std::cout	<< "\033[1;31merror\033[0m: Only one (1) argument is accepted." << std::endl;
	}
		return ;
}

int	main( int argc, char **argv ) {
	
	// convert( argc, argv);
	
//	Errors. --------------------------------------------------------------------
	// test( argc, argv, "" );
	// test( argc, argv, "+.f" );
	// test( argc, argv, ".f" );
	// test( argc, argv, "-+" );
	// test( argc, argv, "+-++-0.43+f" );
	// test( argc, argv, "4.43+f" );
	// test( argc, argv, ".43+f" );
	// test( argc, argv, "   777.434235f   " );
	// test( argc, argv, "[]" );
	// test( argc, argv, "1.2.3" );
	// test( argc, argv, "123.456.f" );
	// test( argc, argv, "24678257456.34634d" );
	// test( argc, argv, "-+++++----++++-+-+++--+-" );
	// test( argc, argv, "-45.+");
	// test( argc, argv, "-12.34ff" );

	// test( argc, argv, "inf" );
	// test( argc, argv, " +inf" );

//	CHARACTER ------------------------------------------------------------------
	// test( argc, argv, "H" );
	// test( argc, argv, "[" );
	// test( argc, argv, "." );
	// test( argc, argv, "f" );
	// test( argc, argv, "\\" );

//	INTEGER --------------------------------------------------------------------
	// test( argc, argv, "0" );
	// test( argc, argv, "127" );
	// test( argc, argv, "-1" );
	// test( argc, argv, "-1234" );

	// test( argc, argv, "2147483647" ); // INT_MAX
	// test( argc, argv, "2147483648" ); // INT_MAX Overflow
	// test( argc, argv, "-2147483648" ); // INT_MIN
	// test( argc, argv, "-2147483649" ); // INT_MIN Overflow

//	FLOAT ----------------------------------------------------------------------
	// test( argc, argv, "2147483648.0f" ); // (INT_MAX Overflow) OK
	// test( argc, argv, "-2147483649.0f" ); // (INT_MIN Overflow) OK
	// test( argc, argv, "24678257456.34634f" );
	// test( argc, argv, "340282346638528859811704183484516925440.000000f" ); // Float MAX
	// test( argc, argv, "440282346638528859811704183484516925440.000000f" ); // Float MAX Overflow
	test( argc, argv, "17976931348623157081452742373170435679807056752584499659891747680315726078002853876058955863276687817154045895351438246423432132688946418276846754670353751698604991057655128207624549009038932894407586850845513394230458323690322294816580855933212334827479782620414472316873817718091929988125040402618412485836899999.f" );
//	DOUBLE ---------------------------------------------------------------------

	// test( argc, argv, "2147483648.0" );

//	PSEUDO ---------------------------------------------------------------------
	// test( argc, argv, "+inf" );
	// test( argc, argv, "-inf" );
	// test( argc, argv, "+inff" );
	// test( argc, argv, "-inff" );
	// test( argc, argv, "nan");
	// test( argc, argv, "nanf" );

	return ( EXIT_SUCCESS );
}
