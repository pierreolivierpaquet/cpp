/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:22:24 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/11 20:47:35 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ZOMBIE_HPP_
# define	ZOMBIE_HPP_

# include	<iostream>

# ifndef	DEFAULT_ZOMBIE_NAME
#  define	DEFAULT_ZOMBIE_NAME "ZOMBOY"
# endif	/*	DEFAULT_ZOMBIE_NAME	*/

class Zombie {
	private:
		std::string _name;
		
	public:
		Zombie( void );
		~Zombie( void );

		void 		setName( std::string zombie_name );
		std::string getName( void ) const;
		
		void		announce( void );
};

Zombie *zombieHorde( int N, std::string name );

#endif	/*	ZOMBIE_HPP_	*/