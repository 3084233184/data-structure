#include"FILE.h"

//写hfmTree文件
bool Write_Tree(int Data_len)
{
	FILE *fp=fopen("hfmTree.txt","w");
	
    for(int j=0;j<2*Data_len-1;j++)
	{
            fprintf(fp,"%c %d\n",Tree[j].Character,Tree[j].Weight); 
    }
    
    fclose(fp);   
	return  OK;	
}
//写CodeFile文件 
bool Write_Code(char Code[],int count)
{
	
	FILE *fp=fopen("CodeFile.txt","w");
    for(int j=0;j<count;j++)
	{
        fprintf(fp,"%c",Code[j]);
        //printf("%c",Code[j]);
    }
    fclose(fp);
	return  OK;	
}
//写TextFile文件
bool Write_Trans(char Translation[],int T)
{
	FILE *fp=fopen("TextFile.txt","w");
    for(int j=0;j<T;j++)
	{
        fprintf(fp,"%c",Translation[j]);
    }
    fclose(fp); 
	return  OK;
}
//写CodePrin文件 
bool Write_Print(char Code[],int count)
{
	FILE *fp=fopen("CodePrin.txt","w");
    for(int j=0;j<count;j++)
	{
        fprintf(fp,"%c",Code[j]);
        if( (j+1) % 50 == 0)
        fprintf(fp,"\n");
    }
    fclose(fp);
	return  OK;	
} 
//读CodeFile文件 
bool Read_Code(char Code[],int count)
{
    FILE *fp=fopen("CodeFile.txt","r");
    if(fp==NULL)
	{
        printf("路径错误或找不到该文件请查证是否已编码后重试!\n");
        system("pause");
        return 0;
    }
    for(int i=0;i<count;i++)
    {
	    fscanf(fp,"%c",&Code[i]);
	    Code[i+1]='\0';
	}
    fclose(fp);
    return OK;
}
// 读hfmTree文件初始化树 
int Read_Tree() 
{
	int Data_len; 
	FILE *fp=fopen("hfmTree.txt","r");
 
    if(fp==NULL)
	{
        printf("路径错误或找不到该文件请查证是否输入过字符集后重试!\n");
        system("pause");
    }
    for(int i=0;!feof(fp);i++)
    {
    	fscanf(fp,"%c %d\n",&Tree[i].Character,&Tree[i].Weight);
		Data_len=i;
	}
	printf("从文件中找到的字符集及权值是：\n");
		for(int j=0;j<Data_len;j++)
		{
			printf("%c %d\n",Tree[j].Character,Tree[j].Weight); 
		
		}
		printf("\n");
    fclose(fp);
    system("pause");
    return Data_len;
}
//通过文件内容建立树 
bool CreatTreeBYFile(int &Data_len,int &Tree_len)
{
	if(Data_len==0)
	{
	 	char choose;
		printf("未创建哈夫曼树是否从hfmTree文件中获取字符集以创建（y/n）？");
		setbuf(stdin,NULL);
		scanf("%c",&choose);
		if(choose=='y'||choose=='Y')
		{
			printf("\n请输入你要处理的字符集大小：");
			scanf("%d",&Data_len);
			//初始化数组 
			 for(int i=0;i<2*Data_len-1;i++)
			 {
				Tree[i].Lchild=-1;
				Tree[i].Rchild=-1;
				Tree[i].Parent=-1;
				Tree[i].Character=' ';
				Tree[i].Weight=0; 
			 }
			//end for
			Read_Tree();
			Tree_len=Creat_HuffmanTree(Data_len); 
			return TRUE;
		}
		if(choose=='n'||choose=='N')
		{
			printf("按任意键返回上一级。");
			system("pause"); 
			return FALSE; 
		}
	}
}
