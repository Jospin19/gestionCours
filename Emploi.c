#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

//Déclaration de la structure des seances
    typedef struct Seance{
        int Id_Seance;
        int niv;
        char Code_Fil1[2];
        char Lettre_Salle1[1];
        char Matricule1[9];
        char Nom_Professeur1[30];
        char Nom_Cours[30];
        char Date_Seance[30];
    }Seance;

//Déclaration de la structure des Emploi
    typedef struct Emploi{
        int Id_Emploi;
        char classe[20];
        char Date_Cours[30];
        Seance Empl[4][6];
    }Emploi;

//Déclaration d'une structure hybride pour les prof
    typedef struct Professeur1{
        int Id_Professeur;
        char Matricule[20];
        char Nom_Professeur[30];
    }Professeur1;

//Déclaration d'une structure hybride pour les Salles
    typedef struct Salle2{
        int Num_Classe;
        int Id_Salle;
        char Code_Filiere1[20];
        char Lettre_Salle[1];
    }Salle2;

//Déclaration d'une structure hybride pour les Cours
    typedef struct Cours2{
         int Id_Cours;
        char Nom_Cours[30];
         int Quota;
    }Cours2;

//Déclaration du pointeur vers le fichier des Salle
    FILE *  Fichier_Empl=NULL;
    FILE * Fichier_Sea=NULL;
    FILE * Fichier_Sal2=NULL;
    FILE * Fichier_Cr2=NULL;
    FILE * Fichier_Prof1=NULL;

//Déclaration des pointeurs qui serviront a creer les tableaux pour la manipulation des Salles
    Emploi * T_Emploi, * T1_Emploi, * T_Rech_Empl;
    Seance * T_Seance, * T1_Seance, * T_Rech_Sean;
    Salle2 * T_Rech_Sal2;
    Cours2 * T_Rech_Cours2;
    Professeur1 * T_Rech_Prof1;

//Déclaration de la fonction qui testera si le fichier des Salles est vide
    int testSiFichierVide(FILE* fichier){
        int caracterePremier = 0;
        //On lit le prmeier caractère du fichier
        caracterePremier = fgetc(fichier);
        if(caracterePremier==EOF){
            return 1;//le fichier est vide donc on retourne 1
        }
    return 0;//le fichier n'est pas vide donc on retourne 0
    }


//Déclaration de la fonction qui recuperera l'ID du dernier Salle
    int Recupere_IDE(){
        int j=1;
        size_t f=1;
        if((T1_Emploi=malloc(100 * sizeof(Emploi)))==NULL){
                printf("Echec de creation du taleau des Emploi");
        }
        else{
            Fichier_Empl = fopen("Files/File_Emploi_tps.bin", "rb+");
            if (Fichier_Empl != NULL){
                if(testSiFichierVide(Fichier_Empl)==1){
                    return 1;
                }
                else
                {
                    f+=fread(T1_Emploi, sizeof(Emploi), 100 , Fichier_Empl);
                    return f;
                    fclose(Fichier_Empl);
                    free(T1_Emploi);
                }
            }
            else{
                printf("Le fichier n a pas pu etre ouvert");
            }
    }
    }


    int Recupere_IDS(){
        int j=1;
        size_t f=1;
        if((T1_Seance=malloc(100 * sizeof(Seance)))==NULL){
                printf("Echec de creation du taleau des Seance");
        }
        else{
            Fichier_Sea = fopen("Files/File_Seance.bin", "rb+");
            if (Fichier_Sea != NULL){
                if(testSiFichierVide(Fichier_Sea)==1){
                    return 1;
                }
                else
                {
                    f+=fread(T1_Seance, sizeof(Seance), 100 , Fichier_Sea);
                    return f;
                    fclose(Fichier_Sea);
                    free(T1_Seance);
                }
        }
        else{
            printf("Le fichier na pas etre ouvert");
        }
    }
    }


 //Déclaration de la fonction qui verifira si un Salle existe déja ou pas
    int Verifie_Salle1(int num_niv,char L[1],char C_F[20]){
        int i=0,cpte=0,maxi;
        switch(num_niv){
        case 1:
            maxi=20;
            if((T_Rech_Sal2=malloc(maxi * sizeof(Salle2)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Sal2 = fopen("Files/File_Salle_Niv1.bin", "rb");
                if (Fichier_Sal2 != NULL){
                    fread(T_Rech_Sal2, sizeof(Salle2), maxi, Fichier_Sal2);
                    fclose(Fichier_Sal2);
                }
                else{
                    printf("Erreur lors de l'ouverture du fichier.\n");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if((T_Rech_Sal2[i].Num_Classe==1)&&(strcmp(T_Rech_Sal2[i].Lettre_Salle,L)==0)&&(strcmp(T_Rech_Sal2[i].Code_Filiere1,C_F)==0)){
                        cpte+=1;
                    }
                    else{
                        continue;
                    }
                }
                return cpte;
            }
            free(T_Rech_Sal2);
            break;
        case 2:
            maxi=20;
            if((T_Rech_Sal2=malloc(maxi * sizeof(Salle2)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Sal2 = fopen("Files/File_Salle_Niv2.bin", "rb");
                if (Fichier_Sal2 != NULL){
                    fread(T_Rech_Sal2, sizeof(Salle2), maxi, Fichier_Sal2);
                    fclose(Fichier_Sal2);
                }
                else{
                    printf("Erreur lors de l'ouverture du fichier.\n");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if((T_Rech_Sal2[i].Num_Classe==2)&&(strcmp(T_Rech_Sal2[i].Lettre_Salle,L)==0)&&(strcmp(T_Rech_Sal2[i].Code_Filiere1,C_F)==0)){
                        cpte+=1;
                    }
                    else{
                        continue;
                    }
                }
                return cpte;
            }
            free(T_Rech_Sal2);
            break;
        case 3:
            maxi=20;
            if((T_Rech_Sal2=malloc(maxi * sizeof(Salle2)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Sal2 = fopen("Files/File_Salle_Niv3.bin", "rb");
                if (Fichier_Sal2 != NULL){
                    fread(T_Rech_Sal2, sizeof(Salle2), maxi, Fichier_Sal2);
                    fclose(Fichier_Sal2);
                }
                else{
                    printf("Erreur lors de l'ouverture du fichier.\n");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if((T_Rech_Sal2[i].Num_Classe==3)&& (strcmp(T_Rech_Sal2[i].Lettre_Salle,L)==0)&&(strcmp(T_Rech_Sal2[i].Code_Filiere1,C_F)==0)){
                        cpte+=1;
                    }
                    else{
                        continue;
                    }
                }
                return cpte;
            }
            free(T_Rech_Sal2);
            break;
        }
    }


//Déclaration de la fonction qui vérifiera si un professeur existe déja
    int Verifie_Professeur1(char N_P[30]){
        int i=0,cpte=0;
        int maxi=100;
        if((T_Rech_Prof1=malloc(maxi * sizeof(Professeur1)))==NULL){
                printf("La verification est impossible!!!");
            }
        else{
            Fichier_Prof1 = fopen("Files/File_Professeur.bin", "rb");
            if (Fichier_Prof1 != NULL){
                fread(T_Rech_Prof1, sizeof(Professeur1), maxi, Fichier_Prof1);
                fclose(Fichier_Prof1);
            }
            else{
                printf("Erreur lors de l'ouverture du fichier.\n");
                printf("Pressez une touche...");
                _getch();
            }
            for(i=0;i<=maxi;i++){
                if((strcmp(T_Rech_Prof1[i].Nom_Professeur,N_P)==0)){
                    cpte+=1;
                }
                else{
                    continue;
                }
            }
            return cpte;
        }
        free(T_Rech_Prof1);
    }

//Déclaration de la fonction qui vérifie si un cours existe
    int Verifie_Cours2(int num_niv,char N_C[30]){
        int i=0,cpte=0,maxi;
        switch(num_niv){
        case 1:
            maxi=100;
            if((T_Rech_Cours2=malloc(maxi * sizeof(Cours2)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Cr2 = fopen("Files/File_Cours_Niv1.bin", "rb");
                if (Fichier_Cr2 != NULL){
                    fread(T_Rech_Cours2, sizeof(Cours2), maxi, Fichier_Cr2);
                    fclose(Fichier_Cr2);
                }
                else{
                    printf("Erreur lors de l'ouverture du fichier.\n");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if(strcmp(T_Rech_Cours2[i].Nom_Cours,N_C)==0){
                        cpte+=1;
                    }
                    else{
                        continue;
                    }
                }

                return cpte;
            }
            free(T_Rech_Cours2);
            break;
        case 2:
            maxi=100;
            if((T_Rech_Cours2=malloc(maxi * sizeof(Cours2)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Cr2 = fopen("Files/File_Cours_Niv2.bin", "rb");
                if (Fichier_Cr2 != NULL){
                    fread(T_Rech_Cours2, sizeof(Cours2), maxi, Fichier_Cr2);
                    fclose(Fichier_Cr2);
                }
                else{
                    printf("Erreur lors de l'ouverture du fichier.\n");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if(strcmp(T_Rech_Cours2[i].Nom_Cours,N_C)==0){
                        cpte+=1;
                    }
                    else{
                        continue;
                    }
                }

                return cpte;
            }
            free(T_Rech_Cours2);
            break;
        case 3:
            maxi=100;
            if((T_Rech_Cours2=malloc(maxi * sizeof(Cours2)))==NULL){
                printf("La verification est impossible!!!");
            }
            else{
                Fichier_Cr2 = fopen("Files/File_Cours_Niv3.bin", "rb");
                if (Fichier_Cr2 != NULL){
                    fread(T_Rech_Cours2, sizeof(Cours2), maxi, Fichier_Cr2);
                    fclose(Fichier_Cr2);
                }
                else{
                    printf("Erreur lors de l'ouverture du fichier.\n");
                    printf("Pressez une touche...");
                    _getch();
                }
                for(i=0;i<=maxi;i++){
                    if(strcmp(T_Rech_Cours2[i].Nom_Cours,N_C)==0){
                        cpte+=1;
                    }
                    else{
                        continue;
                    }
                }

                return cpte;
            }
            free(T_Rech_Cours2);
            break;
    }
    }

//Déclaration de la fonction qui ajoute Salle
//Cette procédure contient les instructions d'initialisation du fichier des Salles
    void Ajout_Emploi(){
        int i=0,v=0,j,id_plusS,id_plusE;
        char d;
        /* lire l'heure courante */
        time_t now = time (NULL);
        /* la convertir en heure locale */
        struct tm tm_now = *localtime (&now);

         // On alloue de la mémoire pour le tableau des Salles
        if(((T_Seance=malloc(24 * sizeof(Seance)))==NULL) || (T_Emploi=malloc(1 * sizeof(Emploi)))==NULL){
            printf("Echec de creation des tableaux!!");
        }
        else{
            //On récupère le dernier ID
            for(j=0;i<=24;j++){
                    id_plusE=Recupere_IDE();
                    id_plusS=Recupere_IDS();
                    strftime (T_Seance[j].Date_Seance, sizeof T_Seance[j].Date_Seance, "%d/%m/%Y", &tm_now);
                    T_Seance[j].Id_Seance=id_plusS+2;
                    T_Emploi[1].Id_Emploi=id_plusE+2;
                    switch(i){
                            case 0:
                                printf("JOURNEE DU LUNDI");
                                classe:
                                printf("VEUILLEZ ENTRER LA FILIERE, LE NIVEAU ET LA LETTRE DE LA SALLE[EXEMPLE SR 1 A]");
                                scanf("%s%*s%d%*s%s",&T_Seance[j].Code_Fil1,&T_Seance[j].niv,&T_Seance[j].Lettre_Salle1);
                                if(Verifie_Salle1(T_Seance[j].niv,T_Seance[j].Lettre_Salle1,T_Seance[j].Code_Fil1)==0){
                                    printf("PARAMETRES INCORRECTES");
                                    goto classe;
                                }
                                prof:
                                printf("\nVEUILLEZ ENTRER LE NOM DU PROFESSEUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Professeur1);
                                if((Verifie_Professeur1(T_Seance[j].Nom_Professeur1)==0)){
                                    printf("CE PROFESSEUR N EXISTE PAS\n");
                                    goto prof;
                                }
                                Cours:
                                printf("\nVEUILLEZ ENTRER LE NOM DU COUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Cours);
                                if(Verifie_Cours2(T_Seance[j].niv,T_Seance[j].Nom_Cours)==0){
                                    printf("CE COUR N EXISTE PAS");
                                    goto Cours;
                                }
                                break;
                            case 1:
                                printf("JOURNEE DU MARDI");
                                printf("VEUILLEZ ENTRER LA FILIERE, LE NIVEAU ET LA LETTRE DE LA SALLE[EXEMPLE SR 1 A]");
                                scanf("%s%*s%d%*s%s",&T_Seance[j].Code_Fil1,&T_Seance[j].niv,&T_Seance[j].Lettre_Salle1);
                                if(Verifie_Salle1(T_Seance[j].niv,T_Seance[j].Lettre_Salle1,T_Seance[j].Code_Fil1)==0){
                                    printf("PARAMETRES INCORRECTES");
                                    goto classe;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU PROFESSEUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Professeur1);
                                if((Verifie_Professeur1(T_Seance[j].Nom_Professeur1)==0)){
                                    printf("CE PROFESSEUR N EXISTE PAS\n");
                                    goto prof;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU COUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Cours);
                                if(Verifie_Cours2(T_Seance[j].niv,T_Seance[j].Nom_Cours)==0){
                                    printf("CE COUR N EXISTE PAS");
                                    goto Cours;
                                }
                                break;
                            case 2:
                                printf("JOURNEE DU MERCREDI");
                                printf("VEUILLEZ ENTRER LA FILIERE, LE NIVEAU ET LA LETTRE DE LA SALLE[EXEMPLE SR 1 A]");
                                scanf("%s%*s%d%*s%s",&T_Seance[j].Code_Fil1,&T_Seance[j].niv,&T_Seance[j].Lettre_Salle1);
                                if(Verifie_Salle1(T_Seance[j].niv,T_Seance[j].Lettre_Salle1,T_Seance[j].Code_Fil1)==0){
                                    printf("PARAMETRES INCORRECTES");
                                    goto classe;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU PROFESSEUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Professeur1);
                                if((Verifie_Professeur1(T_Seance[j].Nom_Professeur1)==0)){
                                    printf("CE PROFESSEUR N EXISTE PAS\n");
                                    goto prof;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU COUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Cours);
                                if(Verifie_Cours2(T_Seance[j].niv,T_Seance[j].Nom_Cours)==0){
                                    printf("CE COUR N EXISTE PAS");
                                    goto Cours;
                                }
                                break;
                            case 3:
                                printf("JOURNEE DU JEUDI");
                                printf("VEUILLEZ ENTRER LA FILIERE, LE NIVEAU ET LA LETTRE DE LA SALLE[EXEMPLE SR 1 A]");
                                scanf("%s%*s%d%*s%s",&T_Seance[j].Code_Fil1,&T_Seance[j].niv,&T_Seance[j].Lettre_Salle1);
                                if(Verifie_Salle1(T_Seance[j].niv,T_Seance[j].Lettre_Salle1,T_Seance[j].Code_Fil1)==0){
                                    printf("PARAMETRES INCORRECTES");
                                    goto classe;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU PROFESSEUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Professeur1);
                                if((Verifie_Professeur1(T_Seance[j].Nom_Professeur1)==0)){
                                    printf("CE PROFESSEUR N EXISTE PAS\n");
                                    goto prof;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU COUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Cours);
                                if(Verifie_Cours2(T_Seance[j].niv,T_Seance[j].Nom_Cours)==0){
                                    printf("CE COUR N EXISTE PAS");
                                    goto Cours;
                                }
                                break;
                            case 4:
                                printf("JOURNEE DU VENDREDI");
                                printf("VEUILLEZ ENTRER LA FILIERE, LE NIVEAU ET LA LETTRE DE LA SALLE[EXEMPLE SR 1 A]");
                                scanf("%s%*s%d%*s%s",&T_Seance[j].Code_Fil1,&T_Seance[j].niv,&T_Seance[j].Lettre_Salle1);
                                if(Verifie_Salle1(T_Seance[j].niv,T_Seance[j].Lettre_Salle1,T_Seance[j].Code_Fil1)==0){
                                    printf("PARAMETRES INCORRECTES");
                                    goto classe;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU PROFESSEUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Professeur1);
                                if((Verifie_Professeur1(T_Seance[j].Nom_Professeur1)==0)){
                                    printf("CE PROFESSEUR N EXISTE PAS\n");
                                    goto prof;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU COUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Cours);
                                if(Verifie_Cours2(T_Seance[j].niv,T_Seance[j].Nom_Cours)==0){
                                    printf("CE COUR N EXISTE PAS");
                                    goto Cours;
                                }
                                break;
                                printf("JOURNEE DU VENDREDI");
                                printf("VEUILLEZ ENTRER LA FILIERE, LE NIVEAU ET LA LETTRE DE LA SALLE[EXEMPLE SR 1 A]");
                                scanf("%s%*s%d%*s%s",&T_Seance[j].Code_Fil1,&T_Seance[j].niv,&T_Seance[j].Lettre_Salle1);
                                if(Verifie_Salle1(T_Seance[j].niv,T_Seance[j].Lettre_Salle1,T_Seance[j].Code_Fil1)==0){
                                    printf("PARAMETRES INCORRECTES");
                                    goto classe;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU PROFESSEUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Professeur1);
                                if((Verifie_Professeur1(T_Seance[j].Nom_Professeur1)==0)){
                                    printf("CE PROFESSEUR N EXISTE PAS\n");
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU COUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Cours);
                                if(Verifie_Cours2(T_Seance[j].niv,T_Seance[j].Nom_Cours)==0){
                                    printf("CE COUR N EXISTE PAS");
                                    goto Cours;
                                }
                                break;
                            case 5:
                                printf("JOURNEE DU SAMEDI");
                                printf("VEUILLEZ ENTRER LA FILIERE, LE NIVEAU ET LA LETTRE DE LA SALLE[EXEMPLE SR 1 A]");
                                scanf("%s%*s%d%*s%s",&T_Seance[j].Code_Fil1,&T_Seance[j].niv,&T_Seance[j].Lettre_Salle1);
                                if(Verifie_Salle1(T_Seance[j].niv,T_Seance[j].Lettre_Salle1,T_Seance[j].Code_Fil1)==0){
                                    printf("PARAMETRES INCORRECTES");
                                    goto classe;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU PROFESSEUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Professeur1);
                                if((Verifie_Professeur1(T_Seance[j].Nom_Professeur1)==0)){
                                    printf("CE PROFESSEUR N EXISTE PAS\n");
                                    goto prof;
                                }
                                printf("\nVEUILLEZ ENTRER LE NOM DU COUR:\t");
                                scanf("%s",&T_Seance[j].Nom_Cours);
                                if(Verifie_Cours2(T_Seance[j].niv,T_Seance[j].Nom_Cours)==0){
                                    printf("CE COUR N EXISTE PAS");
                                    goto Cours;
                                }
                                break;
                            }
                    }//Fin du switch// Fin de la récupération au clavier des informations
                    Fichier_Sea = fopen("Files/File_Seance.bin", "ab");
                    if (Fichier_Sea != NULL){
                        //Début de l'enregistrement dans le fichier
                        fwrite(T_Seance, sizeof(Seance), 24, Fichier_Sea);
                        if (fclose(Fichier_Sea)){
                            printf("Le fichier n'a pas ete correctement ecrit.\n");
                        }
                        else{
                            printf("Ecriture des seances reussie!");
                            fclose(Fichier_Sea);
                        }
                    }
                    else{
                        printf("Le fichier n a pas put etre ouvert!!");
                    }
        }
    }

/*
//Déclaration Affichera les Salles inscrits ou enreistrés
    void Afficher_Emploi(int num_niv){  //Cette procédure contient les instructions d'initialisation du fichier des Salles
        int i=0,maxi;
        maxi=Recupere_ID(num_niv);
         // On alloue de la mémoire pour le taleau des Salles
        if((T_Salle=malloc(maxi * sizeof(Salle)))==NULL){
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
                    printf("L ouverture du fichier n a pas reussi!!");
                }
                break;
            }
            for(i = 0 ; i < maxi; i++){
                    printf("ID: \t%d \t Salle: \t%s%d%s \n",T_Salle[i].Id_Salle,T_Salle[i].Code_Filiere1,T_Salle[i].Num_Classe,T_Salle[i].Lettre_Salle);
                }
        }
        free(T_Salle);
     }

*/
int main(){
//Déclartion de la fonction qui vérifie si un Salle existe ou pas
    Ajout_Emploi(1);
    return 0;
    }
