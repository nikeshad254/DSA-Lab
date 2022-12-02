// Priority Queue implementation in C

#include <stdio.h>
#include <stdlib.h>
int size = 0;

int findMin(int array[]){
	int min=100000;
	
	int i;
	for(i=0;i<size;i++){
		min=min>array[i]?array[i]:min;
	}
	for(i=0;i<size;i++){
		if(min==array[i]){
			return i;
		}
	}
}

// Function to insert an element into the tree
void insert(int array[], int newNum) {
  if (size == 0) {
    array[0] = newNum;
    size += 1;
  } else {
    array[size] = newNum;
    size += 1;
  }
}

// Function to delete an element from the tree
void deleteRoot(int array[]) {
  
  if(size<=0){
  	printf("the queue is empty!!");
  }
  int i;
  int min = findMin(array);
  for(i=min;i<size;i++){
  	array[i]=array[i+1];
  }
  size -= 1;
}

// Print the array
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

// Driver code
int main() {
	int array[10];
	int opt, a;
	do{
		printf("\nChoose one from Below:\n1. insert\t2. delete\t3. show \t 4. exit\n==>");
		scanf("%d",&opt);
		switch(opt){
			case 1:
				printf("Give number to insert:- ");
				scanf("%d",&a);
				insert(array, a);
				break;
			case 2:
				deleteRoot(array);
				break;
			case 3:
				printArray(array, size);;
				break;
			case 4:
				exit(0);
				break;
			default:
				printf("\ninvalid number given, Choose again!\n");
		}
	}while(opt!=4);

}