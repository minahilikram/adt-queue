#include "linkedList.h"

typedef struct queue {
	node * head;
	node * tail;
} queueNode;

/* Preconditions: None.
Postconditions: A new queue is created and is initialized to empty. */
queueNode * createQueue();

/* Preconditions: The queue is not full.
Postconditions: The new element is added as the last element in queue. */
void enqueue(queueNode * myQueue, int i);

/* Preconditions: The queue is not empty.
Postconditions: The first (front) element of the queue is removed and returned to the caller. The front of the queue is set to the successor of the removed element. */
int dequeue(queueNode * myQueue);

/* Preconditions: An initialized queue is available.
Postconditions: Returns TRUE or FALSE */
int isEmpty(queueNode * myQueue);

/* Preconditions: An initialized queue is available and is not empty.
Postconditions: None. */
void printQueue(queueNode * myQueue);

/* Preconditions: An initialized queue exists.
Postconditions: The queue is destroyed and all associated memory is freed. */
void destroyQueue(queueNode * myQueue);
