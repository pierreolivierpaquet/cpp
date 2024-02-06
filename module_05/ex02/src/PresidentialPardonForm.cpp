/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:41:30 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 10:28:28 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"

/******************************************************************************/
/********************************* FUNCTIONS **********************************/

std::string	PresidentialPardonForm::getTarget( void ) const {
	return ( this->_target );
}

void	PresidentialPardonForm::execute( const Bureaucrat &executor ) const {
	if (this->isSigned() == AFORM_NOT_SIGNED) {
		throw( PresidentialPardonForm::NotSigned() );
	} else if (executor.getGrade() > PRESIDENTIAL_EXECUTE ) {
		throw( PresidentialPardonForm::GradeTooLowException() );
	} else {
		std::cout	<< this->_target << " was pardoned by Zaphod Beeblebrox."
					<< std::endl;
	}
	return ;
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) :
	AForm( PRESIDENTIAL_NAME, PRESIDENTIAL_EXECUTE, PRESIDENTIAL_SIGN ),
	_target( target ) {
	
	std::cout	<< this->getName() << " (" << target << ")"
				<< " Constructor called. [parameterized]" << std::endl;
	return ;
}

/******************************************************************************/
/************************** CANONICAL FORM REQUISITE **************************/

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &src ) :
	AForm( PRESIDENTIAL_NAME, PRESIDENTIAL_EXECUTE, PRESIDENTIAL_SIGN ),
	_target( src.getTarget() ) {
	*this = src;
	std::cout	<< this->getName() << " (" << this->_target << ") "
				<< " Constructor called. [reference copy]" << std::endl;
	return ;
}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm& rhs ) {
	( void )rhs; //  Nothing to assign.
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

PresidentialPardonForm::PresidentialPardonForm( void ) : 
	AForm( PRESIDENTIAL_NAME, PRESIDENTIAL_EXECUTE, PRESIDENTIAL_SIGN) {
	std::cout	<< this->getName()
				<< " Constructor called. [default]" << std::endl;
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout	<< this->getName()
				<< " Destructor called. [default]" << std::endl;
	return ;
}

/******************************************************************************/
/********************************** OPERANDS **********************************/

std::ostream &operator<<( std::ostream &output, const PresidentialPardonForm &data ) {
	output	<< "\tAFORM NAME: " << data.getName() << std::endl;
	output 	<< "\tTARGET: " << data.getTarget() << std::endl; // new
	output	<< "\tAFORM SIGNED: ";
	if (data.isSigned()){
		output	<< "TRUE (signed.)" << std::endl;
	} else {
		output	<< "FALSE (not signed.)" << std::endl;
	}
	output	<< "\tREQUIRED GRADE TO EXECUTE: "
			<< data.getGradeToExecute() << std::endl;
	output	<< "\tREQUIRED GRADE TO SIGN: "
			<< data.getGradeToSign();
	return ( output );
}
