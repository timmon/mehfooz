#include<iostream.h>    //for cin, cout 
#include<conio.h>       //for getche() 
#include<ctype.h>       //for tolower() function 
#include<stdlib.h>      //for itoa() 
#include<GRAPHICS.H>    //to  load graphics driver 
#include<dos.h>         //for delay() function
/*_________________________________________________________________________*/
/*_________________________________________________________________________*/
//These Functions prototypes are, for stack function.

int col=60 , row = 417 ,n ,x=60 , y=417  ,size=10 ,arr[10]={12,56,23,46,32,89,11,99,12,66} , count =   0, top = 0;

//Global Variables
char string[45]; 
void push( ); 
void pop( ); 
void stack(); 
void loadgraph(); 

void main() 
{ 
clrscr(); 
char ch; 
loadgraph(); 
setbkcolor(0); 
setcolor(2); 

//This do while; loop will execute untill character 'x' is not Entered
do{ 
 gotoxy(37,5); 
 cout<<"Menu"; 
 gotoxy(30,6); 
 cout<<"Stack               [s]"; 
 gotoxy(30,7); 
 cout<<"Queue               [Q]"; 
 gotoxy(30,8); 
 cout<<"Exit                [x]"; 
 gotoxy(25,9); 
 cout<<"\t\t\t\t"; 
 gotoxy(30,10); 
 cout<<"Enter Option        [ ]\b\b"; 
 ch=getche(); 
 //Converts, Entered char into lower one 
 ch = tolower(ch); 
 gotoxy(30,15); 
 if(ch=='s') 
 // call to stack function 
 stack(); 
 elseif(ch=='q') 
 //call to queue function 
 queue(); 
 cleardevice(); 

}while(ch!='x'); 
 cleardevice(); 
 closegraph(); 
} 

//This function loads , graph driver and mode

void loadgraph() 
{ 
  clrscr(); 
  int driver = DETECT, mode, errorcode; 
  initgraph(&driver, &mode, "c:\\tc\\bgi"); 
  errorcode = graphresult(); 
  if (errorcode != grOk) 
     { 
    cout<<"Graphics error: \n"<<(grapherrormsg(errorcode)); 
    cout<<"Press any key to halt:"; 
    getch(); 
    exit(1); 
    } 
} 


void stack() 
{ 
  cleardevice(); 
  /*-------------------------------------------------------------*/ 
    outtextxy(400,465,"Babar saeed"); 
    outtextxy(500,465,"32"); 
    outtextxy(545,465,"QAU, ISB"); 
  /*-------------------------------------------------------------*/
  //Displays stacks Menu 
  moveto(400,60); 
  outtext("STACK'S OPERATIONS"); 
  moveto(400,80); 
  outtext("PUSH           [p]"); 
  moveto(400,100); 
  outtext("POP            [o]"); 
  moveto(400,120); 
  outtext("EXIT           [x]"); 
  //End of stack Menu
  /*-----------------------------------------------------------------*/
  /*-----------------------------------------------------------------*/
  // displays value of top in start of program 
  moveto(300,425); 
  outtext("Top"); 
  itoa(top,string,10); 
  outtextxy(308,450,string); 
  /*-----------------------------------------------------------------*/
  //Dislplays stack figure 
  setbkcolor(0); 
  setcolor(14); 
  outtextxy(55,26,"STACK"); 
  line(30,40,30,440); 
  int r=40; 
  for(int i = 1 ;i<12 ;i++) 
   { 
     line(30,r,110,r); 
     r+=40; 
   } 
  line(110,40,110,440); 
  r = 55; 
  // This loop Displays stack's boxes Number
  for( i = 10 ;i>=1 ;i--) 
   { 
     moveto(10,r); 
     itoa(i,string,10); 
     outtext(string)  ; 
     r+=40; 
   } 
   //These four statements makes a box 
   line(165,440,210,440); 
   line(165,440,165,460); 
   line(210,440,210,460); 
   line(165,460,210,460); 
   setfillstyle(0, getmaxcolor()); 
   // This do while loop , reads coorect option (push, pop, Exit) 
   // And Makes calls to push, pop functions
   char ch[2]; 
   do 
    { 
     moveto(400,140); 
     outtext("ENTER OPTION   "); 
     ch[0]=getche(); 
     //convert entered option in lower character 
     ch[0] = tolower(ch[0]); 
     if(ch[0]=='p') 
    {  // start of outer if
	// displays p 
       outtext("p"); 
       // make a delay 
       delay(500); 
       // draw a bar to remove p 
       bar(getx()-30,gety(),getx()+2,gety()+20); 
       /*--------------------------------------------------------*/
	   // if size of stack's remaining boxese less than one
	   // than stack is overflow
	   if(size<1) 
        { //start of nested if
		for(int i = 0 ;i<4 ; i++){ 
          moveto(420,170); 
          outtext("Stack Overflow "); 
          delay(1000); 
          setfillstyle(0, getmaxcolor()); 
          bar(420 ,165 ,630 ,180); 
          delay(500);} 
         }//end of nested if
		 /*--------------------------------------------------------*/
		 // if there are stack's boxes remains(if size>1)
		 else 
         { 
          //start of nested else part
		  // decrease stack remaining boxes 
          size--; 
          // increase top position , where last item is Inserted 
          top++; 
          // call to push function 
          push(); 
          // bar removes last displayes value 
          bar(290,440,350,479); 
          // convert integer value to assci value
		  /* becuse outtext/outtextxy function require string as third argument */ 
          itoa(top,string,10); 
          outtextxy(308,447,string); 
          }//End of Nested else Part 
    }//end  of Nested if 
	else if(ch[0]=='o') 
    {  // start of outer if's elseif part
	// Displays o , and remove it after a delay 
       outtext("o"); 
       delay(500); 
       bar(getx()-30,gety(),getx()+10,gety()+20); 
       /*--------------------------------------------------------*/
	   /* if all boxes of stack are empty than display message of overflow */
	   if(size==10) 
         { 
          for(int i = 0 ;i<4 ; i++){ 
          moveto(410,170); 
          outtext("Stack, Underflow "); 
          delay(1000); 
          setfillstyle(0, getmaxcolor()); 
          bar(330 ,165 ,630 ,180);   // (left, top)     ³ upper left corner 
          delay(500);  }                //        (right, bottom) ³ lower right corner*/ 
         } 
       /*--------------------------------------------------------*/
	   /*if there are some boxes of stack filled than call pop function */
	   else 
          { 
          // update top's value 
          top--; 
          pop(); 
          //display value of updated top 
          bar(290,440,350,479); 
          itoa(top,string,10); 
          outtextxy(308,447,string);} 
          } 
         /*------------------------------------------------------*/ 
}while(ch[0]!='x'); 
} 

// this function pushes values in stack
void push() 
{ 
   int a=178 ,  b=425    ; 
   /*---------------------------------------------------------------*/
   //displays the value that is to be pushed in stack 
   moveto(178,447); 
   itoa(arr[count],string,10); 
   outtext(string); 
   /*--------------------------------------------------------------*/
   /*after a delay remove the value , and display the value in box that is to pushed next */ 
   delay(10); 
   bar(170,446,208,455); 
   itoa(arr[count+1],string,10); 
   moveto(178,447); 
   outtext(string); 
   /*--------------------------------------------------------------*/ 
   moveto(a,b); 
   /*this loop displays and moves the value untill top row position is not found */
   while(gety()!=y) 
     { 
      setfillstyle(0, getmaxcolor()); 
      circle(a+6,b+3,12); 
      itoa(arr[count],string,10); 
      outtext(string); 
      delay(10); 
      setfillstyle(0, getmaxcolor()); 
      bar(170 ,gety()-20 ,200 ,gety()+14); 
      moveto(a,b); 
      b--; 
     } 
   setfillstyle(0, getmaxcolor()); 
   circle(a+6,b+3,9); 
   outtext(string); 
   moveto(125,b); 
   /*--------------------------------------------------------------*/
   //This loop displays the animated arrow toward top box os stack
   for(int j   =0 ;j<6 ; j++) 
      { 
    outtext("®"); 
    delay(100); 
    setfillstyle(0, getmaxcolor()); 
    bar(getx()-3 ,gety() ,getx() ,gety()+8); 
    delay(100); 
      } 
   /*--------------------------------------------------------------*/
   delay(100); 
   //Remove last displayed value 
   setfillstyle(0, getmaxcolor()); 
   bar(getx()-48 ,gety() ,getx() ,gety()+8); 
   /*--------------------------------------------------------------*/
   delay(100);
   delay(200); 
   /*while required coloumn of top box is not found , Display and move value to required colimn */
   while(getx()!=x+60) 
     { 
      setfillstyle(0, getmaxcolor()); 
      circle(a+6,b+3,9); 
      itoa(arr[count],string,10); 
      outtext(string); 
      delay(10); 
      setfillstyle(0, getmaxcolor()); 
      bar(getx()-20 ,gety()-10 ,getx()+70 ,gety()+20); 
      moveto(a,b); 
      a--; 
     } 
   /*--------------------------------------------------------------*/
   delay(100); 
   //display the value in required box 
   moveto(60,gety()); 
   outtext(string); 
   count++; 
   // to have cursor position in top box of stack 
   y = y-40; 
} 
/////////////////////////END OF PUSH FUNCTION///////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

/*this function pops/displays values from stack and moves value  untill doesn't get posiotion to Inside value's box */
void pop() 
{ 
   int a=120, b ; 
   //Update row , from where next value is to be poped 
   y = y + 40   ; 
   b = y        ; 
   moveto(120,y); 
   /*-------------------------------------------------------------*/
   /* This loop displayes the arrows towards the stack's box from where , value is to be poped */
   for(int j=0 ;j<6 ; j++) 
    { 
     outtext("®"); 
     delay(100); 
     setfillstyle(0, getmaxcolor()); 
     bar(getx()-3 ,gety() ,getx() ,gety()+8); 
     delay(100); 
    } 
   /*-------------------------------------------------------------*/
   // Remove last displayed arrow 
   delay(100); 
   setfillstyle(0, getmaxcolor()); 
   bar(getx()-48 ,gety() ,getx() ,gety()+8); 
   delay(200); 
   moveto(60,gety()); 
   setfillstyle(0, getmaxcolor()); 
   bar(getx()-10 ,gety()-3 ,getx()+20 ,gety()+8); 
   /*-------------------------------------------------------------*/
   /*This loop will display the value untill poped value is not positioned in values box column  */ 
   delay(500); 
   while(getx()!=178) 
     { 
      setfillstyle(0, getmaxcolor()); 
      circle(a+6,b+3,12); 
      moveto(a,gety()); 
      itoa(arr[count-1],string,10); 
      outtext(string); 
      delay(10); 
      setfillstyle(0, getmaxcolor()); 
      bar(getx()-25 ,gety()-10 ,getx()+30 ,gety()+20); 
      a++; 
     } 
   /*-------------------------------------------------------------*/
   /*This loop will display the value untill poped value is not positioned in values box Row */ 
   delay(500); 
   while(gety()!=430) 
     { 
      setfillstyle(0, getmaxcolor()); 
      circle(a+21,b+3,7); 
      moveto(178,b); 
      itoa(arr[count-1],string,10); 
      outtext(string); 
      delay(10); 
      setfillstyle(0, getmaxcolor()); 
      bar(getx()-30 ,gety()-10 ,getx()+20 ,gety()+9); 
      b++; 
     } 
   /*-------------------------------------------------------------*/
   // These statements displyes poped values in vlaue box 
     delay(10); 
     moveto(178,447); 
     bar(170,446,208,455); 
     count--; 
     moveto(178,447); 
     itoa(arr[count],string,10); 
     outtext(string); 
     size++; 
   /*-------------------------------------------------------------*/ 
} 