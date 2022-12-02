#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 15
int arr[SIZE];
int lastpos=0;

void traverse();
void insert();
void removed();
void search();

void main(){
	int n = SIZE, choice;
	
	do{
		printf("\nChoose one from below:\n1. traverse\t2. insert\t3. remove\t 4. Search\t 5. Exit");
		printf("\nyour choice:- ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
			//traverse or display
				traverse();
			break;
			
			case 2:
			//insert
				insert();
			break;
			
			case 3:
			//remove
				removed();
			break;
			
			case 4:
				search();
				break;
				
			case 5:
			//exit
				exit(0);
			break;
			
			default:
			printf("invalid number choosen.");
		}
		
	}while(choice!=5);
}
void insert(){
	int num, pos, i;
	if(lastpos==SIZE){
		printf("\nlsit is full\n");
		return;
	}
	printf("enter a number to insert: ");
	scanf("%d",&num);
	printf("enter position to insert(0-%d): ",lastpos);
	scanf("%d",&pos);
	if(pos>lastpos){
		printf("invalid postion!!\n");
		return;
	}
	for(i=pos;i<lastpos;i++){
		arr[i+1]=arr[i];
	}
	arr[pos]=num;
	lastpos++;
	printf("value added!!!!!!!\n");
	
}
void traverse(){
	if(lastpos==0){
		printf("the list is empty!!\n");
		return;
	}
	int i=0;
	for(i=0;i<lastpos;i++){
		printf("%d. %d\n",i,arr[i]);
	}
}

void removed(){
	int pos, i, j=0;
	if(lastpos==0){
		printf("the list is empty!!\n");
		return;
	}
	printf("give the postition to remove list: ");
	scanf("%d",&pos);
	int temp[lastpos];
	for(i=0;i<=lastpos;i++){
		if(i==pos){
			continue;
		}
		temp[j]=arr[i];
		j++;
	}
	lastpos--;
	
	for(i=0;i<=lastpos;i++){
		arr[i]=temp[i];	
	}

}
void search(){
	int num, i;
	printf("give number to search:- ");
	scanf("%d",&num);
	for(i=0;i<lastpos;i++){
		if(num==arr[i]){
			printf("found at => %d. %d\n",i, arr[i]);
		}
	}
}