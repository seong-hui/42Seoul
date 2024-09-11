#include "Fixed.hpp"

Fixed::Fixed():fixed_point(0){ // 기본 생성자
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &a){ // 복사 생성자
    std::cout << "Copy constructor called" << std::endl;
    fixed_point = a.fixed_point;
}

Fixed &Fixed::operator=(const Fixed &a){ // 할당 연산자 오버로딩
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &a){ // 자신에게 대입하는 경우를 방지
        fixed_point = a.fixed_point;
    }
    return *this;
}

Fixed::~Fixed(){ // 소멸자
    std::cout << "Destructor called" << std::endl;
} 

int Fixed::getRawBits(void){
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    fixed_point = raw;
}