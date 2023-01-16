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
                scanf(" %c", &choice);
                printf("THIS IS CHOICE : %c\n", choice);
                
                while (choice == 'n')
                {
                   choice = InsertEdges(head);
                }
            }
            PrintGraph(head);
            printf("Everybody was kungfu fightinggggg\n");
        }
        if (choice == 'B')
        {
            InsertNode(head);
        }
        if (choice == 'D')
        {
            printf("I love shoval\n");
        }
        if (choice == 'S')
        {
            printf("I love shoval\n");
        }
        if (choice == 'T')
        {
            printf("I love shoval\n");
        }
        PrintGraph(head);
        FreeGraph(head);
        return 0;
    }
}