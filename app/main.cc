#include <iostream>

#include "app/hello/hello.h"
#include "app/world/world.h"

int main() {
  std::cout << hello() + world() << std::endl;
  return 0;
}
