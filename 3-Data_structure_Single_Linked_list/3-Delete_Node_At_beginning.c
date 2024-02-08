#include"main.h"

void Delete_Node_At_beginning (struct Node **list)
{
	struct Node *TempNode = *list;
	uint32_t List_Lenght = 0;

	List_Lenght = Get_Length (*list);
	if (List_Lenght == 0)
	{
		printf("List Is Empty, Nothing To Be Deleted!! \n");
	}
	else
	{
		*list = TempNode->Node_Link;
		TempNode->Node_Link = NULL;
		free(TempNode);
	}
}
