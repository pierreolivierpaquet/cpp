/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:22:33 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/11 21:04:59 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

void	randomChump(std::string zombie_name){
	Zombie generate(DEFAULT_ZOMBIE_NAME);

	if (zombie_name.length() == 0 && std::cin.eof()){
		std::cout << "EOF: Default name used." << std::endl;
	}
	else
		generate.setName(zombie_name);
	generate.announce();
};