/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:13:56 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/10 21:02:55 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>

# ifndef REPLACE_EXT
#  define REPLACE_EXT ".replace"
#  endif /* REPLACE_EXT */

# ifndef EMPTY
#  define EMPTY ""
# endif /* EMPTY */

/******************************************************************************/

class Replace {
	private:
		std::ifstream	_infile;
		std::ofstream	_outfile;

		std::string		_needle;
		std::string		_substitute;
		
	public:
		Replace( void );
		~Replace( void );

		bool	setInfile( const std::string filename );
		bool	setOutfile( const std::string filename );
		
		void	setNeedle( const std::string needle );
		void	setSubstitute( const std::string substitute );
		
		void	substitute( void );
};

#endif /* REPLACE_HPP */
