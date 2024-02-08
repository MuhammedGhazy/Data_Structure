#include "main.h"


void Insert_Node_After (struct Node *list)
{
	struct Node *TempNode = NULL, *NodeListCounter = NULL;
	uint32_t Counter = 1, NodePosition = 0, ListLength = 0;

	printf("Please Enter Node Position (First Position Is 1)\n");
	scanf("%i", &NodePosition);
	ListLength = Get_Length (list);
	if(NodePosition > ListLength)
	{
		printf("Invalid Node Position -> List Has (%i) Nodes \n", ListLength);
	}
	else
	{
		NodeListCounter = list;
		while(Counter < NodePosition)
		{
			Counter++;
			NodeListCounter	= NodeListCounter->Node_Link;
		}
		TempNode = (struct Node *)malloc(sizeof(struct Node));
		if(NULL == TempNode)
		{
		    printf("Invalid Address!!\n");
		}
		else
		{
			printf("Enter Node Data :");
			scanf("%i", &TempNode->Node_Data);
			TempNode->Node_Link = NodeListCounter->Node_Link;
			NodeListCounter->Node_Link = TempNode;
		}
	}
}


