#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> class Vector {
  protected:
    T *items;
    int size;
    int capacity;

  public:
    Vector(int _capacity = 10) : size(0), capacity(_capacity)
    {
        items = new T[capacity];
    }

    ~Vector()
    {
        delete[] items;
    }

    void pushBack(const T &value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        items[size++] = value;
    }

    T at(int index) const
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Índice fuera de rango");
        }
        return items[index];
    }

    void set(int index, T value)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Índice fuera de rango");
        }
        items[index] = value;
    }

    int getSize() const
    {
        return size;
    }

    int getCapacity() const
    {
        return capacity;
    }

    void resize(int newCapacity)
    {
        if (newCapacity <= capacity)
            return;

        T *newItems = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
        capacity = newCapacity;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << items[i] << " | ";
        }
        cout << endl;
    }
};

#endif // VECTOR_H
