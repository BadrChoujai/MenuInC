#include <stdio.h>
#include <stdlib.h>
#define TRUE    1
#define FALSE   0
struct date
{
    int j;
    int m;
    int a;
};
                                //LE JOUR DE VOTRE NAISSANSE//
int findm(int months, int yearss)
{
           int findmonth, leapyr;
           if ((yearss % 100 == 0) && (yearss % 400 != 0))
           leapyr = 0;
           else if (yearss % 4 == 0)
           leapyr = 1;
           else
           leapyr = 0;
           findmonth = 3 + (2 - leapyr) * ((months + 2) / (2 * months)) + (5 * months + months / 9) / 2;
           findmonth = findmonth % 7;
           return findmonth;
}
int weekday(int date, int month, int year) {
           int dayWeek, yr, yd;
           yr = year % 100;
           yd = year / 100;
           printf("\nVotre Date est : %d / %d / %d \n\n", date, month, year);
           dayWeek = 1.25 * yr + findm(month, year) + date - 2 * (yd % 4);
           dayWeek = dayWeek % 7;
           switch (dayWeek){
           case 0:  printf("Le jour de Votre naissance est : Samedi");
                        break;
           case 1:  printf("Le jour de Votre naissance est : Dimanche");
                        break;
           case 2:  printf("Le jour de Votre naissance est : Lundi");
                        break;
           case 3:  printf("Le jour de Votre naissance est : Mardi");
                        break;
           case 4:  printf("Le jour de Votre naissance est : Mercredi");
                        break;
           case 5:  printf("Le jour de Votre naissance est : Jeudi");
                        break;
           case 6:  printf("Le jour de Votre naissance est : Vendredi");
                        break;
           default:  printf("La date est non valide");
           }
           return 1;
           }
												//CALENDRIER D'UN ANNEE//
int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\n***********Janvier***********",
	"\n\n\n***********Fevrier***********",
	"\n\n\n***********Mars***********",
	"\n\n\n***********Avril***********",
	"\n\n\n***********Mai***********",
	"\n\n\n***********Juin***********",
	"\n\n\n***********Juillet***********",
	"\n\n\n***********Aout***********",
	"\n\n\n***********September***********",
	"\n\n\n***********Octobre***********",
	"\n\n\n***********Novembre***********",
	"\n\n\n***********Decembre***********"
};


int inputyear(void)
{
	int year;
	printf("Donner L'annee de votre choix : ");
	scanf("%d", &year);
	return year;
}

int determinedaycode(int year)
{
	int daycode;
	int d1, d2, d3;

	d1 = (year - 1.)/ 4.0;
	d2 = (year - 1.)/ 100.;
	d3 = (year - 1.)/ 400.;
	daycode = (year + d1 - d2 + d3) %7;
	return daycode;
}


int determineleapyear(int year)
{
	if(year% 4 == FALSE && year%100 != FALSE || year%400 == FALSE)
	{
		days_in_month[2] = 29;
		return TRUE;
	}
	else
	{
		days_in_month[2] = 28;
		return FALSE;
	}
}

void calendar(int year, int daycode)
{
	int month, day;
	for ( month = 1; month <= 12; month++ )
	{
		printf("%s", months[month]);
		printf("\n\nDem  Lun  Mar  Mer  Jou  Ven  Sam\n" );

		// Correction de la pos de la premier date//
		for ( day = 1; day <= 1 + daycode * 5; day++ )
		{
			printf(" ");
		}

		// Afficher tous les date pour un mois//
		for ( day = 1; day <= days_in_month[month]; day++ )
		{
			printf("%2d", day );

			// SI JOUR AVANT SAM? Sinon commencer la ligne suivante Sun//.
			if ( ( day + daycode ) % 7 > 0 )
				printf("   " );
			else
				printf("\n " );
		}
			// POS POUR LE MOIS DERNIER//
			daycode = ( daycode + days_in_month[month] ) % 7;
	}
}
                    //FIN CALENDRIER//
int Bessictile(int a)
{

    if (a%400==0 ||((a%4==0)&&(a%100!=0)))
        return 1;
    else if (!(a%400==0 ||((a%4==0)&&(a%100!=0))))
        return 0;
}
int nbr_mois(int m,int a)
{

    if((a>=1 )&&(m==1 ||m==3 ||m==5 ||m==7 ||m==8 ||m==10 ||m==12))
    {
        return 31;
    }
    else if((a>=1)&&(m==4||m==6||m==9 ||m==11))
    {
        return 30;
    }
     else if ((a>=1)&&(m==2)&&Bessictile(a))
    {
        return 29;
    }
     else if ((a>=1)&&(m==2)&&!(Bessictile(a)))
    {
        return 28;
    }
    else
    {
        return 0;
    }
}

int nbr_jour(struct date d)
{
    int i=1;
    int nbrj=0;
    while(i<=d.a-1)
    {
        if(Bessictile(i))
        	nbrj+=366;
        else
        	nbrj+=365;
        	i++;
    }
    i=1;
    while(i<=d.m-1)
    {
        nbrj+=nbr_mois(i,d.a);
        i++;
    }
    nbrj+=d.j;
    return nbrj;
}

int dif(struct date D1,struct date D2)
{
    return (nbr_jour(D2)-nbr_jour(D1));
}

int Jour(struct date d)
{
    struct date d1;
    d1.a=01;
    d1.j=01;
    d1.m=01;
    int nmbr=dif(d1,d)-1;
    nmbr=nmbr%7;
    return nmbr+1;
}

void MoisC(int a,int m)
{
    int i,j,M[6][7];
    for (i=0;i<6;i++)
    {
        for(j=0;j<7;j++)
        {
            M[i][j]=0;
        }
    }
    int k=1;
    struct date d;
    d.j=1;
    d.m=m;
    d.a=a;
    for(i=Jour(d);i<7;i++,k++)
    {
        M[0][i]=k;
    }
    for (i=1;i<6;i++)
    {
        for (j=0;j<7,k<=nbr_mois(m,a);j++,k++)
        {
            M[i][j]=k;
        }
    }
    if (d.m==1)printf("            ************** Janvier %d ************** \n",d.a);
    if (d.m==2)printf("            ************** Fevrier %d ************** \n",d.a);
    if (d.m==3)printf("            ************** Mars %d ***************** \n",d.a);
    if (d.m==4)printf("            ************** Avril %d **************** \n",d.a);
    if (d.m==5)printf("            ************** Mai %d ****************** \n",d.a);
    if (d.m==6)printf("            ************** Juin %d ***************** \n",d.a);
    if (d.m==7)printf("            ************* Juillet %d *************** \n",d.a);
    if (d.m==8)printf("            ************** Aout %d ***************** \n",d.a);
    if (d.m==9)printf("            ************** Septembre %d ************ \n",d.a);
    if (d.m==10)printf("            *************** Octobre %d ************** \n",d.a);
    if (d.m==11)printf("            *************** Novembre %d ************** \n",d.a);
    if (d.m==12)printf("            ************** Decembre %d **************** \n",d.a);
    	printf("            _______________________________________ \n");
        printf("            Lun | Mar | Mer | Jeu | Ven | Sam | Dim \n");
		for(i=0;i<6;i++)
        {
            printf("            ");
            for(j=0;j<7;j++)
            {
                if(M[i][j]!=0)
                   printf("%3d   ",M[i][j]);
                else
                    printf("      ");
            }
            printf("\n");

        }
        printf("            _______________________________________ \n\n");

}

int choice1(struct date d)
{
	printf("            §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
	printf("            §§§§§§§§§§§§ *CALENDRIER D\'UN MOIS* §§§§§§§§§§§§§§\n");
	printf("            §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n\n");
		printf("                              Donnez La Date en Forme De MM/AAAA :");
		scanf("%d/%d",&d.m,&d.a);
		printf("\n\n");
		MoisC(d.a,d.m);
		printf("\n\n");
}
int choice2(void)
{
    int year, daycode, leapyear;
	printf("                              §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
	printf("                              §§§§§§§§§§§§§ *CALENDRIER DE %d* §§§§§§§§§§§§\n" ,year);
	printf("                              §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n\n");
	year = inputyear();
	daycode = determinedaycode(year);
	determineleapyear(year);
	calendar(year, daycode);
	printf("\n\n");
}
int choice3()
{
	struct date d;
	struct date d1;
	printf("                              §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
	printf("                              §§§§ *CALCULE DU DIFFERENCE ENTRE DEUX DATES* §§§§§\n");
	printf("                              §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n\n");
	printf("                              Donner La 1er Date Ce Forme De (JJ/MM/AAAA):");
	scanf("%d/%d/%d",&d.j,&d.m,&d.a);
	printf("                              Donner La 2eme Date Ce Forme De (JJ/MM/AAAA):");
	scanf("%d/%d/%d",&d1.j,&d1.m,&d1.a);
	printf("                              Votre Age En Jour Est: %d Jours \n",-dif(d1,d));
}
int choice4(struct date d)
{
	int dat, mont, years;
	printf("                              §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
	printf("                              §§§§§§ *AFFICHAGE DU JOUR DE VOTRE NAISSANCE* §§§§§\n");
	printf("                              §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n\n");
    printf("                              Entrer Votre Date Ce Forme De (JJ/MM/AAAA) : ");
    scanf("%d/%d/%d",&dat,&mont,&years);
    weekday(dat, mont, years);
    printf("\n\n");
    return 0;
}
int choice5(struct date d)
{
	printf("                              §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
	printf("                              §§§§§§§§§§§§ *ANNEE BESSICTILE, OU NON ?* §§§§§§§§§\n");
	printf("                              §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n\n");
	printf("                              Donner Un Annee:");
	scanf("%d",&d.a);
	if ((d.a%400==0) || ((d.a%4==0) && (d.a%100!=0)))
    {
    	 printf("                      -L'annee est Bessictile.\n\n");
	}
    else if (!((d.a%400==0) || ((d.a%4==0)&&(d.a%100!=0))))
    {
    	printf("                      -L'annee est Non Bessictile.\n\n");
	}


}

int choice6(struct date d)
{
	int a;
	printf("                              §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n");
	printf("                              §§§§§§§§§§§§§§ *DATE VALIDE, OU NON ?* §§§§§§§§§§§§\n");
	printf("                              §§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§§\n\n");
	printf("                              Donnez Un Date De Votre Choix Ce Forme De (JJ/MM/AAAA):");
	scanf("%d/%d/%d",&d.j,&d.m,&d.a);
								//DETERMINER L'ANNEE//
    if(d.a>=1900 && d.a<=9999)
    {
        //DETERMINER LE MOIS//
        if(d.m>=1 && d.m<=12)
        {
            //DETERMINER LE JOUR//
            if((d.j>=1 && d.j<=31) && (d.m==1 || d.m==3 || d.m==5 || d.m==7 || d.m==8 || d.m==10 || d.m==12))
                printf("                              -Date est Valide.\n");
            else if((d.j>=1 && d.j<=30) && (d.m==4 || d.m==6 || d.m==9 || d.m==11))
                printf("                              -La Date est Valide.\n");
            else if((d.j>=1 && d.j<=28) && (d.m==2))
                printf("                              -La Date est Valide.\n");
            else if(d.j==29 && d.m==2 && (d.a%400==0 ||(d.a%4==0 && d.a%100!=0)))
                printf("                              -La Date est Valide.\n");
            else
                printf("                              -La Date Est Non Valide.\n");
        }
        else
        {
            printf("                              -La Date Est Non Valide.\n");
        }
    }
    else
    {
        printf("                              -La Date Est Non Valide.\n");
    }

    return 0;
}
int choix0(void)
{
	printf("\n\n");
	printf("                ********************* MERCI ,ET AU REVOIR ^_^ ******************\n\n");
}
int prntMenu(int choice)
{
	printf("                ****************************************************************\n\n");
	printf("                *************       M E N U    P R O G R A M M E     ***********\n\n");
	printf("                ****************************************************************\n\n");
	printf("                *      SI VOUS VOULEZ :                                        *\n\n");
	printf("                *      Afficher calendrier D\'un Mois            : 1            *\n\n");
	printf("                *      Afficher calendrier D\'un Annee           : 2            *\n\n");
	printf("                *      Calculer La Diff Entre Deux Dates        : 3            *\n\n");
	printf("                *      Determiner Le Jour De votre Naissance    : 4            *\n\n");
	printf("                *      Determiner L'annee Bessictile Ou Non ?   : 5            *\n\n");
	printf("                *      Determiner La Date Valider Ou Non ?      : 6            *\n\n");
	printf("                *      Quittez Le Programe                      : 0            *\n\n");
	printf("                ****************************************************************\n\n");
	printf("                ===> Tappez Votre Choix: ");
	scanf("%d",&choice);
	return choice;
	system("cls");
}

int main()
{
    struct date d;
    struct date d1;
    struct date d2;
    int i,choix;
    int choice;
    choix=prntMenu(choice);
	while (choix != 0)
{
    for(i=0;i<100;i++)
    	{
    	if (choix==1)
    	{
            system("clear");
			choice1(d);
            system("clear");
			choix=prntMenu(choice);
			break;

		}
    	else if (choix==2)
    	{
    		system("clear");
    		choice2();
			getchar();
			system("clear");
			choix=prntMenu(choice);
			break;
		}
    	else if (choix==3)
    	{
    		system("clear");
			choice3(d2,d1);
			getchar();
            system("clear");
			choix=prntMenu(choice);
			break;

		}
    	else if (choix==4)
    	{
    		system("clear");
			choice4(d);
			getchar();
			system("clear");
			choix=prntMenu(choice);
			break;

		}
    	else if (choix==5)
    	{
    		system("clear");
			choice5(d);
			getchar();
            system("clear");
            choix=prntMenu(choice);
			break;

		}
    	else if (choix==6)
    	{
    		system("clear");
			choice6(d);
			getchar();
			system("clear");
			choix=prntMenu(choice);
			break;

		}
		}

}
if (choix==0)
	{
		choix0();
	}
}
