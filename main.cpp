#include <iostream>
#include "Sequeue.h"
#define MaxVertexNum 5


using namespace std;
typedef char VertexType;
typedef int EdgeType;

typedef struct {
    VertexType Vex[MaxVertexNum] = {'A','B','C','D','E'};
    EdgeType Edge[MaxVertexNum][MaxVertexNum] =  {0,1,1,0,1,
                                                  1,0,0,1,1,
                                                  1,0,0,1,0,
                                                  0,1,1,0,1,
                                                  1,1,0,1,0};
    int vexnum,edgenum;
}MGraph;

int VertexIndex(MGraph graph,VertexType x);
bool Adjacent(MGraph graph,VertexType x, VertexType y);
int FirstNeighbor(MGraph G,VertexType x);
int NextNeighbor(MGraph G,VertexType x,VertexType y);

void BFS(MGraph G,int v,bool *visited,SeQueue &Q);
void BFSTraverse(MGraph G);
void visit(MGraph G,int v);
int main() {
    MGraph graph;
    graph.vexnum = 5;
    graph.edgenum = 7;
    BFSTraverse(graph);
    return 0;
}

/**
 * 判断是否存在<x,y>在graph中
 * @param graph
 * @param x
 * @param y
 * @return
 */
bool Adjacent(MGraph graph,VertexType x, VertexType y){
    int xi = VertexIndex(graph,x);
    int yi = VertexIndex(graph,y);
    return graph.Edge[xi][yi] > 0;
}
/**
 * 返回顶点x在顶点表中的位置,不存在则返回-1
 * @param graph
 * @param x
 * @return
 */
int VertexIndex(MGraph graph,VertexType x){
    for (int i = 0; i < graph.vexnum; ++i) {
        if (x == graph.Vex[i]){
            return i;
        }
    }
    return -1;
}
/**
 * 求图G中顶点x的第一个邻接点，返回定点号，如果不存在x或者x没有邻接点则返回-1
 * @param G
 * @param x
 * @return
 */
int FirstNeighbor(MGraph G,VertexType x){
    int xi = VertexIndex(G,x);
    if(xi == -1)
        return -1;
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.Edge[xi][i] > 0 )
            return i;
    }
    return -1;
}
int NextNeighbor(MGraph G,VertexType x,VertexType y){
    int xi = VertexIndex(G,x);
    int yi = VertexIndex(G,y);
    for (int i = yi + 1; i < G.vexnum; ++i) {
        if (G.Edge[xi][i] > 0)
            return i;
    }
    return -1;
}
void visit(MGraph G,int v){
    cout<<G.Vex[v]<<endl;
}
void BFS(MGraph G,int v,bool *visited,SeQueue &Q){
    visit(G,v);

    visited[v] = true;


    EnQueue(Q,G.Vex[v]);
    while (!isEmpty(Q)){
        VertexType x;
        int w = -1;
        DeQueue(Q,x);
        for(w = FirstNeighbor(G,x);w >= 0;w = NextNeighbor(G,x,G.Vex[w])){
            if(!visited[w]){
                visit(G,w);
                visited[w] = true;
                EnQueue(Q,G.Vex[w]);
            }
        }
    }
}
void BFSTraverse(MGraph G){
    bool visited[G.vexnum];
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }
    SeQueue  Q;
    InitQueue(Q);

    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i])
            BFS(G ,i, visited,Q);
    }
}
void DFSTraverse(MGraph G){
    bool visited[G.vexnum];
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }

}
