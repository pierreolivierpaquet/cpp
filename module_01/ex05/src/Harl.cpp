/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 09:39:19 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/12 13:18:36 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Harl.hpp"

void	Harl::debug( void ){
	std::cout << DEBUG << std::endl;
	return ;
}

void	Harl::info( void ){
	std::cout << INFO << std::endl;
	return ;
}

void	Harl::warning( void ){
	std::cout << WARNING << std::endl;
	return ;
}

void	Harl::error( void ){
	std::cout << ERROR << std::endl;
	return ;
}

/// ---
/// @brief	Validates the <level> identifier, then forward the execution to the
///			right Harl instance complaining function.
///
void	Harl::complain( std::string level ){
	int	i = -1;
	
	if (level.empty() == true){
		return ;
	}
	while (++i < COMMENT_AMOUNT){
		if (level.compare(this->commentFlag[i]) == 0){
			(this->*displayComplain[i])();
			break ;
		}
	}
	return ;
}

/// ---
/// @brief Default constructor.
///
Harl::Harl( void ){
	/*	Array of comment flags (identifiers), in respect to the equivalent
		index from the function pointers array.	*/
	this->commentFlag[ 0 ] = DEBUG_FLAG;
	this->commentFlag[ 1 ] = INFO_FLAG;
	this->commentFlag[ 2 ] = WARNING_FLAG;
	this->commentFlag[ 3 ] = ERROR_FLAG;
	
	/*	Array of relative function pointers.	*/
	this->displayComplain[ 0 ] = &Harl::debug;
	this->displayComplain[ 1 ] = &Harl::info;
	this->displayComplain[ 2 ] = &Harl::warning;
	this->displayComplain[ 3 ] = &Harl::error;	
}

/// ---
/// @brief Destructor.
///
Harl::~Harl( void ){}
