#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

const char* separastring(const char* str, int inicio, int fim)
{

    int comprimento_substring = fim - inicio + 1;
    
    static char resultado[1000] = {0};

    strncpy(resultado, str + inicio, comprimento_substring);
    resultado[comprimento_substring] = '\0'; 
    
    return resultado;
}


const char* centena(char *cent)
{
    static char centena_extenso[1000] = {0};
    
    char unidades[15][100] = {"um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    char especiais[15][100] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove", "cem"};
    char dezenas[15][100] = {"vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
    char centenas[15][100] = {"cento", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

    int var1, var2,var3;

    
    var1 = cent[0] - '0';
    var2 = cent[1] - '0';
    var3 = cent[2] - '0';

    strcpy(centena_extenso, "");


    if(var1 == 0)
    {
        if(var2 == 0)
        {
            if(var3 == 0)
            {
                strcpy(centena_extenso, "l");
                return centena_extenso;
            }
            if(var3 > 0)
            {
                strcpy(centena_extenso, unidades[var3-1]);
            }

        }
        else if(var2 == 1)
        {
            strcpy(centena_extenso, especiais[var3]);
        }
        else
        {
            strcat(centena_extenso, dezenas[var2-2]);
            if(var3 > 0)
            {
                strcat(centena_extenso, " e ");
                strcat(centena_extenso, unidades[var3-1]);
            }
            

        }
    }

    else if(var1 == 1 && var2 == 0 && var3 == 0)
    {
        strcpy(centena_extenso, especiais[10]);
    }


    else
    {
        strcat(centena_extenso, centenas[var1-1]);
        strcat(centena_extenso, " e ");
        if(var2 == 1)
        {
            strcat(centena_extenso, especiais[var3]);
        }
        else
        {
            strcat(centena_extenso, dezenas[var2-2]);
            if(var3 > 0)
            {
                strcat(centena_extenso, " e ");
                strcat(centena_extenso, unidades[var3-1]);
            }
            

        }
    }


    return centena_extenso;
}

const char* escreve_extenso(char *num)
{
    static char resultado[1000] = {0};
    char temp[100];
    char casas[6][100] = {"quadrilhões","trilhões","bilhões", "milhões", "mil", ""};
    char casas_unitarias[6][100] = {"quadrilhão", "trilhão", "bilhão", "milhão", "mil", ""};
    int casa_a_mais = 1;

    memset(resultado, 0, sizeof(resultado));


    int j = 0;
    for(int i = 0; i < (strlen(num) - 3) / 3; i++)
    {
        strcpy(temp, separastring(num, j, j+2));
        j+=3;

        strcpy(temp, centena(temp));

        if(strcmp(temp, "um") == 0)
        {
            strcat(resultado, temp);
            strcat(resultado, " ");
            strcat(resultado, casas_unitarias[i]);
            if(i < (strlen(num) - 3) / 3 - 1)
            {
                strcat(resultado, " ");
            }
            casa_a_mais = 0;

        }


        else if(strcmp(temp, "l") != 0)
        {
            strcat(resultado, temp);
            strcat(resultado, " ");
            strcat(resultado, casas[i]);
            if(i < (strlen(num) - 3) / 3 - 1)
            {
                strcat(resultado, " ");
            }
            casa_a_mais = 1;

        }

        strcpy(temp, "");


    }

    if(atoi(num) == 1)
    {
        strcat(resultado, "real");
    }
    else if(casa_a_mais || atoi(num) == 1000)
    {
        strcpy(resultado, "");
        strcat(resultado, "mil reais");
    }
    else
    {
        strcat(resultado, "de reais");
    }


    strcpy(temp, separastring(num, strlen(num) - 2,strlen(num) - 1));



    if(strcmp(temp, "00") != 0)
    {

        strcat(resultado, " e ");


        char centavos[100] = "0";
        strcat(centavos, temp);

        strcat(resultado, centena(centavos));

        strcat(resultado, " centavos.");

    }



    return resultado;
    
}

