#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

int main () {
    
    int menu = 0;
    int input = 0;
    queueNode * testQueue; 
    char c;
    
    testQueue = createQueue(); 
    
    while (menu != 3) {
    
        printf("\nWhat would you like to test?\n");
        printf("\n[1] Enqueue\n");
        printf("[2] Dequeue\n");
        printf("[3] Destroy & Exit\n");
        scanf("%d", &menu);

        if (menu > 3 || menu < 1)
            while((c = getchar()) != '\n' && c != EOF); /*cleans input buffer, incase characters are input*/
            
        if (menu == 1) {
            
            printf("\nPlease Enter an Integer:");
            scanf("%d", &input);
            
            enqueue(testQueue, input);  /*returns users input to function to add to the queue*/
            
            printf("Current Queue:");
            printQueue(testQueue);        /* queue printed everytime inorder for user to keep track*/
        
        }
        
        if (menu == 2) {
        
            dequeue(testQueue);  /*calls function and sends queue to remove*/
            
            printf("Current Queue:");
            printQueue(testQueue);
        
        }
        
        if (menu == 3) {
        
            destroy(testQueue); /*destroys queue and frees memory*/
            break;
        }
    }
    
    return 0;
}
