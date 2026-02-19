#pragma once // Standard header guard
#include <iostream>
#include <stdexcept> // For errors

class SmartMatrix {
private:
    double** m_data; // Master Pointer
    int m_rows;
    int m_cols;
public:
    // Constructor
    SmartMatrix(int numRows, int numCols) {
        // 1. Save dimensions
        m_rows = numRows;
        m_cols = numCols;

        // Allocate data for Master Pointer
        m_data = new double*[numRows];

        // Allocate columns for each Row
        for (int i = 0; i < numRows; i++) {
            m_data[i] = new double[numCols];
        }

    }

    // Destructor
    ~SmartMatrix() {
        for (int i = 0; i < m_rows; i++) {
            delete[] m_data[i];
        }

        delete[] m_data;
        m_data = nullptr;
    }

    // Accessor
    double& operator()(int r, int c) {
        if (r < 0 || r >= m_rows || c < 0 || c >= m_cols) {
            throw std::out_of_range("Either r or c are out of range.");
        }
        return m_data[r][c];
    }

    // Copy Constructor
    SmartMatrix(const SmartMatrix& other) {
        m_rows = other.m_rows;
        m_cols = other.m_cols;

        m_data = new double*[m_rows];

        for (int i = 0; i < m_rows; i++) {
            m_data[i] = new double[m_cols];
            for (int j = 0; j < m_cols; j++) {
                m_data[i][j] = other.m_data[i][j];
            }
        }
    }

    void print(const char* name) const {
        std::cout << "Matrix " << name << ":" << std::endl;
        for (int i = 0; i < m_rows; i++) {
            for (int j = 0; j < m_cols; j++) {
                std::cout << m_data[i][j] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "-----------------" << std::endl;
    }
};