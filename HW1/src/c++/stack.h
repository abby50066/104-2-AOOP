#ifndef __STACK_H__
#define __STACK_H__

class Stack {
    typedef struct node {
        int data;
        struct node* next;
    }Node;
    Node* top;
public:
/*
    Stack();
    void push(int x);
    int pop();
*/
    Stack()
    {
        ;
    }
    void push(int x)
    {
        Node* node = new Node;
        node->data = x;
        node->next = this->top;

        this->top = node;
    }
    int pop()
    {
        Node* tmp = this->top;
        int value = this->top->data;
        this->top = this->top->next;

        delete tmp;

        return value;
    }

};

#endif
