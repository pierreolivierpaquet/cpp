/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:46 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/09 17:54:54 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon &_Weapon;

	public:
		HumanA(const std::string name, Weapon &weaponRef);
		~HumanA( void );
	
		void		attack( void );
		std::string _getName( void ) const;
		std::string _getWeaponType( void ) const;
};

#endif /* HUMANA_HPP */