#include <string.h>
#include <math.h>
#include <windows.h>



void Admin(){
    int a;
    //Carré du coin supérieur gauche
    gotoxy(70,2);
    coloration(3);
    printf("");
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

        //Début des écritures
    coloration(10);
    gotoxy(16,11);
    printf("INSTITUT AFRICAIN D INFORMATIQUE");
    gotoxy(22,12);
    printf("*******************");
    gotoxy(16,13);
    printf("REPRESENTATION DU CAMEROUN");
    gotoxy(22,14);
    printf("*******************");
    gotoxy(10,15);
    printf("CENTRE D'EXELENCE TECHNOLOGIQUE PAUL BIYA");
    gotoxy(22,16);
    printf("*******************");



    gotoxy(116,11);
    printf("AFRICAN INSTITUT OF COMPUTER SCIENCE");
    gotoxy(124,12);
    printf("*******************");
    gotoxy(120,13);
    printf("REPRESENTATION OF CAMEROON");
    gotoxy(124,14);
    printf("*******************");
    gotoxy(112,15);
    printf("CENTRE D'EXELENCE TECHNOLOGIQUE PAUL BIYA");
    gotoxy(124,16);
    printf("*******************");

    coloration(11);
    gotoxy(70,19);
    printf("EXPOSEE DE LANGAGE C/C++");
    gotoxy(74,20);
    printf("**************");

    gotoxy(65,22);
    printf("APPLICATION DE GESTION DES COURS");
    gotoxy(72,23);
    printf("-----------------");

    coloration(14);
    gotoxy(65,26);
    printf("OPTION DE L ADMINISTRATEUR:");
    gotoxy(65,28);
    printf("1---------->GESTION DES FILIERE");
    gotoxy(65,29);
    printf("2---------->GESTION DES SALLES");
    gotoxy(65,30);
    printf("3---------->GESTION DES PROFESSEURS");
    gotoxy(65,31);
    printf("4---------->AJOUTER DES MATIRES");
    gotoxy(65,32);
    printf("5---------->CREER LE NOUVEL EMPLOIE DE TEMPS");

    }
