/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaquet <pierreolivierpaquet@hotmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 09:59:39 by ppaquet           #+#    #+#             */
/*   Updated: 2024/02/21 14:35:14 by ppaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BASE_HPP_
# define	BASE_HPP_

# include	<iostream>

# ifndef	EXIT_SUCCESS
#  define	EXIT_SUCCESS	0
# endif	/*	EXIT_SUCCESS	*/

# ifndef	BASE_A
#  define	BASE_A	0
# endif	/*	BASE_A	*/

# ifndef	BASE_B
#  define	BASE_B	1
# endif	/*	BASE_B	*/

# ifndef	BASE_C
#  define	BASE_C	2
# endif	/*	BASE_C	*/

class	Base {
	public:
		Base();
		virtual ~Base(	void );
};	/*	Base	*/

#endif	/*	BASE_HPP_	*/
