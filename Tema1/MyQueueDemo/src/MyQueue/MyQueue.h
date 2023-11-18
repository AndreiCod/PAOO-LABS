#pragma once

#include <iostream>

namespace MyQueueNamespace
{
    struct NodeTemplate
    {
    public:
        virtual void print() = 0;

        virtual void print_class_name()
        {
            std::cout << "NodeTemplate" << std::endl;
        }
    };

    struct Node : public NodeTemplate
    {
    public:
        int data;
        Node *next;

        Node *operator=(const Node &other);
        Node *operator=(Node &&other);

        Node(int data);
        ~Node();
        Node(const Node &other);
        Node(Node &&other);

        void print();
        void print_class_name();
    };

    class MyQueue
    {
    private:
        Node *head;
        int size;

    public:
        MyQueue();
        ~MyQueue();
        MyQueue(const MyQueue &other);
        MyQueue(MyQueue &&other);

        void push(int data);
        int pop();
        int peek();
        int getSize();
        bool isEmpty();
        void print();
    };

};