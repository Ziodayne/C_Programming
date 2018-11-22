# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

//////////////////// Graph Theory


typedef struct edge_node{

    int v;
    int weight;
    struct edge_node * next;

} edge_node;


typedef struct graph{

    edge_node **edges;
    int nb_nodes;
    int nb_edges;
    bool is_directional;

} graph;

graph * create_graph(int nb_nodes, bool is_directional){

    graph * g = (graph *) malloc(sizeof(graph));
    g->nb_nodes = nb_nodes;
    g->is_directional = is_directional;
    g->edges = (edge_node **) malloc(sizeof(edge_node) * nb_nodes);

    int i;

    for(i=0;i<nb_nodes;i++){
        g->edges[i] = NULL;
    }

    return g;
}

void print_graph(graph * g){


    int i;
    for(i=0;i< g->nb_nodes;i++)
    {
        printf("%d --> ",i);
        edge_node * p = g->edges[i];
        while(p != NULL)
        {
            printf("%d ", p->v);
            p = p->next;
        }
        printf("\n");
    }

}

// u is the number inside the adjacency array, v is the node value;


void add_edge(graph * g,int u, int v, int weight){

    edge_node * e = (edge_node *) malloc(sizeof(edge_node));
    e->v = v;
    e->weight = weight;

    e->next = g->edges[u];
    g->edges[u] = e;
    g->nb_edges++;

    if(!g->is_directional)
    {
        e = (edge_node *) malloc(sizeof(edge_node));
        e->v = u;
        e->weight = weight;
        e->next = g->edges[v];
        g->edges[v] = e;
        g->nb_edges++;
    }
}

int main(){

    graph * g = create_graph(5,false);
    add_edge(g,2,4,1);
    add_edge(g,2,5,1);


    print_graph(g);


    return 0;
}

