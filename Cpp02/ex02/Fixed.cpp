#include "Fixed.hpp"

Fixed::Fixed():fixedPoint(0){ // 기본 생성자
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num){ // 정수 → 고정 소수점
    std::cout << "Int constructor called" << std::endl;
    fixedPoint = num << fractionalBits;
}

Fixed::Fixed(const float num){ // 실수 → 고정소수점
    std::cout << "Float constructor called" << std::endl;
    fixedPoint = static_cast<int>(roundf(num * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &a){ // 복사 생성자
    std::cout << "Copy constructor called" << std::endl;
    *this = a;
}

Fixed &Fixed::operator=(const Fixed &a){ // 할당 연산자 오버로딩
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &a){ // 자신에게 대입하는 경우를 방지
        fixedPoint = a.fixedPoint;
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

float Fixed::toFloat(void) const{ // 고정 소수점 → 실수
    return static_cast<float>(fixedPoint) / (1<<fractionalBits);
}

int Fixed::toInt(void) const{ // 고정 소수점 → 정수
    return fixedPoint >> fractionalBits;
}

std::ostream& operator<<(std::ostream& o, const Fixed& f){
    o << f.toFloat();
	return o;
}

// 비교 연산자
bool Fixed::operator>(const Fixed &a) const{
    return this->fixedPoint > a.getRawBits();
}

bool Fixed::operator<(const Fixed &a) const{
    return this->fixedPoint < a.getRawBits();
}

bool Fixed::operator>=(const Fixed &a) const{
    return this->fixedPoint >= a.getRawBits();
}

bool Fixed::operator<=(const Fixed &a) const{
    return this->fixedPoint <= a.getRawBits();
}

bool Fixed::operator==(const Fixed &a) const{
    return this->fixedPoint == a.getRawBits();
}

bool Fixed::operator!=(const Fixed &a) const{
    return this->fixedPoint != a.getRawBits();
}

// 산술 연산자
Fixed Fixed::operator+(const Fixed &a) const{
    float num1 = this->toFloat();
    float num2 = a.toFloat();
    return Fixed(num1+num2);

}

Fixed Fixed::operator-(const Fixed &a) const{
    float num1 = this->toFloat();
    float num2 = a.toFloat();
    return Fixed(num1-num2);
}

Fixed Fixed::operator*(const Fixed &a) const{
    float num1 = this->toFloat();
    float num2 = a.toFloat();
    return Fixed(num1*num2);
}

Fixed Fixed::operator/(const Fixed &a) const{
    float num1 = this->toFloat();
    float num2 = a.toFloat();
    return Fixed(num1/num2);
}


// 증감 연산자
Fixed &Fixed::operator++(){ // 전위 증가
    fixedPoint++;
    return *this;
}

Fixed Fixed::operator++(int) { // 후위 증가
    Fixed newNum(*this);
    this->fixedPoint++;
    return newNum;
}

Fixed &Fixed::operator--() { // 전위 감소
    fixedPoint--;
    return *this;
}

Fixed Fixed::operator--(int) { // 후위 감소
    Fixed newNum(*this);
     this->fixedPoint--;
    return newNum;
}

// 정적 함수

Fixed &Fixed::min(Fixed &a, Fixed &b){
    return (a.toFloat() < b.toFloat()) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b){
    return (a.toFloat() < b.toFloat()) ?  a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b){
    return (a.toFloat() > b.toFloat()) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b){
    return (a.toFloat() > b.toFloat()) ?  a : b;
}
