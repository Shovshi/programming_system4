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
        next->edges = NULL;
        next->next = NULL;
        
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

void InsertEdges(pnode head)
{
    int firstNumber = 0;
    int secondNumber = 0;
    int nodeNumber = 0;

    printf("NODE TO WORK ON:\n");
    scanf(" %d", &nodeNumber);
    pnode curr = Find(nodeNumber, head);
    if (curr == NULL)
    {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    }
    //printf("THE NODE IS %d\n", curr->node_num);
    if(curr->edges != NULL)
    {
        FreeEdges(curr->edges);
    }
    printf("test\n");

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
        if (scanf(" %d", &firstNumber) == 0)
        {
            return;
        }

        scanf(" %d", &secondNumber);
        pnode nodeNumber = Find(firstNumber, head);

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
        if (curr->next == NULL)
        {     
            pnode newNode; 
            newNode = malloc(sizeof(node));
            if (newNode == NULL)
                {
                    exit(1);
                }
            newNode->edges = NULL;
            newNode->next = NULL;
            newNode->node_num = number;
            curr->next = newNode;
            return newNode;
        }
        curr=curr->next; 
    }
}

void InsertNode(pnode head)
{
    int numOfNode = 0;
    scanf("%d", &numOfNode);
    int didExist = 0;

    while (head->next != NULL)
    {
        if(head->next->node_num == numOfNode)
        {
            didExist = 1;
            break;
        }
        head = head->next;
    }

}

void PrintGraph(pnode head)
{
    pnode current = head;
    pedge edge = head->edges;

    while (current != NULL)
    {
        printf("THIS IS NODE NUMBER: %d    \n", current->node_num);
        while (edge->next != NULL)
        {
            printf("Weight: %d,", edge->weight);
            printf("To node number: %d,\n", edge->endpoint->node_num);
            edge = edge->next;
        }            
        current = current->next;
        if (current == NULL)
        {
            return;
        }
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

