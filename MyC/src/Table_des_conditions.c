#include <stdlib.h>
#include <stdio.h>

#include "Table_des_conditions.h"





// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


// Function to check if the pile is empty
int isEmpty(struct Pile* pile) {
    return (pile->top == NULL);
}

// Function to push an element onto the pile
void push(struct Pile* pile, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = pile->top;
    pile->top = newNode;
    //printf("%d pushed to pile.\n", data);
}

// Function to remove an element from the pile
int pop(struct Pile* pile) {
    if (isEmpty(pile)) {
        printf( "Pile is empty. Cannot pop from an empty pile.\n");
        exit(EXIT_FAILURE);
    }
    struct Node* temp = pile->top;
    int popped = temp->data;
    pile->top = pile->top->next;
    free(temp);
    return popped;
}

// Function to read head of the stack
int head(struct Pile* pile) {
    if (isEmpty(pile)) {
        printf( "Pile is empty.\n");
        exit(EXIT_FAILURE);
    }
    return pile->top->data;
}



