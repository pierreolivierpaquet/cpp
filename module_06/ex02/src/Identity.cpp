/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identity.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 14:02:59 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 08:44:44 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Identity.hpp"

Base	*idt::generate( void ) {
	Base *ptr = NULL;
	if (idt::random_seed == 0){
		idt::random_seed = time( NULL );
		srand( idt::random_seed );
	}
	int rand_num = 0;
	rand_num = rand() % 3;
	switch ( rand_num ) {
		case BASE_A:
			ptr = new A;
			break;
		case BASE_B:
			ptr = new B;
			break;
		case BASE_C:
			ptr = new C;
			break;
	}
	return ( ptr );
}

void	idt::displayId( std::string id, bool by_reference = false ) {
	std::cout	<< IDENTIFIED_ID << "'" << id << "'";
	if (by_reference == true){
		std::cout	<< " [reference]";
	} else {
		std::cout	<< " [pointer]";
	}
	std::cout << std::endl;
	return ;
}

void	idt::identify( Base *p ) {
	if (dynamic_cast<A *>( p ) != NULL){
		return ( idt::displayId( "A" ) );
	} else if (dynamic_cast<B *>( p ) != NULL) {
		return ( idt::displayId( "B" ) );
	} else if (dynamic_cast<C *>( p )) {
		return ( idt::displayId( "C" ) );
	}
	std::cout << UNIDENTIFIED_ID << std::endl;
	return ;
}

void	idt::identify( Base &p ) {
	try {
		A &temp = dynamic_cast<A &>( p );
		return ( idt::displayId( "A", true ), static_cast<void>( temp ) );
	} catch( const std::exception& exception ) {}
	try {
		B &temp = dynamic_cast<B &>( p );
		return ( idt::displayId( "B", true ), static_cast<void>( temp ) );
	} catch ( const std::exception& exception ) {}
	try {
		C &temp = dynamic_cast<C &>( p );
		return ( idt::displayId( "C", true ), static_cast<void>( temp ) );
	} catch ( const std::exception& exception ) {}
	std::cout << UNIDENTIFIED_ID << std::endl;
	return ;
}

/******************************************************************************/

A::A( void ) : Base() {
	std::cout	<< "'A' Constructor called [default]" << std::endl;
	return ;
}

A::~A( void ) {
	std::cout	<< "'A' Destructor called [default]" << std::endl;
	return ;
}

/******************************************************************************/

B::B( void ) : Base() {
	std::cout	<< "'B' Constructor called [default]" << std::endl;
	return ;
}

B::~B( void ) {
	std::cout	<< "'B' Destructor called [default]" << std::endl;
	return ;
}

/******************************************************************************/

C::C( void ) : Base() {
	std::cout	<< "'C' Constructor called [default]" << std::endl;
	return ;
}

C::~C( void ) {
	std::cout	<< "'C' Destructor called [default]" << std::endl;
	return ;
}
