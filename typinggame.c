#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>
#define SCREEN_WIDTH 90
#define SCREEN_HEIGHT 26
#define WIN_WIDTH 70 
#define MAX_WORD 1000
#define NUM_WORDS 30
int score =0;
char *test;
int pointr=0;
int in[15];
int hight=0;
int type=0;
char mobham[3][10]={"rasoul","typinggame","!@#+_)"};
int mobhamPOINTER=0;
char username1[10];
char level1[10];
int point1;
time_t now;
int left=0,right=0,defaultt=0;
// ------------------------------------------------------
struct history
{
    char username[10];
    char level[10];
    int point;
    char idrr[10];
};






struct node{  
    char  *data;  
    struct node *previous;  
    struct node *next;  
};      
 
// ----------------------------------
DWORD WINAPI keypress_callback( LPVOID args ){
  void (*callback)(char) = (void (*)(char))((void *)(args));

  while(1)
    callback(getch());

  return 0;
}

HANDLE start_listening(void (*callback)(char)){
  HANDLE thread = CreateThread(NULL, 0, keypress_callback, (void *)(callback), 0, NULL);
  return thread;
}





//.......................................................................................................................................................................
 COORD coord={0,0};
 void gotoxy(int x,int y);
void gotoxy(int x,int y)//function to set the cursor position(gotoxy())
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void writech(int col, int row, char *c) {
    gotoxy(col, row);
    WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), c, strlen(c), NULL, NULL);
}
//.......................................................................................................................................................................
void setcolor(int ForgC) //function to change setcolor
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }
// -------------------------------------------------------------------------------------------------------

 void gameover();



  void updateScore(){
	gotoxy(WIN_WIDTH + 7, 5);printf("score: %d\n",score);
}


void drawBorder(){  




	for(int i=0; i<SCREEN_WIDTH; i++){ 
		gotoxy(i,SCREEN_HEIGHT); printf("*");
	}
	
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(0,i); printf("*");
		gotoxy(SCREEN_WIDTH,i); printf("*");
	}
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(WIN_WIDTH,i); printf("*");
	}

    updateScore();


}
//Represent the head and tail of the doubly linked list  
struct node *head, *tail = NULL;  
   
//addNode() will add a node to the list  
void addNode(char *data) {  
    //Create a new node  
    struct node *newNode = (struct node*)malloc(sizeof(struct node));  
    newNode->data = data;  
      
    //If list is empty  
    if(head == NULL) {  
        //Both head and tail will point to newNode  
        head = tail = newNode;  
        //head's previous will point to NULL  
        head->previous = NULL;  
        //tail's next will point to NULL, as it is the last node of the list  
        tail->next = NULL;  
    }  
    else {  
        //newNode will be added after tail such that tail's next will point to newNode  
        tail->next = newNode;  
        //newNode's previous will point to tail  
        newNode->previous = tail;  
        //newNode will become new tail  
        tail = newNode;  
        //As it is last node, tail's next will point to NULL  
        tail->next = NULL;  
    }  
}  
   
//display() will print out the nodes of the list  
void display(float time,float x,int y) {
    int lose=0;
    int count=0;
    //Node current will point to head  
    struct node *current = head;
    head->previous=NULL;  
     struct node *ptr=(struct node*)malloc(sizeof(struct node));
      struct node *p=(struct node*)malloc(sizeof(struct node));

    if(head == NULL) {  
        printf("List is empty\n");  
        return;  
    }  
    // printf("Nodes of doubly linked list: \n");  
     Sleep(500)  ;
        // system("cls");
    while(current != NULL) {  
        lose+=1;
        count+=1;

        gotoxy(0,0);
        for(ptr=current;ptr;ptr=ptr->previous)
        {
            if (ptr->previous==NULL)
            {
                gotoxy(32,hight);
                test=ptr->data;
                if(hight>=7 &&strcmp(ptr->data,"010101010101010")==0)
                {
                test=ptr->data=mobham[mobhamPOINTER];
                mobhamPOINTER+=1;
                }
                for (int i = 0; i < strlen(test); i++)
        {
            if(in[i]==2)
            {
                setcolor(4);
                printf("%c",test[i]);
            }
            else if(in[i]==1)
            {
                setcolor(6);
                printf("%c",test[i]);
            } 
            else
            {
              setcolor(15);
              printf("%c",test[i]);
            }
            

            
        }
        hight+=1;
        
            for (int j = 0; j < strlen(test); j++)
            {
                if(in[j]!=2)
                {   type=0;
                    break;
                }
                else
                    type=1;
            }

            if(type==1)
            {
                type=0;
                hight-=1;
                for (int j = 0; j < strlen(test); j++)
                in[j]=0;
                pointr=0;
                count-=1;
                if(strlen(test)==6 || strlen(test)==7 || strlen(test)==10)
                score+=4;
                else if(strlen(test)<=4)
                score+=1;
                else if(strlen(test)<=5)
                score+=3;
                else if(strlen(test)<=8)
                score+=2;
                ptr=ptr->next;
                test=ptr->data;
                ptr->previous=NULL;
                break;
            }
            


            }
            
            
            else
            {
                setcolor(15);
            printf("\t\t\t\t%s\n", ptr->data);
            }
        } 

        // Sleep(time);
        if(lose%y==0)
        time*=x;
        Sleep(time);
        system("cls");
        setcolor(15);
        drawBorder();


        current = current->next;  

        if(count==26)
        return ;
        
    }  
}  
   






void easy()
{
    char line[128],zobale[128];
       FILE *fp,*fp2,*fp3;
    int n=1;
    
    //Add nodes to the list  
     fp = fopen("normal.txt", "r");
     fp2 = fopen("Long.txt", "r");
     fp3 = fopen("hard.txt", "r");
        drawBorder();
        
    while(n<=50){
        
        for(int i=n;i<=10;i++)
        {
            fscanf(fp, "%s", &line);
            addNode(strdup(line));
            fgetc(fp);
            n++;
            
        }
        for(int i=1;i<=5;i++)
        {
            if(n==15)
            {
                addNode("010101010101010");
                n++;
            }
            else
            {
           if(i%2==1) 
           {
                fscanf(fp2, "%s", &line);
                addNode(strdup(line));
                fgetc(fp2);
                 n++;
                 continue;
           }
            else
            {    
            fscanf(fp, "%s", &line);
            addNode(strdup(line));
            fgetc(fp);
             n++;
            continue;
             }
            }
        }
        for(int i=1;i<=35;i++){
         if(n==30 || n==20)
            {
                addNode("010101010101010");
                n++;
            }
            else
            {
        fscanf(fp3, "%s", &line);
        addNode(strdup(line));
        fgetc(fp3);
        n++;
        fscanf(fp2, "%s", &line);
        addNode(strdup(line));
        fgetc(fp2);
        n++;
        fscanf(fp, "%s", &line);
        addNode(strdup(line));
        fgetc(fp);
        n++;
            }
        }
     }
  
    //Displays the nodes present in the list  
    display(10000,.8,10);
    time(&now);
    gameover();
}
void medium()
{
    char line[128],zobale[128];
       FILE *fp,*fp2,*fp3;
    int n=1;
    
    //Add nodes to the list  
     fp = fopen("normal.txt", "r");
     fp2 = fopen("Long.txt", "r");
     fp3 = fopen("hard.txt", "r");
        drawBorder();
        
     while(n<=50){
        for(int i=n;i<=5;i++)
        {
             
        fscanf(fp, "%s", &line);
        addNode(strdup(line));
        fgetc(fp);
        n++;
            
        }
        for(int i=1;i<=10;i++)
        {
            if(n==15)
            {
                addNode("010101010101010");
                n++;
            }
            else
            {
                if(i%2==1) 
           {
         fscanf(fp2, "%s", &line);
        addNode(strdup(line));
        fgetc(fp2);
        n++;
        continue;
           }
           else
           {
        fscanf(fp, "%s", &line);
        addNode(strdup(line));
        fgetc(fp);
        n++;
        continue;
           }
            }
        }
        for(int i=1;i<=35;i++){
             if( n==20 || n==30)
            {
            addNode("010101010101010");
                n++;
            }
            else
            {
        fscanf(fp3, "%s", &line);
        addNode(strdup(line));
        fgetc(fp3);
        n++;
        fscanf(fp2, "%s", &line);
        addNode(strdup(line));
        fgetc(fp2);
        n++;
        fscanf(fp, "%s", &line);
        addNode(strdup(line));
        fgetc(fp);
        n++;
            }
        }
     }
    //Displays the nodes present in the list  
    display(8000,.7,10);
    time(&now);  
    gameover();

}
void hard()
{
    char line[128],zobale[128];
       FILE *fp,*fp2,*fp3;
    int n=1;
    
    //Add nodes to the list  
     fp = fopen("normal.txt", "r");
     fp2 = fopen("Long.txt", "r");
     fp3 = fopen("hard.txt", "r");
        drawBorder();
        
    while(n<=50){
        
        for(int i=n;i<=5;i++)
        {
           
        fscanf(fp, "%s", &line);
        addNode(strdup(line));
        fgetc(fp);
        n++;
            
        }
        for(int i=1;i<=5;i++)
        {
            if(n==7)
            {
                addNode("010101010101010");
                n++;
            }
            else
            {
                if(i%2==1) 
           {
         fscanf(fp2, "%s", &line);
        addNode(strdup(line));
        fgetc(fp2);
        n++;
        continue;
           }
           else
           {
        fscanf(fp, "%s", &line);
        addNode(strdup(line));
        fgetc(fp);
        n++;
        continue;
           }
            }
        }
        for(int i=1;i<=40;i++){
             if(n==15 ||  n==25)
            {
                addNode("010101010101010");
                n++;
            }
            else
            {
        fscanf(fp3, "%s", &line);
        addNode(strdup(line));
        fgetc(fp3);
        n++;
        fscanf(fp2, "%s", &line);
        addNode(strdup(line));
        fgetc(fp2);
        n++;
        fscanf(fp, "%s", &line);
        addNode(strdup(line));
        fgetc(fp);
        n++;
            }
        }
     }
   
    //Displays the nodes present in the list  
    display(5000,.6,17);
    time(&now);  
    gameover();

}






int level()
{
    int i;
    do{
          system("cls");

    
      setcolor(13);
    printf("\n\n\n\n\n\t\t\t GAME LEVEL");
          setcolor(4);
printf("\n\t\t\t=====================");
      setcolor(13);
printf("\n\n\n\n\t\t\tSelect the GAME LEVEL...!!");
if(getch()==13)
  system("cls");
        setcolor(13);
  printf("\n\n\n\t\t\t1. easy\t\t2. medium\t\t3. hard");
printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",& i);
    system("cls");
          setcolor(15);}while(i!=1 && i!=2 && i!=3);
          int j;
           do{
          system("cls");

    
      setcolor(13);
    printf("\n\n\n\n\n\t\t\t right or left");
          setcolor(4);
printf("\n\t\t\t=====================");
      setcolor(13);
printf("\n\n\n\n\t\t\tSelect the YOUR favorite...!!");
if(getch()==13)
  system("cls");
        setcolor(13);
  printf("\n\n\n\t\t\t1. right\t2. left\t\t3. default");
printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",& j);
    system("cls");
          setcolor(15);}while(j!=1 && j!=2 && j!=3);

          if(j==1)
          right=1;
          else if(j==2)
          left=1;
          else
          defaultt=1;


    return i;
}
// FILE KALAMAT----------------------------------------------------------------------------------------------
void fillNormal()
{
 char    str[2];
    FILE    *fptr;
    int     i;
    int     num;
    char    num2;
    i = 0;
    

    fptr = fopen("normal.txt", "a+");
    if (fptr == NULL)
    {
        printf("ERROR Creating File!");
        exit(1);
    }
 
    
    while (str[i] != '\0')
    {

        num = rand() % 26;
        if(left==1 && (num<=8 ||num>=16))
        {
        num2 = num + 'a';
        str[i] = num2;
        i += 1;
        }
       else if(right==1 && (num>8 && num<16))
        {
        num2 = num + 'a';
        str[i] = num2;
        i += 1;
        }
        else if(defaultt==1)
        {
        num2 = num + 'a';
        str[i] = num2;
        i += 1;
        }


    }
  
  



    
    // puts(str);
    fprintf(fptr,"%s\n", str);
    // strcat(mobham,str);
    fclose(fptr);

}

void fillLong()
{
 char    str[6];
    FILE    *fptr;
    int     i;
    int     num;
    char    num2;
    i = 0;

    fptr = fopen("Long.txt", "a+");
    if (fptr == NULL)
    {
        printf("ERROR Creating File!");
        exit(1);
    }
    
    
    while (str[i] != '\0')
    {
        num = rand() % 26;
         if(left==1 && (num<=8 || num>=16))
        {
        num2 = num + 'a';
        str[i] = num2;
        i += 1;
        }
       else if(right==1 && (num>8 &&num<16))
        {
        num2 = num + 'a';
        str[i] = num2;
        i += 1;
        }
        else if(defaultt==1)
        {
        num2 = num + 'a';
        str[i] = num2;
        i += 1;
        }
    }
    // puts(str);
    fprintf(fptr,"%s\n", str);    
    // strcpy(mobham[2][0],str);
    fclose(fptr);

}

void fillHard()
{
 char    str[3];
    FILE    *fptr;
    int     i;
    int     num;
    char    num2;
    i = 0;

    fptr = fopen("hard.txt", "a+");
    if (fptr == NULL)
    {
        printf("ERROR Creating File!");
        exit(1);
    }
    
    
    while (str[i] != '\0')
    {
        num = (rand() % 30) +34;
        if(left==1 && ((num>=33 && num<39 && num!=34 )||(num>=49 && num<=55)|| num==64))
        {
        num2 = num ;
        str[i] = num2;
        i += 1;
        }
        else if(right==1 && ((num>=39 && num<=48 )||(num>=56 && num<=63)|| num==34))
        {
        num2 = num ;
        str[i] = num2;
        i += 1;
        }
        else if(defaultt==1)
        {
        num2 = num ;
        str[i] = num2;
        i += 1;
        }
    }
    // puts(str);
    fprintf(fptr,"%s\n", str);
    // strcpy(mobham[3][0],str);
    fclose(fptr);

}

void freefileA(){
  FILE *a; 
      a=fopen("normal.txt","w");
      fprintf(a,"%c", ' ');
          fclose(a);
}
void freefileB()
{
  FILE *b;
    b=fopen("Long.txt","w");
      fprintf(b,"%c", ' ');
          fclose(b);
}
void freefileC()
{
  FILE *c;
 c=fopen("hard.txt","w");
      fprintf(c,"%c", ' ');
          fclose(c);
}

// ---------------------------------------------------------------------------------------------------

void userlogin(void);

struct user{
    char username[10];
    char password[10];
}*pUser;

void my_callback_on_key_arrival(char c);

void history()
{
    struct history historygame[1000];
    FILE *IDR =fopen("hard.txt","r");
    char idr[10];
    fscanf(IDR,"%s",idr);
    fclose(IDR);
    
    int history_num=0;
    struct history tmp1,tmp2;
    
    
    FILE *his;
    his=fopen("history.txt","a+");
    fprintf(his,"%s %s %d %s\n",username1,level1,point1,idr);
    fclose(his);

    gotoxy(0,12);
    printf("\t\thistory of user %s in typing game :\n\n",username1);
    FILE *his2;
    his2=fopen("history.txt","r");
    for(int i=0;;i++)
    {   setcolor(13);
        fscanf(his2,"%s %s %d %s",historygame[i].username,historygame[i].level,&historygame[i].point,historygame[i].idrr);
        fgetc(his2);
        history_num=i+1;
        if(strcmp(historygame[i].username,username1)==0 &&strcmp(historygame[i].level,level1)==0 && historygame[i].point==point1 && strcmp(idr,historygame[i].idrr)==0)
        break;
    }
    fclose(his2);

    for (int i = 0; i < history_num; i++)
    {
        for (int j = i+1; j < history_num; j++)
        {


             if((strcmp(historygame[i].level,"easy")==0&&(strcmp(historygame[j].level,"hard")==0||strcmp(historygame[j].level,"medium")==0))||(strcmp(historygame[i].level,"medium")==0 &&strcmp(historygame[j].level,"hard")==0))
                    {
                         tmp2=historygame[i];
                        historygame[i]=historygame[j];
                        historygame[j]=tmp2;
                    }
           
            else if(strcmp(historygame[i].level,historygame[j].level)==0)
            {
                 if(historygame[i].point<historygame[j].point)
            {
                tmp1=historygame[i];
                historygame[i]=historygame[j];
                historygame[j]=tmp1;
            }
            }
        }
        
    }
    for (int i = 0; i < history_num; i++)
    {
        if(strcmp(historygame[i].username,username1)==0 )
        {
            if(strcmp(historygame[i].idrr,idr)==0)
            {
                setcolor(4);
                printf("\t\t%s\t\t %s\t\t %d\t\t%s",historygame[i].username,historygame[i].level,historygame[i].point,ctime(&now));
                setcolor(13);
            }
            else
                printf("\t\t%s\t\t %s\t\t %d\n",historygame[i].username,historygame[i].level,historygame[i].point);
        }
    }


        freefileA();freefileB();freefileC();

}


int main()
{ 
    system("cls"); 
    system("cls");
    setcolor(13);
	gotoxy(WIN_WIDTH + 5, 2);printf("Typing GAME");
	gotoxy(WIN_WIDTH + 6, 4);printf("----------");
	gotoxy(WIN_WIDTH + 6, 6);printf("----------");
	gotoxy(18, 5);printf("Press any key to start");
	getch();
    gotoxy(18, 5);printf("                      ");
    setcolor(15);
    userlogin();
    int levelGAME=level();
      srand(time(NULL));

  for(int i=0;i<100;i++)
  {
  fillNormal(); fillLong(); fillHard();
  }
    

    HANDLE thread_id =start_listening(my_callback_on_key_arrival);

      switch(levelGAME)
    {
        case 1:   easy();      strcpy(level1,"easy");     point1=score;  break;
        case 2:   medium();    strcpy(level1,"medium");   point1=score; break;
        case 3:   hard();      strcpy(level1,"hard");     point1=score; break;
    }
    history();
    WaitForSingleObject(thread_id,INFINITE);
    return 0;


}

void my_callback_on_key_arrival(char c)
{
if(strcmp(test,"010101010101010")!=0){
  
     if(c==8)
    {
        if(pointr-1>=0)
        {
              pointr-=1;
            in[pointr]=0;
        }          
    }
    else if(c==test[pointr])
    {   
             in[pointr]=2;
            pointr+=1;
    }
    else if(c!=test[pointr] )
    {
        if(pointr+1<strlen(test))
        {
             in[pointr]=1;
             pointr+=1;
        }
    }
}
}

void userlogin(void){
    FILE *fp;
    char uName[10], pwd[10];int i;char c;int q=0,Q=0;

    pUser=(struct user *)malloc(sizeof(struct user));
    do{
        i=0;
    system("cls");
            setcolor(13);
            printf("\n\n\n\n\n\t\t\tWELCOME TO MY GAME");
            setcolor(4);
            printf("\n\t\t\t=====================");
            setcolor(13);
            printf("\n\n\n\n\t\t\tPress Enter to proceed...!!");
        if(getch()==13)
            system("cls");
            setcolor(13);
            printf("\n\n\n\t\t\t1. LOGIN\t\t2. REGISTER");
            printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
            scanf("%d",& i);
            system("cls");
            setcolor(15);}while(i!=1 && i!=2);
    switch(i){
        case 1:
            if ( ( fp=fopen("user.txt", "r+")) == NULL) {
                if ( ( fp=fopen("user.txt", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
            }
            setcolor(6);
            printf("\n\n\n\t\t\t\tUsername: ");
            scanf("%9s",uName);
            system("cls");
            printf("\n\n\n\t\t\t\tPassword: ");
            scanf("%9s",pwd);
            system("cls");
            setcolor(15);
            while ( fread (pUser, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( pUser->username, uName) == 0) {
                    if( strcmp ( pUser->password, pwd) == 0) {
                        setcolor(11);
                        printf ("\n\n\n\t\t\t\tsigned in\n\n\n\n\t\t\t\tis loading...\t\t");
                        setcolor(15);
                        q=1;
                        Sleep(1500);
                        system("cls");
                        strcpy(username1,uName);
                        fclose(fp);
                    }
                }
            }
            if(q==1)
            break;
            else if(q==0) 
                    {
                      setcolor(11);
                      printf("\n\n\n\t\t\t\tnot true");
                      setcolor(15);
                      Sleep(1500);
                      system("cls");
                      fclose(fp);
                      free(pUser);
                      userlogin();
                    }
                    else
                        break;
        case 2:
        Q=1;
            do
            {
                if ( ( fp=fopen("user.txt", "a+")) == NULL) {
                    if ( ( fp=fopen("user.txt", "w+")) == NULL) {
                        printf ("Could not open file\n");
                        exit ( 1);
                    }
                }
                    setcolor(6);
                     printf("\n\n\n\t\t\t\tChoose A Username: ");
                    scanf("%9s",pUser->username);
                    system("cls");
                    printf("\n\n\n\t\t\t\tChoose A Password: ");
                    scanf("%9s",pUser->password);
                    system("cls");
                    fwrite (pUser, sizeof(struct user), 1, fp);
                    printf("\n\n\n\t\t\t\tAdd another account? (Y/N): ");
                    scanf("%c",&c);
                }while((c=='Y'||c=='y')&&(c!='n' || c!='N'));
                    setcolor(15);
                    system("cls");
                    fclose(fp);
                break;
    }
                free ( pUser);
                
                if(Q==1)
                {
                    Q=0;q=0;
                    userlogin();
                }
}
void gameover()
{
                    system("cls");
                    gotoxy(32,13);
                    setcolor(13);
                    printf("GAME OVER");
                    gotoxy(20,13);
                    printf("\n\n\t\t\tYOUR SCOR IN  THIS  GAME  IS  :  %d\t\t",score);
                    Sleep(6000);
                    gotoxy(0,0);
                    system("cls");
}
