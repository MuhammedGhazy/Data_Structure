#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdint.h>




void Insert_Node_At_Beginning (struct Node **list);
void Insert_Node_At_End (struct Node **list);
void Insert_Node_After (struct Node **list);
uint32_t Get_Length(struct Node *List);
void Delete_Node_At_beginning (struct Node **list);
void Delete_Node(struct Node *list);
void Display_All_Nodes (struct Node *list);


#endif // MAIN_H
