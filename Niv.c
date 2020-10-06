#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>

//Déclaration de la structure des Niveaux
    typedef struct Niveau{
        int Id_Niveau;
        int Num_Niveau;
    }Niveau;


//Déclaration du pointeur vers le fichier des Niveaux
    FILE *  Fichier_Niv=NULL;

//Déclaration des pointeurs qui serviront a creer les tableaux pour la manipulation des Niveaux
    Niveau * T_Niveau, * T1_Niveau, * T_Rech_Niv;

//Déclaration de la fonction qui testera si le fichier des niveaux est vide
        int testSiFichierVide(FILE* fichier){
        int caracterePremier = 0;
        //On lit le prmeier caractère du fichier
        caracterePremier = fgetc(fichier);
        if(caracterePremier==EOF){
            return 1;//le fichier est vide donc on retourne 1
        }
    return 0;//le fichier n'est pas vide donc on retourne 0
    }

//Déclaration de la procédure de chargement du tableau des recherches
    int Charger_Niveau(){
        int j;
        Fichier_Niv = fopen("Files/File_Niveaux.bin", "rb");
        if (Fichier_Niv!= NULL)
        {
            if(testSiFichierVide(Fichier_Niv)==1){
                return 0;
            }
            else{
                //On se positionne a la fin du fichier
                fseek(Fichier_Niv, 0, SEEK_END);

                //On se déplace d'un niveau en arriere
                fseek(Fichier_Niv, -1 * sizeof(Niveau), SEEK_END);

                // On alloue de la mémoire pour le taleau des niveaux
                T_Rech_Niv=malloc(sizeof(Niveau));
                if (T_Rech_Niv == NULL){ // On vérifie si l'allocation a marché ou pas
                    printf("Echec de creation du taleau des Niveaux");
                }
                else{
                    fread(T_Rech_Niv, sizeof(Niveau), 1 , Fichier_Niv);
                    j=T_Rech_Niv[1].Id_Niveau;
                    return j;
                }
                free(T_Rech_Niv);
                T_Rech_Niv=malloc(j * sizeof(Niveau)); // On alloue de la mémoire pour le taleau des niveaux
                if (T1_Niveau == NULL){ // On vérifie encore si l'allocation a marché ou pas
                    printf("Echec de creation du taleau des Niveaux");
                }
                else{
                    rewind(Fichier_Niv);
                    fread(T_Rech_Niv, sizeof(Niveau), j , Fichier_Niv);
                    fclose(Fichier_Niv);
                }
            }
        }
        else{
            printf("Le fichier n a pas pu etre ouvert!!");
        }
    }

//Déclartion de la fonction qui vérifie si un niveau existe ou pas
     int Verifie_Niveau(int N){
        int i;
        int m=Charger_Niveau();
        if(m==0){
            printf("Le fichier des niveaux ne contiend aucune information!!");
        }
        else
            for(i=0;i<=m;i++){
                if(T_Rech_Niv[i].Num_Niveau==N){
                    return 1;
                }
                else{
                    return 0;
                }
        }
    }


//Déclaration de la fonction qui ajoute utilisateur
    void Ajout_Niveaux(int a){  //Cette procédure contient les instructions d'initialisation du fichier des Niveaux
        int i,id_plus,x,y;
        Fichier_Niv = fopen("Files/File_Niveaux.bin", "ab");
        if (Fichier_Niv != NULL)
        {
            T_Niveau=malloc(a * sizeof(Niveau)); // On alloue de la mémoire pour le taleau des Niveaux
            if (T_Niveau == NULL){ // On vérifie si l'allocation a marché ou pas
                    printf("Echec de creation du taleau des Niveau P");
                }
            else{
                //On se positionne a la fin du fichier
                fseek(Fichier_Niv, 0, SEEK_END);
                /* deplacement d'un Utilisateur en arriere */
                fseek(Fichier_Niv, -1 * sizeof(Niveau), SEEK_END);
                T1_Niveau=malloc(sizeof(Niveau)); // On alloue de la mémoire pour le taleau des Niveaux
                if (T1_Niveau == NULL){ // On vérifie si l'allocation a marché ou pas
                    printf("Echec de creation du tableau des Niveaux");
                }
                else{
                    fread(T1_Niveau, sizeof(Niveau), 1 , Fichier_Niv);
                    id_plus=T1_Niveau[1].Id_Niveau;
                }
                free(T1_Niveau);
                for(i=0;i<a;i++){
                    T_Niveau[i].Id_Niveau=id_plus+i;
                    niv:
                    printf("\nVEUILLEZ ENTRER LE NUMERO DU NIVEAU A ENREGISTRER:\t");
                    scanf("%d",&T_Niveau[i].Num_Niveau);
                    if(Verifie_Niveau(T_Niveau[i].Num_Niveau)!=1){
                    printf("\nNouveau niveau enregistre");
                    }
                    else{
                        printf("Ce niveau existe deja!!! Veuillez entrer un niveau different");
                        goto niv;
                    }
                }// Fin de la récupération au clavier des informations
             }

        //Début de l'enregistrement dans le fichier
            fwrite(T_Niveau, sizeof(Niveau), a, Fichier_Niv);
            if (fclose(Fichier_Niv)){
                printf("Le fichier n'a pas ete correctement ecrit.\n");
            }
            printf("Ecriture dans le fichier reussi!");
            fclose(Fichier_Niv);
            free(T_Niveau);  // On libère la mémoire allouée avec malloc, on n'en a plus besoin
            }
        else{
            Ajout_Niveaux(a);
        }
    }

int main() {
    Ajout_Niveaux(3);
    return 0;
    }
