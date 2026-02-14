#pragma once // Standard header guard
#include <iostream>
#include <stdexcept> // For errors

class DynSmartIntArray {
private:
    int* m_data; // Pointer to Heap
    int m_size; // Size of our array
    int m_capacity; //Total space reserved for DynSmartIntArray object

public:
    // Constructor
    DynSmartIntArray(int size) {
        m_data = new int[size];
        m_size = size;
        m_capacity = size;
        std::cout << "[Constructor] Allocated array of size " << m_size << " at address " << m_data << std::endl;
    }

    // Destructor
    ~DynSmartIntArray() {
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

    void push_back_basic(int value) {
        // Create new array that is one size larger
        int* new_data_pointer = new int[m_size + 1];

        for (int i = 0; i < m_size; i++) {
            new_data_pointer[i] = m_data[i];
        }

        // Add new value at the end
        new_data_pointer[m_size] = value;

        // Free the RAM; Delete the old block of memory
        delete[] m_data;

        // Update Pointer and Size of Array
        m_data = new_data_pointer;
        m_size++;
    }

    void push_back_double(int value) {
        if (m_capacity > m_size) {
            m_data[m_size] = value;
            m_size++;
        } else if (m_capacity < m_size) {
            throw std::out_of_range("Index out of range!");
        } else {
            // This ensures that even if we start at 0, we grow to 1, then 2, 4, 8...
            m_capacity = (m_capacity == 0) ? 1 : m_capacity * 2;


            // Ask computer for new memory location in
            // heap with the appropriate number of bytes
            int* new_data_pointer = new int[m_capacity];

            // Fill new array with old array
            for (int i = 0; i < m_size; i++) {
                new_data_pointer[i] = m_data[i];
            }

            // Add data to the end of new array
            new_data_pointer[m_size] = value;

            // Free the RAM; Delete the old block of memory
            delete[] m_data;
            // Update what m_data points to
            m_data = new_data_pointer;
        }
        // Update the capacity of the array
        m_size++;
    }
};