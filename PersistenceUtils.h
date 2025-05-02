#ifndef PERSISTENCEUTILS_H
#define PERSISTENCEUTILS_H

#include <fstream>
#include <stdexcept>
#include <string>
#include "LinkedList.h"
#include "Vector.h"

using namespace std;

class PersistenceUtils {
public:

    template<typename T>
    static void saveLinkedList(const LinkedList<T>& list, const string& filename) {
        ofstream file(filename);
        if (!file) {
            throw runtime_error("No se pudo abrir el archivo");
        }

        for (int i = 0; i < list.getSize(); ++i) {
            file << list.at(i) << '\n';
        }
    }

    template<typename T>
    static void loadLinkedList(LinkedList<T>& list, const string& filename) {
        ifstream file(filename);
        if (!file) {
            throw runtime_error("No se pudo abrir el archivo");
        }

        while (list.getSize() > 0) {
            list.remove(0);
        }

        T value;
        while (file >> value) {
            list.pushBack(value);
        }
    }

    template<typename T>
    static void saveVector(const Vector<T>& vec, const string& filename) {
        ofstream file(filename);
        if (!file) {
            throw runtime_error("No se pudo abrir el archivo para guardar");
        }

        for (int i = 0; i < vec.getSize(); ++i) {
            file << vec.at(i) << '\n';
        }
    }

    template<typename T>
    static void loadVector(Vector<T>& vec, const string& filename) {
        ifstream file(filename);
        if (!file) {
            throw runtime_error("No se pudo abrir el archivo para cargar");
        }

        vec.clear();

        T value;
        while (file >> value) {
            vec.pushBack(value);
        }
    }
};

#endif // PERSISTENCEUTILS_H
