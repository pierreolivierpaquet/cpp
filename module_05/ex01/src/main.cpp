/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:13:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/02 10:34:59 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

void	test1( void ) {
	try{
		Bureaucrat Paul( "Paul Temps" );
		Paul.setGrade( 150 );
		Bureaucrat Roy( "Roy Dupuis", 60);

		Form Wage( "INCREASE MINIMUM WAGE", 150, 150 );

		Paul.signForm( Wage );
		Roy.signForm( Wage );
		std::cout	<< Wage << std::endl;
	}
	catch( std::exception &e ) {
		std::cout << e.what() << std::endl;
	}
	std::cout	<< "*** TEST 1 DONE ***" << std::endl;
	return ;
}

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	test1();

	return ( 0 );
}
