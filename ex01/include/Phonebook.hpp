/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:29:20 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/20 13:14:05 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

/********************************** GRAPHIC ***********************************/

# ifndef TOP_FRAME
#  define TOP_FRAME ".~~~~~~~~~~.~~~~~~~~~~.~~~~~~~~~~.~~~~~~~~~~.\n"
# endif /* TOP_FRAME */

# ifndef MIDDLE_FRAME
#  define MIDDLE_FRAME "|~~~~~~~~~~'~~~~~~~~~~'~~~~~~~~~~'~~~~~~~~~~|\n"
# endif /* MIDDLE_FRAME */

# ifndef BOTTOM_FRAME
#  define BOTTOM_FRAME "'~~~~~~~~~~'~~~~~~~~~~'~~~~~~~~~~'~~~~~~~~~~'\n"
# endif /* BOTTOME_FRAME */

/******************************************************************************/

# ifndef NO_REGIST
#  define NO_REGIST "\t*** NO REGISTERED CONTACT AT THIS INDEX. ***\n"
# endif /* NO_REGIST */

class Phonebook {
	private:
		size_t		contactIndex;
		Contact		directory[CONTACT_MAX];

	public:
		Phonebook(void);
		~Phonebook(void);

		void	addContact(void);

		void	setContact(size_t index);
		void	incrementIndex(void);
		void	_searchContact(void) const;
		void	_displayDirectory(void) const;
};

#endif /* PHONEBOOK_HPP */