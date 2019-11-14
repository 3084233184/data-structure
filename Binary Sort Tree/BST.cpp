#include"BST.h"

/**
 * 向下遍历查找给定结点的相邻节点,以便插入指定节点
**/
void SearchBSTreeNode(BSTree &ROOT,BSTree &node){
    if(ROOT == NULL)
	{
        return;
    }
    if(ROOT->data > node->data)
	{
        SearchBSTreeNode(ROOT->LChild,node); //递归遍历搜索
        if(ROOT->LChild == NULL)
		{
           ROOT->LChild = node;
        }
    }
	if(ROOT->data < node->data)
	{
        SearchBSTreeNode(ROOT->RChild,node);
        if(ROOT->RChild == NULL){
           ROOT->RChild = node;
        }
    }
}

/**
 * 插入指定节点node
**/
void Insert(BSTree &ROOT,BSTree &node){
    if(ROOT==NULL)
	{
        ROOT = node;
    }
	else{
        SearchBSTreeNode(ROOT,node);
    }
}

/**
 * 二叉排序树创建
**/
void CreatBSTree(BSTree &ROOT,KeyType Key[],int Key_Num)
{
    for(int i=0;i<Key_Num;i++)
	{
        BSTree s = (BSTree)malloc(sizeof(BSTNode));    
        s->data = Key[i];
        s->LChild = NULL;
        s->RChild = NULL;
        Insert(ROOT,s);
    }
}
