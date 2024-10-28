#include <iostream>
#include <stdexcept>

template<typename T>
class Node 
{
public:
    T data;
    Node* next;

    Node(const T& data) : data(data), next(nullptr) {}
};

template<typename T>
class Stack 
{
private:
    Node<T>* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() 
    {
        while (!isEmpty()) 
        {
            pop();
        }
    }

    void push(const T& value) 
    {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("Stack is empty. Cannot pop.");
        }
        Node<T>* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() const 
    {
        if (isEmpty()) 
        {
            throw std::out_of_range("Stack is empty. Cannot retrieve top element.");
        }
        return topNode->data;
    }

    bool isEmpty() const 
    {
        return topNode == nullptr;
    }

    void print() const 
    {
        Node<T>* current = topNode;
        while (current != nullptr) 
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() 
{
    Stack<int> stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Current stack (top to bottom): ";
    stack.print();

    std::cout << "Top element: " << stack.top() << std::endl;

    stack.pop();
    std::cout << "After popping, current stack: ";
    stack.print();

    return 0;
}