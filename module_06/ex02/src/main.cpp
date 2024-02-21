/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:59:05 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 14:57:31 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Identity.hpp"

int	main( int argc, char **argv ) {

	// Base *ptr = idt::generate();
	// idt::identify( ptr );
	// delete ptr;

	B Foo;
	Base &Bar = Foo;	

	idt::identify( Bar );

	return ( EXIT_SUCCESS );
}
