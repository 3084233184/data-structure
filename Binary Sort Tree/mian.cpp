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
    
    
    printf("�Ƿ���ļ��л�ȡ��������y/n����");
	scanf("%c",&Choose); 
	printf("��������������С��\n");
	scanf("%d",&Key_Num); 
	if(Choose=='Y'|Choose=='y')
	{
	    FILE *fp=fopen("Keys.txt","r");
	    if(fp==NULL)
		{
	        printf("·��������Ҳ������ļ����֤�Ƿ��ѱ��������!\n");
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
			printf("�������%d��������",i+1);
			scanf("%d",&Key[i]);
		}
	}
	
    CreatBSTree(ROOT,Key,Key_Num);
    
    
    printf("�ö��������������Ϊ��\n      ");
    Inorder(ROOT);
    
    printf("\n");
    Tree_Print(ROOT,0);
    if(IsBSTree(ROOT))
    {
    	printf("\n����һ�Ŷ�������������\n");
    	return 0; 
	}
	printf("\n�ⲻ��һ�Ŷ�������������");
    printf("\n"); 
    
    return 0;
}
