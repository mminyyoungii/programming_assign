#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<termio.h>
#include<unistd.h>
int sortedArray[15];
int array[15];


//getch함수 선언 
int getch(void) {
    int ch;
    struct termios buf;
    struct termios save;
    tcgetattr(0, &save);
    buf = save;
    buf.c_lflag &= ~(ICANON | ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch=getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}

                                          

//랜덤 출력을 위한 셔플
void shuffle(int *arr)
{	
	srand(time(NULL));
	int tmp;
	int n;
	for(int i=0;i<15;i++)
	{
		n=rand()%(15-i)+i;
		tmp=arr[i];
		arr[i]=arr[n];
		arr[n]=tmp;
	}
}


//빈 칸 기준으로 움직일 수 있는지 여부 확인 
//움직일 수 있으면 0, 못움직이면 1리턴
int canMove(int b_x, int b_y)
{
	if(b_x<0||b_y<0)
		return 1;
	if(b_x>3||b_y>3)
		return 1;
	return 0;
                                                                                                 }

int main(int argc, char *argv[])
{
	//sortedArra 정렬..
	for(int i=0;i<15;i++)
	{
		sortedArray[i]=i+1;
	}
	int b_x=3;
	int b_y=3;

	//위 왼쪽 아래 오른쪽
	char i='i';	
	char j='j';
	char k='k';
	char l='l';
	char q='q';
	int ch;

	if(!strcmp(argv[1],"1"))
	{
		//1번 실행
		for(int i=0;i<15;i++)
		{
			array[i]=i+1;
		}
		int k=0;
		
		system("clear");
		printf("\n\n\n\n\n\n\n");

		for(int i=0;i<4;i++)
		{	
			printf("\t\t\t\t\t\t\t\t\t\t\t");
			for(int j=0;j<4;j++)
			{	
				if(i==3 && j==3)
					break;
				printf("%5d  ",array[k]);	//기본 상태 출력 
				k++;
			}
			printf("\n");
		}

		int check=0;
		while(1)
		{
			ch=getch();
			if(ch=='q')		//q입력 받으면 종료 
				return 0;
			
			int tmp=0;	
			if(ch=='i')//i입력시 위로 
			{	
				
                                k=0;

                                b_y+=1;
                                if(canMove(b_x,b_y)==1)
                                {
                                        b_y-=1;
					//continue;
                                }
                                else
                                {
					check=1;
                                        int t=array[b_y*4+b_x];
                                         system("clear");
					  array[(b_y-1)*4+b_x]=t;
					array[b_y*4+b_x]=-1;
					printf("\n\n\n\n\n\n\n");

                                        for(int i=0;i<4;i++)
                                        {
						printf("\t\t\t\t\t\t\t\t\t\t\t");

                                        for(int j=0;j<4;j++)
                                        {
                                                if(i==b_y&&j==b_x)
                                                        printf("       ");
                                                else {
                                                        printf("%5d  ",array[k]);
                                                }

                                                k++;
                                        }
                                                printf("\n");
                                        }
                                  }
 				 printf("\n");


			}
			else if(ch=='j')	//j입력시 왼쪽 
			{
				k=0;
                                b_x+=1;
                                if(canMove(b_x,b_y)==1)
                                {
                                        b_x-=1;
					//continue;
                                }
                                else
                                {
					check=1;

                                        int t=array[b_y*4+b_x];
					system("clear");
                                        array[b_y*4+b_x-1]=t;
					array[b_y*4+b_x]=-1;
					
					printf("\n\n\n\n\n\n\n");

                                        for(int i=0;i<4;i++)
                                        {
						printf("\t\t\t\t\t\t\t\t\t\t\t");

                                        for(int j=0;j<4;j++)
                                        {
                                                if(i==b_y&&j==b_x)
                                                        printf("       ");
                                                else {
                                                        printf("%5d  ",array[k]);
                                                }

                                                k++;
                                        }
                                                printf("\n");
                                        }
                                }
				  printf("\n");


			}
			else if(ch=='k')	//k입력시 아래로 
			{
				 k=0;
				
                                b_y-=1;
                                if(canMove(b_x,b_y)==1)
                                {
                                        b_y+=1;
					//continue;
                                }
                                else
                                {
					check=1;

                                        int t=array[b_y*4+b_x];
                                        system("clear");

					array[(b_y+1)*4+b_x]=t;
					array[b_y*4+b_x]=-1;
					printf("\n\n\n\n\n\n\n");

                                        for(int i=0;i<4;i++)
                                        {
						printf("\t\t\t\t\t\t\t\t\t\t\t");

                                        for(int j=0;j<4;j++)
                                        {
                                                if(i==b_y&&j==b_x)
                                                        printf("       ");
                                                else {
                                                        printf("%5d  ",array[k]);
                                                }

                                                k++;
                                        }
                                                printf("\n");
                                        }
                                }
				  printf("\n");


			}
			else if(ch=='l')	//l입력 받으면 오른쪽   
			{
				k=0;	
                                b_x-=1;
                                if(canMove(b_x,b_y)==1)
                                {
                                        b_x+=1;
					//continue;
                                }
                                else
                                {
					check=1;

                                        int t=array[b_y*4+b_x];
					system("clear");
                                        array[b_y*4+(b_x+1)]=t;
					
					array[b_y*4+b_x]=-1;
					printf("\n\n\n\n\n\n\n");

                                        for(int i=0;i<4;i++)
                                        {
						printf("\t\t\t\t\t\t\t\t\t\t\t");

                                        for(int j=0;j<4;j++)
                                        {
                                                if(i==b_y&&j==b_x)
                                                        printf("       ");
						else {
                                                        printf("%5d  ",array[k]);
                                                }

                                                k++;
                                        }
                                                printf("\n");
                                        }
                                }
                                  printf("\n");

		
			  printf("\n");

			}


			if(check==1){
				int flag=0;

				for(int i=0;i<15;i++)
				{
					if(array[i]!=i+1)
						flag=1;
	
				}
				if(flag==0)
				{	
					sleep(3);
					printf("\n\t\t\t\t\t\t\t\t\t\t\t\t ");

					printf("축하합니다\n");
					return 0;
				}
			}
			
		}
	


		
	}
	else if(!strcmp(argv[1],"2"))
	{
		//2번 실행
		system("clear");
		for(int i=0;i<15;i++)
                {
                        array[i]=i+1;
                }
	
		shuffle(array);
		int k=0;
		printf("\n\n\n\n\n\n\n");

		//랜덤으로 수 출력하기 
		for(int i=0;i<4;i++)
		{	
			printf("\t\t\t\t\t\t\t\t\t\t\t");

			for(int j=0;j<4;j++)
			{
				if(i==3 && j==3)
                                      break;

				printf("%5d  ",array[k]);
				k++;
			}
			printf("\n");
		}
		printf("\n");
		

		
		while(1)
		{
			ch=getch();
			if(ch=='q')		//q입력 받으면 종료 
				return 0;
			
			int tmp=0;	
			if(ch=='i')//i입력시 위로 
			{
                                k=0;

                                b_y+=1;
                                if(canMove(b_x,b_y)==1)
                                {
                                        b_y-=1;
					//continue;
                                }
                                else
                                {
                                        int t=array[b_y*4+b_x];
                                        system("clear");
					array[(b_y-1)*4+b_x]=t;
					array[b_y*4+b_x]=-1;
					printf("\n\n\n\n\n\n\n");

                                        for(int i=0;i<4;i++)
                                        {
						printf("\t\t\t\t\t\t\t\t\t\t\t");

                                        for(int j=0;j<4;j++)
                                        {
                                                if(i==b_y&&j==b_x)
                                                        printf("       ");
                                                else {
                                                        printf("%5d  ",array[k]);
                                                }

                                                k++;
                                        }
                                                printf("\n");
                                        }
                                  }
 				 printf("\n");


			}
			else if(ch=='j')	//j입력시 왼쪽 
			{
				k=0;

                                b_x+=1;
                                if(canMove(b_x,b_y)==1)
                                {
                                        b_x-=1;
					//continue;
                                }
                                else
                                {
                                        int t=array[b_y*4+b_x];
                                        system("clear");
					array[b_y*4+b_x-1]=t;
					array[b_y*4+b_x]=-1;
					printf("\n\n\n\n\n\n\n");

                                        for(int i=0;i<4;i++)
                                        {
						printf("\t\t\t\t\t\t\t\t\t\t\t");

                                        for(int j=0;j<4;j++)
                                        {
                                                if(i==b_y&&j==b_x)
                                                        printf("       ");
                                                else {
                                                        printf("%5d  ",array[k]);
                                                }

                                                k++;
                                        }
                                                printf("\n");
                                        }
                                }
				  printf("\n");


			}
			else if(ch=='k')	//k입력시 아래로 
			{
				  k=0;

                                b_y-=1;
                                if(canMove(b_x,b_y)==1)
                                {
                                        b_y+=1;
					//continue;
                                }
                                else
                                {
                                        int t=array[b_y*4+b_x];
                                         system("clear");

					  array[(b_y+1)*4+b_x]=t;
					array[b_y*4+b_x]=-1;
					printf("\n\n\n\n\n\n\n");
                                        for(int i=0;i<4;i++)
                                        {  
						printf("\t\t\t\t\t\t\t\t\t\t\t");

                                        for(int j=0;j<4;j++)
                                        {
                                                if(i==b_y&&j==b_x)
                                                        printf("       ");
                                                else {
                                                        printf("%5d  ",array[k]);
                                                }

                                                k++;
                                        }
                                                printf("\n");
                                        }
                                }
				  printf("\n");


			}
			else if(ch=='l')	//l입력 받으면 오른쪽   
			{
				k=0;

                                b_x-=1;
                                if(canMove(b_x,b_y)==1)
                                {
                                        b_x+=1;
					//continue;
                                }
                                else
                                {
                                        int t=array[b_y*4+b_x];
                                        system("clear");
					array[b_y*4+(b_x+1)]=t;
					
					array[b_y*4+b_x]=-1;
					printf("\n\n\n\n\n\n\n");
                                        for(int i=0;i<4;i++)
                                        {
						printf("\t\t\t\t\t\t\t\t\t\t\t");

                                        for(int j=0;j<4;j++)
                                        {
                                                if(i==b_y&&j==b_x)
                                                        printf("       ");
						else {
                                                        printf("%5d  ",array[k]);
                                                }

                                                k++;
                                        }
                                                printf("\n");
                                        }
                                }
                                  printf("\n");

		
			  printf("\n");

			}



			int flag=0;

			for(int i=0;i<15;i++)
			{
				if(array[i]!=i+1)
					flag=1;

			}
			if(flag==0)
			{	
				sleep(3);
				printf("\n\t\t\t\t\t\t\t\t\t\t\t  ");

				printf("축하합니다\n");
				return 0;
			}

			
		}
		

	}
}
