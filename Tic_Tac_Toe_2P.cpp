#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<stdio.h>
using namespace std;
void welcome()
{
	cout<<"Welcome to mt Tic-Tac-Toe game.GG.\n\n\n\n\n\nLoading............Please wait..............."<< endl;
	for(float i=0;i<10000000;i++)
	{
		//cout<<'\a';
	}
}
void win(char a[3][3], int & ctrl)
{
	int s;
	if(ctrl==0)
	{
		for(int col=0;col<3 && ctrl==0;col++)
		{
			if(a[0][col]=='x' && a[1][col]=='x' && a[2][col]=='x')
			{
				ctrl=1;
				break;
			} 
			if(a[0][col]=='o' && a[1][col]=='o' && a[2][col]=='o')
			{
					ctrl=2;
					break;
			}
		}
		for(int row=0;row<3 && ctrl==0;row++)
		{
			if(a[row][0]=='x' && a[row][1]=='x' && a[row][2]=='x')
			{
				ctrl=1;
				break;
			}
			if(a[row][0]=='o' && a[row][1]=='o' && a[row][2]=='o')
			{
				ctrl=2;
				break;
			}
		}
		if(ctrl==0)
		{
			if((a[0][0]=='x'&&a[1][1]=='x'&&a[2][2]=='x'&& ctrl==0)||(a[0][2]=='x'&&a[1][1]=='x'&&a[2][0]=='x'&&ctrl==0))
			{
				ctrl=1;
				return;
			}
			if((a[0][0]=='o'&&a[1][1]=='o'&&a[2][2]=='o'&&ctrl==0)||(a[0][2]=='o'&&a[1][1]=='o'&&a[2][0]=='o'&&ctrl==0))
			{
				ctrl=2;
				return;
			}
		}
		for(int l=0;l<3;l++)
		{	
			for(int j=0;j<3;j++)
			{
				if(a[l][j]!='_')
					s++;
			}
		}
		if(s>=9)
			ctrl=-1;		
	}	
}
void chck(char a[3][3],int & r,int & c)
{
	while(a[r][c]!='_'|| r>=3 || c>=3)
	{
		cout<<"\ninput again: ";
		cin>>r>>c;
				
	}
}

int main()
{
	welcome();
	char a[3][3];
	for(int q=0;q<3;q++)
		for(int w=0;w<3;w++)
			a[q][w]='_';//={('n','n','n'),('n','n','n'),('n','n','n')};
	char name1[20],name2[20];
	cout<<"Enter the players name:"<<endl;
	gets(name1);
	gets(name2);
	int n;
	cout<<"How many times do u wanna play: ";
	cin>>n;
	int tally1=0,tally2=0;
	for(int i=1;i<=n;i++)
	{
		int ctrl=0;
		for(int x=0;x<9&& ctrl==0;x++)
		{
		 	int r1,r2,c1,c2;
			cout<<"\n Player 1: input x in any row and col.\n";
	 		cin>>r1>>c1;
			chck(a,r1,c1);
			a[r1][c1]='x';
	 		for(int r=0;r<3;r++)
			{
			 	for(int c=0;c<3;c++)
		 		{
					cout<<a[r][c]<<" ";
				}
				cout<<endl;
			}
		 	win(a, ctrl);
		 	if((ctrl==-1)||(ctrl==1)||(ctrl==2))
		 		break;
		 	cout<<ctrl;
		 	cout<<"\n Player 2: input o in any row and col.\n";
			cin>>r2>>c2;
	 		chck(a,r2,c2);
	 		a[r2][c2]='o';
	 		for(int r=0;r<3;r++)
			{
			 	for(int c=0;c<3;c++)
		 		{
					cout<<a[r][c]<<" ";
				}
				cout<<endl;
			}
		 	win(a, ctrl);
		 	if((ctrl==-1)||(ctrl==1)||(ctrl==2))
		 		break;
		 	cout<<ctrl;
		}
		if(ctrl==1)
			tally1++;
		if(ctrl==2)
			tally2++;
		else
		{
			tally1++;tally2++;
		}
	}
	if(tally1>tally2)
		cout<<"\nPlayer 1 won. Congratulations "<<name1<<endl;
	else
		if(tally2>tally1)
			cout<<"\nPlayer 2 won. Congratulations "<<name2<<endl;
		else
			cout<<"\nNOBODY WON> IT'S A DRAW."<<endl;
	cout<<"\nTHANK YOU FOR PLAYING. PLEASE COME AGAIN LATER. LEAVE A RATING FOR US IN THE PLAYSTORE.\n GOODBYE.\n";
	return 0;
}
