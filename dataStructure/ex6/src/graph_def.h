#include<cstdio>
#include<cstring>
#include<iostream>
#include<iomanip>

const int maxn=25, maxe=45;
const bool VISITED=true, UNVISITED=false;

class Graph{
    private:
        int n;
        int tot=0, link[maxn], to[maxe], next[maxe], weight[maxe];
        bool vis[maxn];

    public:
        Graph();
        Graph(int);

        void add_edge(int, int, int);

        int get_first(int);

        int get_to(int);
        int get_next(int);
        int get_weight(int);

        void set_mark(int, bool);
        bool get_mark(int);
};
