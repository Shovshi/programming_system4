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
        next->edges = NULL;
        next->next = NULL;
        next->node_num = 0;

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
    while (head != NULL) 
    {
        pnode temp = head;
        FreeEdges(temp->edges);
        head = head->next;
        free(temp);
        if(head == NULL) return;
    }    
}

void FreeEdges(pedge head)
{
    while (head != NULL) 
    {
        pedge temp = head;
        head = head->next;
        free(temp);
        if(head == NULL) return;
    }    
}

char InsertEdges(pnode head)
{
    char firstNumber = 0;
    char secondNumber = 0;
    int nodeNumber = 0;

    printf("NODE TO WORK ON:\n");
    scanf(" %d", &nodeNumber);
    pnode curr = Find(nodeNumber, head);
    //printf("THE NODE IS %d\n", curr->node_num);


    pedge graphEdge = NULL;
    graphEdge = malloc(sizeof(edge));
    if (graphEdge == NULL)
    {
        exit(1);
    }
    graphEdge->endpoint = NULL;
    graphEdge->next = NULL;
    graphEdge->weight = 0;

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
        graphEdge->weight = 0;
        graphEdge->endpoint = nodeNumber;
        graphEdge->endpoint->node_num = nodeNumber->node_num;
        graphEdge->weight = secondNumber;

        printf("THIS IS NODENUMBER %d\n", nodeNumber->node_num);
        printf("THIS IS WEIGHT: %d\n", secondNumber);
        pedge nextEdge = NULL;
        nextEdge = malloc(sizeof(edge));
        nextEdge->endpoint = NULL;
        nextEdge->next = 0;
        nextEdge->weight = 0;
        if (nextEdge == NULL)
        {
            exit(1);
        }

        graphEdge->next = nextEdge;
        graphEdge = nextEdge;
    }
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
    pnode current = head;
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
        if(current->edges != NULL)
        {
            edge = current->edges;
        }
        else
        {
            break;
        }

        printf("\n");
    }
}

