#include <iostream>
#include "MyQueue.h"

int main(int argc, char **argv)
{
    MyQueue queue;

    queue.push(1);
    std::cout << queue.peek() << std::endl;

    queue.push(2);

    std::cout << queue.pop() << std::endl;

    queue.push(3);
    std::cout << "Size of queue: " << queue.getSize() << std::endl;

    MyQueue queue2(queue);

    queue.print();
    queue2.print();

    MyQueue queue3(std::move(queue2));

    queue3.print();
    queue2.print();

    return 0;
}