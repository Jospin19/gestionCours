#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//D�claration de la structure des Utilisateur
    typedef struct Utilisateur{
         int Id_Utilisateur;
        char  Pseudo[30];
        char  Passe_Utilisateur[30];
    }Utilisateur;

//D�claration du pointeur vers le fichier des Utilisateur
    FILE *  Fichier_Ut=NULL;

//D�claration des pointeurs qui serviront a creer les tableaux pour la manipulation des Utilisateurs
    Utilisateur * T_Utilisateur, * T1_Utilisateur, * T_Rech_Util;

//D�claration de la fonction qui testera si le fichier des utilisateurs est vide
    int testSiFichierVide(FILE* fichier){
        int caracterePremier = 0;
        //On lit le prmeier caract�re du fichier
        caracterePremier = fgetc(fichier);
        if(caracterePremier==EOF){
            return 1;//le fichier est vide donc on retourne 1
        }
    return 0;//le fichier n'est pas vide donc on retourne 0
    }


//D�claration de la fonction qui recuperera l'ID du dernier utilisateur
    int Recupere_ID(){
        int j=1;
        size_t f=1;
        if((T1_Utilisateur=malloc(100 * sizeof(Utilisateur)))==NULL){
                printf("Echec de creation du taleau des utilisateurs");
        }
        else{
            Fichier_Ut = fopen("Files/File_Utilisateurs.bin", "rb+");
            if (Fichier_Ut != NULL){
                if(testSiFichierVide(Fichier_Ut)==1){
                    return 1;
                }
                else
                {
                    f+=fread(T1_Utilisateur, sizeof(Utilisateur), 100 , Fichier_Ut);
                    return f;
                    fclose(Fichier_Ut);
                    free(T1_Utilisateur);
                }
            }
            else{
                printf("Le fichier n a pas pu etre ouvert!");
            }
        }
    }


 //D�claration de la fonction qui verifira si un utilisateur existe d�ja ou pas
    int Verifie_Utilisateur(char N[30]){
        int i=0,cpte=0;
        int maxi=Recupere_ID();
        if((T_Rech_Util=malloc(maxi * sizeof(Utilisateur)))==NULL){
                printf("La verification est impossible!!!");
            }
        else{
            Fichier_Ut = fopen("Files/File_Utilisateurs.bin", "rb");
            if (Fichier_Ut != NULL){
                fread(T_Rech_Util, sizeof(Utilisateur), maxi, Fichier_Ut);
                fclose(Fichier_Ut);
            }
            else{
                printf("Erreur lors de l'ouverture du fichier.\n");
                printf("Pressez une touche...");
                _getch();
            }
            for(i=0;i<=maxi;i++){
                if(strcmp(T_Rech_Util[i].Pseudo,N)==0){
                    cpte+=1;
                }
                else{
                    continue;
                }
            }
            return cpte;
        }
        free(T_Rech_Util);
    }


//D�claration de la fonction qui ajoute utilisateur
//Cette proc�dure contient les instructions d'initialisation du fichier des utilisateurs
    void Ajout_Utilisateurs(int a){
        int i,id_plus;
         // On alloue de la m�moire pour le tableau des utilisateurs
        if((T_Utilisateur=malloc(a * sizeof(Utilisateur)))==NULL){
            printf("Echec de creation du tableau des utilisateurs!!");
        }
        else{
            //On r�cup�re le dernier ID

            for(i=0;i<a;i++){
                    id_plus=Recupere_ID();
                    T_Utilisateur[i].Id_Utilisateur=id_plus+2;
                    Util:
                    printf("\nVEUILLEZ ENTRER VOTRE PSEUDO D UTILISATEUR:\t");
                    scanf("%s",&T_Utilisateur[i].Pseudo);
                    if(Verifie_Utilisateur(T_Utilisateur[i].Pseudo)>=1){
                        goto Util;
                    }
                    else{
                        printf("\nVEUILLEZ ENTRER VOTRE MOT DE PASSE:\t");
                        scanf("%s",&T_Utilisateur[i].Passe_Utilisateur);
                        // Fin de la r�cup�ration au clavier des informations
                        Fichier_Ut = fopen("Files/File_Utilisateurs.bin", "ab");
                        if (Fichier_Ut != NULL){
                            //D�but de l'enregistrement dans le fichier
                            fwrite(T_Utilisateur, sizeof(Utilisateur), a, Fichier_Ut);
                            if (fclose(Fichier_Ut)){
                                printf("Le fichier n'a pas ete correctement ecrit.\n");
                            }
                            else{
                                printf("Ecriture dans le fichier reussi!");
                                fclose(Fichier_Ut);
                            }
                        }
                        else{
                            printf("L ouverture du fichier n a pas reussi!!");
                        }
                    }
            }

        }
        free(T_Utilisateur);
    }


//D�claration Affichera les utilisateurs inscrits ou enreistr�s
    void Afficher_Utilisateurs(){  //Cette proc�dure contient les instructions d'initialisation du fichier des utilisateurs
        int i=0,maxi=Recupere_ID();
         // On alloue de la m�moire pour le taleau des utilisateurs
        if((T_Utilisateur=malloc(maxi * sizeof(Utilisateur)))==NULL){
                printf("Echec de creation du tableau des utilisateurs!!");
        }
        else{
            Fichier_Ut = fopen("Files/File_Utilisateurs.bin", "rb+");
            if (Fichier_Ut != NULL){
                //D�but de l'enregistrement dans le fichier
                fread(T_Utilisateur, sizeof(Utilisateur), maxi, Fichier_Ut);
                fclose(Fichier_Ut);
                for(i = 0 ; i < maxi; i++){
                    printf("ID:\t%d\tUTILISATEUR:\t%s \n",T_Utilisateur[i].Id_Utilisateur,T_Utilisateur[i].Pseudo);
                }
                fclose(Fichier_Ut);
            }
            else{
                    printf("L ouverture du fichier n a pas reussi!!");
            }
        free(T_Utilisateur);
        }
     }


int main(){
//D�clartion de la fonction qui v�rifie si un utilisateur existe ou pas
    Ajout_Utilisateurs(1);
    Afficher_Utilisateurs();
    return 0;
    }
