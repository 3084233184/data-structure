#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXSIZE 100
#define OK 1
#define ERROR 0
#define TRUE 1 
#define FALSE 0
#define MAX 32767 


//������������������ 
struct HuffTree
{
 char Character;//�õ���ַ� 
 int Weight;//�ýڵ��Ȩֵ 
 int Lchild;//��¼���ӽ��  �������±� 
 int Rchild;//��¼�Һ��ӽ��������±�
 int Parent;//��¼���׽��������±�
}Tree[MAXSIZE];
 
 //������������������� 
struct HuffCode
{
	char code[MAX];
	int start;
}HCD[MAXSIZE];


//дhfmTree�ļ�
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
//дCodeFile�ļ� 
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
//дTextFile�ļ�
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
//дCodePrin�ļ� 
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
//��CodeFile�ļ� 
bool Read_Code(char Code[],int count)
{
    FILE *fp=fopen("CodeFile.txt","r");
    if(fp==NULL)
	{
        printf("·��������Ҳ������ļ����֤�Ƿ��ѱ��������!\n");
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
// ��hfmTree�ļ���ʼ���� 
int Read_Tree() 
{
	int Data_len; 
	FILE *fp=fopen("hfmTree.txt","r");
 
    if(fp==NULL)
	{
        printf("·��������Ҳ������ļ����֤�Ƿ�������ַ���������!\n");
        system("pause");
    }
    for(int i=0;!feof(fp);i++)
    {
    	fscanf(fp,"%c %d\n",&Tree[i].Character,&Tree[i].Weight);
		Data_len=i;
	}
	printf("���ļ����ҵ����ַ�����Ȩֵ�ǣ�\n");
		for(int j=0;j<Data_len;j++)
		{
			printf("%c %d\n",Tree[j].Character,Tree[j].Weight); 
		
		}
		printf("\n");
    fclose(fp);
    system("pause");
    return Data_len;
}
//������ 
void Get_Data(int Data_len)
{  
	//��ʼ������ 
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
		printf("�������%d���ַ���",i+1);
		setbuf(stdin,NULL);
		//fflush(stdin);
		scanf("%c",&Tree[i].Character);//�����ַ� 
		printf("�������ַ�'%c'Ȩֵ��",Tree[i].Character);
		scanf("%d",&Tree[i].Weight); //����Ȩֵ 
	}
}

/* ѭ������ Huffman �� */
int Creat_HuffmanTree(int Data_len)
{  
	int Lnode,Rnode;
	int min1,min2;
	int Tree_len=0;
    for (int i=0; i<Data_len-1; i++)
    {
        min1=min2=MAX;     /* m1��m2�д�������޸�����ҽ��Ȩֵ��С��������� */
        Lnode==0;
        /* �ҳ����н����Ȩֵ��С���޸�����������㣬���ϲ�֮Ϊһ�Ŷ����� */
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
            /* �����ҵ��������ӽ�� x1��x2 �ĸ������Ϣ */
        Tree[Lnode].Parent  = Data_len+i;
        Tree[Rnode].Parent  = Data_len+i;
        Tree[Data_len+i].Weight = Tree[Lnode].Weight + Tree[Rnode].Weight;
        Tree[Data_len+i].Lchild = Lnode;
        Tree[Data_len+i].Rchild = Rnode;
    } 
    
    //����ڵ���±� 
    while(Tree[Tree_len].Parent!=-1)
    {
    	Tree_len=Tree[Tree_len].Parent;
    	Tree_len=Tree_len;
	}
	//end for 
	
    printf ("\n�ɹ���������������\n");
	if(!Write_Tree(Data_len))
	{
		printf("д���ļ�ʱ��������ϵ����Ա��\n");	
	}
	printf ("�ɹ�д���ļ�hfmTree��\n");
	return Tree_len; 
}

int Initialization()//��ʼ��ϵͳ 
{
	int Data_len;
	printf("��ѡ�����\n          ��ʼ�����ܣ�\n��������Ҫ������ַ�����С��");
	scanf("%d",&Data_len);
	Get_Data(Data_len);
	return Data_len;
}

//�����ֽ��й��������� 
int Ecoding_Article(int Data_len)
{
	int A_lenth;
	char choose;
	char Article[MAXSIZE];
	char Code[MAX];
	int count;
	printf("�Ƿ���ToBeTran.txt�е����֣�y/n����");
	setbuf(stdin,NULL);
	scanf("%c",&choose);
	 if(choose=='y'||choose=='Y')
	{	
		printf("��������Ҫ�ļ��е����ֳ��ȣ�");
		scanf("%d",&A_lenth);  
 		//���ļ�����ȡ��Ҫ��������� 
	    FILE *p1=fopen("ToBeTran.txt","r");
	    if(!p1)
	        printf("��ʧ��\n");
	    for(int i=0;i<A_lenth;i++)
	    {
	        fscanf(p1,"%c",&Article[i]);
	    }
	    fclose(p1);
	    //end for
		printf("\n��Ҫ����������ǣ�");
		for(int q=0; q<A_lenth; q++)
		{
			printf("%c",Article[q]);
		}
	}
	if(choose=='n'||choose=='N')
	{
		//���ն˻�ȡ��Ҫ��������� 
		printf("��������Ҫ��������ֳ��ȣ�");
		scanf("%d",&A_lenth); 
		printf("\n��������Ҫ��������֣�");
		for(int q=0; q<A_lenth; q++)
		{
			setbuf(stdin,NULL);
			scanf("%c",&Article[q]);
		}
		printf("\n��Ҫ����������ǣ�");
		for(int q=0; q<A_lenth; q++)
		{
			printf("%c",Article[q]);
		}
		//end for 
	}
	//end for 
	printf("\n");
	printf("�������������");
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

// �Թ����������б��� 
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
	
	printf("���ַ��������������£�\n    �ַ�  \n");
	for(int i=0;i<Data_len;i++)
	{
		printf("    %c        ",Tree[i].Character);
		for(int x=HCD[i].start+1;x<MAXSIZE;x++)
		printf("%c",HCD[i].code[x]);
		printf("\n");
	}
}
//ͨ���ļ��е����ݽ����������� 
int Creat_HuffmanTree_byFile(int Data_len)
{
	if(Data_len==0)
	{
	 	char choose;
		printf("δ�������������Ƿ��hfmTree�ļ��л�ȡ�ַ����Դ�����y/n����");
		setbuf(stdin,NULL);
		scanf("%c",&choose);
		if(choose=='y'||choose=='Y')
		{
			printf("\n��������Ҫ������ַ�����С��");
			scanf("%d",&Data_len);
			//��ʼ������ 
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
			printf("�������������һ����");
			system("pause");  
		}
	}
	return Data_len;
}
//����
void Decoding(int Data_len,int count,int Tree_len) 
{
	//���ļ��л�ȡ���������� 
	char Code[MAXSIZE];
	Read_Code(Code,count);
	
	printf("�ļ��д���Ĺ����������ǣ�");
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
	printf("\n������Ϊ��");
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

//��ӡ�����ļ� 
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
 
//��ӡ�������� 
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

//��ӡ�˵� 
void Display()
{
     printf("  ��ӭʹ�ñ�������������ϵͳ��\n");
     printf("********************************\n");
     printf("*                              *\n");
     printf("*    I                 ��ʼ��  *\n");
     printf("*                              *\n");
     printf("*    E                 ��  ��  *\n");
     printf("*                              *\n");
     printf("*    D                 ��  ��  *\n");
     printf("*                              *\n");
     printf("*    P               ӡ�����ļ�*\n");
     printf("*                              *\n");
     printf("*    T               ӡ��������*\n");
     printf("*                              *\n");
     printf("*    Q                �˳�ϵͳ *\n");
     printf("*                              *\n");
     printf("********************************\n");
}
//ͨ���ļ����ݽ����� 
bool CreatTreeBYFile(int &Data_len,int &Tree_len)
{
	if(Data_len==0)
	{
	 	char choose;
		printf("δ�������������Ƿ��hfmTree�ļ��л�ȡ�ַ����Դ�����y/n����");
		setbuf(stdin,NULL);
		scanf("%c",&choose);
		if(choose=='y'||choose=='Y')
		{
			printf("\n��������Ҫ������ַ�����С��");
			scanf("%d",&Data_len);
			//��ʼ������ 
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
			printf("�������������һ����");
			system("pause"); 
			return FALSE; 
		}
	}
}
//����ѡ�� 
void Menu()
{
	 int Data_len=0;//�ַ������� 
	 int count;//���볤�� 
	 int Tree_len;//���ڵ���±�
	 int level=0;//���� 
     char choose;
     do{
     Display();
     printf("���������ѡ��:");
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
         case 'q': system("cls");printf("��ӭ�ٴ�ʹ�ñ�ϵͳ��");exit(1);
         default: printf("���������������ȷ����ţ�\n");system("cls"); 
         }
     }while(choose!='q'||choose!='Q');
} 

int main()
{
	system("mode con cols=55 lines=35");
	Menu(); 
}

    /* ���ڲ����Ƿ�ɹ����ɹ������� 
	    for(int i=0;i<2*Data_len-1;i++)
	{
		printf("%c%d%d\n",Tree[i].Character,Tree[i].Weight,Tree[i].Parent);
	}*/
	
	/* ���ڲ鿴���ļ��л�ȡ����Ϣ 
		printf("���ļ����ҵ��ı����ǣ�");
		for(int j=0;j<count;j++)
		{
			printf("%c",Code[j]); 
		
		}
	*/ 
