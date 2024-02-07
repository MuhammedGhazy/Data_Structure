#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct Node
{
	unsigned int Node_Data;
	struct Node *Node_Link;
};

typedef enum
{
	Return_NOkay,
	Return_Okay
}List_Status_T;


struct Node *List_Head = NULL;

List_Status_T Insert_Node_At_Beginning (struct Node **list);



int main()
{
	List_Status_T Ret_Vall = Return_NOkay;

	Ret_Vall = Insert_Node_At_Beginning (&List_Head); printf("Status = %i \n", Ret_Vall);
	printf("Node Data Is => (%i)\n", List_Head->Node_Data);
	Ret_Vall = Insert_Node_At_Beginning (&List_Head); printf("Status = %i \n", Ret_Vall);
	printf("Node Data Is => (%i)\n", List_Head->Node_Data);
	Ret_Vall = Insert_Node_At_Beginning (&List_Head); printf("Status = %i \n", Ret_Vall);
	printf("Node Data Is => (%i)\n", List_Head->Node_Data);



	return (0);
}

List_Status_T Insert_Node_At_Beginning (struct Node **list)
{
	List_Status_T ret_val = Return_NOkay;
	struct Node *Temp_Node = NULL;

	Temp_Node =(struct Node *) malloc(sizeof (struct Node));
	if(NULL == Temp_Node)
	{
		printf("Error!! In Alocated Memory.\n");
		ret_val = Return_NOkay;
	}
	else
	{
		printf("Please Enter Node Data :");
		scanf("%i", &Temp_Node->Node_Data);

		if(NULL == *list)
		{
			Temp_Node->Node_Link = NULL;
			*list = Temp_Node;
		}
		else
		{
			Temp_Node->Node_Link = *list;
			*list = Temp_Node;
			ret_val = Return_Okay;
		}
	}
	return (ret_val);
}



