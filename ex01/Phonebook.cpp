/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:35:04 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/18 13:05:15 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <sstream> // string to int

/// @brief Constructor function
Phonebook::Phonebook(void) : contactIndex(0) {};

void	Phonebook::incrementIndex(void){
	this->contactIndex++;
	this->contactIndex %= CONTACT_MAX;
};

/// @brief Checks that the string is under a valid phone number format.
bool	is_phoneNumber(
	std::string phone_number){
	std::size_t	i = -1;
	std::size_t l = phone_number.length();
	while (++i < l)
	{
		if (!isdigit(phone_number[i]) && phone_number[i] != '-')
		{
			return(false);
		}
	}
	return (true);
}

bool	is_searchable(
	std::string index,
	int *i_index){
	std::size_t	i = -1;
	std::size_t	l = index.length();
	if (l > 1)
		return (false);
	while (++i < l)
	{
		if (!isdigit(index[i]))
		{
			return (false);
		}
	}
	std::istringstream result(index);
	result >> *i_index;
	if (*i_index < 0 || *i_index > 7)
	{
		return (false);
	}
	return (true);
};

std::string	userInput(
	size_t input_type,
	std::string prompt,
	int *index){
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
		std::cin.clear();
		input.clear();
		input = SPACE;
	}
	return (input);
};

void	Phonebook::setContact(
	size_t index){
	this->directory[index].setFirstName(
							userInput(TEXT_TYPE, "\t1. FIRST NAME", NULL));
	this->directory[index].setLastName(
							userInput(TEXT_TYPE, "\t2. LAST NAME", NULL));
	this->directory[index].setNickName(
							userInput(TEXT_TYPE, "\t3. NICK NAME", NULL));
	this->directory[index].setSecret(
							userInput(TEXT_TYPE, "\t4. DARKEST SECRET", NULL));
	this->directory[index].setPhoneNumber(
							userInput(PHONE_TYPE, "\t5. PHONE NUMBER", NULL));
	this->directory[index].setRegistered();
	return ;
};

void	Phonebook::addContact(void){
	Phonebook::setContact(this->contactIndex);
	Phonebook::incrementIndex();
};

void	printSpace(std::size_t i){
	while (i-- > 0){
		std::cout << SPACE;
	}
	return;
};

void	printSubString(std::string sub_name){
	std::cout << sub_name.substr(0, 9) << ".";
};

void	printInfo(std::string sub_name){
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

void	displayInfo(Contact info){
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
	std::cout << ".~~~~~~~~~~.~~~~~~~~~~.~~~~~~~~~~.~~~~~~~~~~." << std::endl;
	std::cout << SEPARATOR << " INDEX    " << SEPARATOR \
		<< " FRST NM. " << SEPARATOR \
		<< " LST NM.  " << SEPARATOR \
		<< " NCKNM.   " << SEPARATOR << std::endl;
	std::cout << "|~~~~~~~~~~'~~~~~~~~~~'~~~~~~~~~~'~~~~~~~~~~|" << std::endl;
	while (i < CONTACT_MAX){
		std::cout << SEPARATOR << "        " << i << "." << SEPARATOR;
		displayInfo(this->directory[i]);
		i++;
	}
	std::cout << "'~~~~~~~~~~'~~~~~~~~~~'~~~~~~~~~~'~~~~~~~~~~'" << std::endl;
	return ;
};

void	Phonebook::_searchContact(void) const{
	int	index;
	this->_displayDirectory(); // test
	std::string contact_index = userInput(
								SEARCH_TYPE, "ENTER CONTACT'S INDEX",
								&index);
	Contact temp = this->directory[index];
	if (!temp._getRegistration())
	{
		std::cout << "SORRY; NO REGISTERED CONTACT AT THIS INDEX." << std::endl;
		return ;
	}
	std::cout << temp._getFirstName() << SPACE;
	std::cout << temp._getLastName() << std::endl;
	std::cout << temp._getNickName() << std::endl;
	std::cout << temp._getSecret() << std::endl;
	std::cout << temp._getPhoneNumber() << std::endl;
	return ;
};
