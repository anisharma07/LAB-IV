#include <iostream>

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T value) : data(value), next(nullptr) {}
};
template <typename T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the list
    void insert(T value)
    {
        Node<T> *newNode = new Node<T>(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node<T> *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to delete a node with a specific value
    void remove(T value)
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->data == value)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T> *current = head;
        while (current->next != nullptr && current->next->data != value)
        {
            current = current->next;
        }

        if (current->next != nullptr)
        {
            Node<T> *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
    }

    // Function to traverse and display the list
    void traverse()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

int main()
{
    LinkedList<int> myList;

    myList.insert(1);
    myList.insert(2);
    myList.insert(3);

    std::cout << "Linked List: ";
    myList.traverse();

    myList.remove(2);

    std::cout << "After deleting 2: ";
    myList.traverse();

    return 0;
}