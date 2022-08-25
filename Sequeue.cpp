//
// Created by 2048 on 2022/8/25.
//
#define MaxVertexNum 5
#include "Sequeue.h"

void InitQueue(SeQueue &Q){
    Q.rear = Q.front = 0;
}
bool isEmpty(SeQueue Q){
    if(Q.front == Q.rear)
        return true;
    return false;
}
bool EnQueue(SeQueue &Q,VertexType x){
    if((Q.rear + 1) % MaxVertexNum == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = Q.rear + 1 % MaxVertexNum;
    return true;
}
bool DeQueue(SeQueue &Q,VertexType &x){
    if(Q.rear == Q.front) return false;
    x = Q.data[Q.front];
    Q.front++;
    return true;
}