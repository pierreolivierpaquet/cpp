/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:55:02 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/06 12:05:22 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

#ifndef		SEP
# define	SEP \
"------------------------------------------------------------------------------"
#endif	/*	SEP	*/

void	print_sep( std::string title = "", bool nl = true) {
	std::cout << SEP ;
	if (title.size() != 0){
		std::cout << "[ \033[1;38;5;208m" << title << " \033[0m]";
	}
	if (nl == true){
		std::cout << std::endl;
	}
	return ;
}

/******************************************************************************/

void	test_pdf( void ) {
	print_sep( "PDF" );

	Span	test( 6 );
	test.addNumber( 6 );
	test.addNumber( 3 );
	test.addNumber( 17 );
	test.addNumber( 9 );
	test.addNumber( 11 );

	test.print();
	std::cout	<< "Shortest span\t=\t" << test.shortestSpan() << std::endl;
	std::cout	<< "Longest span\t=\t" << test.longestSpan() << std::endl;
	return ;
}

void	test_add_max_limit( void ) {
	print_sep( "ADDNUMBER - EXCEEDING" );
	// Span 	impossible; // Uncomment: Default constructor unreachable.
	Span	test( 10 );
	try {
		test.addNumber( 1 );
		test.addNumber( 2 );
		test.addNumber( 3 );
		test.addNumber( 4 );
		test.addNumber( 5 );
		test.addNumber( 6 );
		test.addNumber( 7 );
		test.addNumber( 8 );
		test.addNumber( 9 );
		test.addNumber( 10 );
		test.addNumber( 42 ); // Comment to bypass throw()
	} catch (Span::ExceedingNumber &e) {
		std::cout << e.what() << std::endl;
	}
	test.print();
	return ;
}

void	test_shortspan( void ) {
	print_sep( "SHORTSPAN" );
	Span	test1(10);
//	No number = exception throw()
	try {
		std::cout << "Shortest span\t=\t" << test1.shortestSpan() << std::endl;
	} catch (Span::NoSpan &e) {
		std::cout << e.what() << std::endl;
	}
	test1.addNumber( 42 );
	try {
		std::cout << test1.shortestSpan() << std::endl;
	} catch (Span::NoSpan &e) {
		std::cout << "Shortest span\t=\t" << e.what() << std::endl;
	}
	test1.addNumber( 84 );
	try {
		std::cout << "Shortest span\t=\t" << test1.shortestSpan() << std::endl;
	} catch (Span::NoSpan &e) {
		std::cout << e.what() << std::endl;
	}
	test1.addNumber( 43 );
	try {
		std::cout << "Shortest span\t=\t" << test1.shortestSpan() << std::endl;
	} catch (Span::NoSpan &e) {
		std::cout << e.what() << std::endl;
	}
	test1.addNumber( 84 );
	try {
		std::cout << "Shortest span\t=\t" << test1.shortestSpan() << std::endl;
	} catch (Span::NoSpan &e) {
		std::cout << e.what() << std::endl;
	}
	return ;
}

void	test_longspan( void ) {
	print_sep( "LONGSPAN" );

	Span test2( 10 );
	try {
		std::cout << "Longest span\t=\t" << test2.longestSpan() << std::endl;
	} catch (Span::NoSpan &e) {
		std::cout << e.what() << std::endl;
	}
	test2.addNumber( 42 );
	try {
		std::cout << "Longest span\t=\t" << test2.longestSpan() << std::endl;
	} catch (Span::NoSpan &e) {
		std::cout << e.what() << std::endl;
	}
	test2.addNumber( 42 );
	try {
		std::cout << "Longest span\t=\t" << test2.longestSpan() << std::endl;
	} catch (Span::NoSpan &e) {
		std::cout << e.what() << std::endl;
	}
	test2.addNumber( 84 );
	try {
		std::cout << "Longest span\t=\t" << test2.longestSpan() << std::endl;
	} catch (Span::NoSpan &e) {
		std::cout << e.what() << std::endl;
	}
	test2.addNumber( 0 );
	try {
		std::cout << "Longest span\t=\t" << test2.longestSpan() << std::endl;
	} catch (Span::NoSpan &e) {
		std::cout << e.what() << std::endl;
	}
	return ;
}

void	test_n_number( u_int32_t N ) {
	Span	test( N );
	try {
		test.addNumber( N, std::numeric_limits< int >::max() );
		test.print( "test_n_number.txt" );
		std::cout << "Longest span\t=\t" << test.longestSpan() << std::endl;
		std::cout << "Shortest span\t=\t" << test.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		test.addNumber( 42 );
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return ;
}

void	test_misc( void ) {
	print_sep( "MISCELLANEOUS" );

	Span	test( 10 );
	try {
		test.addNumber( 2 );
		test.addNumber( -10 );
		test.addNumber( 2 );
		test.addNumber( 3 );
		test.addNumber( 4 );
		test.addNumber( 5 );
		test.addNumber( 6 );
		test.addNumber( 7 );
		test.addNumber( 8 );
		test.addNumber( 9 );
	} catch (Span::ExceedingNumber &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span\t=\t" << test.longestSpan() << std::endl;
		std::cout << "Shortest span\t=\t" << test.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return ;
}

void	test_add_vector_iterator( void ) {
	print_sep( "ADDNUMBER - VECTOR ITERATOR" );
	int	arr[] = { 2, 12, 22, 32, 42, 52, 62, 72, 82, 92, 102, 112, 122, 132 };
	std::vector< int > vec( arr, arr + sizeof( arr ) / sizeof( int ) );

	Span	from_vec( sizeof( arr ) / sizeof( int ) );
	try {
		from_vec.addNumber< std::vector<int> >( vec.begin(), vec.end() );
		from_vec.print();
		std::cout << "Longest span\t=\t" << from_vec.longestSpan() << std::endl;
		std::cout << "Shortest span\t=\t" << from_vec.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		from_vec.addNumber( 4242 );
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return ;
}

void	test_add_list_iterator( void ) {
	print_sep( "ADDNUMBER - LIST ITERATOR" );
	int	arr[] = { 1, 11, 21, 31, 41, 51, 61, 71, 81, 91, 101, 111, 121, 131 };
	std::list< int >lst( arr, arr + sizeof( arr ) / sizeof( int ) );

	Span	from_lst( sizeof( arr ) / sizeof( int ) );
	from_lst.addNumber< std::list<int> >( lst.begin(), lst.end() );
	try {
		from_lst.print();
	std::cout << "Longest span\t=\t" << from_lst.longestSpan() << std::endl;
	std::cout << "Shortest span\t=\t" << from_lst.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return ;
}

void	test_add_partial_vector( void ) {
	print_sep( "ADDNUMBER - PARTIAL VECTOR" );
	int	arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
	std::vector< int > vec( arr, arr + sizeof( arr ) / sizeof( int ) );

	Span	from_vec( sizeof( arr ) / sizeof( int ) );
	std::vector< int >::const_iterator it;
	for (it = vec.begin(); it != vec.end(); it++)
	{
		if (*it == arr [ 5 ]){
			break ;
		}
	}
	try {
		from_vec.addNumber< std::vector<int> >( ++vec.begin(), it );
		from_vec.addNumber< std::vector<int> >( ++vec.begin(), it );
		from_vec.print();
		std::cout << "Longest span\t=\t" << from_vec.longestSpan() << std::endl;
		std::cout << "Shortest span\t=\t" << from_vec.shortestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return ;
}

/******************************************************************************/

int	main( int argc, char **argv ) {
	static_cast<void>( argc );
	static_cast<void>( argv );

	test_pdf();
	// test_misc();
	// test_add_max_limit();
	// test_shortspan();
	// test_longspan();
	// test_n_number( 10000 );
	// test_add_vector_iterator();
	// test_add_list_iterator();
	// test_add_partial_vector();

	return ( EXIT_SUCCESS );
}
