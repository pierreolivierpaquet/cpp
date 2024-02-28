/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:07:14 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/28 07:55:16 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/whatever.hpp"

#ifndef		SEPARATOR
# define	SEPARATOR \
"------------------------------------------------------------------------------"
#endif	/*	SEPARATOR	*/

/// ------------------------------------------------------- @section TEST UTIL.S

template < class U >
void	tpp_print( std::string msgA, const U &A, std::string msgB, const U &B ) {
	std::cout << msgA << A << "\n" << msgB << B << std::endl;
	return ;
}

void	print_separator( std::string title ) {
	std::cout	<< SEPARATOR << "[ \033[1;38;5;208m"
				<< title
				<< "\033[0m ]" << std::endl;
	return ;
}

/// ------------------------------------------------------------ @section TEST.S

void	test_int( int a, int b ) {
	print_separator( "INTEGER" );
	const int min = ::min< int >( a, b );
	const int max = ::max< int >( a, b );

	tpp_print( "INT 'A': ", a, "INT 'B': ", b );
	tpp_print( "INT MIN: ", min, "INT MAX: ", max );

	::swap( a, b );

	tpp_print( "SWAPPED INT 'A': ", a, "SWAPPED INT 'B': ", b );

	return ;
}

void	test_string( std::string a, std::string b ) {
	print_separator( "STRING" );
	const std::string min = ::min< std::string >( a, b );
	const std::string max = ::max< std::string >( a, b );

	tpp_print( "STRING 'A': ", a, "STRING 'B': ", b );
	tpp_print( "STRING MIN: ", min, "STRING MAX: ", max );

	::swap( a, b );

	tpp_print( "SWAPPED STRING 'A': ", a, "SWAPPED STRING 'B': ", b );

	return ;
}

void	test_float( float a, float b ) {
	print_separator( "FLOAT" );
	const float	min = ::min< float >( a, b );
	const float	max = ::max< float >( a, b );

	tpp_print< float >( "FLOAT 'A': ", a, "FLOAT 'B': ", b );
	tpp_print< float >( "FLOAT MIN: ", min, "FLOAT MAX: ", max );

	::swap( a, b );

	tpp_print( "SWAPPED FLOAT 'A': ", a, "SWAPPED FLOAT 'B': ", b );

	return ;
}

/// @brief Test provided in the pdf.
void	test_pdf( void ) {
	print_separator( "PDF" );

	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return ;
}

///--------------------------------------------------------------------------///

int main ( int argc, char **argv) {
	static_cast<void>( argc );
	static_cast<void>( argv );

	test_pdf();

	test_float( 1.11f, 9.99f );
	test_string( "+A", "-A" );
	test_int( INT_MIN, INT_MAX );

	return (0);
}
