/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:12:01 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/23 15:08:47 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WHATEVER_HPP_
# define	WHATEVER_HPP_

# include	<iostream>

template<typename T>
void	swap( T &value1, T &value2 ) {
	const T reference = value1;
	
	value1 = value2;
	value2 = reference;
	return ;
}

template<typename M>
const M	&max( const M &value1, const M &value2  ) {
	return ( ( value1 >= value2 ) ? value1 : value2 );
}

template<typename M>
const M	&min( const M &value1, const M &value2  ) {
	return ( ( value1 <= value2 ) ? value1 : value2 );
}

#endif	/*	WHATEVER_HPP_	*/
