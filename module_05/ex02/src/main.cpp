/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:13:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/05 11:00:31 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"

void	test1( void ) {
	ShrubberyCreationForm *Plant;
	try{
		Bureaucrat Daniel( "Dan", 145 );
		Bureaucrat	Elon( "Degenerusk" );
		Elon.setGrade( 137 );
		Plant = new ShrubberyCreationForm( "valerie" );

		std::cout << *Plant << std::endl;

		Daniel.signForm( *Plant );
		Plant->execute( Elon );
	}
	catch ( std::exception &e ) {
		std::cout	<< e.what() << std::endl;	
	}
	delete Plant;
	return ;
}

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	test1();

	return ( 0 );
}
