#ifndef SENECA_DYNACOPY_H
#define SENECA_DYNACOPY_H

namespace seneca {

    // Function template for dynamically copying an array (returns new array)
    template <typename T>
    T* dynaCopy(const T* source, int size) {
        T* newArray = new T[size];  // Dynamically allocate memory for new array
        for (int i = 0; i < size; ++i) {
            newArray[i] = source[i];  // Copy the elements
        }
        return newArray;
    }

    // Function template for dynamically copying into an existing array (modifies destination)
    template <typename T>
    T* dynaCopy(T*& destination, const T* source, int size) {
        delete[] destination;  // Free any existing memory
        destination = new T[size];  // Allocate memory for the new array
        for (int i = 0; i < size; ++i) {
            destination[i] = source[i];  // Copy the elements
        }
        return destination;  // Return the updated destination pointer
    }

    // Function template to print array elements
    template <typename T>
    void prnArray(const T* arr, int size) {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i];
            if (i < size - 1) std::cout << ", ";  // Add comma if it's not the last element
        }
        std::cout << std::endl;
    }

}

#endif // SENECA_DYNACOPY_H
