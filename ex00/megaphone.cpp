/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:13:18 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/15 14:35:45 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>

#ifndef MEGAPHONE
# define MEGAPHONE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
#endif /* MEGAPHONE */

#ifndef SPACE
# define SPACE " "
#endif /* SPACE */

void	str_toupper(
	std::string& str){
	std::size_t	i = -1;
	std::size_t l = str.length();
	while (++i < l)
		str[i] = toupper(str[i]);
	i = 0;
	return ;
}

int	main(
	int argc,
	char **argv){
	if (argc == 1){
		return (std::cout << MEGAPHONE << std::endl, EXIT_SUCCESS);
	}
	int	i = 0;
	while (++i < argc){
		std::string louder = argv[i];
		if (louder.empty())
			return (louder.clear(), EXIT_SUCCESS);
		str_toupper(louder);
		std::cout << louder;
		if (i + 1 != argc)
			std::cout << SPACE;
		louder.clear();
	}
	return (std::cout << std::endl, EXIT_SUCCESS);
}
