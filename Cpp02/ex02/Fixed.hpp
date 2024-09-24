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

         // 비교 연산자 오버로딩
        bool operator>(const Fixed &a) const;
        bool operator<(const Fixed &a) const;
        bool operator>=(const Fixed &a) const;
        bool operator<=(const Fixed &a) const;
        bool operator==(const Fixed &a) const;
        bool operator!=(const Fixed &a) const;

        // 산술 연산자 오버로딩
        Fixed operator+(const Fixed &a) const;
        Fixed operator-(const Fixed &a) const;
        Fixed operator*(const Fixed &a) const;
        Fixed operator/(const Fixed &a) const;

        // 증감 연산자 오버로딩
        Fixed &operator++();    // 전위 증가
        Fixed operator++(int);  // 후위 증가
        Fixed &operator--();    // 전위 감소
        Fixed operator--(int);  // 후위 감소

        // 정적 함수
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};
std::ostream& operator<<(std::ostream& o, const Fixed& f);

#endif