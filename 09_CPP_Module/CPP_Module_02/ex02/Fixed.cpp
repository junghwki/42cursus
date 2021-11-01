#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->_rawBits = 0;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
	//this->_rawBits = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	//std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = fixed.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw * (1 << this->_fractonalBits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (1 << this->_fractonalBits));
}

int Fixed::toInt(void) const
{
	return (this->_rawBits >> this->_fractonalBits);
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << std::endl;
	this->_rawBits = (num * (1 << this->_fractonalBits));
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called" << std::endl;
	this->_rawBits = roundf(num * (1 << this->_fractonalBits));
}

bool Fixed::operator>(Fixed &fixed)
{
	return (this->_rawBits > fixed._rawBits);
}

bool Fixed::operator<(Fixed &fixed)
{
	return (this->_rawBits < fixed._rawBits);
}

bool Fixed::operator>=(Fixed &fixed)
{
	return (this->_rawBits >= fixed._rawBits);
}

bool Fixed::operator<=(Fixed &fixed)
{
	return (this->_rawBits <= fixed._rawBits);
}

bool Fixed::operator==(Fixed &fixed)
{
	return (this->_rawBits == fixed._rawBits);
}

bool Fixed::operator!=(Fixed &fixed)
{
	return (this->_rawBits != fixed._rawBits);
}

Fixed& Fixed::operator+(const Fixed& fixed)
{
	this->_rawBits = this->_rawBits + fixed._rawBits;
	return (*this);
}

Fixed& Fixed::operator-(const Fixed& fixed)
{
	this->_rawBits = this->_rawBits - fixed._rawBits;
	return (*this);
}

Fixed& Fixed::operator*(const Fixed& fixed)
{
	this->_rawBits = this->_rawBits * fixed._rawBits * (1 >> this->_fractonalBits);
	return (*this);
}
Fixed& Fixed::operator/(const Fixed& fixed)
{
	this->_rawBits = this->_rawBits / fixed._rawBits * (1 << this->_fractonalBits);
	return (*this);
}

Fixed& Fixed::operator++(void)
{
	Fixed ret(this->_rawBits);

	ret._rawBits = this->_rawBits++;
	return (ret);
}

Fixed& Fixed::operator--(void)
{
	Fixed ret(this->_rawBits);

	ret._rawBits = this->_rawBits--;
	return (ret);
}

Fixed& Fixed::operator++(int)
{
	this->_rawBits++;
	return (*this);
}

Fixed& Fixed::operator--(int)
{
	this->_rawBits--;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Fixed const &value)
{
	out << value.toFloat();
	return (out);
}