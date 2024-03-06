/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 08:13:57 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/06 11:56:53 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		EASYFIND_HPP_
# define	EASYFIND_HPP_

# include	<iostream>
# include	<list>
# include	<vector>
// # include	<array> // c++11

// # include	<algorithm>
// # include	<iterator>

# ifndef	EXIT_SUCCESS
#  define	EXIT_SUCCESS	0
# endif	/*	EXIT_SUCCESS	*/

class ElementNotFound : public std::exception {
	public:
		virtual const char *what( void ) const throw();
};

# include "easyfind.tpp"

#endif	/*	EASYFIND_HPP_	*/
