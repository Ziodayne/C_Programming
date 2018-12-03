#include <stdio.h>
#include <stdbool.h>

typedef struct edge_node
{

    int v;
    int weight;
    struct edge_node *next;

} edge_node;

typedef struct graph
{

    edge_node **edges;
    int nb_nodes;
    int nb_edges;
    bool is_directional;

} graph;

graph *create_graph(int nb_nodes, bool is_directional)
{

    graph *g = (graph *)malloc(sizeof(graph));
    g->nb_nodes = nb_nodes;
    g->nb_edges = 0;
    g->is_directional = is_directional;

    g->edges = (edge_node **)malloc(sizeof(edge_node) * nb_nodes);
    int i;
    for (i = 0; i < nb_nodes; i++)
    {
        g->edges[i] = NULL;
    }
    return g;
}

void print_graph(graph *g)
{

    int i;
    for (i = 0; i < g->nb_nodes; i++)
    {
        printf("%d --> ", i);
        edge_node *p = g->edges[i];
        while (p != NULL)
        {
            printf("%d ", p->v);
            p = p->next;
        }
        printf("\n");
    }
}

void add_node(graph *g, int u, int v, int weight)
{

    edge_node *e = (edge_node *)malloc(sizeof(edge_node));
    e->v = v;
    e->weight = weight;
    e->next = g->edges[u];
    g->edges[u] = e;
    g->nb_edges++;

    if (g->is_directional)
    {
        e = (edge_node *)malloc(sizeof(edge_node));
        e->v = u;
        e->weight = weight;
        e->next = g->edges[v];
        g->edges[v] = e;
        g->nb_edges++;
    }
}

void shortest_path(graph *g)
{

    edge_node *p = g->edges[0];
    int distance = 0;
    int car = 0;
    int weight = p->weight;

    printf("Distance Travelled: %d\n", distance);

    while (p != g->edges[g->nb_nodes])
    {
        while (p != NULL)
        {
            if (p->weight < weight)
                weight = p->weight;
            p = p->next;

            if (p == NULL)
            {
                p = g->edges[car];
                while (p != NULL)
                {
                    if (p->weight == weight)
                    {
                        printf("Node: %d\tWeight is %d\n", p->v, p->weight);
                        distance += p->weight;
                        printf("Distance Travelled: %d\n", distance);
                        car = p->v;
                        p = g->edges[car];
                        weight = p->weight;
                        break;
                    }
                    p = p->next;
                }
            }
        }
        //if(p == g->edges[g->nb_edges]) break;
        p = p->next;
    }

    printf("Distance Travelled: %d\n", distance);
}

int main()
{
    graph *g = create_graph(8, false);
    add_node(g, 0, 1, 2);
    add_node(g, 0, 2, 1);
    add_node(g, 0, 3, 3);
    add_node(g, 1, 4, 1);
    add_node(g, 1, 5, 2);
    add_node(g, 2, 5, 1);
    add_node(g, 3, 6, 1);
    add_node(g, 4, 7, 1);
    add_node(g, 5, 4, 1);
    add_node(g, 5, 6, 2);
    add_node(g, 6, 7, 1);

    shortest_path(g);

    //print_graph(g);

    return 0;
}
