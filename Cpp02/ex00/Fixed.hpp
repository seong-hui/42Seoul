#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
    private:
        int fixed_point;
        static const int fractional_bits=8;
    public:
        Fixed();
        Fixed(const Fixed &a);
        Fixed &operator= (const Fixed &a);
        ~Fixed();
        int getRawBits(void);
        void setRawBits(int const raw);
};

#endif