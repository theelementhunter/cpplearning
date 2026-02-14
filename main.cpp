#include <iostream>
#include <cmath>
#include "SmartIntArray.h"

void test_function() {
    std::cout << "#--- Inside Function ---#" << std::endl;

    // Array Size
    int array_size = 7;

    // Build Specific instance of SmartIntArray Class
    SmartIntArray array_1(array_size);

    // Manually putting things in the array
    array_1[0] = 1;
    array_1[1] = 2;


    // Looping to fill the array and print its values
    for (int i = 0; i < array_size; i++) {
        array_1[i] = static_cast<int>(std::pow(i, 2));
        std::cout << "Inside index " << i << ": "<< array_1[i] << std::endl;
    }

    //Using our helper function
    std::cout << array_1.getSize() << " <-- Array Size" << std::endl;

    // Destructor Activates as soon as the ending bracket comes
    std::cout << "#--- Destructor is destructing ---#" << std::endl;

    //
}

int main() {
    test_function();
    std::cout << "Back in main." << std::endl;
    return 0;
}