/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:03:36 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/15 14:08:36 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FIXED_HPP_
# define	FIXED_HPP_

# include <iostream>

class Fixed {
	private:
		int					_fixed_value;
		static const int	_nbits;

	public:
	/* Constructors */
		Fixed( void );	// Default.
		Fixed( Fixed const &src );	// Copy.
		//Fixed( /* Insert parameter here. */ );	// Parametric.

	/* Destructor */
		~Fixed( void );	// Default.

	/* Overload operands. */
		Fixed &operator=( Fixed const &rhs );	// Assignation.

		int		getRawBits_( void ) const;
		void	setRawBits( int const raw );
};	/* Fixed */

#endif	/*	FIXED_HPP_	*/
