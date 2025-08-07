/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:48:15 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/07 11:49:26 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					raw_bit;
		static const int	fraction = 8;

		public:
		Fixed();
		Fixed(const int raw_bit);
		Fixed(const float raw_bit);
		~Fixed();
		Fixed(Fixed const &copy);
		
		Fixed	&operator=(Fixed const &copy);

		Fixed	operator+(Fixed const &fixed) const;
		Fixed	operator-(Fixed const &fixed) const;
		Fixed	operator*(Fixed const &fixed) const;
		Fixed	operator/(Fixed const &fixed) const;

		bool	operator==(Fixed const &fixed) const;
		bool	operator!=(Fixed const &fixed) const;
		bool	operator<=(Fixed const &fixed) const;
		bool	operator>=(Fixed const &fixed) const;
		bool	operator<(Fixed const &fixed) const;
		bool	operator>(Fixed const &fixed) const;
		
		Fixed	&operator++(void);
		Fixed	operator++(int raw_bit);
		Fixed	&operator--(void);
		Fixed	operator--(int raw_bit);
		
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);

		void	setRawBits(int const raw);
		int		getRawBits(void) const;
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed_nbr);