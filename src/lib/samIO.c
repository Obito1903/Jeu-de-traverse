/*! @file samIO.c
 *  @author Samuel Rodrigues <samuel.rodrigues@eisti.eu>
 *  @version 0.1
 *  @date Thu Nov 21 09:10:44 2019
 *
 *  @brief Ensemble de fonction permettant la saise de nombres
 *
 */

// Inclusion des entêtes de librairies
#include "samIO.h"

int saisieInt(void)
{
	int i_val;
	int i_entierValide;
	char caractereSuivant;

	i_entierValide = scanf("%d", &i_val);
	caractereSuivant = getchar();
	//Test si scanf renvoi un nombre et si
	if ((i_entierValide == 0) || (caractereSuivant == '.') || (caractereSuivant == ','))
	{
		printf("Erreur, saisie incorect\n");
		exit(EXIT_FAILURE);
	}
	return i_val;
}

int intTest(int min, int max, char *txt)
{
	int i_val;
	do
	{
		system("clear");
		printf("%s", txt);
		ptSaisieInt(&i_val);
	} while ((i_val < min) || (i_val > max));
	return i_val;
}

void ptSaisieInt(int *i_resultat)
{
	int i_entierValide;
	char caractereSuivant;

	i_entierValide = scanf("%d", i_resultat);
	caractereSuivant = getchar();
	//Test si scanf renvoi un nombre et si
	if ((i_entierValide == 0) || (caractereSuivant == '.') || (caractereSuivant == ','))
	{
		printf("Erreur, saisie incorect\n");
		exit(EXIT_FAILURE);
	}
}

void ptIntTest(int *i_val, int min, int max, char *txt)
{
	do
	{
		system("clear");
		printf("%s", txt);
		ptSaisieInt(i_val);
	} while ((*i_val < min) || (*i_val > max));
}

void saisieDouble(double *d_resultat)
{
	int i_doubleValide;

	i_doubleValide = scanf("%lf", d_resultat);

	//Test si scanf renvoi un nombre et si
	if (!(i_doubleValide))
	{
		printf("Erreur, saisie incorect\n");
		exit(EXIT_FAILURE);
	}
}

void doubleTest(double *d_val, double min, double max, char *txt)
{
	do
	{
		system("clear");
		printf("%s", txt);
		saisieDouble(d_val);
	} while ((*d_val < min) || (*d_val > max));
}

void saisieFloat(float *f_resultat)
{
	int i_floatValide;

	i_floatValide = scanf("%f", f_resultat);

	//Test si scanf renvoi un nombre et si
	if (!(i_floatValide))
	{
		printf("Erreur, saisie incorect\n");
		exit(EXIT_FAILURE);
	}
}

void floatTest(float *f_val, float min, float max, char *txt)
{
	do
	{
		system("clear");
		printf("%s", txt);
		saisieFloat(f_val);
	} while ((*f_val < min) || (*f_val > max));
}