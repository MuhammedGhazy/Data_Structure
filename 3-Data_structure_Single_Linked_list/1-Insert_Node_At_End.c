#include "main.h"

List_Status_T Insert_Node_At_End (struct Node **list)
{
	List_Status_T ret_Val = List_N_Okay;
	struct Node *TempNode = NULL;
	struct Node *LastNode = NULL;

	TempNode =(struct Node *) malloc(sizeof(struct Node));
	if(NULL == TempNode)
	{
		ret_Val = List_N_Okay;
		printf("Error!! Invalid Address\n");
	}
	else
	{
		printf("Please Enter Node Data :");
		scanf("%i", &TempNode->Node_Data);
		TempNode->Node_Link = NULL;
		ret_Val = List_Okay;
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
		ret_Val = List_Okay;
	}
	return (ret_Val);

}
