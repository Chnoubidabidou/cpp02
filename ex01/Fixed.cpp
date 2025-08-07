/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:10 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/07 11:43:36 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): raw_bit(0)
{
	std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const int input)
{
	this->raw_bit = input << Fixed::raw_bit;
	std::cout << "Int constructor called" << std::endl; 
}

Fixed::Fixed(const float input)
{
	this->raw_bit = roundf(input * float(1 << Fixed::fraction));
	std::cout << "Float constructor called" << std::endl; 
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const & copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

void	Fixed::setRawBits(const int raw)
{
	this->raw_bit = raw;
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

Fixed	&Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->raw_bit = src.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &stream, Fixed const &fixed_nbr)
{
	stream << fixed_nbr.toFloat();
	return (stream);
}
