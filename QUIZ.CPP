#include<string.h>    //For Password
#include<iostream.h>
#include<fstream.h>   //To open and write the records of scores and questions 
#include<conio.h>     //For clrscr(), getch(), and font effects
#include<stdlib.h>    //For random()
#include<stdio.h>     //To enter questions and special fonts

char ch,a;
int score=0,q=1;      //To count score and question number

//To Reward Correct answers. Further referenced in questions()
void good() {
	clrscr();
	textcolor(3+BLINK);
	cout<<"\n\n\n\n\t\t\t\t";
	cprintf("CORRECT!!");
	textcolor(WHITE);
	getch();
	clrscr();};

//To Punish wrong answers
void bad(){
	clrscr();
	textcolor(RED+BLINK);
	cout<<"\n\n\n\n\t\t\t\t";
	cprintf("WRONG!!");
	textcolor(WHITE);
	getch();
	clrscr();};

//To view score 
void scbrd(){
	clrscr();
	cout<<"\t\t\t\t SCORE BOARD \t\t\t\t\n";
	char line[30];
	int c=0;
	ifstream infile;
	infile.open("abc.txt",ios::in);
	infile.seekg(0,ios::beg);
	while(!infile.eof())
	{
		cout<<"\n";
	    infile.getline(line,30,'\n');
		c++;
		cout<<c<<">"<<line;
	}};

/*Class of the question: 
  consists of 1 question [151 chars], 
  1 answer [1 char], 4 options [30 chars]*/
class Qstruct {
	char question[151];
	char ans;
	char op1[31],op2[31],op3[31],op4[31];
	public:
		int qno;
		void getdata(){
			cout<<"Enter question no.";
			cin>>qno;
			cout<<"Enter Answer ";
			cin>>ans;
			cout<<"Enter option A ";
			cin>>op1;
			cout<<"Enter option B ";
			cin>>op2;
			cout<<"Enter option C ";
			cin>>op3;
			cout<<"Enter option D ";
			cin>>op4;}
		void putdata(){
			cout<<"Question no:"<<qno<<endl;
			cout<<"Question:"<<question;
			cout<<"Option A:"<<op1<<endl;
			cout<<"Option B:"<<op2<<endl;
			cout<<"Option C:"<<op3<<endl;
			cout<<"Option D:"<<op4<<endl;
			void putans();}
		void getq(){
			cout<<"Enter Question ";
			fgets(question , 151 , stdin);}
		void putans(){
			cout<<"Answer:"<<ans<<endl;}
		int getqno(){
			return qno;}
		int putan(){
			return ans;}
} qtn,qstn,qSet;

//For champ
class playchamp{
	public:
		char ans,name[6];
		int cscore;
		int champlay(void);
		void initialize(){
			strcpy(name,"Champ");
			cscore=0;
			cout<<"\n\n\t\t\t\tYou\'re playing against Champ. \n\t\t\t\tChamp gets the same question as you.\n";
			cout<<"\t\t\t\tHe has the same scoring system as you.";
			cout<<"\n\t\t\t\tTry n beat him.\n";
		}
} champ;

//champ plays
int playchamp::champlay(void){
	cout<<"\n Champ:";
	int xran=random(3);
	if(xran==1) ans='a';
	else if(xran==2) ans='b';
	else if(xran==3) ans='c';
	else if(xran==0) ans='d';
	int a=ans;
	return a;}
	
//class for player
class play {
	char a;
	char name[20];
    public:
	  void initializ(){
		cout<<"\n\n\n\t\t\t"<<"WELCOME GUEST. PLEASE ENTER YOUR NAME.\n\n\t\t";
		cin>>name;
		clrscr();}

	  void initializ(int a){
		cout<<"\n\n\n\t\t\t"<<"WELCOME GUEST. PLEASE ENTER YOUR NAME.\n\n\t\t";
		cin>>name;cout<<endl;
		champ.initialize();
		getch();
		clrscr();}

	  void question(void);

	  void question(int);

	  void dispscr(void);

	  void dispscr(int);

	  void tofil(void);

	  void tofil(int);

	  void del(){name[20]='X'; }};

/*Takes a random question from binary file and prints it on screen along
  With the options. Takes in one answer from the user, updates score,
  calls good() and bad()*/
void play::question(void){
		fstream qin;

		qin.open("question.dat",ios::in|ios::binary);
		qin.seekg(0,ios::beg);
		int x=random(10)+1;

		while(!qin.eof())
		{
			qin.read((char*)&qtn,sizeof(qtn));
			if(qtn.getqno()==x)
			{
			    qstn=qtn;
				qtn.putdata();
				cout<<"\n";
			}
		}

		cout<<endl<<endl<<"Enter answer:";
		cin>>a;

		int y=qstn.putan();
		int z=a;
		if(y==z)
		{
			good();
			score+=2;
		}
	    else
		{
			score--;
			bad();
		}
	    ++q;};

void play::question(int parameter){
		parameter++; parameter--;
		fstream qin;

		qin.open("question.dat",ios::in|ios::binary);
		qin.seekg(0,ios::beg);
		int x=random(10)+1;

		while(!qin.eof())
		{
			qin.read((char*)&qtn,sizeof(qtn));
			if(qtn.getqno()==x)
			{
			    qstn=qtn;
				qtn.putdata();
				cout<<"\n";
			}
		}

		cout<<endl<<endl<<"Enter answer:";
		cin>>a;
		cout<<endl<<"Champ:";
		getch();
		cout<<champ.ans;
		getch();

		int y=qstn.putan();
		int z=a;
		int w=champ.champlay();
		if(y==z)
		{
			good();
			score+=2;
		}
	    else
		{
			score--;
			bad();
		}
		if(w==y)champ.cscore+=2;
		else champ.cscore--;
	    ++q;};

//Displays score from binary file
void play::dispscr(void)
	{
		cout<<"\n\n\n\n\t\t\t\t\tQUIZ "<<"\n\n";
		cout<<"\tPLAYER:"<<name<<"\t\t\t\t\t\t\tSCORE:"<<score;
		question();
	}

void play::dispscr(int parameter){
	parameter++; parameter--;
	cout<<"\n\n\n\n\t\t\t\t\tQUIZ "<<"\n\n";
	cout<<"\tPLAYER:"<<name<<"\t\t\t\t\t\t\tSCORE:"<<score;
	cout<<"\n\tPLAYER:"<<champ.name<<"\t\t\t\t\t\t\tSCORE:"<<champ.cscore;
	question(parameter);}

//Saves name and score to the text file
void play::tofil(void)
       {
		ofstream tofile;
		tofile.open("abc.txt",ios::app);
		tofile<<name<<"\t\t\t"<<score<<"\n";
		tofile.close();
		}

void play::tofil(int parameter){
	parameter++; parameter--;
	if(score>champ.cscore){
		clrscr();
		cout<<"\n\n\n\n\n\t\t\t\t\t\tYOU WIN!!!\n";
		ofstream tofile;
		tofile.open("abc.txt",ios::app);
		tofile<<name<<"\t\t\t"<<score<<"\n";
		tofile.close();}
	else {
		clrscr();
		cout<<"\n\n\n\n\n\t\t\t\t\t\tYOU LOSE..\n";}
}
//Views all questions
void viewqs(){
	clrscr();
	ifstream sAll("question.dat",ios::binary|ios::in);
	sAll.seekg(0,ios::beg);
	while(!sAll.eof()){
			sAll.read((char*)&qSet,sizeof(qSet));
			qSet.putdata();
			qSet.putans();
			cout<<"\n";
			getch();}
	getch();
	sAll.close();}

//Function to enter questions to the binary file
void enteqs(){
    char password[4],passkey[4];
	clrscr();
	strcpy(passkey,"bob");
	cout<<"\n\n\n\n\n\t\t\t\t ENTER PASSWORD:\n\t\t\t\t\t";
	cin>>password;
	if(!strcmp(password,passkey)){
		clrscr();
		ofstream qwrite;
		qwrite.open("question.dat",ios::app|ios::binary);
		char x='y';
		while(x=='y'||x=='Y'){
			qSet.getdata();
			qSet.getq();
			qwrite.write((char*)&qSet,sizeof(qSet));
			cout<<"Question added.\n";
			cout<<"RECORD:\n";
			qSet.putdata();
			cout<<"\nWant to enter more?(y/n)";
			cin>>x;}
		qwrite.close();}}

play p;

//Function to play quiz
void playgame(){
	while(1)
	{
		clrscr();
		p.initializ();
		for(int f=0;f<10;f++){
		p.dispscr();
		};
		p.tofil();
		clrscr();
		cout<<"\n\n\n\t\t\tPress a key to go to scoreboard";
		getch();
		scbrd();
		cout<<"\nPress m for main menu, x to exit.\n";
		cin>>ch;
		if(ch=='m'||ch=='M') goto home;
		else if (ch=='x'||ch=='X') exit(1);
    }
	home: return;}

void playgame(int parameter){
	while(1)
	{
		clrscr();
		p.initializ(parameter);
		for(int f=0;f<10;f++){
		p.dispscr(parameter);
		};
		p.tofil(parameter);
		clrscr();
		cout<<"\n\n\n\t\t\tPress a key to go to scoreboard";
		getch();
		scbrd();
		cout<<"\nPress m for main menu, x to exit.\n";
		cin>>ch;
		if(ch=='m'||ch=='M') goto home;
		else if (ch=='x'||ch=='X') exit(1);
    }
	home: return;}
//Function to play along with champ
void agchamp(){
	playgame(1);}
//MAIN FUNCTION ACTUALLY BEGINS HERE.
void main(){
    randomize();
	int choice;
	top: //label for goto
	clrscr();
	cout<<"\n\n\n\n\n\t\t\t\t1:PLAY THE GAME\n\t\t\t\t2:PLAY AGAINST CHAMP\n\t\t\t\t3:VIEW ALL QUESTIONS\n\t\t\t\t4:ADD QUESTIONS\n\t\t\t\t5:EXIT\n\t\t\t\tNOW CHOOSE.\n";
	cin>>choice;
	switch(choice){
		case(1):playgame();
		        break;
		case(2):agchamp();
					break;
		case(3):viewqs();
				break;
		case(4):enteqs();
				break;
		case(5):exit(1);
		default:cout<<"WRONG CHOICE\n";
				goto top;} //goto is here. Transfers control to top
	goto top;
	}