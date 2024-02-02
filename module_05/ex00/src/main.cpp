/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:13:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/02 09:47:13 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

void	test1( void ) {
	try{
		Bureaucrat Daniel("Daniel", 2 );
		Bureaucrat Johan( "Johan" );
		Daniel.incrementGrade();
		Johan.incrementGrade();
		// Daniel.incrementGrade(); // Uncomment for TOO HIGH throw().
		std::cout << Johan << std::endl;
		std::cout << Daniel << std::endl;
	}
	catch ( Bureaucrat::GradeTooHighException &exception ) {
		std::cout << exception.what() << std::endl;
	}
	catch ( Bureaucrat::GradeTooLowException &exception ) {
		std::cout << exception.what() << std::endl;
	}
	return ;
}

void	test3( void ) {
	try{
		Bureaucrat JustinTrudeau( "Justin", LOWEST_GRADE );
		// Bureaucrat JustinTrudeau( "Justin", -42 ); // Uncomment for TOO HIGH throw()
		// Bureaucrat JustinTrudeau( "Justin", 43 ); // Uncomment for NO throw()
		
		std::cout << JustinTrudeau << std::endl;
	}
	catch ( Bureaucrat::GradeTooHighException &ex ) {
		std::cout << ex.what() << std::endl;
	}
	catch ( Bureaucrat::GradeTooLowException &ex ) {
		std::cout << ex.what() << std::endl;
	}
}

void 	test2( void ) {
	Bureaucrat *Molo = NULL;
	try{
		// Molo = new Bureaucrat( "Yelo", -1 ); // Uncomment for CONSTR. throw()
		Molo = new Bureaucrat( "Yelo", 1 );
		Molo->decrementGrade( 101 );
	}
	catch( Bureaucrat::GradeTooHighException &e ) {
		std::cout << e.what() << std::endl;
	}
	catch( Bureaucrat::GradeTooLowException &e ) {
		std::cout << e.what() << std::endl;
	}
	if (Molo != NULL){
		delete Molo;
	}
	return ;
}

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	test1();
	// test2();
	// test3();

	return ( 0 );
}
