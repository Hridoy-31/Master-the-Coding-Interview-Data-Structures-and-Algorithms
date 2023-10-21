#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class myCustomArray
{
private:
    T *arr;
    size_t size;
    size_t capacity;

public:
    // Constructor
    myCustomArray(size_t initialCapacity = 10) : size(0), capacity(initialCapacity)
    {
        arr = new T[capacity];
    }

    // Destructor
    ~myCustomArray()
    {
        delete[] arr;
    }

    // Add an element to the end of the array
    void pushback(const T &value)
    {
        if (size >= capacity)
        {
            // If the array is full, double it's capacity
            capacity *= 2;
            T *new_arr = new T[capacity];
            for (size_t i = 0; i < size; i++)
            {
                new_arr[i] = arr[i];
            }

            delete[] arr;
            arr = new_arr;
        }
        arr[size++] = value;
    }

    // Get the element at a specific index
    T &at(size_t index)
    {
        if (index < 0 or index >= size)
        {
            throw out_of_range("Index out of range.");
        }
        return arr[index];
    }

    // Get the number of elements in the array
    size_t getSize() const
    {
        return size;
    }

    // Get the capacity of the array
    size_t getCapacity() const
    {
        return capacity;
    }

    // Check if the array is empty
    bool isEmpty() const
    {
        return size == 0;
    }
};

int main()
{
    myCustomArray<int> myArray;

    // Add elements in the array
    for (int i = 1; i <= 15; i++)
    {
        myArray.pushback(i * 10);
    }

    // Access and print elements
    for (size_t i = 0; i < myArray.getSize(); i++)
    {
        cout << "Element at index " << i << ": " << myArray.at(i) << endl;
    }

    cout << "Array size: " << myArray.getSize() << endl;
    cout << "Array capacity: " << myArray.getCapacity() << endl;

    return 0;
}