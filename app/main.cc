#include <iostream>

#include "app/hello/hello.h"
#include "app/world/world.h"

int main(int /*argc*/, char** /*argv*/) {
  std::cout << hello() << " " << world() << std::endl;
  return 0;
}
