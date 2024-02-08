#include "main.h"

void Insert_Node_At_End (struct Node **list)
{
	struct Node *TempNode = NULL;
	struct Node *LastNode = NULL;

	TempNode =(struct Node *) malloc(sizeof(struct Node));
	if(NULL == TempNode)
	{
		printf("Error!! Invalid Address\n");
	}
	else
	{
		printf("Please Enter Node Data :");
		scanf("%i", &TempNode->Node_Data);
		TempNode->Node_Link = NULL;
	}
	if(NULL == *list)
	{
		*list = TempNode;
	}
	else
	{
		LastNode = *list;
		while(LastNode->Node_Link != NULL)
		{
			LastNode = LastNode->Node_Link;
		}
		LastNode->Node_Link = TempNode;
	}

}
