/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:49 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 17:55:05 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

# ifndef DEFAULT_WEAPON
#  define DEFAULT_WEAPON "bare hands"
# endif /* DEFAULT_WEAPON */

class HumanB {
	private:
		std::string _name;
		Weapon *_Weapon;

	public:
		HumanB(const std::string name);
		~HumanB( void );

		void		setWeapon(Weapon &new_weapon);
		std::string	_getWeaponType( void ) const;
		std::string	_getName( void ) const;
		void		attack( void );
};

#endif /* HUMANB_HPP */