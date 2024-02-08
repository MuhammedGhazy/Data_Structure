#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

typedef enum
{
	List_N_Okay,
	List_Okay
}Return_Status_T;

struct Node
{
	unsigned int Node_Data;
	struct Node *Node_Link;
};

Return_Status_T Insert_Node_After (struct Node **list);

int main()
{

	return (0);
}
Return_Status_T Insert_Node_After (struct Node **list)
{
	Return_Status_T ret_val = List_N_Okay;
	struct Node *TempNode = NULL, *NodeListCounter = NULL;
	uint32_t Counter = 1, NodePosition = 0, ListLength = 0;

	printf("Please Enter Node Position (First Position Is 1)\n");
	scanf("%i", &NodePosition);
	ListLength = Get_Lenght (list);
	if(NodePosition > ListLength)
	{
		printf("Invalid Node Position -> List Has (%i) Nodes \n", ListLength);
		ret_val = List_N_Okay;
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
			ret_val = List_N_Okay;
		}
		else
		{
			printf("Enter Node Data :");
			scanf("%i", &TempNode->Node_Data);
			TempNode->Node_Link = NodeListCounter->Node_Link;
			NodeListCounter->Node_Link = TempNode;
			ret_val = List_Okay;
		}
	}
	return (ret_val);
}


