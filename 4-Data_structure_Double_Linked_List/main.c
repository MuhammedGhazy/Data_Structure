#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

struct Node
{
	uint32_t Node_Data;
	struct Node *Right_Node_Link;
	struct Node *Left_Node_Link;
};

struct Node *D_L_L = NULL;

void Display_All_Nodes (struct Node *list);
void Insert_Node_At_Beginning (struct Node **list, uint32_t Data);
void Insert_Node_At_End (struct Node *list, uint32_t Data);

int main()
{
	Insert_Node_At_Beginning(&D_L_L, 11);
	Insert_Node_At_Beginning(&D_L_L, 22);
	Insert_Node_At_Beginning(&D_L_L, 33);
	Display_All_Nodes(D_L_L);
	Insert_Node_At_End(D_L_L, 44);
	Insert_Node_At_End(D_L_L, 55);
	Insert_Node_At_End(D_L_L, 66);
	Display_All_Nodes(D_L_L);
	return (0);
}

void Insert_Node_At_Beginning (struct Node **list, uint32_t Data)
{
	struct Node *Temp_Node = NULL;

	Temp_Node =(struct Node *) malloc(sizeof(struct Node));
	if(NULL != Temp_Node)
	{
		Temp_Node->Node_Data = Data;
	
		if(NULL == *list)
		{
			Temp_Node->Right_Node_Link = NULL;
			Temp_Node->Left_Node_Link = NULL;
			(*list) = Temp_Node;
		}
		else
		{
			Temp_Node->Right_Node_Link = (*list);
			Temp_Node->Left_Node_Link = NULL;
			(*list)->Left_Node_Link = Temp_Node;
			(*list) = Temp_Node;
		}
	}
	else
	{
		printf("Error!! Cant Allocate The new Node.\n");
	}
}

void Insert_Node_At_End (struct Node *list, uint32_t Data)
{
	struct Node *Temp_Node = NULL, *Node_List_Counter = list;

	Temp_Node =(struct Node *) malloc(sizeof(struct Node));
	if(NULL != Temp_Node)
	{
		Temp_Node->Node_Data = Data;
		Temp_Node->Right_Node_Link = NULL;
		Node_List_Counter = list;
		while(Node_List_Counter->Right_Node_Link != NULL)
		{
			Node_List_Counter= Node_List_Counter->Right_Node_Link;
		}
		Temp_Node->Left_Node_Link = Node_List_Counter;
		Node_List_Counter->Right_Node_Link = Temp_Node;
	}
	else
	{
		 printf("Error!! Cant Allocate The new Node.\n");
	}


}

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
                        TempNode = TempNode->Right_Node_Link;
                }
                if(NULL == TempNode)
                {
                        printf("NULL\n");
                }
        }
}


