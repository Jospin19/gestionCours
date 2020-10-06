#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//Déclaration de la structure des Cours
    typedef struct Cours{
         int Id_Cours;
        char Nom_Cours[30];
         int Quota;
    }Cours;

//Déclaration du pointeur vers le fichier des Cours
    FILE *  Fichier_Cours=NULL;

//Déclaration des pointeurs qui serviront a creer les tableaux pour la manipulation des Cours
    Cours * T_Cours, * T1_Cours, * T_Rech_Cours;

//Déclaration de la fonction qui testera si le fichier des Cours est vide
    int testSiFichierVide(FILE* fichier){
        int caracterePremier = 0;
        //On lit le prmeier caractère du fichier
        caracterePremier = fgetc(fichier);
        if(caracterePremier==EOF){
            return 1;//le fichier est vide donc on retourne 1
        }
    return 0;//le fichier n'est pas vide donc on retourne 0
    }


//Déclaration de la fonction qui recuperera l'ID du dernier Cours
    int Recupere_ID(int num_niv){
        int j=1;
        size_t f=1;
        if((T1_Cours=malloc(100 * sizeof(Cours)))==NULL){
                printf("Echec de creation du taleau des Cours");
        }
        else{
            switch(num_niv){
            case 1:
                Fichier_Cours = fopen("Files/File_Cours_Niv1.bin", "rb+");
                if (Fichier_Cours != NULL){
                    if(testSiFichierVide(Fichier_Cours)==1){
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
                    printf("Erreur lors de l'ouverture du fichier.\n");
                    printf("Pressez une touche...");
                    _getch();
                }
            break;
            case 2:
                Fichier_Cours = fopen("Files/File_Cours_Niv2.bin", "rb+");
                if (Fichier_Cours != NULL){
                    if(testSiFichierVide(Fichier_Cours)==1){
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
                    printf("Erreur lors de l'ouverture du fichier.\n");
                    printf("Pressez une touche...");
                    _getch();
                }
            break;
            case 3:
                Fichier_Cours = fopen("Files/File_Cours_Niv3.bin", "rb+");
                if (Fichier_Cours != NULL){
                    if(testSiFichierVide(Fichier_Cours)==1){
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
                    printf("Erreur lors de l'ouverture du fichier.\n");
                    printf("Pressez une touche...");
                    _getch();
                }
            break;
        }
    }
    }

 //Déclaration de la fonction qui verifira si un Cours existe déja ou pas
    int Verifie_Cours(int num_niv,char N_C[30]){
        int i=0,cpte=0,maxi;
        switch(num_niv){
        case 1:
            maxi=Recupere_ID(num_niv);
            if((T_Rech_Cours=malloc(maxi * sizeof(Cours)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Cours = fopen("Files/File_Cours_Niv1.bin", "rb");
                if (Fichier_Cours != NULL){
                    fread(T_Rech_Cours, sizeof(Cours), maxi, Fichier_Cours);
                    fclose(Fichier_Cours);
                }
                else{
                    printf("Erreur lors de l'ouverture du fichier.\n");
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
            break;
        case 2:
            maxi=Recupere_ID(num_niv);
            if((T_Rech_Cours=malloc(maxi * sizeof(Cours)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Cours = fopen("Files/File_Cours_Niv2.bin", "rb");
                if (Fichier_Cours != NULL){
                    fread(T_Rech_Cours, sizeof(Cours), maxi, Fichier_Cours);
                    fclose(Fichier_Cours);
                }
                else{
                    printf("Erreur lors de l'ouverture du fichier.\n");
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
            break;
        case 3:
            maxi=Recupere_ID(num_niv);
            if((T_Rech_Cours=malloc(maxi * sizeof(Cours)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Cours = fopen("Files/File_Cours_Niv3.bin", "rb");
                if (Fichier_Cours != NULL){
                    fread(T_Rech_Cours, sizeof(Cours), maxi, Fichier_Cours);
                    fclose(Fichier_Cours);
                }
                else{
                    printf("Erreur lors de l'ouverture du fichier.\n");
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
            break;
        }
    }


//Déclaration de la fonction qui ajoute Cours
//Cette procédure contient les instructions d'initialisation du fichier des Cours
    void Ajout_Cours(int a,int num_niv){
        int i,id_plus,r,s=0;
         // On alloue de la mémoire pour le tableau des Cours
        if((T_Cours=malloc(a * sizeof(Cours)))==NULL){
            printf("Echec de creation du tableau des Cours!!");
        }
        else{
            //On récupère le dernier ID
            for(i=0;i<a;i++){
                    id_plus=Recupere_ID(num_niv);
                    T_Cours[i].Id_Cours=id_plus+2;
                    Crs:
                    printf("\nVEUILLEZ ENTRER LE NOM DE VOTRE COURS:\t");
                    scanf("%s",&T_Cours[i].Nom_Cours);
                    if(Verifie_Cours(num_niv,T_Cours[i].Nom_Cours)>=1){
                        goto Crs;
                    }
                    else{
                        Quo:
                        printf("\VEUILLEZ ENTRER LE QUOTA DE CE COURS:\t");
                        r=scanf("%d",&T_Cours[i].Quota);
                        if(r!=1){
                            do{
                                s=2;
                                scanf("%*[^\n]");
                                goto Quo;
                            }while(s=2);
                        }
                        // Fin de la récupération au clavier des informations
                        switch(num_niv){
                        case 1:
                            Fichier_Cours = fopen("Files/File_Cours_Niv1.bin", "ab");
                            if (Fichier_Cours != NULL){
                                //Début de l'enregistrement dans le fichier
                                fwrite(T_Cours, sizeof(Cours), a, Fichier_Cours);
                                if (fclose(Fichier_Cours)){
                                    printf("Le fichier n'a pas ete correctement ecrit.\n");
                                }
                                else{
                                    printf("Ecriture dans le fichier reussi!");
                                    fclose(Fichier_Cours);
                                }
                            }
                            else{
                                printf("L ouverture du fichier n a pas reussi!!");
                            }
                            break;
                        case 2:
                            Fichier_Cours = fopen("Files/File_Cours_Niv2.bin", "ab");
                            if (Fichier_Cours != NULL){
                                //Début de l'enregistrement dans le fichier
                                fwrite(T_Cours, sizeof(Cours), a, Fichier_Cours);
                                if (fclose(Fichier_Cours)){
                                    printf("Le fichier n'a pas ete correctement ecrit.\n");
                                }
                                else{
                                    printf("Ecriture dans le fichier reussi!");
                                    fclose(Fichier_Cours);
                                }
                            }
                            else{
                                printf("L ouverture du fichier n a pas reussi!!");
                            }
                            break;
                        case 3:
                            Fichier_Cours = fopen("Files/File_Cours_Niv3.bin", "ab");
                            if (Fichier_Cours != NULL){
                                //Début de l'enregistrement dans le fichier
                                fwrite(T_Cours, sizeof(Cours), a, Fichier_Cours);
                                if (fclose(Fichier_Cours)){
                                    printf("Le fichier n'a pas ete correctement ecrit.\n");
                                }
                                else{
                                    printf("Ecriture dans le fichier reussi!");
                                    fclose(Fichier_Cours);
                                }
                            }
                            else{
                                printf("L ouverture du fichier n a pas reussi!!");
                            }
                            break;

                        }
                        }
            }

        }
        free(T_Cours);
    }


//Déclaration Affichera les Cours inscrits ou enreistrés
    void Afficher_Cours(int num_niv){  //Cette procédure contient les instructions d'initialisation du fichier des Cours
        int i=0,maxi;
        maxi=Recupere_ID(num_niv);
         // On alloue de la mémoire pour le taleau des Cours
        if((T_Cours=malloc(maxi * sizeof(Cours)))==NULL){
                printf("Echec de creation du tableau des Cours!!");
        }
        else{
            switch(num_niv){
            case 1:
                Fichier_Cours = fopen("Files/File_Cours_Niv1.bin", "rb+");
                if (Fichier_Cours != NULL){
                    //Début de l'enregistrement dans le fichier
                    fread(T_Cours, sizeof(Cours), maxi, Fichier_Cours);
                    fclose(Fichier_Cours);
                }
                else{
                    printf("L ouverture du fichier n a pas reussi!!");
                }
                break;
            case 2:
                Fichier_Cours = fopen("Files/File_Cours_Niv2.bin", "rb+");
                if (Fichier_Cours != NULL){
                    //Début de l'enregistrement dans le fichier
                    fread(T_Cours, sizeof(Cours), maxi, Fichier_Cours);
                    fclose(Fichier_Cours);
                }
                else{
                    printf("L ouverture du fichier n a pas reussi!!");
                }
                break;
            case 3:
                Fichier_Cours = fopen("Files/File_Cours_Niv3.bin", "rb+");
                if (Fichier_Cours != NULL){
                    //Début de l'enregistrement dans le fichier
                    fread(T_Cours, sizeof(Cours), maxi, Fichier_Cours);
                    fclose(Fichier_Cours);
                }
                else{
                    printf("L ouverture du fichier n a pas reussi!!");
                }
                break;
            }
            for(i = 0 ; i < maxi; i++){
                    printf("ID:\t%d\t Cours:\t%s\tQUOTA ACTUEL:\t%d\n",T_Cours[i].Id_Cours,T_Cours[i].Nom_Cours,T_Cours[i].Quota);
                }
        }
        free(T_Cours);
     }


int main(){
//Déclartion de la fonction qui vérifie si un Cours existe ou pas
    Ajout_Cours(1,1);
    Afficher_Cours(1);
    return 0;
    }
