/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:13:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/30 17:00:44 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;
	try{
		Bureaucrat Daniel("Daniel", 2 );
		Bureaucrat Johan( "Johan" );
		Daniel.incrementGrade();
		Johan.decrementGrade();
		std::cout << Johan << std::endl;
		std::cout << Daniel << std::endl;
	}
	catch ( Bureaucrat::GradeTooHighException &exception ) {
		std::cout << exception.what() << std::endl;
	}
	catch ( Bureaucrat::GradeTooLowException &exception ) {
		std::cout << exception.what() << std::endl;
	}
	return ( 0 );
}
