/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:13:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/07 09:12:02 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"

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

void	test_pdf() {
	test_separator( "START - TEST PDF" );
	try {
		Intern	someRandomIntern;
		AForm	*rrf = NULL;
		
		std::cout	<< "AFORM (before): " << rrf << std::endl;
		rrf = someRandomIntern.makeForm( "robotomy request", "Bender" );
		std::cout	<< "AFORM (after): " << rrf << std::endl;
		if (rrf) {
			std::cout	<< *rrf << std::endl;
			delete	rrf;
		}
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - TEST PDF" );
	return ;
}

void	test_internShrubbery( void ) {
	test_separator( "START - INTERN SHRUBBERY" );
	try {
		Bureaucrat	Foo_a( "Foo_a", 5);
		Intern	John_a;
		AForm *intern_form = NULL;
		intern_form = John_a.makeForm( "shrubbery creation", "Foo_target" );
		if (intern_form) {
			std::cout	<< *intern_form << std::endl;
			Foo_a.signForm( *intern_form );
			Foo_a.executeForm( *intern_form );
			delete intern_form;
		}
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "invalid form name" );
	try {
		Bureaucrat	Foo_b( "Foo_b", 5);
		Intern	John_b;
		AForm *intern_form = NULL;
		intern_form = John_b.makeForm( "shrubbery request", "Foo_target" );
		if (intern_form) {
			std::cout	<< *intern_form << std::endl;
			Foo_b.signForm( *intern_form );
			Foo_b.executeForm( *intern_form );
			delete intern_form;
		}
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - INTERN SHRUBBERY" );
	return ;
}

void	test_internRobotomy( void ) {
	test_separator( "START - INTERN ROBOTOMY" );
	try {
		Bureaucrat	Foo_a( "Foo_a", 5);
		Intern	John_a;
		AForm *intern_form = NULL;
		intern_form = John_a.makeForm( "robotomy request", "Foo_target" );
		if (intern_form) {
			std::cout	<< *intern_form << std::endl;
			Foo_a.signForm( *intern_form );
			Foo_a.executeForm( *intern_form );
			delete intern_form;
		}
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;	
	}
	test_separator( "invalid form name" );
	try {
		Bureaucrat	Foo_b( "Foo_b", 5);
		Intern	John_b;
		AForm *intern_form = NULL;
		intern_form = John_b.makeForm( "robotomy  request", "Foo_target" );
		if (intern_form) {
			std::cout	<< *intern_form << std::endl;
			Foo_b.signForm( *intern_form );
			Foo_b.executeForm( *intern_form );
			delete intern_form;
		}
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - INTERN ROBOTOMY" );
}

void	test_internPresidential( void ) {
	test_separator( "START - INTERN ROBOTOMY" );
	try {
		Bureaucrat	Foo_a( "Foo_a", 5);
		Intern	John_a;
		AForm *intern_form = NULL;
		intern_form = John_a.makeForm( "presidential pardon", "Foo_target" );
		if (intern_form) {
			std::cout	<< *intern_form << std::endl;
			Foo_a.signForm( *intern_form );
			Foo_a.executeForm( *intern_form );
			delete intern_form;
		}
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;	
	}
	test_separator( "invalid form name" );
	try {
		Bureaucrat	Foo_b( "Foo_b", 5);
		Intern	John_b;
		AForm *intern_form = NULL;
		intern_form = John_b.makeForm( "presidentia1 pardon", "Foo_target" );
		if (intern_form) {
			std::cout	<< *intern_form << std::endl;
			Foo_b.signForm( *intern_form );
			Foo_b.executeForm( *intern_form );
			delete intern_form;
		}
	}
	catch (std::exception &e) {
		std::cout	<< e.what() << std::endl;
	}
	test_separator( "END - INTERN ROBOTOMY" );
}

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	test_pdf();
	test_internShrubbery();
	test_internRobotomy();
	test_internPresidential();

	return ( 0 );
}
