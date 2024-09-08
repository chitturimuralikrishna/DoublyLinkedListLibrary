#include "dll.h"

NODE_DLL head;
NODE_DLL *head_ptr = &head; 

typedef struct node node;

struct node {
	int data;
	NODE_DLL dll;
};

unsigned long offset = GETOFFSET(node, dll)

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


   	printf("offset %ld\n", offset);

	NODE_DLL *temp = head_ptr;

    printf("\nNode list: ");
	DLL_TRAVERSE_START(head_ptr, temp)
	{   
		printf("%d ",((node *)((char *)temp - offset))->data);
	}
	DLL_TRAVERSE_END


    printf("\n\nDelete node Head:\n");     	
   	DeleteFromDll(head_ptr, head_ptr);

    printf("Node list: ");
	DLL_TRAVERSE_START(head_ptr, temp)
		printf("%d ",((node *)((char *)temp - offset))->data);
	DLL_TRAVERSE_END
 

	printf("\n\nDelete node %d:\n", node1->data);
   	DeleteFromDll(head_ptr, &node1->dll);
	free(node1);

    printf("Node list: ");
	DLL_TRAVERSE_START(head_ptr, temp)
		printf("%d ",((node *)((char *)temp - offset))->data);
	DLL_TRAVERSE_END


	printf("\n\nDelete node %d:\n", node3->data);
   	DeleteFromDll(head_ptr, &node3->dll);
	free(node3);

    printf("Node list: ");
	DLL_TRAVERSE_START(head_ptr, temp)
		printf("%d ",((node *)((char *)temp - offset))->data);
	DLL_TRAVERSE_END


	printf("\n\nDelete node %d:\n", node4->data);
   	DeleteFromDll(head_ptr, &node4->dll);
	free(node4);

    printf("Node list: ");
	DLL_TRAVERSE_START(head_ptr, temp)
		printf("%d ",((node *)((char *)temp - offset))->data);
	DLL_TRAVERSE_END


	printf("\n\nDelete node %d:\n", node2->data);
   	DeleteFromDll(head_ptr, &node2->dll);
	free(node2);

    printf("Node list: ");
	DLL_TRAVERSE_START(head_ptr, temp)
		printf("%d ",((node *)((char *)temp - offset))->data);
	DLL_TRAVERSE_END

    printf("\n");
	return 0;
}
