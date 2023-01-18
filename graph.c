#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX __INT32_MAX__


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

    scanf(" %d", &nodeNumber);
    pnode curr = Find(nodeNumber, head);
    if(curr->edges != NULL)
    {
        FreeEdges(curr->edges);
    }

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
        pedge nextEdge = NULL;
        nextEdge = malloc(sizeof(edge));
        nextEdge->endpoint = NULL;
        nextEdge->next = NULL;
        nextEdge->weight = 0;

        if (nextEdge == NULL)
        {
            exit(1);
        }
        if (scanf(" %d", &firstNumber) == 0)
        {            
            free(nextEdge);
            return;
        }

        scanf(" %d", &secondNumber);
        pnode nodeNumber = Find(firstNumber, head);

        graphEdge->endpoint = nodeNumber;
        graphEdge->endpoint->node_num = nodeNumber->node_num;
        graphEdge->weight = secondNumber;


        graphEdge->next = nextEdge;
        graphEdge = graphEdge->next;
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


void DeleteNode(pnode head , int nodeToDelete)
{
    pnode temp = head;

    while (temp->next != NULL)
    {            
        if(temp->next->node_num == nodeToDelete)
        {
            printf("here7\n");
            pnode temp2 = temp->next;
            DeleteEdgesToNode(head , nodeToDelete);
            temp->next = temp->next->next;
            FreeEdges(temp2->edges);
            free(temp2);
        }
            printf("here8\n");

        temp = temp->next;
    }
    
}

void DeleteEdgesToNode(pnode head , int nodeToDelete)
{
    pnode curr = head;
    pedge edge = NULL;
    while (curr != NULL)
    {
        if(curr->edges == NULL)
        {
            curr = curr->next;
            continue;
        }

        edge = curr->edges;
        if (edge->endpoint->node_num == nodeToDelete) // IF THE EDGE TO DELETE IS THE FIRST
        {
            if(edge->next == NULL) // IF THE EDGE IS SINGLE WE FREE IT
            {
                free(edge);
            }
            else // IF THE EDGE ISN'T SINGLE WE CONNECT THE NODE TO THE NEXT EDGE AND FREE THE PREVIOUS ONE
            {                
                curr->edges = edge->next;
                free(edge);
            }
        }
        else
        {
            while (edge!= NULL)
            {
                if(edge->endpoint == NULL || edge->next == NULL || edge->next->endpoint == NULL)
                {
                    break;
                }
                if(edge->next->endpoint->node_num == nodeToDelete)
                {
                    if(edge->next->next->endpoint == NULL) // THE NODE TO DELETE IS THE LAST ONE
                    {
                        FreeEdges(edge->next);
                        edge->next = NULL;
                    }
                    else if(edge->next->next->endpoint != NULL) // THE NODE TO DELETE IS NOT THE LAST OR FIRST ONE
                    {
                        pedge temp = edge->next;
                        edge->next = edge->next->next;
                        free(temp);
                    } 
                }
                edge = edge->next;
            }   
        }
        curr = curr->next;
    }
}

void Dijkstra(pnode head)
{
    int number1 = 0;
    int number2 = 0;

    pnode curr = head;

    scanf(" %d" , &number1);
    scanf(" %d", &number2);

   while (curr != NULL)
   {
        curr->isVisited = 0;
        curr->fastestPath = MAX;
        curr = curr->next;
   }
   
   pnode dijkstra1 = Find(number1 , head);
   pnode dijkstra2 = Find(number2 , head);

   dijkstra1->fastestPath = 0;
    curr = dijkstra1;
    
   while (curr != NULL)
   {
        if(curr->isVisited)
        {
            curr = curr->next;
            continue;
        }
        pedge edge = curr->edges;
        while (edge->endpoint != NULL)
        {   

            if(edge->endpoint->fastestPath > edge->weight + curr->fastestPath)
            {
                edge->endpoint->fastestPath = edge->weight + curr->fastestPath;
            }
            if(edge->next == 0)
            {
                break;
            }
            edge = edge->next;
        }
       curr->isVisited = 1;
       curr = MinimumNeihgbour(curr);  // returns minimum of its neighbors that has not been visited
   }
   
   if(dijkstra2->fastestPath == MAX)
   {
        printf("-1\n");
        return;
   }
    printf("%d\n",dijkstra2->fastestPath);
}

pnode MinimumNeihgbour(pnode node)
{
        pnode nodeWithMinimumWeight = NULL;
        int min = MAX;
        pedge edge = node->edges;
        while (edge->endpoint != NULL)
        {
            if (edge->endpoint->fastestPath < min && edge->endpoint->isVisited == 0)
            {
                nodeWithMinimumWeight = edge->endpoint;
            }
            edge = edge->next;
        }
        return nodeWithMinimumWeight;
}

void PrintGraph(pnode head)
{
    pnode current = head;
    pedge edge = head->edges;

    while (current != NULL)
    {
        printf("THIS IS NODE NUMBER: %d    \n", current->node_num);
        while (edge->endpoint != NULL)
        {
            printf("Weight: %d,", edge->weight);
            printf("To node number: %d,\n", edge->endpoint->node_num);
            if(edge->next == NULL || edge->next == 0)
            {
                break;
            }
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

void TSP(pnode head)
{
    // SCAN AMOUNT OF NODES NEEDED , MALLOC THE MEMORY FOR THEM THEN INSERT
    int numberOfNodesToTravelThrough = 0;
    scanf(" %d" , &numberOfNodesToTravelThrough);
    int * nodeToTraverse = malloc( numberOfNodesToTravelThrough * (sizeof(int)));
    if(nodeToTraverse == NULL)
    {
        exit(1);
    }

    int tempNode = 0;
    for (int i = 0; i < numberOfNodesToTravelThrough; i++)
    {
        scanf("%d\n" , &tempNode);
        *(nodeToTraverse + i * (sizeof(int))) = tempNode;
    }
    
    for (int j = 0; j < numberOfNodesToTravelThrough; j++)
    {
        printf(" %d\n", *(nodeToTraverse + j * (sizeof(int))));
    }
    

    free(nodeToTraverse);
    printf("here\n");
}
