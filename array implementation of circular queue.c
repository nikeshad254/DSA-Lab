// Circular Queue implementation in C

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int items[SIZE];
int front = -1, rear = -1;

// Check if the queue is full
int isFull() {
  if ((front == rear + 1) || (front == 0 && rear == SIZE - 1)) return 1;
  return 0;
}

// Check if the queue is empty
int isEmpty() {
  if (front == -1) return 1;
  return 0;
}

// Adding an element
void enQueue() {
	int element;
  printf("give element to insert:- ");
  scanf("%d",&element);
	
  if (isFull())
    printf("\n Queue is full!! \n");
  else {
    if (front == -1) front = 0;
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf(" Inserted -> %d\n", element);
  }
}

// Removing an element
void deQueue() {
  int element;
  if (isEmpty()) {
    printf("\n Queue is empty !! \n");
    return;
  } else {
    element = items[front];
    if (front == rear) {
      front = -1;
      rear = -1;
    } 
    // Q has only one element, so we reset the 
    // queue after dequeing it. ?
    else {
      front = (front + 1) % SIZE;
    }
    printf("\n Deleted element -> %d \n", element);
  }
}

// Display the queue
void display() {
  int i;
  if (isEmpty())
    printf(" \n Empty Queue\n");
  else {
    printf("\n Front -> %d ", front);
    printf("\n Items -> ");
    for (i = front; i != rear; i = (i + 1) % SIZE) {
      printf("%d ", items[i]);
    }
    printf("%d ", items[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

void main() {
	int opt, a;
	do{
		printf("\nChoose one from Below:\n1. insert\t2. delete\t3. show \t 4. exit\n==>");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				enQueue();
				break;
			case 2:
				deQueue();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\ninvalid number given, Choose again!\n");
		}
	}while(opt!=4);
	
}