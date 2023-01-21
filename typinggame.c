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
