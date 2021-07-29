#ifndef post_h
#define post_h
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int pid;
	char place[200];
	int distance;
	char direction[200];
}post;

#endif
