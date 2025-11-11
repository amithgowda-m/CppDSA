#include <iostream>
using namespace std;

// new int → allocates memory on the heap (not on the stack). Heap memory survives after the function ends.
// *ptr = 1200 → stores value in that heap memory.
// ptr itself is a pointer variable on the stack, which stores the address of the heap memory.
// return ptr → gives main() the address of the heap memory. This is safe.

int* ret(){
    int *ptr = new int;
    *ptr = 1200;
    cout<<"ptr points to "<<*ptr;
    cout<<"\nptr is : "<<ptr;
    return ptr;
}
int main(){
    int *x = ret();
    cout<<"\n the valur is"<<*x;
    cout<<"\n x :"<<x;
    delete x; // free heap memory
    x = nullptr; // optional but good practice
//ptr and x point to the same heap memory.
// *ptr / *x = the value stored (1200).
// ptr / x = the address of that memory.
// Heap memory survives function return, unlike stack variables.

    return 0;
}

// | Concept        | Stack                    | Heap                                 |
// | -------------- | ------------------------ | ------------------------------------ |
// | Where it lives | Function variables       | Dynamically allocated memory         |
// | Lifetime       | Ends when function exits | Lives until `delete` or program ends |
// | Access         | Direct                   | Via pointer                          |
// | Example here   | `ptr` inside `ret()`     | `*ptr` (the integer it points to)    |
