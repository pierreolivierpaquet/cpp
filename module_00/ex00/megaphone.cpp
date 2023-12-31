/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:13:18 by ppaquet           #+#    #+#             */
/*   Updated: 2023/12/20 16:01:51 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#ifndef MEGAPHONE
# define MEGAPHONE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
#endif /* MEGAPHONE */

#ifndef SPACE
# define SPACE " "
#endif /* SPACE */

void	str_toupper(
	std::string& str)
{
	std::size_t	i = 0;
	std::size_t l = str.length();
	while (i < l){
		str[i] = toupper(str[i]);
		i++;
	}
	i = 0;
	return ;
}

int	main(
	int argc,
	char **argv)
{
	if (argc == 1)
		return (std::cout << MEGAPHONE << std::endl, EXIT_SUCCESS);
	int	i = 0;
	while (++i < argc){
		std::string louder = argv[i];
		if (louder.empty())
			return (louder.clear(), EXIT_SUCCESS);
		str_toupper(louder);
		std::cout << louder;
		louder.clear();
	}
	return (std::cout << std::endl, EXIT_SUCCESS);
}
