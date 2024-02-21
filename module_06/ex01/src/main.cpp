/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:00:46 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 09:54:39 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

/******************************************************************************/

int	main( int argc, char **argv ) {
	( void )argc;
	( void )argv;

	Data Foo = { "Foo", 42, 1000 };
	Data *FooTwo = NULL;
	uintptr_t	Bar = 0;

	Bar = ser::serialize( &Foo );
	FooTwo = ser::deserialize( Bar );

	return ( EXIT_SUCCESS );
}
