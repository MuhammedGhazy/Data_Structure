#include "main.h"

void Display_All_Nodes (struct Node *list)
{
	struct Node *TempNode = list;

	printf("Node Value : ");
	if(NULL == TempNode)
	{
		printf("List Is Empty!!\n");
	}
	else
	{
		while(TempNode != NULL)
		{
			printf("%i ->", TempNode->Node_Data);
			TempNode = TempNode->Node_Link;
		}
		if(NULL == TempNode)
		{
			printf("NULL\n");
		}
	}
}
