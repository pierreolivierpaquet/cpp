/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 08:01:21 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 09:07:21 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

uintptr_t	ser::serialize( Data *ptr ) {
	uintptr_t	serialized = 0;
	
	serialized = reinterpret_cast<uintptr_t>( ptr );
	return ( serialized );
}

Data	*ser::deserialize( uintptr_t raw ) {
	Data *deserialized = NULL;
	
	deserialized = reinterpret_cast<Data *>( raw );
	return ( deserialized );
}
