/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:35:15 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/17 13:49:32 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP_
# define	FIXED_HPP_

# include	<iostream>
# include	<cmath>

class Fixed {
	private:
		int					_fixed_point;
		static const int	_nbits;			

	public:
	/* Constructors */
		Fixed( void );	// Default.
		Fixed( Fixed const &src );	// Copy.
		Fixed( const int integer_number );	// Parametric.
		Fixed( const float float_number );	// Parametric.

	/* Destructor */
		~Fixed( void );	// Default.

	/* Overload operands. */
		Fixed &operator=( Fixed const &rhs );	// Assignation.

		int		getRawBits_( void ) const;
		void	setRawBits( const int raw);

		float	toFloat_( void ) const;
		int		toInt_( void ) const;

};	/* Fixed */

std::ostream &operator<<( std::ostream &o, const Fixed &rhs);

#endif	/*	FIXED_HPP_	*/
