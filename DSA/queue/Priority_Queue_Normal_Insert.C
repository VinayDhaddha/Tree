#include<stdio.h>
#include<conio.h>
#define MAX 3
typedef  struct
{
	int q[MAX];
	int f,r;
}queue;
void insert(queue *t,int ele)
{
	if(t->r==MAX-1)
	{
		printf("Queue Overflow\n");
		return;
	}

	t->r++;
	t->q[t->r]=ele;
}
int isempty(queue *t)
{
	if(t->f==t->r+1)
	  return 1;
	else return 0;
}
int delete1(queue *t)
{
	int max,pos,i;
	if(isempty(t))
	{
		printf("Queue Underflow\n");
		return -1;
	}
	max=t->q[t->f];//Place the first element at '0' ie. f
	pos=t->f;//if max is at q[f] then my position is f
	for(i=t->f+1;i<=t->r;i++)
		if(t->q[i]>max)
		{
			max=t->q[i];
			pos=i;
		}
		for(i=pos;i<t->r;i++)//for loop for shifting elements
			t->q[i]=t->q[i+1];
		t->r--;//because r also shifts by 1 towards left after deleting
		return max;
}
int queuefront(queue *t)
{
	if(isempty(t))
	{
		printf("Queue Empty\n");
		return -1;
	}
	return (t->q[t->f]);
}
int queueend(queue *t)
{
	if(isempty(t))
	{
		printf("Queue Empty\n");
		return -1;
	}
	return (t->q[t->r]);
}
void display(queue *t)
{
	int i;
	if(isempty(t))
	{
		printf("Queue Empty\n");
		return;
	}
	for(i=t->f;i<=t->r;i++)
	   printf("%d ",t->q[i]);
	printf("\n");
}
int main()
{
	queue x;
	int ch,ele;
	x.f=0;
	x.r=-1;
	//clrscr();
	while(1)
	{
		printf("Enter choice 1.Insert 2.Delete 3.Queuefront 4.Queueend 5.Display 6.Exit\n");
		scanf("%d",&ch);
		if(ch==6)
		  break;
		switch(ch)
		{
			case 1:printf("Enter element\n");
			       scanf("%d",&ele);
			       insert(&x,ele);
			       display(&x);
			       break;
			case 2:if(isempty(&x))
				  printf("Queue Underflow\n");
			       else
			       {
				  ele=delete1(&x);
				  printf("Deleted elemment=%d\n",ele);
				  display(&x);
			       }
			       break;
			case 3:if(isempty(&x))
				  printf("Queue Empty");
			       else
			       {
				  ele=queuefront(&x);
				  printf("Queuefront=%d\n",ele);
				  display(&x);
			       }
			       break;
			case 4:if(isempty(&x))
				  printf("Queue Empty");
			       else
			       {
				  ele=queueend(&x);
				  printf("Queueend=%d\n",ele);
				  display(&x);
			       }
			       break;
			case 5:display(&x);
			       break;
		       default:printf("Invalid choice\n");
		}
	}
	return 0;
}


