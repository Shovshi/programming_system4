#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main()
{
    char choice = 0;
    pnode head = NULL;
    head = (malloc(sizeof(node)));
    head->edges = NULL;
    head->next = NULL;
    head->node_num = 0;
    if (head == NULL)
    {
        printf("Malloc failed\n");
        return -1;
    }
    while (scanf("%c", &choice) != EOF)
    {
        if (choice == 'A')
        {
            CreateGraph(head);
        }
        if (choice == 'B')
        {
            InsertEdges(head);
        }
        if (choice == 'D')
        {
            int nodeToDelete = 0;
            scanf(" %d", &nodeToDelete);
            if (nodeToDelete == head->node_num)
            {
                pnode temp = head;
                DeleteEdgesToNode(head, nodeToDelete);
                head = head->next;
                FreeEdges(temp->edges);
                free(temp);
            }
            else
            {
                DeleteNode(head, nodeToDelete);
            }
        }
        if (choice == 'S')
        {
            Dijkstra(head);
        }
        if (choice == 'T')
        {
            TSP(head);
        }
        if (choice == 'n')
        {
            InsertEdges(head);
        }
    }
    //printf("BEFORE PRINT / FREE \n");
    //PrintGraph(head);
    FreeGraph(head);
    return 0;
}