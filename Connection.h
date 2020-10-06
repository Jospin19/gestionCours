#include <string.h>
#include <math.h>
#include <windows.h>



void Util()
         {
         int i;
               coloration(10);
               for(i=0;i<=8;i++)                                  /*Début de la formation du b: Les initiales de bienvenue*/
                  {
                        gotoxy(29,2+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(29+i,6);
                        printf("%c",2);
                        gotoxy(29+i,7);
                        printf("%c",2);
                   }
               for(i=0;i<=4;i++)
                  {
                        gotoxy(37,6+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(29+i,9);
                        printf("%c",2);
                        gotoxy(29+i,10);
                        printf("%c",2);
                   }                                      /*Fin de la formation du b: Les initiales de bienvenue*/
               for(i=0;i<=8;i++)                                  /*Début de la formation du I: Les initiales de bienvenue*/
                  {
                        gotoxy(41,2+i);
                        printf("%c%c",4,4);
                   }                                          /*Fin de la formation du I: Les initiales de bienvenue*/
               for(i=0;i<=8;i++)                                  /*Debut de la formation du E: Les initiales de bienvenue*/
                  {
                        gotoxy(45+i,2);
                        printf("%c",2);
                        gotoxy(45+i,3);
                        printf("%c",2);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(45,2+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(45+i,6);
                        printf("%c",2);
                        gotoxy(45+i,7);
                        printf("%c",2);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(45+i,9);
                        printf("%c",2);
                        gotoxy(45+i,10);
                        printf("%c",2);
                   }                                         /*Fin de la formation du E: Les initiales de bienvenue*/
               for(i=0;i<=8;i++)      /*Debut de la formation du N: Les initiales de bienvenue*/
                  {
                        gotoxy(56,2+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(56+i,2+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(64,2+i);
                        printf("%c%c",4,4);
                   }                                         /*Fin de la formation du N: Les initiales de bienvenue*/
               for(i=0;i<=8;i++)                                   /*Début de la formation de v: Les initiales de bienvenue*/
                  {
                        gotoxy(68+i,2+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(84-i,2+i);
                        printf("%c%c",4,4);
                   }                                          /*Fin de la formation de v: Les initiales de bienvenue*/
               for(i=0;i<=8;i++)                                  /*Debut de la formation du E: Les initiales de bienvenue*/
                  {
                        gotoxy(88+i,2);
                        printf("%c",2);
                        gotoxy(88+i,3);
                        printf("%c",2);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(88,2+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(88+i,6);
                        printf("%c",2);
                        gotoxy(88+i,7);
                        printf("%c",2);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(88+i,9);
                        printf("%c",2);
                        gotoxy(88+i,10);
                        printf("%c",2);
                   }                                         /*Fin de la formation du E: Les initiales de bienvenue*/
               for(i=0;i<=8;i++)      /*Debut de la formation du V: Les initiales de bienvenue*/
                  {
                        gotoxy(100,2+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(100+i,2+i);
                        printf("%c%c",4,4);
                  }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(108,2+i);
                        printf("%c%c",4,4);
                   }                                         /*Fin de la formation du V: Les initiales de bienvenue*/
               for(i=0;i<=8;i++)                                  /*Debut de la formation du U: Les initiales de bienvenue*/
                  {
                        gotoxy(112,2+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(120,2+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(112+i,9);
                        printf("%c",2);
                        gotoxy(112+i,10);
                        printf("%c",2);
                   }                                         /*Fin de la formation du U: Les initiales de bienvenue*/
               for(i=0;i<=8;i++)                                  /*Debut de la formation du E: Les initiales de bienvenue*/
                  {
                        gotoxy(124+i,2);
                        printf("%c",2);
                        gotoxy(124+i,3);
                        printf("%c",2);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(124,2+i);
                        printf("%c%c",4,4);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(124+i,6);
                        printf("%c",2);
                        gotoxy(124+i,7);
                        printf("%c",2);
                   }
               for(i=0;i<=8;i++)
                  {
                        gotoxy(124+i,9);
                        printf("%c",2);
                        gotoxy(124+i,10);
                        printf("%c",2);
                   }                                         /*Fin de la formation du E: Les initiales de bienvenue*/



gotoxy(40,22);
               printf("%c",201);
               for(i=0;i<=80;i++)
                   {
                        printf("%c",205);
                   }
               printf("%c",187);
               gotoxy(40,23);
               printf("%c",186);
               for(i=0;i<=20;i++)
                   {
                        gotoxy(40,23+i);
                        printf("%c",186);
                   }
               gotoxy(40,44);
               printf("%c",200);
               for(i=0;i<=80;i++)
                   {
                        printf("%c",205);
                   }
               printf("%c",188);
               for(i=20;i>=0;i--)
                   {
                        gotoxy(122,43-i);
                        printf("%c",186);
                   }
               coloration(10);
               for(i=0;i<=4;i++)                               /*Debut de la formation du C: Les initiales de Connexion*/
                   {
                        gotoxy(55+i,24);
                        printf("%c",4);
                   }
               for(i=0;i<=4;i++)
                   {
                        gotoxy(55,24+i);
                        printf("%c",4);
                   }
               for(i=0;i<=4;i++)
                   {
                        gotoxy(55+i,28);
                        printf("%c",4);
                   }
               for(i=0;i<=4;i++)                               /*Debut de la formation du O: Les initiales de Connexion*/
                   {
                        gotoxy(61+i,24);
                        printf("%c",4);
                   }
               for(i=0;i<=4;i++)
                   {
                        gotoxy(61,24+i);
                        printf("%c",4);
                   }
               for(i=0;i<=4;i++)
                   {
                        gotoxy(65,24+i);
                        printf("%c",4);
                   }
               for(i=0;i<=4;i++)
                   {
                        gotoxy(61+i,28);
                        printf("%c",4);
                   }                                          /*Fin de la formation du O: Les initiales de Connexion*/
               for(i=0;i<=4;i++)                              /*Debut de la formation du N: Les initiales de Connexion*/
                  {
                       gotoxy(67,24+i);
                       printf("%c",4);
                  }
               for(i=0;i<=4;i++)
                  {
                       gotoxy(67+i,24+i);
                       printf("%c",4);
                  }
               for(i=0;i<=4;i++)
                   {
                        gotoxy(71,24+i);
                        printf("%c",4);
                   }                                          /*Fin de la formation du N:Les initiales de Connexion*/
              for(i=0;i<=4;i++)                              /*Debut de la formation du N: Les initiales de Connexion*/
                  {
                       gotoxy(73,24+i);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(73+i,24+i);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(77,24+i);
                       printf("%c",4);
                  }                                          /*Fin de la formation du N:Les initiales de Connexion*/
              for(i=0;i<=4;i++)                               /*Debut de la formation du E: Les initiales de Connexion*/
                  {
                       gotoxy(79+i,24);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(79,24+i);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(79+i,26);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(79+i,28);
                       printf("%c",4);
                  }                                         /*Fin de la formation du E: Les initiales de Connexion*/
              for(i=0;i<=4;i++)                                /*Début de de la formation du X: les initiales de Connexion*/
                  {
                       gotoxy(85+i,24+i);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(89-i,24+i);
                       printf("%c",4);
                  }                                          /*Fin de la formation du X: les initiales de Connexion*/
              for(i=0;i<=4;i++)                                /*Début de la formation du I: les initiales de Connexion*/
                  {
                       gotoxy(91,24+i);
                       printf("%c",4);
                  }                                            /*Fin de la formation du I: les initiales de Connexion*/
              for(i=0;i<=4;i++)                               /*Debut de la formation du O: Les initiales de Connexion*/
                  {
                       gotoxy(93+i,24);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(93,24+i);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(97,24+i);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(93+i,28);
                       printf("%c",4);
                  }                                          /*Fin de la formation du O: Les initiales de Connexion*/
              for(i=0;i<=4;i++)                              /*Debut de la formation du N: Les initiales de Connexion*/
                  {
                       gotoxy(99,24+i);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(99+i,24+i);
                       printf("%c",4);
                  }
              for(i=0;i<=4;i++)
                  {
                       gotoxy(103,24+i);
                       printf("%c",4);
                  }                                          /*Fin de la formation du N:Les initiales de Connexion*/
              gotoxy(46,32);                                     /*Début du dessin du carre de USER*/
              printf("USER  :     ");
              gotoxy(54,31);
              printf("%c",218);
              for(i=0;i<=50;i++)
                  {
                       gotoxy(55+i,31);
                       printf("%c",240);
                       }
              for(i=0;i<=1;i++)
                  {
                       gotoxy(54,32+i);
                       printf("%c",179);
                  }
              gotoxy(54,33);
              printf("%c",192);
              for(i=0;i<=50;i++)
                  {
                       gotoxy(55+i,33);
                       printf("%c",240);
                  }
              gotoxy(105,33);
              printf("%c",217);
              for(i=0;i>=0;i--)
                  {
                       gotoxy(105,32-i);
                       printf("%c",179);
                  }
              gotoxy(105,31);
              printf("%c",191);                                   /*Fin du desin du carre de USER*/
              gotoxy(46,37);                                     /*Début du dessin du carre de USER*/
              coloration(10);
              printf("LOGIN  :");

              gotoxy(54,36);
              printf("%c",218);
              for(i=0;i<=50;i++)
                  {
                       gotoxy(55+i,36);
                       printf("%c",240);
                  }
              for(i=0;i<=1;i++)
                  {
                       gotoxy(54,37+i);
                       printf("%c",179);
                  }
              gotoxy(54,38);
              printf("%c",192);
              for(i=0;i<=50;i++)
                  {
                       gotoxy(55+i,38);
                       printf("%c",240);
                  }
              gotoxy(105,38);
              printf("%c",217);
              for(i=0;i>=0;i--)
                  {
                       gotoxy(105,37-i);
                       printf("%c",179);
                  }
              gotoxy(105,36);
              printf("%c",191);          /*Fin du desin du carre de USER*/
}

