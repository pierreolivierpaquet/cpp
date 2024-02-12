/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastConversion.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 07:34:41 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/12 15:02:38 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CASTCONVERSION_HPP_
# define	CASTCONVERSION_HPP_

# include	<iostream>
# include	<limits>

# include	<cstring>

# ifndef	NUM_INCL
#  define	NUM_INCL	"+-.0123456789f"
# endif	/*	NUM_EXCL	*/

class Conversion {
	private:
		typedef enum conv {
			C_UNDEFINED,
			C_CHAR,
			C_INT,
			C_FLOAT,
			C_DOUBLE,
			C_NAN,
			C_NANF,
			C_INF,
			C_ERROR = 100
		} conv_type_t;

		const std::string	_program_input;
		conv_type_t			_conversion_type;
		
		int					_int_cast;
		float				_float_cast;
		double				_double_cast;
		char				_char_cast;

		void	_setType( void );

	public:
//	CONSTRUCTOR.S --------------------------------------------------------------
		Conversion( std::string program_input ); // Default.
		Conversion( const Conversion &rhs );

//	DESTRUCTOR.S ---------------------------------------------------------------
		~Conversion( void );

//	OVERLOAD.S -----------------------------------------------------------------
		Conversion &operator=( const Conversion &rhs );

//	GETTER.S -------------------------------------------------------------------
		conv_type_t 	getConversionType( void ) const;
		std::string		getProgramInput( void ) const;
		char			getChar( void ) const;
		int				getInt( void ) const;
		float			getFloat( void ) const;
		double			getDouble( void ) const;

//	SETTER.S -------------------------------------------------------------------

//	FUNCTION.S -----------------------------------------------------------------
	

};	//	Conversion

#endif	/*	CASTCONVERSION_HPP_	*/

