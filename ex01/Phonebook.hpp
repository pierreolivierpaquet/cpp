/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:29:20 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/18 11:25:31 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

/// @brief Listing of all contacts.
class Phonebook {
	private:
		size_t	contactIndex;
		Contact		directory[ CONTACT_MAX ];

	public:
		// Constructor & Destructor
		Phonebook(void);
		~Phonebook(void) {};

		void	addContact(void);

		// Getters & Setters
		void	setContact(size_t index);
		void	incrementIndex(void);
		void	_searchContact(void) const;
		void	_displayDirectory(void) const;
};

#endif /* PHONEBOOK_HPP */