/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 14:40:48 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/12 12:52:59 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/CastConversion.hpp"

#ifndef		EXIT_SUCCESS
# define	EXIT_SUCCESS	0
#endif	/*	EXIT_SUCCESS	*/

int	main( int argc, char **argv ) {
	( void ) argc;
	( void ) argv;

	

	return ( EXIT_SUCCESS );
}

//	1) Détecter le type de litéral passé en paramètre
//		- Char
//		- int
//		- float
//		- double
//
//	2) Convertir explicitement vers les autres types de données.
//
//	3)	Afficher un message d'erreur si la conversion ne fait pas sens, ou en cas d'overflow.
//
//	4)	
