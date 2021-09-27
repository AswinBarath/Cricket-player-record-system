#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char begining(char t[],char c[]);
char t1[20],t2[20];
int n;
void team1();
void team2();
class data
{
 char name[30];
 int playercode;
 int MR;
 int total_run1;
 int total_run2;
  public:
	data()
	{
	playercode=0;
	strcpy(name,00);
	MR=0;
	total_run1=0;
	total_run2=0;
	}

	void enter_name_runs(char t[])       //TO TAKE ENTRY OF NEW RECORDS
	{
	 int i;
	 cout<<"\n Enter player's number            : ";
	 cin>>playercode;
	 cout<<"\n Enter player name 	            : ";
	 gets(name);
	 cout<<"\n Enter number of matches          :";
	 cin>>n;
	 for(i=0;i<n;i++)
	 {
	 cout<<"\n'"<<i+1<<"'-match run(s)          : ";
	 cin>>MR;
	 if(t==t1)
	 {
	 total_run1=total_run1+MR;
	 }
	 else
	 if(t==t2)
	 {
	 total_run2=total_run2+MR;
	 }
	 }
	}

	void show_record()           //TO DISPLAY THE RECORDS EXISTING IN THE FILE
	{int i;
	 cout<<"\n Player number                    :"<<playercode;
	 cout<<"\n Player name                      :"<<name;
	 for(i=0;i<n;i++)
	 cout<<"\n'"<<i+1<<"'-match run(s)          : "<<MR;
	}

	int getplayercode()
	{
	return playercode;
	}
	int gettotalruns1()
	{
	return total_run1;
	}
	int gettotalruns2()
	{
	return total_run2;
	}
	char* get_name()
	{
	return name;
	}

	void modify_data(char t[])         //TAKE DATA TO MODIFIFY EXISTING RECORD
	{ int i;
	int total_run1=0,total_run2=0;
	if(t==t1)
	{
	cout<<"\n ::::::::Enter new data for modification :::::::: ";
	for(i=0;i<n;i++)
	{
	cout<<"\n'"<<i+1<<"'-match run(s)          : ";
	cin>>MR;
	total_run1=total_run1+MR;
	}
	}
	else
	if(t==t2)
	{
	cout<<"\n ::::::::Enter new data for modification :::::::: ";
	for(i=0;i<n;i++)
	{
	cout<<"\n'"<<i+1<<"'-match run(s)          : ";
	cin>>MR;
	total_run2=total_run2+MR;
	}
	}
	}
};

data d;
fstream file;
fstream file1;




//*  *  *  *  *  *  *  *  *  *  *  *  INSERT NEW RECORD(s)  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
void insert(char t[])
{       if(t==t1)
       {
	int i,no;
	file.open("record1.dat",ios::in|ios::app|ios::binary);
	cout<<"\n           ::Entry of new record(s)::          ";
	cout<<"\nHow many record(s) you want to enter : ";
	cin>>no;
		for(i=0;i<no;i++)
		{
		d.enter_name_runs(t1);	       //insert  records
		file.write((char*)&d,sizeof(d));
		}
	file.close();
	}
	else
	if(t==t2)
	{
	int i,no;
	file.open("record2.dat",ios::in|ios::app|ios::binary);
	cout<<"\n           ::Entry of new record(s)::          ";
	cout<<"\nHow many record(s) you want to enter : ";
	cin>>no;
		for(i=0;i<no;i++)
		{
		d.enter_name_runs(t2);	       //insert  records
		file.write((char*)&d,sizeof(d));
		}
	file.close();
	}
}

//*  *  *  *  *  *  *  *  *  *  *  *  *  DISPLAY EXISTING RECORD(s)   *  *  *  *  *  *  *  *  *  *  *  *  *  *
void display(char t[])
{    if(t==t1)
      {
      int run;
	file.open("record1.dat",ios::in|ios::binary);
	cout<<"\n|||||||||||||||||||||| Entered record(s) ||||||||||||||||||||||||";
	file.read((char*)&d,sizeof(d));
		while(file)
		{
		 d.show_record();
		 file.read((char*)&d,sizeof(d));
		}
	run=d.gettotalruns1();
	cout<<"\n TOTAL RUNS:"<<run;
	file.close();
	}
	else
	if(t==t2)
      {
      int run;
	file.open("record2.dat",ios::in|ios::binary);
	cout<<"\n|||||||||||||||||||||| Entered record(s) ||||||||||||||||||||||||";
	file.read((char*)&d,sizeof(d));
		while(file)
		{
		 d.show_record();
		 file.read((char*)&d,sizeof(d));
		}
	run=d.gettotalruns2();
	cout<<"\n TOTAL RUNS:"<<run;
	file.close();
	}


}

//*  *  *  *  *  *  *  *  *  *  *  *  * SEARCH RECORD *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
void search(char t[])
{       if(t==t1)
       {
	int p,r,srch=0;
	file.open("record1.dat",ios::in|ios::binary);
	cout<<"\nEnter the player code to see his records : ";
	cin>>r;
	file.seekg(0);
	file.read((char*)&d,sizeof(d));
		while(file)
		{
		p=d.getplayercode();
		if(r==p)
		{
		d.show_record();
		srch=1;
		break;
		}
		else
		{
		file.read((char*)&d,sizeof(d));
		}
		}
	file.close();
	if(srch==0)
	{
	cout<<"\nThere is no record which have this playercode .";
	}
	}
	else
	if(t==t2)
       {
	int p,r,srch=0;
	file.open("record2.dat",ios::in|ios::binary);
	cout<<"\nEnter the player code to see his records : ";
	cin>>r;
	file.seekg(0);
	file.read((char*)&d,sizeof(d));
		while(file)
		{
		p=d.getplayercode();
		if(r==p)
		{
		d.show_record();
		srch=1;
		break;
		}
		else
		{
		file.read((char*)&d,sizeof(d));
		}
		}
	file.close();
	if(srch==0)
	{
	cout<<"\nThere is no record which have this playercode .";
	}
	}
}

//*  *  *  *  *  *  *  *  *  *  *  *  *  *  MODIFY DATA *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
void modify(char t[])
{       if(t==t1)
       {
	int posi=0,got=0,dmd=0;
	cout<<"\nEnter the playercode whose record to be modified : ";
	cin>>dmd;
	int ifdata=1;
	file.open("record1.dat",ios::in|ios::out|ios::binary);
	posi=file.tellg();
		 while(file)
		{ file.read((char*)&d,sizeof(d));
		 got=d.getplayercode();
		   if(dmd==got)
			 {file.seekg(posi);
			   d.modify_data(t1);
			   ifdata=2;
			   file.write((char*)&d,sizeof(d));
			   break;
			}
		posi=file.tellg();
		}
	file.close();
	if(ifdata==1)
	{cout<<"\n           Data not available for modification         ";
	}
	}
	if(t==t2)
       {
	int posi=0,got=0,dmd=0;
	cout<<"\nEnter the playercode whose record to be modified : ";
	cin>>dmd;
	int ifdata=1;
	file.open("record2.dat",ios::in|ios::out|ios::binary);
	posi=file.tellg();
		 while(file)
		{ file.read((char*)&d,sizeof(d));
		 got=d.getplayercode();
		   if(dmd==got)
			 {file.seekg(posi);
			   d.modify_data(t2);
			   ifdata=2;
			   file.write((char*)&d,sizeof(d));
			   break;
			}
		posi=file.tellg();
		}
	file.close();
	if(ifdata==1)
	{cout<<"\n           Data not available for modification         ";
	}
	}
}

//*  *  *  *  *  *  *  *  *  *  *  *  *  *  * DELETE RECORD*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *
void delete_record(char t[])
{       if(t==t1)
	{
	int remove_record=0,code_get=0;
	cout<<"\n Enter the player code whose record to be deleted : ";
	cin>>remove_record;
	file.open("record1.dat",ios::in|ios::out|ios::binary);
	file1.open("tempo.dat",ios::in|ios::out|ios::binary);
	file.seekg(0);
		 while(file)
		 {
		  file.read((char*)&d,sizeof(d));
		  code_get=d.getplayercode();
		  if(remove_record==code_get)
		  {cout<<" ";
		  }
		  else
		  { file1.write((char*)&d,sizeof(d));
		  }
		  }
	file.close();
	file1.close();
	remove("record1.dat");
	rename("tempo.dat","record1.dat");
	}
	else
	if(t==t2)
	{
	int remove_record=0,code_get=0;
	cout<<"\n Enter the player code whose record to be deleted : ";
	cin>>remove_record;
	file.open("record2.dat",ios::in|ios::out|ios::binary); file1.open("tempo.dat",ios::in|ios::out|ios::binary);
	file.seekg(0);
		 while(file)
		 {
		  file.read((char*)&d,sizeof(d));
		  code_get=d.getplayercode();
		  if(remove_record==code_get)
		  {cout<<" ";
		  }
		  else
		  { file1.write((char*)&d,sizeof(d));
		  }
		  }
	file.close();
	file1.close();
	remove("record2.dat");
	rename("tempo.dat","record2.dat");
	}

}
void close()
{
cout<<"\n PRESS ENTER TO EXIT!!";
getch();}
void play1();
void play2();
void teamrec(char t[]);

//*  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  *  * * * *
void play1()
{
	clrscr();
	int choice;
	char ans='n';
	cout<<::t1<<"\n!!!!!!!!!!YOUR BATING!!!!!!!!!!";
	do
	{
	cout<<"\n=*=*=*=*=*=*=*=*=* PLAYER RECORD KEEPING SYSTEM "<<t1<<" *=*=*=*=*=*=*=*=*=*";
	cout<<"\n 1.INSERT RECORD \n 2.DISPLAY RCEORD \n 3.SEARCH RECORD \n 4.MODIFY RECORD \n 5.DELETE PREVIOUS ENTERED RECORD \n 6.VIEW TEAM DETAILS \n 7.ENTER NEXT TEAM RECORD ";
	cout<<"\n Enter any one of the options : ";
	cin>>choice;

	switch(choice)
	{
	 case 1: insert(t1); teamrec(t1);
	 break;
	 case 2: display(t1);
	 break;
	 case 3: search(t1);
	 break;
	 case 4: modify(t1);
	 break;
	 case 5: delete_record(t1);
	 break;
	 case 6: team1();
	 break;
	 case 7: play2();
	 break;
	 default: cout<<"\n Enter choice between 1 to 7 ";
	}
	cout<<"\n Do you want to choose any other option ? :(y/n): ";
	cin>>ans;

	}while(ans=='y'||ans=='Y');
}

//********************************************************************************
void play2()
{
	clrscr();
	int choice;
	char ans='n';
	cout<<::t2<<" !!!!!!!YOUR  BATING!!!!!!! ";
	do
	{
	cout<<"\n=*=*=*=*=*=*=*=*=* PLAYER RECORD KEEPING SYSTEM "<<t2<<" *=*=*=*=*=*=*=*=*=*";
	cout<<"\n 1.INSERT RECORD \n 2.DISPLAY RCEORD \n 3.SEARCH RECORD \n 4.MODIFY RECORD \n 5.DELETE PREVIOUS ENTERED RECORD \n 6.VIEW TEAM DETAILS \n 7.ENTER NEXT TEAM RECORD ";
	cout<<"\n Enter any one of the options : ";
	cin>>choice;

	switch(choice)
	{
	 case 1: insert(t2); teamrec(t2);
	 break;
	 case 2: display(t2);
	 break;
	 case 3: search(t2);
	 break;
	 case 4: modify(t2);
	 break;
	 case 5: delete_record(t2);
	 break;
	 case 6: team2();
	 break;
	 case 7: play1();
	 break;
	 default: cout<<"\n Enter choice between 1 to 7";
	}
	cout<<"\n Do you want to choose any other option ? :(y/n): ";
	cin>>ans;
	clrscr();
	}while(ans=='y'||ans=='Y');

}
//********************************************************************************
void front()
{
	int k,i,j;
	for(k=0;k<2;k++)
	{
	for(i=0;i<10;i++)
	{
	cout<<"\n";
	 for(j=0;j<20;j++)
	   {
		if(i<j||j>10-i)
	      cout<<" ";
	      else
	      cout<<"*";
	    }
	  }
	 cout<<"\n*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";	  }
	cout<<"\n\n+++++++++++++++++++++++++||| CRICKET |||++++++++++++++++++++++++";
}

//******************************************************************************
char second()
{
	clrscr();
	char y;
	ofstream ifile("matchdet.txt",ios::out);
	char date[10],place[20];
	cout<<"\n \t \t \t    ------------------------" ;
	cout<<"\n \t \t \t    ---------WELCOME--------" ;
	cout<<"\n \t \t \t    ------------------------" ;
	cout<<"\n \t*ENTER THE FIRST TEAM  ";
	gets(t1);
	ifile<<"\n TEAM_1--"<<t1;
	cout<<"\n \t*ENTER THE SECOND TEAM  ";
	gets(t2);
	ifile<<"\n TEAM_2--"<<t2;
	cout<<"\n \t*ENTER THE PLACE  ";
	gets(place);
	ifile<<"\n PLACE--"<<place;
	cout<<"\n \t*ENTER THE DATE  ";
	gets(date);
	ifile<<"\n DATE--"<<date;
	ifile.close();
	cout<<"\n \t \t \t \t press enter to continue ";
	y=begining(t1,t2);
	return(y);
	}

//********************************************************************************
char begining(char t1[],char t2[])
{
	clrscr();
	char s;
	cout<<"\n \n \t \t "<<t1<<"  Vs  "<<t2<<"\n";
	cout<<"\n \n";
	ifstream ifile("matchdet.txt",ios::in);
	ifile.seekg(0,ios::beg);
	char ch[20];
	while(!ifile.eof())
	{
	cout<<"\n \t \t  ";
	ifile>>ch;
	puts(ch);
	cout<<"\n--------------------------------------------------------" ;
	}
	ifile.close();
	cout<<"\n  \t \t WOW! \n THE CLIMATE IS AWESOME.\n NOW IT WOULD BE A GOOD MATCH BETWEEN TWO GOOD TEAMS. \n LETS MOVE ON TO THE TOSS, PRESS E TO TOSS:";
	cin>>s;
	return(s);
}

//*******************************************************************
int toss()
{
	clrscr();
	randomize();
	int h;
	char chance[1],F;
	chance[0]='T';
	chance[1]='H';
	h=random(2);
	if(h==1)
	{
	cout<<"\n \t  THE CALL IS FOR TEAM '"<<t1<<"'\n  \n \t \t DO YOU WANT HEAD(H) OR TAIL(T):";
	cin>>F;
	}
	else
	{
	cout<<"\n \t  THE CALL IS FOR TEAM '"<<t2<<"'\n  \n \t \t DO YOU WANT HEAD(H) OR TAIL(T):";
	cin>>F;
	}
	if(F==chance[h])
	{
	cout<<"\n WOW!(-: GOOD BEGINING. \n YOU HAVE WON THE TOSS";
	team1();
	team2();
	return(1);
	}
	else
	{
	cout<<"\n OOPS! )-: YOU HAVE LOST THE TOSS";
	team1();
	team2();
	return(2);
	}
}

//***********************************************************************
void team1()
{
	cout<<"\n PLAYERS IN '"<<::t1<<"'are:-";
	char ch[20];
	display(t1);
	ifstream ifile("players1.txt",ios::in);
	while(!ifile.eof())
	{
	ifile>>ch;
	cout<<"\n";
	puts(ch);
	}
	ifile.close();
}

//************************************************************************
void team2()
{
	cout<<"\n PLAYERS IN '"<<::t2<<"'are:-";
	char ch[20];
	display(t2);
	ifstream ifile("players2.txt",ios::in);
	while(!ifile.eof())
	{
	ifile>>ch;
	cout<<"\n ";
	puts(ch);
	}
	ifile.close();
}

//*************************************************************************
void teamrec(char l[])
{

	ofstream ifile(l,ios::out);
	int trn,ovr,boundaries,dot,wick;
	if(l==t1)
	{
	trn=d.gettotalruns1();
	}
	else
	if(l==t2)
	{
	trn=d.gettotalruns2();
	}
	ifile<<"\n \t-*TOTALRUNS--"<<trn;
	cout<<"\n \t -*ENTER THE NO. OF OVERS PLAYED  ";
	cin>>ovr;
	ifile<<"\n -*OVERS--"<<ovr;
	cout<<"\n \t -*ENTER THE NO. OF BONDARIES  ";
	cin>>boundaries;
	ifile<<"\n -*BOUNDARIES--"<<boundaries;
	cout<<"\n \t -*ENTER THE NO.OF DOTS  ";
	cin>>dot;
	ifile<<"\n -*DOTS--"<<dot;
	cout<<"\n \t -*ENTER THE NO.OF WICKETS  ";
	cin>>wick;
	float h=(trn/ovr);
	cout<<"\n \t -*RUN RATE"<<h;
	ifile<<"\n \t -*WICKETS--"<<wick;
	ifile.close();
}

//*********************************************************
void trophy()
{
	cout<<"\n\t(***=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=***)";
	cout<<"\n\t    -##############  INDIA  ##############-    ";
	cout<<"\n\t    -##############   2018  ##############-    ";
	cout<<"\n\t         ------------------------------        ";
	cout<<"\n\t                   #########                   ";
	cout<<"\n\t                  ###########                  ";
	cout<<"\n\t                 #############                 ";
	cout<<"\n\t                ###############                ";
	cout<<"\n\t           #########################           ";
}

//**************************************************************************
void sresult(char x[])
{
	clrscr();
	trophy();
	char ch[21];
	ifstream ifile(x,ios::in);
	cout<<"\n \n \t \t HURRAY! MATCH WON BY "<<x<<"\n";
	while(!ifile.eof())
	{
	ifile>>ch;
	puts(ch);
	}
	ifile.close();
}

//*******************************************************
void tresult(char x[],char y[]='\0')
{
	trophy();
	cout<<"\n \n \n \t \t MATCH TIED BETWEEN"<<x<<"  and  "<<y;
 }

//********************************************************************************
void result()
{
	ifstream ifile(t1,ios::in);
	ifstream ofile(t2,ios::in);
	int r1,r2;
	ifile>>r1;
	ofile>>r2;
	if(r1==r2)
	{
	tresult(t1,t2);
	}
	else
	if(r1>r2)
	{
	sresult(t1);
	}
	else
	{
	if(r1<r2)
	sresult(t2);
	}
}
void main()
{
	clrscr();
	char m,f;
	front();
	cout<<"\t\t\tPress M to continue:";
	cin>>m;
	if(m=='M'||m=='m')
	{
	f=second();
	if(f=='E'||f=='e')
	{
	if(toss()==1)
	{
	play1();
	play2();}
	else
	{
	play2();
	play1();}
	}
	}
	result();
	cout<<"\n----------------------------------THANK YOU! ----------------------------------";
	getch();
}
