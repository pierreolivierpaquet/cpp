/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:15:58 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/11 21:49:31 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Replace.hpp"

/// ---
/// @brief 
/// 
bool	Replace::setInfile( const std::string filename ){
	if (filename.empty() == true || this->_infile.is_open() == true){
		return ( false );
	} else {
		this->_infile.open( filename.c_str() );
		if (this->_infile.is_open() == false){
			return ( false );
		}
	}
	return ( true );
}

/// ---
/// @brief 
/// 
bool	Replace::setOutfile( const std::string filename ){
	if (filename.empty() == true || this->_outfile.is_open() == true){
		return ( false );
	} else {
		this->_outfile.open( filename.c_str() );
		if (this->_outfile.is_open() == false){
			return ( false );
		}
	}
	return ( true );
}

/// ---
/// @brief 
/// 
void	Replace::setNeedle( const std::string needle ){
	this->_needle = needle;
	return ;
}

/// ---
/// @brief 
///
void	Replace::setSubstitute( const std::string substitute ){
	this->_substitute = substitute;
	return ;
}

/// ---
/// @brief 
/// 
void	Replace::substitute( void ){
	size_t	i;
	size_t	n;
	std::string	line = EMPTY;

	while (true){
		getline( this->_infile, line );
		i = 0;
		n = 0;
		while ( i < line.length() ){
			n = line.find( this->_needle, i );
			/*	If needle was NOT found, n will be equivalent to the maximum
				value of size_t (std::string::npos), which is a static member
				of std::string.	*/
			if (n != std::string::npos){
				line.erase( n, this->_needle.length() );
				line.insert( n, this->_substitute.c_str(), this->_substitute.length() );
				i += ( n + this->_substitute.length() );
			} else {
				i = line.length();
			}
		}
		if (this->_infile.eof() == true){
			break ;
		} 
		if (line.empty()){
			this->_outfile << std::endl;
		} else {
			this->_outfile << line << std::endl;
		}
		line.clear();
	}
	return ;
}

/******************************************************************************/

/// ---
/// @brief Default constructor.
/// 
Replace::Replace( void ){}

/// ---
/// @brief Destructor.
///  
Replace::~Replace( void ){
	if (this->_infile.is_open() == true){
		this->_infile.close();
	} else if (this->_outfile.is_open() == true){
		this->_outfile.close();
	}
	return ;
}
