#include<stdio.h>
#include<stdlib.h>
#include"BST.h"
#include"Operation.h"

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
