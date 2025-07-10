/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:48:14 by lgrisel           #+#    #+#             */
/*   Updated: 2025/07/08 15:15:10 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): value(0)
{
}

Fixed::Fixed(const int input)
{
	this->value = input << Fixed::fraction;
}

Fixed::Fixed(const float input)
{
	this->value = roundf(input * float(1 << Fixed::fraction));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &src)
{
	this->value = src.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}

Fixed	Fixed::operator+(Fixed const &fixed) const
{
	Fixed	res;

	res.value = this->value + fixed.value;
	return (res);
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	Fixed	res;

	res.value = this->value - fixed.value;
	return (res);
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	Fixed	res;

	res.value = (long(this->value)
		* long(fixed.value)) >> Fixed::fraction;
	return (res);
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
	Fixed	res;

	res.value = (long(this->value)
		<< long(Fixed::fraction)) / fixed.value;
	return (res);
}

Fixed	&Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	res(*this);

	this->value++;
	return (res);
}

Fixed	&Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	res(*this);

	this->value--;
	return (res);
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return (this->value > fixed.value);
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	return (this->value < fixed.value);
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return (this->value >= fixed.value);
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return (this->value <= fixed.value);
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return (this->value == fixed.value);
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return (this->value != fixed.value);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

void	Fixed::setRawBits(int const fp_value)
{
	this->value = fp_value;
}

int	Fixed::getRawBits(void) const
{
	return (this->value);
}

float	Fixed::toFloat(void) const
{
	return (float(this->value) / float(1 << Fixed::fraction));
}

int	Fixed::toInt(void) const
{
	return (this->value >> Fixed::fraction);
}