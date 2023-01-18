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

void insert_node_cmd(pnode *head);
void delete_node_cmd(pnode *head);
void printGraph_cmd(pnode head); // for self debug
void deleteGraph_cmd(pnode *head);
void shortsPath_cmd(pnode head);
void TSP_cmd(pnode head);

pnode Find(int number , pnode head);
pnode MinimumNeihgbour(pnode Node);
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
void TSP(pnode head);

#endif
