/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:39 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/02 10:30:10 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

/******************************************************************************/
/********************************* FUNCTIONS **********************************/

void	Form::beSigned( const Bureaucrat &person ) {
	std::cout << "TEST: " << person.getGrade() << std::endl; // to delete
	std::cout << "TEST THIS: " << this->getGradeToSign() << std::endl;
	if (this->_signed){
		throw( Form::AlreadySigned() );
	} else if (person.getGrade() <= this->_gradeToSign ){
		this->_signed = FORM_SIGNED;
	} else {
		throw( Form::GradeTooLowException() );
	}
	return ;
}

const std::string	Form::getName( void ) const {
	return ( this->_name );
}

bool	Form::isSigned( void ) const {
	return ( this->_signed );
}

grade_t	Form::getGradeToExecute( void ) const {
	return ( this->_gradeToExecute );
}

grade_t	Form::getGradeToSign( void ) const {
	return ( this->_gradeToSign );
}

grade_t	Form::checkGrade( const grade_t to_check ) const {
	if (to_check < 1){
		throw( Form::GradeTooHighException() );
	} else if (to_check > 150) {
		throw( Form::GradeTooLowException() );
	}
	return ( to_check );
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

Form::Form( const std::string form_name ) :
	_name( form_name ),
	_signed( FORM_NOT_SIGNED ),
	_gradeToExecute( DEFAULT_GRADE ),
	_gradeToSign( DEFAULT_GRADE ) {
	std::cout	<< this->_name
				<< " Form Constructor called. [<name> parameterized]" << std::endl;
	return ;
}

Form::Form(	const grade_t to_execute,
			const grade_t to_sign ) :
	_name( DEFAULT_FORM_NAME ),
	_signed( FORM_NOT_SIGNED ),
	_gradeToExecute( this->checkGrade( to_execute ) ),
	_gradeToSign(  this->checkGrade( to_sign ) ) {
	std::cout	<< this->_name
				<< " Form Constructor called. [<grades> parameterized]" << std::endl;
	return ;
}

Form::Form( const std::string form_name,
			const grade_t to_execute,
			const grade_t to_sign ) :
	_name( form_name ),
	_signed( FORM_NOT_SIGNED ),
	_gradeToExecute( this->checkGrade( to_execute ) ),
	_gradeToSign( this->checkGrade( to_sign ) ) {
	std::cout	<< this->_name
				<< " Form Constructor called. [full parameterized]" << std::endl;
	return ;
}

/******************************************************************************/
/************************** CANONICAL FORM REQUISITE **************************/

Form::Form( const Form &src ) :
	_name( src._name ),
	_gradeToExecute( src._gradeToExecute ),
	_gradeToSign( src._gradeToSign ) {
	*this = src;
	std::cout	<< this->_name
				<< " Form Constructor called. [reference copy]" << std::endl;
	return ;
}

Form	&Form::operator=( const Form &rhs ) {
	this->_signed = rhs._signed;
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

Form::Form( void ) :
	_name( DEFAULT_FORM_NAME ),
	_signed( FORM_NOT_SIGNED ),
	_gradeToExecute( DEFAULT_GRADE ),
	_gradeToSign( DEFAULT_GRADE ) {
	std::cout	<< this->_name
				<< " Form Constructor called. [default]" << std::endl;
	return ;
}

Form::~Form( void ) {
	std::cout	<< this->_name
				<< " Form Destructor called. [default]"<< std::endl;
	return ;
}

/******************************************************************************/
/******************************* NESTED CLASSES *******************************/

const char *Form::GradeTooHighException::what( void ) const throw() {
	return ( "\033[91m\033[1mForm: Grade is too high.\033[0m" );
}

const char *Form::GradeTooLowException::what( void ) const throw() {
	return ( "\033[91m\033[1mForm: Grade is too low.\033[0m" );
}

const char *Form::AlreadySigned::what( void ) const throw() {
	return ( "\033[91m\033[1mForm: Already signed.\033[0m" );
}

/******************************************************************************/
/********************************** OPERANDS **********************************/

std::ostream &operator<<( std::ostream &output, const Form &data ) {
	output	<< "\tFORM NAME: " << data.getName() << std::endl;
	output	<< "\tFORM SIGNED: ";
	if (data.isSigned()){
		output	<< "TRUE (signed.)" << std::endl;
	} else {
		output	<< "FALSE (not signed.)" << std::endl;
	}
	output	<< "\tREQUIRED GRADE TO EXECUTE: "
			<< data.getGradeToExecute() << std::endl;
	output	<< "\tREQUIRED GRADE TO SIGN "
			<< data.getGradeToSign();
	return ( output );
}
