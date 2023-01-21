#include <conio.h>
#include <windows.h>
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#include<dos.h>


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






void userlogin(void);

struct user{
    char username[10];
    char password[10];
}*pUser;








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
