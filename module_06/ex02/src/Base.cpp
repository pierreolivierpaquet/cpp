/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:59:36 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 14:14:20 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Base.hpp"

Base::Base( void ) {
	std::cout	<< "'Base' Constructor called [default]" << std::endl;
	return ;
}

Base::~Base() {
	std::cout	<< "'Base' Destructor called [default]" << std::endl;
	return ;
}
