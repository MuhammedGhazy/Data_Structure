#include "main.h"

int main()
{
	int User_Choice = 0;
	uint32_t List_Length = 0;
	List_Status_T ret_status = List_N_Okay;
	Return_Status_T Ret_Status = Return_NOkay;

 	printf("-> Hello to Single Linked List \n");
    	while(1){
        	printf("\n");
        	printf("===============================\n");
        	printf("-> 1) Insert_Node_At_Beginning \n");
        	printf("-> 2) Insert_Node_At_End \n");
        	printf("-> 3) Insert_Node_After \n");
        	printf("-> 4) Delete_Node_At_Beginning \n");
        	printf("-> 5) Delete_Node \n");
        	printf("-> 6) Display_All_Nodes \n");
        	printf("-> 7) Get_Length \n");
        	printf("-> 8) Quit from application \n");
       		printf("===============================\n");

        	printf("\n");
        	printf("UserChoice : ");
        	scanf("%i", &User_Choice);

        	switch(User_Choice){
            	case 1:
                	Insert_Node_At_Beginning(&List_Head);
            	break;
            	case 2:
                	Insert_Node_At_End(&List_Head);
            	break;
            	case 3:
                	Insert_Node_After(&List_Head);
            	break;
            	case 4:
                	Delete_Node_At_beginning(&List_Head);
            	break;
            	case 5:
                	Delete_Node(List_Head);
            	break;
            	case 6:
			Display_All_Nodes(List_Head);
            	break;
            	case 7:
                	List_Length = Get_Length(List_Head);
                	printf("List Length : << %i >> Nodes\n", List_Length);
            	break;
            	case 8:
                	printf("Quit from application \n");
                	exit(1);
            	break;
            	default:
                	printf("User Choice out of range !!\n");
            	break;
        	}
    	}
    	return (0);
}

