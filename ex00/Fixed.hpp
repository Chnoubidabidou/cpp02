/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 12:34:19 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/07 11:33:04 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	
	private:
		int					raw_bit;
		static const int	fraction = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();

		Fixed	&operator=(const Fixed &copy);
		int		getRawBits(void)const;
		void	setRawBits(int const raw);
};