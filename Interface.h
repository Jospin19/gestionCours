#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "Graphique.h"
#include "Utilisateur.h"
#include "Professeur.h"
#include "Salle.h"
#include "Cours.h"
#include "Filiere.h"
#include "Seances.h"
#include "Administrateur.h"
#include "Connection.h"
#include "Trace_Emploi.h"
#include "Vide.h"


void Affichage(){
    int a,k,chx,t,u;
    int r,s,niv; int w;
    int choix,n,p;
    char  nom[30],passe[30];
    int nv;
    char C[2];
    char L[1];
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
    gotoxy(16,26);
    printf("OPTION DU PROGRAMME:");
    gotoxy(35,28);
    printf("1---------->SE CONNECTER EN ADMINISTRATEUR");
    gotoxy(35,29);
    printf("2---------->CONSULTER L EMPLOI DE TEMPS");
    gotoxy(35,30);
    printf("3---------->AJOUTER UN UTILISATEUR");

    Debut:
    coloration(10);
    gotoxy(71,35);
    printf("EFFECTUEZ VOTRE CHOIX");
    gotoxy(94,35);
    t=scanf("%d",&choix);
    if(t!=1){
        do{
            u=2;
            scanf("%*[^\n]");
            goto Debut;
        }while(u=2);
    }
    if((choix>=4) || (choix<=0)){
        gotoxy(71,41);
        coloration(12);
        printf("ERREUR D ENTREE DU CHOIX");
        goto Debut;
    }
    else{
            switch(choix){
            case 1:
                cas1:
            system("cls");
            Util();
            con1:
            gotoxy(60,32);
            scanf("%s",&nom);
            if(Verifie_Utilisateur(nom)==0){
                printf("            ");
                goto con1;
            }
            else{
                con2:
                coloration(0);
                gotoxy(60,37);
                scanf("%s",&passe);
                if(Verifie_Passe(passe)==0){
                    printf("            ");
                    goto con2;
                }
                else{
                    system("cls");
                    Admin();
                    coloration(10);
                    gotoxy(71,35);
                    printf("EFFECTUEZ VOTRE CHOIX");
                    gotoxy(94,35);
                    scanf("%d",&chx);
                    if((chx>=7) || (chx<=0)){
                        gotoxy(71,41);
                        coloration(12);
                        printf("ERREUR D ENTREE DU CHOIX");
                        goto Debut;
                    }
                    else{
                            switch(chx){
                            case 1:
                                system("cls");
                                vide();
                                coloration(14);
                                gotoxy(16,26);
                                printf("OPTION DISPONIBLE:");
                                gotoxy(35,28);
                                printf("1---------->AJOUTER UNE FILIERE");
                                gotoxy(35,29);
                                printf("2---------->CONSULTER LES FILIERES EXISTANTES");
                                coloration(10);
                                gotoxy(71,35);
                                printf("EFFECTUEZ VOTRE CHOIX");
                                gotoxy(94,35);
                                scanf("%d",&w);
                                if((w==1)||(w==2)){
                                        switch(w){
                                        case 1:
                                            system("cls");
                                            vide();
                                            Ajout_Filieres(1);
                                        break;
                                        case 2:
                                            system("cls");
                                            vide();
                                            Afficher_Filieres();
                                        break;
                                        }
                                    }
                                    else{
                                        system("cls");
                                        Affichage();
                                    }
                                break;
                            case 2:
                                system("cls");
                                vide();
                                coloration(14);
                                gotoxy(16,26);
                                printf("OPTION DISPONIBLE:");
                                gotoxy(35,28);
                                printf("1---------->AJOUTER UNE SALLE");
                                gotoxy(35,29);
                                printf("2---------->CONSULTER TOUS LES LES SALLES EXISTANTES");
                                coloration(10);
                                gotoxy(71,35);
                                printf("EFFECTUEZ VOTRE CHOIX");
                                gotoxy(94,35);
                                scanf("%d",&w);
                                if((w==1)||(w==2)){
                                        switch(w){
                                        case 1:
                                            system("cls");
                                            vide();
                                            ss:
                                            coloration(7);
                                            gotoxy(16,26);
                                            printf("Dans quel niveau desirez vous l'ajouter?");
                                            coloration(10);
                                            gotoxy(58,26);
                                            r=scanf("%d",&niv);
                                            if(r!=1){
                                            do{
                                                s=2;
                                                scanf("%*[^\n]");
                                                goto ss;
                                            }while(s=2);
                                            }
                                            if((niv>=4) || (niv<=0)){
                                            goto ss;
                                            }
                                            else{
                                            system("cls");
                                            vide();
                                            Ajout_Salles(1,niv);
                                        }
                                        break;
                                        case 2:
                                            sw:
                                            coloration(7);
                                            gotoxy(16,26);
                                            printf("Dans quel niveau desirez voir les salles?");
                                            coloration(10);
                                            gotoxy(58,26);
                                            r=scanf("%d",&niv);
                                            if(r!=1){
                                            do{
                                                s=2;
                                                scanf("%*[^\n]");
                                                goto sw;
                                            }while(s=2);
                                            }
                                            if((niv>=4) || (niv<=0)){
                                            goto sw;
                                            }
                                            system("cls");
                                            vide();
                                            Afficher_Salles(niv);
                                        break;
                                        }
                                    }
                                    else{
                                        system("cls");
                                        Affichage();
                                    }
                                    break;
                            case 3:
                                system("cls");
                                vide();
                                coloration(14);
                                gotoxy(16,26);
                                printf("OPTION DISPONIBLE:");
                                gotoxy(35,28);
                                printf("1---------->AJOUTER UN PROFESSEUR");
                                gotoxy(35,29);
                                printf("2---------->CONSULTER LES PROFESSEURS EXISTANTS");
                                coloration(10);
                                gotoxy(71,35);
                                printf("EFFECTUEZ VOTRE CHOIX");
                                gotoxy(94,35);
                                scanf("%d",&w);
                                if((w==1)||(w==2)){
                                        switch(w){
                                        case 1:
                                            system("cls");
                                            vide();
                                            Ajout_Professeurs(1);
                                        break;
                                        case 2:
                                            system("cls");
                                            vide();
                                            Afficher_Professeurs();
                                        break;
                                        }
                                    }
                                    else{
                                        system("cls");
                                        Affichage();
                                    }
                                break;
                            case 4:
                                system("cls");
                                vide();
                                coloration(14);
                                gotoxy(16,26);
                                printf("OPTION DISPONIBLE:");
                                gotoxy(35,28);
                                printf("1---------->AJOUTER UN COUR");
                                gotoxy(35,29);
                                printf("2---------->CONSULTER TOUS LES COURS");
                                coloration(10);
                                gotoxy(71,35);
                                printf("EFFECTUEZ VOTRE CHOIX");
                                gotoxy(94,35);
                                scanf("%d",&w);
                                if((w==1)||(w==2)){
                                        switch(w){
                                        case 1:
                                            system("cls");
                                            vide();
                                            se:
                                            coloration(7);
                                            gotoxy(16,26);
                                            printf("Dans quel niveau desirez vous l'ajouter?");
                                            coloration(10);
                                            gotoxy(58,26);
                                            r=scanf("%d",&niv);
                                            if(r!=1){
                                            do{
                                                s=2;
                                                scanf("%*[^\n]");
                                                goto se;
                                            }while(s=2);
                                            }
                                            if((niv>=4) || (niv<=0)){
                                            goto se;
                                            }
                                            else{
                                            system("cls");
                                            vide();
                                            Ajout_Cours(1,niv);
                                        }
                                        break;
                                        case 2:
                                            s:
                                            coloration(7);
                                            gotoxy(16,26);
                                            printf("Dans quel niveau desirez voir les cours?");
                                            coloration(10);
                                            gotoxy(58,26);
                                            r=scanf("%d",&niv);
                                            if(r!=1){
                                            do{
                                                s=2;
                                                scanf("%*[^\n]");
                                                goto s;
                                            }while(s=2);
                                            }
                                            if((niv>=4) || (niv<=0)){
                                            goto s;
                                            }
                                            system("cls");
                                            vide();
                                            Afficher_Cours(niv);
                                        break;
                                        }
                                    }
                                    else{
                                        system("cls");
                                        Affichage();
                                    }
                                    break;
                            case 5:
                                system("cls");
                                vide();
                                sf:
                                coloration(7);
                                gotoxy(16,26);
                                printf("Dans quel niveau desirez vous l'ajouter?");
                                coloration(10);
                                gotoxy(58,26);
                                r=scanf("%d",&p);
                                if(r!=1){
                                do{
                                    s=2;
                                    scanf("%*[^\n]");
                                    goto sf;
                                }while(s=2);
                                }
                                if((p>=4) || (p<=0)){
                                goto sf;
                                }
                                else{
                                system("cls");
                                vide();
                                Ajout_Emploi(p);
                                break;
                                }
                        }
                }
                }
            }
            break;
            case 2:
                clas:
                system("cls");
                Emp();
                Charger_Seances();
                gotoxy(27,16);
                printf("08H-10H");
                gotoxy(27,22);
                printf("10H-12H");
                gotoxy(27,28);
                printf("12H-14H");
                gotoxy(27,34);
                printf("14H-16H");
                break;

            case 3:
                system("cls");
                vide();
                Ajout_Utilisateurs(1);
                break;
            }
        }
    }


    void Gestion_interface(){

        Affichage();
    }
