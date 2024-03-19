/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:28:00 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/19 11:54:46 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

void	displayComparison( const PmergeMe< deque_t > &deque, const PmergeMe< vector_t > &vector ) {
	std::cout	<< "Before:\t";
	deque.printUnsorted();
	std::cout	<< "After:\t";
	deque.printSortedDeque();
	std::cout	<< "Time to process a range of " << deque.getSize() << "\t"
				<< "elements with " << deque.getTypeInfo() << " : ";
	deque.printDuration();
	std::cout	<< "Time to process a range of " << vector.getSize() << "\t"
				<< "elements with " << vector.getTypeInfo() << " : ";
	vector.printDuration();
	return ;
}
