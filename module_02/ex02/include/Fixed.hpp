/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:35:15 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/16 15:04:36 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP_
# define	FIXED_HPP_

# include <iostream>
# include <cmath>

class Fixed {
	private:
		int					_fixed_value;
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

		/* Overload comparaison operands */
		bool	operator>( const Fixed &rhs ) const;
		bool	operator>=( const Fixed &rhs ) const;
		bool	operator<( const Fixed &rhs ) const;
		bool	operator<=( const Fixed &rhs ) const;
		bool	operator==( const Fixed &rhs ) const;
		bool	operator!=( const Fixed &rhs ) const;

		/* Incrementation & Decrementation */
		Fixed	&operator++( void );
		Fixed	&operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		static const Fixed &min_( const Fixed &first, const Fixed &second );
		static const Fixed &max_( const Fixed &first, const Fixed &second );
		static Fixed &min_( Fixed &first, Fixed &second );
		static Fixed &max_( Fixed &first, Fixed &second );

		Fixed operator*( const Fixed &rhs ) const;
		Fixed operator/( const Fixed &rhs ) const;
		Fixed operator+( const Fixed &rhs ) const;
		Fixed operator-( const Fixed &rhs ) const;
};	/* Fixed */

std::ostream &operator<<( std::ostream &o, const Fixed &rhs);

#endif	/*	FIXED_HPP_	*/
