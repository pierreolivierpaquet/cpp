/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:03:36 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/17 10:12:46 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP_
# define	FIXED_HPP_

# include	<iostream>

class Fixed {
	private:
		int					_fixed_value;
		static const int	_nbits;

	public:
	/* Constructors */
		Fixed( void );	// *Canonical* Default.
		Fixed( Fixed const &src );	// *Canonical* Copy.
		//Fixed( /* Insert parameter here. */ );	// Parametric.

	/* Destructor */
		~Fixed( void );	// *Canonical* Default.

	/* Overload operands. */
		Fixed	&operator=( Fixed const &rhs );	// *Canonical* Assignation.

		int		getRawBits_( void ) const;
		void	setRawBits( int const raw );
};	/* Fixed */

#endif	/*	FIXED_HPP_	*/
