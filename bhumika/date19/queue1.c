#include<stdio.h>

#define MAX 5

int rear=0;
int front=0;

int q[MAX];
 void enqueue(int val);
 void dequeue();
 void dispQueue();

 int main()
 {
 	enqueue(10);
 	enqueue(20);
 	enqueue(30);
 	enqueue(40);
 	enqueue(50);
	enqueue(60);

dispQueue();

 dequeue();
 dequeue();
 dequeue();
 dequeue();
 dequeue();
 dequeue();

dispQueue();
printf("\n\n");
return 0;
}

void dispQueue()
{
	int i;
	if(front==rear);
	{
		printf("\nempty");
		return ;
	}
	printf("\nQueue is\n");
	for(i=front;i<rear;i++)
	printf("%d",q[i]);
	printf("\n\n");
}

void enqueue(int val)
{
	if(rear==MAX)
	{
	printf("\nQueue is full\n");
	return ;
	}
	q[rear]=val;
	rear++;
	}
void dequeue()
{
	if(front==rear)
	{
		front=0;
		rear=0;
		printf("\nempty queue\n");
		return ;
	}
	printf("\n%d is dequeued from the queue",q[front]);
	front++;
}









