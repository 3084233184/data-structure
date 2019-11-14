#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1 
#define FALSE 0
#define MAX 32767 


//定义哈夫曼树结点类型 
struct HuffTree
{
 char Character;//该点的字符 
 int Weight;//该节点的权值 
 int Lchild;//记录左孩子结点  的数组下标 
 int Rchild;//记录右孩子结点的数组下标
 int Parent;//记录父亲结点的数组下标
}Tree[MAXSIZE];
 
 //定义哈夫曼编码结点类型 
struct HuffCode
{
	char code[MAX];
	int start;
}HCD[MAXSIZE];


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
//创建树 
void Get_Data(int Data_len)
{  
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
	for(int i=0;i<Data_len;i++)
	{
		printf("请输入第%d个字符；",i+1);
		setbuf(stdin,NULL);
		//fflush(stdin);
		scanf("%c",&Tree[i].Character);//输入字符 
		printf("请输入字符'%c'权值；",Tree[i].Character);
		scanf("%d",&Tree[i].Weight); //输入权值 
	}
}

/* 循环构造 Huffman 树 */
int Creat_HuffmanTree(int Data_len)
{  
	int Lnode,Rnode;
	int min1,min2;
	int Tree_len=0;
    for (int i=0; i<Data_len-1; i++)
    {
        min1=min2=MAX;     /* m1、m2中存放两个无父结点且结点权值最小的两个结点 */
        Lnode==0;
        /* 找出所有结点中权值最小、无父结点的两个结点，并合并之为一颗二叉树 */
        for (int j=0; j<Data_len+i; j++)
        {
            if (Tree[j].Weight < min1 && Tree[j].Parent==-1)
            {
                min2=min1; 
                Rnode=Lnode; 
                min1=Tree[j].Weight;
                Lnode=j;
            }
            else if (Tree[j].Weight < min2 && Tree[j].Parent==-1)
            {
                min2=Tree[j].Weight;
                Rnode=j;
            }
        } /* end for */
            /* 设置找到的两个子结点 x1、x2 的父结点信息 */
        Tree[Lnode].Parent  = Data_len+i;
        Tree[Rnode].Parent  = Data_len+i;
        Tree[Data_len+i].Weight = Tree[Lnode].Weight + Tree[Rnode].Weight;
        Tree[Data_len+i].Lchild = Lnode;
        Tree[Data_len+i].Rchild = Rnode;
    } 
    
    //求根节点的下标 
    while(Tree[Tree_len].Parent!=-1)
    {
    	Tree_len=Tree[Tree_len].Parent;
    	Tree_len=Tree_len;
	}
	//end for 
	
    printf ("\n成功创建哈夫曼树！\n");
	if(!Write_Tree(Data_len))
	{
		printf("写入文件时出错，请联系管理员！\n");	
	}
	printf ("成功写入文件hfmTree！\n");
	return Tree_len; 
}

int Initialization()//初始化系统 
{
	int Data_len;
	printf("你选择的是\n          初始化功能！\n请输入你要处理的字符集大小：");
	scanf("%d",&Data_len);
	Get_Data(Data_len);
	return Data_len;
}

//对文字进行哈夫曼编码 
int Ecoding_Article(int Data_len)
{
	int A_lenth;
	char choose;
	char Article[MAXSIZE];
	char Code[MAX];
	int count;
	printf("是否翻译ToBeTran.txt中的文字（y/n）？");
	setbuf(stdin,NULL);
	scanf("%c",&choose);
	 if(choose=='y'||choose=='Y')
	{	
		printf("请输入你要文件中的文字长度：");
		scanf("%d",&A_lenth);  
 		//从文件中提取需要编码的文字 
	    FILE *p1=fopen("ToBeTran.txt","r");
	    if(!p1)
	        printf("打开失败\n");
	    for(int i=0;i<A_lenth;i++)
	    {
	        fscanf(p1,"%c",&Article[i]);
	    }
	    fclose(p1);
	    //end for
		printf("\n您要编码的文字是：");
		for(int q=0; q<A_lenth; q++)
		{
			printf("%c",Article[q]);
		}
	}
	if(choose=='n'||choose=='N')
	{
		//从终端获取需要编码的文字 
		printf("请输入你要编码的文字长度：");
		scanf("%d",&A_lenth); 
		printf("\n请输入你要编码的文字：");
		for(int q=0; q<A_lenth; q++)
		{
			setbuf(stdin,NULL);
			scanf("%c",&Article[q]);
		}
		printf("\n您要编码的文字是：");
		for(int q=0; q<A_lenth; q++)
		{
			printf("%c",Article[q]);
		}
		//end for 
	}
	//end for 
	printf("\n");
	printf("其哈夫曼编码是");
	for(int p=0;p<A_lenth;p++)
	{
		for(int q=0;q<Data_len;q++)
		{
			if(Article[p]==Tree[q].Character)
			{
				for(int z=HCD[q].start+1;z<MAXSIZE;z++)
				{
					printf("%c",HCD[q].code[z]);
					Code[count++]=HCD[q].code[z];
				}
			}
		}
	}
	Write_Code(Code,count);
	system("pause");
	return count;
}

// 对哈夫曼树进行编码 
void Ecoding(int Data_len)
{
	int k;
	for(k=0;k<Data_len;k++)
	{
		int j=k;
		int lenth=MAXSIZE-1;
		while(Tree[j].Parent!=-1)
		{
			if(Tree[ Tree[j].Parent ].Lchild==j)
			   HCD[k].code[lenth--]='0';
			if(Tree[ Tree[j].Parent ].Rchild==j)
			   HCD[k].code[lenth--]='1';
				j=Tree[j].Parent;
			
		}
		HCD[k].start=lenth;
	}
	
	printf("各字符哈弗曼编码如下：\n    字符  \n");
	for(int i=0;i<Data_len;i++)
	{
		printf("    %c        ",Tree[i].Character);
		for(int x=HCD[i].start+1;x<MAXSIZE;x++)
		printf("%c",HCD[i].code[x]);
		printf("\n");
	}
}
//通过文件中的数据建立哈夫曼树 
int Creat_HuffmanTree_byFile(int Data_len)
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
			Creat_HuffmanTree(Data_len); 
		}
		if(choose=='n'||choose=='N')
		{
			printf("按任意键返回上一级。");
			system("pause");  
		}
	}
	return Data_len;
}
//译码
void Decoding(int Data_len,int count,int Tree_len) 
{
	//从文件中获取哈夫曼编码 
	char Code[MAXSIZE];
	Read_Code(Code,count);
	
	printf("文件中储存的哈夫曼编码是：");
    for(int i=0;i<count;i++)
    {
    	printf("%c",Code[i]);
	}
	printf("\n");
	printf("Tree_len=%d",Tree_len);
	//end for  
	
	//
	int Trans=Tree_len;
	char Translation[MAX];
	printf(""); 
	int T=0;
	printf("\n其译文为：");
	int i=0;
	while(Code[i]!='\0')
	{
		if(Code[i]=='0')
		{
			Trans=Tree[Trans].Lchild;
		}
		if(Code[i]=='1')
		{
			Trans=Tree[Trans].Rchild;
		}
		if(Tree[Trans].Rchild==-1&&Tree[Trans].Lchild==-1)//
		{
			printf("%c",Tree[Trans].Character);
			Translation[T++]=Tree[Trans].Character;
			Trans=Tree_len;
		}
		i++; 
	}
	Write_Trans(Translation,T);
	system("pause");
}

//打印代码文件 
void Code_Print(int count)
{
	char Code[MAXSIZE];
	Read_Code(Code,count);
	for(int i=0;i<count;i++)
	{
		printf("%c",Code[i]);
		if((i+1)%50==0)
			printf("\n");
	}
	printf("\n");
	Write_Print(Code,count);
	system("pause");
}
 
//打印哈夫曼树 
void Tree_Print(int LEN,int level)
{
	static FILE *fp=fopen("TreePrint.txt","w");
	if(Tree[LEN].Weight!=0)
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
		printf("%d %c\n",Tree[LEN].Weight,Tree[LEN].Character);
		fprintf(fp,"%d %c\n",Tree[LEN].Weight,Tree[LEN].Character);
		
		Tree_Print(Tree[LEN].Lchild,level);
		Tree_Print(Tree[LEN].Rchild,level);
	}	
	return;
}

//打印菜单 
void Display()
{
     printf("  欢迎使用本哈弗曼编译码系统！\n");
     printf("********************************\n");
     printf("*                              *\n");
     printf("*    I                 初始化  *\n");
     printf("*                              *\n");
     printf("*    E                 编  码  *\n");
     printf("*                              *\n");
     printf("*    D                 译  码  *\n");
     printf("*                              *\n");
     printf("*    P               印代码文件*\n");
     printf("*                              *\n");
     printf("*    T               印哈夫曼树*\n");
     printf("*                              *\n");
     printf("*    Q                退出系统 *\n");
     printf("*                              *\n");
     printf("********************************\n");
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
//功能选择 
void Menu()
{
	 int Data_len=0;//字符集长度 
	 int count;//编码长度 
	 int Tree_len;//根节点的下标
	 int level=0;//树高 
     char choose;
     do{
     Display();
     printf("请输入你的选择:");
     setbuf(stdin,NULL); 
     scanf("%c",&choose);
     switch(choose)
         {
         case 'I':  
         case 'i': Data_len=Initialization();Tree_len=Creat_HuffmanTree(Data_len);system("pause");system("cls");break;
         case 'E':  
		 case 'e': CreatTreeBYFile(Data_len,Tree_len); 
		 		   if(Data_len==0) break;
			       Ecoding(Data_len);count=Ecoding_Article(Data_len);system("cls");break;
         case 'D':  
         case 'd': Decoding(Data_len,count,Tree_len);system("cls");break;
         case 'P':  
         case 'p': Code_Print(count);system("cls");break;
         case 'T':  
         case 't': Tree_Print(Tree_len,level);system("pause");system("cls");break;
         case 'Q':  
         case 'q': system("cls");printf("欢迎再次使用本系统！");exit(1);
         default: printf("输入错误！请输入正确的序号！\n");system("cls"); 
         }
     }while(choose!='q'||choose!='Q');
} 

int main()
{
	system("mode con cols=55 lines=35");
	Menu(); 
}

    /* 用于测试是否成功生成哈夫曼树 
	    for(int i=0;i<2*Data_len-1;i++)
	{
		printf("%c%d%d\n",Tree[i].Character,Tree[i].Weight,Tree[i].Parent);
	}*/
	
	/* 用于查看从文件中获取的信息 
		printf("从文件中找到的编码是：");
		for(int j=0;j<count;j++)
		{
			printf("%c",Code[j]); 
		
		}
	*/ 
