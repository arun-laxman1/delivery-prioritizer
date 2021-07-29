#include "pq.h"
#include"post.h"

eletype scan()
{
    post p;
    printf("Enter post id:\t");
    scanf("%d",&p.pid);
    printf("Enter place:\t");
    scanf("%s",&p.place);
    printf("Enter distance:\t");
    scanf("%d",&p.distance);
    printf("Enter the direction: ");
    scanf("%s",&p.direction);
    printf("\n");
    return p;
}

int main()
{
	int num,i;
	printf("---------------------------DELIVERY PRIORITIZER---------------------------");
    pq *a1;
    pq *a2;
    printf("\n\nEnter number of Places:\t");
    scanf("%d",&num);
    system("@cls||clear");
    post p[num];
    printf("---------------------------DELIVERY PRIORITIZER---------------------------\n\n");
    a1 = create(num);
    a2 = create(num);
    for(i=0;i<num;i++)
    {
        p[i]=scan();
    }
    system("@cls||clear");
    for(i=0;i<num;i++)
    {
    	insert(a2,p[i]);
	}
    printf("---------------------------DELIVERY PRIORITIZER---------------------------");
    printf("\n\nDeliver in this order:\n");
    num=direction_prioritizer(a2,a1,num);
    num=direction_prioritizer(a1,a2,num);
    num=direction_prioritizer(a2,a1,num);
    direction_prioritizer(a1,a2,num);
    return 1;
}
