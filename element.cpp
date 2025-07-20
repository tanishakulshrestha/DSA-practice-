#include <iostream>
using namespace std;

#define MAX 100

class StackArray {
    int arr[MAX];
    int size;

public:
    StackArray() {
        size = 0;
    }

    void display() {
        cout << "Array: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // Insert at specific index
    void push(int index, int value) {
        if (size >= MAX || index < 0 || index > size)
            return;

        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }

        arr[index] = value;
        size++;
    }

    // Push at end
    void push(int value) {
        if (size >= MAX)
            return;

        arr[size++] = value;
    }

    // Delete at index
    void removeAtIndex(int index) {
        if (index < 0 || index >= size)
            return;

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }
};

int main() {
    StackArray s;

    s.push(10); // push at end
    s.push(20);
    s.push(30);
    s.display(); // 10 20 30

    s.push(1, 15); // insert at index 1
    s.display();   // 10 15 20 30

    s.removeAtIndex(2); // remove 20
    s.display();        // 10 15 30

    return 0;
}
