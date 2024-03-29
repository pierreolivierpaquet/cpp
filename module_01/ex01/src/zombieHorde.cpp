/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:17:45 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/12 12:11:29 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"

Zombie *zombieHorde( int N, std::string name ){
	Zombie *new_horde = NULL;
	int		i = -1;
	
	if (N < 0){
		return (NULL);
	}
	new_horde = new Zombie[ N ];
	
	/*	Horde name(s) initialization.	*/
	while (++i < N){
		new_horde[i].setName(name);
		
		/*	*** If zombieHorde needs to announce itself. ***	*/
		// std::cout << "Zombie #" << (i + 1) << std::endl << "\t";
		// new_horde[i].announce();
	}
	
	return (new_horde);
};
