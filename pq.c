#include"post.h"
#include "pq.h"

pq* create(int maxsize)
{
    pq*a;
    post temp;
    temp.pid=123;
    strcpy(temp.place,"Random");
    temp.distance=999;
    a=(pq*)malloc(sizeof(pq));
    a->maxsize=maxsize;
    a->data=(eletype*)malloc(a->maxsize*sizeof(eletype));
    a->size=1;
    a->data[0]=temp;
    return a;
}

int isEmpty(pq *a)
{
	return(a->size==1);
}

int print(eletype p)
{
    printf("\nPost id:\t%d\n",p.pid);
    printf("Place:\t%s\n",p.place);
    printf("Distance:\t%d\n",p.distance);
    printf("Direction: %s\n",p.direction);
    return 1;
}

int insert(pq* a,eletype x)
{
    eletype temp;
    int i=a->size;
    a->data[i]=x;
    (a->size)++;
    //printf("I AM IN INSERT 1;");
    while(i>1)
    {
    	//printf("I AM IN INSERT 2:");
        if(a->data[i].distance<a->data[i/2].distance)
        {
            temp=a->data[i];
            a->data[i]=a->data[i/2];
            a->data[i/2]=temp;
            i=i/2;
        }
        else
            break;
    }
    return 0;
}

eletype delete_min(pq *a)
{
	eletype x = a->data[1];
	a->data[1]=a->data[a->size-1];
	int i=1;
	int min_id;
	while(2*i<a->size)
	{
		if(a->data[i].distance>a->data[2*i].distance)
		{
			min_id = 2*i;
			if((2*i+1)<a->size)
			{	
				if(a->data[2*i].distance> a->data[2*i+1].distance)
					min_id = 2*i+1;
			}
			eletype temp = a->data[i];
			a->data[i] = a->data[min_id];
			a->data[min_id] = temp;
			i=min_id;
		}
		else if (a->data[i].distance>a->data[2*i+1].distance && 2*i+1<a->size)
		{
			min_id = 2*i+1;
			eletype temp = a->data[i];
			a->data[i] = a->data[min_id];
			a->data[min_id] = temp;
			i = min_id;
		}
		else
			break;
	}
	(a->size)--;
	return x;
}

int direction_prioritizer(pq *a,pq *b,int n)
{
	int k=0,i;
	char p[20],q[20];
	eletype t1,t2;
	if(isEmpty(a))
		return k;
	else
	{
		t1=delete_min(a);
		strcpy(p,t1.direction);
		print(t1);
		for(i=1;i<n;i++)
		{
			strcpy(q,a->data[1].direction);
			if(strcmp(q,p)==0)
			{
				t1=delete_min(a);
				print(t1);
				//printf("i am in if");
			}
			else
			{
				t2=delete_min(a);
				insert(b,t2);
				k++;
				//printf("i am in else");
			}
		}
		return k;
	}
}

int display(pq* a)
{
    int i;
    for(i=1;i<a->size;i++)
    {
        print(a->data[i]);
    }
    return 0;
}

