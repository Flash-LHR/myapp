#include <cstring>
#include <iostream>

#include "app/hello/hello.h"
#include "app/world/world.h"

int main() {
  std::cout << hello(1) + world() << std::endl;
  return 0;
}
