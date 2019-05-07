#include<iostream>
#include<stack>
#include<queue>
#define TElemType int
using namespace std;
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild,*rchild;
    int LTag,RTag;
}BiThrNode,*BiThrTree;

