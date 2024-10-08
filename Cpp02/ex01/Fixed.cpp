#include "Fixed.hpp"

Fixed::Fixed():fixed_point(0){ // 기본 생성자
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num){ // 정수 → 고정 소수점
    std::cout << "Int constructor called" << std::endl;
    fixed_point = num << fractional_bits;
}

Fixed::Fixed(const float num){ // 실수 → 고정소수점
    std::cout << "Float constructor called" << std::endl;
    fixed_point = static_cast<int>(roundf(num * (1 << fractional_bits)));
}

Fixed::Fixed(const Fixed &a){ // 복사 생성자
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
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

int Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return fixed_point;
}

void Fixed::setRawBits(int const raw){
    std::cout << "setRawBits member function called" << std::endl;
    fixed_point = raw;
}

float Fixed::toFloat(void) const{ // 고정 소수점 → 실수
    return static_cast<float>(fixed_point) / (1<<fractional_bits);
}

int Fixed::toInt(void) const{ // 고정 소수점 → 정수
    return fixed_point >> fractional_bits;
}

std::ostream& operator<<(std::ostream& o, const Fixed& f){
    o << f.toFloat();
	return o;
}
// 고정 소수점 출력시 toFloat()을 적용해 부동소수점으로 값을 출력할 수 있도록 
// ostream 클래스의 << 연산자를 오버로딩 해줌
// 고정소수점 값을 실수로 출력할 수 있게 하기 위해 삽입 연산자를 오버로딩