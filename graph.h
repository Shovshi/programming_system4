#ifndef GRAPH_
#define GRAPH_

typedef struct GRAPH_NODE_ *pnode;
;

typedef struct edge_
{

    int weight;
    pnode endpoint;
    struct edge_ *next;
} edge, *pedge;

typedef struct GRAPH_NODE_
{
    int isVisited;
    int fastestPath;
    int node_num;
    pedge edges;
    struct GRAPH_NODE_ *next;
} node, *pnode;


pnode Find(int number , pnode head); // find the pointer to a certain node
pnode MinimumNeihgbour(pnode Node); // returns pointer to neighbour with lowest weight
void InsertEdges(pnode head);
void FreeGraph(pnode head);
void CreateGraph(pnode head);
void FreeEdges(pedge head);
void InsertNode(pnode head);
void PrintGraph(pnode head);
void DeleteNode(pnode head , int nodeToDelete);
void DeleteEdgesToNode(pnode head , int node);
void Dijkstra(pnode head);
pnode MinimumNeihgbour(pnode node);
void Swap(int * arr , int start , int i);
int Permute(int *arr, int start, int end ,pnode head);
void TSP(pnode head);
int CalculatePath(pnode head,int * arr ,int end);
#endif
