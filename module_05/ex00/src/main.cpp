/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 15:10:02 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 19:35:14 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

#ifndef		EXIT_SUCCESS
# define	EXIT_SUCCESS	0
#endif	/*	EXIT_SUCCESS	*/

#ifndef		SEPARATOR
# define	SEPARATOR	\
"------------------------------------------------------------------------------"
#endif	/*	SEPARATOR	*/

static void	test_separator( std::string message = "" ) {
	std::cout	<< SEPARATOR;
	if (message.length() > 0){
		std::cout << BOLD << "[ " << message << " ]" << RESET << std::endl;
	} else {
		std::cout << std::endl;
	}
	return ;
}

/// @brief	Throws a GradeTooHighException() for declaring a Bureaucrat
///			with invalid grade value.
/// @note	Destructors never get called after an exception has been thrown
///			from a constructor, since it's object does not exists yet.
/// @note	Constructor messages are called at the end of the methods.
static void	test_gradeTooHigh( void ) {
	test_separator( "START - GRADE TOO HIGH" );
	try {
		Bureaucrat	invalid_a;
		invalid_a.setGrade( 0 );
	}
	catch ( Bureaucrat::GradeTooHighException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("1");
	try {
		Bureaucrat invalid_b( 0 );
	}
	catch ( Bureaucrat::GradeTooHighException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("2");
	try {
		Bureaucrat invalid_c( "John Foo", -1 );
	}
	catch ( Bureaucrat::GradeTooHighException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("3");
	try {
		Bureaucrat invalid_d( "John Bar");
		invalid_d.setGrade( -100 );
	}
	catch ( Bureaucrat::GradeTooHighException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("4");
	try {
		Bureaucrat invalid_e( "Johnny FooBar", 1);
		Bureaucrat invalid_f( invalid_e );
		invalid_f.setGrade( -10 );
	}
	catch ( Bureaucrat::GradeTooHighException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - GRADE TO HIGH" );
	return ;
}

/// @brief	Throws a GradeTooLowException() exception for declaring a Bureaucrat
///			with invalid grade value.
static void	test_gradeTooLow( void ) {
	test_separator( "START - GRADE TOO LOW" );
	try {
		Bureaucrat	invalid_a;
		invalid_a.setGrade( 151 );
	}
	catch ( Bureaucrat::GradeTooLowException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("1");
	try {
		Bureaucrat invalid_b( 151 );
	}
	catch ( Bureaucrat::GradeTooLowException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("2");
	try {
		Bureaucrat invalid_c( "John Foo", 151 );
	}
	catch ( Bureaucrat::GradeTooLowException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("3");
	try {
		Bureaucrat invalid_d( "John Bar");
		invalid_d.setGrade( 200 );
	}
	catch ( Bureaucrat::GradeTooLowException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("4");
	try {
		Bureaucrat invalid_e( "Johnny FooBar", 150);
		Bureaucrat invalid_f( invalid_e );
		invalid_f.setGrade( 2000 );
	}
	catch ( Bureaucrat::GradeTooLowException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - GRADE TO LOW" );
	return ;
}

static void	test_incrementTooHigh( void ) {
	test_separator( "START - INCREMENT TOO HIGH" );
	try {
		Bureaucrat	increment_a( "John", 3 );
		std::cout	<< increment_a << std::endl;
		increment_a.incrementGrade();
		std::cout	<< increment_a << std::endl;
		increment_a.incrementGrade();
		std::cout	<< increment_a << std::endl;
		increment_a.incrementGrade();
	}
	catch ( Bureaucrat::GradeTooHighException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("1");
	try {
		Bureaucrat	increment_b( "John Foo", 50 );
		std::cout	<< increment_b << std::endl;
		increment_b.incrementGrade( 50 );
		std::cout	<< increment_b << std::endl;
	}
	catch ( Bureaucrat::GradeTooHighException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - INCREMENT TO HIGH" );
	return ;
}

static void	test_decrementTooLow( void ) {
	test_separator( "START - DECREMENT TOO LOW" );
	try {
		Bureaucrat	decrement_a( "John", 148 );
		std::cout	<< decrement_a << std::endl;
		decrement_a.decrementGrade();
		std::cout	<< decrement_a << std::endl;
		decrement_a.decrementGrade();
		std::cout	<< decrement_a << std::endl;
		decrement_a.decrementGrade();
	}
	catch ( Bureaucrat::GradeTooLowException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("1");
	try {
		Bureaucrat	decrement_b( "John Foo", 101 );
		std::cout	<< decrement_b << std::endl;
		decrement_b.decrementGrade( 50 );
		std::cout	<< decrement_b << std::endl;
	}
	catch ( Bureaucrat::GradeTooLowException &e ) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - DECREMENT TO LOW" );
	return ;
}

int	main ( int argc, char **argv ) {
	( void ) argc; 
	( void ) argv;

	test_gradeTooHigh();
	test_gradeTooLow();
	
	test_incrementTooHigh();
	test_decrementTooLow();

	return ( EXIT_SUCCESS );	
}
