/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:13:55 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/29 14:00:49 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/easyfind.hpp"

template < typename T >
typename T::const_iterator easyfind( const T &container, int find ) {

	typename T::const_iterator iter = container.begin();
	for (; iter != container.end(); iter++)
	{
		if (*iter == find){
			return (iter) ;
		}
	}
	throw( ElementNotFound() );
	return ( container.end() );
}

const char *ElementNotFound::what( void ) const throw() {
	return ("\033[1;31merror\033[0m: element not found within the provided container.");
}
