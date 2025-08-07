/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:48:14 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/07 11:47:26 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): raw_bit(0)
{
}

Fixed::Fixed(const int input)
{
	this->raw_bit = input << Fixed::fraction;
}

Fixed::Fixed(const float input)
{
	this->raw_bit = roundf(input * float(1 << Fixed::fraction));
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
	if (this != &src)
		this->raw_bit = src.getRawBits();
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

	res.raw_bit = this->raw_bit + fixed.raw_bit;
	return (res);
}

Fixed	Fixed::operator-(Fixed const &fixed) const
{
	Fixed	res;

	res.raw_bit = this->raw_bit - fixed.raw_bit;
	return (res);
}

Fixed	Fixed::operator*(Fixed const &fixed) const
{
	Fixed	res;

	res.raw_bit = (long(this->raw_bit) * long(fixed.raw_bit)) >> Fixed::fraction;
	return (res);
}

Fixed	Fixed::operator/(Fixed const &fixed) const
{
	Fixed	res;

	res.raw_bit = (long(this->raw_bit) << long(Fixed::fraction)) / fixed.raw_bit;
	return (res);
}

Fixed	&Fixed::operator++(void)
{
	this->raw_bit++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	res(*this);

	this->raw_bit++;
	return (res);
}

Fixed	&Fixed::operator--(void)
{
	this->raw_bit--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	res(*this);

	this->raw_bit--;
	return (res);
}

bool	Fixed::operator>(Fixed const &fixed) const
{
	return (this->raw_bit > fixed.raw_bit);
}

bool	Fixed::operator<(Fixed const &fixed) const
{
	return (this->raw_bit < fixed.raw_bit);
}

bool	Fixed::operator>=(Fixed const &fixed) const
{
	return (this->raw_bit >= fixed.raw_bit);
}

bool	Fixed::operator<=(Fixed const &fixed) const
{
	return (this->raw_bit <= fixed.raw_bit);
}

bool	Fixed::operator==(Fixed const &fixed) const
{
	return (this->raw_bit == fixed.raw_bit);
}

bool	Fixed::operator!=(Fixed const &fixed) const
{
	return (this->raw_bit != fixed.raw_bit);
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
	this->raw_bit = fp_value;
}

int	Fixed::getRawBits(void) const
{
	return (this->raw_bit);
}

float	Fixed::toFloat(void) const
{
	return (float(this->raw_bit) / float(1 << Fixed::fraction));
}

int	Fixed::toInt(void) const
{
	return (this->raw_bit >> Fixed::fraction);
}
