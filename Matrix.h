#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T, int ROWS, int COLS>
class Matrix {
  protected:
    T m[ROWS][COLS];

  public:
    Matrix()
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                m[i][j] = T();
            }
        }
    }

    T at(int row, int col) const
    {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        {
            throw out_of_range("Índice fuera de rango");
        }
        return m[row][col];
    }

    void set(int row, int col, T value)
    {
        if (row < 0 || row >= ROWS || col < 0 || col >= COLS)
        {
            throw out_of_range("Índice fuera de rango");
        }
        m[row][col] = value;
    }

    int numRows() const
    {
        return ROWS;
    }
    int numCols() const
    {
        return COLS;
    }

    void print() const
    {
        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }
};

#endif // MATRIX_H
