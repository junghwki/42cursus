#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int _rawBits;
	static const int _fractonalBits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& fixed);
	Fixed(const int num);
	Fixed(const float num);
	Fixed& operator=(const Fixed& fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, Fixed const& fixed);

#endif
