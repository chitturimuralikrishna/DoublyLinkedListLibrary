#include "dll.h"

NODE_DLL head;
NODE_DLL *head_ptr = &head; 

typedef struct node node;

struct node {
	int data;
	NODE_DLL dll;
};


int main()
{
    
	if(InitDllLibrary(head_ptr) == 0) {
		printf("DLL init failed\n");
		return 1;
	}

	node *node1 = (node *)malloc(sizeof(node));
   	node1->data = 10;
   	if(InsertToDll(head_ptr, &node1->dll) == 0) {
		printf("Insert failed\n");
		return 1;
   	}

	node *node2 = (node *)malloc(sizeof(node));
   	node2->data = 555;
   	if(InsertToDll(head_ptr, &node2->dll) == 0) {
		printf("Insert failed\n");
		return 1;
   	}

	node *node3 = (node *)malloc(sizeof(node));
   	node3->data = 100;
   	if(InsertToDll(head_ptr, &node3->dll) == 0) {
		printf("Insert failed\n");
		return 1;
   	}

	node *node4 = (node *)malloc(sizeof(node));
   	node4->data = 999;
   	if(InsertToDll(head_ptr, &node4->dll) == 0) {
		printf("Insert failed\n");
		return 1;
   	}


   	unsigned long offset = (unsigned long) (&(((node *)0)->dll));
   	printf("offset %ld\n", offset);

	NODE_DLL *temp = head_ptr;
    printf("\nNode list: ");
    while(temp->next != head_ptr) {
		temp = temp->next;
		printf("%d ",((node *)((char *)temp - offset))->data);
	}
    
    printf("\n\nDelete node Head:\n");     	
   	if(DeleteFromDll(head_ptr, head_ptr) == 0) {
		printf("Delete failed\n");
	}
	temp = head_ptr;
    printf("Node list: ");
    while(temp->next != head_ptr) {
		temp = temp->next;
		printf(" %d ",((node *)((char *)temp - offset))->data);
	}
 
	printf("\n\nDelete node %d:\n", node1->data);
   	if(DeleteFromDll(head_ptr, &node1->dll) == 0) {
		printf("Delete failed\n");
		return 1;
	} else {
		free(node1);
	}
	temp = head_ptr;
    printf("Node list: ");
    while(temp->next != head_ptr) {
		temp = temp->next;
		printf(" %d ",((node *)((char *)temp - offset))->data);
	}

	printf("\n\nDelete node %d:\n", node3->data);
   	if(DeleteFromDll(head_ptr, &node3->dll) == 0) {
		printf("Delete failed\n");
		return 1;
	} else {
		free(node3);
	}
	temp = head_ptr;
    printf("Node list: ");
    while(temp->next != head_ptr) {
		temp = temp->next;
		printf(" %d ",((node *)((char *)temp - offset))->data);
	}

	printf("\n\nDelete node %d:\n", node4->data);
   	if(DeleteFromDll(head_ptr, &node4->dll) == 0) {
		printf("Delete failed\n");
		return 1;
	} else {
		free(node4);
	}
	temp = head_ptr;
    printf("Node list: ");
    while(temp->next != head_ptr) {
		temp = temp->next;
		printf(" %d ",((node *)((char *)temp - offset))->data);
	}

	printf("\n\nDelete node %d:\n", node2->data);
   	if(DeleteFromDll(head_ptr, &node2->dll) == 0) {
		printf("Delete failed\n");
		return 1;
	} else {
		free(node2);
	}
	temp = head_ptr;
    printf("Node list: ");
    while(temp->next != head_ptr) {
		temp = temp->next;
		printf(" %d ",((node *)((char *)temp - offset))->data);
	}

	return 0;
}
