/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:30:59 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/21 12:41:01 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CLAPTRAP_HPP_
# define	CLAPTRAP_HPP_

# include	<iostream>

/******************************************************************************/
/******************************************************************************/

# ifndef	EMPTY_STR
#  define	EMPTY_STR	""
# endif	/*	EMPTY_STR	*/

# ifndef	EXIT_SUCCESS
#  define	EXIT_SUCCESS 0
# endif	/*	EXIT_SUCCESS	*/

/********************************** MESSAGES **********************************/

# ifndef	MSG_CLAPTRAP
#  define	MSG_CLAPTRAP	"ClapTrap "
# endif	/*	MSG_CLAPTRAP	*/

# ifndef	MSG_ATTACKS
#  define	MSG_ATTACKS		" attacks "
# endif	/*	MSG_ATTACKS	*/

# ifndef	MSG_CAUSING
#  define	MSG_CAUSING		", causing "
# endif	/*	MSG_CAUSING	*/

# ifndef	MSG_DAMAGE
#  define	MSG_DAMAGE		" points of damage!"
# endif	/*	MSG_DAMAGE	*/

# ifndef	MSG_CONSTRUCTOR
#  define	MSG_CONSTRUCTOR " Constructor called."
# endif	/*	MSG_CONSTRUCTOR	*/

# ifndef	MSG_DESTRUCTOR
#  define	MSG_DESTRUCTOR	" Destructor called."
# endif	/*	MSG_DESTRUCTOR	*/

/*********************************** POINTS ***********************************/

/* Default amount of Hit Points (life). */
# ifndef	CT_DEFAULT_HIT
#  define	CT_DEFAULT_HIT		10
# endif	/*	CT_DEFAULT_HIT	*/

/* Default amount of Energy. */
# ifndef	CT_DEFAULT_ENERGY
#  define	CT_DEFAULT_ENERGY	10
# endif	/*	CT_DEFAULT_ENERGY	*/

/* Default amount of damage point(s) inflicted on the enemy. */
# ifndef	CT_DEFAULT_ATTACK
#  define	CT_DEFAULT_ATTACK	0
# endif	/*	CT_DEFAULT_ATTACK	*/

# ifndef	COST_ATTACK
#  define	COST_ATTACK	1
# endif	/*	COST_ATTACK	*/

# ifndef	COST_REPAIR
#  define	COST_REPAIR	1
# endif	/*	COST_REPAIR	*/

# ifndef	CT_DEAD
#  define	CT_DEAD		0
# endif	/*	CT_DEAD	*/

/******************************************************************************/
/******************************************************************************/

class ClapTrap {
	private:
		std::string	_name;
		/// @note Decreases when enemy attack, or increases from repairing.
		int			_hit_point;
		/// @note Decreases by <COST> when attacking, or repairing.
		int			_energy_point;
		/// @note Affects enemy's hit points when attacking.
		int			_attack_damage;
	
	public:
		ClapTrap	&operator=( const ClapTrap &rhs ); // Assignation overload.
		ClapTrap	( const ClapTrap &source ); // Copy constructor.
		ClapTrap	( void ); // Default constructor.
		~ClapTrap	( void ); // Default destructor.

		ClapTrap	( const std::string name ); // Parameterized constructor.

		/* ACTION FUNCTION */
		void	attack		( const std::string &target );
		void	takeDamage	( unsigned int amount );
		void	beRepaired	( unsigned int amount );

		/* SETTER+GETTER */
		std::string	getName			( void ) const;
		int			getHitPoint		( void ) const;
		int			getEnergyPoint	( void ) const;
		int			getAttackDamage	( void ) const;

		void	setName			( const std::string name );
		void	setHitPoint		( const int points );
		void	setEnergyPoint	( const int points );
		void	setAttackDamage	( const int points );
		void	subEnergyPoint	( const int points );
		void	subHitPoint		( const int points );
		void	addHitPoints	( const int points );
		
}	/*	ClapTrap	*/;

#endif	/*	CLAPTRAP_HPP_	*/
