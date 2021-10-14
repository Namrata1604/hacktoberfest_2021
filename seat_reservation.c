#include <stdio.h>
#define SIZE 5
int items[SIZE];
int front = -1, rear = -1;
int isFull() {
 if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
 return 1;
 return 0;
}
int isEmpty() {
 if (front == -1) return 1;
 return 0;
}
void enQueue(int element) {
 if (isFull())
 printf("NO");
 else {
 if (front == -1)
 front = 0;
 rear = (rear + 1) % SIZE;
 items[rear] = element;
 }
}
int deQueue() {
 int element;
 if (isEmpty()) {
 printf("\n Queue is empty !! \n");
 return (-1);
 }
 else {
 element = items[front];
 if (front == rear) {
 front = -1;
 rear = -1;
 }
 else {
 front = (front + 1) % SIZE;
 }
 return (element);
 }
} 

int main() {
 int seat, choice, i;
 do{
 printf("Number of seats available: %d\n", SIZE-(rear+1));
 printf("1 to Book Ticket\n2 to Exit\nEnter your choice : ");
 scanf("%d", &choice);
 if(choice == 1){
 printf("Enter number of seats: ");
 scanf("%d", &seat);
 if((SIZE-(rear+1)) < seat)
 printf("\nNO\n\n");
 else {
 printf("\nYES\n\n");
 for(i=0; i<seat; i++){
 enQueue(1);
 }
 }
 }
 else if(choice == 2)
 exit(0);
 else{
 printf("Invalid choice\n");
 }
 }while(1);
 return 0;
} 
