#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    char choice = 0;
    pnode head = NULL;

    while (scanf("%c", &choice) != EOF)
    {
        if (choice == 'A')
        {
            head = (malloc(sizeof(node)));
            head->edges = NULL;
            head->next = NULL;
            head->node_num = 0;
            if(head == NULL)
            {
                printf("Malloc failed\n");
                return -1;
            }
            else
            {
                CreateGraph(head);
            }
            printf("Everybody was kungfu fightinggggg\n");
        }
        if (choice == 'B')
        {
            InsertEdges(head);
        }
        if (choice == 'D')
        {
            int nodeToDelete = 0;
            scanf(" %d" , &nodeToDelete);
            DeleteNode(head , nodeToDelete);
                       
        }
        if (choice == 'S')
        {
            printf("I love shoval\n");
        }
        if (choice == 'T')
        {
            printf("I love shoval\n");
        }
        if (choice == 'n')
        {
            InsertEdges(head);
        }
    }
    printf("BEFORE PRINT / FREE \n");
    PrintGraph(head);
    FreeGraph(head);
    return 0;
}