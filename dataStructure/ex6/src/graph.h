#include "graph_def.h"

Graph::Graph(){
    n=tot=0;
}

Graph::Graph(int nn){
    n=nn;
    tot=0;
    memset(link,0,sizeof(maxn));
    memset(to,0,sizeof(maxe));
    memset(next,0,sizeof(maxe));
    memset(weight,0,sizeof(maxe));
}

void Graph::add_edge(int x,int y,int z){
    tot++;
    to[tot]=y; weight[tot]=z;
    next[tot]=link[x]; link[x]=tot;
}

int Graph::get_first(int x){ return link[x]; }

int Graph::get_to(int e){ return to[e]; }
int Graph::get_next(int e){ return next[e]; }
int Graph::get_weight(int e){ return weight[e]; }

void Graph::set_mark(int x, bool v){ vis[x]=v; }
bool Graph::get_mark(int x){ return vis[x]; }