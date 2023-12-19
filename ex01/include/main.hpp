/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:54 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/19 14:52:14 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <cstdlib>

# ifndef WAIT_INPUT
#  define WAIT_INPUT 1
# endif /* WAIT_INPUT */

# ifndef SPACE
#  define SPACE " "
# endif /* SPACE */

# ifndef TAB
#  define TAB "\t"
# endif /* TAB */

# ifndef DOT
#  define DOT "."
# endif /* DOT */

# ifndef EMPTY
#  define EMPTY ""
# endif /* EMPTY */

# ifndef SEPARATOR
#  define SEPARATOR "|"
# endif /* SEPARATOR */

# define TEXT_TYPE 1
# define PHONE_TYPE 0
# define SEARCH_TYPE 2

/******************************************************************************/
/********************************* MESSAGES ***********************************/

# define BANNER_FRAME "-----------------------------------------------------\n"
# define MSG_WELCOME "\tWELCOME TO YOUR PHONEBOOK.\n"
# define ADD_INSTRUCTIONS "\tENTER > \'ADD\' FOR A NEW CONTACT.\n"
# define SEARCH_INSCTRUCTIONS "\tENTER > \'SEARCH\' TO LOOK FOR A CONTACT.\n"
# define EXIT_INSTRUCTIONS "\tENTER > \'EXIT\' TO QUIT PHONEBOOK.\n"

# ifndef INPUT_PROMPT
#  define INPUT_PROMPT " > "
# endif /* INPUT_PROMPT */

/******************************************************************************/
/******************************** IDENTIFIERS *********************************/

# ifndef ADD
#  define ADD "ADD"
# endif /* ADD */

# ifndef SEARCH
#  define SEARCH "SEARCH"
# endif /* SEARCH */

# ifndef EXIT
#  define EXIT "EXIT"
# endif /* EXIT */

#endif /* MAIN_HPP */