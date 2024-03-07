/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:49:38 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/07 17:17:56 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BITCOINEXCHANGE_HPP_
# define	BITCOINEXCHANGE_HPP_

# include	<iostream>
# include	<fstream>
# include	<cstring>
# include	<limits>
# include	<map>
# include	<cstdlib> // u_int32_t
// # include	<list>
// # include	<vector>

# ifndef	EMPTY_STR
#  define	EMPTY_STR		""
# endif	/*	EMPTY_STR	*/

# ifndef	CSV_FILENAME
#  define	CSV_FILENAME	"data.csv"
# endif	/*	CSV_FILENAME	*/

# define	INPUT_CHAR		"0123456789-| "

typedef struct s_data {
	std::pair<std::string, std::string>	origin_data;
	u_int32_t	year;
	u_int32_t	month;
	u_int32_t	day;
	float		value;
} t_data;

typedef std::map<size_t, t_data> ifMap;

class	BitcoinExchange {
	private:
	
		static const std::string _csv_name; // Static data CSV file.

		BitcoinExchange( void );
		std::string		_infile_name;	//	provided filename for input
		std::ifstream	_infile;	// infile stream from input.
		std::ifstream	_csv;	// infile stream from CSV data sheet.

		ifMap _infile_map;

	public:
///	---------------------------------------- @class CONSTRUCTOR.S - DESTRUCTOR.S
		BitcoinExchange( std::string f_name );
		BitcoinExchange( const BitcoinExchange &rhs );
		~BitcoinExchange( void );

///	------------------------------------------------------------ @class OPERANDS

		BitcoinExchange &operator=( const BitcoinExchange &rhs );

///	------------------------------------------------------------ @class GETTER.S

		std::string	getInfileName( void ) const;

///	------------------------------------------------------------ @class SETTER.S

		void	setInfileName( std::string name );

///	----------------------------------------------------- @class NESTED CLASS.ES

///	---------------------------------------------------------- @class FUNCTION.S

	void	display( void );

};	/*	BitcoinExchange	*/

#endif	/*	BITCOINEXCHANGE_HPP_	*/
