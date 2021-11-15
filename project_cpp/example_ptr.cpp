/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
#include <memory>
using namespace std;

  

class MyClass {  
public:   MyClass(int a) : var(a)   { }
    void printInfo() {   
        cout << var<<endl;
        cout << this->var<<endl;
        cout << (*this).var<<endl; 
     }
private:   int var;
};

/*
class Item
{
public:
	Item() { std::cout << "Item acquired\n"; }
	~Item() { std::cout << "Item destroyed\n"; }
	friend std::ostream& operator<<(std::ostream& out, const Item &item)
	{
		out << "I am an Item!\n";
		return out;
	}
};
*/

    struct Counter;

    Counter* createCounter(std::uint32_t i);
    void destroyCounter(Counter*);
    Counter* createCounter(std::uint32_t i){
        Counter *p2 ;
        return p2;
    }

    class Wrapper {
        public:
            Wrapper(): rustStruct(CounterPtr(createCounter(0))) {}
           std::uint32_t bla(){
               return 78;
           } 
        //private:
            struct Deleter {
                void operator()(Counter* rs) const {
                    destroyCounter(rs);
                }
            };

            typedef std::unique_ptr<Counter, Deleter> CounterPtr;

            CounterPtr rustStruct;
    }; // class Wrapper
    
 
int main() {
    
    Wrapper ptr ();
   std::cout <<  *ptr  <<endl; 
    /*
    MyClass obj {7};
	obj.printInfo();
	
  std::unique_ptr<Item> variable(new Item);
 
	if (variable) // используем неявное преобразование item в тип bool, чтобы убедиться, что item владеет Item-ом
		std::cout << *variable; // выводим Item, которым владеет item
		*/
	return 0;
}
