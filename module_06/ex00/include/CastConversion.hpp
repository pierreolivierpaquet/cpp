/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CastConversion.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 07:34:41 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/14 14:09:27 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CASTCONVERSION_HPP_
# define	CASTCONVERSION_HPP_

# include	<iostream>
# include	<sstream> // for number extraction
// # include	<limits>

# include	<cstring>

# ifndef	FLOAT_CHAR
#  define	FLOAT_CHAR	"f"
# endif	/*	FLOAT_CHAR	*/

# ifndef	POINT_CHAR
#  define	POINT_CHAR	"."
# endif	/*	DOUBLE_CHAR	*/

# ifndef	SIGN_CHARS
#  define	SIGN_CHARS	"+-"
# endif	/*	SIGN_CHARS	*/

# ifndef	DIGIT_CHARS
#  define	DIGIT_CHARS	"0123456789"
# endif	/*	DIGIT_CHARS	*/

# ifndef	NOT_FOUND
#  define	NOT_FOUND	std::string::npos
# endif	/*	NOT_FOUND	*/

class Conversion {
	private:
		typedef enum conv {
			C_ERROR,
			C_NAN,		//	nan
			C_NANF,		//	nanf
			C_INF,		//	+inf
			C_MINF,		//	-inf
			C_INFF,		//	+inff
			C_MINFF,	//	-inff
			C_CHAR,		//	character
			C_INT,		//	integer
			C_DOUBLE,	//	double
			C_FLOAT,	//	float
			C_UNDEFINED
		} conv_type_t;

		bool	isError(	std::string input ) const;
		bool	isNan(		std::string input ) const;
		bool	isNanf(		std::string input ) const;
		bool	isInf(		std::string input ) const;
		bool	isInff(		std::string input ) const;
		bool	isMinf(		std::string input ) const;
		bool	isMinff(	std::string input ) const;
		bool	isChar(		std::string input ) const;
		bool	isInt(		std::string input ) const;
		bool	isDouble(	std::string input ) const;
		bool	isFloat(	std::string input ) const;

//	----------------------------------------------------------------------------
		const std::string	_program_input;
		conv_type_t			_conversion_type;
		
		char				_char_cast;
		int					_int_cast;
		double				_double_cast;
		float				_float_cast;

		typedef	bool(Conversion::*typeIdentifier)(std::string input) const;
		typeIdentifier	_type_id[ C_UNDEFINED ];
		void			_mapping_type_id( void );
		typedef void(Conversion::*setOriginType)(void);
		setOriginType	_origin_type[ 4 ];
		void			_mapping_origin_type( void );
		typedef void(Conversion::*convertFromType)(void);
		convertFromType	_from_type[ 4 ];
		void			_mapping_from_type( void );
		void			_convert( void );

		void	_setChar(	void );
		void	_setInt(	void );
		void	_setDouble(	void );
		void	_setFloat(	void );

		void	_convertFromChar(	void );
		void	_convertFromInt(	void );
		void	_convertFromDouble(	void );
		void	_convertFromFloat(	void );
	public:
//	CONSTRUCTOR.S --------------------------------------------------------------
		Conversion( std::string program_input ); // Default.
		Conversion( const Conversion &rhs );

//	DESTRUCTOR.S ---------------------------------------------------------------
		~Conversion( void );

//	OVERLOAD.S -----------------------------------------------------------------
		Conversion &operator=( const Conversion &rhs );

//	GETTER.S -------------------------------------------------------------------
		conv_type_t 	getConversionType(	void ) const;
		std::string		getProgramInput(	void ) const;
		char			getChar(			void ) const;
		int				getInt(				void ) const;
		float			getFloat(			void ) const;
		double			getDouble(			void ) const;

//	SETTER.S -------------------------------------------------------------------

//	FUNCTION.S -----------------------------------------------------------------
	

};	//	Conversion

#endif	/*	CASTCONVERSION_HPP_	*/
