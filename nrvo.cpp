#include <iostream>
 
struct C {
  C() {}
  C(const C&) { std::cout << "A copy was made.\n"; }
  C(const C&&) { std::cout << "A move was occured.\n"; }
};
 
C f() {
  return C();
}
 
int main() {
  std::cout << "Hello World!\n";
  C obj = f();
  return 0;
}
