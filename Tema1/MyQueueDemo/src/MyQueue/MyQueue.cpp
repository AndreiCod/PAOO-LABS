#include "MyQueue.h"
#include <iostream>
#include <stdexcept>

using namespace MyQueueNamespace;

Node::Node(int data)
    : data(data), next(nullptr)
{
    std::cout << "Node created" << std::endl;
}

Node::~Node()
{
    delete this->next;

    std::cout << "Node destroyed" << std::endl;
}

Node::Node(const Node &other)
    : data(other.data), next(other.next)
{
    std::cout << "Node copied" << std::endl;
}

Node::Node(Node &&other)
    : data(other.data), next(other.next)
{
    other.next = nullptr;

    std::cout << "Node moved" << std::endl;
}

Node *Node::operator=(const Node &other)
{
    this->data = other.data;
    this->next = other.next;

    std::cout << "Node copied using assign operator" << std::endl;

    return this;
}

Node *Node::operator=(Node &&other)
{
    this->data = other.data;
    this->next = other.next;

    other.next = nullptr;

    std::cout << "Node moved using assign operator" << std::endl;

    return this;
}

void Node::print()
{
    std::cout << this->data << std::endl;
}

void Node::print_class_name()
{
    std::cout << "Node" << std::endl;
}

MyQueue::MyQueue()
    : head(nullptr), size(0)
{
    std::cout << "Queue created" << std::endl;
}

MyQueue::~MyQueue()
{
    delete this->head;

    std::cout << "Queue destroyed" << std::endl;
}

MyQueue::MyQueue(const MyQueue &other)
    : size(other.size)
{
    this->head = new Node(other.head->data);

    Node *current = this->head;
    Node *otherCurrent = other.head->next;

    while (otherCurrent != nullptr)
    {
        current->next = new Node(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }

    std::cout << "Queue copied" << std::endl;
}

MyQueue::MyQueue(MyQueue &&other)
    : head(other.head), size(other.size)
{
    other.head = nullptr;
    other.size = 0;

    std::cout << "Queue moved" << std::endl;
}

void MyQueue::push(int data)
{
    Node *newNode = new Node(data);
    if (this->head == nullptr)
    {
        this->head = newNode;
    }
    else
    {
        Node *current = this->head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
    }
    this->size++;
}

int MyQueue::pop()
{
    if (this->head == nullptr)
    {
        throw std::out_of_range("Queue is empty");
    }
    Node *current = this->head;
    this->head = this->head->next;
    int data = current->data;
    current->next = nullptr;
    delete current;
    this->size--;
    return data;
}

int MyQueue::peek()
{
    if (this->head == nullptr)
    {
        throw std::out_of_range("Queue is empty");
    }
    return this->head->data;
}

int MyQueue::getSize()
{
    return this->size;
}

bool MyQueue::isEmpty()
{
    return this->size == 0;
}

void MyQueue::print()
{
    Node *current = this->head;
    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}