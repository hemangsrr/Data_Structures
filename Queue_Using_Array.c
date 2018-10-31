// Title : QUEUE USING ARRAY
// Name : Hemang Mohan
// Roll No. 28
// 09/10/2018







#define MAX 50

typedef struct queue
{
	int front, rear;
	int items[MAX];
}queue;


int isEmpty(queue *q)
{
	if(q->rear < q->front)
		return 1;
	else
		return 0;
}

int isFull(queue *q)
{
	if(q->rear==MAX-1)
		return 1;
	else
		return 0;
}

void enQueue(queue *q, int x)
{
	q->rear++;
	q->items[q->rear] = x;
}

int deQueue(queue *q)
{
	int x;
	x = q->items[q->front];
	q->front++;
	return x;
}

void traverse(queue *q)
{
	int i;
	for(i=q->front; i<=q->rear; i++)
	{
		printf("\n %d", q->items[i]);
	}
}

void main()
{
	queue *q;
	int ch, item, check;
	q->front = 0;
	q->rear = -1;
	printf("\n\n _____---QUEUE USING ARRAY---_____ \n\n\n");
	do
	{
		printf("\n\n 1. ENQUEUE \n");
		printf(" 2. DEQUEUE \n");
		printf(" 3. DISPLAY \n");
		printf(" 4. QUIT \n");
		printf("\n Enter Your Choice : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1 :
				printf("\n Enter element to be inserted : ");
				scanf("%d", &item);
				check = isFull(q);
				if(check==1)
				{
					printf("\n Queue OverFlow!!!\n");
				}
				else
				{
					if(q->front==-1)
					{
						q->rear++;
						q->items[q->rear] = item;
						q->front++;
					}
					else
						enQueue(q, item);
				}
				break;
			case 2 :
				check = isEmpty(q);
				if(check==1)
				{
					printf("\n Queue UnderFlow!!!\n");
				}
				else
				{
					item = deQueue(q);
					printf("\n The deleted Element is : %d", item);
				}
				break;
			case 3 :
				printf("\n The Queue is : ");
				traverse(q);
				break;
			case 4 :
				break;
		}
	}while(ch!=4);
	printf("\n___Program Exited___\n\n");
}
