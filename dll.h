#ifndef __DLL_H__
#define __DLL_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct node_dll NODE_DLL;

struct node_dll {
	NODE_DLL *prev;
	NODE_DLL *next;
};

int InitDllLibrary(NODE_DLL *);
int InsertToDll(NODE_DLL *, NODE_DLL *);
int DeleteFromDll(NODE_DLL *, NODE_DLL *);

#define GETOFFSET(node,dll)  \
	 (unsigned long) &(((node *)0)->dll);

#define DLL_TRAVERSE_START(head, temp) \
{                                      \
	if(!head) {  					   \
		printf("Head is null");  	   \
		return 1; 					   \
	} 								   \
	temp = head; 					   \
	while (temp->next != head) { 	   \
		temp = temp->next;

#define DLL_TRAVERSE_END \
	}                    \
}						                         


#endif

