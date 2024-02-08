#include "main.h"

void Insert_Node_At_Beginning (struct Node **list)
{

	struct Node *Temp_Node = NULL;

	Temp_Node =(struct Node *) malloc(sizeof (struct Node));
	if(NULL == Temp_Node)
	{
		printf("Error!! In Alocated Memory.\n");

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

		}
	}

}



