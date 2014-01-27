#include "queue.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    
    queueNode * queueOne;   /* initialize variables */
    queueNode * queueTwo;
    
    int r;
    int people;                         /* keyboard input */
    int i;
    int currentTimeOne[2] = {0, 0};     /* array to keep track of current time */
    int currentTimeTwo[3] = {0, 0, 0};
    int totalTimeOne[2] = {0, 0};       /* array to keep track of total time */  
    int totalTimeTwo[3] = {0, 0, 0};
    int valueOne;
    int valueTwo;
    int counterOne;
    int counterTwo;
    double timeOne;
    double timeTwo;
    
    /* creates two queues */
    queueOne = createQueue();
    queueTwo = createQueue();
    
    printf("\nhow many people?\n");
    scanf("%d", &people);
    
    /* creates a seed based on time */
    srand(time(NULL));
    
    /* loop to add random numbers to both queues so that they are the same numbers */
    for (i=0; i<people; i++) {
    
        r = rand() % 3;
        r = r + 1;
        enqueue(queueOne, r);
        enqueue(queueTwo, r);
        
    }
    
    printf("\n------------------------------");
    
    /* prints out both queues */
    printf("\n");
    printf("queueOne:");
    printQueue(queueOne);
    printf("\n");
    printf("queueTwo:");
    printQueue(queueTwo);
    printf("\n");
    
    
    /*SIMULATION ONE*/
    
    printf("------------------------------\nSIMULATION ONE: 2 CHECKPOINTS\n\n");
    
    if (people > 1) {   /* controls the for loop within the while loop */
        counterOne = 2;
    }
    else if (people == 1) {
        counterOne = 1;
    }
    while (isEmpty(queueOne) == 0) {
        for (i=0; i<counterOne; i++) {
            if (currentTimeOne[i] == 0) {
                valueOne = dequeue(queueOne);   /* dequeue returns value saved in valueOne */
                currentTimeOne[i] = valueOne;
                totalTimeOne[i] = totalTimeOne[i] + valueOne;
            }
            else if (currentTimeOne[i] != 0) {
                currentTimeOne[i] = currentTimeOne[i] - 1;  /* subracts 1 from time as if 1 minute passing by */
            }
        }
    }
    for (i=0; i<2; i++) {
        printf("checkpoint %d took %d minutes.\n", i+1, totalTimeOne[i]);
    }
    
    /* find average time */
    timeOne = (totalTimeOne[0] + totalTimeOne[1]) / 2;
    printf("average time: %0.2f", timeOne);


    /*SIMULATION TWO*/
    
    printf("\n------------------------------\nSIMULATION TWO: 3 CHECKPOINTS\n\n");
    
    if (people > 2) {
        counterTwo = 3;
    }
    else if (people == 2) {
        counterTwo = 2;
    }
    else if (people == 1) {
        counterTwo = 1;
    }
    while (isEmpty(queueTwo) == 0) {
        for (i=0; i<counterTwo; i++) {
            if (currentTimeTwo[i] == 0) {
                valueTwo = dequeue(queueTwo);
                currentTimeTwo[i] = valueTwo;
                totalTimeTwo[i] = totalTimeTwo[i] + valueTwo;
            }
            else if (currentTimeTwo[i] != 0) {
                currentTimeTwo[i] = currentTimeTwo[i] - 1;
            }
        }
    }
    for (i=0; i<3; i++) {
        printf("checkpoint %d took %d minutes.\n", i+1, totalTimeTwo[i]);
    }
    
    timeTwo = (totalTimeTwo[0] + totalTimeTwo[1] + totalTimeTwo[2]) / 3;
    printf("average time: %.2f\n", timeTwo);
    
    printf("\n");
    
    destroy(queueOne);
    destroy(queueTwo);
    
return 0;
}
