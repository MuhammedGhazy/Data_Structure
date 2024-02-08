#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>

struct Node
{
        unsigned int Node_Data;
        struct Node *Node_Link;
};

typedef enum
{
        Return_NOkay,
        Return_Okay
}Return_Status_T;

struct Node *List_Head = NULL;

typedef enum
{
	List_N_Okay,
	List_Okay
}List_Status_T;

List_Status_T Insert_Node_At_Beginning (struct Node **list);
List_Status_T Insert_Node_At_End (struct Node **list);
Return_Status_T Insert_Node_After (struct Node **list);
uint32_t Get_Length(struct Node *List);
void Delete_Node_At_beginning (struct Node **list);
void Delete_Node(struct Node *list);
void Display_All_Nodes (struct Node *list);


#endif // MAIN_H
