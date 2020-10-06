#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//D�claration de la structure des Cours
    typedef struct Cours{
         int Id_Cours;
         int NIV;
        char Nom_Cours[30];
         int Quota;
    }Cours;


//D�claration du pointeur vers le fichier des Cours
    FILE *  Fichier_Cours=NULL;

//D�claration des pointeurs qui serviront a creer les tableaux pour la manipulation des Cours
    Cours * T_Cours, * T1_Cours, * T_Rech_Cours;

//D�claration de la fonction qui testera si le fichier des Cours est vide
    int testSiFichierVideC(FILE* fichier){
        int caracterePremier = 0;
        //On lit le prmeier caract�re du fichier
        caracterePremier = fgetc(fichier);
        if(caracterePremier==EOF){
            return 1;//le fichier est vide donc on retourne 1
        }
    return 0;//le fichier n'est pas vide donc on retourne 0
    }


//D�claration de la fonction qui recuperera l'ID du dernier Cours
    int Recupere_IDC(int num_niv){
        int j=1;
        size_t f=1;
        if((T1_Cours=malloc(100 * sizeof(Cours)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("Echec de creation du taleau des Cours");
        }
        else{
                Fichier_Cours = fopen("Files/File_Cours.bin", "rb+");
                if (Fichier_Cours != NULL){
                    if(testSiFichierVideC(Fichier_Cours)==1){
                        return 1;
                    }
                    else
                    {
                        f+=fread(T1_Cours, sizeof(Cours), 100 , Fichier_Cours);
                        return f;
                        fclose(Fichier_Cours);
                        free(T1_Cours);
                    }
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("Erreur lors de l'ouverture du fichier.");
                    printf("Pressez une touche...");
                    _getch();
                }
    }
    }

 //D�claration de la fonction qui verifira si un Cours existe d�ja ou pas
    int Verifie_Cours(int num_niv,char N_C[30]){
        int i=0,cpte=0,maxi;
            maxi=Recupere_IDC(num_niv);
            if((T_Rech_Cours=malloc(maxi * sizeof(Cours)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Cours = fopen("Files/File_Cours.bin", "rb");
                if (Fichier_Cours != NULL){
                    fread(T_Rech_Cours, sizeof(Cours), maxi, Fichier_Cours);
                    fclose(Fichier_Cours);
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("Erreur lors de l'ouverture du fichier.");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if(strcmp(T_Rech_Cours[i].Nom_Cours,N_C)==0){
                        cpte+=1;
                    }
                    else{
                        continue;
                    }
                }
                return cpte;
            }
            free(T_Rech_Cours);
    }


//D�claration de la fonction qui ajoute Cours
//Cette proc�dure contient les instructions d'initialisation du fichier des Cours
    void Ajout_Cours(int a,int num_niv){
        int i,id_plus,r,s=0;
         // On alloue de la m�moire pour le tableau des Cours
        if((T_Cours=malloc(a * sizeof(Cours)))==NULL){
            gotoxy(71,41);
            coloration(12);
            printf("Echec de creation du tableau des Cours!!");
        }
        else{
            //On r�cup�re le dernier ID
            for(i=0;i<a;i++){
                    id_plus=Recupere_IDC(num_niv);
                    T_Cours[i].Id_Cours=id_plus+2;
                    Crs:
                    coloration(7);
                    gotoxy(16,26);
                    printf("VEUILLEZ ENTRER LE NOM DE VOTRE COURS:");
                    coloration(10);
                    gotoxy(65,26);
                    scanf("%s",&T_Cours[i].Nom_Cours);
                    if(Verifie_Cours(num_niv,T_Cours[i].Nom_Cours)>=1){
                        printf("PARAMETRES INCORRECTES");
                        gotoxy(16,26);
                        printf("                      ");
                        goto Crs;
                    }
                    else{
                        Quo:
                        coloration(7);
                        gotoxy(16,28);
                        printf("VEUILLEZ ENTRER LE QUOTA DE CE COURS:");
                        coloration(10);
                        gotoxy(65,28);
                        r=scanf("%d",&T_Cours[i].Quota);
                        if(r!=1){
                            do{
                                s=2;
                                scanf("%*[^]");
                                gotoxy(65,28);
                                printf("                      ");
                                goto Quo;
                            }while(s=2);
                        switch(num_niv){
                        case 1:
                            T_Cours[i].NIV=1;
                            break;
                        case 2:
                            T_Cours[i].NIV=2;
                            break;
                        case 3:
                            T_Cours[i].NIV=3;
                            break;
                        }
                        }
                        // Fin de la r�cup�ration au clavier des informations
                            Fichier_Cours = fopen("Files/File_Cours.bin", "ab");
                            if (Fichier_Cours != NULL){
                                //D�but de l'enregistrement dans le fichier
                                fwrite(T_Cours, sizeof(Cours), a, Fichier_Cours);
                                if (fclose(Fichier_Cours)){
                                    gotoxy(71,41);
                                    coloration(12);
                                    printf("Le fichier n'a pas ete correctement ecrit.");
                                }
                                else{
                                    gotoxy(71,41);
                                    coloration(12);
                                    printf("Ecriture dans le fichier reussi!");
                                    fclose(Fichier_Cours);
                                }
                            }
                            else{
                                gotoxy(71,41);
                                coloration(12);
                                printf("L ouverture du fichier n a pas reussi!!");
                            }
                        }
            }

        }
        free(T_Cours);
    }


//D�claration Affichera les Cours inscrits ou enreistr�s
    void Afficher_Cours(int num_niv){  //Cette proc�dure contient les instructions d'initialisation du fichier des Cours
       int i=0,cpte=0,maxi;
            maxi=Recupere_IDC(num_niv);
            if((T_Cours=malloc(maxi * sizeof(Cours)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Cours = fopen("Files/File_Cours.bin", "rb");
                if (Fichier_Cours != NULL){
                    fread(T_Cours, sizeof(Cours), maxi, Fichier_Cours);
                    fclose(Fichier_Cours);
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("Erreur lors de l'ouverture du fichier.");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if(num_niv==T_Rech_Cours[i].Nom_Cours){
                        coloration(10);
                        gotoxy(16,26+i);
                        printf("COURS:\t%s\tQUOTA:\t%d",T_Rech_Cours[i].Nom_Cours,T_Rech_Cours[i].Quota);
                    }
                }
            }
            free(T_Rech_Cours);
     }


void Crss(){



}
