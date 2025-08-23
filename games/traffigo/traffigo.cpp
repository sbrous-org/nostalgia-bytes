#include<iostream>
#include<windows.h>
#include<string>
#include<conio.h>
#include<time.h>
#include<fstream>
class CAR;
class OBST;
class FRAME;
class SPEEDOMETER;
int DELAY=1000,c=0,C_T,T_X,score;
using namespace std;
void gotoxy(short x,short y)
{
	COORD pos={x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
void delays(int k)
{
	for(int i=0;i<=k*k*100;i++);
}
class TRAFFIC
{
	int x,y,colour,cl,check;
	public:
		
		void set_traffic(int a)
		{	
			check=0;
			if(a==1) x=12;
			else if(a==2) x=27;
			else x=42;
			T_X=x;
		}
		void show_traffic()
		{	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			gotoxy(T_X-1,4);
			cout<<"STOP";
		}
	
		void del_traffic()
		{
			gotoxy(T_X-1,4);
			cout<<"    ";	
		}
		int check_traffic()
		{
			check++;
			if(check>10)
			{	
				if(C_T==T_X)
				{
					int s;
					if(DELAY<600) s=1;
					else if(DELAY<800) s=3;
					else s=5;
					score-=s;
				}
				else
				{
					check=0;
					return 0;
				}	
			}
		}	
};
class MENU_DESIGN
{
	int k,p[3],clr,m[3];
	public:
	
	MENU_DESIGN()
	{
		k=0;
		clr=10;
		for(int i=0,j=20;i<3;i++,j+=10)
		p[i]=j;
		m[0]=6;m[1]=8;m[2]=7;
	}
	void move_line(int &p,int n)
	{
		
		for(int i=n;i<n+2;i++)
		{
			if((i+5)!=12)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5+i);
			else
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7+i);
			gotoxy(p,i); cout<<"|";
			gotoxy(p+1,i); cout<<" ";
		}
		if(p==10)
		p=40;
	}
	void traffic_show(int k,int clr)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),clr);
		if(k%2==0)
		for(int i=11;i<40;i+=2)
		{
			gotoxy(i,5); cout<<" ";
			gotoxy(i,10); cout<<" ";
			gotoxy(i-1,5); cout<<"-";
			gotoxy(i-1,10); cout<<"-";
		}
		else
		for(int i=11;i<40;i+=2)
		{
			gotoxy(i,5); cout<<"-";
			gotoxy(i,10); cout<<"-";
			gotoxy(i-1,5); cout<<" ";
			gotoxy(i-1,10); cout<<" ";
		}	
		for(int i=6;i<10;i++)
		{
			gotoxy(10,i); cout<<"|";
			gotoxy(40,i); cout<<"|";
		}
	}
	void perform()
	{
		if(k<=20)
		{
			
			traffic_show(k,clr);
			for(int i=40,j=0;j<3;i+=10,j++)
			if(p[j]<40) move_line(p[j],m[j]);
			for(int j=0;j<3;j++)
				p[j]--;
		}
		else
			{
				clr=12;
				traffic_show(1,clr);
			}
		k++;
		if(k==40)
		{
			k=0;
			clr=10;
		}
	}
};
class OBST
{	
	int x,y;
	public:
	void set(int a)
		{
			if(a==1) x=12;
			else if(a==2) x=27;
			else x=42;
		}
	void move_obst(int k)
	{	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		y=k;
		gotoxy(x-3,y-1);
		cout<<"        ";
		gotoxy(x-3,y);
		cout<<"########";
	}
	void del_obst(int k)
	{
		y=k;
		gotoxy(x-3,y);
		cout<<"        ";	
	}
	int check_collision()
	{
		if(y>=22)
		{
			if(x==C_T)
				throw 1;
			else
			{
				int s;
					if(DELAY<600) s=5;
					else if(DELAY<800) s=3;
					else s=1;
				score+=s;
				return 0;
			}
		}
	}	
};

class FRAME
{	
	int a,b,c,d,x,y,z,count;
	public:
	FRAME()
	{
		a=b=c=d=x=y=z=15;
		count=0;
	}
	void move_frame()
	{
		if(T_X==12)
		{
			a=b=x=12;
			c=d=y=z=10;
		}
		else if(T_X==27)
		{
			c=b=y=12;
			x=z=a=d=10;
		}
		else if(T_X==42)
		{
			a=b=x=y=10;
			c=d=z=12;
		}
		
		int i,j;
		for(i=5;i<=19;i++)
		{	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
			gotoxy(i,5);	cout<<"_";
			gotoxy(i,25);	cout<<"_";
		}
		for(i=20;i<=34;i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),y);
			gotoxy(i,5);	cout<<"_";
			gotoxy(i,25);	cout<<"_";
		}
		for(i=35;i<=50;i++)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),z);
			gotoxy(i,5);	cout<<"_";
			gotoxy(i,25);	cout<<"_";
		}
			count++;
			if(count%2==0)
				for(j=7;j<=25;j=j+2)
				{
					gotoxy(5,j);
					cout<<" ";
					gotoxy(20,j);
					cout<<" ";
					gotoxy(35,j);
					cout<<" ";
					gotoxy(50,j);
					cout<<" ";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
					gotoxy(5,j-1);
					cout<<"|";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),b);
					gotoxy(20,j-1);
					cout<<"|";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
					gotoxy(35,j-1);
					cout<<"|";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),d);
					gotoxy(50,j-1);
					cout<<"|";
				}
			else
			{
				for(j=7;j<=25;j=j+2)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),a);
					gotoxy(5,j);
					cout<<"|";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),b);
					gotoxy(20,j);
					cout<<"|";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
					gotoxy(35,j);
					cout<<"|";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),d);
					gotoxy(50,j);
					cout<<"|";
					gotoxy(5,j-1);
					cout<<" ";
					gotoxy(20,j-1);
					cout<<" ";
					gotoxy(35,j-1);
					cout<<" ";
					gotoxy(50,j-1);
					cout<<" ";
				}
			}
	}
};
class SPEEDOMETER
{
	int i,sc,sr,x;
	public:
		void initialize()
		{
			sc=52,sr=18,x=0;
		}
		void frame_speedo()	// Frame of the speedometer
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
			for(i=10;i<=19;i++)
			{
				gotoxy(51,i);	cout<<"o";
				gotoxy(60,i);	cout<<"o";
			}
			for(i=51;i<=60;i++)
			{
				gotoxy(i,10);	cout<<"o";
				gotoxy(i,19);	cout<<"o";
			}	
		}
		void show_speed()	// shows the speed category(SLOW or Average or Fast)
		{
			if(DELAY>850&&DELAY<=1000)
			{	
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
				gotoxy(53,9);	cout<<"  SLOW    ";
			}
			else if(DELAY>750&&DELAY<=850)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				gotoxy(53,9);	cout<<"AVERAGE";
			}
			else if(DELAY<=750&&DELAY>=680)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
				gotoxy(53,9);	cout<<"  FAST    ";
			}
		}
		void show_graph()	//creating graph of speed increasing when up arrow is pressed
		{
				if(DELAY>850&&DELAY<=1200)	// 1200 is given for precaution, its actually 850-1200
				{	
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
					if(DELAY%50==0)
					{	
						x++;sc++;	sr=18;
						for(i=1;i<=x;i++)
						{
							gotoxy(sc,sr--);	cout<<"|";
						}
					}
				}
				else if(DELAY>700&&DELAY<=850)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
					if(DELAY%50==0)
					{	
						x++;sc++;	sr=18;
						for(i=1;i<=x;i++)
						{
							gotoxy(sc,sr--);	cout<<"|";
						}
					}
				}
				else if(DELAY>550&&DELAY<=700)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					if(DELAY%50==0)
					{	
						x++;	sc++;	sr=18;
						for(i=1;i<=x;i++)
						{
							gotoxy(sc,sr--);	cout<<"|";
						}
					}
			}
		}
		void delete_graph()	//for deleting graph id down arrow is pressed
		{	
				if(DELAY%50==0)
				{
					sr=18;
					for(int i=1;i<=x;i++)
					{
						gotoxy(sc,sr--);	cout<<" ";
					}
					sc--; x--;
				}
		}
};
SPEEDOMETER S;	// GLOBALLY DECLARED
class CAR
{	
int x,y;
public:
	void show_car(int c,int r)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		int k=1;
		for(int i=0;i<3;i++)
		{
			gotoxy(c,r);
			for(int j=1;j<=k;j++)
			{
				cout<<"*";
			}
			k=k+2;
			c--;r++;
		}
		C_T=x;
	}
	void set(int a=42, int b=22)
	{
		x=a;
		y=b;
		show_car(x,y);
	}
	void rub_car(int c,int r)
	{
		int k=1;
		for(int i=0;i<3;i++)
		{
			gotoxy(c,r);
			for(int j=1;j<=k;j++)
			{
				cout<<" ";
			}
			k=k+2;
			c--;r++;
		}
	}
	void switch_car()
	{
		S.frame_speedo();	//new
		if(GetAsyncKeyState(VK_LEFT))
		{	if(x==42||x==27)
				x-=15;
			show_car(x,y);
			rub_car(x+15,y);
			cout<<'\a';
			
		}
		else if(GetAsyncKeyState(VK_RIGHT))
		{	
			if(x==12||x==27)
				x+=15;
			show_car(x,y);
			rub_car(x-15,y);
			cout<<'\a';
		}
		else if(GetAsyncKeyState(VK_UP))
		{
			DELAY-=10;
			if(DELAY<=550)
				DELAY=550;
			S.show_graph();	// new
		}
		else if(GetAsyncKeyState(VK_DOWN))
		{
			DELAY+=10;
			if(DELAY>=1000)
				DELAY=1000;
			S.delete_graph();	//new
		}
		S.show_speed();	//new
	}
	
};
struct DET
{
	int ch;
	char name[10];
};
class SCORE				//everthing related to score will be done here eg. storing the h_score in file
{
	//int ch;
	DET ob;
	public:
		char name[10];
		void show_score()
		{
			gotoxy(23,2);						// i hvnt changed d clr,. if u want, chnge it accrdng to ur choice
			cout<<"SCORE : "<<score;
		}
		void show_hs()
		{
			strcpy(ob.name,"NULL");
			ob.ch=0;
			ifstream fin;
			fin.open("TRAFFIGO.DAT",ios::in|ios::binary);
			while(fin)
			{
				fin.read((char*)&ob,sizeof(ob));
			}
			
			cout<<ob.name<<"\t"<<ob.ch;
			fin.close();
		}
	void add_score()
	{
		ob.ch=0;
		strcpy(ob.name,"NULL");
		fstream f;
		f.open("TRAFFIGO.DAT",ios::in|ios::binary);
		while(f)
		{
			f.read((char*)&ob,sizeof(ob));
		}
		if(ob.ch<score)
		ob.ch=score;
		strcpy(ob.name,name);
		f.close();
		f.open("TRAFFIGO.DAT",ios::out|ios::binary);
			f.write((char*)&ob,sizeof(ob));
		f.close();
	}
	int disp_h_score()
	{
		int r_score=0;
		ifstream fin;
		fin.open("caar.DAT",ios::in|ios::binary);
		while(fin)
		{
			fin.read((char*)&ob,sizeof(ob));
		}
		r_score=ob.ch;
		fin.close();
		return r_score;
	}
	
};
SCORE P;


void check(OBST &O,int &j,int &ctr,int &obx,int obx2)
{
	ctr=O.check_collision();
		if(ctr==0)
		{
			O.del_obst(j);
			j=6;
			ctr=1;
			
			obx=rand()%3+1;
			O.set(obx);	
		}	
}

void play()
{
	DELAY=1000;
	S.initialize();
	FRAME F;
	CAR C;
	TRAFFIC T;
	OBST O[2];

	int J[2]={7,7},obx[2]={1,1},ctr[2]={1,1},q=0,sec=0,ctr2=1,tfx;
	obx[0]=rand()%3+1;
	tfx=rand()%3+1;
		
	O[0].set(obx[0]);
	T.set_traffic(tfx);
	while(1)
	{
		delays(DELAY);
		F.move_frame();
		T.show_traffic();
		if(q==0)
		{C.set(); q=1;} 
		C.switch_car();
		
		O[0].move_obst(J[0]);
		check(O[0],J[0],ctr[0],obx[0],obx[1]);
		ctr2=T.check_traffic();
		if(J[0]==15) 
		{
			while(obx[0]==obx[1])
				obx[1]=rand()%3+1;
			O[1].set(obx[1]);
			sec=1;
		}
		if(ctr2==0)
		{
			T.del_traffic();
			ctr2=1;
			tfx=rand()%3+1;
			T.set_traffic(tfx);
		}
		J[0]++;
		if(sec==1)
		{
			O[1].move_obst(J[1]);
			check(O[1],J[1],ctr[1],obx[1],obx[0]);
			J[1]++;
		}
		P.show_score();
	}	
}
class GAME_NAME
{
		
	public:
		int pointer;
	void precaution()		
	{	
		if(GetAsyncKeyState(VK_RETURN))
			{
				Sleep(2000);					////chnge if u want
				pointer=-2;
			}
		if(GetAsyncKeyState(VK_UP))
			pointer=-1;
		if(GetAsyncKeyState(VK_DOWN))
			pointer=-1;
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
		for(i=2;i<=10;i++)
			des(i,2);
		for(i=2;i<=10;i++)
			des(6,i);
	
//--------------------------------------T
//------------------------------------
		for(i=10;i>=2;i--)
			des(13,i);	
		for(i=13;i<=19;i++)
			des(i,2);
		for(i=2;i<=6;i++)
			des(19,i);
		for(i=19;i>=13;i--)
			des(i,6);	
		for(i=13;i<=19;i=i=i+2)
			des(i,x++);	
		//--------------------R
		//---------------
		for(i=10;i>=2;i--)
			des(23,i);	
		for(i=23;i<=29;i++)
			des(i,2);
		for(i=2;i<=10;i++)
			des(29,i);
		for(i=23;i<=29;i++)
			des(i,6);
		
	//-----------------A
	//-----------------	
		for(i=10;i>=2;i--)
			des(33,i);	
		for(i=33;i<=39;i++)
			des(i,2);
		for(i=33;i<=38;i++)
			des(i,6);
		//----------------------F
		//--------------------
		for(i=13;i<=21;i++)
			des(2,i);
		for(i=2;i<=7;i++)
			des(i,13);
		for(i=2;i<=6;i++)
			des(i,17);
	//--------------------F
	//--------------------------
	
		for(i=10;i<=18;i++)
			des(i,13);
		for(i=13;i<=21;i++)
			des(14,i);
		for(i=10;i<=18;i++)
			des(i,21);
	//---------------	
	//--------------------- I
		for(i=28;i>=21;i--)
		{	des(i,13);	des(i+11,13);}
		for(i=13;i<=21;i++)
		{	des(21,i);	des(32,i);}
		for(i=21;i<=28;i++)
		{	des(i,21);	des(i+11,21);}
		for(i=21;i>=17;i--)
		{	des(28,i);	des(39,i);}
		int a=1,ac=27;
		for(i=17;i>=13;i--)
		{	
			if(a<=3)
				des(ac--,17);
			des(39,i);
			a++;
		}
		gotoxy(10,24);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		system("pause");
		precaution();
	
	}
};
class MENU
{
	int pointer;
	char name[20];
	public:
//	void entry_design(int);
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
			cout<<"Ride down the tracks to reach your destination as fast as";
			gotoxy(5,11);
			cout<<"possible. Use the UP(^) and DOWN(v) arrows to increase";
			gotoxy(5,12);
			cout<<"and decrease your speed respectively. Make sure your car";
			gotoxy(5,13);
			cout<<"does not land in the track with Red lights, they will ";
			gotoxy(5,14);
			cout<<"decrease your score. Avoid the obstacles on the way and ";
			gotoxy(5,15);
			cout<<"gain more score by Riding as Fast as possible.";
			gotoxy(5,16);
			cout<<"You can view your speed in the speedometer.";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			gotoxy(5,18);
			cout<<"Press Escape to go back to Menu...";
			if(GetAsyncKeyState(VK_ESCAPE))
				break;
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
			cout<<"TRAFFIGO";
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
		for(int i=3;i>0;i--)
		{	
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
			gotoxy(10,14);
			cout<<"Going to menu in "<<i<<" seconds"; 
			Beep(500,1000);
		}
	}
			void precaution()		// this function avoids useful keys which can b pressed
	{	
		if(GetAsyncKeyState(VK_RETURN))
			{
				pointer=-2;
			}
		if(GetAsyncKeyState(VK_UP))
			pointer=-1;
		if(GetAsyncKeyState(VK_DOWN))
			pointer=-1;
	}
	
	void entry_menu()
	{
		GAME_NAME *g;
		g=new GAME_NAME;
		g->entry_des();
		pointer=g->pointer;
		delete(g);
		int z=1,rw=18,kh=2,rr1=18;
		char choice,kbh;
		int xy=1,pointer=0;		// new
		MENU_DESIGN MD;
		do
		{	
			precaution();
			if(xy==1)
			{
				system("cls");
				xy++;
				
			}
			MD.perform();
			gotoxy(18,4);	cout<<"T R A F F I G O";
			delays(800);
			string Menu[5]={" PLAY"," Instructions"," High Score"," Developers"," Exit"};
			for(int m=0;m<5;m++)
			{
				if(pointer==m)
				{	
					gotoxy(18,rr1+m);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
					cout<<"*"<<Menu[m]<<" ";
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
			else if(GetAsyncKeyState(VK_RETURN))
			{	
				kh++;
				Beep(534,500);
				if(pointer==0)
				{	
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
					gotoxy(10,10);
					cout<<"Enter your Name:";
					cin>>P.name;
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
					gotoxy(10,10);
					cout<<"Use your LEFT(<) and RIGHT(>) arrows to move your car";
					gotoxy(10,11);
					cout<<"Use your UP(^) and DOWN(v) arrows to change speed of the car";
					gotoxy(10,13);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
					cout<<"GET READY";
					gotoxy(10,15);
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
					system("pause");
					system("cls");
					score=0;
					try
					{
						play();
					}
					catch(int n)
					{
						P.add_score();
						system("cls");
						gotoxy(10,10);
						cout<<"YOUR SCORE="<<score;
						gotoxy(10,12);
						cout<<"HIGHSCORE="<<P.disp_h_score();
						Beep(100,3000);
					}	
					for(int i=3;i>0;i--)
					{
						gotoxy(10,14);
						cout<<"Going to menu in "<<i<<" seconds"; 
						Beep(500,1000);
					}
					if(GetAsyncKeyState(VK_RETURN))
					{
						pointer=-2;
					}
					xy=1;
				
				}
				else if(pointer==1)
				{	
					instruction();
					if(GetAsyncKeyState(VK_RETURN))
					{
						pointer=-2;
					}
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
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				gotoxy(24,12);
				//cout<<"H I G H S C O R E = "<<P.disp_h_score();
				P.show_hs();
					xy=1;
					for(int i=3;i>0;i--)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
						gotoxy(10,14);
						cout<<"Going to menu in "<<i<<" seconds"; 
						Beep(500,1000);
					}
					if(GetAsyncKeyState(VK_RETURN))
					{
						pointer=-2;
					}
					xy=1;
				}
				
				else if(pointer==3)
				{
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
					exit(0);
				}
				pointer=0;
			}
		}while(z);
	}	
};

int main()
{
	srand(time(NULL));
	MENU M;
	M.entry_menu();
	return 0;
}

