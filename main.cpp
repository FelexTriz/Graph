#include <iostream>
#define MaxVertexNum 5

typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum] =  {0,1,1,0,1,
                                                  1,0,0,1,1,
                                                  1,0,0,1,0,
                                                  0,1,1,0,1,
                                                  1,1,0,1,0};
    int vexnum,edgenum;
}MGraph;

int vertexIndex(MGraph graph,VertexType x);
int main() {
    MGraph graph;
    graph.vexnum = 5;
    graph.edgenum = 7;

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
    int xi = vertexIndex(graph,x);
    int yi = vertexIndex(graph,y);
    return graph.Edge[xi][yi] > 0;
}
/**
 * 返回顶点x在顶点表中的位置,不存在则返回-1
 * @param graph
 * @param x
 * @return
 */
int vertexIndex(MGraph graph,VertexType x){
    for (int i = 0; i < graph.vexnum; ++i) {
        if (x == graph.Vex[i]){
            return i;
        }
    }
    return -1;
}