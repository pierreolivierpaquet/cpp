/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:22:31 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/08 15:20:53 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string zombie_name){
	Zombie *create = new Zombie(DEFAULT_ZOMBIE_NAME);
	
	if (zombie_name.length() == 0 && std::cin.eof()){
		std::cout << "EOF: Default name used." << std::endl;
	}
	else
		create->setName(zombie_name);
	return (create);
};
