/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:46:46 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/12 12:33:40 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HUMANA_HPP_
# define	HUMANA_HPP_

# include	"Weapon.hpp"

class HumanA {
	private:
		std::string	_name;
		Weapon		&_Weapon;

	public:
		HumanA( const std::string name, Weapon &weaponRef );
		~HumanA( void );
	
		std::string 		getName( void ) const;
		const std::string	getWeaponType_( void ) const;
		
		void		attack( void );
};

#endif	/*	HUMANA_HPP_	*/
