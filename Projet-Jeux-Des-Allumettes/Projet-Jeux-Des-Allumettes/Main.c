#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h> 

#define MAX_TAILLE_NOM_JOUEUR 20

void affichage();
int choixFonctionnalite();
void regleDuJeux();
void historique();
void choixJeux();
void humainVShumain();
void humainVSordi();
void jeu(int nb_allumettes, char  joueur1[20], char  joueur2[20]);
void saveGame(char Joueur[], int a);
	void historique();

void main(){
	
	//Presentation du jeux
	affichage();

	//Choix et lancement de la fonctionnalite
	choixFonctionnalite();
	
}


void affichage() {
	printf("                     **************************\n");
	printf("                     *   Jeux des allumettes  *\n");
	printf("                     **************************\n");
	printf("\n");
	printf("             Bonjour et bienvenue dans le jeux des allumetes\n");
	printf("\n");

	printf("Vous allez avoir 3 menus.");
	printf("Vous choisirez d'abord si vous voulez voir les regles du jeu ou non, puis le nombre d'allumettes a utiliser, et enfin le nombre de joueurs?????????. \n \n");

}

int choixFonctionnalite() {

	int choix= -1;

	while (choix != 0) {

		printf("                  -------------------------------\n");
		printf("                 |          Que faire ?          |\n");
		printf("                  -------------------------------\n");
		printf("                 |1 - Jouer                      |\n");
		printf("                 |2 - Voir les regles du jeux    |  \n");
		printf("                 |3 - Historique des parties     |  \n");
		printf("                 |0 - Quitter                    | \n");
		printf("                  -------------------------------\n ");
		printf("                         Votre choix : ");

		scanf("%d", &choix);
		printf("\n");
		printf("\n");


		switch (choix) {
		case 1:  choixJeux(); break;
		case 2: regleDuJeux(); break;
		case 3: historique(); break;
		case 0: printf("A tres bien tot !"); break;
		default: printf("Votre choix n'éxiste pas ! Veuillez choisire un choix possible ! \n \n"); break;
		}
	}
	
}


void choixJeux() {
	int choixJeux = -1;
	while (choixJeux != 0) {
		printf("1 - Joueur vs Joueur \n");
		printf("2 - Jeux vs Ordi \n");
		printf("0 - Quitter \n \n");
		printf("Votre choix : ");
		scanf("%d", &choixJeux);

		switch (choixJeux)
		{
		case 1: humainVShumain(); break;
		case 2: humainVSordi(); break;
		case 0: break;
		default: printf("Votre choix n'éxiste pas ! Veuillez choisire un choix possible ! \n \n"); break;
		}
	}
}

void regleDuJeux() {
	printf("               **************************************\n");
	printf("               |           Regles du jeu            |\n");
	printf("               **************************************\n\n");

	printf("                      Le but du jeu est simple !\n \n");
	printf("Ce jeu se joue a deux.Vous avez un nombre n d allumettes.\nA tour de role, chacun des deux joueurs enleve entre 1 et 3 allumettes selon ce qu il souhaite.Le perdant est celui qui doit enlever la derniere allulettes.\n \n Attention, il existe 3 niveaux de difficulte en version humain vs ordi.\n Le 1er est plutot simple a battre, donc pour les debutants. Mais le dernier ... \n Concactez moi si vous avez reussi(screenshot evidemment^^), mon e - mail est dans les credits ! \n \n");
}

void  humainVShumain(){
	int nb_allumettes = 30;
	int* p_nb_allumettes = &nb_allumettes;
	char joueur1[MAX_TAILLE_NOM_JOUEUR];
	char joueur2[MAX_TAILLE_NOM_JOUEUR];
	int perdu = 0;
	int premier_tour = 1;
	int joueurCourant;
	printf("Entrez le nom du joueur 1 : ");
	scanf("%s",joueur1);
	printf("\n");
	printf("Entrez le nom du joueur 2 : ");
	scanf("%s",joueur2);
	printf("\n");
	while(perdu==0 ){
		if (premier_tour == 1) {
			if ((1 + (rand() % 2) == 1)) {
				joueurCourant = 1;
			}
			else {
				joueurCourant = 2;
			}
			premier_tour = 0;
		}
		else {
			joueurCourant = 3 - joueurCourant;
		}
		jeu(p_nb_allumettes,joueur1, joueur2, joueurCourant);
		if(nb_allumettes == 0){
			if(joueurCourant == 1){
				printf("Le joueur %s a perdu.", joueur1);
			}else{
				printf("Le joueur %s a perdu.", joueur2);
			}
			perdu = 1;
		}
		printf("\n");
		
	}

}

void jeu(int* p_nb_allumettes, char  joueur1[MAX_TAILLE_NOM_JOUEUR], char joueur2[MAX_TAILLE_NOM_JOUEUR], int joueurCourant)
{/*
	//probleme char
	char nb_allumettes_jouees;
	int tour_joueur = 0;
	printf("Nombre d'allumettes restantes : %d\n", *p_nb_allumettes);
	if(joueurCourant == 1){
		printf("Au tour de %s\n", joueur1);
	}else{
		printf("Au tour de %s\n", joueur2);
	}
	
	printf("Combien prenez-vous d'allumettes ? ");
	scanf("%c", nb_allumettes_jouees);
	while (nb_allumettes_jouees < '1' || nb_allumettes_jouees > '3') {
		printf("Erreur : Vous devez donner un entier compris entre 1 et 3.\n Combien prenez-vous d'allumettes ? ");
		scanf("%c", &nb_allumettes_jouees);
	}
	while (nb_allumettes_jouees >= '1' && nb_allumettes_jouees <= '3' && *p_nb_allumettes < (nb_allumettes_jouees - '0')) {
		printf("Erreur : Vous devez jouer un nombre inferieur au nombre d'allumettes restantes.\n Combien prenez-vous d'allumettes ? ");
		scanf("%c", &nb_allumettes_jouees);
	}
	*p_nb_allumettes -= nb_allumettes_jouees;*/
}

void humainVSordi() {
	int allumettes= 30;
	int joueur1 = 1;
	int joueur2 = 2;
	// faire se que marco a fait 

	// attention il faut que le nb dallu < au db dallu restant !!!!!!
	// 
	// nb allumette a prendre pour lordi
	int nbDallumetes = (allumettes - 1) % 4 ;

	//mode facile
	int nballu =  rand() % 3 + 1; 

}


void historique(){
	FILE* fic = fopen("historique.txt", "r+");
	char ligne[50];
	const char delim[2] = "-";

	char* Joueur;
	int nbVictoireHumain, nbDefaiteHumain, nbVictoireOrdiFacile, nbDefaiteOrdiFacile, nbVictoireOrdiDifficile, nbDefaiteOrdiDifficile;

	if (fic == NULL) {
		printf("Fichier non trouvee");
		return;
	}
	printf("*********************************************************************\n");
	printf("|                             Score                                 |\n");
	printf("*********************************************************************\n");
	while (1) {

		fgets(ligne, 50, fic);
		
		Joueur= strtok(ligne, delim);;
		nbVictoireHumain = strtok(NULL, delim);
		nbDefaiteHumain = strtok(NULL, delim);
		nbVictoireOrdiFacile = strtok(NULL, delim);
		nbDefaiteOrdiFacile = strtok(NULL, delim);
		nbVictoireOrdiDifficile= strtok(NULL, delim);
		nbDefaiteOrdiDifficile= strtok(NULL, delim);
	printf("|                                                                   |\n");
	printf("|                                                                   |\n");
	printf("                          Joueur: %s\n", Joueur);
	printf("|                                                                   |\n");
	printf("|                 Victoire Humain vs Humain : %s                     |\n", nbVictoireHumain);
	printf("|                 Defaite Humain vs Humain : %s                      |\n", nbDefaiteHumain);
	printf("|                 Victoire Humain vs Ordi FACILE : %s                |\n", nbVictoireOrdiFacile);
	printf("|                 Defaite Humain vs Ordi FACILE : %s                 |\n", nbVictoireOrdiFacile);
	printf("|                 Victoire Humain vs Ordi DIFFICILE : %s             |\n", nbVictoireOrdiDifficile);
	printf("|                 Defaite Humain vs Ordi DIFFICILE : %s              |\n", nbVictoireOrdiDifficile);
	printf("|                                                                   |\n");
	printf("*********************************************************************\n");

		if (feof(fic))
			break;
	}
	printf("\n");

	fclose(fic);
}

// a finir !!!!!
void saveGame(char Joueur[], int a) {
	FILE* fic = fopen("historique.txt", "r+");
	char ligne[50];
	const char delim[2] = "-";

	char* nomJoueur;
	int nbVictoireHumain, nbDefaiteHumain, nbVictoireOrdiFacile, nbDefaiteOrdiFacile, nbVictoireOrdiDifficile, nbDefaiteOrdiDifficile;

	if (fic == NULL) {
		printf("Fichier non trouvee");
		return;
	}
	
	while (1) {

		fgets(ligne, 50, fic);

		nomJoueur = strtok(ligne, delim);;

		if (strcmp(Joueur, nomJoueur) == 0) {
			printf("eeeeeeeeeee");
			nbVictoireHumain = strtok(NULL, delim);
			nbDefaiteHumain = strtok(NULL, delim);
			nbVictoireOrdiFacile = strtok(NULL, delim);
			nbDefaiteOrdiFacile = strtok(NULL, delim);
			nbVictoireOrdiDifficile = strtok(NULL, delim);
			nbDefaiteOrdiDifficile = strtok(NULL, delim);

			// faire ecriture sur la meme ligne ( supprimer et reecrit)
			fprintf(fic,"test" );
		}
		
		

		if (feof(fic))
			break;
	}
	printf("\n");

	fclose(fic);
}