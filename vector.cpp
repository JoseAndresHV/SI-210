#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> class Vector {
  private:
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

    T at(int index)
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

    int getSize()
    {
        return size;
    }

    int getCapacity()
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

class Persona {
  private:
    string nombre;
    int edad;

  public:
    Persona() : nombre(""), edad(0) {}

    Persona(string n, int e) : nombre(n), edad(e) {}

    friend ostream &operator<<(ostream &out, const Persona &p)
    {
        out << "Nombre: " << p.nombre << ", Edad: " << p.edad;
        return out;
    }
};

int main()
{
    // Vector de enteros
    Vector<int> v(2);
    v.pushBack(10);
    v.pushBack(20);
    v.pushBack(30);
    v.pushBack(40);
    v.pushBack(5);
    v.pushBack(35);

    v.print();

    try
    {
        int value = v.at(0);
        cout << "Valor en índice 0: " << value << endl;
    } catch (out_of_range error)
    {
        cout << "Error: " << error.what() << endl;
    }

    cout << "Fuera del catch" << endl;

    // Vector de Personas
    Vector<Persona> personas;
    personas.pushBack(Persona("Juan", 25));
    personas.pushBack(Persona("Ana", 30));
    personas.pushBack(Persona("Luis", 20));
    personas.pushBack(Persona("Marta", 28));

    personas.print();

    return 0;
}
