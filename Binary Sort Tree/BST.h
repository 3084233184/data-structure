#ifndef MAX
#define MAX 20
#define YES true
#define NO false
#include<stdio.h>
#include<stdlib.h>
typedef int KeyType; //数据类型 

typedef struct BSTNode{
    KeyType  data;
    struct BSTNode *LChild;
    struct BSTNode *RChild;
}BSTNode,*BSTree; 

/**
 * 向下遍历查找给定结点的相邻节点,以便插入指定节点
**/
void SearchBSTreeNode(BSTree &ROOT,BSTree &node);

/**
 * 插入指定节点node
**/
void Insert(BSTree &ROOT,BSTree &node);

/**
 * 二叉排序树创建
**/
void CreatBSTree(BSTree &ROOT,KeyType Key[],int Key_Num);

#endif 
