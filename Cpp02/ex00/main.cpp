
#include "Fixed.hpp"

int main( void ) {
  Fixed a;
  Fixed b( a );
  Fixed c;
  Fixed c = b; // 복사 생성자 실행됨. 왜?
c = b;
  std::cout << a.getRawBits() << std::endl;
  std::cout << b.getRawBits() << std::endl;
  std::cout << c.getRawBits() << std::endl;
return 0; 
}