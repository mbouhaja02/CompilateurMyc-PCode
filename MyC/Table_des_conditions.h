/*
 *  Table des conditions.h
 *
 *  Stack structure to keep track of condition number trail  
 *
 */

#ifndef TABLE_DES_CONDITIONS_H
#define TABLE_DES_CONDITIONS_H

// Define a node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the pile using linked list
struct Pile {
    struct Node* top;
};

struct cond {
  int total;
  struct Pile s;
};

void push(struct Pile* pile, int data);
int pop(struct Pile* pile);
int head(struct Pile* pile);

#endif