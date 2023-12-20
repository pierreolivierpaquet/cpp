/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:48:33 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/20 13:18:07 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

# ifndef CONTACT_MAX
#  define CONTACT_MAX 8
# endif /* CONTACT_MAX */

class	Contact {
	private:
		bool		registered;
		std::string	first_name;
		std::string	last_name;
		std::string	nick_name;
		std::string	secret;
		std::string	phone_number;

	public:

		Contact(void);
		~Contact(void);
		
		void		setRegistered(void);
		void		setFirstName(std::string first_name);
		void		setLastName(std::string last_name);
		void		setNickName(std::string nick_name);
		void		setSecret(std::string secret);
		void		setPhoneNumber(std::string phone_number);
		
		bool		_getRegistration(void) const;
		std::string _getFirstName(void) const;
		std::string _getLastName(void) const;
		std::string _getNickName(void) const;
		std::string _getSecret(void) const;
		std::string _getPhoneNumber(void) const;
};

#endif /* CONTACT_HPP */
