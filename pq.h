#ifndef pq_h
#define pq_h
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<string.h>
#include"post.h"

typedef post eletype;

typedef struct
{
    int size;
    int maxsize;
    eletype *data;
}pq;

pq* create(int);
int insert(pq*,eletype);
int display(pq*);
eletype delete_min(pq*);
int direction_prioritizer(pq *a,pq *b,int n);
int isEmpty(pq *a);
int print(eletype p);

#endif
