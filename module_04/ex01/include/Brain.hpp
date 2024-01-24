/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:15:24 by ppaquet           #+#    #+#             */
/*   Updated: 2024/01/24 16:05:11 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BRAIN_HPP_
# define	BRAIN_HPP_

#include <iostream>

# ifndef	N_IDEAS
#  define	N_IDEAS	100
# endif	/*	N_IDEAS	*/

class	Brain {
	private:
		std::string	_ideas[ N_IDEAS ];
		size_t		_iBrain; // Index of ideas array.
		
	protected:
	
	public:
	/* Constructors */
		Brain( void ); // Default
		Brain( const Brain &src ); // Reference copy.

	/* Overload operands */
		Brain &operator=( const Brain &rhs ); // Assignation overload.
		
	/* Destructor */
		~Brain( void ); // Default.
		
	/* Setter + Getter */
		const std::string	getIdeas( const size_t index ) const;
		void	setIdeas( const std::string idea );
		void	setIdeas( const std::string idea, const size_t index );
		
};	/*	Brain	*/

#endif	/*	BRAIN_HPP_	*/