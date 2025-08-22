 #include<iostream>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<fstream>
void gotoxy(short,short);
int sc=20,rc=13,shc=0;
using namespace std;
class HScore
{
   public:
   char gmode[10],glevel[10];
   int points;
   void pt(const char *n, int p, const char *l)
   	{
   		strcpy(gmode,n);
   		points=p;
   		strcpy(glevel,l);
	}
	void reset(const char *str, const char *l)
	{
		strcpy(gmode,str);
		points=0;
		strcpy(glevel,l);
	}
   void show()
   {
   		if(shc<3)
   		{	
   			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(12,rc++);
			cout<<glevel;
			gotoxy(sc,12);
			cout<<gmode;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			gotoxy(sc+2,rc-1);
			cout<<points;
   			shc++;
   		}
   		else
   		{	
   			sc=30,rc=13;
   			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(sc,12);
			cout<<gmode;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			gotoxy(sc+2,rc++);
			cout<<points;
   		}
   	}
}; 

void frame();
void pause(int);
void precaution();
void food_generate();
void del_poison();
void food_check();
void poison_generate();
void poison_check();
void display_HS();
void add_HS(int);
void init_HS();


int a[100][2],size,xy,mode=1,food[2],nof,gm,poison[2],pointer,point=1,pointer1=0,poison_strt,food_chk,poison_chk,SCORE=0;	//size = length of snake
void gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void delays(int k)
{
	for(int i=0;i<=k*k*100;i++);
}
void del(int y=a[size][0],int x=a[size][1])
{	
	gotoxy(y,x);
	cout<<" ";
}
void des(int c,int r)
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	delays(400);
	gotoxy(c,r);	cout<<"o";
}

void entry_des()
{
	int i,x=6,y=13;
	for(i=8;i>=2;i--)
		des(i,2);
	for(i=2;i<=6;i++)
		des(2,i);
	for(i=2;i<=8;i++)
		des(i,6);
	for(i=6;i<=10;i++)
		des(8,i);
	for(i=8;i>=2;i--)
		des(i,10);
//--------------------------------------
//------------------------------------
	for(i=2;i<=10;i++)
		des(11,i);
	for(i=11;i<=17;i++)
		des(i,2);
	for(i=11;i<=15;i++)
		des(i,6);
	for(i=11;i<=17;i++)
		des(i,10);
		//--------------------
		//---------------
	for(i=10;i>=2;i--)
		des(20,i);	
	for(i=20;i<=28;i++)
		des(i,2);
	for(i=2;i<=6;i++)
		des(28,i);
	for(i=28;i>=20;i--)
		des(i,6);	
	for(i=20;i<=28;i=i=i+2)
		des(i,x++);	
		
	for(i=10;i>=2;i--)
		des(31,i);	
	for(i=31;i<=38;i++)
		des(i,2);
	for(i=2;i<=6;i++)
		des(38,i);
	for(i=38;i>=31;i--)
		des(i,6);
		//----------------------
	for(i=13;i<=21;i++)
		des(2,i);
	for(i=2;i<=8;i++)
		des(i,13);
	for(i=2;i<=6;i++)
		des(i,17);
	for(i=2;i<=8;i++)
		des(i,21);
	
	for(i=21;i>=13;i--)
		des(11,i);
	for(i=12;i<=19;i++)
		des(i,y++);
	for(i=21;i>=13;i--)
		des(20,i);
		
	for(i=23;i<=29;i++)
		des(i,13);
	for(i=13;i<=21;i++)
		des(26,i);
		
	for(i=13;i<=21;i++)
		des(32,i);
	for(i=32;i<=38;i++)
		des(i,13);
	for(i=32;i<=36;i++)
		des(i,17);
	for(i=32;i<=38;i++)
		des(i,21);
	gotoxy(10,24);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	system("pause");
	precaution();
}


void initialize()	// initializes the x and y coordinatesof the snake
{
	int b[10]={13,13,14,13,15,13,16,13,17,13},k=0;
	SCORE=0,food_chk=0,poison_chk=0,nof=0,size=5;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<2;j++)
		{
			a[i][j]=b[k++];
		}
	}
}
void check()	// checks if the snake hits itself
{
	for(int i=1;i<size;i++)
	{
		if(a[0][0]==a[i][0]&&a[0][1]==a[i][1])
			throw 1;
	}
	food_check();
	if(poison_chk==1)
		poison_check();
}
void show()			//	shows the snake
{	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	gotoxy(10,2);
	if(mode==0)	
		cout<<"GAME MODE = EASY   ";
	else if(mode==1)
		cout<<"GAME MODE = MEDIUM";
	else
		cout<<"GAME MODE= HARD   ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	gotoxy(6,24);	cout<<"* = FOOD";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
	gotoxy(24,24);	cout<<"# = POISON";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(16,4);
	cout<<"SCORE : "<<SCORE;
	frame();
	int i;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	gotoxy(a[0][0],a[0][1]);
	cout<<"o";
	for(i=1;i<size;i++)
	{	
		gotoxy(a[i][0],a[i][1]);
		cout<<"o";
	}
}

void food_generate()
{	
	int flag=0;
	food[1]=rand()%14+6;
	food[0]=rand()%29+6;
	for(int i=1;i<size;i++)
	{
		if(food[0]==a[i][0]&&food[1]==a[i][1])
			flag=1;	
	}
	if(flag==0)
	{
		nof++;				// counter of number of food eaten
		if(nof%5==0)
			poison_strt=1;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		gotoxy(food[0],food[1]);
		cout<<"*";
		food_chk=1;
	}
	else
	food_generate();
}
void poison_generate()
{
	gotoxy(poison[0],poison[1]);	cout<<" ";
	int flag=0;
	poison[1]=rand()%14+6;
	poison[0]=rand()%29+6;
	for(int i=1;i<size;i++)
	{
		if(poison[0]==a[i][0]&&poison[1]==a[i][1]||poison[0]==food[0]&&poison[1]==food[1])
			flag=1;	
	}
	if(flag==0)
	{	
		poison_strt=0,poison_chk=1;
		gotoxy(poison[0],poison[1]);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		cout<<"#";
		food_chk=1;
	}
	else
	poison_generate();
}
void food_check()			//checks if food is eaten by snake
{
		if(food[0]==a[0][0]&&food[1]==a[0][1]||food[0]==poison[0]&&food[1]==poison[1])
			{
				SCORE++;
				size++;
				cout<<'\a';
				food_generate();
			}
}
void poison_check()			//checks if poison is eaten by snake
{
	if(poison[0]==a[0][0]&&poison[1]==a[0][1])
	{
		del(a[size][0],a[size][1]);
		del(a[size-1][0],a[size-1][1]);
		SCORE--;
		size-=2;
		cout<<'\a';
		poison_strt=0;	//variable to start poison	
		poison_chk=0;	//variable to enable poison checking
	}
}
void pos_switch()				// swtches snake position
{	
	for(int i=size;i>0;i--)
	{
		a[i][0]=a[i-1][0];
		a[i][1]=a[i-1][1];
	}	
}
void game_type()
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(15,10);
	cout<<"SELECT GAME TYPE";
		int rr1=12;
		string gt[2]={" Classic"," Modern"};
	while(1)
	{	
		delays(1000);
		for(int m=0;m<2;m++)
		{
			if(pointer1==m)
			{	
				gotoxy(18,rr1+m);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				cout<<"o"<<gt[m]<<" ";
			}
			else
			{
				gotoxy(18,rr1+m);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				cout<<"  "<<gt[m];	
			}
		}
		if(GetAsyncKeyState(VK_DOWN))
		{	
			pointer1++;	
			cout<<'\a'; 			
			if(pointer1>1)
				pointer1=0;
		}
		else if(GetAsyncKeyState(VK_UP))
		{
			pointer1--;		
			cout<<'\a';			
			if(pointer1<0)
				pointer1=1;
		}
		else if(GetAsyncKeyState(VK_RETURN))
		{	
			if(pointer1==0)
				gm=0;
			else if(pointer1==1)
				gm=1;
			break;
		}
	}
	pointer1=0;
}
void frame()				//	frame of the game called in show() function
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
	for(int i=5;i<=35;i++)
	{	
		gotoxy(i,5);	cout<<"X";
		gotoxy(i,20);	cout<<"X";
	}
	for(int i=5;i<=20;i++)
	{
		gotoxy(5,i);	cout<<"X";
		gotoxy(35,i);	cout<<"X";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(12,22);
	cout<<"SPACE BAR = PAUSE";
}

void direction_press(char ch)
{	
	int md;
	if(mode==0)
		md=900;
	else if(mode==1)
		md=750;
	else
		md=600;

	int i=1,space=0;
	char c;
	if(food_chk==0)
		food_generate();
	if(poison_strt==1)
		poison_generate();
		
	switch(ch)
	{
		case 72:
			while(1)
			{	
				if(kbhit())
				{
					c=getch();
					if(c==75||c==77)
						direction_press(c);
					else if(c==32)
						pause(ch);
				}
				delays(md);
				pos_switch();
				a[0][1]-=i;
				if(gm==0)
				{
					if(a[0][1]==5)			//this is for circular movement of snake
						a[0][1]=19;
				}
				else
				{
					if(a[0][1]==5)		// for modern game type
						throw 1;
				}
				check();
				show();
				del();
			}
			 
		 case 80:
			while(1)
			{
				if(kbhit())
				{
					c=getch();
					if(c==75||c==77)
						direction_press(c);
					else if(c==32)
						pause(ch);
				}
				delays(md);
				pos_switch();
				a[0][1]+=i;
				if(gm==0)
				{	if(a[0][1]==20)		//this is for circular movement of snake
						a[0][1]=6;
				}
				else
				{
					if(a[0][1]==20)		// for modern game type
						throw 1;
				}
				check();
				show();
				del();
			}
				 
		case 75:
			while(1)
			{
				if(kbhit())
				{
					c=getch();
					if(c==72||c==80)
						direction_press(c);
					else if(c==32)
						pause(ch);
				}
				delays(md);
				pos_switch();
				a[0][0]-=i;
				if(gm==0)
				{
					if(a[0][0]==5)		//this is for circular movement of snake
						a[0][0]=34;
				}
				else
				{
					if(a[0][0]==5)		// for modern game type
						throw 1;
				}
				check();
				show();
				del();
			}
		 
		case 77:
			while(1)
			{
				if(kbhit())
				{
					c=getch();
					if(c==72||c==80)
						direction_press(c);
					else if(c==32)
						pause(ch);
				}
				delays(md);
				pos_switch();
				a[0][0]+=i;
				if(gm==0)
				{
					if(a[0][0]==35)			//this is for circular movement of snake
						a[0][0]=6;
				}
				else
				{
					if(a[0][0]==35)		// for modern game type
						throw;
				}
				check();
				show();
				del();
			}
	}
}

void pause(int c)
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	gotoxy(12,22);
	cout<<"SPACE BAR = START";
	char g;
	while(1)
	{
		if(kbhit)
		{
			g=getch();
			if(g==32)
			direction_press(c);
		}
	}
}

void add_HS()
{
	char str1[10],str2[10];
	strcpy(str1,"CLASSIC");
	strcpy(str2,"MODERN");	
	HScore ob,h_ob[6];
		h_ob[0].reset(str1,"EASY");
		h_ob[1].reset(str1,"MEDIUM");
		h_ob[2].reset(str1,"HARD");
		h_ob[3].reset(str2,"EASY");
		h_ob[4].reset(str2,"MEDIUM");
		h_ob[5].reset(str2,"HARD");
		fstream fin,fout;
	fin.open("serpente.DAT",ios::in|ios::binary);

	while(fin.read((char*)&ob,sizeof(ob)))
	{
		if(strcmpi(ob.gmode,str1)==0)
		{
			
			if(strcmpi(ob.glevel,"EASY")==0)
			{
					h_ob[0].pt(ob.gmode,ob.points,ob.glevel);
			}
			else if(strcmpi(ob.glevel,"MEDIUM")==0)
			{
					h_ob[1].pt(ob.gmode,ob.points,ob.glevel);
			}
			else if(strcmpi(ob.glevel,"HARD")==0)
			{
					h_ob[2].pt(ob.gmode,ob.points,ob.glevel);
			}
		}
		else if(strcmpi(ob.gmode,str2)==0)
		{
			
			if(strcmpi(ob.glevel,"EASY")==0)
			{
					h_ob[3].pt(ob.gmode,ob.points,ob.glevel);
			}
			else if(strcmpi(ob.glevel,"MEDIUM")==0)
			{
					h_ob[4].pt(ob.gmode,ob.points,ob.glevel);
			}
			else if(strcmpi(ob.glevel,"HARD")==0)
			{
					h_ob[5].pt(ob.gmode,ob.points,ob.glevel);
			}
		}
	}
	fin.close();
	if(gm==0)
	{
		if(mode==0)
		{
			if(h_ob[0].points<SCORE)
				h_ob[0].points=SCORE;
		}
		else if(mode==1)
		{
			if(h_ob[1].points<SCORE)
				h_ob[1].points=SCORE;
		}
		else if(mode==2)
		{
			if(h_ob[2].points<SCORE)
				h_ob[2].points=SCORE;
		}
	}
	else if(gm==1)
	{
		if(mode==0)
		{
			if(h_ob[3].points<SCORE)
				h_ob[3].points=SCORE;
		}
		else if(mode==1)
		{
			if(h_ob[4].points<SCORE)
				h_ob[4].points=SCORE;
		}
		else if(mode==2)
		{
			if(h_ob[5].points<SCORE)
				h_ob[5].points=SCORE;
		}
	}
	fout.open("serpente.DAT",ios::out|ios::binary);
	
		fout.write((char*)&h_ob[0],sizeof(h_ob[0]));
		fout.write((char*)&h_ob[1],sizeof(h_ob[1]));
		fout.write((char*)&h_ob[2],sizeof(h_ob[2]));
		fout.write((char*)&h_ob[3],sizeof(h_ob[3]));
		fout.write((char*)&h_ob[4],sizeof(h_ob[4]));
		fout.write((char*)&h_ob[5],sizeof(h_ob[5]));
	
	fout.close();
}  

void display_HS()
{
  ifstream fin;
  fin.open("serpente.DAT",ios::in|ios::binary);
  HScore ob;
  while(fin.read((char*)&ob,sizeof(ob)))
  {
  	ob.show();
  }
  fin.close();
}
int display_iHS()
{
	char str1[10],str2[10];
	if(gm==0) strcpy(str1,"CLASSIC");
	else strcpy(str1,"MODERN");
	if(mode==0)
	strcpy(str2,"EASY");
	else if(mode==1) strcpy(str2,"MEDIUM");
	else strcpy(str2,"HARD");
  ifstream fin;
  fin.open("serpente.DAT",ios::in|ios::binary);
  HScore ob;
  while(fin.read((char*)&ob,sizeof(ob)))
  {
  	if(strcmpi(ob.gmode,str1)==0 && strcmpi(ob.glevel,str2)==0)
  	{
  		fin.close();
  		return ob.points;
  	}
  }
  
}
void init_HS()
{
	SCORE=0;
	for(int i=0;i<2;i++)
	{
		gm=i;
		add_HS();
	}
}




void developers()
{
	system("cls");
 	for(int i=30;i>=2;i--)
	{ 
	  	delays(1000);
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		gotoxy(24,i-1);
		cout<<"S E R P E N T E";
  		gotoxy(26,i+1);
  		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
  		cout<<"Developer:";
  		gotoxy(26,i+3);
  		cout<<"The S.Brous";
  		gotoxy(26,i+4);
  		cout<<"SUDIPTA NATH";
  		gotoxy(26,i+5);
  		cout<<"SUBHOJOY DEY";
	}
	xy=1;
	for(int i=3;i>0;i--)
	{	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		gotoxy(10,14);
		cout<<"Going to menu in "<<i<<" seconds"; 
		Beep(500,1000);
	}
}
void print_inst(char ch[],int c,int r,int d=700)
{
	gotoxy(c,r);
	for(int i=0;ch[i]!='\0';i++)
		{
			delays(d);
			cout<<ch[i];
		}
}
void instruction()
{	
			system("cls");
		int ic=12,ir=0;
		char c12[]={"INSTRUCTIONS"};
		for(int ch=0;c12[ch]!='\0';ch++)
		{	ic+=2;
			for(int i=0;i<=7;i++)
			{
				delays(300);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);	
				gotoxy(ic,i+1);	cout<<c12[ch];
				gotoxy(ic,i);	cout<<" ";
			}
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	
		int v;
		char str1[40],str2[40],str3[40],str4[40],str5[40],str6[40],str7[40],str8[40];
		strcpy(str1,"Your SERPENTE is ready, hungry for days");
		strcpy(str2,"USE the arrows to direct your SERPENTE");
		strcpy(str3,"towards the food item(*). Avoid your");
		strcpy(str4,"SERPENTE to hit itself. You also have");
		strcpy(str5,"poisons(#) which will decrease the size");
		strcpy(str6,"of your SERPENTE and decrease the SCORE");
		strcpy(str7,"by 1. Use your Strategy to create your");
		strcpy(str8,"Highscore and challenge your Friends.");
		print_inst(str1,5,10);
		print_inst(str2,5,11);
		print_inst(str3,5,12);
		print_inst(str4,5,13);
		print_inst(str5,5,14);
		print_inst(str6,5,15);
		print_inst(str7,5,16);
		print_inst(str8,5,17);
		for(int i=3;i>0;i--)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				gotoxy(10,19);
				cout<<"Going to menu in "<<i<<" seconds"; 
				Beep(500,1000);
			}
}
void option_display()
{
	string option[3]={" 1. Easy"," 2. Medium"," 3. Hard"};
	while(1)
	{	
		delays(1000);
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		gotoxy(10,8);	cout<<"SELECT DIFFICULTY";
		gotoxy(10,14);	cout<<"Press the Escape Key to go back to Main Menu";
		for(int i=0;i<3;i++)
		{	
			if(point==i)
			{
				gotoxy(10,10+i);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				cout<<"*"<<option[i]<<" "<<endl;
			}
			else
			{
				gotoxy(10,10+i);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				cout<<"  "<<option[i]<<endl;	
			}
		}
		if(GetAsyncKeyState(VK_DOWN)!=0)
		{	
			point++;
			cout<<'\a'; 			
			if(point>2)
				point=0;
		}
		else if(GetAsyncKeyState(VK_UP)!=0)
		{
			point--;
			cout<<'\a';			
			if(point<0)
				point=2;
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			Beep(523,500);
			break;
		}
		else if(GetAsyncKeyState(VK_RETURN))	
		{	
			Beep(523,500);
			if(point==0)
				mode=0;
			else if(point==1)
				mode=1;
			else
				mode=2;
			break;
		}
	}
}
void precaution()		// this function avoids useful keys which can b pressed
{	
	if(GetAsyncKeyState(VK_RETURN))
		pointer=-2;
	if(GetAsyncKeyState(VK_UP))
		pointer=-1;
	if(GetAsyncKeyState(VK_DOWN))
		pointer=-1;
}
				
void entry_menu()
{
	int z=1,rw=18,kh=2,rr1=9;
	char choice,kbh;
	xy=1,pointer=0;		// new
	do
	{	
		if(xy==1)
		{
			system("cls");
			xy++;
		}
		delays(1000);
		string Menu[6]={" PLAY"," Instructions"," High Score"," Difficulty"," Developers"," Exit"};
		for(int m=0;m<6;m++)
		{
			if(pointer==m)
			{	
				gotoxy(18,rr1+m);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				cout<<"o"<<Menu[m]<<" ";
			}
			else
			{
				gotoxy(18,rr1+m);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				cout<<"  "<<Menu[m];	
			}
		}
		if(GetAsyncKeyState(VK_DOWN)!=0)
		{	
			pointer++;
			cout<<'\a'; 			
			if(pointer>5)
				pointer=0;
		}
		else if(GetAsyncKeyState(VK_UP)!=0)
		{
			pointer--;
			cout<<'\a';			
			if(pointer<0)
				pointer=5;
		}
		else if(GetAsyncKeyState(VK_RETURN))
		{	
			kh++;
			Beep(534,500);
			if(pointer==0)
			{	
				xy=1;
				system("cls");
				game_type();
				initialize();
				gotoxy(25,26);
				system("cls");
				
				if(gm==0)
				{
					gotoxy(18,10);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					cout<<"CLASSIC MODE";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
					gotoxy(19,12);	cout<<"GET READY";
				}
				else
				{
					gotoxy(23,10);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					cout<<"MODERN MODE";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
					gotoxy(17,12);	cout<<"AVOID HITING THE WALLS";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
					gotoxy(24,14);	cout<<"GET READY";
				}
				gotoxy(10,18);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				system("pause");	// user will press any key to start the game
				system("cls");
				try
				{
					direction_press(75);
				}
				catch(int n)
					{
					add_HS();
					system("cls");
					}
					gotoxy(10,10);
					cout<<"YOUR SCORE="<<SCORE;
					gotoxy(10,12);
					cout<<"HIGHSCORE="<<display_iHS();
					for(int i=3;i>0;i--)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
						gotoxy(10,14);
						cout<<"Going to menu in "<<i<<" seconds"; 
						Beep(500,1000);
					}
					precaution();
			}
			else if(pointer==1)
			{
				instruction();
				precaution();
				xy=1;
			}
			else if(pointer==2)
			{
				system("cls");
				int hc=0,hr=0;
				gotoxy(10,10);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					for(int i=0;i<=14;i++)
				{
					delays(400);
					gotoxy(hc+i,10);
					cout<<" H I G H";
				}
				for(int i=0;i<=10;i++)
				{
					delays(400);
					gotoxy(24,hr+i);
					cout<<"S C O R E ";
					gotoxy(24,hr+i-1);
					cout<<"          ";
				}
				Beep(532,500);
				display_HS();
				xy=1;
				shc=0,sc=20,rc=13;
					
				for(int i=5;i>0;i--)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
					gotoxy(10,18);
					cout<<"Going to menu in "<<i<<" seconds"; 
					Beep(500,1000);
				}
				precaution();
			}
			else if(pointer==3)
			{
				option_display();
				xy=1;
				precaution();
			}
			else if(pointer==4)
			{
				developers();
				precaution();
			}
			else if(pointer==5)
			{
				system("cls");
				exit(0);
			}
			pointer=0;
		}
	}while(z);
}
int main()
{	
	srand(time(NULL));
	entry_des();
	init_HS();
	entry_menu();
	getch();
}
