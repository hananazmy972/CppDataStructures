#include <iostream>
using namespace std;

    int main() {
    string food = "Pizza"; // A food variable of type string
    cout << food <<"\n";  // Outputs the value of food (Pizza)
    cout << &food <<"\n"; // Outputs the memory address of food (0x6dfed4)

    //pinter
    string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food

    // Output the value of food (Pizza)
    cout << food << "\n";

    // Output the memory address of food 
    cout << &food << "\n";

    // Output the memory address of food with the pointer
    cout << ptr << "\n";
   
    // There are three ways to declare pointer variables, but the first way is preferred:
    // string* mystring; // Preferred
    // string *mystring;
   //  string * mystring;

    // Reference: Output (the memory address) of food with the pointer 
    cout << ptr << "\n";

    // Dereference: Output (the value) of food with the pointer
    cout << *ptr << "\n";

    // Change the value of the pointer
    *ptr = "Hamburger";
    cout << *ptr << "\n";
    
    // Output the new value of the food variable  (this will also change the value of the original variable)
    cout << food << "\n";

  return 0;
}