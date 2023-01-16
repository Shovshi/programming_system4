#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

void CreateGraph(pnode head)
{
    int numOfNodes = 0;
    scanf("%d", &numOfNodes);
    (head)->node_num = 0;
    pnode temp = head;

    for (int i = 1; i < numOfNodes; i++)
    {
        pnode next = NULL;
        next = malloc(sizeof(node));
        if (next == NULL)
        {
            exit(1);
        }
        (next)->node_num = i;
        (temp)->next = next;
        temp = (temp)->next;
    }
}

void FreeGraph(pnode head)
{
    pnode t = head;
    pnode t2 = head;
    while (t->next != NULL)
    {
        t = t->next;
        FreeEdges(t2->edges);
        free(t2);
        t2 = t2->next;
    }
    free(t);
}

void FreeEdges(pedge head)
{
    pedge t = head;
    pedge t2 = head;
    while (t->next != NULL)
    {
        t = t->next;
        free(t2);
        t2 = t2->next;
    }
    free(t);
}

char InsertEdges(pnode head)
{
    char firstNumber = 0;
    char secondNumber = 0;
    int nodeNumber = 0;

    printf("NODE TO WORK ON:\n");
    scanf(" %d", &nodeNumber);
    pnode curr = Find(nodeNumber, head);
    printf("THE NODE IS %d\n", curr->node_num);


    pedge graphEdge = NULL;
    graphEdge = malloc(sizeof(edge));
    if (graphEdge == NULL)
    {
        exit(1);
    }

    curr->edges = graphEdge;

    while (1)
    {
        scanf(" %c", &firstNumber);
        firstNumber = firstNumber - '0';
        if (firstNumber < 0 || firstNumber >= 9)
        {
            return firstNumber + '0';
        }
        scanf(" %c", &secondNumber);
        secondNumber = secondNumber - '0';
        pnode nodeNumber = Find(firstNumber, head);
        graphEdge->endpoint =  NULL;
        graphEdge->endpoint = nodeNumber;
        graphEdge->weight = secondNumber;

        printf("THIS IS NODENUMBER %d\n", nodeNumber->node_num);
        printf("THIS IS WEIGHT: %d\n", secondNumber);
        pedge nextEdge = NULL;
        nextEdge = malloc(sizeof(edge));
        if (nextEdge == NULL)
        {
            exit(1);
        }

        graphEdge->next = nextEdge;
        graphEdge = graphEdge->next;
    }
    free(graphEdge);
    PrintGraph(head);

}

pnode Find(int number, pnode head)
{
    pnode curr = head;
    while (curr != NULL)
    {
        if (curr->node_num == number)
        {
            return curr;
        }
        curr=curr->next; 
    }
    return NULL;
}

void insertNode(pnode head)
{
    int numOfNode = 0;
    scanf("%d", &numOfNode);
    pnode nodeToInsert = Find(numOfNode, head);

    int firstNumber = 0;
    int secondNumber = 0;
    // while ()
    {
        /* code */
    }
}
void PrintGraph(pnode head)
{
    /*pnode current = head;
    pedge edge = head->edges;

    while (current != NULL)
    {
        printf("THIS IS NODE NUMBER: %d    ", current->node_num);
        while (edge->next != NULL)
        {
            printf("Weight: %d,", edge->weight);
            printf("To node number: %d,", edge->endpoint->node_num);
            edge = edge->next;
        }
        current = current->next;
        printf("\n");
    }*/

    pedge currEdge = NULL;

    if(head==NULL)
    {
        printf("The graph is empty!\n");
        return;
    }

    while(head != NULL)
    {
        pedge currEdge = NULL;

    if (head == NULL)
    {
        printf("The graph is empty!\n");
        return;
    }

    while (head != NULL)
    {
        currEdge = head->edges;

        printf("Node #%d:\n", head->node_num);

        if(currEdge == NULL)
            printf("No edges are coming out from the node.\n");

        else
        {
            while (currEdge != NULL)
            {
                printf("w(%d,%d) = %d\n", head->node_num, currEdge->endpoint->node_num, currEdge->weight);
                currEdge = currEdge->next;

                if (currEdge != NULL)
                    printf(",");
            }
        }
        printf("\n");
        head = head->next;
    }
}
}
