/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:00:39 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/28 11:27:26 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ITER_HPP_
# define	ITER_HPP_

# include	<iostream>

# ifndef	EXIT_SUCCESS
#  define	EXIT_SUCCESS	0
# endif	/*	EXIT_SUCCESS	*/

template < typename Y >
Y  ft_fourtytwo(Y &i) {
	i = 42;
	return ( i ) ;
}

template < typename Y >
void	print_output( Y &to_print ) {
	std::cout	<< to_print << std::endl;
	return ;
}

/// ------------------------------------------------------------------------ ///

template < typename T, typename FPTR >
void	iter( T *array, size_t size, FPTR func ) {
	for (size_t i = 0; i < size; i++) {
		func( array[ i ] );
	}
	return ;
}

template < typename T >
void	iter( T *array, size_t size, void(*func)(T &) ) {
	for (size_t i = 0; i < size; i++) {
		func( array[ i ]);
	}
	return ;
}

#endif	/*	ITER_HPP_	*/
