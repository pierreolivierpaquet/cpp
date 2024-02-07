/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:41:32 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/06 21:46:53 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

const char *noises[] = {"Whirr", "Buzz", "Hmm", "Grind", "Rattle", "Squeak",
"Clank","Whine","Roar","Chirp", "Click","Screech","Thump","Vibrate","Hiss" };

void	drillNoises( void ) {
	int	size = sizeof( noises ) / sizeof( noises[ 0 ] ); // Lenght of the array.
	int amount = 3;
	int index = 0;
	for (int i = 0; i < amount; i++){
		index = rand() % size;
		std::cout	<< noises[ index ];
		if (i < (amount - 1)){
			std::cout	<< " ";
		} else {
			std::cout << std::endl;
		}
	}
	return ;
}

/******************************************************************************/
/********************************* FUNCTIONS **********************************/

bool RobotomyRequestForm::_robotomized = false;

std::string	RobotomyRequestForm::getTarget( void ) const {
	return ( this->_target );
}

void	RobotomyRequestForm::execute( const Bureaucrat &executor ) const {
	if (this->isSigned() == AFORM_NOT_SIGNED) {
		throw( RobotomyRequestForm::NotSigned() );
	} else if (executor.getGrade() > ROBOTOMY_EXECUTE ) {
		throw( RobotomyRequestForm::GradeTooLowException() );
	} else {
		drillNoises();
		if (RobotomyRequestForm::_robotomized){
			std::cout	<< this->_target
						<< " successfully robotomized." << std::endl;
		} else {
			std::cout	<< this->_target
						<< " has not been robotomized: Try again. " << std::endl;
		}
		RobotomyRequestForm::_robotomized = !RobotomyRequestForm::_robotomized;
		}
	return ;
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) :
	AForm( ROBOTOMY_NAME, ROBOTOMY_EXECUTE, ROBOTOMY_SIGN ),
	_target( target ) {
	
	std::cout	<< this->getName() << " (" << target << ")"
				<< " Constructor called. [parameterized]" << std::endl;
	return ;
}

/******************************************************************************/
/************************** CANONICAL FORM REQUISITE **************************/

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &src ) :
	AForm( ROBOTOMY_NAME, ROBOTOMY_EXECUTE, ROBOTOMY_SIGN ),
	_target( src.getTarget() ) {
	*this = src;
	std::cout	<< this->getName() << " (" << this->_target << ") "
				<< " Constructor called. [reference copy]" << std::endl;
	return ;
}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm& rhs ) {
	( void )rhs; //  Nothing to assign.
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

RobotomyRequestForm::RobotomyRequestForm( void ) : 
	AForm( ROBOTOMY_NAME, ROBOTOMY_EXECUTE, ROBOTOMY_SIGN) {
	std::cout	<< this->getName()
				<< " Constructor called. [default]" << std::endl;
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout	<< this->getName()
				<< " Destructor called. [default]" << std::endl;
	return ;
}

/******************************************************************************/
/********************************** OPERANDS **********************************/

std::ostream &operator<<( std::ostream &output, const RobotomyRequestForm &data ) {
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
