/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 20:12:09 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/20 22:14:26 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCAVTRAP_HPP_
# define	SCAVTRAP_HPP_

# include	"ClapTrap.hpp"

/*********************************** POINTS ***********************************/

/* Amount of points recovered during life regeneration. */
# ifndef	ST_DEFAULT_HIT
#  define	ST_DEFAULT_HIT	100
# endif	/*	ST_DEFAULT_HIT	*/

/* Energy level. */
# ifndef	ST_DEFAULT_ENERGY
#  define	ST_DEFAULT_ENERGY	50
# endif	/*	ST_DEFAULT_ENERGY	*/

/* Number of damage point(s) suffered by the enemy. */
# ifndef	ST_DEFAULT_ATTACK
#  define	ST_DEFAULT_ATTACK	20
# endif	/*	ST_DEFAULT_ATTACK	*/

/********************************** MESSAGES **********************************/

# ifndef	MSG_SCAVTRAP
#  define	MSG_SCAVTRAP	"ScavTrap "
# endif	/*	MSG_SCAVTRAP	*/

/******************************************************************************/

class ScavTrap : public ClapTrap {
	public:
	/* Constructors */
		ScavTrap( void );	// Default.
		ScavTrap( ScavTrap const &src );	// Copy.
		ScavTrap( std::string name );	// Parametric.

	/* Destructor */
		~ScavTrap( void );	// Default.

	/* Overload operands. */
		ScavTrap &operator=( ScavTrap const &rhs );	// Assignation.

		void	attack( const std::string &target );
};	/* ScavTrap */

#endif	/*	SCAVTRAP_HPP_	*/
