/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:34:20 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/20 11:56:32 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Contact.hpp"
#include "Phonebook.hpp"

/// @brief Takes input from user, and stores it into Phonebook.
bool	log_info(
	Phonebook book)
{
	std::string action;
	action = EMPTY;
	
	std::cout   << BANNER_FRAME << MSG_WELCOME << std::endl;
	std::cout   << ADD_INSTRUCTIONS \
				<< SEARCH_INSCTRUCTIONS \
				<< EXIT_INSTRUCTIONS << BANNER_FRAME;
	while (WAIT_INPUT)
	{
		std::cout << INPUT_PROMPT;
		std::getline(std::cin, action);
		if (!action.compare(EXIT))
			return (true);
		else if (!action.compare(ADD))
			book.addContact();
		else if (!action.compare(SEARCH))
			book._searchContact();
		if (std::cin.eof())
			return (true);
		std::cin.clear();
		action.clear();
		action = EMPTY;
	}
	return (true);
};

int	main(
	int argc,
	char **argv)
{
	(void)argc;
	(void)argv;
	Phonebook book;
	log_info(book);
	return (EXIT_SUCCESS);	
};