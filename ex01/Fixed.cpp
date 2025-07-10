/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrisel <lgrisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 10:52:10 by lgrisel           #+#    #+#             */
/*   Updated: 2025/07/08 14:44:33 by lgrisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static	float ft_pow(float base, int exp)
{
	float	result;

	if (!exp)
		return (1);
	if (exp < 0)
	{
		base = 1 / base;
		exp *= -1;
	}
	result = base;
	while (--exp)
		result *= base;
	return (result);
}


Fixed::Fixed(void): value(0)
{
	std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const int value): value(value * ft_pow(2, this->fraction))
{  
	std::cout << "Int constructor called" << std::endl; 
} 

Fixed::Fixed(const float value): value((int)(value * (1 << this->fraction) + (value >= 0 ? 0.5f : -0.5f)))
{  
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
	return (this->value * ft_pow(2, -this->fraction));
}

int	Fixed::toInt(void) const
{
	return (this->value * ft_pow(2, -this->fraction));
}

Fixed	&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->value = copy.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr)
{
	return (str << fixed_nbr.toFloat());
}