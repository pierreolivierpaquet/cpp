/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:31:08 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/21 14:06:10 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRAGTRAP_HPP_
# define	FRAGTRAP_HPP_

# include "ScavTrap.hpp"

/********************************** MESSAGE ***********************************/

# ifndef	MSG_FRAGTRAP
#  define	MSG_FRAGTRAP	"FragTrap "
# endif	/*	MSG_FRAGTRAP	*/

/*********************************** POINTS ***********************************/

/* Default amount of Hit Points (life). */
#ifndef		FT_DEFAULT_HIT
# define	FT_DEFAULT_HIT		100
#endif	/*	FT_DEFAULT_HIT	*/

/* Default amount of Energy. */
#ifndef		FT_DEFAULT_ENERGY
# define	FT_DEFAULT_ENERGY	100
#endif	/*	FT_DEFAULT_ENERGY	*/

/* Default amount of damage point(s) inflicted on the enemy. */
#ifndef		FT_DEFAULT_ATTACK
# define	FT_DEFAULT_ATTACK	30
#endif	/*	FT_DEFAULT_ATTACK	*/

/******************************************************************************/
/******************************************************************************/

class FragTrap : public ClapTrap {
	public:
	/* Constructors */
		FragTrap( void );	// Default.
		FragTrap( FragTrap const &src );	// Copy.
		FragTrap( std::string name );	// Parameterized.

	/* Destructor */
		~FragTrap( void );	// Default.

	/* Overload operands. */
		FragTrap &operator=( FragTrap const &rhs );	// Assignation.

		void	attack( const std::string &target );
		
	/* FragTrap specialty. */
		void	highFivesGuys( void );
};	/* FragTrap */

#endif	/*	FRAGTRAP_HPP_	*/
