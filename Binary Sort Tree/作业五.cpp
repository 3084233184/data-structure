#include<stdio.h>
#include<stdlib.h>
#define MAX 20
#define YES true
#define NO false 
typedef int KeyType; //数据类型 

typedef struct BSTNode{
    KeyType  data;
    struct BSTNode *LChild;
    struct BSTNode *RChild;
}BSTNode,*BSTree; 
 

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
 * 判断是否为二叉排序树 
**/
bool IsBSTree(BSTree node)
{
	if(node == NULL) return YES;
	if( node->LChild == NULL && node->RChild == NULL ) return YES;
	if( node->LChild != NULL && node->RChild == NULL )
	{
		if(node->LChild->data > node->data) return NO;
		else return IsBSTree(node->LChild);
	}
	if( node->LChild == NULL && node->RChild!=NULL)
	{
		if( node->RChild->data < node->data ) return NO;
		else return IsBSTree(node->RChild);
	}
	if( node->RChild != NULL && node->LChild != NULL)
	{
		if(( node->LChild->data > node->data ) || ( node->RChild->data < node->data )) 
			return NO;
		else
			return ( IsBSTree(node->LChild) && IsBSTree(node->RChild) );
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



/**
 * 中序打印二叉树
**/ 
void Inorder(BSTree &node)
{
    if(node == NULL) return;
    Inorder(node->LChild);
    printf("%d ",node->data);
    Inorder(node->RChild);
}

/**
 * 树形打印哈夫曼树 
**/ 
void Tree_Print(BSTree &node,int level)
{
	static FILE *fp=fopen("TreePrint.txt","w");
	if(node!=NULL)
	{
		switch(level)
		{
			case 0:break;
			case 1:printf("|_____");fprintf(fp,"|_____");break;
			case 2:printf("|______|_____");fprintf(fp,"|______|_____");break;
			case 3:printf("|____________|_____");fprintf(fp,"|____________|_____");break;
			case 4:printf("|___________________|_____");fprintf(fp,"|___________________|_____");break;
			case 5:printf("|__________________________|_____");fprintf(fp,"|__________________________|_____");break;
			default:break;
		}
		level++;
		printf("%d \n",node->data);
		fprintf(fp,"%d \n",node->data);
		
		Tree_Print(node->LChild,level);
		Tree_Print(node->RChild,level);
	}	
	return;
}

int main()
{
	int Key_Num;
    KeyType Key[MAX];
    BSTree ROOT = NULL;
    char Choose;
    
    
    printf("是否从文件中获取整数集（y/n）？");
	scanf("%c",&Choose); 
	printf("请输入整数集大小：\n");
	scanf("%d",&Key_Num); 
	if(Choose=='Y'|Choose=='y')
	{
	    FILE *fp=fopen("Keys.txt","r");
	    if(fp==NULL)
		{
	        printf("路径错误或找不到该文件请查证是否已编码后重试!\n");
	        system("pause");
	        return 0;
	    }
	    for(int i=0;i<Key_Num;i++)
	    {
		    fscanf(fp,"%d",&Key[i]);
		}
	    fclose(fp);
	}
	if(Choose=='N'|Choose=='n')
	{
		for(int i=0;i<Key_Num;i++)
		{
			printf("请输入第%d个整数：",i+1);
			scanf("%d",&Key[i]);
		}
	}
    CreatBSTree(ROOT,Key,Key_Num);
    
    
    printf("该二叉树的中序遍历为：\n      ");
    Inorder(ROOT);
    
    printf("\n");
    Tree_Print(ROOT,0);
    if(IsBSTree(ROOT))
    {
    	printf("\n这是一颗二叉树排序树。\n");
    	return 0; 
	}
	printf("\n这不是一颗二叉树排序树。");
    printf("\n"); 
    
    return 0;
}
