#include"BST.h"

/**
 * ���±������Ҹ����������ڽڵ�,�Ա����ָ���ڵ�
**/
void SearchBSTreeNode(BSTree &ROOT,BSTree &node){
    if(ROOT == NULL)
	{
        return;
    }
    if(ROOT->data > node->data)
	{
        SearchBSTreeNode(ROOT->LChild,node); //�ݹ��������
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
 * ����ָ���ڵ�node
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
 * ��������������
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
