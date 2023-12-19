/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:48:28 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/18 09:47:06 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#include "Contact.hpp"
#include "Phonebook.hpp"

/// @brief Contact constructor fucntion. All values are nullified.
Contact::Contact( void ) : registered(false), \
							first_name(EMPTY), \
							last_name(EMPTY), \
							nick_name(EMPTY), \
							secret(EMPTY), \
							phone_number(EMPTY) {};

/***************************************************************** FIRST NAME */

/// @brief Flags the instance as registered (by user).
void	Contact::setRegistered(void) {
	this->registered = true;
	return ;
};

bool	Contact::_getRegistration(void) const {
	return (this->registered);
};

/***************************************************************** FIRST NAME */

/// @brief Assigns a new first name to the instance.
void	Contact::setFirstName(std::string first_name) {
	this->first_name = first_name;
	return;
};

std::string Contact::_getFirstName(void) const{
	return (this->first_name);
};

/****************************************************************** LAST NAME */

/// @brief Assigns a new last name to the instance.
void	Contact::setLastName(std::string last_name) {
	this->last_name = last_name;
	return;
};

std::string Contact::_getLastName(void) const{
	return (this->last_name);
};

/******************************************************************* NICKNAME */

/// @brief Assigns a new nickname to the instance.
void	Contact::setNickName(std::string nick_name) {
	this->nick_name = nick_name;
	return;
};

std::string Contact::_getNickName(void) const{
	return (this->nick_name);
};

/********************************************************************* SECRET */

std::string	Contact::_getSecret(void) const{
	return(this->secret);
};

void	Contact::setSecret(std::string secret) {
	this->secret = secret;
	return ;
};

/*************************************************************** PHONE NUMBER */

std::string Contact::_getPhoneNumber(void) const{
	return (this->phone_number);
};

void	Contact::setPhoneNumber(std::string phone_number) {
	this->phone_number = phone_number;
	return ;
};
