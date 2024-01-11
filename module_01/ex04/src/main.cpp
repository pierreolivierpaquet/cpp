/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 08:36:34 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/10 20:00:17 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

/// ---
/// @param err_message Message to be displayed on the std::cerr stream.
/// @return Error value (FAILURE).
///
bool	error( const std::string err_message ){
	std::cerr << err_message << std::endl;
	return ( false );
}

/// ---
/// @brief Validates the amount of arguments provided by User.
///	Displays messages in case of error.
/// @param N Number of arguments.
///
bool	arguments_check( int argc , char **argv, Replace &data){
	std::string checker = EMPTY;
	
	/* Validates the amount of argument(s) */
	if (argc != 4){
		if (argc == 1){
			return (error( "Please provide: <filename> <search> <replace>." ));
		} else if (argc < 4){
			return (error( "Too few arguments." ));
		} else if (argc > 4){
			return (error( "Too many arguments." ));
		}
	}
	/* Parse each arguments of the array and validates their lenght */
	for (int i = 1; i < argc; i++){
		checker = argv[i];
		if (checker.length() == 0){
			return (error( "Invalid argument: Make sure it's not empty." ));
		} else {
			checker.clear();
		}
	}
	data.setNeedle( argv[2] );
	data.setSubstitute( argv[3] );
	return ( true );
}

/// ---
/// @brief Opens the file for further reading manipulations. Also create a new
/// file for its modified version.
/// @param filename Name of the file which needs to be opened and replaced.
/// @return Wether the process was SUCCESSFUL, or not.
///
bool	files_handler( char *filename, Replace &data){
	std::string name(filename);

	if (data.setInfile( name ) != true){
		return ( error("error: Opening infile.") );
	}
	/* Adds the extension to the name for the modified version. */
	name.append(REPLACE_EXT);
	if (data.setOutfile( name ) != true){
		return ( error("error: Creating outfile.") );
	}
	return ( true );
}

/// ---
/// @brief 
///
int	main( int argc, char **argv ){
	Replace data;
	
	if (arguments_check( argc, argv, data) == false || 
		files_handler( argv[1] , data) == false){
		return ( FAILURE );
	}
	/* Proceed with the substitution of argv[2] with argv[3]. */
	data.substitute();
	return ( SUCCESS );
}
