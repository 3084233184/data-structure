#include<stdio.h> 
#include<stdlib.h>
#include"LinkStack.h"
#include"Game.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//������ main 
int main()
{
  system("mode con cols=50 lines=25"); 
  LinkStack *Top;
  for(int i=0;i<11;i++)
  {
  for(int j=0;j<10;j++)
  printf("%2d  ",Map[i][j]);
  printf("\n");
  }
  Top=CreatLinkStack();
  Top=FindAnswer(Top);
  printf("����\n0->��,1->��,2->��,3->��\n"); 
  printf("\n");
  DispStack(Top);//����յ� 
  printf("\n");
  system("pause");
}
