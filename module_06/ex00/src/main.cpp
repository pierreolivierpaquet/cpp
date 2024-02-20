/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:40:48 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/20 12:34:35 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CastConversion.hpp"

#ifndef		SEPARATOR
# define	SEPARATOR	\
"------------------------------------------------------------------------------"
#endif	/*	SEPARATOR	*/

#ifndef		STOP_DELIM
# define	STOP_DELIM	"__STOP__"
#endif	/*	STOP_DELIM	*/

#ifndef		TEST_AMOUNT
# define	TEST_AMOUNT	25
#endif	/*	TEST_AMOUNT	*/

/******************************************************************************/

void	printout( std::string out, bool nl = true ) {
	std::cout	<< out;
	if (nl){
		std::cout	<< std::endl;
	}
	return ;
}

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
		std::cout	<< "\033[1;31merror\033[0m: Only one (1) argument is accepted."
					<< std::endl;
	}
		return ;
}

/******************************************************************************/

void	tests_main( int ac, char **av ) {
	( void )ac;
	( void )av;
	printout( "\n[\033[1;32m MAIN TESTS \033[0m]\n" );

	std::size_t i = 0;
	std::string to_convert[ TEST_AMOUNT ] = {
		"0",
		"nan",
		"42.0f", STOP_DELIM };
	while ( to_convert[ i ].compare( STOP_DELIM ) != 0 && \
			i < TEST_AMOUNT ){
		printout( static_cast<std::string>(SEPARATOR) \
				+ " \"\033[38;5;208m" + to_convert[ i ] + "\033[0m\"" );
		test( ac, av, to_convert[ i ] );
		i++;
	}
	return ;
}

/******************************************************************************/

void	tests_error( int ac, char **av) {
	( void )ac;
	( void )av;
	printout( "\n[\033[1;31m ERROR TESTS \033[0m]\n" );

	std::size_t i = 0;
	std::string to_convert[ TEST_AMOUNT ] = {
		"",
		"+.f",
		".f",
		"-+",
		"+-++-0.43+f",
		"4.43+f",
		".43+f",
		"   777.434235f   ",
		"[]",
		"1.2.3",
		"123.456.f",
		"24678257456.34634d",
		"-+++++----++++-+-+++--+-",
		"-45.+",
		"-12.34ff",
		"inf",
		" +inf",
		STOP_DELIM };
	while ( to_convert[ i ].compare( STOP_DELIM ) != 0 && \
			i < TEST_AMOUNT ){
		printout( static_cast<std::string>(SEPARATOR) \
				+ " \"\033[38;5;208m" + to_convert[ i ] + "\033[0m\"" );
		test( ac, av, to_convert[ i ] );
		i++;
	}
	return ;
}

/******************************************************************************/

void	tests_character( int ac, char **av ) {
	( void )ac;
	( void )av;
	printout( "\n[\033[1;32m CHARACTER TESTS \033[0m]\n" );

	std::size_t i = 0;
	std::string to_convert[ TEST_AMOUNT ] = {
		"H",
		"[",
		".",
		"f",
		"\\",
		"\"",
		STOP_DELIM };
	while ( to_convert[ i ].compare( STOP_DELIM ) != 0 && \
			i < TEST_AMOUNT ){
		printout( static_cast<std::string>(SEPARATOR) \
				+ " \"\033[38;5;208m" + to_convert[ i ] + "\033[0m\"" );
		test( ac, av, to_convert[ i ] );
		i++;
	}
	return ;
}

/******************************************************************************/

void	tests_integer( int ac, char **av ) {
	( void )ac;
	( void )av;
	printout( "\n[\033[1;32m INTEGER TESTS \033[0m]\n" );

	std::size_t i = 0;
	std::string to_convert[ TEST_AMOUNT ] = {
		"42",
		"-42",
		"127",
		"-1",
		"-1234",
		"2147483647",/* INT_MAX */
		"2147483648",/* INT_MAX Overflow */
		"-2147483648",/* INT_MIN */
		"-2147483649",/* INT_MIN Overflow */
		STOP_DELIM };
	while ( to_convert[ i ].compare( STOP_DELIM ) != 0 && \
			i < TEST_AMOUNT ){
		printout( static_cast<std::string>(SEPARATOR) \
				+ " \"\033[38;5;208m" + to_convert[ i ] + "\033[0m\"" );
		test( ac, av, to_convert[ i ] );
		i++;
	}
	return ;
}

/******************************************************************************/

void	tests_pseudo( int ac, char **av ) {
	( void )ac;
	( void )av;
	printout( "\n[\033[1;32m PSEUDO TESTS \033[0m]\n" );

	std::size_t i = 0;
	std::string to_convert[ TEST_AMOUNT ] = {
		"+inf",
		"-inf",
		"+inff",
		"-inff",
		"nan",
		"nanf",
		STOP_DELIM };
	while ( to_convert[ i ].compare( STOP_DELIM ) != 0 && \
			i < TEST_AMOUNT ){
		printout( static_cast<std::string>(SEPARATOR) \
				+ " \"\033[38;5;208m" + to_convert[ i ] + "\033[0m\"" );
		test( ac, av, to_convert[ i ] );
		i++;
	}
	return ;
}

/******************************************************************************/

void	tests_float( int ac, char **av ) {
	( void )ac;
	( void )av;
	printout( "\n[\033[1;32m FLOAT TESTS \033[0m]\n" );

	std::size_t i = 0;
	std::string to_convert[ TEST_AMOUNT ] = {
		"-4.2f",
		"4.2f",
		"42.2f",
		"2147483648.0f",/* INT_MAX Overtflow : OK */
		"-2147483649.0f",/* INT_MIN Overflow : OK */
		"24678257456.34634f",
		"340282346638528859811704183484516925440.000000f",/* FLOAT "MAX" */
		"440282346638528859811704183484516925440.000000f",/* FLOAT "MAX" Overflow */
		"-340282346638528859811704183484516925440.000000f",/* FLOAT "MIN" */
		"-440282346638528859811704183484516925440.000000f",/* FLOAT "MIN" Overflow */
		STOP_DELIM };
	while ( to_convert[ i ].compare( STOP_DELIM ) != 0 && \
			i < TEST_AMOUNT ){
		printout( static_cast<std::string>(SEPARATOR) \
				+ " \"\033[38;5;208m" + to_convert[ i ] + "\033[0m\"" );
		test( ac, av, to_convert[ i ] );
		i++;
	}
	return ;
}

/******************************************************************************/

void	tests_double( int ac, char **av ) {
	( void )ac;
	( void )av;
	printout( "\n[\033[1;32m DOUBLE TESTS \033[0m]\n" );

	std::size_t i = 0;
	std::string to_convert[ TEST_AMOUNT ] = {
		"-4.2",
		"4.2",
		"42.0",
		"9999.0",
		"123456.0", 
		"9876.54321", 
		"2147483648.0",
		"440282346638528859811704183484516925440.000000",/* (Float MAX Overflow) : OK */
		"-440282346638528859811704183484516925440.000000",/* (Float MIN Overflow) : OK */
		STOP_DELIM };
	while ( to_convert[ i ].compare( STOP_DELIM ) != 0 && \
			i < TEST_AMOUNT ){
		printout( static_cast<std::string>(SEPARATOR) \
				+ " \"\033[38;5;208m" + to_convert[ i ] + "\033[0m\"" );
		test( ac, av, to_convert[ i ] );
		i++;
	}
	return ;
}

/******************************************************************************/

void	tests_all( int ac, char **av ) {
	tests_main(			ac, av );
	tests_pseudo(		ac, av );
	tests_error(		ac, av );
	tests_character(	ac, av );
	tests_integer(		ac, av );
	tests_float(		ac, av );
	tests_double(		ac, av );
}

/******************************************************************************/

int	main( int argc, char **argv ) {

	convert( argc, argv);
	// tests_all( argc, argv );

	return ( EXIT_SUCCESS );
}
