/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:13:03 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 14:22:38 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"

void	test1( void ) {
	AForm	*form_to_execute = NULL;
	Intern	Underestimated;

	form_to_execute = Underestimated.makeForm( "shrubbery creation", "Crustin" );
	if (form_to_execute == NULL){
		return ;
	}
	Bureaucrat Denise( "Denise Bombardier", 5 );
	
	Denise.signForm( *form_to_execute );
	Denise.executeForm( *form_to_execute );

	if (form_to_execute){
		delete form_to_execute;
	}
	return ;
}

int	main( int argc, char **argv ){
	( void )argc;
	( void )argv;

	test1();

	return ( 0 );
}
