#pragma once

struct Node
{
public:
    int data;
    Node *next;

    Node(int data);
    ~Node();
    Node(const Node &other);
    Node(Node &&other);
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
};
