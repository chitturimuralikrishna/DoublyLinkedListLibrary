#include "dll.h"

int InitDllLibrary(NODE_DLL *head)
{
	if(!head) {
		printf("Head is NULL\n");
		return 0;
	}	
	head->prev = head;
	head->next = head;
	
	return 1;
}

int InsertToDll(NODE_DLL *head, NODE_DLL *new)
{
	if(!head) {
		printf("Head is NULL\n");
		return 0;
	}
	
	if(!new) {
		printf("New node is NULL\n");
		return 0;
	}

	new->prev = head;
	new->next = head->next;
	head->next = new;
	new->next->prev = new;

 	return 1;	
}

int DeleteFromDll(NODE_DLL *head, NODE_DLL *node)
{
	if(!head) {
		printf("Head is NULL\n");
		return 0;
	}

	if(!node) {
		printf("Node is NULL\n");
		return 0;
	}

	if(node == head){
		printf("Head deletion not allowed\n");
		return 0;
	}

	node->prev->next = node->next;
	node->next->prev = node->prev;
	
	return 1;
}
