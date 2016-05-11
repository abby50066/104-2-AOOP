#include <stdlib.h>
#include "stack.h"

void push(struct stack* this, int x)
{
    if (this->data == -1) {
        this->data = x;
    }
    else {
        struct stack* tmp = this,* node = (struct stack* )malloc(sizeof(struct stack));
        node->data = x;
        node->next = NULL;

        while (tmp->next != NULL) {
            tmp = tmp->next;
        }

        tmp->next = node;
    }
}

int pop(struct stack* this)
{
    struct stack* tmp = this, *prev = this;
    int value;

    if (tmp == NULL) {
        return -1;
    }

    while (tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    prev->next = NULL;
    value = tmp->data;
    free(tmp);

    return value;
}

struct stack* new_stack()
{
    struct stack* stk = malloc(sizeof(struct stack));
    stk->data = -1;
    stk->next = NULL;
    return stk;
}

void delete_stack(struct stack* stk)
{
    struct stack* tmp;

    while(stk != NULL){
        tmp = stk;
        stk = stk->next;
        free(tmp);
    }
}

