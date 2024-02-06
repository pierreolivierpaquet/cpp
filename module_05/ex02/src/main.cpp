/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:13:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 10:27:26 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

void	test1( void ) {
	ShrubberyCreationForm *Plant;
	try {
		Bureaucrat Daniel( "Dan", 145 );
		// Bureaucrat Daniel( "Dan", 146 ); // For <GradeTooLow> to sign + <NotSigned> throw().
		
		Bureaucrat	Elon( "Degenerusk" );
		Elon.setGrade( 137 );
		// Elon.setGrade( 138 ); // For <GradeTooLow> throw() for execution.
		
		Plant = new ShrubberyCreationForm( "valerie" );
		// Daniel.signForm( *Plant );
		ShrubberyCreationForm Garden = *Plant;

		std::cout << Garden << std::endl;

		Daniel.signForm( Garden ); // Comment for <notSigned> throw().
		Elon.executeForm( Garden );
	}
	catch ( std::exception &e ) {
		std::cout	<< e.what() << std::endl;	
	}
	delete Plant;
	return ;
}

void	test2( void ) {
	try {
		RobotomyRequestForm Quebec( "Bruno Marchand" );
		RobotomyRequestForm Quebec2( "Valerie Plante" );
		Bureaucrat Mayor( "Regis Labeaume", 45 );
		Bureaucrat Random( "François Legault", 72 );
	
		Random.signForm( Quebec );
		// Random.signForm( Quebec2 );
		Mayor.executeForm( Quebec );
		// Mayor.executeForm( Quebec2 );
		// Mayor.executeForm( Quebec );
		// Mayor.executeForm( Quebec2 );
		// Mayor.executeForm( Quebec );
		// Mayor.executeForm( Quebec2 );
		// Mayor.executeForm( Quebec );
		// Mayor.executeForm( Quebec2 );
	}
	catch ( std::exception &e ) {
		std::cout	<< e.what() << std::endl;
	}
	return ;
}

void 	test3( void ) {
	try {
		Bureaucrat Mach( "Sylvie Laporte", 5 );
		Bureaucrat Cominar( "Ben Letapis", 24 );

		PresidentialPardonForm Suspect( "Sus" );
		
		Mach.signForm( Suspect );
		Cominar.executeForm( Suspect );
	}
	catch ( std::exception &e ) {
		std::cout	<< e.what() << std::endl;
	}
	return ;
}

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	// test1();
	// test2();
	test3();

	return ( 0 );
}
