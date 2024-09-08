#ifndef DLL_H
#define DLL_H

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


#endif

