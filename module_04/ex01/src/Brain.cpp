/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:18:09 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 17:18:31 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

const std::string Brain::getIdeas( const size_t index ) const {
	if (index > 0 && index >= N_IDEAS){
		std::cout	<< "Error: Idea index " << index
					<< ": too high.";
		return ( "" );
	}
	return ( this->_ideas[ index ] );
}

void	Brain::setIdeas( const std::string idea ) {
	this->_ideas[ this->_iBrain++ ] = idea;
	this->_iBrain %= N_IDEAS;
	return ;
}

void	Brain::setIdeas( const std::string idea, const size_t index ) {
	if (index > 0 && index >= N_IDEAS){
		std::cout	<< "Error: Idea index " << index
					<< ": too high.";
	} else {
	this->_ideas[ index ].clear();
	this->_ideas[ index ] = idea;
	}
	return ;
}

/******************************************************************************/
/************************* CANONICAL FORM REQUISITES **************************/

Brain::Brain( const Brain &src ) {
	*this = src;
	std::cout << "Brain Constructor called. [reference copy]" << std::endl;
	return ;
}

Brain	&Brain::operator=( const Brain &rhs ) {
	size_t	i = 0;

	while (i < N_IDEAS){
		this->_ideas[ i ] = rhs._ideas[ i ];
		i++;
	}
	this->_iBrain = rhs._iBrain;
	return (*this);	
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

Brain::Brain( void ) : _iBrain( 0 ) {
	std::cout	<< "Brain Constructor called. [default]" << std::endl;
	return ;
}

Brain::~Brain( void ) {
	std::cout	<< "Brain Destructor called." << std::endl;
	return ;
}
