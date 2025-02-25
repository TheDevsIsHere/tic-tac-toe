#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char bordo [3][3];
const char Giocatore = 'O';
const char Computer = 'X';

int mossGiocatore();
int controlla_spazi();
int controlla_vincitore();
void puliscibordo();
void stampabordo();
void mossComputer();
void stampa_vincitore(char);




int main()
{
    char vincitore = ' ';
    puliscibordo();

    while(vincitore == ' ' && controlla_spazi() != 0)
    {
        stampabordo();
        mossGiocatore();
        mossComputer();
        vincitore = controlla_vincitore();
        if(vincitore != ' ' && controlla_spazi() == 0)
        {
            break;
        }
    }
    stampabordo();
    stampa_vincitore(vincitore);

    return 0;
}

void stampa_vincitore(char vincitore)
{   
    if (vincitore == Giocatore)
    {
        printf("Hai vinto");
    }
    else if (vincitore == Computer)
    {
        printf("Hai Perso");
    }
    else
    {
        printf("Pareggio");
    }
}

void mossComputer()
{
    int mossax, mossay = 0;
    srand(time(0));
    mossax = rand() % 3;
    mossay = rand() % 3;
    if (controlla_spazi() > 0)
    {
        if (bordo[mossax][mossay] == ' ')
        {
            bordo[mossax][mossay] = Computer;
        }
        else
        {
            while(bordo[mossax][mossay] != ' ')
            {
                mossax = rand() % 3;
                mossay = rand() % 3;
            }
            bordo[mossax][mossay] = Computer;
        }
    }
    else
    {
        stampa_vincitore(' ');
    }
}

int controlla_vincitore()
{
    for (int i = 0; i < 3; i++)
    {
        if(bordo[i][0] != ' ' && bordo[i][0] == bordo[i][1] &&  bordo[i][0] == bordo[i][2])
        {
            return bordo[i][0];
        }
        if(bordo[0][i] != ' ' && bordo[0][i] == bordo[1][i] &&  bordo[0][i] == bordo[2][i])
        {
            return bordo[0][i];
        }
        if(bordo[0][0] != ' ' && bordo[0][0] == bordo[1][1] &&  bordo[0][0] == bordo[2][2])
        {
            return bordo[0][0];
        }
        if(bordo[0][2] != ' ' && bordo[0][2] == bordo[1][1] &&  bordo[0][2] == bordo[2][0])
        {
            return bordo[0][2];
        }
    }
    return ' ';
}
int controlla_spazi()
{
    int spazi = 9;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(bordo[i][j] != ' ')
            {
                spazi--;
            }
        }
    }
    return spazi;
}

int mossGiocatore()
{
    int x, y = 0;
    printf("Scegli La Riga (1-3): ");
    scanf("%d", &x);
    x=x-1;
    printf("Scegli La Colonna (1-3): ");
    scanf("%d", &y);
    y=y-1;

    if (bordo[x][y] != ' ' || y < 0 || x < 0 || x >3 || y >3)
    { 
        printf("Mossa Invalida \n");
        while (bordo[x][y] != ' ' || y < 0 || x < 0 || x >3 || y >3)
        {
            printf("Scegli La Riga (1-3): ");
            scanf("%d", &x);
            x=x-1;
            printf("Scegli La Colonna (1-3): ");
            scanf("%d", &y);
            y=y-1;
            printf("Mossa Invalida \n");
        }
    }
    if (bordo[x][y] == ' ')
    {
        bordo[x][y] = Giocatore;
    }
    return x, y;
}

void puliscibordo()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            bordo[i][j] = ' ';
        }
    }
    
}

void stampabordo()
{
    printf(" %c | %c  | %c \n", bordo[0][0], bordo[0][1], bordo[0][2]);
    printf("---|----|---\n");
    printf(" %c | %c  | %c \n", bordo[1][0], bordo[1][1], bordo[1][2]);
    printf("---|----|---\n");
    printf(" %c | %c  | %c \n", bordo[2][0], bordo[2][1], bordo[2][2]);
}
