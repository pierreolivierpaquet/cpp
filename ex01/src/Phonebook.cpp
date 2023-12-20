/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:35:04 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/20 11:58:49 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <sstream>

Phonebook::Phonebook(void) : contactIndex(0){};

void	Phonebook::incrementIndex(void){
	this->contactIndex++;
	this->contactIndex %= CONTACT_MAX;
};

bool	is_phoneNumber(
	std::string phone_number)
{
	std::size_t	i = 0;
	std::size_t l = phone_number.length();
	while (i < l)
	{
		if (!isdigit(phone_number[i]) && phone_number[i] != '-'){
			return(false);
		}
		i++;
	}
	return (true);
}

bool	is_searchable(
	std::string index,
	int *i_index)
{
	std::size_t	i = 0;
	std::size_t	l = index.length();
	if (l > 1)
		return (false);
	while (i < l)
	{
		if (!isdigit(index[i])){
			return (false);
		}
		i++;
	}
	std::istringstream result(index);
	result >> *i_index;
	if (*i_index < 0 || *i_index > 7){
		return (false);
	}
	return (true);
};

std::string	userInput(
	size_t input_type,
	std::string prompt,
	int *index)
{
	std::string input = EMPTY;
	std::cin.clear();
	bool	valid = true;
	while (WAIT_INPUT)
	{
		std::cout << prompt << INPUT_PROMPT;
		std::getline(std::cin, input);
		if (input_type == PHONE_TYPE)
			valid = is_phoneNumber(input);
		if (input_type == SEARCH_TYPE)
			valid = is_searchable(input, index);
		if (std::cin.good() && !input.empty() && valid)
			return (input);
		if (std::cin.eof()){
			return (input);
		}
		std::cin.clear();
		input.clear();
		input = SPACE;
	}
	return (input);
};

void	Phonebook::setContact(
	size_t index)
{
	this->directory[index].setFirstName(
							userInput(TEXT_TYPE, "\tFIRST NAME", NULL));
	if (std::cin.eof())
		return ;
	this->directory[index].setLastName(
							userInput(TEXT_TYPE, "\tLAST NAME", NULL));
	if (std::cin.eof())
		return ;
	this->directory[index].setNickName(
							userInput(TEXT_TYPE, "\tNICK NAME", NULL));
	if (std::cin.eof())
		return ;
	this->directory[index].setSecret(
							userInput(TEXT_TYPE, "\tDARKEST SECRET", NULL));
	if (std::cin.eof())
		return ;
	this->directory[index].setPhoneNumber(
							userInput(PHONE_TYPE, "\tPHONE NUMBER", NULL));
	if (std::cin.eof())
		return ;
	this->directory[index].setRegistered();
	return ;
};

void	Phonebook::addContact(void){
	Phonebook::setContact(this->contactIndex);
	Phonebook::incrementIndex();
};

void	printSpace(
	std::size_t i)
{
	while (i-- > 0){
		std::cout << SPACE;
	}
	return;
};

void	printSubString(
	std::string sub_name)
{
	std::cout << sub_name.substr(0, 9) << DOT;
};

void	printInfo(
	std::string sub_name)
{
	size_t		l = sub_name.length();
	if (l < 10){
		printSpace(10 - l);
		std::cout << sub_name;
	}
	else {
		printSubString(sub_name);
	}
	return ;
};

void	displayInfo(
	Contact info)
{
	printInfo(info._getFirstName());
	std::cout << SEPARATOR;
	printInfo(info._getLastName());
	std::cout << SEPARATOR;
	printInfo(info._getNickName());
	std::cout << SEPARATOR << std::endl;
	return ;
};

void	Phonebook::_displayDirectory(void) const{
	std::size_t	i = 0;
	std::cout << std::endl << TAB << TOP_FRAME;
	std::cout << TAB << SEPARATOR << " INDEX    " << SEPARATOR \
									<< " FRST NM. " << SEPARATOR \
									<< " LST NM.  " << SEPARATOR \
									<< " NCKNM.   " << SEPARATOR << std::endl;
	std::cout << TAB << MIDDLE_FRAME;
	while (i < CONTACT_MAX){
		std::cout << TAB << SEPARATOR << "        " \
							<< i << DOT << SEPARATOR;
		displayInfo(this->directory[i]);
		i++;
	}
	std::cout << TAB << BOTTOM_FRAME;
	return ;
};

void	Phonebook::_searchContact(void) const{
	int	index = -1;
	this->_displayDirectory();
	std::string contact_index = userInput(
								SEARCH_TYPE, "\tENTER CONTACT'S INDEX",
								&index);
	if(index < 0){
		return ;
	}
	Contact temp = this->directory[index];
	if (!temp._getRegistration()){
		std::cout << NO_REGIST;
		return ;
	}
	std::cout << std::endl;
	std::cout << "\tFULL NAME:      " << temp._getFirstName() << SPACE;
	std::cout << temp._getLastName() << std::endl;
	std::cout << "\tNICKNAME:       " << temp._getNickName() << std::endl;
	std::cout << "\tDARKEST SECRET: " << temp._getSecret() << std::endl;
	std::cout << "\tPHONE NUMBER:   " << temp._getPhoneNumber() << std::endl;
	return ;
};
