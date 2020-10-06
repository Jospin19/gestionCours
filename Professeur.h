#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//Déclaration de la structure des Professeur
    typedef struct Professeur{
        int Id_Professeur;
        char Matricule[20];
        char Nom_Professeur[30];
        int Tranche1;
        int Tranche2;
        int Tranche3;
        int Tranche4;
    }Professeur;

//Déclaration du pointeur vers le fichier des Professeur
    FILE *  Fichier_Prof=NULL;

//Déclaration des pointeurs qui serviront a creer les tableaux pour la manipulation des Professeurs
    Professeur * T_Professeur, * T1_Professeur, * T_Rech_Prof;

//Déclaration de la fonction qui testera si le fichier des Professeurs est vide
    int testSiFichierVideP(FILE* fichier){
        int caracterePremier = 0;
        //On lit le prmeier caractère du fichier
        caracterePremier = fgetc(fichier);
        if(caracterePremier==EOF){
            return 1;//le fichier est vide donc on retourne 1
        }
    return 0;//le fichier n'est pas vide donc on retourne 0
    }


//Déclaration de la fonction qui recuperera l'ID de la derniere Professeur
    int Recupere_IDP(){
        int j=1;
        size_t f=1;
        if((T1_Professeur=malloc(100 * sizeof(Professeur)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("Echec de creation du taleau des Professeurs");
        }
        else{
            Fichier_Prof = fopen("Files/File_Professeur.bin", "rb+");
            if (Fichier_Prof != NULL)
                if(testSiFichierVideP(Fichier_Prof)==1){
                    return 1;
                }
                else
                {
                    f+=fread(T1_Professeur, sizeof(Professeur), 100 , Fichier_Prof);
                    return f;
                    fclose(Fichier_Prof);
                    free(T1_Professeur);
                }
        }
    }


 //Déclaration de la fonction qui verifira si un Professeur existe déja ou pas
    int Verifie_Professeur(char M[20],char N_P[30]){
        int i=0,cpte=0;
        int maxi=Recupere_IDP();
        if((T_Rech_Prof=malloc(maxi * sizeof(Professeur)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("La verification est impossible!!!");
            }
        else{
            Fichier_Prof = fopen("Files/File_Professeur.bin", "rb");
            if (Fichier_Prof != NULL){
                fread(T_Rech_Prof, sizeof(Professeur), maxi, Fichier_Prof);
                fclose(Fichier_Prof);
            }
            else{
                gotoxy(71,41);
                coloration(12);
                printf("Erreur lors de l'ouverture du fichier.");
                printf("Pressez une touche...");
                _getch();
            }
            for(i=0;i<=maxi;i++){
                if((strcmp(T_Rech_Prof[i].Matricule,M)==0) && (strcmp(T_Rech_Prof[i].Nom_Professeur,N_P)==0)){
                    cpte+=1;
                }
                else{
                    continue;
                }
            }
            return cpte;
        }
        free(T_Rech_Prof);
    }


//Déclaration de la fonction qui ajoute Professeur
//Cette procédure contient les instructions d'initialisation du fichier des Professeurs
    void Ajout_Professeurs(int a){
        int i,id_plus;
         // On alloue de la mémoire pour le tableau des Professeurs
        if((T_Professeur=malloc(a * sizeof(Professeur)))==NULL){
            gotoxy(71,41);
            coloration(12);
            printf("Echec de creation du tableau des Professeurs!!");
        }
        else{
            for(i=0;i<a;i++){
                    //On récupère le dernier ID
                    id_plus=Recupere_IDP();
                    T_Professeur[i].Id_Professeur=id_plus+2;
                    Prof:
                    coloration(7);
                    gotoxy(16,26);
                    printf("VEUILLEZ ENTRER LE NOM DU PROFESSEUR:");
                    coloration(10);
                    gotoxy(65,26);
                    scanf("%s",&T_Professeur[i].Nom_Professeur);
                    Mat:
                    coloration(7);
                    gotoxy(16,28);
                    printf("VEUILLEZ ENTRER LE MATRICULE DU PROFESSEUR:");
                    coloration(10);
                    gotoxy(71,28);
                    scanf("%s",&T_Professeur[i].Matricule);
                    if(strlen(T_Professeur[i].Matricule)>=10){
                        printf("ERREUR D'ENTREE DU MATRICULE.VEUILLEZ LE REMPLIR A NOUVEAU");
                        gotoxy(16,28);
                        printf("                             ");
                        goto Mat;
                    }
                    if(Verifie_Professeur(T_Professeur[i].Matricule, T_Professeur[i].Nom_Professeur)>=1){
                        gotoxy(71,41);
                    coloration(12);
                        printf("CE PROFESSEUR EXISTE DEJA!");
                        gotoxy(16,26);
                        printf("                       ");
                        goto Prof;
                    }
                    // Fin de la récupération au clavier des informations
                    Fichier_Prof = fopen("Files/File_Professeur.bin", "ab");
                    if (Fichier_Prof != NULL){
                            //Début de l'enregistrement dans le fichier
                            fwrite(T_Professeur, sizeof(Professeur), a, Fichier_Prof);
                            if (fclose(Fichier_Prof)){
                                gotoxy(71,41);
                                coloration(12);
                                printf("Le fichier n'a pas ete correctement ecrit.");
                            }
                            else{
                                gotoxy(71,41);
                                coloration(12);
                                printf("Ecriture dans le fichier reussi!");
                                fclose(Fichier_Prof);
                            }
                        }
                        else{
                            gotoxy(71,41);
                            coloration(12);
                            printf("L ouverture du fichier n a pas reussi!!");
                        }
                    }
            }
        free(T_Professeur);
    }


//Déclaration Affichera les Professeurs inscrits ou enreistrés
    void Afficher_Professeurs(){  //Cette procédure contient les instructions d'initialisation du fichier des Professeurs
        int i=0,maxi=Recupere_IDP();
         // On alloue de la mémoire pour le taleau des Professeurs
        if((T_Professeur=malloc(maxi * sizeof(Professeur)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("Echec de creation du tableau des Professeurs!!");
        }
        else{
            Fichier_Prof = fopen("Files/File_Professeur.bin", "rb+");
            if (Fichier_Prof != NULL){
                //Début de la lecture dans le fichier
                fread(T_Professeur, sizeof(Professeur), maxi, Fichier_Prof);
                fclose(Fichier_Prof);
                for(i = 0 ; i < maxi; i++){
                    coloration(10);
                    gotoxy(16,26+i);
                    printf("ID:%d\tProfesseur:\t%sMATRICULE:\t%s",T_Professeur[i].Id_Professeur,T_Professeur[i].Nom_Professeur,T_Professeur[i].Matricule);
                }
                fclose(Fichier_Prof);
            }
            else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("L ouverture du fichier n a pas reussi!!");
            }
        free(T_Professeur);
        }
     }


void Prof(){
//Déclartion de la fonction qui vérifie si un Professeur existe ou pas
    }

