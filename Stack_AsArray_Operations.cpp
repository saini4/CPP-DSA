/*
 * Program: Stack Implementation
 * Description: This program implements a basic stack data structure using an array. 
 * The stack supports the following operations:
 * 1. Push: Adds an element to the top of the stack.
 * 2. Pop: Removes the top element from the stack and returns it.
 * 3. Peek: Returns the top element without removing it.
 * 4. Traversal: Displays all elements in the stack from top to bottom.
 *
 * Time Complexities:
 * - Push: O(1)
 * - Pop: O(1)
 * - Peek: O(1)
 * - Traversal: O(n), where n is the number of elements in the stack.
 */
    
    #include <iostream>
    using namespace std;

    class Stack
    {
    private:
        int top;
        int arr[5];
        int size = sizeof(arr) / sizeof(arr[0]);

    public:
        Stack()
        {
            top = -1;
        }

        bool push(int x);
        int pop();
        int peek();
        void traversal();
    };

    bool Stack::push(int num)
    {
        if (top < size - 1)
        {
            arr[++top] = num;
            cout << "Element " << num << " is pushed into stack" << endl;
            return true;
        }
        else
        {
            cout << "Stack is already full" << endl;
            return false;
        }
    }

    int Stack::pop()
    {
        if (top > -1)
        {
            int x = arr[top];
            arr[top] = 0;
            top--;
            cout << "Popped element: " << x << endl;
            return x;
        }
        else
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }

    int Stack::peek()
    {
        if (top != -1)
        {
            cout << arr[top] << " is the peek element" << endl;
            return arr[top];
        }
        else
        {
            cout << "Stack underflow" << endl;
            return -1;
        }
    }

    void Stack::traversal()
    {
        if (top == -1)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack elements (from top to bottom):" << endl;
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << "\t";
            }
            cout << endl;
        }
    }

    int main()
    {
        Stack s;
        s.push(5);
        s.push(10);
        s.push(15);
        s.push(20);
        s.push(25);

        s.pop();
        s.pop();
        s.peek();
        s.traversal();
    }
