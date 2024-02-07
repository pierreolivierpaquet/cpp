/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:13:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 21:47:19 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

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

static void	test_shrubbery( void ) {
	test_separator( "START - SHRUBERRY" );
	try{
		Bureaucrat				Foo_a( "Foo_a", 145 );
		std::cout	<< Foo_a << std::endl;
		Bureaucrat				Bar_a( "Bar_a", 137 );
		std::cout	<< Bar_a << std::endl;
		ShrubberyCreationForm	RandomShrub_a( "Garden_a");
		std::cout	<< RandomShrub_a << std::endl;

		Foo_a.signForm( RandomShrub_a );
		Bar_a.executeForm( RandomShrub_a );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "not signed" );
	try{
		Bureaucrat				Foo_b( "Foo_b", 145 );
		std::cout	<< Foo_b << std::endl;
		Bureaucrat				Bar_b( "Bar_b", 137 );
		std::cout	<< Bar_b << std::endl;
		ShrubberyCreationForm	RandomShrub_b( "Garden_b");
		std::cout	<< RandomShrub_b << std::endl;

		Bar_b.executeForm( RandomShrub_b );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "too low to sign" );
	try{
		Bureaucrat				Foo_c( "Foo_c", 146 );
		std::cout	<< Foo_c << std::endl;
		Bureaucrat				Bar_c( "Bar_c", 137 );
		std::cout	<< Bar_c << std::endl;
		ShrubberyCreationForm	RandomShrub_c( "Garden_c");
		std::cout	<< RandomShrub_c << std::endl;

		Foo_c.signForm( RandomShrub_c );
		Bar_c.executeForm( RandomShrub_c );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "too low to execute" );
	try{
		Bureaucrat				Foo_d( "Foo_d", 145 );
		std::cout	<< Foo_d << std::endl;
		Bureaucrat				Bar_d( "Bar_d", 138 );
		std::cout	<< Bar_d << std::endl;
		ShrubberyCreationForm	RandomShrub_d( "Garden_d");
		std::cout	<< RandomShrub_d << std::endl;

		Foo_d.signForm( RandomShrub_d );
		Bar_d.executeForm( RandomShrub_d );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - SHRUBERRY" );
	return ;
}

static void	test_robotomy( void ) {
	test_separator( "START - ROBOTOMY" );
	try{
		Bureaucrat				Foo_a( "Foo_a", 72 );
		std::cout	<< Foo_a << std::endl;
		Bureaucrat				Bar_a( "Bar_a", 45 );
		std::cout	<< Bar_a << std::endl;
		RobotomyRequestForm	RandomRobotomy_a( "Robotomy_a");
		std::cout	<< RandomRobotomy_a << std::endl;

		Foo_a.signForm( RandomRobotomy_a );
		Bar_a.executeForm( RandomRobotomy_a );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "50%%" );
	try{
		Bureaucrat				Foo_Foo( "Foo_Foo", 1 );
		std::cout	<< Foo_Foo << std::endl;
		Bureaucrat				Bar_Bar( "Bar_Bar", 2 );
		std::cout	<< Bar_Bar << std::endl;
		RobotomyRequestForm	RandomRobotomy_one( "Robotomy_one");
		std::cout	<< RandomRobotomy_one << std::endl;
		RobotomyRequestForm RandomRobotomy_two( "Robotomy_two" );
		std::cout	<< RandomRobotomy_two << std::endl;

		Foo_Foo.signForm( RandomRobotomy_one );
		Foo_Foo.signForm( RandomRobotomy_two );
		
		Bar_Bar.executeForm( RandomRobotomy_one );
		Bar_Bar.executeForm( RandomRobotomy_two );
		Bar_Bar.executeForm( RandomRobotomy_two );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "not signed" );
	try{
		Bureaucrat				Foo_b( "Foo_b", 72 );
		std::cout	<< Foo_b << std::endl;
		Bureaucrat				Bar_b( "Bar_b", 45 );
		std::cout	<< Bar_b << std::endl;
		RobotomyRequestForm	RandomRobotomy_b( "Robotomy_b");
		std::cout	<< RandomRobotomy_b << std::endl;

		Bar_b.executeForm( RandomRobotomy_b );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "too low to sign" );
	try{
		Bureaucrat				Foo_c( "Foo_c", 73 );
		std::cout	<< Foo_c << std::endl;
		Bureaucrat				Bar_c( "Bar_c", 45 );
		std::cout	<< Bar_c << std::endl;
		RobotomyRequestForm	RandomRobotomy_c( "Robotomy_c");
		std::cout	<< RandomRobotomy_c << std::endl;

		Foo_c.signForm( RandomRobotomy_c );
		Bar_c.executeForm( RandomRobotomy_c );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "too low to execute" );
	try{
		Bureaucrat				Foo_d( "Foo_d", 72 );
		std::cout	<< Foo_d << std::endl;
		Bureaucrat				Bar_d( "Bar_d", 46 );
		std::cout	<< Bar_d << std::endl;
		RobotomyRequestForm	RandomRobotomy_d( "Robotomy_d");
		std::cout	<< RandomRobotomy_d << std::endl;

		Foo_d.signForm( RandomRobotomy_d );
		Bar_d.executeForm( RandomRobotomy_d );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - ROBOTOMY" );
	return ;
}

static void	test_presidential( void ) {
	test_separator( "START - PRESIDENTIAL" );
	try{
		Bureaucrat				Foo_a( "Foo_a", 25 );
		std::cout	<< Foo_a << std::endl;
		Bureaucrat				Bar_a( "Bar_a", 5 );
		std::cout	<< Bar_a << std::endl;
		PresidentialPardonForm	RandomPresidential_a( "Presidential_a");
		std::cout	<< RandomPresidential_a << std::endl;

		Foo_a.signForm( RandomPresidential_a );
		Bar_a.executeForm( RandomPresidential_a );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "not signed" );
	try{
		Bureaucrat				Foo_b( "Foo_b", 25 );
		std::cout	<< Foo_b << std::endl;
		Bureaucrat				Bar_b( "Bar_b", 5 );
		std::cout	<< Bar_b << std::endl;
		PresidentialPardonForm	RandomPresidential_b( "Presidential_b");
		std::cout	<< RandomPresidential_b << std::endl;

		Bar_b.executeForm( RandomPresidential_b );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "too low to sign" );
	try{
		Bureaucrat				Foo_c( "Foo_c", 26 );
		std::cout	<< Foo_c << std::endl;
		Bureaucrat				Bar_c( "Bar_c", 5 );
		std::cout	<< Bar_c << std::endl;
		PresidentialPardonForm	RandomPresidential_c( "Presidential_c");
		std::cout	<< RandomPresidential_c << std::endl;

		Foo_c.signForm( RandomPresidential_c );
		Bar_c.executeForm( RandomPresidential_c );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "too low to execute" );
	try{
		Bureaucrat				Foo_d( "Foo_d", 25 );
		std::cout	<< Foo_d << std::endl;
		Bureaucrat				Bar_d( "Bar_d", 6 );
		std::cout	<< Bar_d << std::endl;
		PresidentialPardonForm	RandomPresidential_d( "Presidential_d");
		std::cout	<< RandomPresidential_d << std::endl;

		Foo_d.signForm( RandomPresidential_d );
		Bar_d.executeForm( RandomPresidential_d );
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - PRESIDENTIAL" );
	return ;
}

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	test_shrubbery();
	test_robotomy();
	test_presidential();

	return ( 0 );
}
