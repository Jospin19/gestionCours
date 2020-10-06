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
        char Matricule1[20];
        char Nom_Professeur1[30];
        char Nom_Cours[30];
        char Date_Seance[30];
    }Seance;

//Variables
    int x,y;
//Déclaration de la structure des Emploi
    typedef struct Emploi{
        int Id_Emploi;
        char classe[20];
        char Date_Cours[30];
        Seance Empl[4][6];
    }Emploi;

//Déclaration du pointeur vers le fichier des Salle
    FILE *  Fichier_Empl=NULL;
    FILE * Fichier_Sea=NULL;
    FILE * Fichier_Sal2=NULL;
    FILE * Fichier_Cr2=NULL;
    FILE * Fichier_Prof1=NULL;

//Déclaration des pointeurs qui serviront a creer les tableaux pour la manipulation des Salles
    Seance * T_Seance, * T1_Seance, * T_Rech_Sean;


//Déclaration de la fonction qui testera si le fichier des Salles est vide
    int testSiFichierVideS(FILE* fichier){
        int caracterePremier = 0;
        //On lit le prmeier caractère du fichier
        caracterePremier = fgetc(fichier);
        if(caracterePremier==EOF){
            return 1;//le fichier est vide donc on retourne 1
        }
    return 0;//le fichier n'est pas vide donc on retourne 0
    }


//Déclaration de la fonction qui recuperera l'ID du dernier Salle

    int Recupere_IDS(){
        int j=1;
        size_t f=1;
        if((T1_Seance=malloc(100 * sizeof(Seance)))==NULL){
                gotoxy(71,41);
                coloration(12);
                printf("Echec de creation du taleau des Seance");
        }
        else{
            Fichier_Sea = fopen("Files/File_Seance.bin", "rb+");
            if (Fichier_Sea != NULL){
                if(testSiFichierVideS(Fichier_Sea)==1){
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
            gotoxy(71,41);
            coloration(12);
            printf("Le fichier na pas etre ouvert");
        }
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
        if((T_Seance=malloc(24 * sizeof(Seance)))==NULL){
            printf("Echec de creation des tableaux!!");
        }
        else{
            //On récupère le dernier ID
            i=0;
            for(j=0;j<=24;j++){
                    id_plusS=Recupere_IDS();
                    strftime (T_Seance[j].Date_Seance, sizeof T_Seance[j].Date_Seance, "%d/%m/%Y", &tm_now);
                    T_Seance[j].Id_Seance=id_plusS+2;
                    switch(j){
                            case 0:case 6:case 12:case 18:
                                coloration(4);
                                gotoxy(16,25);
                                printf("JOURNEE DU LUNDI            ");
                                T_Seance[j].niv=T_Seance[0].niv;
                                break;
                            case 1:case 7:case 13:case 19:
                                coloration(4);
                                gotoxy(16,25);
                                printf("JOURNEE DU MARDI            ");
                                T_Seance[j].niv=T_Seance[0].niv;
                                break;
                            case 2:case 8:case 14:case 20:
                                coloration(4);
                                gotoxy(16,25);
                                printf("JOURNEE DU MERCREDI            ");
                                T_Seance[j].niv=T_Seance[0].niv;
                                break;
                            case 3:case 9:case 15:case 21:
                                coloration(4);
                                gotoxy(16,25);
                                printf("JOURNEE DU JEUDI               ");
                                T_Seance[j].niv=T_Seance[0].niv;
                                break;
                            case 4:case 10:case 16:case 22:
                                coloration(4);
                                gotoxy(16,25);
                                printf("JOURNEE DU VENDREDI           ");
                                T_Seance[j].niv=T_Seance[0].niv;
                                break;
                            case 5:case 11:case 17:case 23:
                                coloration(4);
                                gotoxy(16,25);
                                printf("JOURNEE SAMEDI            ");
                                T_Seance[j].niv=T_Seance[0].niv;
                                break;
                    }
                    if(j==0){
                            coloration(7);
                                gotoxy(16,28);
                                printf("VEUILLEZ ENTRER LE NIVEAU:");
                                coloration(10);
                                vc:
                                gotoxy(60,28);
                                x=scanf("%d",&T_Seance[j].niv);
                                    if(x!=1){
                                        do{
                                            y=2;
                                            scanf("%*[^]");
                                            goto vc;
                                        }while(y=2);
                                    }
                                    if((T_Seance[j].niv>=4) || (T_Seance[j].niv<=0)){
                                        goto vc;
                                    }

                    }

                                prof:
                                coloration(7);
                                gotoxy(16,28);
                                printf("VEUILLEZ ENTRER LE NOM DU PROFESSEUR:");
                                coloration(10);
                                gotoxy(60,28);
                                scanf("%s              ",&T_Seance[j].Nom_Professeur1);
                                coloration(7);
                                gotoxy(80,28);
                                printf("MATRICULE:");
                                coloration(10);
                                gotoxy(92,28);
                                scanf("%s               ",&T_Seance[j].Matricule1);
                                if((Verifie_Professeur(T_Seance[j].Matricule1,T_Seance[j].Nom_Professeur1)<=0)){
                                    gotoxy(71,41);
                                    coloration(12);
                                    printf("CE PROFESSEUR N EXISTE PAS");
                                    gotoxy(16,28);
                                    goto prof;
                                }

                                Cours:
                                coloration(7);
                                gotoxy(16,30);
                                printf("VEUILLEZ ENTRER LE NOM DU COUR:");
                                coloration(10);
                                gotoxy(50,30);
                                scanf("%s",&T_Seance[j].Nom_Cours);
                                if(Verifie_Cours(T_Seance[j].niv,T_Seance[j].Nom_Cours)==0){
                                    gotoxy(71,41);
                                    coloration(12);
                                    printf("CE COUR N EXISTE PAS");
                                    gotoxy(16,30);
                                    printf("                          ");
                                    goto Cours;
                                }
                            }
                    }//Fin du switch// Fin de la récupération au clavier des informations
                    Fichier_Sea = fopen("Files/File_Seance.bin", "ab");
                    if (Fichier_Sea != NULL){
                        //Début de l'enregistrement dans le fichier
                        fwrite(T_Seance, sizeof(Seance), 24, Fichier_Sea);
                        if (fclose(Fichier_Sea)){
                            gotoxy(71,41);
                            coloration(12);
                            printf("Le fichier n'a pas ete correctement ecrit.");
                        }
                        else{
                            gotoxy(71,41);
                            coloration(12);
                            printf("Ecriture des seances reussie!");
                            fclose(Fichier_Sea);
                        }
                    }
                    else{
                        gotoxy(71,41);
                        coloration(12);
                        printf("Le fichier n a pas put etre ouvert!!");
                    }
                     free(T_Seance);
        }

    int Charger_Seances(){
        int i=0,cpte=0;
        int maxi=24;
        T_Seance=malloc(maxi * sizeof(Seance));
        T_Seance=malloc(100 * sizeof(Seance));
        if((T_Seance==NULL)){
                gotoxy(71,41);
                coloration(12);
                printf("La verification est impossible!!!");
            }
        else{
            Fichier_Sea = fopen("Files/File_Seance.bin", "rb+");
            if (Fichier_Sea != NULL){
                fread(T_Seance, sizeof(Seance), maxi, Fichier_Sea);
                fclose(Fichier_Sea);
            }
            else{
                gotoxy(71,41);
                coloration(12);
                printf("Erreur lors de l'ouverture du fichier.");
                printf("Pressez une touche...");
                _getch();
            }
                gotoxy(46,14);
                printf("%s",T_Seance[1].Nom_Cours);
                gotoxy(46,15);
                printf("%s",T_Seance[1].Nom_Professeur1);
                gotoxy(46,16);
                printf("NIVEAU: %d",T_Seance[1].niv);

                gotoxy(46,20);
                printf("%s",T_Seance[2].Nom_Cours);
                gotoxy(46,21);
                printf("%s",T_Seance[2].Nom_Professeur1);
                gotoxy(46,22);
                printf("NIVEAU: %d",T_Seance[2].niv);

                gotoxy(46,26);
                printf("%s",T_Seance[3].Nom_Cours);
                gotoxy(46,27);
                printf("%s",T_Seance[3].Nom_Professeur1);
                gotoxy(46,28);
                printf("NIVEAU: %d",T_Seance[3].niv);

                gotoxy(27,32);
                printf("%s",T_Seance[4].Nom_Cours);
                gotoxy(46,33);
                printf("%s",T_Seance[4].Nom_Professeur1);
                gotoxy(46,34);
                printf("NIVEAU: %d",T_Seance[4].niv);


                gotoxy(65,14);
                printf("%s",T_Seance[5].Nom_Cours);
                gotoxy(65,15);
                printf("%s",T_Seance[5].Nom_Professeur1);
                gotoxy(65,16);
                printf("NIVEAU: %d",T_Seance[5].niv);

                gotoxy(65,20);
                printf("%s",T_Seance[6].Nom_Cours);
                gotoxy(65,21);
                printf("%s",T_Seance[6].Nom_Professeur1);
                gotoxy(65,22);
                printf("NIVEAU: %d",T_Seance[6].niv);

                gotoxy(65,26);
                printf("%s",T_Seance[7].Nom_Cours);
                gotoxy(65,27);
                printf("%s",T_Seance[7].Nom_Professeur1);
                gotoxy(65,28);
                printf("NIVEAU: %d",T_Seance[7].niv);

                gotoxy(65,32);
                printf("%s",T_Seance[8].Nom_Cours);
                gotoxy(65,33);
                printf("%s",T_Seance[8].Nom_Professeur1);
                gotoxy(65,34);
                printf("NIVEAU: %d",T_Seance[8].niv);



                gotoxy(81,14);
                printf("%s",T_Seance[9].Nom_Cours);
                gotoxy(81,15);
                printf("%s",T_Seance[9].Nom_Professeur1);
                gotoxy(81,16);
                printf("NIVEAU: %d",T_Seance[9].niv);

                gotoxy(81,20);
                printf("%s",T_Seance[10].Nom_Cours);
                gotoxy(81,21);
                printf("%s",T_Seance[10].Nom_Professeur1);
                gotoxy(81,22);
                printf("NIVEAU: %d",T_Seance[10].niv);

                gotoxy(81,26);
                printf("%s",T_Seance[11].Nom_Cours);
                gotoxy(81,27);
                printf("%s",T_Seance[11].Nom_Professeur1);
                gotoxy(81,28);
                printf("NIVEAU: %d",T_Seance[11].niv);

                gotoxy(81,32);
                printf("%s",T_Seance[12].Nom_Cours);
                gotoxy(81,33);
                printf("%s",T_Seance[12].Nom_Professeur1);
                gotoxy(81,34);
                printf("NIVEAU: %d",T_Seance[12].niv);



                gotoxy(99,14);
                printf("%s",T_Seance[13].Nom_Cours);
                gotoxy(99,15);
                printf("%s",T_Seance[13].Nom_Professeur1);
                gotoxy(99,16);
                printf("NIVEAU: %d",T_Seance[13].niv);

                gotoxy(99,20);
                printf("%s",T_Seance[14].Nom_Cours);
                gotoxy(99,21);
                printf("%s",T_Seance[14].Nom_Professeur1);
                gotoxy(99,22);
                printf("NIVEAU: %d",T_Seance[14].niv);

                gotoxy(99,26);
                printf("%s",T_Seance[15].Nom_Cours);
                gotoxy(99,27);
                printf("%s",T_Seance[15].Nom_Professeur1);
                gotoxy(99,28);
                printf("NIVEAU: %d",T_Seance[15].niv);

                gotoxy(99,32);
                printf("%s",T_Seance[16].Nom_Cours);
                gotoxy(99,33);
                printf("%s",T_Seance[16].Nom_Professeur1);
                gotoxy(99,34);
                printf("NIVEAU: %d",T_Seance[16].niv);


                gotoxy(117,14);
                printf("%s",T_Seance[17].Nom_Cours);
                gotoxy(117,15);
                printf("%s",T_Seance[17].Nom_Professeur1);
                gotoxy(117,16);
                printf("NIVEAU: %d",T_Seance[17].niv);

                gotoxy(117,20);
                printf("%s",T_Seance[18].Nom_Cours);
                gotoxy(117,21);
                printf("%s",T_Seance[18].Nom_Professeur1);
                gotoxy(117,22);
                printf("NIVEAU: %d",T_Seance[18].niv);

                gotoxy(117,26);
                printf("%s",T_Seance[19].Nom_Cours);
                gotoxy(117,27);
                printf("%s",T_Seance[19].Nom_Professeur1);
                gotoxy(117,28);
                printf("NIVEAU: %d",T_Seance[19].niv);

                gotoxy(117,32);
                printf("%s",T_Seance[20].Nom_Cours);
                gotoxy(117,33);
                printf("%s",T_Seance[20].Nom_Professeur1);
                gotoxy(117,34);
                printf("NIVEAU: %d",T_Seance[20].niv);



                gotoxy(133,14);
                printf("%s",T_Seance[21].Nom_Cours);
                gotoxy(133,15);
                printf("%s",T_Seance[21].Nom_Professeur1);
                gotoxy(133,16);
                printf("NIVEAU: %d",T_Seance[21].niv);

                gotoxy(133,20);
                printf("%s",T_Seance[22].Nom_Cours);
                gotoxy(133,21);
                printf("%s",T_Seance[22].Nom_Professeur1);
                gotoxy(133,22);
                printf("NIVEAU: %d",T_Seance[22].niv);

                gotoxy(133,26);
                printf("%s",T_Seance[23].Nom_Cours);
                gotoxy(133,27);
                printf("%s",T_Seance[23].Nom_Professeur1);
                gotoxy(133,28);
                printf("NIVEAU: %d",T_Seance[23].niv);

                gotoxy(133,32);
                printf("%s",T_Seance[24].Nom_Cours);
                gotoxy(133,33);
                printf("%s",T_Seance[24].Nom_Professeur1);
                gotoxy(133,34);
                printf("NIVEAU: %d",T_Seance[24].niv);

            }
        free(T_Seance);
        gotoxy(120,36);
        scanf("");
    }

void Sean(){
//Déclartion de la fonction qui vérifie si un Salle existe ou pas
    }
