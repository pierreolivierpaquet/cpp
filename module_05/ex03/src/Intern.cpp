/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:23:21 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/07 08:59:13 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

const int Intern::_nTask = TASK_AMOUNT;

/******************************************************************************/
/********************************* FUNCTIONS **********************************/

AForm *Intern::_makeShrubbery( const std::string target ) const{
	AForm *shrubbery_form = NULL;
	shrubbery_form = new ShrubberyCreationForm( target );
	return ( shrubbery_form );
}

AForm *Intern::_makeRobotomy( const std::string target ) const {
	AForm *robotomy_form = NULL;
	robotomy_form = new RobotomyRequestForm( target );
	return ( robotomy_form );
}

AForm *Intern::_makePresidential( const std::string target ) const {
	AForm *presidential_form = NULL;
	presidential_form = new PresidentialPardonForm( target );
	return ( presidential_form );
}

AForm *Intern::makeForm( std::string form_name, std::string target ) const {
	AForm *new_form = NULL;
	
	for (size_t i = 0; i < this->_nTask; i++){
		if (form_name.compare( this->_formIdentifier[ i ] ) == 0){
			new_form = (this->*_formList[ i ])( target );
			std::cout	<< "Intern \033[1m\033[32mcreated\033[0m: "
						<< new_form->getName() << "." << std::endl;
			return ( new_form );
		}
	}
	std::cout	<< "Intern \033[1m\033[31mwas not able to create\033[0m "
				<< form_name << ": Try again." << std::endl;
	return ( new_form );
}

/******************************************************************************/
/************************** CANONICAL FORM REQUISITE **************************/

Intern::Intern( const Intern &src ) {
	*this = src;
	return ;
}

Intern &Intern::operator=( const Intern &rhs ) {
	for (size_t i = 0; i < this->_nTask; i++){
		this->_formList[ i ] = rhs._formList[ i ];
		this->_formIdentifier[ i ] = rhs._formIdentifier[ i ];
	}
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

Intern::Intern( void ) {
	this->_formList[ SHRUBBERY ]	= &Intern::_makeShrubbery;
	this->_formList[ ROBOTOMY ]		= &Intern::_makeRobotomy;
	this->_formList[ PRESIDENTIAL ]	= &Intern::_makePresidential;
	
	_formIdentifier[ SHRUBBERY ]	= SHRUBBERY_ID;
	_formIdentifier[ ROBOTOMY ]		= ROBOTOMY_ID;
	_formIdentifier[ PRESIDENTIAL ]	= PRESIDENTIAL_ID;
	
	std::cout	<< "Intern Constructor called. [reference copy] " << std::endl;
	return ;
}

Intern::~Intern( void ) {
	std::cout	<< "Intern Destructor called. [default]" << std::endl;
	return ;
}
