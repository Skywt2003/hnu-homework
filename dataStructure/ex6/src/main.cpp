#include "graph.h"

const double INFINITY=1e9;

int n,m,s,t;
double dist[maxn];
Graph *G;

int get_min_vertex(){
    int ret=-1;
    double min_dist=INFINITY;
    for (int i=1; i<=n; i++)
        if (G->get_mark(i) == UNVISITED && dist[i] < min_dist) min_dist=dist[i], ret=i;
    return ret;
}

void Dijkstra(){
    for (int i=1;i<=n;i++) dist[i]=INFINITY;
    dist[t]=100.0;

    for (int i=1;i<=n;i++){
        int v=get_min_vertex();
        G->set_mark(v, VISITED);
        for (int e=G->get_first(v); e; e=G->get_next(e)){
            int u=G->get_to(e);
            dist[u] = std::min(dist[u] , dist[v] / (1.0 - (double)G->get_weight(e)/100.0));
        }
    }
}

int main(){
    std::cin>>n>>m;
    G = new Graph(n);

    while (m--){
        int x,y,z;
        std::cin>>x>>y>>z;
        G->add_edge(x,y,z);
        G->add_edge(y,x,z);
    }
    std::cin>>s>>t;

    Dijkstra();

    // std::printf("%.8lf\n", dist[s]);
    dist[s]-=5e-9;
    std::cout<<std::fixed<<std::setprecision(8)<<dist[s]<<std::endl;
    // std::cout<<dist[s]<<std::endl;
    return 0;
}