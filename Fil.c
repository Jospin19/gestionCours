#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//Déclaration de la structure des Filiere
    typedef struct Filiere{
         int Id_fil;
        char Code_Filiere[20];
        char Nom_Filiere[30];
    }Filiere;

//Déclaration du pointeur vers le fichier des Filiere
    FILE *  Fichier_Fil=NULL;

//Déclaration des pointeurs qui serviront a creer les tableaux pour la manipulation des Filieres
    Filiere * T_Filiere, * T1_Filiere, * T_Rech_Fil;

//Déclaration de la fonction qui testera si le fichier des Filieres est vide
    int testSiFichierVide(FILE* fichier){
        int caracterePremier = 0;
        //On lit le prmeier caractère du fichier
        caracterePremier = fgetc(fichier);
        if(caracterePremier==EOF){
            return 1;//le fichier est vide donc on retourne 1
        }
    return 0;//le fichier n'est pas vide donc on retourne 0
    }


//Déclaration de la fonction qui recuperera l'ID de la derniere Filiere
    int Recupere_ID(){
        int j=1;
        size_t f=1;
        if((T1_Filiere=malloc(100 * sizeof(Filiere)))==NULL){
                printf("Echec de creation du taleau des Filieres");
        }
        else{
            Fichier_Fil = fopen("Files/File_Filiere.bin", "rb+");
            if (Fichier_Fil != NULL)
                if(testSiFichierVide(Fichier_Fil)==1){
                    return 1;
                }
                else
                {
                    f+=fread(T1_Filiere, sizeof(Filiere), 100 , Fichier_Fil);
                    return f;
                    fclose(Fichier_Fil);
                    free(T1_Filiere);
                }
        }
    }


 //Déclaration de la fonction qui verifira si un Filiere existe déja ou pas
    int Verifie_Filiere(char C[20],char N[30]){
        int i=0,cpte=0;
        int maxi=Recupere_ID();
        if((T_Rech_Fil=malloc(maxi * sizeof(Filiere)))==NULL){
                printf("La verification est impossible!!!");
            }
        else{
            Fichier_Fil = fopen("Files/File_Filiere.bin", "rb");
            if (Fichier_Fil != NULL){
                fread(T_Rech_Fil, sizeof(Filiere), maxi, Fichier_Fil);
                fclose(Fichier_Fil);
            }
            else{
                printf("Erreur lors de l'ouverture du fichier.\n");
                printf("Pressez une touche...");
                _getch();
            }
            for(i=0;i<=maxi;i++){
                if((strcmp(T_Rech_Fil[i].Code_Filiere,C)==0) || (strcmp(T_Rech_Fil[i].Nom_Filiere,N)==0)){
                    cpte+=1;
                }
                else{
                    continue;
                }
            }
            return cpte;
        }
        free(T_Rech_Fil);
    }


//Déclaration de la fonction qui ajoute Filiere
//Cette procédure contient les instructions d'initialisation du fichier des Filieres
    void Ajout_Filieres(int a){
        int i,id_plus;
         // On alloue de la mémoire pour le tableau des Filieres
        if((T_Filiere=malloc(a * sizeof(Filiere)))==NULL){
            printf("Echec de creation du tableau des Filieres!!");
        }
        else{
            for(i=0;i<a;i++){
                    //On récupère le dernier ID
                    id_plus=Recupere_ID();
                    T_Filiere[i].Id_fil=id_plus+2;
                    Fil:
                    printf("\nVEUILLEZ ENTRER LE CODE DE VOTRE FILIERE:[02 CARACTERES AU MAXIMUM]\t");
                    scanf("%s",&T_Filiere[i].Code_Filiere);
                    if(strlen(T_Filiere[i].Code_Filiere)>=3){
                        goto Fil;
                    }
                        printf("\nVEUILLEZ ENTRER LE NOM DE CETTE NOUVELLE FILIERE:\t");
                        scanf("%s",&T_Filiere[i].Nom_Filiere);
                        if(Verifie_Filiere(T_Filiere[i].Code_Filiere, T_Filiere[i].Nom_Filiere)>=1){
                            printf("CETTE FILIERE EXISTE DEJA!");
                            goto Fil;
                        }
                        // Fin de la récupération au clavier des informations
                        Fichier_Fil = fopen("Files/File_Filiere.bin", "ab");
                        if (Fichier_Fil != NULL){
                            //Début de l'enregistrement dans le fichier
                            fwrite(T_Filiere, sizeof(Filiere), a, Fichier_Fil);
                            if (fclose(Fichier_Fil)){
                                printf("Le fichier n'a pas ete correctement ecrit.\n");
                            }
                            else{
                                printf("Ecriture dans le fichier reussi!");
                                fclose(Fichier_Fil);
                            }
                        }
                        else{
                            printf("L ouverture du fichier n a pas reussi!!");
                        }
                    }
            }
        free(T_Filiere);
    }


//Déclaration Affichera les Filieres inscrits ou enreistrés
    void Afficher_Filieres(){  //Cette procédure contient les instructions d'initialisation du fichier des Filieres
        int i=0,maxi=Recupere_ID();
         // On alloue de la mémoire pour le taleau des Filieres
        if((T_Filiere=malloc(maxi * sizeof(Filiere)))==NULL){
                printf("Echec de creation du tableau des Filieres!!");
        }
        else{
            Fichier_Fil = fopen("Files/File_Filiere.bin", "rb+");
            if (Fichier_Fil != NULL){
                //Début de la lecture dans le fichier
                fread(T_Filiere, sizeof(Filiere), maxi, Fichier_Fil);
                fclose(Fichier_Fil);
                for(i = 0 ; i < maxi; i++){
                    printf("ID: \t %d \t Filiere: \t %s \t NOM DE LA FILIERE: \t %s \n",T_Filiere[i].Id_fil,T_Filiere[i].Code_Filiere,T_Filiere[i].Nom_Filiere);
                }
                fclose(Fichier_Fil);
            }
            else{
                    printf("L ouverture du fichier n a pas reussi!!");
            }
        free(T_Filiere);
        }
     }


int main(){
//Déclartion de la fonction qui vérifie si un Filiere existe ou pas
    Ajout_Filieres(1);
    Afficher_Filieres();
    return 0;
    }
