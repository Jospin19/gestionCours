#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

    HANDLE couleur;

    void gotoxy(int x, int y){
        HANDLE hConsoleOutput;
        COORD dwCursorPosition;
        //cout.flush();
        dwCursorPosition.X = x;
        dwCursorPosition.Y = y;
        hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
    }

    void coloration(int k){

        couleur=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(couleur,k);
    }

