#include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<fstream>
using namespace std;
void frame();
void obstacle();
void bonus(int bj);
int disp_h_score();
void add_score();

int cc=13,rr=15,SCORE=0,l1=33,l2=33+14,K,BX,b_count=38,b_erase=0,r_menu,xy;
char name[15];

void gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void delays(int k)
{
	for(int i=0;i<=k*k*100;i++);
}
void del(int c,int r)
{
	gotoxy(c,r);
	cout<<" ";
}
void play(int a,int b,int j)
{ 
		if(GetAsyncKeyState(VK_UP))
		{
			del(cc,rr);
			rr--;
			gotoxy(cc,rr);
			cout<<"&";	
		}
		else
		{
			del(cc,rr);
			rr++;
			gotoxy(cc,rr);
			cout<<"&";	
		}
		if(rr==5||rr==25)
		{	
			Beep(523,500);
		/*	system("cls");
			gotoxy(10,10);
			cout<<"YOUR SCORE="<<SCORE;
			gotoxy(10,12);
			cout<<"HIGHSCORE="<<disp_h_score();
			SCORE=0,cc=13,rr=15;				//NEW
			for(int i=3;i>0;i--)
			{
				gotoxy(10,14);
				cout<<"Going to menu in "<<i<<" seconds"; 
				Beep(500,1000);
			}*/
			add_score();
			r_menu=0;
		}
		if(j==13)
		{
			if(rr<=a||rr>=b)
			{
				Beep(523,500);
		/*			system("cls");
			gotoxy(10,10);
			cout<<"YOUR SCORE="<<SCORE;
			gotoxy(10,12);
			cout<<"HIGHSCORE="<<disp_h_score();
			SCORE=0,cc=13,rr=15;				//NEW
			for(int i=3;i>0;i--)
			{
				gotoxy(10,14);
				cout<<"Going to menu in "<<i<<" seconds"; 
				Beep(500,1000);
			}*/
				add_score();
				r_menu=0;
				 
			}
			else
			{
				SCORE++;
				cout<<'\a';
			//	add_score();
			}
		}
}
void frame()
{
	int i;
	for(i=11;i<34;i++)
	{gotoxy(i,5);	cout<<"-";}
	for(i=11;i<34;i++)
	{gotoxy(i,25);	cout<<"-";}
	for(i=6;i<25;i++)
	{gotoxy(10,i);	cout<<"|";}
	for(i=6;i<25;i++)
	{gotoxy(34,i);	cout<<"|";}
}
void obstacle_line(int j,int x)
{
	int i;
		for(i=6;i<=6+x;i++)
		{gotoxy(j-1,i);cout<<"|";}
		for(i=6;i<=6+x;i++)
		del(j,i);
		
		for(i=10+x;i<=24;i++)
		{gotoxy(j-1,i);cout<<"|";}
		for(i=10+x;i<=24;i++)
		del(j,i);

}
void bonus(int bj)
{
	gotoxy(bj-1,BX);
	cout<<"*";
	del(bj,BX);
}
void obstacle(int &x1)
{
	gotoxy(19,3);		cout<<"SCORE:::"<<SCORE;
	int x2,j;
	j=l1;						
	x2=rand()%13+1;
	while(j>=11 && r_menu==1)				
	{	
		K=x1;
		delays(700);
		play(6+K,10+K,l1);
		obstacle_line(l1,x1);
		if(l2<=33)
		{
			obstacle_line(l2,x2);
		}
		
		if((b_count)<33 && b_count!=j && b_erase==0 && b_count!=j-1)
		{	bonus(b_count);}					//b_c for bonus count
		
		if(b_count==13)
		{
			if(rr==BX || rr==BX-1 || rr==BX+1)
			{
				del(12,BX); 
				SCORE+=10;
			//	add_score();
				gotoxy(19,3);		cout<<"SCORE:::"<<SCORE;
				cout<<'\a';
				b_erase=1;
			}
		}
		
		if(b_count==10)
		{
			del(b_count-1,BX);
			gotoxy(b_count,BX);
			cout<<"|";
			b_count=38;
			BX=rand()%12+8;
			b_erase=0;					//range of bonus
		}
		
		
		if(l1<=13) K=x2;
		if(l1==11)
		{
			l1=l2;
			l2=l1+14;
			x1=x2;
		}
		l1--;
		l2--;
		j--;
		b_count--;					
	}
		
}
void add_score()
{
	int ch=0;
	fstream f;
	f.open("AS.DAT",ios::in|ios::binary);
	while(f)
	{
		f>>ch;
	}
	if(ch<SCORE)
	ch=SCORE;
	f.close();
	f.open("AS.DAT",ios::out|ios::binary);
	f<<ch;
	f.close();
}
int disp_h_score()
{
	int r_score=0;
	ifstream fin;
	fin.open("AS.DAT",ios::in|ios::binary);
	while(fin)
	{
		fin>>r_score;
	}
	fin.close();
	return r_score;
}

void print_inst(char ch[],int c,int r,int d=300)
{
	gotoxy(c,r);
	for(int i=0;ch[i]!='\0';i++)
		{
			delays(d);
			cout<<ch[i];
		}
}
void instruction()
{		system("cls");
		int v;
		char str1[40],str2[40],str3[40],str4[40],str5[40],str6[40],str7[40];
		strcpy(str1,"Help your bird to get past the obstacles");
		strcpy(str2,"by juming using the UP ARROW.");
		strcpy(str3,"Collect the bonuses(*) and boost your");
		strcpy(str4,"score. Make sure you dont get your bird");
		strcpy(str5,"killed in the process of collecting");
		strcpy(str6,"bonuses. Lets see if your Bird is Broppy");
		strcpy(str7,"enough to survive the mission...");
		print_inst(str1,5,10);
		print_inst(str2,5,11);
		print_inst(str3,5,12);
		print_inst(str4,5,13);
		print_inst(str5,5,14);
		print_inst(str6,5,15);
		print_inst(str7,5,16);
		for(int i=3;i>0;i--)
			{
				gotoxy(10,18);
				cout<<"Going to menu in "<<i<<" seconds"; 
				Beep(500,1000);
			}
}
void entry_design(int d)
{	int i,x=6,m=2;
	for(i=2;i<=10;i++)
	{	delays(d);	gotoxy(2,i);	cout<<"*";}
	for(i=2;i<=8;i++)
	{	delays(d);	gotoxy(i,6);	cout<<"*";}
	for(i=6;i<=10;i++)
	{	delays(d);	gotoxy(8,i);	cout<<"*";}
	for(i=8;i>=2;i--)
	{	delays(d);	gotoxy(i,10);	cout<<"*";}
	//cout<<'\a';
	
	for(i=10;i>=2;i--)
	{	delays(d);	gotoxy(11,i);	cout<<"*";}
	for(i=11;i<=17;i++)
	{	delays(d);	gotoxy(i,2);	cout<<"*";}
	for(i=2;i<=6;i++)
	{	delays(d);	gotoxy(17,i);	cout<<"*";}
	for(i=17;i>=11;i--)
	{	delays(d);	gotoxy(i,6);	cout<<"*";}
	for(i=11;i<=17;i=i=i+2)
	{	delays(d);	gotoxy(i,x++);	cout<<"*";}
	//cout<<'\a';
	
	for(i=26;i>=20;i--)
	{	delays(d);	gotoxy(i,2);	cout<<"*";}
	for(i=2;i<=10;i++)
	{	delays(d);	gotoxy(20,i);	cout<<"*";}
	for(i=20;i<=26;i++)
	{	delays(d);	gotoxy(i,10);	cout<<"*";}
	for(i=10;i>=2;i--)
	{	delays(d);	gotoxy(26,i);	cout<<"*";}	
	//cout<<'\a';
	
	for(i=10;i>=2;i--)
	{	delays(d);	gotoxy(29,i);	cout<<"*";}
	for(i=29;i<=35;i++)
	{	delays(d);	gotoxy(i,2);	cout<<"*";}
	for(i=2;i<=6;i++)
	{	delays(d);	gotoxy(35,i);	cout<<"*";}
	for(i=35;i>=29;i--)
	{	delays(d);	gotoxy(i,6);	cout<<"*";}
	//cout<<'\a';
	
	for(i=10;i>=2;i--)
	{	delays(d);	gotoxy(38,i);	cout<<"*";}
	for(i=38;i<=44;i++)
	{	delays(d);	gotoxy(i,2);	cout<<"*";}
	for(i=2;i<=6;i++)
	{	delays(d);	gotoxy(44,i);	cout<<"*";}
	for(i=44;i>=38;i--)
	{	delays(d);	gotoxy(i,6);	cout<<"*";}
	//cout<<'\a';
	
	for(i=47;i<=53;i=i=i+2)
	{	delays(d+100);	gotoxy(i,m++);	cout<<"*";}
	m--;
	for(i=53;i<=59;i=i=i+2)
	{	delays(d+100);	gotoxy(i,m--);	cout<<"*";}
	for(i=6;i<=10;i++)
	{	delays(d+100);	gotoxy(53,i);	cout<<"*";}
	//cout<<'\a';
}
void developers()
{
	system("cls");
 	for(int i=30;i>=2;i--)
	{ 
	  	delays(800);
		system("cls");
		gotoxy(20,i-1);
		cout<<"Broppy Birds";
  		gotoxy(20,i+1);
  		cout<<"Developers:";
  		gotoxy(20,i+2);
  		cout<<"The S.Brous";
  		gotoxy(20,i+3);
  		cout<<"Sudipta Nath";
  		gotoxy(20,i+4);
  		cout<<"Subhojoy Dey";
	}
	xy=1;
}
void entry_menu()
{
	int z=1,rw=18;
	xy=1;
	do
	{	if(xy==1)
		{
			system("cls");
			xy++;
			entry_design(0);
		}
		delays(1000);
		gotoxy(19,rw);
		cout<<"*";
		gotoxy(20,18);
		cout<<" PLAY";
		gotoxy(20,19);
		cout<<" Instructions";
		gotoxy(20,20);
		cout<<" High Score";
		gotoxy(20,21);
		cout<<" Developers";
		gotoxy(20,22);
		cout<<" Exit";
	
		if(GetAsyncKeyState(VK_DOWN))
		{
			del(19,rw);
			rw++;
			cout<<'\a'; 			// new
			if(rw>22)
				rw=18;
		}
		else if(GetAsyncKeyState(VK_UP))
		{
			del(19,rw);
			rw--;
			cout<<'\a';				// new
			if(rw<18)
				rw=22;
		}
		else if(GetAsyncKeyState(VK_RETURN))
		{	
			Beep(534,500);			// new
			if(rw==18)
			{	
				xy=1;
				system("cls");
				gotoxy(10,10);	cout<<"Press the Space Bar to Start";
				getch();
				//Beep(500,2000);
				delays(2000);
				system("cls");
				frame();
				srand(time(NULL));
				int x1=rand()%13+1;
				BX=rand()%12+8;				
				r_menu=1;
				getch();
				while(r_menu)
				{
					obstacle(x1);
				}
				
				system("cls");
				gotoxy(10,10);
				cout<<"YOUR SCORE="<<SCORE;
				gotoxy(10,12);
				cout<<"HIGHSCORE="<<disp_h_score();
				SCORE=0,cc=13,rr=15;				//NEW
				for(int i=3;i>0;i--)
				{
					gotoxy(10,14);
					cout<<"Going to menu in "<<i<<" seconds"; 
					Beep(500,1000);
				}
					l1=33; l2=33+14;
			}
			else if(rw==19)
			{
				instruction();
				xy=1;
			}
			else if(rw==20)
				{
					system("cls");
					gotoxy(10,10);
					cout<<"H I G H S C O R E = "<<disp_h_score();
					xy=1;
					for(int i=3;i>0;i--)
					{
						gotoxy(10,14);
						cout<<"Going to menu in "<<i<<" seconds"; 
						Beep(500,1000);
					}
				}
			else if(rw==21)
			{
				developers();
			}
			else if(rw==22)
			{
				system("cls");
				exit(0);
			}
		}
	}while(z);
}
	

int main()
{
	
	entry_design(200); 
	entry_menu();
}

