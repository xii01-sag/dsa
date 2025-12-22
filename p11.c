#include <stdio.h>
#define MAX 100
struct G
{
    int v, a[MAX][MAX];
};
void init(struct G *g, int v)
{
    g->v = v;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            g->a[i][j] = 0;
}
void addEdge(struct G *g, int s, int d)
{
    if (s < g->v && d < g->v)
        g->a[s][d] = 1;
}
void DFS(struct G *g, int s, int vis[])
{
    printf("%d ", s);
    vis[s] = 1;
    for (int i = 0; i < g->v; i++)
        if (g->a[s][i] && !vis[i])
            DFS(g, i, vis);
}
void BFS(struct G *g, int s)
{
    int q[MAX], f = 0, r = 0, vis[MAX] = {0};
    printf("%d ", s);
    vis[s] = 1;
    q[r++] = s;
    while (f < r)
    {
        int c = q[f++];
        for (int i = 0; i < g->v; i++)
            if (g->a[c][i] && !vis[i])
            {
                printf("%d ", i);
                vis[i] = 1;
                q[r++] = i;
            }
    }
}
int main()
{
    struct G g;
    int n, e, s, d, start;
    printf("Enter vertices: ");
    scanf("%d", &n);
    init(&g, n);
    printf("Enter edges: ");
    scanf("%d", &e);
    while (e--)
    {
        scanf("%d %d", &s, &d);
        addEdge(&g, s, d);
    }
    printf("Enter start node: ");
    scanf("%d", &start);
    int vis[MAX] = {0};
    printf("DFS: ");
    DFS(&g, start, vis);
    printf("\nBFS: ");
    BFS(&g, start);
    return 0;
}
