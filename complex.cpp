#include<iostream>
#include<memory>

class Complex
{
  private:
	int xCoordinate;
	int yCoordinate;
	std::string msg;
  public:
	  Complex(int xParam, int yParam, std::string paramMsg):xCoordinate(xParam), yCoordinate(yParam), msg(paramMsg)
	{
	     std::cout << "constructor " << msg << std::endl;
	}
	Complex getComplex(void)
	{
		std::cout << "return this " << msg << std::endl;
		return *this;
	}
	 void printXYCoordinates(void)
	{
		std::cout << "x = " << xCoordinate << " y = " << yCoordinate << std::endl;
	}
	~Complex()
	{
	    std::cout << "destructor " << msg << std::endl;	    
	}
	
};

int main()
{
	Complex myNum = Complex(3, 6, "tg36").getComplex();
	myNum.printXYCoordinates();
    std::cout << std::endl;

	Complex(8, 8,"t88").printXYCoordinates();
	std::cout << std::endl;

	Complex(9, 0,"tg90").getComplex().printXYCoordinates();
	std::cout << std::endl;
	
	std::shared_ptr<Complex> myNumPtr = std::make_shared<Complex>(4, 4,"t44");
	myNumPtr->printXYCoordinates();
	std::cout << std::endl;
	
	std::shared_ptr<Complex> myNumPtr2(new Complex(5,5,"t55"));
	myNumPtr2->printXYCoordinates();
	std::cout << std::endl;
	
	std::unique_ptr<Complex> myNumPtr3(new Complex(7,7,"t77"));
	myNumPtr3->printXYCoordinates();
	std::cout << std::endl;
}