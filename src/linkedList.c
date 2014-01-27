#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>

/*Initalizes list*/
node * createList() {
    node * dummyNode;
    dummyNode = malloc(sizeof(node));
    dummyNode->nodeLength = 0;
    dummyNode->nodeValue = 0;
    
    return dummyNode;
}

/*Adds a node to the front of the list*/
void addFront(node * head, int i) {
    node * newNode;
    newNode = initNode(i);
    newNode->next = head->next;
    head->next = newNode;

}

/* Adds node to the back of the list. */
node * addBack(node * tail, int i) {
    
    node * newNode;
    
    newNode = initNode(i);
    tail->next = newNode;
    
    return newNode;
}

/*Gets the value stored in the node at the front of the list*/
int getFront(node * head) {
    
    return head->next->nodeValue;
}

/*Removes the first node in the list*/
int removeFront(node * head) {
    node * tempPtr;
    int nodeValue;
    tempPtr = head->next;
    nodeValue = tempPtr->nodeValue;
    head->next = head->next->next;
    free(tempPtr);
    
    return nodeValue;
}

/*Prints the list*/
void printList(node * head) {
    node * N;
    N = head;
    N = N->next;
    while (N != NULL) {
        printf("%d ", N->nodeValue);
        N = N->next;
    }
}

/*Initializes a new node to add to the list*/
node * initNode(int i) {
    node * newNode;
    newNode = malloc(sizeof(node));
    newNode->nodeValue = i;
    newNode->next = NULL;
    
    return newNode;

}

/*Destroys the list*/
void destroy(node * head) {
    node * temp = head;
    while (temp != NULL) {
        temp = temp->next;
        free(head);
        head = temp;
    }
}
