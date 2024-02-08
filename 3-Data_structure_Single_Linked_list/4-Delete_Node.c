#include "main.h"

void Delete_Node(struct Node *list)
{
	struct Node *NodeListCounter = list;
	struct Node *NextNode = list;
	uint32_t NodePosition = 0;
	uint32_t NodeCounter = 1;
	uint32_t ListLength = 0;

	printf("Enter Node Position (First Node Is 1)\n");
	scanf("%i", &NodePosition);
	ListLength = Get_Length(list);
	if((ListLength == 0) || (NodePosition > ListLength))
	{
		printf("Please Use Delete Node At Beginning!!\n");
	}
	else
	{
		while(NodeCounter < (NodePosition - 1))
		{
			NodeCounter++;
			NodeListCounter = NodeListCounter->Node_Link;
		}
		NextNode = NodeListCounter->Node_Link;
		NodeListCounter->Node_Link = NextNode->Node_Link;
		free (NextNode);
	}
}
