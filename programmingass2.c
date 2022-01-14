#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

//구조체 선언
struct word{
	char eng[16];
	char kor[30];
	struct word *next;
};

typedef struct word WORD;
typedef WORD *LINK;	//포인터


//파일을 오픈, 링크드리스트에 저장까지 구현
LINK read_file_sort()
{
     
        LINK head=NULL;
	LINK tail=NULL;
        LINK cur;
	
        FILE *fp;
	if((fp=fopen("dic.txt","r"))==NULL) //파일 오픈
        {
                printf("dic.txt 파일을 열 수 없습니다. \n");
                exit(1);
        }
	
	

        char tmp1[16];	//영어 저장할 임시 변수 
        char tmp2[21];	//한글 저장할 임시 변수 
        int count=0;
	
        
	//파일을 읽어와서 연결리스트에 저장 
	while(fscanf(fp,"%s %s\n",tmp1,tmp2)!=EOF)	
        {
		
		cur=malloc(sizeof(WORD));
		strcpy(cur->eng,tmp1);	//읽어와서 저장
		strcpy(cur->kor,tmp2);	//읽어와서 저장 
		cur->next=NULL;


		count++;
		if(head==NULL)
		{
			head=cur;	//head가 첫번째 노드를 가리키도록 
		}else{
			tail->next=cur;	//tail이 마지막 노드를 가리키도록 
		}
		
		tail=cur;

		
        }

	

	//정렬을 위한 새로운 커서 선언 
	LINK cur2=malloc(sizeof(WORD));
	cur2=head;
	
	
	//BUBBLE SORT를 이용한 정렬
	for(int i=0;i<count;i++)
	{	
		if(cur2->next==NULL) break;
		for(int j=0;j<count-i-1;j++)
		{	
			if(strcmp(cur2->eng,cur2->next->eng)>0)	//순서가 맞지 않을경우
			{
			
				//swap
				strcpy(tmp1,cur2->eng);
				strcpy(tmp2,cur2->kor);
				strcpy(cur2->eng,cur2->next->eng);
				strcpy(cur2->kor,cur2->next->kor);
				strcpy(cur2->next->eng,tmp1);
                                strcpy(cur2->next->kor,tmp2);
				
			}

			cur2=cur2->next;
		}
		cur2=head->next;
	}
	



	return head;
}



//정렬이 제대로 되었는지 확인하기 위해 링크드리스트를 출력해보는 함수 
 
int count_2=0;
void print_list(LINK head)
{	
	if(head->next==NULL)
	{	
		printf("%d %s %s ---> ",count_2,head->eng,head->kor);
		printf("NULL\n");
	}
	else {
		printf("%d %s %s--> \n",count_2,head->eng,head->kor);
		count_2++;
		print_list(head->next);
	}
}


void play_game(LINK head)
{
	char buf[16];
	LINK cur=malloc(sizeof(WORD));
	cur=head;
	int tot=0;	//전체 문항 개수 
	int c_num=0;	//맞춘 것의 개수 
	int inc_num=0;	//틀린 것의 개수 
	float score;
	bool check=0;
	while(cur!=NULL)
	{	
		printf("%s -> ",cur->kor);
		scanf("%s",buf);
		if(!strcmp(buf,".quit"))
		{
			check=1;
			printf("당신의 점수는 %.2f 점입니다. \n",(float)c_num/tot*100);
			
			break;
			
		}else if(!strcmp(buf,cur->eng))
		{
			printf("correct!\n");
			c_num++;
		}
		else 
		{
			printf("incorrect!\n");
			inc_num++;
		}
		
		tot++;	
		cur=cur->next;
	}

	if(check==0)
	{	// 전체를 출력하고 끝난경우  
		printf("당신의 점수는 %.2f 점입니다.\n",(float)c_num/tot*100);
	}


}

int main()
{
	int input;	//입력받은 번호 저장
	FILE *fp;
	LINK h;
	
	h=read_file_sort();
//	print_list(h);


	
	


	system("clear");
	printf(">>영어 단어 맞추기 프로그램<<\n");
	printf("1. 영어 단어 맞추기\t2. 프로그램 종료\n\n");
	printf("번호를 선택하세요: ");
	scanf("%d",&input);
	system("clear");

	if(input==1)
	{
		printf(">>영어 단어 맞추기<<\n");
		play_game(h);
		getchar();
		getchar();
		main();
	}
	else if(input==2)
	{
		system("clear");
		return 0;
	}
	else
	{
		printf("1 또는 2를 선택하세요\n");
		main();
	}

		
}