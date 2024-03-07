/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 08:49:38 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/07 10:52:59 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BITCOINEXCHANGE_HPP_
# define	BITCOINEXCHANGE_HPP_

# include	<iostream>
# include	<fstream>
# include	<cstring> // memset
# include	<limits>
# include	<list>
# include	<vector>

# ifndef	EMPTY_STR
#  define	EMPTY_STR	""
# endif	/*	EMPTY_STR	*/

class	BitcoinExchange {
	private:
		std::string		_infile_name;
		std::ifstream	_infile;

	public:
///	---------------------------------------- @class CONSTRUCTOR.S - DESTRUCTOR.S
		BitcoinExchange( void );
		BitcoinExchange( const BitcoinExchange &rhs );
		~BitcoinExchange( void );

///	------------------------------------------------------------ @class OPERANDS

		BitcoinExchange &operator=( const BitcoinExchange &rhs );

///	------------------------------------------------------------ @class GETTER.S

		std::string	getInfileName( void ) const;

};	/*	BitcoinExchange	*/

#endif	/*	BITCOINEXCHANGE_HPP_	*/