//Simple Queue Dynamic 
#include <stdio.h> 
#include <stdlib.h> 
 
int size; 
struct Queue{ 
    int front; //Index Of front element in Queue 
    int rear; //Index of rear element in Queue 
    int *queue; //Base address of array to store Queue 
}Q; 
//Function to insert an element to rear of Queue 
void insert(int val) 
{ 
    //Checking if Queue is Full 
    if(Q.rear==size-1) 
    { 
        printf("Queue is Full\n"); 
        printf("Reallocating Memory\n"); 
        size++; 
        Q.queue = (int *)realloc(Q.queue,size*sizeof(int)); //Reallocating Array for Queue 
    } 
    if(Q.front==-1) 
    { 
        Q.front = 0; //Initializing First element 
    } 
    Q.rear++; 
    *(Q.queue+Q.rear) = val; 
    printf("Insertion Successful\n"); 
} 
//Function to delete the front element of Queue 
void delete() 
{ 
    //Checking if Queue is Empty 
    if(Q.front==-1) 
    { 
        printf("Queue is Empty"); 
    } 
    else 
    { 
        //Deleting Element from front 
        printf("Deleted Element : %d\n",*(Q.queue+Q.front)); 
        Q.front++; 
    } 
    if(Q.front==Q.rear) 
    { 
        Q.front=Q.rear=-1; 
    } 
} 
//Function Display all elements of Queue 
void display() 
{ 
    //Checking if Queue is Empty 
    if(Q.rear==-1) 
    { 
 
 
        printf("Queue is Empty"); 
    } 
    else 
    { 
        for(int i=Q.front;i<=Q.rear;i++) 
        printf("%d\n",*(Q.queue+i)); 
    } 
} 
void main() 
{ 
    int choice,val; 
    Q.front=Q.rear=-1; //Initializing Empty Queue 
    printf("Enter the Size : "); 
    scanf("%d",&size); 
    Q.queue=(int *)malloc(size*sizeof(int)); //Dynamically Allocating Array for Queue 
    printf("Main Menu\n1.Insert\n2.Delete\n3.Display\n4.Exit\n"); 
    for(;;) 
    { 
        printf("Enter Your choice : "); 
        scanf("%d",&choice); 
        switch(choice) 
        { 
            case 1 : printf("Enter the element to be inserted : "); 
                     scanf("%d",&val); 
                     insert(val); 
                     break; 
            case 2 : delete(); 
                     break; 
            case 3 : display(); 
                     break; 
            case 4 : printf("!! THANK YOU !!\n"); 
                     exit(0); 
            default : printf("Invalid Choice\nEnter Again\n"); 
        } 
    } 
}
