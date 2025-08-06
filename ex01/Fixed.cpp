/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:10 by lgrisel           #+#    #+#             */
/*   Updated: 2025/08/05 12:20:15 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void): value(0)
{
	std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const int input)
{
	this->value = input << Fixed::value;
	std::cout << "Int constructor called" << std::endl; 
}

Fixed::Fixed(const float input)
{
	this->value = roundf(input * float(1 << Fixed::fraction));
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
	this->value = raw;
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

Fixed	&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = copy.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	str << fixed_nbr.toFloat();
	return (str);
}
