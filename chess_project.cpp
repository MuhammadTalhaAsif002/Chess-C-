#include <iostream>
#include<string>
#include <cstring>
#include <fstream>

#include <chrono>
#include <thread> 
// #include <windows.h>
#include <conio.h>
using namespace std;

//CHESS LOGIC
void displayboard(char chessboard[8][8]);
void userinput(char chessboard[8][8]);
void userinput2(char chessboard[8][8]);
void spacecheck(char chessboard[8][8],int i1,int j1,int i2,int j2);
int pawnmove1(char chessboard[8][8],int i1,int j1,int i2,int j2);
int pawnmove2(char chessboard[8][8],int i1,int j1,int i2,int j2);
int pawnmove3(char chessboard[8][8],int i1,int j1,int i2,int j2);
int pawnmove4(char chessboard[8][8],int i1,int j1,int i2,int j2);
int rookmove1(char chessboard[8][8],int i1,int j1,int i2,int j2);
int rookmove2(char chessboard[8][8],int i1,int j1,int i2,int j2);
int rookmove3(char chessboard[8][8],int i1,int j1,int i2,int j2);
int rookmove4(char chessboard[8][8],int i1,int j1,int i2,int j2);
int rookmove5(char chessboard[8][8],int i1,int j1,int i2,int j2);
int rookmove6(char chessboard[8][8],int i1,int j1,int i2,int j2);
void sleepAsec(){
    std::this_thread::sleep_for(std::chrono::milliseconds(2000)); 
}
//FILE HANDLING
void writeToUserTurnFile(string userturn){
  ofstream MyFile("userturn.txt"); 
  MyFile << userturn;
  MyFile.close();
}
void eraseChessBoardFileContent(){ 
    remove("chessboard.txt");
} 
void writeToChessBoard(char text){
  ofstream MyFile("chessboard.txt", std::ios_base::app ); 
  MyFile << text;
  MyFile.close(); 
}
int readUserTurn(){
    int value=-1;
    ifstream myfile("userturn.txt");  
    for (int i = 0; i < 1; i++)
    { 
        myfile >> value; 
    }
    // myfile >> value; 
    return value;
}
bool displayboardFromFile(string filename){
    char chessboard_t[8][8];
    char val=' ';
    ifstream myfile("chessboard.txt"); 
   
    for (int i = 0; i < 8; i++)
    { 
      for (int j = 0; j < 8; j++)
        { 
            myfile >> val; 
            if(val == '-'){
                chessboard_t[i][j]=' ';
            }
            else{
                chessboard_t[i][j]=val; 
            }
        }
    }
    // myfile >> value; 
    displayboard(chessboard_t);
    return "true";
}

int main()
{
	int user1=0;
	int user2=1;
	int count=0;
	int gameon=1;
	char game_resume_restart=' ';
	char chessboard[8][8]={'R','H','B','K','Q','B','H','R',
	                       'P','P','P','P','P','P','P','P',
	                       ' ',' ',' ',' ',' ',' ',' ',' ',
						   ' ',' ',' ',' ',' ',' ',' ',' ',
	                       ' ',' ',' ',' ',' ',' ',' ',' ',
	                       ' ',' ',' ',' ',' ',' ',' ',' ',
	                       'p','p','p','p','p','p','p','p',
	                       'r','h','b','k','q','b','h','r'};
	                       
	 if(readUserTurn()==-1){
	        cout<<"Welcom to my Chess Board, Lets start a new game!"<<endl; 
	        cout<<"3..."<<endl; 
	        cout<<"2..."<<endl; 
	        cout<<"1..."<<endl;
	        system("Go!!!");
	        sleepAsec(); 
	        displayboard(chessboard); 
	 }
	 else{
    	cout <<"Do you want to continue previous game or start a new one?"<<endl;
    	cout <<"Press C to Continue and R to restart..\n\n"<<endl;
    	cin  >> game_resume_restart;
    	if(game_resume_restart=='R' || game_resume_restart=='r'){
    	    displayboard(chessboard); 
    	}else if( game_resume_restart=='C' || game_resume_restart=='c'){
    	   
    	    displayboardFromFile("chessboard.txt");
    	}else{
    	    cout<<"Please enter a valid input!"<<endl;
    	}
	 }

	while(gameon==1){
	    //based on even turn and odd turn 
		if(count%2==0 || readUserTurn()%2==0){
		    //first user turn
		    userinput(chessboard);
		}
		if(count%2==1 || readUserTurn()%2==1){
			userinput2(chessboard);
		}
		count++;
		writeToUserTurnFile(to_string(count));
	}
}
void displayboard(char chessboard[8][8]){
    system("clear");
    //erasing previous content
    eraseChessBoardFileContent();
    //writing chessboard to file
    for(int i=0;i<8; i++){
        for(int j=0; j<8;j++){
            char ch = chessboard[i][j];
            if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
                writeToChessBoard(ch);
            }else{
                writeToChessBoard('-');
            }
            // writeToChessBoard('');//. is for space
        }
        //- means new line
        // for(int a=0;a<8;a++){
            // writeToChessBoard('.');
        // }
    }
	int num=8;
	cout<<"          "; 
	cout<<"     a     b     c     d     e     f     g     h" << endl;
	cout<<"            " <<"-------------------------------------------------";
	cout <<endl;
	for(int i=0;i<8;i++){
		cout<<"          ";
		cout<<num <<" ";
		num--;
	    cout<<"|";
		for (int j=0;j<8;j++){
			cout<<"  "<<chessboard[i][j]<<"  " <<"|";
			if(j==7){
				cout<<endl;
			}
		}
		cout<<"            ";
		cout<<"-------------------------------------------------";
		cout<<endl;
		
	}
	
}
void userinput(char chessboard[8][8]){
	int min=0,sec=0;
	int condition1,condition2,condition3,condition4,condition5;
	int i1=0,i2=0,j1=0,j2=0;
	char inputconvert[4];

	cout<<"Player 1 Turn!"<<endl;
	cout<<"Enter your move: ";
	for(int i=0;i<4;i++){
		cin>>inputconvert[i];
		}
	
	if(inputconvert[0]=='8'){
		i1=0;
	}
		if(inputconvert[0]=='7'){
		i1=1;
	}
		if(inputconvert[0]=='6'){
		i1=2;
	}
		if(inputconvert[0]=='5'){
		i1=3;
		
	}
		if(inputconvert[0]=='4'){
		i1=4;
			
	}
		if(inputconvert[0]=='3'){
		i1=5;
		
	}
		if(inputconvert[0]=='2'){
		i1=6;
		
	}
		if(inputconvert[0]=='1'){
		i1=7;
		
	}
		if(inputconvert[1]=='a'){
		j1=0;
		
	}
		if(inputconvert[1]=='b'){
		j1=1;
		
    }
    	if(inputconvert[1]=='c'){
		j1=2;
		
	}
		if(inputconvert[1]=='d'){
		j1=3;
		
	}
		if(inputconvert[1]=='e'){
		j1=4;
	
	}
		if(inputconvert[1]=='f'){
		j1=5;
	
	}
		if(inputconvert[1]=='g'){
		j1=6;
		
	}
		if(inputconvert[1]=='h'){
		j1=7;
		
	}
	if(inputconvert[2]=='8'){
		i2=0;
	
	}
	if(inputconvert[2]=='7'){
		i2=1;
			
	}
	if(inputconvert[2]=='6'){
		i2=2;
			
	}
	if(inputconvert[2]=='5'){
		i2=3;
			
	}
	if(inputconvert[2]=='4'){
		i2=4;
			
	}
	if(inputconvert[2]=='3'){
		i2=5;
			
	}
	if(inputconvert[2]=='2'){
		i2=6;
			
	}
	if(inputconvert[2]=='1'){
		i2=7;
			
	}
	if(inputconvert[3]=='a'){
		j2=0;
		
	}
	if(inputconvert[3]=='b'){
		j2=1;
			
	}
	if(inputconvert[3]=='c'){
		j2=2;
			
	}
	if(inputconvert[3]=='d'){
		j2=3;
			
	}
	if(inputconvert[3]=='e'){
		j2=4;
			
	}
	if(inputconvert[3]=='f'){
		j2=5;
		
	}
	if(inputconvert[3]=='g'){
		j2=6;
			
	}
	if(inputconvert[3]=='h'){
		j2=7;
			
	}
	cout<<i1<<j1<<i2<<j2<<endl;
	if(chessboard[i1][j1]=='P' || chessboard[i1][j1]=='K' || chessboard[i1][j1]=='Q' || chessboard[i1][j1]=='R' || chessboard[i1][j1]=='H' || chessboard[i1][j1]=='B' ){
		cout<<"Invalid Element Selected;"<<endl;
		userinput(chessboard);
	}
	spacecheck(chessboard,i1,j1,i2,j2);
	if(chessboard[i1][j1]=='p'){
	condition1=pawnmove1(chessboard,i1,j1,i2,j2);
   condition2=pawnmove2(chessboard,i1,j1,i2,j2);
    if(condition1==0 && condition2==0){
    	chessboard[i2][j2]=chessboard[i1][j1];
     	chessboard[i1][j1]=' ';
	    displayboard(chessboard);}
    }
    if(chessboard[i1][j1]=='r'){
    	condition3=rookmove1(chessboard,i1,j1,i2,j2);
    	condition4=rookmove2(chessboard,i1,j1,i2,j2);
    	condition5=rookmove3(chessboard,i1,j1,i2,j2);
    	if(condition4==1 || condition3==1 && condition5==1 && chessboard[i2][j2]!='p' && chessboard[i2][j2]!='k' && chessboard[i2][j2]!='q' && chessboard[i2][j2]!='h'  && chessboard[i2][j2]!='b'){
    	chessboard[i2][j2]=chessboard[i1][j1];
     	chessboard[i1][j1]=' ';
	    displayboard(chessboard);}
	}
	if(chessboard[i1][j1]=='k'){
		if(i1-i2==1 && j1-j2==0 || i2-i1==1 && j2-j1==0 || i1-i2==0 && j2-j1==1 || i1-i2==0 && j1-j2==1 || i1-i2==1 && j1-j2==1 || i1-i2==1 && j2-j1==1 || i2-i1==1 && j1-j2==1 || i2-i1==1 && j2-j1==1){
		chessboard[i2][j2]=chessboard[i1][j1];
     	chessboard[i1][j1]=' ';
	    displayboard(chessboard);
		}
		else{
			cout<<"Invalid King Move!"<<endl;
			userinput(chessboard);
		}
	}
	if(chessboard[i1][j1]=='h'){
		if(i1-i2==2 && j1-j2==1 || i1-i2==2 && j2-j1==1 || i1-i2==1 && j1-j2==2 || i2-i1==1 && j1-j2==2 || i2-i1==2 && j1-j2==1 || i1-i2==1 && j2-j1==2 || i2-i1==1 && j2-j1==2 || i2-i1==2 && j2-j1==1){
		chessboard[i2][j2]=chessboard[i1][j1];
     	chessboard[i1][j1]=' ';
	    displayboard(chessboard);
		}
		else{
			cout<<"Invalid Knight(Horse) Move!"<<endl;
		}
	}
	if(chessboard[i1][j1]=='b'){
		if(i1>i2 && j1>j2){
			while(i1>=i2 && j1>=j2){
				
			}
		}
		if(i1>i2 && j2>j1){
		}
		if(i2>i1 && j1>j2){
			
		}
		if(i2>i1 && j2>j1){
			
		}
	}
   
	
	
}
void spacecheck(char chessboard[8][8],int i1,int j1,int i2,int j2){//To check whether user has selected a valid operation!
	int check;
	if(chessboard[i1][j1]==' '){
		cout<<"Invalid Operation!"<<endl;
		userinput(chessboard);
	}
}
int pawnmove1(char chessboard[8][8],int i1,int j1,int i2,int j2){//Pawn Validation 1!
      int flag=0;
	  int condition1;
	  condition1=i1-i2;
	 if(j1!=j2 || condition1>2 || condition1<=0){
      	cout<<"Invalid move!"<<endl;
      	flag=1;
	  }
	  return flag;
}
int pawnmove2(char chessboard[8][8],int i1,int j1,int i2,int j2){
	int flag=0;
 	int condition1;
    condition1=i1-i2;
    static int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0;
    if(j1==0 && condition1==2 && c1==2){
    	cout<<"Invalid pawn move 1!"<<endl;
    	flag=1;
	}
	if(j1==1 && condition1==2 && c2==2){
    	cout<<"Invalid pawn move 2!"<<endl;
    	flag=1;
	}
	if(j1==2 && condition1==2 && c3==2){
    	cout<<"Invalid pawn move 3!"<<endl;
    	flag=1;
	}
	if(j1==3 && condition1==2 && c4==2){
    	cout<<"Invalid pawn move 4!"<<endl;
    	flag=1;
	}
	if(j1==4 && condition1==2 && c5==2){
    	cout<<"Invalid pawn move 5!"<<endl;
    	flag=1;
	}
	if(j1==5 && condition1==2 && c6==2){
    	cout<<"Invalid pawn move 6!"<<endl;
    	flag=1;
	}
	if(j1==6 && condition1==2 && c7==2){
    	cout<<"Invalid move 7!"<<endl;
    	flag=1;
	}
	if(j1==7 && condition1==2 && c8==2){
    	cout<<"Invalid pawn move 8!"<<endl;
    	flag=1;
	}
    if(j1==0 && condition1==2){
    c1=2;
	}
	if(j1==1 && condition1==2){
    c2=2;
	}
	if(j1==2 && condition1==2){
    	c3=2;
	}
	if(j1==3 && condition1==2){
    	c4=2;
	}
	if(j1==4 && condition1==2){
    	c5=2;
	}
	if(j1==5 && condition1==2){
    	c6=2;
	}
	if(j1==6 && condition1==2){
    	c7=2;
	}
	if(j1==7 && condition1==2){
    	c8=2;
	}
	return flag;
}
int rookmove1(char chessboard[8][8],int i1,int j1,int i2,int j2){
	int flag=1;
	if(i1!=i2){
		flag=0;
	}
	return flag;
}
int rookmove2(char chessboard[8][8],int i1,int j1,int i2,int j2){
	int flag=1;
	if(j1!=j2){
		flag=0;
	}
	return flag;
}
int rookmove3(char chessboard[8][8],int i1,int j1,int i2,int j2){
	int flag=1;
	if(i1!=i2 && j1!=j2){
		flag=0;
	}
	return flag;
}
void userinput2(char chessboard[8][8]){
	int condition1,condition2,condition3,condition4,condition5;
	int i1=0,i2=0,j1=0,j2=0;
	char inputconvert[4];
	
	cout<<"Player 2 Turn!"<<endl;
	cout<<"Enter your move: ";
	for(int i=0;i<4;i++){
		cin>>inputconvert[i];
		}
	
	if(inputconvert[0]=='8'){
		i1=0;
	}
		if(inputconvert[0]=='7'){
		i1=1;
	}
		if(inputconvert[0]=='6'){
		i1=2;
	}
		if(inputconvert[0]=='5'){
		i1=3;
		
	}
		if(inputconvert[0]=='4'){
		i1=4;
			
	}
		if(inputconvert[0]=='3'){
		i1=5;
		
	}
		if(inputconvert[0]=='2'){
		i1=6;
		
	}
		if(inputconvert[0]=='1'){
		i1=7;
		
	}
		if(inputconvert[1]=='A'){
		j1=0;
		
	}
		if(inputconvert[1]=='B'){
		j1=1;
		
    }
    	if(inputconvert[1]=='C'){
		j1=2;
		
	}
		if(inputconvert[1]=='D'){
		j1=3;
		
	}
		if(inputconvert[1]=='E'){
		j1=4;
	
	}
		if(inputconvert[1]=='F'){
		j1=5;
	
	}
		if(inputconvert[1]=='G'){
		j1=6;
		
	}
		if(inputconvert[1]=='H'){
		j1=7;
		
	}
	if(inputconvert[2]=='8'){
		i2=0;
	
	}
	if(inputconvert[2]=='7'){
		i2=1;
			
	}
	if(inputconvert[2]=='6'){
		i2=2;
			
	}
	if(inputconvert[2]=='5'){
		i2=3;
			
	}
	if(inputconvert[2]=='4'){
		i2=4;
			
	}
	if(inputconvert[2]=='3'){
		i2=5;
			
	}
	if(inputconvert[2]=='2'){
		i2=6;
			
	}
	if(inputconvert[2]=='1'){
		i2=7;
			
	}
	if(inputconvert[3]=='A'){
		j2=0;
		
	}
	if(inputconvert[3]=='B'){
		j2=1;
			
	}
	if(inputconvert[3]=='C'){
		j2=2;
			
	}
	if(inputconvert[3]=='D'){
		j2=3;
			
	}
	if(inputconvert[3]=='E'){
		j2=4;
			
	}
	if(inputconvert[3]=='F'){
		j2=5;
		
	}
	if(inputconvert[3]=='G'){
		j2=6;
			
	}
	if(inputconvert[3]=='H'){
		j2=7;
			
	}
	cout<<i1<<j1<<i2<<j2<<endl;
	if(chessboard[i1][j1]=='p' || chessboard[i1][j1]=='k' || chessboard[i1][j1]=='q' || chessboard[i1][j1]=='r' || chessboard[i1][j1]=='h' || chessboard[i1][j1]=='b' ){
		cout<<"Invalid Element Selected;"<<endl;
		userinput2(chessboard);
	}
	spacecheck(chessboard,i1,j1,i2,j2);
	if(chessboard[i1][j1]=='P'){
	condition1=pawnmove3(chessboard,i1,j1,i2,j2);
   condition2=pawnmove4(chessboard,i1,j1,i2,j2);
    if(condition1==0 && condition2==0){
    	chessboard[i2][j2]=chessboard[i1][j1];
     	chessboard[i1][j1]=' ';
	    displayboard(chessboard);}
    }
    if(chessboard[i1][j1]=='R'){
    	condition3=rookmove4(chessboard,i1,j1,i2,j2);
    	condition4=rookmove5(chessboard,i1,j1,i2,j2);
    	condition5=rookmove6(chessboard,i1,j1,i2,j2);
    	if(condition4==1 || condition3==1 && condition5==1 && chessboard[i2][j2]!='P' && chessboard[i2][j2]!='K' && chessboard[i2][j2]!='Q' && chessboard[i2][j2]!='H'  && chessboard[i2][j2]!='B'){
    	chessboard[i2][j2]=chessboard[i1][j1];
     	chessboard[i1][j1]=' ';
	    displayboard(chessboard);}
	}
	if(chessboard[i1][j1]=='K'){
		if(i1-i2==1 && j1-j2==0 || i2-i1==1 && j2-j1==0 || i1-i2==0 && j2-j1==1 || i1-i2==0 && j1-j2==1 || i1-i2==1 && j1-j2==1 || i1-i2==1 && j2-j1==1 || i2-i1==1 && j1-j2==1 || i2-i1==1 && j2-j1==1){
		chessboard[i2][j2]=chessboard[i1][j1];
     	chessboard[i1][j1]=' ';
	    displayboard(chessboard);
		}
		else{
			cout<<"Invalid King Move!"<<endl;
			userinput2(chessboard);
		}
	}
	if(chessboard[i1][j1]=='H'){
		if(i1-i2==2 && j1-j2==1 || i1-i2==2 && j2-j1==1 || i1-i2==1 && j1-j2==2 || i2-i1==1 && j1-j2==2 || i2-i1==2 && j1-j2==1 || i1-i2==1 && j2-j1==2 || i2-i1==1 && j2-j1==2 || i2-i1==2 && j2-j1==1){
		chessboard[i2][j2]=chessboard[i1][j1];
     	chessboard[i1][j1]=' ';
	    displayboard(chessboard);
		}
		else{
			cout<<"Invalid Knight(Horse) Move!"<<endl;
		}
	}
	if(chessboard[i1][j1]=='B'){
		if(i1>i2 && j1>j2){
			while(i1>=i2 && j1>=j2){
				
			}
		}
		if(i1>i2 && j2>j1){
		}
		if(i2>i1 && j1>j2){
			
		}
		if(i2>i1 && j2>j1){
			
		}
	}
}
	int pawnmove3(char chessboard[8][8],int i1,int j1,int i2,int j2){//Pawn Validation 1!
      int flag=0;
	  int condition1;
	  condition1=i2-i1;
	 if(j1!=j2 || condition1>2 || condition1<=0){
      	cout<<"Invalid move!"<<endl;
      	flag=1;
	  }
	  return flag;
}
int pawnmove4(char chessboard[8][8],int i1,int j1,int i2,int j2){
	int flag=0;
 	int condition1;
    condition1=i2-i1;
    static int c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0;
    if(j1==0 && condition1==2 && c1==2){
    	cout<<"Invalid pawn move 1!"<<endl;
    	flag=1;
	}
	if(j1==1 && condition1==2 && c2==2){
    	cout<<"Invalid pawn move 2!"<<endl;
    	flag=1;
	}
	if(j1==2 && condition1==2 && c3==2){
    	cout<<"Invalid pawn move 3!"<<endl;
    	flag=1;
	}
	if(j1==3 && condition1==2 && c4==2){
    	cout<<"Invalid pawn move 4!"<<endl;
    	flag=1;
	}
	if(j1==4 && condition1==2 && c5==2){
    	cout<<"Invalid pawn move 5!"<<endl;
    	flag=1;
	}
	if(j1==5 && condition1==2 && c6==2){
    	cout<<"Invalid pawn move 6!"<<endl;
    	flag=1;
	}
	if(j1==6 && condition1==2 && c7==2){
    	cout<<"Invalid move 7!"<<endl;
    	flag=1;
	}
	if(j1==7 && condition1==2 && c8==2){
    	cout<<"Invalid pawn move 8!"<<endl;
    	flag=1;
	}
    if(j1==0 && condition1==2){
    c1=2;
	}
	if(j1==1 && condition1==2){
    c2=2;
	}
	if(j1==2 && condition1==2){
    	c3=2;
	}
	if(j1==3 && condition1==2){
    	c4=2;
	}
	if(j1==4 && condition1==2){
    	c5=2;
	}
	if(j1==5 && condition1==2){
    	c6=2;
	}
	if(j1==6 && condition1==2){
    	c7=2;
	}
	if(j1==7 && condition1==2){
    	c8=2;
	}
	return flag;
}
int rookmove4(char chessboard[8][8],int i1,int j1,int i2,int j2){
	int flag=1;
	if(i1!=i2){
		flag=0;
	}
	return flag;
}
int rookmove5(char chessboard[8][8],int i1,int j1,int i2,int j2){
	int flag=1;
	if(j1!=j2){
		flag=0;
	}
	return flag;
}
int rookmove6(char chessboard[8][8],int i1,int j1,int i2,int j2){
	int flag=1;
	if(i1!=i2 && j1!=j2){
		flag=0;
	}
	return flag;
}
