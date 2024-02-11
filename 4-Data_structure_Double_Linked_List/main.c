#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

#define DELETE_NODE_AT_BEGINNING

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
void Insert_Node_At_After (struct Node *list, uint32_t Data, uint32_t position);
void Insert_Node_At_Before (struct Node **list, uint32_t Data, uint32_t position);
void Delete_Node_At_Beginning(struct Node **list);
void Delete_Node_At_End (struct Node *list);
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
	Insert_Node_At_After(D_L_L, 99, 3);
	Display_All_Nodes(D_L_L);
	Insert_Node_At_Before(&D_L_L, 88, 1);
	Insert_Node_At_Before(&D_L_L, 23, 5);
	Delete_Node_At_Beginning(&D_L_L);
	Delete_Node_At_End(D_L_L);
	Delete_Node_At_End(D_L_L);
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

void Insert_Node_At_After (struct Node *list, uint32_t Data, uint32_t position)
{
        struct Node *Temp_Node = NULL, *Node_List_Counter_One = NULL, *Node_List_Counter_Tow = NULL;

	Node_List_Counter_One = list;
	while(position != 1)
	{
		Node_List_Counter_One = Node_List_Counter_One->Right_Node_Link;
		position--;
	}

        Temp_Node =(struct Node *) malloc(sizeof(struct Node));
        if(NULL != Temp_Node)
        {
                Temp_Node->Node_Data = Data;
		if(NULL == Node_List_Counter_One->Right_Node_Link)
		{
			Node_List_Counter_One->Right_Node_Link = Temp_Node;
			Temp_Node->Left_Node_Link = Node_List_Counter_One;
                	Temp_Node->Right_Node_Link = NULL;
		}
		else
		{
			Node_List_Counter_Tow = Node_List_Counter_One->Right_Node_Link;
			Node_List_Counter_One->Right_Node_Link = Temp_Node;
			Node_List_Counter_Tow->Left_Node_Link = Temp_Node;
			Temp_Node->Left_Node_Link = Node_List_Counter_One;
			Temp_Node->Right_Node_Link = Node_List_Counter_Tow;
		}
	}
	else
        {
                 printf("Error!! Cant Allocate The new Node.\n");
        }


}

void Insert_Node_At_Before (struct Node **list, uint32_t Data, uint32_t position)
{
	struct Node *Temp_Node = NULL;
	struct Node *Node_List_Counter_One = NULL;
	struct Node *Node_List_Counter_Tow = NULL;
	uint32_t Node_Position = position;

	Node_List_Counter_One = (*list);
	while(Node_Position > position -1)
	{
		Node_List_Counter_One = Node_List_Counter_One->Right_Node_Link;
		Node_Position--;
	}
	Temp_Node = (struct Node *) malloc (sizeof(struct Node));
	if(NULL != Temp_Node)
	{
		Temp_Node->Node_Data = Data;
		if(1 == position)
		{
			Temp_Node->Left_Node_Link = NULL;
			Temp_Node->Right_Node_Link = (*list);
			(*list)->Left_Node_Link = Temp_Node;
			(*list) = Temp_Node;
		}
		else
		{
			Node_List_Counter_Tow = Node_List_Counter_One->Right_Node_Link;
			Node_List_Counter_One->Right_Node_Link = Temp_Node;
			Node_List_Counter_Tow->Left_Node_Link = Temp_Node;
			Temp_Node->Right_Node_Link = Node_List_Counter_Tow;
			Temp_Node->Left_Node_Link = Node_List_Counter_One;
		}
	}
	else
	{
			printf("Error!! Cant Allocate The new Node.\n");
	}
	
}

void Delete_Node_At_Beginning(struct Node **list)
{
	struct Node *Temp_Node = *list;

#ifdef DELETE_NODE_AT_BEGINNING

(*list) = (*list)->Right_Node_Link;
(*list)->Left_Node_Link = NULL;
free(Temp_Node);
Temp_Node = NULL;
#elif
(*list) = (*list)->Right_Node_Link;
free((*list)->Left_Node_Link);
(*list)->Left_Node_Link = NULL;
#endif
}

void Delete_Node_At_End (struct Node *list)
{
	struct Node *Node_List_Counter_One = list;
	struct Node *Node_List_Counter_Two = NULL;

	while(Node_List_Counter_One->Right_Node_Link != NULL)
	{
		Node_List_Counter_One = Node_List_Counter_One->Right_Node_Link;
	}
	Node_List_Counter_Two = Node_List_Counter_One->Left_Node_Link;
	Node_List_Counter_Two->Right_Node_Link = NULL;
	free(Node_List_Counter_One);
	Node_List_Counter_One = NULL;
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


