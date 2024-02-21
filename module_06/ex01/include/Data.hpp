/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:01:23 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 08:48:35 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DATA_HPP_
# define	DATA_HPP_

# include	<iostream>
# include	<cstdint>

# ifndef	EXIT_SUCCESS
#  define	EXIT_SUCCESS	0
# endif	/*	EXIT_SUCCESS	*/

typedef struct	s_data{
	std::string name;
	uint16_t	age;
	int			money;
}	Data;

namespace ser {
	uintptr_t	serialize( Data *ptr );
	Data		*deserialize( uintptr_t raw );
}

#endif	/*	DATA_HPP_	*/
