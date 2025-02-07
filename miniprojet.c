//projet gestion d'etudiant .........
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#define max 50

//declaration
int i,nm,n,nb,j,choixxx,choixx,choix,choixxxx;

struct etudiants{
     int matricule,jour,mois,annee;
     char nom[30],prenom[30],lieu_de_naissance[30];
     char adresse[30];
     float moy[50];
};
struct etudiants les_etudiants[max];

struct etudiants2{
     int matricule2,jour2,mois2,annee2;
     char nom2[30],prenom2[30],lieu_de_naissance2[30];
     char adresse2[30];
     float moy2[50];
};
struct etudiants2 etudiants2[max];

struct trier{
     int matriculee,jourr,moiss,anneee;
     char nomm[30],prenomm[30],lieu_de_naissancee[30];
     char adressel[30];
     int coeff;
     char nomf[50];
     int codef;
     float moy[50];
};
struct trier trier[max];

struct module{
     int coef;
     char nom[50];
     int code;
     float moy[50];
};
struct module module[max];


struct module2{
     int coef2;
     char nom2[50];
     int code2;
     float moy2[50];
};
struct module2 module2[max];

struct note{
     float N[100][20];
     int matriculenote;
     char nomnote[30];
};
struct note note[max];

struct moyenne {
float moy;
int code;
};

struct liste {
struct moyenne* m;           // Donnée stockée dans l'élément
struct liste* next;  // Pointeur vers l'élément suivant
};


///LES PROCEDURES
void reglage(){
     FILE *nt;
nt=fopen("notes.txt","w");
fprintf(nt,"les notes des etudiants : \n\n");
fprintf(nt,"matricule | nom prenom | note \n\n");
for(i=1;i<=n;i++){
     fprintf(nt,"%d | %s %s | ",les_etudiants[i].matricule,les_etudiants[i].nom,les_etudiants[i].prenom);
     for(j=1;j<=nm;j++){
          fprintf(nt,"%s : %0.2f  ",module[j].nom,note->N[i][j]);
     }
     fprintf(nt,"\n");
}
fclose(nt);
     }
//*******************************procedure saisir la liste d'etudiants**************************************************************
void saisir_des_etudiant(){
     FILE *f;
     f=fopen("etudiants.txt","a");
printf("Entrer le nombre des etudiants que vous vouliez saisie : ");
scanf("%d",&nb);
printf("\n\n");
fprintf(f,"la list des etudiants : \n\n");
fprintf(f,"matricule | nom | prenom | date de naissance | lieu de naissance | adresse \n\n");

for(i=1;i<=nb;i++){

     printf("Saisir les informations de l'etudiant numero %d :  \n\n",n+1);
     printf("matricule : ");
     scanf("%d",&les_etudiants[n+1].matricule);
     for(j=0;j<n+1;j++){
          if(les_etudiants[n+1].matricule==les_etudiants[j].matricule){
          printf("le matricule est deja utiliser saisissez un autre! : ");
          scanf("%d",&les_etudiants[n+1].matricule);
          j=j-1;
          }
     }
     printf("Nom : ");
     scanf("%s",&les_etudiants[n+1].nom);
     printf("Prenom : ");
     scanf("%s",&les_etudiants[n+1].prenom);
     printf("date de naissance (jour mois annee): ");
     do{ printf("le jour : ");
          scanf("%d",&les_etudiants[n+1].jour);
          if((les_etudiants[n+1].jour>31)||(les_etudiants[n+1].jour==0)){
          printf("le jour doit etre valide [1-31] ");
          }
     }while((les_etudiants[n+1].jour>31)||(les_etudiants[n+1].jour==0));

     do{ printf("le mois : ");
          scanf("%d",&les_etudiants[n+1].mois);
          if(les_etudiants[n+1].mois>12){
          printf("le mois doit etre valide [1-12] ");
          }
     }while((les_etudiants[n+1].mois>12)||(les_etudiants[n+1].mois==0));


     do{ printf("l annee : ");
          scanf("%d",&les_etudiants[n+1].annee);
          if((les_etudiants[n+1].annee==0)||(les_etudiants[n+1].annee>=2024)){
          printf("l annee doit etre valide ");
          }
     }while((les_etudiants[n+1].annee==0)||(les_etudiants[n+1].annee>=2024));
     printf("lieu de naissance : ");
     scanf("%s",&les_etudiants[n+1].lieu_de_naissance);
     printf("adresse : ");
     scanf(" %[^\n]",&les_etudiants[n+1].adresse);
     if (f == NULL) {
     printf("Erreur d'ouverture du fichier.\n");
     return;
}

fprintf(f, "%d | %s | %s | %d/%d/%d | %s | %s\n", les_etudiants[n+1].matricule, les_etudiants[n+1].nom, les_etudiants[n+1].prenom, les_etudiants[n+1].jour, les_etudiants[n+1].mois, les_etudiants[n+1].annee,les_etudiants[n+1].lieu_de_naissance, les_etudiants[n+1].adresse);



     n=n+1;
}
for(i=1;i<=nb;i++){
     etudiants2[i].matricule2=les_etudiants[i].matricule;
     strcpy(etudiants2[i].nom2,les_etudiants[i].nom);
     strcpy(etudiants2[i].adresse2,les_etudiants[i].adresse);
     strcpy(etudiants2[i].prenom2,les_etudiants[i].prenom);
     strcpy(etudiants2[i].lieu_de_naissance2,les_etudiants[i].lieu_de_naissance);
     etudiants2[i].jour2=les_etudiants[i].jour;
     etudiants2[i].annee2=les_etudiants[i].annee;
     etudiants2[i].mois2=les_etudiants[i].mois;}
          fclose(f);}

////*******************************procedure afficher la liste d'etudiants*******************************
void afficher_les_etudiants(){
     system("cls");
     if(n==0){
          printf("la liste est vide ");
     }
for(i=1;i<=n;i++){ printf("\n");
     printf("etudient avec  : \nmatricule :%d \n",les_etudiants[i].matricule);
     printf("Son Nom : %s \n",les_etudiants[i].nom);
     printf("son Prenom : %s \n",les_etudiants[i].prenom);
     printf("sa date de naissance : %d %d %d \n",les_etudiants[i].jour,les_etudiants[i].mois,les_etudiants[i].annee);
     printf("son lieu de naissance : %s \n",les_etudiants[i].lieu_de_naissance);
     printf("son adresse : %s \n",les_etudiants[i].adresse);
}

}

//*******************************procedure modifier un etudiant*******************************************
void modifier(){
     int mat,k=0;
     int i;
     FILE *f; int y;
     printf("la liste des etudiants enregistre:\n");
     if(n==0){
          printf("la liste est vide ");
     }
     for(i=1;i<=n;i++){
     printf("matricule: %d           etudiant:%s %s\n",les_etudiants[i].matricule,les_etudiants[i].nom,les_etudiants[i].prenom);
     }
     reessaye:
     printf("\n \n");
     printf("Saisir le matricule de l etudiant que vous vouliez modifier : ");
     scanf("%d",&mat);

     for(i=1;i<=n;i++){
          if(les_etudiants[i].matricule==mat){
               k=i;
          }
     }
     if(k==0) {
               printf("aucun etudiant a le matricule saisie");
               goto reessaye;
          }
          int arris;
printf("nouveau matricule : ");
scanf("%d",&les_etudiants[k].matricule);
for(i=1;i<=n;i++){
     if(les_etudiants[k].matricule==les_etudiants[i].matricule){
          printf("le matricule est deja utiliser saisissez un autre! : ");
          scanf("%d",&arris);
     }
}
les_etudiants[k].matricule=arris;
printf("nouveau Nom : ");
scanf("%s",&les_etudiants[k].nom);
printf("nouveau Prenom : ");
scanf("%s",&les_etudiants[k].prenom);
printf("nouvelle date de naissance : ");
do{ printf("le jour :");
          scanf("%d",&les_etudiants[k].jour);
          if((les_etudiants[k].jour>31)||(les_etudiants[k].jour==0)){
          printf("le jour doit etre valide [1-31] ");
          }
     }while((les_etudiants[k].jour>31)||(les_etudiants[k].jour==0));

     do{ printf("le mois :");
          scanf("%d",&les_etudiants[k].mois);
          if(les_etudiants[k].mois>12){
          printf("le mois doit etre valide [1-12] ");
          }
     }while((les_etudiants[k].mois>12)||(les_etudiants[k].mois==0));


     do{ printf("l annee : ");
          scanf("%d",&les_etudiants[k].annee);
          if(les_etudiants[k].annee>=2024){
          printf("l annee doit etre valide ");
          }
     }while((les_etudiants[k].annee==0)||(les_etudiants[k].annee>=2024));
printf("nouveau lieu de naissace : ");
gets(gets(les_etudiants[k].lieu_de_naissance));
printf("nouvelle adresse : ");
scanf("%s",&les_etudiants[k].adresse);
for(i=1;i<=n;i++){
          if(etudiants2[i].matricule2==mat)
               k=i;
     }
     etudiants2[k].matricule2=les_etudiants[k].matricule;
     strcpy(etudiants2[k].nom2,les_etudiants[k].nom);
     strcpy(etudiants2[k].adresse2,les_etudiants[k].adresse);
     strcpy(etudiants2[k].prenom2,les_etudiants[k].prenom);
     strcpy(etudiants2[k].lieu_de_naissance2,les_etudiants[k].lieu_de_naissance);
     etudiants2[k].jour2=les_etudiants[k].jour;
     etudiants2[k].annee2=les_etudiants[k].annee;
     etudiants2[k].mois2=les_etudiants[k].mois;
     printf("voulez vous le modifier au niveau du fichier aussi ? (oui 0/non 1) : ");
     scanf("%d",&y);
     if(y==0){
                    f=fopen("etudiants.txt","w");
                    fprintf(f,"la list des etudiants : \n\n");
                    fprintf(f,"matricule | nom | prenom | date de naissance | lieu de naissance | adresse \n\n");
                    for(i=1;i<=n;i++){
          fprintf(f, "%d | %s | %s | %d/%d/%d | %s | %s\n", les_etudiants[i].matricule, les_etudiants[i].nom, les_etudiants[i].prenom, les_etudiants[i].jour, les_etudiants[i].mois, les_etudiants[i].annee,les_etudiants[i].lieu_de_naissance, les_etudiants[i].adresse);
                    }
          fclose(f);
     }
          reglage();
}


//*******************************procedure sup un etudiant*****************************************
void supprimer(){

     int j,mat,k;
     printf("la liste des etudiants enregistre:\n");
     if(n==0){
          printf("la liste est vide ");
     }

     for(i=1;i<=n;i++){
     printf("matricule: %d           etudiant:%s %s\n",les_etudiants[i].matricule,les_etudiants[i].nom,les_etudiants[i].prenom);
     }
     printf("\n \n");
     printf("Saisir le matricule de l etudient que vous vouliez supprimier : ");
     scanf("%d",&mat);

     for(i=1;i<=n;i++){
     if(les_etudiants[i].matricule==mat)
     {
               k=i;
               n=n-1;
               for(j=k;j<=n;j++){
                         les_etudiants[j]=les_etudiants[j+1];
               }
          }
     if(etudiants2[i].matricule2==mat){
          k=i;

               for(j=k;j<=n+1;j++){
                         etudiants2[j]=etudiants2[j+1];
               }
     }
     }
     int y;
     FILE *f;
     printf("voulez vous le supprimé au niveau du fichier aussi ? (oui 0/non 1) : ");
     scanf("%d",&y);
     if(y==0){
                    f=fopen("etudiants.txt","w");
                    fprintf(f,"la list des etudiants : \n\n");
                    fprintf(f,"matricule | nom | prenom | date de naissance | lieu de naissance | adresse \n\n");
                    for(i=1;i<=n;i++){
          fprintf(f, "%d | %s | %s | %d/%d/%d | %s | %s\n", les_etudiants[i].matricule, les_etudiants[i].nom, les_etudiants[i].prenom, les_etudiants[i].jour, les_etudiants[i].mois, les_etudiants[i].annee,les_etudiants[i].lieu_de_naissance, les_etudiants[i].adresse);
                    }
          fclose(f);
     }
     reglage();
}

//*******************************procedure ajouter un etudiant****************************************
void ajouter(){
printf("\n\n");
printf("Saisir les informations de votre etudiant :  \n\n");
printf("matricule : ");
scanf("%d",&les_etudiants[n+1].matricule);
for(j=0;j<n+1;j++){
          if(les_etudiants[n+1].matricule==les_etudiants[j].matricule){
          printf("le matricule est deja utiliser saisissez un autre! : ");
          scanf("%d",&les_etudiants[n+1].matricule);
          }
     }
etudiants2[n+1].matricule2=les_etudiants[n+1].matricule;
printf("Nom : ");
scanf("%s",&les_etudiants[n+1].nom);
strcpy(etudiants2[n+1].nom2,les_etudiants[n+1].nom);
printf("Prenom : ");
gets(gets(les_etudiants[n+1].prenom));
strcpy(etudiants2[n+1].prenom2,les_etudiants[n+1].prenom);
printf("date de naissance : ");
do{ printf("le jour : ");
          scanf("%d",&les_etudiants[n+1].jour);
          if((les_etudiants[n+1].jour>31)||(les_etudiants[n+1].jour==0)){
          printf("le jour doit etre valide [1-31] ");
          }
     }while((les_etudiants[n+1].jour>31)||(les_etudiants[n+1].jour==0));

     do{ printf("le mois : ");
          scanf("%d",&les_etudiants[n+1].mois);
          if(les_etudiants[n+1].mois>12){
          printf("le mois doit etre valide [1-12] ");
          }
     }while((les_etudiants[n+1].mois>12)||(les_etudiants[n+1].mois==0));


     do{ printf("l annee : ");
          scanf("%d",&les_etudiants[n+1].annee);
          if(les_etudiants[n+1].annee>=2024){
          printf("l annee doit etre valide ");
          }
     }while((les_etudiants[n+1].annee==0)||(les_etudiants[n+1].annee>=2024));
etudiants2[n+1].jour2=les_etudiants[n+1].jour;
etudiants2[n+1].mois2=les_etudiants[n+1].mois;
etudiants2[n+1].annee2=les_etudiants[n+1].annee;
printf("lieu de naissace : ");
gets(gets(les_etudiants[n+1].lieu_de_naissance));
strcpy(etudiants2[n+1].lieu_de_naissance2,les_etudiants[n+1].lieu_de_naissance);
printf("adresse : ");
scanf("%s",&les_etudiants[n+1].adresse);
strcpy(etudiants2[n+1].adresse2,les_etudiants[n+1].adresse);
n=n+1;
FILE *f;
int y;
printf("voulez vous l'ajouter au niveau du fichier aussi ? (oui 0/non 1) : ");
     scanf("%d",&y);
     if(y==0){
                    f=fopen("etudiants.txt","a");

          fprintf(f, "%d | %s | %s | %d/%d/%d | %s | %s\n", les_etudiants[n].matricule, les_etudiants[n].nom, les_etudiants[n].prenom, les_etudiants[n].jour, les_etudiants[n].mois, les_etudiants[n].annee,les_etudiants[n].lieu_de_naissance, les_etudiants[n].adresse);

          fclose(f);
     }
printf("\n\n");}

//*******************************procedure POUR QUITTER*************************************************
void quitter(){
     system("cls");
printf("\n\n        \t------------FIN-----------\n\n\n");
printf("\n\n        \t------------MERCI-----------\n\n\n");
}

//*******************************procedure de trie par nom************************************************
void trier_ordre_alphabetique_ascendent(){
     int h,t;

     do{
          h=0;
          for(i=1;i<=n-1;i++){
                    if(strcoll(etudiants2[i].nom2,etudiants2[i+1].nom2)>0){
                    trier[i].matriculee=etudiants2[i].matricule2;
                    trier[i].jourr=etudiants2[i].jour2;
                    trier[i].anneee=etudiants2[i].annee2;
                    trier[i].moiss=etudiants2[i].mois2;
                    strcpy(trier[i].nomm,etudiants2[i].nom2);
                    strcpy( trier[i].prenomm,etudiants2[i].prenom2);
                    strcpy(trier[i].lieu_de_naissancee,etudiants2[i].lieu_de_naissance2);
                    strcpy( trier[i].adressel,etudiants2[i].adresse2);
                    etudiants2[i].matricule2=etudiants2[i+1].matricule2;
                    strcpy( etudiants2[i].nom2,etudiants2[i+1].nom2);
                    strcpy( etudiants2[i].prenom2,etudiants2[i+1].prenom2);
                    strcpy( etudiants2[i].lieu_de_naissance2,etudiants2[i+1].lieu_de_naissance2);
                    strcpy( etudiants2[i].adresse2,etudiants2[i+1].adresse2);
                    etudiants2[i+1].matricule2=trier[i].matriculee;
                    strcpy(  etudiants2[i+1].nom2, trier[i].nomm);
                    strcpy( etudiants2[i+1].prenom2,trier[i].prenomm);
                    strcpy( etudiants2[i+1].lieu_de_naissance2,trier[i].lieu_de_naissancee);
                    strcpy( etudiants2[i+1].adresse2,trier[i].adressel);
                    h++;}
                    }
     }while(h!=0);
     printf("Les etudiants trier par nom : \n\n");
     for(i=1;i<=n;i++)
     {printf("\n");
     printf("sa matricule :%d \n",etudiants2[i].matricule2);
     printf("Son Nom : %s \n",etudiants2[i].nom2);
     printf("son Prenom : %s \n",etudiants2[i].prenom2);
     printf("sa date de naissance : %d / %d / %d \n",etudiants2[i].jour2,etudiants2[i].mois2,etudiants2[i].annee2);
     printf("son lieu de naissance : %s \n",etudiants2[i].lieu_de_naissance2);
     printf("son adresse : %s \n",etudiants2[i].adresse2);
                    }
     }
void trier_ordre_alphabetique_descendant(){
     int h,t;

     do{
          h=0;
          for(i=1;i<=n-1;i++){
                    if(strcoll(etudiants2[i].nom2,etudiants2[i+1].nom2)<0){
                    trier[i].matriculee=etudiants2[i].matricule2;
                    trier[i].jourr=etudiants2[i].jour2;
                    trier[i].anneee=etudiants2[i].annee2;
                    trier[i].moiss=etudiants2[i].mois2;
                    strcpy(trier[i].nomm,etudiants2[i].nom2);
                    strcpy( trier[i].prenomm,etudiants2[i].prenom2);
                    strcpy(trier[i].lieu_de_naissancee,etudiants2[i].lieu_de_naissance2);
                    strcpy( trier[i].adressel,etudiants2[i].adresse2);
                    etudiants2[i].matricule2=etudiants2[i+1].matricule2;
                    strcpy( etudiants2[i].nom2,etudiants2[i+1].nom2);
                    strcpy( etudiants2[i].prenom2,etudiants2[i+1].prenom2);
                    strcpy( etudiants2[i].lieu_de_naissance2,etudiants2[i+1].lieu_de_naissance2);
                    strcpy( etudiants2[i].adresse2,etudiants2[i+1].adresse2);
                    etudiants2[i+1].matricule2=trier[i].matriculee;
                    strcpy(  etudiants2[i+1].nom2, trier[i].nomm);
                    strcpy( etudiants2[i+1].prenom2,trier[i].prenomm);
                    strcpy( etudiants2[i+1].lieu_de_naissance2,trier[i].lieu_de_naissancee);
                    strcpy( etudiants2[i+1].adresse2,trier[i].adressel);
                    h++;}
                    }
     }while(h!=0);
     printf("Les etudiants trier par nom : \n\n");
     for(i=1;i<=n;i++)
     {printf("\n");
     printf("sa matricule :%d \n",etudiants2[i].matricule2);
     printf("Son Nom : %s \n",etudiants2[i].nom2);
     printf("son Prenom : %s \n",etudiants2[i].prenom2);
     printf("sa date de naissance : %d / %d / %d \n",etudiants2[i].jour2,etudiants2[i].mois2,etudiants2[i].annee2);
     printf("son lieu de naissance : %s \n",etudiants2[i].lieu_de_naissance2);
     printf("son adresse : %s \n",etudiants2[i].adresse2);
                    }

     }


//*******************************procedure saisir DES MODULES*********************************************
void saisir_les_modules(){
     FILE *m;
     m=fopen("modules.txt","w");
printf("Entrer le nombre de modules que vous vouliez saisir : ");
scanf("%d",&nb);
printf("\n\n");

fprintf(m,"la list des modules : \n\n");
fprintf(m,"code | Nom | coeffesion \n\n");

for(i=1;i<=nb;i++){

     printf("Saisir les informations du module numero %d :  \n\n",nm+1);
     printf("code : ");
     scanf("%d",&module[nm+1].code);
     for(j=0;j<nm+1;j++){
          if(module[nm+1].code==module[j].code){
          printf("le code est deja utiliser saisissez un autre! : ");
          scanf("%d",&module[nm+1].code);
          }
     }
     printf("Nom : ");
     scanf("%s",&module[nm+1].nom);
     printf("coefficient : ");
     scanf("%d",&module[nm+1].coef);


     if (m == NULL) {
          printf("Erreur d'ouverture du fichier.\n");
          return;
     }

     fprintf(m, "%d | %s | %d\n", module[nm+1].code, module[nm+1].nom, module[nm+1].coef);


     nm=nm+1;

}
fclose(m);
for(i=1;i<=nm;i++){
     module2[i].code2=module[i].code;
     strcpy(module2[i].nom2,module[i].nom);
     module2[i].coef2=module[i].coef;}


          }

          void ajouter_modules(){
     FILE *m;
     m=fopen("modules.txt","a");
     printf("Saisir les informations du module numero %d :  \n\n",nm+1);
     printf("code : ");
     scanf("%d",&module[nm+1].code);
     for(j=0;j<nm+1;j++){
          if(module[nm+1].code==module[j].code){
          printf("le code est deja utiliser saisissez un autre! : ");
          scanf("%d",&module[nm+1].code);
          }
     }
     printf("Nom : ");
     scanf("%s",&module[nm+1].nom);
     printf("coefficient : ");
     scanf("%d",&module[nm+1].coef);


     if (m == NULL) {
          printf("Erreur d'ouverture du fichier.\n");
          return;
     }

     fprintf(m, "%d | %s | %d\n", module[nm+1].code, module[nm+1].nom, module[nm+1].coef);


     nm=nm+1;


fclose(m);
for(i=1;i<=nm;i++){
     module2[i].code2=module[i].code;
     strcpy(module2[i].nom2,module[i].nom);
     module2[i].coef2=module[i].coef;}


     }


//*******************************procedure MODIFIER MODULES*********************************************
void modifier_module(){
     int cod,k,m;
          printf("La liste des modules : \n");
     if(nm==0){
          printf("La liste des modules est vide!\n");
     }
     for(i=1;i<=nm;i++){
          printf("code : %d           nom module : %s\n",module[i].code,module[i].nom);
     }
     printf("\n");
     printf("Saisir le code du module que vous vouliez modifier : ");
     scanf("%d",&cod);

     for(i=1;i<=nm;i++){
          if(module[i].code==cod)
               k=i;
     }
     for(j=1;j<=nm;j++){
          if(module2[j].code2==cod)
               m=j;
     }
printf("code: ");
scanf("%d",&module[k].code);
for(j=0;j<k;j++){
          if(module[k].code==module[j].code){
          printf("le code est deja utiliser saisissez un autre! : ");
          scanf("%d",&module[k].code);

          }
     }
     for(j=k+1;j<=nm;j++){
          if(module[k].code==module[j].code){
          printf("le code est deja utiliser saisissez un autre! : ");
          scanf("%d",&module[k].code);
          }
     }
module2[m].code2=module[k].code;
printf("Nom : ");
scanf("%s",&module[k].nom);
strcpy(module2[m].nom2,module[k].nom);
printf("coeffeciant : ");
scanf("%d",&module[k].coef);
module2[m].coef2=module[k].coef;
FILE *md;
md=fopen("modules.txt","w");
fprintf(md,"la list des modules : \n\n");
fprintf(md,"code | Nom | coeffesion \n\n");
for(i=1;i<=nm;i++){
     fprintf(md, "%d | %s | %d\n", module[i].code, module[i].nom, module[i].coef);
}
fclose(md);

}

//*******************************procedure SUP MODULES*************************************************
void supprimer_module(){

     int j,cod,k;
     printf("La liste des modules : \n");
     if(nm==0){
          printf("La liste des modules est vide!\n");
     }
     for(i=1;i<=nm;i++){
          printf("code : %d           nom module : %s\n",module[i].code,module[i].nom);
     }
     printf("\n");
     printf("Saisir le code du module que vous vouliez supprimer : ");
     scanf("%d",&cod);

     for(i=1;i<=nm;i++){
     if(module[i].code==cod)
     {
               k=i;
               nm=nm-1;
               for(j=k;j<=nm;j++){
                         module[j]=module[j+1];
               }
          }

     }
     for(i=1;i<=nm;i++){
     if(module2[i].code2==cod)
     {
               k=i;
               for(j=k;j<=nm;j++){
                         module2[j]=module2[j+1];
               }
          }

     }

     FILE *m;
m=fopen("modules.txt","w");
fprintf(m,"la list des modules : \n\n");
fprintf(m,"code | Nom | coeffesion \n\n");
for(i=1;i<=nm;i++){
     fprintf(m, "%d | %s | %d\n", module[i].code, module[i].nom, module[i].coef);
}
fclose(m);
}

//*******************************procedure AFFICHER LES MODULES*******************************
void afficher_les_modules(){
     if(nm==0){
          printf("La liste des modules est vide!");
     }
for(i=1;i<=nm;i++){ printf("\n");
     printf("nom du module: %s \t code: %d \t coeffission: %d\n",module[i].nom,module[i].code,module[i].coef);
}
}

//*******************************procedure trie des module par nom*******************************
void trier_module_par_nom_ascendent(){
     int h,t;

     do{
          h=0;
          for(i=1;i<=nm-1;i++){
                    if(strcoll(module2[i].nom2,module2[i+1].nom2)>0){
                    trier[i].codef=module2[i].code2;
                    trier[i].coeff=module2[i].coef2;
                    strcpy(trier[i].nomf,module2[i].nom2);

                    module2[i].code2=module2[i+1].code2;
                    module2[i].coef2=module2[i+1].coef2;
                    strcpy( module2[i].nom2,module2[i+1].nom2);
                    module2[i+1].code2=trier[i].codef;
                    module2[i+1].coef2=trier[i].coeff;
                    strcpy(  module2[i+1].nom2,trier[i].nomf);
                    h++;}
                    }
     }while(h!=0);
     printf("Les module trier par nom (ascendent) : \n\n");
     for(i=1;i<=nm;i++){ printf("\n");
     printf("nom du module: %s \t code: %d \t coeffission: %d\n",module2[i].nom2,module2[i].code2,module2[i].coef2);
}
     }
void trier_module_par_nom_descendant(){
     int h,t;

     do{
          h=0;
          for(i=1;i<=nm-1;i++){
                    if(strcoll(module2[i].nom2,module2[i+1].nom2)<0){
                    trier[i].codef=module2[i].code2;
                    trier[i].coeff=module2[i].coef2;
                    strcpy(trier[i].nomf,module2[i].nom2);
                    module2[i].code2=module2[i+1].code2;
                    module2[i].coef2=module2[i+1].coef2;
                    strcpy( module2[i].nom2,module2[i+1].nom2);
                    module2[i+1].code2=trier[i].codef;
                    module2[i+1].coef2=trier[i].coeff;
                    strcpy(  module2[i+1].nom2,trier[i].nomf);
                    h++;}
                    }
     }while(h!=0);
     printf("Les module trier par nom (descendant) : \n\n");
     for(i=1;i<=nm;i++){ printf("\n");
     printf("nom du module: %s \t code: %d \t coeffission: %d\n",module2[i].nom2,module2[i].code2,module2[i].coef2);
}
     }

//*******************************procedure saisir les notes*******************************
void saisir_les_notes(){
     int mat,x;
     printf("la liste des etudiants enregistre:\n");
     for(i=1;i<=n;i++){
     printf("matricule: %d           etudiant:%s %s\n",les_etudiants[i].matricule,les_etudiants[i].nom,les_etudiants[i].prenom);
     }
     printf("\n \n");
     do{
     printf("donnez le matricule de l'etudiant : ");
     scanf("%d",&mat);
     for(int i=1;i<=n;i++){
          if(les_etudiants[i].matricule==mat){
               note[i].matriculenote=mat;
               strcpy(note[i].nomnote,les_etudiants[i].nom);
               for(int j=1;j<=nm;j++){
                    printf("saisissez les note de letudiant : %s\n",note[i].nomnote);
                    printf("--module : %s ",module[j].nom);

                    do{
                    scanf("%f",&note->N[i][j]);
                    if(note->N[i][j]>20){
                         printf("note doit etre inferieur ou egal a 20 reesayer :");
                    }
                    }while(note->N[i][j]>20);

               }

          }
     }
     printf("voulez vous saisir les notes d un autre etudiant (1 pour oui ; 0 pour non ) : ");
     scanf("%d",&x);
}while (x==1);
FILE *nt;
nt=fopen("notes.txt","w");
fprintf(nt,"les notes des etudiants : \n\n");
fprintf(nt,"matricule | nom prenom | note \n\n");
for(i=1;i<=n;i++){
     fprintf(nt,"%d | %s %s | ",les_etudiants[i].matricule,les_etudiants[i].nom,les_etudiants[i].prenom);
     for(j=1;j<=nm;j++){
          fprintf(nt,"%s : %0.2f  ",module[j].nom,note->N[i][j]);
     }
     fprintf(nt,"\n");
}
fclose(nt);
}

//*******************************procedure afficher les notes*******************************
void afficher_les_notes(){
     int mat,x,a;
     printf("la liste des etudiants enregistre:\n");
     for(i=1;i<=n;i++){
     printf("matricule: %d           etudiant:%s %s\n",les_etudiants[i].matricule,les_etudiants[i].nom,les_etudiants[i].prenom);
     }
     printf("\n \n");
     do{
     printf("donnez le matricule de l'etudiant : ");
     scanf("%d",&mat);
     for(int i=1;i<=n;i++){
          if(les_etudiants[i].matricule==mat){
               x=1;
               for(int j=1;j<=nm;j++){
                    printf("la note de letudiant : %s\n",note[i].nomnote);
                    printf("--> %s : %0.2f \n",module[j].nom,note->N[i][j]);
               }
          }
     }
     if(x==0){printf("l etudiant nexiste pas!!!!");}

     printf("voulez vous afficher les notes d un autre etudiant (1 pour oui ; 0 pour non ) : ");
     scanf("%d",&a);
     }while((x==0)||(a==1));
}

//*******************************procedure afficher moyenne des etudiant*******************************
void afficher_moy_decroi(){
float s,moy,V[50];
struct liste* l=NULL, *nouveau, *dernier;
int h,x=0;

     for(i=1;i<=n;i++){
          s=0;
          moy=0;
          for(j=1;j<=nm;j++){
               s=s+(note->N[i][j]*module[j].coef);
               x=x+module[j].coef;
          }
          moy=moy+(s/x);


          nouveau = malloc(sizeof(struct liste));
nouveau->m = malloc(sizeof(struct moyenne));
nouveau->m->moy = moy;
nouveau->m->code = les_etudiants[i].matricule;
nouveau->next = NULL;

if (l == NULL) {
l = nouveau;
dernier = nouveau;
} else {
dernier->next = nouveau;
dernier = nouveau;
}
          nouveau=l;



          x=0;
          while(nouveau!=NULL){
                    for(int k=1;k<=n;k++){
               if(nouveau->m->code==etudiants2[k].matricule2){
                    etudiants2->moy2[k]=nouveau->m->moy;
               }
          }
          nouveau=nouveau->next;
          }

     }

do{
               h=0;
          for(i=1;i<=n-1;i++){
               for(j=1;j<=n-i;j++){
                    if(etudiants2->moy2[i]<etudiants2->moy2[i+1]){
                    trier[i].matriculee=etudiants2[i].matricule2;
                    trier[i].jourr=etudiants2[i].jour2;
                    trier[i].anneee=etudiants2[i].annee2;
                    trier[i].moiss=etudiants2[i].mois2;
                    trier->moy[i]=etudiants2->moy2[i];
                    strcpy(trier[i].nomm,etudiants2[i].nom2);
                    strcpy( trier[i].prenomm,etudiants2[i].prenom2);
                    strcpy(trier[i].lieu_de_naissancee,etudiants2[i].lieu_de_naissance2);
                    strcpy( trier[i].adressel,etudiants2[i].adresse2);
                    etudiants2[i]=etudiants2[i+1];
                    etudiants2->moy2[i]=etudiants2->moy2[i+1];
                    etudiants2[i+1].matricule2=trier[i].matriculee;
                    etudiants2->moy2[i+1]=trier->moy[i];
                    etudiants2[i+1].jour2= trier[i].jourr;
                    etudiants2[i+1].mois2=trier[i].moiss;
                    etudiants2[i+1].annee2=trier[i].anneee;
                    strcpy( etudiants2[i+1].nom2, trier[i].nomm);
                    strcpy( etudiants2[i+1].prenom2,trier[i].prenomm);
                    strcpy( etudiants2[i+1].lieu_de_naissance2,trier[i].lieu_de_naissancee);
                    strcpy( etudiants2[i+1].adresse2,trier[i].adressel);
                    h++;}
                    }}
     }while(h!=0);


printf("Les etudiants trier par moyenne decroissante : \n\n");
     for(i=1;i<=n;i++)
     {printf("\n");
     printf("sa matricule :%d \n",etudiants2[i].matricule2);
     printf("Son Nom : %s \n",etudiants2[i].nom2);
     printf("son Prenom : %s \n",etudiants2[i].prenom2);
     printf("sa date de naissance : %d / %d / %d \n",etudiants2[i].jour2,etudiants2[i].mois2,etudiants2[i].annee2);
     printf("son lieu de naissance : %s \n",etudiants2[i].lieu_de_naissance2);
     printf("son adresse : %s \n",etudiants2[i].adresse2);
     printf("sa moyenne : %0.2f\n",etudiants2->moy2[i]);
                    }

}
void afficher_moy_CROIS(){
float s,moy,V[50];
struct liste* l=NULL, *nouveau, *dernier;
int h,x=0;
     for(i=1;i<=n;i++){
          s=0;
          moy=0;
          for(j=1;j<=nm;j++){
               s=s+(note->N[i][j]*module[j].coef);
               x=x+module[j].coef;
          }
          moy=moy+(s/x);

          nouveau = malloc(sizeof(struct liste));
nouveau->m = malloc(sizeof(struct moyenne));
nouveau->m->moy = moy;
nouveau->m->code = les_etudiants[i].matricule;
nouveau->next = NULL;

if (l == NULL) {
l = nouveau;
dernier = nouveau;
} else {
dernier->next = nouveau;
dernier = nouveau;
}
          nouveau=l;



          x=0;
          while(nouveau!=NULL){
                    for(int k=1;k<=n;k++){
               if(nouveau->m->code==etudiants2[k].matricule2){
                    etudiants2->moy2[k]=nouveau->m->moy;
               }
          }
          nouveau=nouveau->next;
          }

     }


do{
               h=0;
          for(i=1;i<=n-1;i++){
               for(j=1;j<=n-i;j++){
                    if(etudiants2->moy2[i]>etudiants2->moy2[i+1]){
                    trier[i].matriculee=etudiants2[i].matricule2;
                    trier[i].jourr=etudiants2[i].jour2;
                    trier[i].anneee=etudiants2[i].annee2;
                    trier[i].moiss=etudiants2[i].mois2;
                    trier->moy[i]=etudiants2->moy2[i];
                    strcpy(trier[i].nomm,etudiants2[i].nom2);
                    strcpy( trier[i].prenomm,etudiants2[i].prenom2);
                    strcpy(trier[i].lieu_de_naissancee,etudiants2[i].lieu_de_naissance2);
                    strcpy( trier[i].adressel,etudiants2[i].adresse2);
                    etudiants2[i]=etudiants2[i+1];
                    etudiants2->moy2[i]=etudiants2->moy2[i+1];
                    etudiants2[i+1].matricule2=trier[i].matriculee;
                    etudiants2->moy2[i+1]=trier->moy[i];
                    etudiants2[i+1].jour2= trier[i].jourr;
                    etudiants2[i+1].mois2=trier[i].moiss;
                    etudiants2[i+1].annee2=trier[i].anneee;
                    strcpy(  etudiants2[i+1].nom2, trier[i].nomm);
                    strcpy( etudiants2[i+1].prenom2,trier[i].prenomm);
                    strcpy( etudiants2[i+1].lieu_de_naissance2,trier[i].lieu_de_naissancee);
                    strcpy( etudiants2[i+1].adresse2,trier[i].adressel);
                    h++;}
                    }}
     }while(h!=0);


printf("Les etudiants trier par moyenne croissante : \n\n");
     for(i=1;i<=n;i++)
     {printf("\n");
     printf("sa matricule :%d \n",etudiants2[i].matricule2);
     printf("Son Nom : %s \n",etudiants2[i].nom2);
     printf("son Prenom : %s \n",etudiants2[i].prenom2);
     printf("sa date de naissance : %d / %d / %d \n",etudiants2[i].jour2,etudiants2[i].mois2,etudiants2[i].annee2);
     printf("son lieu de naissance : %s \n",etudiants2[i].lieu_de_naissance2);
     printf("son adresse : %s \n",etudiants2[i].adresse2);
     printf("sa moyenne : %0.2f\n",etudiants2->moy2[i]);
                    }

}

//*******************************procedure afficher moyenne des modules*******************************
void moyenne_module_crois(){
float s,moy,V[50];
int h,x=0;
     for(j=1;j<=nm;j++){
          s=0;
          moy=0;
          for(i=1;i<=n;i++){
               s=s+note->N[i][j];
               x=x+1;
          }
          moy=moy+(s/x);
          module->moy[j]=moy;
          x=0;
          for(int k=1;k<=n;k++){
               if(module[j].code==module2[k].code2){
                    module2->moy2[k]=module->moy[j];
               }
          }
     }
     for(i=1;i<=nm-1;i++){
          for(j=1;j<=nm-i;j++){
               if(module2->moy2[j]>module2->moy2[j+1]){
                    trier[j].coeff=module2[j].coef2;
                    trier[j].codef=module2[j].code2;
                    strcpy(trier[j].nomm,module2[j].nom2);
                    trier->moy[j]=module2->moy2[j];
                    module2[j]=module2[j+1];
                    module2->moy2[j]=module2->moy2[j+1];
                    module2[j+1].coef2=trier[j].coeff;
                    module2[j+1].code2=trier[j].codef;
                    strcpy(module2[j+1].nom2,trier[j].nomm);
                    module2->moy2[j+1]=trier->moy[j];
               }
          }
     }
     for(i=1;i<=nm;i++){ printf("\n");
     printf("nom du module: %s \t code: %d \t coeffission: %d \t sa moyenne: %0.2f\n",module2[i].nom2,module2[i].code2,module2[i].coef2,module2->moy2[i]);
}
          }
void moyenne_module_decroi(){
float s,moy,V[50];
int h,x=0;
     for(j=1;j<=nm;j++){
          s=0;
          moy=0;
          for(i=1;i<=n;i++){
               s=s+note->N[i][j];
               x=x+1;
          }
          moy=moy+(s/x);
          module->moy[j]=moy;
          x=0;
          for(int k=1;k<=n;k++){
               if(module[j].code==module2[k].code2){
                    module2->moy2[k]=module->moy[j];
               }
          }
     }
     for(i=1;i<=nm-1;i++){
          for(j=1;j<=nm-i;j++){
               if(module2->moy2[j]<module2->moy2[j+1]){
                    trier[j].coeff=module2[j].coef2;
                    trier[j].codef=module2[j].code2;
                    strcpy(trier[j].nomm,module2[j].nom2);
                    trier->moy[j]=module2->moy2[j];
                    module2[j]=module2[j+1];
                    module2->moy2[j]=module2->moy2[j+1];
                    module2[j+1].coef2=trier[j].coeff;
                    module2[j+1].code2=trier[j].codef;
                    strcpy(module2[j+1].nom2,trier[j].nomm);
                    module2->moy2[j+1]=trier->moy[j];
               }
          }
     }
     for(i=1;i<=nm;i++){ printf("\n");
     printf("nom du module: %s \t code: %d \t coeffission: %d \t sa moyenne: %0.2f\n",module2[i].nom2,module2[i].code2,module2[i].coef2,module2->moy2[i]);
}
          }


//================================================================
//============================================================================
     //*************************** Le programme principale**********************************************
int main()
{   FILE *m;
     menu:
do{
          printf("\n\033[1;34m   *******      Gestion des etudiants    ****** \033[0m\n\n");
          printf("=================================================================== \n\n");
                              printf("  Totale des eleves : %d\n\n",n);
                              printf("  Totale de modules : %d\n\n",nm);
          printf("-------------------Etudiant------------------------------------------ \n");
          printf("      <1.  Saisir les etudiants------------------------------ \n");
          printf("      <2.  Afficher la list des etudiants-------------------- \n");
          printf("      <3.  gerer les etudiants-------------------------------- \n\n\n");
          printf("-------------------Modules------------------------------------------- \n");
          printf("      <4.  Saisir les modules-------------------------------- \n");
          printf("      <5.  gerer les modules---------------------------------\n");
          printf("      <6.  afficher les modules------------------------------ \n\n\n");
          printf("-------------------Notes--------------------------------------------- \n");
          printf("      <7.  saisir les notes----------------------------------\n");
          printf("      <8.  afficher les notes--------------------------------\n\n");
          printf("      <9.  Quitter------------------------------------------- \n\n");
          printf("===================================================================    \n\n");
               printf("\t \t \t \033[1;31mPS : en cas despace mettez   _   merci\033[0m\n");
          printf("\n");
               printf("\033[1;33mSaisissez votre choix : \033[0m");
          scanf("%d",&choix);
          printf("\n\n");



          switch(choix){
case 1:{ system("cls");saisir_des_etudiant();system("cls");break;}
case 2:{ system("cls");{system("cls");printf("\n*******Choisissez l ordre d affichage****** \n\n");
                    printf(" 1.------avec l ordre enregistrer------ \n\n");
                    printf(" 2.------ordre alphabetique------------ \n\n");
                    printf(" 3.------ordre de leur moyenne--------- \n\n");
                    printf(" 0.------retourner au MENU------------- \n\n");
                    printf("\t-->Saisissez votre choix : ");
                    scanf("%d",&choixxx);
                    switch (choixxx){
                    case 1: {system("cls");afficher_les_etudiants();break;}
                    case 2: {system("cls");{ printf("1.------ordre ascendent------\n\n");printf("2.------ordre descendant------\n\n");printf("\t-->Saisissez votre choix : ");
                                             scanf("%d",&choixxx);
                                             switch (choixxx){
                                             case 1: {system("cls");trier_ordre_alphabetique_ascendent();break;}
                                             case 2: {system("cls");trier_ordre_alphabetique_descendant();break;}}};break;}
                    case 3: {system("cls");printf("1.ordre croissant de leur moyenne\n\n ");printf("2.ordre decroissant de leur moyenne\n\n");printf("\t-->votre choix : ");
                                             scanf("%d",&choixxx);
                                             switch(choixxx){
                                                  case 1:{system("cls");afficher_moy_CROIS();break;}
                                                  case 2:{system("cls");afficher_moy_decroi();break;}
                                             };break;}
                    case 0: {system("cls");goto menu;break;}}};break;}

case 3:{ system("cls");{ printf("\n*******Choisissez l action****** \n\n");
                    printf("1.------suprimer------ \n\n");
                    printf("2.------modifier------ \n\n");
                    printf("3.------ajouter------- \n\n");
                    printf("0.------retourner au MENU------------- \n\n");
                    printf("Saisissez votre choix : ");
                    scanf("%d",&choixx);
                    switch(choixx){
                    case 1:{system("cls");supprimer();system("cls");break;}
                    case 2:{system("cls");modifier();system("cls");break;}
                    case 3:{system("cls");ajouter();system("cls");break;}
                    case 0:{system("cls");goto menu;break;}}}break;}
case 4:{ system("cls");saisir_les_modules();system("cls");break;}
case 5:{ system("cls");{ printf("\n*******Choisissez l action****** \n\n");
                    printf("1.------suprimer------ \n\n");
                    printf("2.------modifier------ \n\n");
                    printf("3.------ajouter------ \n\n");
                    printf("0.------retourner au MENU------------- \n\n");
                    printf("\t-->Saisissez votre choix : ");
                    scanf("%d",&choixxxx);
                    switch(choixxxx){
                    case 1:{system("cls");supprimer_module();system("cls");break;}
                    case 2:{system("cls");modifier_module();system("cls");break; }
                    case 3:{system("cls");ajouter_modules();system("cls");break;}
                    case 0:{system("cls");goto menu;break;}}}break;}
case 6:{ system("cls");{ printf("\n*******Choisissez l ordre d affichage****** \n\n");
                    printf(" 1.------avec l ordre enregistrer------ \n\n");
                    printf(" 2.------ordre alphabetique------------ \n\n");
                    printf(" 3.------ordre de leur moyenne--------- \n\n");
                    printf(" 0.------retourner au MENU------------- \n\n");
                    printf("-->Saisissez votre choix : ");
                    scanf("%d",&choixxx);
                    switch (choixxx){
                    case 1:{ system("cls");afficher_les_modules();break;}
                    case 2:{ system("cls");{ printf("1.------ordre ascendent------\n\n");printf("2.------ordre decendant------\n\n");printf("-->Saisissez votre choix : ");
                                   scanf("%d",&choixxx);
                                   switch(choixxx){
                                   case 1:{system("cls");trier_module_par_nom_ascendent();break;}
                                   case 2:{system("cls");trier_module_par_nom_descendant();break;}}};break;}

                    case 3:{system("cls");printf("1.------ordre ascendent------\n\n");printf("2.------ordre decendant------\n\n");printf("-->Saisissez votre choix : ");
                    scanf("%d",&choixxx);
                    switch(choixxx){
                         case 1:{system("cls");moyenne_module_crois();break;}
                         case 2:{system("cls");moyenne_module_decroi();break;}
                    };break;}
                    case 0:{system("cls");goto menu;break;}}};break;}
case 7:{ system("cls");saisir_les_notes();system("cls");break;}
case 8:{ system("cls");afficher_les_notes();break;}
case 9:{ system("cls");quitter();break;}
default:printf("Choix errone !!! le choix entre [0 - 9]");
     }
     }while(choix!=9);
return 0;
}