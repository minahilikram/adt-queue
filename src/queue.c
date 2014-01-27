#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

/* Creates a queue and initalizes it to empty. */
queueNode * createQueue() {

    queueNode * myQueue;
    myQueue = malloc(sizeof(queueNode));
    myQueue->head = createList();
    myQueue->tail = myQueue->head;
    
    return myQueue;

}

/* Adds element to tail of the queue. */
void enqueue(queueNode * myQueue, int i) {
    
    myQueue->tail = addBack(myQueue->tail, i);
}

/* Removes element from front of the queue. */
int dequeue(queueNode * myQueue) {
    
    int value;
    
    if (myQueue->head->next == NULL) {
        myQueue->tail = myQueue->head;
        return 0;
    }
    else if (myQueue->head->next->next == NULL) {
        myQueue->tail = myQueue->head;
        value = removeFront(myQueue->head);
        return value;
    }
    else {
        value = removeFront(myQueue->head);
        return value;
    }
}

/* Checks if queue is empty, and returns TRUE or FALSE. */
int isEmpty(queueNode * myQueue) {
    
    if (myQueue->head->next != NULL) {
        return 0;
    }
    else {
        return 1;
    }
}

/* Prints queue. */
void printQueue(queueNode * myQueue) {

    printList(myQueue->head);

}

/* Destroys queue and free memory. */
void destroyQueue(queueNode * myQueue) {

    destroy(myQueue->head);
    free(myQueue);   

}
