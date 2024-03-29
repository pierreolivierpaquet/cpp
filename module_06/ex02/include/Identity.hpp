/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:53:54 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/22 08:43:25 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		IDENTITY_HPP_
# define	IDENTITY_HPP_

# include	"../include/Base.hpp"
class Base;

# include	<stdlib.h>	// rand(); srand()
# include	<time.h>	// time()

# ifndef	IDENTIFIED_ID
#  define	IDENTIFIED_ID	"\tClass identified as "
# endif	/*	IDENTIFIED_ID	*/

# ifndef	UNIDENTIFIED_ID
#  define	UNIDENTIFIED_ID	"\tNo derived class identified."
# endif	/*	UNIDENTIFIED_ID	*/

class	A : public Base {
	public:
		A( void );
		~A( void );
};	/*	A	*/

class	B : public Base {
	public:
		B( void );
		~B( void );
};	/*	B	*/

class	C : public Base {
	public:
		C( void );
		~C( void );
};	/*	C	*/

namespace	idt {
	static	time_t	random_seed;
	Base	*generate( void );
	void	identify( Base *p );
	void	identify( Base &p );
	void	displayId( std::string id, bool by_reference );
}

#endif	/*	IDENTITY_HPP_	*/
