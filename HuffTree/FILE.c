#include"FILE.h"

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
