/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:13:56 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/25 15:57:32 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/iter.hpp"

template<typename Y>
void  ft_fourtytwo(Y &i) {
	i = 42;
	return ;
}

int	main( int argc, char **argv ) {

	std::string	array[ 10 ] = {
		"ZERO",
		"ONE",
		"TWO",
		"THREE",
		"FOUR",
		"FIVE",
		"SIX",
		"SEVEN",
		"EIGHT",
		"NINE" };
	
	iter( &array[ 5 ], 5, ft_fourtytwo );
	iter( array, 10, print_output );

	int	digits[ 13 ] = { 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 666 };

	iter( digits, 13, print_output );
	iter( digits, 13, ft_fourtytwo );
	iter( digits, 13, print_output );
	
	return	EXIT_SUCCESS;
}
