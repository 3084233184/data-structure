#include"Operation.h"

/**
 * ÅĞ¶ÏÊÇ·ñÎª¶ş²æÅÅĞòÊ÷ 
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
 * Ê÷ĞÎ´òÓ¡¹ş·òÂüÊ÷ 
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
/**
 * ÖĞĞò´òÓ¡¶ş²æÊ÷
**/ 
void Inorder(BSTree &node)
{
    if(node == NULL) return;
    Inorder(node->LChild);
    printf("%d ",node->data);
    Inorder(node->RChild);
}
