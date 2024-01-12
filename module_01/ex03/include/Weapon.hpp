/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:52 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/12 12:30:51 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WEAPON_HPP_
# define	WEAPON_HPP_

#include	<iostream>

# ifndef	ATTACK_ACTION
#  define	ATTACK_ACTION " attacks with their "
# endif	/*	ATTACK_ACTION	*/

class Weapon {
	private:
		std::string	_type;
	
	public:
		Weapon( const std::string weapon_type );
		~Weapon( void );

		const std::string	&getType_( void ) const;
		void				setType( const std::string weapon_type );
};

#endif	/*	WEAPON_HPP_	*/
