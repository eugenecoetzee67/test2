#include <iostream>
#include <typeinfo> 

int x = 6;

struct Test {
  Test() {}
  Test(const Test&) { std::cout << "A copy was made.\n"; }
  Test(const Test&&) { std::cout << "A move was occured.\n"; }
};
 
Test f() {
  return Test();
}

int getInt(void)
{
    return x;

}  


int&& getRvalueInt(void)
{

    return std::move(x);

} 

void printAddress(const int& paramInt)
{ 
    std::cout << "paramInt = " << paramInt << " at address = " << reinterpret_cast<const void*>(&paramInt) << std::endl;  

}


 
int main() {
  std::cout << "Hello World!\n";
  Test obj = f();
  std::cout << typeid(obj).name() << std::endl; 
  std::cout << "x = " << x << " at address = " << &x <<std::endl;
  printAddress(x);
  printAddress(getInt());
  printAddress(getRvalueInt());
  printAddress(x); 
  int myMovedX = getRvalueInt();
  printAddress(myMovedX);
  printAddress(x);
  
  return 0;
}
