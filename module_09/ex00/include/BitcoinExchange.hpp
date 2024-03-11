/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:49:38 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/11 10:09:34 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BITCOINEXCHANGE_HPP_
# define	BITCOINEXCHANGE_HPP_

# include	<iostream>
# include	<fstream>
# include	<sstream> // stringstream
# include	<ctime> // get year
# include	<limits>
# include	<map>
# include	<cstdlib> // u_int32_t
// # include	<list>
// # include	<vector>

# ifndef	EMPTY_STR
#  define	EMPTY_STR		""
# endif	/*	EMPTY_STR	*/

# ifndef	CSV_FILENAME
#  define	CSV_FILENAME	"/home/ppaquet/Documents/cpp/module_09/ex00/data.csv"
# endif	/*	CSV_FILENAME	*/

# ifndef	CSV_DELIMITER
#  define	CSV_DELIMITER	","
# endif	/*	CSV_DELIMITER	*/

# ifndef	INPUT_DELIMITER
#  define	INPUT_DELIMITER	"|"
# endif	/*	INPUT_DELIMITER	*/

# ifndef	ARROW
#  define	ARROW			" => "
# endif	/*	ARROW	*/


# define	INPUT_CHAR		"0123456789-|., "

typedef enum	{
		DAY,
		MONTH,
		YEAR
	}	e_current_time;

typedef struct s_data {
	std::pair<std::string, std::string>	origin_data;
	u_int32_t	year;
	u_int32_t	month;
	u_int32_t	day;
	float		value;
	bool	operator==(const struct s_data &comp) const;
	bool	operator<(const struct s_data &comp) const;
} t_data;

/// @brief Input file token pair ( "first * second" ).
typedef std::pair< std::string, std::string > tokenPair;

typedef std::map< size_t, t_data > ifMap;
typedef	std::pair< size_t, t_data > ifPair;

class	BitcoinExchange {
	private:
	
		static const std::string _csv_name; // Static data CSV file.

		BitcoinExchange( void );
		std::string		_infile_name;	//	provided filename for input
		std::ifstream	_infile;	// infile stream from input.
		std::ifstream	_csv;	// infile stream from CSV data sheet.

		ifMap	_infile_map;
		ifMap	_csv_map;

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

		class	BadInput : public std::exception {
			public:
				virtual const char *what( void ) const throw();
		};
		class	ValueTooLarge : public std::exception {
			public:
				virtual const char *what( void ) const throw ();
		};
		class	ValueNegative : public std::exception {
			public:
				virtual const char *what( void ) const throw ();
		};

///	---------------------------------------------------------- @class FUNCTION.S

	void	display( void );

};	/*	BitcoinExchange	*/

#endif	/*	BITCOINEXCHANGE_HPP_	*/
