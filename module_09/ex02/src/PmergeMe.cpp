/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:28:00 by ppaquet           #+#    #+#             */
/*   Updated: 2024/03/18 13:36:05 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

void	displayComparison( const PmergeMe< deque_t > &deque, const PmergeMe< vector_t > &vector ) {
	std::cout	<< "Before:\t";
	deque.printUnsorted();
	std::cout	<< "After:\t";
	deque.printSortedDeque();
	std::cout	<< "Time to process a range of\t" << deque.getSize() << " "
				<< "elements with " << deque.getTypeInfo() << "\t: ";
	deque.printDuration();
	std::cout	<< "Time to process a range of\t" << vector.getSize() << " "
				<< "elements with " << vector.getTypeInfo() << "\t: ";
	vector.printDuration();
	return ;
}
