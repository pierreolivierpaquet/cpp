/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:34:20 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/15 21:34:03 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Contact.hpp"
#include "Phonebook.hpp"

/// @brief Takes input from user, and stores it into Phonebook.
bool	log_info(
	Phonebook book){
	std::string action;
	action = EMPTY;
	std::cout << MSG_WELCOME;
	std::cout << ADD_INSTRUCTIONS << SEARCH_INSCTRUCTIONS << EXIT_INSTRUCTIONS;
	while (WAIT_INPUT)
	{
		std::cout << INPUT_PROMPT;
		std::getline(std::cin, action);
		if (!action.compare(EXIT)){
			return (true);
		}
		else if (!action.compare(ADD)){
			book.addContact();
		}
		else if (!action.compare(SEARCH)){
			book._searchContact();
		}
		std::cin.clear();
		action.clear();
		action = EMPTY;
	}
	return (true);
};

int	main(
	int argc,
	char **argv){
	(void)argc;
	(void)argv;
	Phonebook book;
	log_info(book);
	return (EXIT_SUCCESS);	
};