/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:13:56 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/28 11:40:57 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

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

void	test_demi( void ) {
	print_separator( "DEMI - 1 STRING ARRAY" );
	
	std::string	array[ 10 ] = {
		"ZERO",
		"ONE",
		"TWO",
		"THREE",
		"FOUR",
		"FIVE",
		"SIX",
		"SEVEN",
		"EIGHT",
		"NINE" };
	
	std::cout	<< "\t\t\t\t[ ORIGINAL STRING ARRAY ]" << std::endl;
	iter( array, 10, ::print_output );
	
//	Iterates throught the array starting at the 6th element, replaces
//	the element by 42.
	iter( &array[ 5 ], 10 * 0.5 - 1, ft_fourtytwo<std::string> );
	std::cout	<< "\t\t\t\t[ AFTER FT_FOURTYTWO() ITERATION ]" << std::endl;
	iter( array, 10, print_output );

	return ;
}

void	test_int( void ) {
	print_separator( "INTEGER" );
	int	digits[ 13 ] = {
		13, 14, 15, 16, 17, 18, 19,
		20, 21, 22, 23, 24, 666 };

	std::cout	<< "\t\t\t\t[ ORIGINAL INT ARRAY ]" << std::endl;
	iter( digits, 13, print_output );
	
	std::cout	<< SEPARATOR << std::endl;
	
//	Iterates throught the array and replaces the element by 42.
	iter( digits, 13, ft_fourtytwo<int> );
	std::cout	<< "\t\t\t\t[ AFTER FT_FOURTYTWO() ITERATION ]" << std::endl;
	iter( digits, 13, print_output );
	return ;
}

/// ------------------------------------------------------------------------ ///

int	main( int argc, char **argv ) {
	static_cast< void >( argc );
	static_cast< void >( argv );

	test_demi();
	test_int();

	return	EXIT_SUCCESS;
}
