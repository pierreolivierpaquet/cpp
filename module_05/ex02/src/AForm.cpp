/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:38:39 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/02 11:33:44 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

/******************************************************************************/
/********************************* FUNCTIONS **********************************/

void	AForm::beSigned( const Bureaucrat &person ) {
	if (this->_signed){
		throw( AForm::AlreadySigned() );
	} else if (person.getGrade() <= this->_gradeToSign ){
		this->_signed = FORM_SIGNED;
	} else {
		throw( AForm::GradeTooLowException() );
	}
	return ;
}

const std::string	AForm::getName( void ) const {
	return ( this->_name );
}

bool	AForm::isSigned( void ) const {
	return ( this->_signed );
}

grade_t	AForm::getGradeToExecute( void ) const {
	return ( this->_gradeToExecute );
}

grade_t	AForm::getGradeToSign( void ) const {
	return ( this->_gradeToSign );
}

grade_t	AForm::checkGrade( const grade_t to_check ) const {
	if (to_check < 1){
		throw( AForm::GradeTooHighException() );
	} else if (to_check > 150) {
		throw( AForm::GradeTooLowException() );
	}
	return ( to_check );
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

AForm::AForm( const std::string form_name ) :
	_name( form_name ),
	_signed( FORM_NOT_SIGNED ),
	_gradeToExecute( DEFAULT_GRADE ),
	_gradeToSign( DEFAULT_GRADE ) {
	std::cout	<< this->_name
				<< " Form Constructor called. [<name> parameterized]" << std::endl;
	return ;
}

AForm::AForm(	const grade_t to_execute,
			const grade_t to_sign ) :
	_name( DEFAULT_FORM_NAME ),
	_signed( FORM_NOT_SIGNED ),
	_gradeToExecute( this->checkGrade( to_execute ) ),
	_gradeToSign(  this->checkGrade( to_sign ) ) {
	std::cout	<< this->_name
				<< " Form Constructor called. [<grades> parameterized]" << std::endl;
	return ;
}

AForm::AForm( const std::string form_name,
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

AForm::AForm( const AForm &src ) :
	_name( src._name ),
	_gradeToExecute( src._gradeToExecute ),
	_gradeToSign( src._gradeToSign ) {
	*this = src;
	std::cout	<< this->_name
				<< " Form Constructor called. [reference copy]" << std::endl;
	return ;
}

AForm	&AForm::operator=( const AForm &rhs ) {
	this->_signed = rhs._signed;
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

AForm::AForm( void ) :
	_name( DEFAULT_FORM_NAME ),
	_signed( FORM_NOT_SIGNED ),
	_gradeToExecute( DEFAULT_GRADE ),
	_gradeToSign( DEFAULT_GRADE ) {
	std::cout	<< this->_name
				<< " Form Constructor called. [default]" << std::endl;
	return ;
}

AForm::~AForm( void ) {
	std::cout	<< this->_name
				<< " Form Destructor called. [default]"<< std::endl;
	return ;
}

/******************************************************************************/
/******************************* NESTED CLASSES *******************************/

const char *AForm::GradeTooHighException::what( void ) const throw() {
	return ( "\033[91m\033[1mForm: Grade is too high.\033[0m" );
}

const char *AForm::GradeTooLowException::what( void ) const throw() {
	return ( "\033[91m\033[1mForm: Grade is too low.\033[0m" );
}

const char *AForm::AlreadySigned::what( void ) const throw() {
	return ( "\033[91m\033[1mForm: Already signed.\033[0m" );
}

/******************************************************************************/
/********************************** OPERANDS **********************************/

std::ostream &operator<<( std::ostream &output, const AForm &data ) {
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
