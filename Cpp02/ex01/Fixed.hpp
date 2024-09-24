#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed{
    private:
        int fixed_point;
        static const int fractional_bits=8;
    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &a);
        Fixed &operator= (const Fixed &a);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);

        float toFloat(void) const;
        int toInt(void) const;
};
std::ostream& operator<<(std::ostream& o, const Fixed& f);

#endif 