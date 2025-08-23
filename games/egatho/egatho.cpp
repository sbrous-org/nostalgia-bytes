#include<iostream>
#include<windows.h>
#include<string>
#include<conio.h>
#include<time.h>
#include<fstream>
using namespace std;
int c=15,r=20,c_b,SPACE=0,LIFE,SCORE,COUNT=0;
bool key=false;
void gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void delays(int k)
{
	for(int i=0;i<=k*k*100;i++);
}
void load()
		{
			int cn=35,t=1;
			system("cls");	
			int x=30;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			gotoxy(30,10);	cout<<"L O A D I N G";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			gotoxy(27,11);	cout<<"feel free to wait...";
			for(int i=1;i<=100;i++)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);	
				delays(500);
				gotoxy(cn,13);	cout<<i<<" %";
			}		
			while(t)
			{
				delays(1000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				gotoxy(35,15);	cout<<"READY";
				gotoxy(27,16);	cout<<"Press Enter to Start";
				if(GetAsyncKeyState(VK_RETURN))
					t=0;
			}
		}
class DESIGN
{
	int i,d;
	public:
		
		void des(int x,int y)
		{
			delays(d);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			gotoxy(x,y);	cout<<"o";
		}
		void entry_design(int q)
		{
			d=q;			
			for(i=2;i<=10;i++)
				des(2,i);
			for(i=2;i<=8;i++)
				des(i,2);
			for(i=2;i<=6;i++)
				des(i,6);
			for(i=2;i<=8;i++)
				des(i,10);
				
			for(i=17;i>=11;i--)
				des(i,2);
			for(i=2;i<=10;i++)
				des(11,i);
			for(i=11;i<=17;i++)
				des(i,10);
			for(i=10;i>=6;i--)
				des(17,i);
			for(i=17;i>=14;i--)
				des(i,6);
				
			for(i=10;i>=2;i--)
				des(20,i);	
			for(i=20;i<=26;i++)
				des(i,2);
			for(i=2;i<=10;i++)
				des(26,i);
			for(i=20;i<=26;i++)
				des(i,6);
			
			for(i=29;i<=35;i++)
				des(i,2);
			for(i=2;i<=10;i++)
				des(32,i);
				
			for(i=2;i<=10;i++)
				des(38,i);
			for(i=2;i<=10;i++)
				des(44,i);
			for(i=38;i<=44;i++)
				des(i,6);
				
			for(i=53;i>=47;i--)
				des(i,2);	
			for(i=2;i<=10;i++)
				des(47,i);	
			for(i=47;i<=53;i++)
				des(i,10);	
			for(i=10;i>=2;i--)
				des(53,i);
		}
};
// frame of the game
class FRAME
{
	int i;
	public:
		FRAME()
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
			for(i=4;i<=30;i++)
			{
				gotoxy(i,21);	cout<<"X";
				gotoxy(i,2);	cout<<"X";
			}
			for(i=2;i<=21;i++)
			{
				gotoxy(4,i);	cout<<"X";
				gotoxy(30,i);	cout<<"X";
			}
		}
};
class SCORES
{
	int i;
	public:
		int c,r;
		void display_life()
		{	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			gotoxy(12,22);	cout<<"EGGS";
			gotoxy(12,23);	cout<<"LEFT";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			gotoxy(11,25);	cout<<"SPACE = JUMP";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			for(i=1;i<=8;i++)
			{
				if(i==1)
				{
					c=19,r=22;
				}
				if(i==5)
				{
					c=19,r=23;
				}
				if(i<=LIFE)	
				{
					gotoxy(c++,r);	cout<<"o";
				}
				else	
				{
					gotoxy(c++,r);	cout<<" ";
				}
			}
		}
		void display_score()
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			gotoxy(14,1);	cout<<"SCORE: "<<SCORE;
		}
		
};
//class to control the busket movement
class BUSKET
{
	
	public:
	int cc,rr,i;
	void get(int p,int q)
	{
		i=1;
		cc=c+p;			// is c and r required?
		rr=r-q;
	}
	void frame()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(cc,rr);
		cout<<"\\___/";
	}
	void show_busket()
	{
		if(rr>=4&&rr<=20)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(cc,rr);	cout<<"\\___/";
		}
	}
	void move_busket()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(cc,rr);	cout<<"     ";
		gotoxy(cc+2,rr-1);	cout<<" ";
		if(cc==25)
			i=-1;
		else if(cc==5)
			i=1;
		cc=cc+1*(i);
		gotoxy(cc,rr);	cout<<"\\___/";
	}
	void new_column()
	{
		srand(time(NULL));
		cc=rand()%20+5;
		rr=4;
	}
	void rub_busket()
	{
		if(rr>=4&&rr<=20)
		{
			gotoxy(cc,rr);	cout<<"     ";
		}
	}
	void operator =(BUSKET BT)
	{							// to copy the column value of above busket to the below				
		cc=BT.cc;
		rr=BT.rr;	
		i=BT.i;	
	}
	void re_initialize()
	{
		if(rr>20)	
		{
			rr=-3;
			cc=rand()%20+5;
		}
	}
		
};
//calss egg to perform the eg moement
class EGG
{
	int x,y;
	public:
		void frame(BUSKET BW)
		{
			x=BW.cc+2;
			y=BW.rr;
			gotoxy(x,y-1);	cout<<"o";		
		}
		void move_along_busket(BUSKET &b)
		{	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			x=b.cc+2;
			y=b.rr;
			gotoxy(x,y-1);	cout<<"o";		
		}
		void move_up(int n)
		{
			if(n>=4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				gotoxy(c_b+2,n);	cout<<" ";
				gotoxy(c_b+2,n-1);	cout<<"o";
			}
			
		}
		void move_down(int n)
		{
			if(n<21)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				gotoxy(c_b+2,n);	cout<<"o";
				gotoxy(c_b+2,n-1);	cout<<" ";
			}
		}
		void del_egg(int n)
		{
			gotoxy(c_b+2,n-1);	cout<<" ";
		}
		void again(int &up,int &down,int & i,int &check,int &n)
		{
			gotoxy(c_b+2,n-1);	cout<<" ";
			up=0;
			down=0;
			check=1;
			if(i==2) i=0;
			if(i==0)n=19;
			else n=13;
		}
};

void go_down(BUSKET B[],EGG E,int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	B[2].rub_busket();
	B[2].rr++;
	gotoxy(B[2].cc+2,n+1);
	cout<<"o";
	gotoxy(B[2].cc+2,n);
	cout<<" ";
	B[2].re_initialize();
	B[2].show_busket();
	B[1].rub_busket();
	B[1].rr++;
	B[1].re_initialize();
	B[1].show_busket();
	B[0].rub_busket();
	B[0].rr++;
	B[0].re_initialize();
	B[0].show_busket();
				
}
void swap_busket(BUSKET *B)
{
	int rv;
	BUSKET TB;
	TB=B[1];
	B[1]=B[0];
	B[0]=B[2];
	B[2]=TB;
	B[1].i=1;
	B[2].i=1;
	if(COUNT%3==0)
	{
		rv=rand()%2+1;
		if(rv==1)	B[1].i=0;
		else		B[2].i=0;
	}
	COUNT++;
}
void play()
{
	system("cls");
	FRAME F;
	BUSKET *B;
	B=new BUSKET[3];
	B[0].get(0,0);B[1].get(5,8);B[2].get(10,16);	
	EGG E;
	SCORES S;
	int h[2]={13,5},rz=4,aa=1;
	int n=19,e_ctr_up=0,e_ctr_down=0,i=0,check_egg=1,jugar=0;   
	for(int k=0;k<3;k++)
	B[k].frame();
	E.frame(B[i]);
	while(1)
	{
		delays(600);
		S.display_life();
		S.display_score();
		for(int k=0;k<3;k++)
		B[k].move_busket();
		
		if(e_ctr_up==0 && check_egg==1)
			if(GetAsyncKeyState(VK_SPACE))
			{	if(!key)
				{
					int k;
					e_ctr_up=1;
					check_egg=0;
					c_b=B[i].cc;
					SPACE++;
					key=true;
				}
			}
			else
			{
				key=false;
			}
		if(e_ctr_up==1 && jugar==0)
		{
			
			if(n>h[i]-1)
			{
				n--;
				E.move_up(n);
			}
			else
			{
				E.del_egg(n);
				n++;
				E.move_down(n);
				jugar=1;
			}
		}
		
		if(e_ctr_down==1)
		{
			if(n<21)n++;
			E.move_down(n);
			if(n==21)
			{
				if(LIFE==0)
				throw(1);
				E.again(e_ctr_up,e_ctr_down,i,check_egg,n);
				
			}
		}
		if(check_egg==1)
		{
			E.move_along_busket(B[i]);
			
		}	
		if(n==h[i] && jugar==1)
		{
			e_ctr_up=0;
			jugar=0;
			if(c_b>(B[i+1].cc-1) && c_b<(B[i+1].cc+5))
			{
				E.del_egg(n+1);
				i++;
				cout<<'\a';	
				check_egg=1;
				SCORE++;	
			}
			else
			{	
				E.del_egg(n);
				e_ctr_down=1; 
				check_egg=0;
				LIFE--;
			}
			
		}
		if(i==2&&check_egg==1)
		{	
			E.del_egg(n);
			while(rz!=20)
			{
				delays(800);
				go_down(B,E,rz-1);
				rz++;
			}
			swap_busket(B);
			i=0;
			E.again(e_ctr_up,e_ctr_down,i,check_egg,n);
			rz=4;
		}
	}
}


// score class
class SCORE_FILE
{
	public:
	void add_score()
	{
		int ch=0;
		fstream f;
		f.open("PING.DAT",ios::in|ios::binary);
		while(f)
		{
			f>>ch;
		}
		if(ch<SCORE)
		ch=SCORE;
		f.close();
		f.open("PING.DAT",ios::out|ios::binary);
		f<<ch;
		f.close();
	}
	int disp_h_score()
	{
		int r_score=0;
		ifstream fin;
		fin.open("PING.DAT",ios::in|ios::binary);
		while(fin)
		{
			fin>>r_score;
		}
		fin.close();
		return r_score;
	}

	
}file;


// menu class
class MENU
{
public:
 int pointer=0;
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
		while(1)
		{
			delays(800);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			gotoxy(5,10);
			cout<<"Get your Eggs as high as you can.";
			gotoxy(5,11);
			cout<<"USE the SPACE bar to jump across Buskets.";
			gotoxy(5,12);
			cout<<"You have 8 eggs with you. Lets see how high";
			gotoxy(5,13);
			cout<<"you can take your Eggs. GOOD LUCK!!";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			gotoxy(5,16);
			cout<<"Press Escape to go back to Menu...";
			if(GetAsyncKeyState(VK_ESCAPE))
				break;
		}
	}
	void developers()
	{
		int t1=1;
		system("cls");
 		for(int i=30;i>=2;i--)
		{ 
	  		delays(1000);
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
			gotoxy(28,i-1);
			cout<<"EGATHO";
  			gotoxy(26,i+1);
  			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
  			cout<<"Developers:";
  			gotoxy(26,i+3);
  			cout<<"The S.Brous";
  			gotoxy(26,i+4);
	  		cout<<"SUDIPTA NATH";
  			gotoxy(26,i+5);
  			cout<<"SUBHOJOY DEY";
		}
		while(t1)
		{
			delays(1000);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			gotoxy(14,14);
			cout<<"Press Escape to go back to Main Menu"; 
			if(GetAsyncKeyState(VK_ESCAPE))
				t1=0;
		}
	}
	void precaution()
{
	if(GetAsyncKeyState(VK_RETURN))
			{
				pointer=-2;
			}	
}
void entry_menu()
{
	DESIGN D;
	int z=1,rw=18,kh=2,rr1=18;
	char choice,kbh;
	int xy=0;		// new
	D.entry_design(350);
	do
	{	precaution();
		D.entry_design(0);
		if(xy==1)
		{
			system("cls");
			xy++;
		}
		delays(1000);
		string Menu[5]={" START"," How To"," Best Score"," Creators"," Quit"};
		for(int m=0;m<5;m++)
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
			if(pointer>4)
				pointer=0;
		}
		else if(GetAsyncKeyState(VK_UP)!=0)
		{
			pointer--;
			cout<<'\a';			
			if(pointer<0)
				pointer=4;
		}
		else if(GetAsyncKeyState(VK_ESCAPE))
		{
			char ch11;int b=1;
			system("cls");
			while(b)
			{
				delays(1000);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				gotoxy(26,14);	cout<<"EXIT?";
				gotoxy(20,16);	cout<<"Are you Sure(Y/N)";
				if(kbhit())
				{
					ch11=getch();
					if(ch11==89||ch11==121)
						{	
							Beep(535,500);
							exit(0);
						}
					else if(ch11==78||ch11==110)
					{
						b=0;xy=1;
					}
				}
			}
		}
		else if(GetAsyncKeyState(VK_RETURN))
		{	
			kh++;
			int t1=1;
			if(pointer==0)
			{	
				Beep(100,500);
				load();
				if(GetAsyncKeyState(VK_SPACE))
					key=true;
				xy=1;SCORE=0;LIFE=8;
				try
				{
					play();
				}
				catch(int n)
				{
					file.add_score();
					system("cls");
					gotoxy(10,10);
					cout<<"YOUR SCORE="<<SCORE;
					gotoxy(10,12);
					cout<<"BEST SCORE="<<file.disp_h_score();
					SCORE=0;
				}
				while(t1)
				{
					delays(1000);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
					gotoxy(10,14);
					cout<<"Press Escape to go back to Main Menu"; 
					if(GetAsyncKeyState(VK_ESCAPE))
						t1=0;
				}
				if(GetAsyncKeyState(VK_RETURN))
				{
					pointer=-2;
				}
			}
			else if(pointer==1)
			{	
				Beep(200,500);
				instruction();
				if(GetAsyncKeyState(VK_RETURN))
				{
					pointer=-2;
				}
				xy=1;
			}
			else if(pointer==2)
			{	
				Beep(200,500);
				int t1=1;
				system("cls");
				gotoxy(26,8);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				cout<<"E G A T H O";
				gotoxy(20,10);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				cout<<"B E S T  S C O R E = "<<file.disp_h_score();
				xy=1;
				while(t1)
				{
					delays(1000);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
					gotoxy(14,14);
					cout<<"Press Escape to go back to Main Menu"; 
					if(GetAsyncKeyState(VK_ESCAPE))
						t1=0;
				}
				if(GetAsyncKeyState(VK_RETURN))
				{
					pointer=-2;
				}
			}
			else if(pointer==3)
			{
				Beep(200,500);
				developers();
					if(GetAsyncKeyState(VK_RETURN))
				{
					pointer=-2;
				}
				xy=1;
			}
			else if(pointer==4)
			{
				system("cls");
				Beep(534,500);
				exit(0);
			}
			pointer=0;	
		}
	
	}while(z);
}	
};
//main function
main()
{
	MENU M;
	M.entry_menu();
}
