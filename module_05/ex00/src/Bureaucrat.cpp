/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 10:13:01 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/30 17:09:44 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

/******************************************************************************/
/********************************* FUNCTIONS **********************************/

const std::string	Bureaucrat::getName( void ) const {
	return ( this->_name );
}

grade_t	Bureaucrat::getGrade( void ) const {
	return ( this->_grade );
}

void	Bureaucrat::setGrade( grade_t new_grade ) {
	if (new_grade < 1) {
		throw( Bureaucrat::GradeTooHighException() );
	} else if (new_grade > 150) {
		throw( Bureaucrat::GradeTooLowException() );
	} else {
		this->_grade = new_grade;
	}
	return ;
}

void	Bureaucrat::incrementGrade( void ) {
	this->setGrade( this->getGrade() - 1 );
	return ;
}

void	Bureaucrat::incrementGrade( grade_t	amount ) {
	this->setGrade( this->getGrade() - amount );
	return ;
}

void	Bureaucrat::decrementGrade( void ) {
	this->setGrade( this->getGrade() + 1 );
	return ;
}

void	Bureaucrat::decrementGrade( grade_t amount ) {
	this->setGrade( this->getGrade() + amount );
	return ;
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

Bureaucrat::Bureaucrat( const std::string new_name ) :
	_name( new_name ) {
	this->setGrade( DEFAULT_GRADE );
	std::cout	<< this->_name
				<< " Constructor called [<name> parameterized]" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( const grade_t new_grade ) :
	_name( DEFAULT_NAME ) {
	this->setGrade( new_grade );
	std::cout	<< this->_name
				<< " Constructor called. [<grade> parameterized]" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat( const std::string new_name, const grade_t new_grade ) :
	_name( new_name ) {
	this->setGrade( new_grade );
	std::cout	<< this->_name
				<< " Constructor called. [full parameterized]" << std::endl;
	return ;
}

/******************************************************************************/
/************************** CANONICAL FORM REQUISITE **************************/

Bureaucrat::Bureaucrat( const Bureaucrat &src ) : 
	_name( src._name ) {
	*this = src;
	std::cout	<< this->_name
				<< " Constructor called. [reference copy]" << std::endl;
	return ;
}

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &rhs ) {
	this->_grade = rhs._grade;
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

Bureaucrat::Bureaucrat( void ) :
	_name( DEFAULT_NAME),
	_grade( DEFAULT_GRADE ) {
	std::cout	<< this->_name << " Constructor called. [default]" << std::endl;
	return ;
}

Bureaucrat::~Bureaucrat( void ) {
	std::cout	<< this->_name << " Destructor called. [default]" << std::endl;
	return ;
}

/******************************************************************************/
/******************************* NESTED CLASSES *******************************/

const char *Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ( "Grade is too high." );
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ( "Grade is too low." );	
}

/******************************************************************************/
/********************************** OPERANDS **********************************/

std::ostream	&operator<<( std::ostream &output, const Bureaucrat &data ) {
	output	<< data.getName()
			<< ", bureaucrat grade "
			<< data.getGrade();
	return ( output );
}
