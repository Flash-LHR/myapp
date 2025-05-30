#include "app/hello/hello.h"

#include <iostream>
#include <string>

std::string hello(int x) noexcept {
  int y = x + 1;
  std::cout << y << std::endl;
  return "Hello";
}
