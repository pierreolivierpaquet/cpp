/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:13:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 20:11:06 by ppaquet          ###   ########.fr       */
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

static void	test_formGradeTooHigh( void ) {
	test_separator( "START - FORM GRADE TOO HIGH" );
	try{
		Form	invalid_a( 0, 1 );
	}
	catch (Form::GradeTooHighException &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("1");
	try{
		Form	invalid_b( 1, 0 );
	}
	catch (Form::GradeTooHighException &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("2");
	try{
		Form	invalid_c( 0, 0 );
	}
	catch (Form::GradeTooHighException &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("3");
	try{
		Form	invalid_d("FooForm", -100, -100 );
	}
	catch (Form::GradeTooHighException &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - FORM GRADE TOO HIGH" );
	return ;
}

static void	test_formGradeTooLow( void ) {
	test_separator( "START - FORM GRADE TOO LOW" );
	try{
		Form	invalid_a( 151, 150 );
	}
	catch (Form::GradeTooLowException &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("1");
	try{
		Form	invalid_b( 150, 151 );
	}
	catch (Form::GradeTooLowException &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator("2");
	try{
		Form	invalid_c( 151, 151 );
	}
	catch (Form::GradeTooLowException &e) {
		std::cout	<< e.what() << std::endl;
	}
		test_separator("3");
	try{
		Form	invalid_d("FooForm", 1000, 1000 );
	}
	catch (Form::GradeTooLowException &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - FORM GRADE TOO LOW" );
}

static void	test_can_sign( void ) {
	test_separator( "START - CAN SIGN" );
	try{
		Bureaucrat	John( "John", 42 );
		std::cout	<< John << std::endl;
		Form		random_form( "Random Action", 142, 42 );
		std::cout	<< random_form << std::endl;
		
		John.signForm( random_form );
		std::cout	<< random_form << std::endl;
	}
	catch (Form::GradeTooLowException &e){
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - CAN SIGN" );
	return ;	
}

static void	test_cannot_sign( void ) {
	test_separator( "START - CANNOT SIGN" );
	try{
		Bureaucrat	John( "John", 43 );
		std::cout	<< John << std::endl;
		Form		random_form( "Random Action", 142, 42 );
		std::cout	<< random_form << std::endl;

		John.signForm( random_form );
		std::cout	<< random_form << std::endl;
	}
	catch (Form::GradeTooLowException &e){
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - CANNOT SIGN" );
	return ;
}

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	test_formGradeTooHigh();
	test_formGradeTooLow();

	test_can_sign();
	test_cannot_sign();

	return ( EXIT_SUCCESS );
}
