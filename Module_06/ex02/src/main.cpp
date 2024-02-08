#include "Base.hpp"

int main() {
  Base *base = generate();
  Base *_null = NULL;
  identify(base);
  identify(*base);
  identify(_null);
  identify(*_null);
  delete base;
}