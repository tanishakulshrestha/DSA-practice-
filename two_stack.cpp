#include <iostream>
using namespace std;

class TwoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    // Constructor with dynamic memory allocation
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }

    // Push into Stack 1
    void push1(int v) {
        if (top1 + 1 < top2) {
            top1++;
            arr[top1] = v;
        } else {
            cout << "Stack Overflow in Stack 1\n";
        }
    }

    // Push into Stack 2
    void push2(int v) {
        if (top1 + 1 < top2) {
            top2--;
            arr[top2] = v;
        } else {
            cout << "Stack Overflow in Stack 2\n";
        }
    }

    // Pop from Stack 1
    int pop1() {
        if (top1 >= 0) {
            return arr[top1--];
        } else {
            cout << "Stack Underflow in Stack 1\n";
            return -1;
        }
    }

    // Pop from Stack 2
    int pop2() {
        if (top2 < size) {
            return arr[top2++];
        } else {
            cout << "Stack Underflow in Stack 2\n";
            return -1;
        }
    }

    // Display both stacks
    void display() {
        cout << "\nStack 1 (left to right): ";
        for (int i = 0; i <= top1; i++) {
            cout << arr[i] << " ";
        }

        cout << "\nStack 2 (right to left): ";
        for (int i = size - 1; i >= top2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Destructor
    ~TwoStacks() {
        delete[] arr;
    }
};

int main() {
    int v;
    TwoStacks ts(10);  // Create two stacks in one array of size 10

    // Example push operations
    v = 10; ts.push1(v);
    v = 20; ts.push1(v);
    v = 30; ts.push1(v);

    v = 100; ts.push2(v);
    v = 200; ts.push2(v);
    v = 300; ts.push2(v);

    ts.display();

    // Pop one element from each stack
    v = ts.pop1();
    cout << "\nPopped from Stack 1: " << v << endl;

    v = ts.pop2();
    cout << "Popped from Stack 2: " << v << endl;

    ts.display();

    return 0;
}
