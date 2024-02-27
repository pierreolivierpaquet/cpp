#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

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

void	test_int( void ) {
	print_separator( "INTEGER ARRAY" );
//	Tests the default constructor.
	Array<int> empty;

	std::cout	<< "EMPTY Default constructor: " << empty.getElement() << std::endl;

//	Tests the parameterized constructor.
	Array<int>	test( 9 );
	for (int i = 0; i < 9; i++)
    {
        const int value = rand() % 10;
        test[i] = value;
    }

    Array<int>	numbers(10);
    for (int i = 0; i < 10; i++)
    {
        const int value = rand() % 25;
        numbers[i] = value;
    }

//	Tests the overload assignation operands.
	test = numbers;

//	Tests the overload [] operand.
	test[ 3 ] = 666;
	std::cout << "test at index 3: " << test[ 3 ] << std::endl;
	std::cout << numbers[ 3 ] << std::endl;

//  Tests the exception.
	try {
		test[ 10 ] = 666;
		std::cout << "test at index 10: " << test[ 10 ] << std::endl;
	} catch ( std::exception &e ){
		std::cout << e.what() << std::endl;
	}
	try {
		test[ 11 ] = 666;
		std::cout << "test at index 11: " << test[ 11 ] << std::endl;
	} catch ( std::exception &e ){
		std::cout << e.what() << std::endl;
	}
	return ;
}

void	test_string( void ) {
	std::string test[4] = {"ONE", "TWO", "THREE", "FOUR"};

	print_separator( "STRING ARRAY" );
	Array<std::string> Foo;

	Array<std::string> Bar( 4 );
	try {
		Bar[ 3 ] = test[ 0 ];
		Bar[ 2 ] = test[ 1 ];
		Bar[ 1 ] = test[ 2 ];
		Bar[ 0 ] = test[ 3 ];
	} catch ( Array<std::string>::BadArrayIndex &bad ) {
		std::cout	<< bad.what() << std::endl;
	}
	for (size_t i = 0; i < 4; i++){
		std::cout	<< Bar[ i ] << std::endl;
	}
	try {
		Bar[ 4 ] = test[ 2 ];
	} catch ( Array<std::string>::BadArrayIndex &bad ) {
		std::cout	<< bad.what() << std::endl;
	}
	Foo = Bar;
	try {
		Foo[ 3 ] = "********";
		Foo[ 2 ] = "********";
	} catch ( Array<std::string>::BadArrayIndex &bad ) {
		std::cout	<< bad.what() << std::endl;
	}
	for (size_t i = 0; i < 4; i++){
		std::cout	<< "FOO: " << Foo[ i ] << std::endl;
		std::cout	<< "BAR: " << Bar[ i ] << std::endl;
	}
	return ;
}

void	test_pdf( void ) {
	print_separator( "PDF main()" );
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return ;
}

/// ------------------------------------------------------------------------ ///

int main( int, char ** ) {

//	random seed.
	srand( time( NULL ) );

	test_int();
	test_string();

	test_pdf();

	return EXIT_SUCCESS;
}
