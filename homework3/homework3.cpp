#include "my_unique_ptr.hpp"
#include <iostream>

int main()
{
    int* ptr1{new int}, *ptr2{new int};
    *ptr1 = 1;
    *ptr2 = 2;
    my_unique_ptr::unique_ptr<int> _ptr1{ptr1};
    my_unique_ptr::unique_ptr<int> _ptr2{ptr2};
    std::cout << *_ptr1 << ' ' << *_ptr2;
    my_unique_ptr::unique_ptr<int> _ptr3{_ptr1.release()};
    std::cout << std::endl << *_ptr3;
    return EXIT_SUCCESS;
}