#include <string.h>
#include <math.h>
#include <windows.h>


void Emp() {
    int i,j,a;
     gotoxy(22,7);
     printf("%c",201);
     for(i=0;i<=120;i++)
         {
              printf("%c",205);
         }
     printf("%c",187);
     gotoxy(22,8);
     printf("%c",186);
     for(i=0;i<=28;i++)
         {
              gotoxy(22,8+i);
              printf("%c",186);
         }
     gotoxy(22,37);
     printf("%c",200);
     for(i=0;i<=120;i++)
         {
              printf("%c",205);
         }
     printf("%c",188);
     for(i=28;i>=0;i--)
         {
              gotoxy(144,36-i);
              printf("%c",186);
         }
     for(i=0;i<=29;i++){
     for(j=0;j<=120;j+=18)
         {
              gotoxy(22+j,7+i);
              printf("%c",186);
         }
         }
     for(i=0;i<=120;i++){
     for(j=0;j<=28;j+=6)

         {
              gotoxy(23+i,7+j);
              printf("%c",205);
         }
         }

    gotoxy(24,10);
    printf("HORAIRE/JOUR");
    gotoxy(46,10);
    printf("LUNDI");
    gotoxy(65,10);
    printf("MARDI");
    gotoxy(81,10);
    printf("MERCREDI");
    gotoxy(99,10);
    printf("JEUDI");
    gotoxy(117,10);
    printf("VENDREDI");
    gotoxy(133,10);
    printf("SAMEDI");

//Carré du coin supérieur gauche
    coloration(13);
    for(a=0;a<=7;a++){
        gotoxy(1,1+a);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c",35,35,35,35,35,35,35,35,35,35,35,35);
    }

    //Trait horizontal supérieur
    for(a=0;a<=150;a++){
        gotoxy(1+a,4);
        printf("%c%c",35,35);
        gotoxy(1+a,5);
        printf("%c%c",35,35);
    }

    //Carré du coin supérieur droit
    for(a=0;a<=7;a++){
        gotoxy(153,1+a);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c",35,35,35,35,35,35,35,35,35,35,35,35);
    }

    for(a=0;a<=35;a++){
        gotoxy(6,6+a);
        printf("%c%c",35,35);
    }

    for(a=0;a<=35;a++){
        gotoxy(158,6+a);
        printf("%c%c",35,35);
    }

  //Symétrique
  for(a=0;a<=7;a++){
        gotoxy(1,35+a);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c",35,35,35,35,35,35,35,35,35,35,35,35);
    }
    for(a=0;a<=150;a++){
        gotoxy(1+a,38);
        printf("%c%c",35,35);
        gotoxy(1+a,39);
        printf("%c%c",35,35);
    }
    for(a=0;a<=7;a++){
        gotoxy(153,35+a);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c",35,35,35,35,35,35,35,35,35,35,35,35);
    }
}

