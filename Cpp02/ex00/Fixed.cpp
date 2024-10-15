#include "Fixed.hpp"

Fixed::Fixed():fixedPoint(0){ // 기본 생성자
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a){ // 복사 생성자
    std::cout << "Copy constructor called" << std::endl;
    // *this = a;
    fixedPoint = a.getRawBits();// 이렇게 하는 게 더좋다?
}

// 왜 레퍼런스로 넘겨주나?
Fixed &Fixed::operator=(const Fixed &a){ // 할당 연산자 오버로딩
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &a){ // 자신에게 대입하는 경우를 방지
        fixedPoint = a.getRawBits();
    }
    return *this;
}

Fixed::~Fixed(){ // 소멸자
    std::cout << "Destructor called" << std::endl;
} 

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPoint;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    fixedPoint = raw;
}