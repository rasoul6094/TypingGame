#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>



struct node{  
    char  *data;  
    struct node *previous;  
    struct node *next;  
};   


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





  void updateScore(){
	gotoxy(WIN_WIDTH + 7, 5);printf("score: %d\n",score);
}


void drawBorder(){  




	for(int i=0; i<SCREEN_WIDTH; i++){ 
		gotoxy(i,SCREEN_HEIGHT); printf("#");
	}
	
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(0,i); printf("#");
		gotoxy(SCREEN_WIDTH,i); printf("#");
	}
	for(int i=0; i<SCREEN_HEIGHT; i++){
		gotoxy(WIN_WIDTH,i); printf("#");
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



void userlogin(void);

struct user{
    char username[10];
    char password[10];
}*pUser;




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
             
         fscanf(fp2, "%s", &line);
        addNode(strdup(line));
        fgetc(fp2);
        n++;
        fscanf(fp, "%s", &line);
        addNode(strdup(line));
        fgetc(fp);
        n++;
            
        }
        for(int i=1;i<=35;i++){
         if(n==40 || n==30 || n==20)
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
            
         fscanf(fp2, "%s", &line);
        addNode(strdup(line));
        fgetc(fp2);
        n++;
        fscanf(fp, "%s", &line);
        addNode(strdup(line));
        fgetc(fp);
        n++;
            
        }
        for(int i=1;i<=35;i++){
             if(n==20 || n==30 || n==40)
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
            
         fscanf(fp2, "%s", &line);
        addNode(strdup(line));
        fgetc(fp2);
        n++;
        fscanf(fp, "%s", &line);
        addNode(strdup(line));
        fgetc(fp);
        n++;
            
        }
        for(int i=1;i<=40;i++){
             if(n==15 || n==25 || n==35)
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

    return i;
}




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
        num2 = num + 'a';
        str[i] = num2;
        i += 1;
    }
    // puts(str);
    fprintf(fptr,"%s\n", str);
    
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
        num2 = num + 'a';
        str[i] = num2;
        i += 1;
    }
    // puts(str);
    fprintf(fptr,"%s\n", str);
    
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
        num = rand() % 14;
        num2 = num + 33;
        str[i] = num2;
        i += 1;
    }
    // puts(str);
    fprintf(fptr,"%s\n", str);
    
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

int main()
{ 
    
  system("cls");
  srand(time(NULL));

  for(int i=0;i<100;i++)
  {
  fillNormal(); fillLong(); fillHard();
  }
    system("cls");
	gotoxy(WIN_WIDTH + 5, 2);printf("Typing Tutor");
	gotoxy(WIN_WIDTH + 6, 4);printf("----------");
	gotoxy(WIN_WIDTH + 6, 6);printf("----------");
	gotoxy(18, 5);printf("Press any key to start");
	getch();
    gotoxy(18, 5);printf("                      ");

    userlogin();
    int levelGAME=level();
  
  
        switch(levelGAME)
    {
        case 1:   easy();     break;
        case 2:   medium();   break;
        case 3:   hard();     break;
    }
  
  
  
  freefileA();freefileB();freefileC();
     return 0;
}


void userlogin(void){
    FILE *fp;
    char uName[10], pwd[10];int i;char c;int q=0,Q=0;

    pUser=(struct user *)malloc(sizeof(struct user));
    do{
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
            if ( ( fp=fopen("user.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
            }
            setcolor(6);
            printf("\n\n\n\t\t\t\tUsername: ");
            scanf("%9s",uName);
            username1=uName;
            system("cls");
            printf("\n\n\n\t\t\t\tPassword: ");
            scanf("%9s",pwd);
            system("cls");
            setcolor(15);
            while ( fread (pUser, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( pUser->username, uName) == 0) {
                    if( strcmp ( pUser->password, pwd) == 0) {
                        setcolor(11);
                        printf ("\n\n\n\t\t\t\tsigned in\n");
                        setcolor(15);
                        q=1;
                        Sleep(1500);
                        system("cls");
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
                      userlogin();
                    }
                    else
                        break;
        case 2:
        Q=1;
            do
            {
                if ( ( fp=fopen("user.dat", "a+")) == NULL) {
                    if ( ( fp=fopen("user.dat", "w+")) == NULL) {
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
                }while(c=='Y'||c=='y');
                    setcolor(15);
                    system("cls");
                break;
    }
                    free ( pUser);
                    fclose(fp);
                if(Q==1)
                {
                    Q=0;q=0;
                    userlogin();
                }
}
