#ifndef MAX
#define MAX 20
#define YES true
#define NO false
#include<stdio.h>
#include<stdlib.h>
typedef int KeyType; //�������� 

typedef struct BSTNode{
    KeyType  data;
    struct BSTNode *LChild;
    struct BSTNode *RChild;
}BSTNode,*BSTree; 

/**
 * ���±������Ҹ����������ڽڵ�,�Ա����ָ���ڵ�
**/
void SearchBSTreeNode(BSTree &ROOT,BSTree &node);

/**
 * ����ָ���ڵ�node
**/
void Insert(BSTree &ROOT,BSTree &node);

/**
 * ��������������
**/
void CreatBSTree(BSTree &ROOT,KeyType Key[],int Key_Num);

#endif 
