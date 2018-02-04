#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<dos.h>

char graph[6][6];
int pl_c[6][6],x,y,color;

int t=0,w1=0,a1[4]={1,1,1,1},p,q,n,i21=0;
char b1[4];

void gotoxytext(int x, int y, const char *str);

void player(int color)                     //plus one and chain reaction
{

    if(graph[x-1][y-1]=='1')               //plus one at corners
     {
      if((x==1) && (y==1))
      {
       graph[x-1][y]++;
       graph[x][y-1]++;
       graph[x-1][y-1]='0';
       pl_c[x-1][y]=color;
       pl_c[x][y-1]=color;
       pl_c[x-1][y-1]=15;
      }

     else  if((x==1) && (y==6))
      {
       graph[x][y-1]++;
       graph[x-1][y-2]++;
       graph[x-1][y-1]='0';
       pl_c[x][y-1]=color;
       pl_c[x-1][y-2]=color;
       pl_c[x-1][y-1]=15;
      }


      else if((x==6) && (y==1))
      {
       graph[x-2][y-1]++;
       graph[x-1][y]++;
       graph[x-1][y-1]='0';
       pl_c[x-2][y-1]=color;
       pl_c[x-1][y]=color;
       pl_c[x-1][y-1]=15;
      }


      else if((x==6) && (y==6))
      {
       graph[x-1][y-2]++;
       graph[x-2][y-1]++;
       graph[x-1][y-1]='0';
       pl_c[x-1][y-2]=color;
       pl_c[x-2][y-1]=color;
       pl_c[x-1][y-1]=15;
      }

     else
     graph[x-1][y-1]++;

    }


    else if(graph[x-1][y-1]=='2')          //plus one at edges
    {
     if(x==1)
     {
      graph[x-1][y-2]++;
      graph[x-1][y]++;
      graph[x][y-1]++;
      graph[x-1][y-1]='0';
      pl_c[x-1][y-2]=color;
      pl_c[x-1][y]=color;
      pl_c[x][y-1]=color;
      pl_c[x-1][y-1]=15;
     }

     else if(x==6)
     {
      graph[x-1][y-2]++;
      graph[x-1][y]++;
      graph[x-2][y-1]++;
      graph[x-1][y-1]='0';
      pl_c[x-1][y-2]=color;
      pl_c[x-1][y]=color;
      pl_c[x-2][y-1]=color;
      pl_c[x-1][y-1]=15;
     }


     else if(y==1)
     {
      graph[x-2][y-1]++;
      graph[x-1][y]++;
      graph[x][y-1]++;
      graph[x-1][y-1]='0';
      pl_c[x-2][y-1]=color;
      pl_c[x-1][y]=color;
      pl_c[x][y-1]=color;
      pl_c[x-1][y-1]=15;
     }

     else if(y==6)
     {
      graph[x-2][y-1]++;
      graph[x-1][y-2]++;
      graph[x][y-1]++;
      graph[x-1][y-1]='0';
      pl_c[x-2][y-1]=color;
      pl_c[x-1][y-2]=color;
      pl_c[x][y-1]=color;
      pl_c[x-1][y-1]=15;
     }

    else
     graph[x-1][y-1]++;

   }

    else if(graph[x-1][y-1]=='3')               //chain reaction
     {
      graph[x-2][y-1]++;
      graph[x-1][y-2]++;
      graph[x-1][y]++;
      graph[x][y-1]++;
      graph[x-1][y-1]='0';
      pl_c[x-2][y-1]=color;
      pl_c[x-1][y-2]=color;
      pl_c[x-1][y]=color;
      pl_c[x][y-1]=color;
      pl_c[x-1][y-1]=15;
     }

  else                                     //plus one anywhere left
    graph[x-1][y-1]++;
    pl_c[x-1][y-1]=color;

    for(int k=0;k<10;k++)                  //multiple chain reaction
     for(int i=1;i<=6;i++)
      for(int j=1;j<=6;j++)
   {
    if(graph[i-1][j-1]=='2')
     {
      if((i==1) && (j==1))
      {
       graph[i-1][j]++;
       graph[i][j-1]++;
       graph[i-1][j-1]='0';
       pl_c[i-1][j]=color;
       pl_c[i][j-1]=color;
       pl_c[i-1][j-1]=15;
      }

     else  if((i==1) && (j==6))
      {
       graph[i][j-1]++;
       graph[i-1][j-2]++;
       graph[i-1][j-1]='0';
       pl_c[i][j-1]=color;
       pl_c[i-1][j-2]=color;
       pl_c[i-1][j-1]=15;
      }


      else if((i==6) && (j==1))
      {
       graph[i-2][j-1]++;
       graph[i-1][j]++;
       graph[i-1][j-1]='0';
       pl_c[i-2][j-1]=color;
       pl_c[i-1][j]=color;
       pl_c[i-1][j-1]=15;
      }


      else if((i==6) && (j==6))
      {
       graph[i-1][j-2]++;
       graph[i-2][j-1]++;
       graph[i-1][j-1]='0';
       pl_c[i-1][j-2]=color;
       pl_c[i-2][j-1]=color;
       pl_c[i-1][j-1]=15;
      }
    }


    else if(graph[i-1][j-1]=='3')
    {
     if(i==1)
     {
      graph[i-1][j-2]++;
      graph[i-1][j]++;
      graph[i][j-1]++;
      graph[i-1][j-1]='0';
      pl_c[i-1][j-2]=color;
      pl_c[i-1][j]=color;
      pl_c[i][j-1]=color;
      pl_c[i-1][j-1]=15;
     }

     else if(i==6)
     {
      graph[i-1][j-2]++;
      graph[i-1][j]++;
      graph[i-2][j-1]++;
      graph[i-1][j-1]='0';
      pl_c[i-1][j-2]=color;
      pl_c[i-1][j]=color;
      pl_c[i-2][j-1]=color;
      pl_c[i-1][j-1]=15;
     }


     else if(j==1)
     {
      graph[i-2][j-1]++;
      graph[i-1][j]++;
      graph[i][j-1]++;
      graph[i-1][j-1]='0';
      pl_c[i-2][j-1]=color;
      pl_c[i-1][j]=color;
      pl_c[i][j-1]=color;
      pl_c[i-1][j-1]=15;
     }

     else if(j==6)
     {
      graph[i-2][j-1]++;
      graph[i-1][j-2]++;
      graph[i][j-1]++;
      graph[i-1][j-1]='0';
      pl_c[i-2][j-1]=color;
      pl_c[i-1][j-2]=color;
      pl_c[i][j-1]=color;
      pl_c[i-1][j-1]=15;
     }

   }

    else if(graph[i-1][j-1]>='4')
     {
      graph[i-2][j-1]++;
      graph[i-1][j-2]++;
      graph[i-1][j]++;
      graph[i][j-1]++;
      graph[i-1][j-1]='0';
      pl_c[i-2][j-1]=color;
      pl_c[i-1][j-2]=color;
      pl_c[i-1][j]=color;
      pl_c[i][j-1]=color;
      pl_c[i-1][j-1]=15;
     }

 }

   for(i = 0 ; i < 6 ; i++)
    for(j = 0 ; j < 6 ; j++)                    //printing output
     {
      if(graph[i][j]=='0')
       pl_c[i][j]=15;
      textcolor(pl_c[i][j]);
      gotoxytext((4*(i+1)-1),2*(j+1),"");
      cprintf("%c",graph[i][j]);
      delay(10);
     }
}



void gotoxytext(int x, int y, const char *str)
{

    gotoxy(x,y);
    cout << str;
}









int main()
{
  clrscr();					  //the game begins
char begin;
cout<<"WELCOME TO THE CHAIN REACTION \n";
cout<<"press 'y' to continue the old game \n else press 'n' for a new game ";
cin>>begin;
clrscr();
  if(begin=='y')
  {
   char v;
   ifstream ifile("players.dat",ios::binary);
   ifile.get(v);
   n=v;
   ifile.close();

   for(int i = 0 ; i < 6 ; i++)
  for(int j = 0 ; j < 6 ; j++)
   pl_c[i][j]=15;

 for(i = 0 ; i < 6 ; i++)
  for(j = 0 ; j < 6 ; j++)
   graph[i][j]='0';



 ifstream jfile("cor.txt");
 for(i = 0 ;jfile.eof()!=1;i++,t++)
 {
    if(a1[i]!=1)
     goto great;
   char x11,y11;
   jfile.get(x11);
   jfile.get(y11);
   x=x11-48;
   y=y11-48;

    color=i+2;

    player(color);        //all if conditions
   great:
   if(i==n-1)
    i=-1;


 if(t>=n)    				//winnnnerrrrr!!!!
 {
  int w;
  for(int l=0;l<4;l++)
  {
   w=0,w1=0;
   for(p=0;p<6;p++)
    for(q=0;q<6;q++)
    {
     if(pl_c[p][q]==l+2)                     //checking dead
     w1++;
     }
     if(w1==0)                  //deleted the player
      a1[l]--;
  }
 }         //if(t>=n)
 }    //for

 jfile.close();


 for(char a2 = 1 ; a2 <= 6 ; a2++)
  {
   gotoxy(31,2*(a2));
   cout<<(char)(a2+48);
  }
  for(a2 = 1 ; a2 <= 6 ; a2++)
  {
   gotoxy(4*(a2)-1,16);
   cout<<(char)(a2+48);
  }
 gotoxytext(31,16,"x/y");

 gotoxytext(40,10,"Input '9 9' to exit");

 gotoxytext(40,2,"For each cell in the board, we define a");
 gotoxytext(40,3,"critical no. The critical no. is equal");
 gotoxytext(40,4,"to the number of orthogonally adjacent");
 gotoxytext(40,5,"cells. That would be 4 for usual cells,");
 gotoxytext(40,6,"3 for cells in the edge and 2 for cells");
 gotoxytext(40,7,"in the corner.");

 //
 i--;

 for(;;i++,t++)
  {
    if(a1[i]!=1)
     goto awesome1;

    int p,q;
    do{
    gotoxy(1,20);
    cout<<"\n Player "<<i+1<<"\nEnter the position to place in the form 'x,y'\n";
    cin>>x>>y;
    if(x==9&y==9)
	goto skip;
    { ofstream file("cor.txt",ios::app);
     file.put(x+48);
     file.put(y+48);
    file.close();
    }
    skip:
    if(x==9&&y==9)
     exit(0);
   }while((pl_c[x-1][y-1]!=15)&&(pl_c[x-1][y-1]!=i+2));

    color=i+2;

    player(color);        //all if conditions
   awesome1:
   if(i==n-1)
    i=-1;


  if(t>=n)    				//winnnnerrrrr!!!!
  {int w;
  for(int l=0;l<4;l++)
  {
   w=0,w1=0;
   for(p=0;p<6;p++)
    for(q=0;q<6;q++)
    {
     if((pl_c[p][q]==l+2)||(pl_c[p][q]==15))   //checking winner
      w++;
     if(pl_c[p][q]==l+2)                     //checking dead
      w1++;
     }
     if(w1==0)                  //deleted the player
      a1[l]--;
     if(w==36)                   //declaration of awesomness
      {
       gotoxy(45,12);
       cout<<"Player "<<l+1<<" WINS";
       goto label1;
      }
   }
  }
  }

// i21=i;
 }//if's brack


  /////////changeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee


 if(begin=='n')
 {
   do{                                       //input no. of players
   gotoxy(1,20);
   cout<<"\n Enter no. of players ";
   cin>>n;
  }while(n==1);
  ofstream ofile("players.dat",ios::binary);              //input in the file players
  ofile.put(n);
  ofile.close();

	       //real  work!!!!

 clrscr();

 for(char a2 = 1 ; a2 <= 6 ; a2++)
  {
   gotoxy(31,2*(a2));
   cout<<(char)(a2+48);
  }
  for(a2 = 1 ; a2 <= 6 ; a2++)
  {
   gotoxy(4*(a2)-1,16);
   cout<<(char)(a2+48);
  }
 gotoxytext(31,16,"x/y");

 gotoxytext(40,10,"Input '9 9' to exit");

 gotoxytext(40,2,"For each cell in the board, we define a");
 gotoxytext(40,3,"critical no. The critical no. is equal");
 gotoxytext(40,4,"to the number of orthogonally adjacent");
 gotoxytext(40,5,"cells. That would be 4 for usual cells,");
 gotoxytext(40,6,"3 for cells in the edge and 2 for cells");
 gotoxytext(40,7,"in the corner.");

 for(int i = 0 ; i < 6 ; i++)
  for(int j = 0 ; j < 6 ; j++)
   pl_c[i][j]=15;

 for(i = 0 ; i < 6 ; i++)
  for(j = 0 ; j < 6 ; j++)
   graph[i][j]='0';


 ofstream file("cor.txt");
 for(i=0;;i++,t++)
  {
    if(a1[i]!=1)
     goto awesome;

    int p,q;
    do{
    gotoxy(1,20);
    cout<<"\n Player "<<i+1<<"\nEnter the position to place in the form 'x,y'\n";
    cin>>x>>y;
    if(x==9&y==9)
	goto skip2;

     file.put(x+48);
     file.put(y+48);


     skip2:
    if(x==9&&y==9)
     goto ext;
   }while((pl_c[x-1][y-1]!=15)&&(pl_c[x-1][y-1]!=i+2));

    color=i+2;

    player(color);        //all if conditions
   awesome:
   if(i==n-1)
    i=-1;


  if(t>=n)    				//winnnnerrrrr!!!!
  {int w;
  for(int l=0;l<4;l++)
  {
   w=0,w1=0;
   for(p=0;p<6;p++)
    for(q=0;q<6;q++)
    {
     if((pl_c[p][q]==l+2)||(pl_c[p][q]==15))   //checking winner
      w++;
     if(pl_c[p][q]==l+2)                     //checking dead
      w1++;
    }
     if(w1==0)                  //deleted the player
      a1[l]--;
     if(w==36)                   //declaration of awesomness
      {
       gotoxy(45,12);
       cout<<"Player "<<l+1<<" WINS";
       goto label;
      }
   }//for
  }//if(t and n)
  }
  ext:
 file.close();
 exit(0);
 }
 label:
 label1:
 getch();
 return 0;
}