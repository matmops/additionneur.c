#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

// Porte logique NAND
char pl_NAND(char A, char B)
{
    if (A=='1' && B=='1') 
    {
        return ('0'); 
    }

    else
    {
        return ('1');    
    }
}

// Porte logique NOR
char pl_NOR(char A, char B)
{
    if (A=='1' || B=='1') 
    {
        return ('0'); 
    }

    else
    {
        return ('1');    
    }
}

// Porte logique AND 
char pl_AND(char A, char B)
{
    return pl_NAND(pl_NAND(A,B),'1');

}

// Porte logique OR
char pl_OR(char A, char B)
{
    return  pl_NOR(pl_NOR(A,B), '0');
}

// Porte logique XOR
char pl_XOR(char A, char B)
{
    return pl_NAND(pl_NAND(A, pl_NAND(A,B)), pl_NAND(B, pl_NAND(A,B)));
}


// Porte logique NOT
char pl_NOT(char A)
{
   return pl_NAND(A,A);
}

// Additionneur complet 1 bit
char add_1b(char A, char B, char Cin, char* Cout)
{
    char CarryOut = pl_OR(pl_AND(A,B), pl_AND(pl_XOR(A,B), Cin));
    char Sum = pl_XOR(pl_XOR(A,B),Cin);
    
    *Cout = CarryOut;

    return Sum;
}

// Additionneur complet 16 bit
char add_16b(char *A, char *B, char *sum)
{
    char carryOut = '0';

    for (int i=15; i>=0; i--)
    {
        sum[i] = add_1b(A[i], B[i], carryOut, &carryOut);     
    }
    
    return carryOut;
    
}

// Fonction qui convertit l'entrée (hexadecimal) en Bit
void convertir_entree(char* tab, char* strhexa) 
{
        
    char c;
    int i;
    int index= 2;
    int arrSize = checkLengthCharArray(strhexa);
    

        for (i = 2 +(6 - arrSize); i < 6 ; i++) 
        {

            c = tolower(strhexa[index]);
            index++;
            
        // Remplace caractere par caractere selon le caractere hexadecimal
            switch (c) 
            {
                case '0':
                    tab[((i-2)*4)+0] = '0';
                    tab[((i-2)*4)+1] = '0';
                    tab[((i-2)*4)+2] = '0';
                    tab[((i-2)*4)+3] = '0';
                    break;
                case '1':
                    tab[((i-2)*4)+0] = '0';
                    tab[((i-2)*4)+1] = '0';
                    tab[((i-2)*4)+2] = '0';
                    tab[((i-2)*4)+3] = '1';               
                    break;
                case '2':
                    tab[((i-2)*4)+0] = '0';
                    tab[((i-2)*4)+1] = '0';
                    tab[((i-2)*4)+2] = '1';
                    tab[((i-2)*4)+3] = '0';
                    break;
                case '3':
                    tab[((i-2)*4)+0] = '0';
                    tab[((i-2)*4)+1] = '0';
                    tab[((i-2)*4)+2] = '1';
                    tab[((i-2)*4)+3] = '1';
                    break;
                case '4':
                    tab[((i-2)*4)+0] = '0';
                    tab[((i-2)*4)+1] = '1';
                    tab[((i-2)*4)+2] = '0';
                    tab[((i-2)*4)+3] = '0';
                    break;
                case '5':
                    tab[((i-2)*4)+0] = '0';
                    tab[((i-2)*4)+1] = '1';
                    tab[((i-2)*4)+2] = '0';
                    tab[((i-2)*4)+3] = '1';
                    break;
                case '6':
                    tab[((i-2)*4)+0] = '0';
                    tab[((i-2)*4)+1] = '1';
                    tab[((i-2)*4)+2] = '1';
                    tab[((i-2)*4)+3] = '0';
                    break;
                case '7':
                    tab[((i-2)*4)+0] = '0';
                    tab[((i-2)*4)+1] = '1';
                    tab[((i-2)*4)+2] = '1';
                    tab[((i-2)*4)+3] = '1';
                    break;
                case '8':
                    tab[((i-2)*4)+0] = '1';
                    tab[((i-2)*4)+1] = '0';
                    tab[((i-2)*4)+2] = '0';
                    tab[((i-2)*4)+3] = '0';
                    break;
                case '9':
                    tab[((i-2)*4)+0] = '1';
                    tab[((i-2)*4)+1] = '0';
                    tab[((i-2)*4)+2] = '0';
                    tab[((i-2)*4)+3] = '1';
                    break;
                case 'a':
                    tab[((i-2)*4)+0] = '1';
                    tab[((i-2)*4)+1] = '0';
                    tab[((i-2)*4)+2] = '1';
                    tab[((i-2)*4)+3] = '0';
                    break;
                case 'b':
                    tab[((i-2)*4)+0] = '1';
                    tab[((i-2)*4)+1] = '0';
                    tab[((i-2)*4)+2] = '1';
                    tab[((i-2)*4)+3] = '1';
                    break;
                case 'c':
                    tab[((i-2)*4)+0] = '1';
                    tab[((i-2)*4)+1] = '1';
                    tab[((i-2)*4)+2] = '0';
                    tab[((i-2)*4)+3] = '0';
                    break;
                case 'd':
                    tab[((i-2)*4)+0] = '1';
                    tab[((i-2)*4)+1] = '1';
                    tab[((i-2)*4)+2] = '0';
                    tab[((i-2)*4)+3] = '1';
                    break;
                case 'e':
                    tab[((i-2)*4)+0] = '1';
                    tab[((i-2)*4)+1] = '1';
                    tab[((i-2)*4)+2] = '1';
                    tab[((i-2)*4)+3] = '0';
                    break;
                case 'f':
                    tab[((i-2)*4)+0] = '1';
                    tab[((i-2)*4)+1] = '1';
                    tab[((i-2)*4)+2] = '1';
                    tab[((i-2)*4)+3] = '1';
                    break;
                default:
                    printf("\n Chiffre Hexadécimal non valide %c",
                        tab[i]);
            }
            
            }
}

// Vérifie la taille du tableau de caractere
int checkLengthCharArray(char *charArr)
{
    int i=0;
    while(charArr[i]!='\0')
    {
        i++;
    }
    return i;
}

// Vérifie la valeur d'entrée en Hexadecimal
int checkHexaValues(char *charArr)
{
    if(charArr[0] != '0' || charArr[1] != 'x')
    {
        return 1;
    }
    int i=2;

    while(charArr[i] != '\0')
    {
        // Si le caractere dans le tableau est compris entre 0->F ou 0->f selon la table ASCII
        if ( ((charArr[i] >= 48) && (charArr[i] <= 57)) || ((charArr[i] >= 65) && (charArr[i] <= 70)) 
                                                        || ((charArr[i] >= 97) && (charArr[i] <= 102)))
        {
            i++;
        }
        else
        {
            return 1;
        }
        
    }

    return 0;
}

int main(int argc, char **argv) 
{
    // Vérifie le nombre d'arguments entrer
    if (argc!=3)
    {
        printf("Deux valeurs en hexadecimal doivent être données au programme pour qu'il fonctionne\n");
        return 1;
    }
    
    // Copie les deux arguments dans des tableaux de characteres
    char *hex1 = argv[1];
    char *hex2 = argv[2];
    
    // Vérifie si les deux arguments ont des valeurs en hexadecimal qui sont correctes
    // Vérifie si les deux arguments commencent par '0x'
    if(checkHexaValues(hex1) == 1 || checkHexaValues(hex2) == 1)
    {
        printf("Un des arguments n'est pas en hexadecimal\n");
        return 2;
    }
    
    // Vérifie si les deux arguments ont entre 3 et 6 characters
    if( checkLengthCharArray(hex1) > 6 || checkLengthCharArray(hex1) < 3 
     || checkLengthCharArray(hex2) > 6 || checkLengthCharArray(hex2) < 3)
    
    {
        printf("Un des arguments ne peux pas être representé sur 16 bits\n");
        return 2;
    }
    
    // Convertir les valeurs des deux tableaux en binaire
    char tab1[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
    char tab2[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};

    printf("%s hex1\n",hex1);
    printf("%s hex2\n",hex2);


    convertir_entree(tab1, hex1);
    convertir_entree(tab2, hex2);

    // On recopie les valeurs de tab1 dans un nouveau tableau de caratere pour y ajouter un '\0'
    char tab1temp[17];
    for(int l=0; l<16; l++)
    {
        tab1temp[l] = tab1[l];
    }
    
    // On ajoute le \0 pour pouvoir imprimer correctement les valeurs en binaire de tab1
    tab1temp[16] = '\0';

    // On recopie les valeurs de tab2 dans un nouveau tableau de caratere pour y ajouter un '\0'
    char tab2temp[17];
    for(int l=0; l<16; l++)
    {
        tab2temp[l] = tab2[l];
    }
    
    // On ajoute le \0 pour pouvoir imprimer correctement les valeurs en binaire de tab2
    tab2temp[16] = '\0';
    
    printf("%s tab1\n",tab1temp);
    printf("%s tab2\n",tab2temp);

    // On creer un tableau contenant des valeurs initial de '0' pour pouvoir un stocker le resultat de la somme de tab1 et tab2
    char sum[16] = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
    
    // On creer un caractere auquel est assigné le résultat du carryOut (overflow)
    char overflow = add_16b(tab1, tab2, sum);

    // On recopie les valeurs de 'sum' dans un nouveau tableau de caratere pour y ajouter un '\0'
    char sumtemp[17];
    for(int l=0; l<16; l++)
    {
        sumtemp[l] = sum[l];
    }

    // On ajoute le \0 pour pouvoir imprimer correctement les valeurs en binaire de sumtemp
    sumtemp[16] = '\0';
    printf("%s sum\n",sumtemp);
    printf("%c overflow\n", overflow);

    return 0;
}
