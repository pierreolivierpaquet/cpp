/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:22:21 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 09:57:15 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# ifndef DEFAULT_ZOMBIE_NAME
#  define DEFAULT_ZOMBIE_NAME "Normie"
# endif /* DEFAULT_ZOMBIE_NAME */

class Zombie {
	private:
		std::string	name;
		
	public:
		Zombie(std::string zombie_name);
		~Zombie( void );

		std::string _getName( void ) const;
		void		setName(std::string const zombie_name);
		void		announce( void );
};

void	randomChump(std::string zombie_name);

Zombie *newZombie(std::string zombie_name);

#endif /* ZOMBIE_HPP */