#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

//Déclaration de la structure des Salle
    typedef struct Salle{
        int Num_Classe;
        int Id_Salle;
        char Code_Filiere1[20];
        char Lettre_Salle[1];
    }Salle;

    typedef struct Filiere1{
         int Id_fil;
        char Code_Filiere[20];
        char Nom_Filiere[30];
    }Filiere1;

//Déclaration du pointeur vers le fichier des Salle
    FILE *  Fichier_Sal=NULL;
    FILE * Fichier_Fil1=NULL;

//Déclaration des pointeurs qui serviront a creer les tableaux pour la manipulation des Salles
    Salle * T_Salle, * T1_Salle, * T_Rech_Sal;
    Filiere1 * T_Rech_Fil;

//Déclaration de la fonction qui testera si le fichier des Salles est vide
    int testSiFichierVideSa(FILE* fichier){
        int caracterePremier = 0;
        //On lit le prmeier caractère du fichier
        caracterePremier = fgetc(fichier);
        if(caracterePremier==EOF){
            return 1;//le fichier est vide donc on retourne 1
        }
    return 0;//le fichier n'est pas vide donc on retourne 0
    }


//Déclaration de la fonction qui recuperera l'ID du dernier Salle
    int Recupere_IDSa(int num_niv){
        int j=1;
        size_t f=1;
        if((T1_Salle=malloc(100 * sizeof(Salle)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("Echec de creation du taleau des Salles");
        }
        else{
            switch(num_niv){
            case 1:
                Fichier_Sal = fopen("Files/File_Salle_Niv1.bin", "rb+");
                if (Fichier_Sal != NULL){
                    if(testSiFichierVideSa(Fichier_Sal)==1){
                        return 1;
                    }
                    else
                    {
                        f+=fread(T1_Salle, sizeof(Salle), 100 , Fichier_Sal);
                        return f;
                        fclose(Fichier_Sal);
                        free(T1_Salle);
                    }
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("Erreur lors de l'ouverture du fichier.");
                    printf("Pressez une touche...");
                    _getch();
                }
            break;
            case 2:
                Fichier_Sal = fopen("Files/File_Salle_Niv2.bin", "rb+");
                if (Fichier_Sal != NULL){
                    if(testSiFichierVideSa(Fichier_Sal)==1){
                        return 1;
                    }
                    else
                    {
                        f+=fread(T1_Salle, sizeof(Salle), 100 , Fichier_Sal);
                        return f;
                        fclose(Fichier_Sal);
                        free(T1_Salle);
                    }
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("Erreur lors de l'ouverture du fichier.");
                    printf("Pressez une touche...");
                    _getch();
                }
            break;
            case 3:
                Fichier_Sal = fopen("Files/File_Salle_Niv3.bin", "rb+");
                if (Fichier_Sal != NULL){
                    if(testSiFichierVideSa(Fichier_Sal)==1){
                        return 1;
                    }
                    else
                    {
                        f+=fread(T1_Salle, sizeof(Salle), 100 , Fichier_Sal);
                        return f;
                        fclose(Fichier_Sal);
                        free(T1_Salle);
                    }
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("Erreur lors de l'ouverture du fichier.");
                    printf("Pressez une touche...");
                    _getch();
                }
            break;
        }
    }
    }

//Déclaration de la fonction qui verifiera q'une filiere existe avant d'autoriser la création de salles dans cette derniere
    int Verifie_Filiere1(char C[20]){
        int i=0,cpte=0;
        int maxi=5;
        if((T_Rech_Fil=malloc(maxi * sizeof(Filiere1)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("La verification est impossible!!!");
            }
        else{
            Fichier_Fil1 = fopen("Files/File_Filiere.bin", "rb");
            if (Fichier_Fil1 != NULL){
                fread(T_Rech_Fil, sizeof(Filiere1), maxi, Fichier_Fil1);
                fclose(Fichier_Fil1);
            }
            else{
                gotoxy(71,41);
                coloration(12);
                printf("Erreur lors de l'ouverture du fichier.");
                printf("Pressez une touche...");
                _getch();
            }
            for(i=0;i<=maxi;i++){
                if((strcmp(T_Rech_Fil[i].Code_Filiere,C)==0)){
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

 //Déclaration de la fonction qui verifira si un Salle existe déja ou pas
    int Verifie_Salle(int num_niv,char L[1]){
        int i=0,cpte=0,maxi;
        switch(num_niv){
        case 1:
            maxi=Recupere_IDSa(num_niv);
            if((T_Rech_Sal=malloc(maxi * sizeof(Salle)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Sal = fopen("Files/File_Salle_Niv1.bin", "rb");
                if (Fichier_Sal != NULL){
                    fread(T_Rech_Sal, sizeof(Salle), maxi, Fichier_Sal);
                    fclose(Fichier_Sal);
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("Erreur lors de l'ouverture du fichier.");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if(strcmp(T_Rech_Sal[i].Lettre_Salle,L)==0){
                        cpte+=1;
                    }
                    else{
                        continue;
                    }
                }
                return cpte;
            }
            free(T_Rech_Sal);
            break;
        case 2:
            maxi=Recupere_IDSa(num_niv);
            if((T_Rech_Sal=malloc(maxi * sizeof(Salle)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Sal = fopen("Files/File_Salle_Niv2.bin", "rb");
                if (Fichier_Sal != NULL){
                    fread(T_Rech_Sal, sizeof(Salle), maxi, Fichier_Sal);
                    fclose(Fichier_Sal);
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("Erreur lors de l'ouverture du fichier.");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if(strcmp(T_Rech_Sal[i].Lettre_Salle,L)==0){
                        cpte+=1;
                    }
                    else{
                        continue;
                    }
                }
                return cpte;
            }
            free(T_Rech_Sal);
            break;
        case 3:
            maxi=Recupere_IDSa(num_niv);
            if((T_Rech_Sal=malloc(maxi * sizeof(Salle)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Sal = fopen("Files/File_Salle_Niv3.bin", "rb");
                if (Fichier_Sal != NULL){
                    fread(T_Rech_Sal, sizeof(Salle), maxi, Fichier_Sal);
                    fclose(Fichier_Sal);
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("Erreur lors de l'ouverture du fichier.");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if(strcmp(T_Rech_Sal[i].Lettre_Salle,L)==0){
                        cpte+=1;
                    }
                    else{
                        continue;
                    }
                }
                return cpte;
            }
            free(T_Rech_Sal);
            break;
        }
    }


//Déclaration de la fonction qui ajoute Salle
//Cette procédure contient les instructions d'initialisation du fichier des Salles
    void Ajout_Salles(int a,int num_niv){
        int i,id_plus;
         // On alloue de la mémoire pour le tableau des Salles
        if((T_Salle=malloc(a * sizeof(Salle)))==NULL){
            gotoxy(71,41);
            coloration(12);
            printf("Echec de creation du tableau des Salles!!");
        }
        else{
            //On récupère le dernier ID
            for(i=0;i<a;i++){
                    id_plus=Recupere_IDSa(num_niv);
                    T_Salle[i].Id_Salle=id_plus+2;
                    Niv:
                    coloration(7);
                    gotoxy(16,26);
                    printf("VEUILLEZ ENTRER LA FILIERE DE CETTE SALLE[UNE FILIERE EXISTANTE]:");
                    coloration(10);
                    gotoxy(84,26);
                    scanf("%s",&T_Salle[i].Code_Filiere1);
                    if((Verifie_Filiere1(T_Salle[i].Code_Filiere1)==0)||(strlen(T_Salle[i].Code_Filiere1)!=2)){
                        printf("PARAMETRES INCORRECTES");
                        gotoxy(16,26);
                        printf("                      ");
                        goto Niv;
                    }
                    else{
                        Let:
                        coloration(7);
                        gotoxy(16,28);
                        printf("VEUILLEZ ENTRER LA LETTRE DE CETTE SALLE:");
                        coloration(10);
                        gotoxy(65,28);
                        scanf("%s",&T_Salle[i].Lettre_Salle);
                        if(Verifie_Salle(num_niv,T_Salle[i].Lettre_Salle)>=1){
                            gotoxy(71,41);
                            coloration(12);
                            printf("Cette salle existe deja!!!! Entrez une lettre differente!!");
                            gotoxy(16,28);
                            printf("                      ");
                            goto Let;
                        }
                        // Fin de la récupération au clavier des informations
                        switch(num_niv){
                        case 1:
                            T_Salle[i].Num_Classe=1;
                            Fichier_Sal = fopen("Files/File_Salle_Niv1.bin", "ab");
                            if (Fichier_Sal != NULL){
                                //Début de l'enregistrement dans le fichier
                                fwrite(T_Salle, sizeof(Salle), a, Fichier_Sal);
                                if (fclose(Fichier_Sal)){
                                    gotoxy(71,41);
                                    coloration(12);
                                    printf("Le fichier n'a pas ete correctement ecrit.");
                                }
                                else{
                                    gotoxy(71,41);
                                    coloration(12);
                                    printf("Ecriture dans le fichier reussi!");
                                    fclose(Fichier_Sal);
                                }
                            }
                            else{
                                gotoxy(71,41);
                                coloration(12);
                                printf("L ouverture du fichier n a pas reussi!!");
                            }
                            break;
                        case 2:
                            T_Salle[i].Num_Classe=2;
                            Fichier_Sal = fopen("Files/File_Salle_Niv2.bin", "ab");
                            if (Fichier_Sal != NULL){
                                //Début de l'enregistrement dans le fichier
                                fwrite(T_Salle, sizeof(Salle), a, Fichier_Sal);
                                if (fclose(Fichier_Sal)){
                                    gotoxy(71,41);
                                    coloration(12);
                                    printf("Le fichier n'a pas ete correctement ecrit.");
                                }
                                else{
                                    gotoxy(71,41);
                                    coloration(12);
                                    printf("Ecriture dans le fichier reussi!");
                                    fclose(Fichier_Sal);
                                }
                            }
                            else{
                                gotoxy(71,41);
                                coloration(12);
                                printf("L ouverture du fichier n a pas reussi!!");
                            }
                            break;
                        case 3:
                            T_Salle[i].Num_Classe=3;
                            Fichier_Sal = fopen("Files/File_Salle_Niv3.bin", "ab");
                            if (Fichier_Sal != NULL){
                                //Début de l'enregistrement dans le fichier
                                fwrite(T_Salle, sizeof(Salle), a, Fichier_Sal);
                                if (fclose(Fichier_Sal)){
                                    gotoxy(71,41);
                                    coloration(12);
                                    printf("Le fichier n'a pas ete correctement ecrit.");
                                }
                                else{
                                    gotoxy(71,41);
                                    coloration(12);
                                    printf("Ecriture dans le fichier reussi!");
                                    fclose(Fichier_Sal);
                                }
                            }
                            else{
                                gotoxy(71,41);
                                coloration(12);
                                printf("L ouverture du fichier n a pas reussi!!");
                            }
                            break;

                        }
                        }
            }

        }
        free(T_Salle);
    }


//Déclaration Affichera les Salles inscrits ou enreistrés
    void Afficher_Salles(int num_niv){  //Cette procédure contient les instructions d'initialisation du fichier des Salles
        int i=0,maxi;
        maxi=Recupere_IDSa(num_niv);
         // On alloue de la mémoire pour le taleau des Salles
        if((T_Salle=malloc(maxi * sizeof(Salle)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("Echec de creation du tableau des Salles!!");
        }
        else{
            switch(num_niv){
            case 1:
                Fichier_Sal = fopen("Files/File_Salle_Niv1.bin", "rb+");
                if (Fichier_Sal != NULL){
                    //Début de l'enregistrement dans le fichier
                    fread(T_Salle, sizeof(Salle), maxi, Fichier_Sal);
                    fclose(Fichier_Sal);
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("L ouverture du fichier n a pas reussi!!");
                }
                break;
            case 2:
                Fichier_Sal = fopen("Files/File_Salle_Niv2.bin", "rb+");
                if (Fichier_Sal != NULL){
                    //Début de l'enregistrement dans le fichier
                    fread(T_Salle, sizeof(Salle), maxi, Fichier_Sal);
                    fclose(Fichier_Sal);
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("L ouverture du fichier n a pas reussi!!");
                }
                break;
            case 3:
                Fichier_Sal = fopen("Files/File_Salle_Niv3.bin", "rb+");
                if (Fichier_Sal != NULL){
                    //Début de l'enregistrement dans le fichier
                    fread(T_Salle, sizeof(Salle), maxi, Fichier_Sal);
                    fclose(Fichier_Sal);
                }
                else{
                    gotoxy(71,41);
                    coloration(12);
                    printf("L ouverture du fichier n a pas reussi!!");
                }
                break;
            }
            for(i = 0 ; i < maxi; i++){
                    coloration(10);
                    gotoxy(16,26+i);
                    printf("ID:\t%d \tSalle:\t%s%d%s ",T_Salle[i].Id_Salle,T_Salle[i].Code_Filiere1,T_Salle[i].Num_Classe,T_Salle[i].Lettre_Salle);
                }
        }
        free(T_Salle);
     }


void Sal(){
//Déclartion de la fonction qui vérifie si un Salle existe ou pas
    }
