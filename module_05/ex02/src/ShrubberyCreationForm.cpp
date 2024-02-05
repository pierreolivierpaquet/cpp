/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:41:35 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/05 13:51:45 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

/******************************************************************************/
/********************************* FUNCTIONS **********************************/

std::string	ShrubberyCreationForm::getTarget( void ) const {
	return ( this->_target );
}

void	ShrubberyCreationForm::execute( const Bureaucrat &executor ) const {
	if (this->isSigned() == AFORM_NOT_SIGNED) {
		throw( ShrubberyCreationForm::NotSigned() );
	} else if (executor.getGrade() > SHRUBBERY_EXECUTE ) {
		throw( ShrubberyCreationForm::GradeTooLowException() );
	} else {
		std::ofstream garden;
		
		garden.open( this->_target.c_str(), std::ios::app );
		if (garden.is_open() != true){
			throw( ShrubberyCreationForm::FailedExecution() );
		}
		for (size_t i = 0; i < TREE_AMOUNT; i++) {
			garden	<< "               ,@@@@@@@,\n"
					<< "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
					<< "    ,&&%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
					<< "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
					<< "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
					<< "   %&&%/ %&&%&&@@\\ V /@@' `88\\8 `/88'\n"
					<< "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
					<< "       |o|        | |         | |\n"
					<< "       |.|        | |         | |\n"
					<< "     \\/ ._\\//_/__/  ,\\|_//__\\/.  \\_//__/_\n"
					<< std::endl;
		}
		garden.close();
	}
	return ;
}

/******************************************************************************/
/************************* PARAMETERIZED CONSTRUCTOR **************************/

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) :
	AForm( SHRUBBERY_NAME, SHRUBBERY_EXECUTE, SHRUBBERY_SIGN ),
	_target( target + SHRUBBERY_EXT ) {
	
	std::cout	<< this->getName() << " (" << target << ")"
				<< " Constructor called. [parameterized]" << std::endl;
	return ;
}

/******************************************************************************/
/************************** CANONICAL FORM REQUISITE **************************/

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &src ) :
	AForm( SHRUBBERY_NAME, SHRUBBERY_EXECUTE, SHRUBBERY_SIGN ),
	_target( src.getTarget() ) {
	*this = src;
	std::cout	<< this->getName() << " (" << this->_target << ") "
				<< " Constructor called. [reference copy]" << std::endl;
	return ;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm& rhs ) {
	( void )rhs; //  Nothing to assign.
	return ( *this );
}

/******************************************************************************/
/*********************** DEFAULT CONSTRUCTOR/DESTRUCTOR ***********************/

ShrubberyCreationForm::ShrubberyCreationForm( void ) : 
	AForm( SHRUBBERY_NAME, SHRUBBERY_EXECUTE, SHRUBBERY_SIGN) {
	std::cout	<< this->getName()
				<< " Constructor called. [default]" << std::endl;
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout	<< this->getName()
				<< " Destructor called. [default]" << std::endl;
	return ;
}

/******************************************************************************/
/******************************* NESTED CLASSES *******************************/

const char *ShrubberyCreationForm::FailedExecution::what( void ) const throw() {
	return ( "\033[91m\033[1mShrubbery: Failure during execution.\033[0m" );
}

/******************************************************************************/
/********************************** OPERANDS **********************************/

std::ostream &operator<<( std::ostream &output, const ShrubberyCreationForm &data ) {
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
