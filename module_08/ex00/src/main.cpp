/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:13:59 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/06 11:59:03 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

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

void	test_vector( int to_find ) {
	print_separator( "VECTOR CONTAINER" );
	int digits[] = { 1, 12, 22, 32, 42, 52, 62, 72, 82, 92 };
	// std::vector<int> vec( &digits[ 0 ], &digits[ 9 ] );
	std::vector<int> vec( digits, digits + (sizeof( digits ) / sizeof( int )) );
	// std::vector<int>::const_iterator it;
	
	// it = vec.begin();
	std::vector<int>::const_iterator found;
	try {
		found = easyfind( vec, 42 );
		std::cout	<< "'" << *found << "' "
					<< "\033[1;32mfound\033[0m within \033[1;34mvector\033[0m."
					<< std::endl;
	} catch ( ElementNotFound &ex ) {
		std::cout << ex.what() << std::endl;
	};
	try {
		found = easyfind( vec, to_find );
		std::cout	<< "'" << *found << "' "
					<< "\033[1;32mfound\033[0m within \033[1;34mvector\033[0m."
					<< std::endl;
	} catch ( ElementNotFound &ex ) {
		std::cout << ex.what() << std::endl;
	};
	vec.push_back( to_find );
	std::cout	<< "\t*** '" << to_find << "' "
				<< "added to the container ***" << std::endl;
	try {
		found = easyfind( vec, to_find );
		std::cout	<< "'" << *found << "' "
					<< "\033[1;32mfound\033[0m within \033[1;34mvector\033[0m."
					<< std::endl;
	} catch ( ElementNotFound &ex ) {
		std::cout << ex.what() << std::endl;
	};
	return ;
}

void	test_list( int to_find ) {
	print_separator( "LIST CONTAINER" );
	int	digits[] = { -11, 11, 22, 33, 44, 55, 66, 77, 88, 99, 1010, 1111 };
	std::list<int>	lst( digits, digits + ( sizeof( digits ) / sizeof( int ) ) );

	std::list<int>::const_iterator found;
	try {
		found = easyfind( lst, -11 );
		std::cout	<< "'" << *found << "' "
					<< "\033[1;32mfound\033[0m within \033[1;34mlist\033[0m."
					<< std::endl;
	} catch ( ElementNotFound &ex ) {
		std::cout << ex.what() << std::endl;
	};
	try {
		found = easyfind( lst, to_find );
		std::cout	<< "'" << *found << "' "
					<< "\033[1;32mfound\033[0m within \033[1;34mlist\033[0m."
					<< std::endl;
	} catch ( ElementNotFound &ex ) {
		std::cout << ex.what() << std::endl;
	};
	lst.push_back( to_find );
	std::cout	<< "\t*** '" << to_find << "' "
				<< "added to the container ***" << std::endl;
	try {
		found = easyfind( lst, to_find );
		std::cout	<< "'" << *found << "' "
					<< "\033[1;32mfound\033[0m within \033[1;34mlist\033[0m."
					<< std::endl;
	} catch ( ElementNotFound &ex ) {
		std::cout << ex.what() << std::endl;
	};
	return ;
}

// void	test_array( int to_find ) {
// 	print_separator( "ARRAY CONTAINER" );
// 	std::array<int, 8> arr = { -321, -123, 123, 321, 1234, 4321, 8765, 0 };

// 	std::array<int, 8>::const_iterator found;
// 	try {
// 		found = easyfind( arr, 4321 );
// 		std::cout	<< "'" << *found << "' "
// 					<< "\033[1;32mfound\033[0m within \033[1;34marray\033[0m."
// 					<< std::endl;
// 	} catch ( ElementNotFound &ex ) {
// 		std::cout << ex.what() << std::endl;
// 	};
// 	try {
// 		found = easyfind( arr, to_find );
// 		std::cout	<< "'" << *found << "' "
// 					<< "\033[1;32mfound\033[0m within \033[1;34marray\033[0m."
// 					<< std::endl;
// 	} catch ( ElementNotFound &ex ) {
// 		std::cout << ex.what() << std::endl;
// 	};
// 	arr[7] = to_find;
// 	std::cout	<< "\t*** '" << to_find << "' "
// 				<< "added to the container ***" << std::endl;
// 	try {
// 		found = easyfind( arr, to_find );
// 		std::cout	<< "'" << *found << "' "
// 					<< "\033[1;32mfound\033[0m within \033[1;34marray\033[0m."
// 					<< std::endl;
// 	} catch ( ElementNotFound &ex ) {
// 		std::cout << ex.what() << std::endl;
// 	};
// 	return ;
// }

/// -------------------------------------------------------------- @section MAIN

int	main( int argc, char **argv ) {
	static_cast<void>( argc );
	static_cast<void>( argv );
	
	test_vector( 102 );
	test_list( 2222 );
	// test_array( 55 );

	return ( EXIT_SUCCESS );
}
