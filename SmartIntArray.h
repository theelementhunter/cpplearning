#pragma once // Standard header guard
#include <iostream>
#include <stdexcept> // For errors

class SmartIntArray {
private:
    int* m_data; // Pointer to Heap
    int m_size; // Size of our array

public:
    // Constructor
    SmartIntArray(int size) {
        m_data = new int[size];
        m_size = size;
        std::cout << "[Constructor] Allocated array of size " << m_size << " at address " << m_data << std::endl;
    }

    // Destructor
    ~SmartIntArray() {
        delete[] m_data; // Free my RAM
        std::cout << "[Destructor] Deallocated array of size " << m_size << " at address " << m_data << std::endl;
    }

    // Operator Overload
    int& operator[](int index) {
        if (index < 0 || index >= m_size) {
            throw std::out_of_range("Index out of range!");
        }
        return m_data[index]; //Return what is in the memory storage, not a copy (which is stored on the Stack temporarily)
    }

    //Helper function: Gets Size
    [[nodiscard]] int getSize() const {return m_size;}
};