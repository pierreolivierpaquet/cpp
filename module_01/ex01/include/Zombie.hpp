/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:22:24 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 12:03:31 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# ifndef DEFAULT_ZOMBIE_NAME
#  define DEFAULT_ZOMBIE_NAME "ZOMBOY"
# endif /* DEFAULT_ZOMBIE_NAME */

class Zombie {
	private:
		std::string name;
		
	public:
		Zombie( void ); // Default constructor
		~Zombie( void );

		void 		setName(std::string zombie_name);
		std::string _getName( void ) const;
		void		announce( void );
};

Zombie *zombieHorde(int N, std::string name);

#endif /* ZOMBIE_HPP */