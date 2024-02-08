#include "main.h"

uint32_t Get_Length(struct Node *List)
{
    struct Node *TempNode = List;
    uint32_t NodeCount = 0;

    while(TempNode != NULL)
    {
        NodeCount++;
        TempNode = TempNode->Node_Link;
    }

    return (NodeCount);
}

