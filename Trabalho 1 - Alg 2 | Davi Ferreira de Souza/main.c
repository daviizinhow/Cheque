#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <unistd.h> 
#include "funcoes.c"

#define usuario "bancobom"
#define senha "senhabanco"

typedef struct
{
    int dia;
    int mes;
    int ano;
}data;

void limpabuffer()
{
    while (getchar() != '\n');
}

void menu2();
int menu3();

int main()
{
    char user_inserido[100];
    char senha_inserida[100];
    int escolha;
    int ret;

    printf("┌───────────────────────────────────────┐\n");
    printf("│                                       │\n");
    printf("│   Bem vindo(a)!                       │\n");
    printf("│   Insira sua senha para continuar:    │\n");
    printf("│                                       │\n");
    printf("└───────────────────────────────────────┘\n");

    printf("Usuário: ");
    fgets(user_inserido, 100, stdin);

    printf("Senha: ");
    fgets(senha_inserida, 100, stdin);

    user_inserido[strlen(user_inserido) - 1] = '\0'; // Remove o \n no final da string
    senha_inserida[strlen(senha_inserida) - 1] = '\0';

    if (strcmp(user_inserido, usuario) != 0 || strcmp(senha_inserida, senha) != 0)
    {
        system("clear");
        printf("┌───────────────────────────────────┐\n");
        printf("│                                   │\n");
        printf("│   Usuário ou senha inválidos.     │\n");
        printf("│   Gostaria de tentar novamente?   │\n");
        printf("│                                   │\n");
        printf("│   1-Sim                           │\n");
        printf("│   2-Não                           │\n");
        printf("│                                   │\n");
        printf("└───────────────────────────────────┘\n\n");

        do
        {
            printf("Insira sua escolha: ");
            ret = scanf("%d", &escolha);
            if (escolha > 2 || escolha < 1 || ret != 1)
            {
                printf("\nEscolha inválida.\n");
                limpabuffer();
            }
        } while (ret != 1 || escolha > 2 || escolha < 1);

        if (escolha == 1)
        {
            system("clear");
            limpabuffer();
            main();
            return 0;
        }
        else
        {
            return 0;
        }
    }

    menu2();
}

void menu2()
{
    int escolha, ret;

    system("clear");
    printf("┌───────────────────────────────────┐\n");
    printf("│                                   │\n");
    printf("│   Opções:                         │\n");
    printf("│                                   │\n");
    printf("│   1-Enviar cheque                 │\n");
    printf("│   2-Sair                          │\n");
    printf("│                                   │\n");
    printf("└───────────────────────────────────┘\n\n");

    do
    {
        printf("Insira sua escolha: ");
        ret = scanf("%d", &escolha);
        if (escolha > 2 || escolha < 1 || ret != 1)
        {
            printf("\nEscolha inválida.\n");
            limpabuffer();
        }
    } while (ret != 1 || escolha > 2 || escolha < 1);

    if (escolha == 1)
    {
        printf("\n\n");
        limpabuffer();
        system("clear");
        menu3();
    }
    else
    {
        system("clear");
        limpabuffer();
        main();
    }
}

int menu3()
{
    int escolha, ret;
    long double valor;
    char valor_str[100] = "";
    char destinatario[100];
    char nome[100];
    char espacos[100] = "";
    char extenso[1000] = "";
    data data_hoje;
    int dia, mes, ano;

    do
    {
        printf("Insira o valor do cheque: ");
        ret = scanf("%Lf", &valor);

        if(ret != 1 || valor <= 0 || valor > 999999999999999999.99)
        {
            printf("\nEscolha inválida.\n");
            printf("Tente novamente.\n\n");
            limpabuffer();
        }
    }while(ret != 1 || valor <= 0 || valor > 999999999999999999.99);

    sprintf(valor_str, "%021.2Lf", valor);

    strcpy(extenso, "");
    
    strcpy(extenso, escreve_extenso(valor_str)); 



    limpabuffer();

    printf("Insira o nome do destinatário: ");
    fgets(destinatario, 100, stdin);

    destinatario[strlen(destinatario) - 1] = '\0';

    printf("Insira a data de hoje(dd/mm/ano) : ");
    
    do
    {
        scanf("%d/%d/%d", &data_hoje.dia, &data_hoje.mes, &data_hoje.ano);
        if(data_hoje.dia < 1 || data_hoje.dia > 31 || data_hoje.mes < 1 || data_hoje.mes > 12 || data_hoje.ano < 1)
        {
            printf("\nData inválida.\n");
            printf("Insira a data novamente: ");
            limpabuffer();
        }
    }while(data_hoje.dia < 1 || data_hoje.dia > 31 || data_hoje.mes < 1 || data_hoje.mes > 12 || data_hoje.ano < 1);


    

    limpabuffer();

    printf("Insira seu nome: ");
    fgets(nome, 100, stdin);

    nome[strlen(nome) - 1] = '\0';
    destinatario[0] = toupper(destinatario[0]);
    nome[0] = toupper(nome[0]);

    system("clear");
    

    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
    printf("    Pague por meio\n");
    printf("    deste cheque uma quantia de: %s\n", extenso);
    printf("    a %s\n", destinatario);
    printf("    BANCO BOM\n");
    printf("%-70s%s\n", espacos, nome);
    printf("%-70s%02d/%02d/%04d\n", espacos, data_hoje.dia, data_hoje.mes, data_hoje.ano);
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
    
    sleep(10);
    system("clear");


    printf("┌───────────────────────────────────────┐\n");
    printf("│                                       │\n");
    printf("│   Gostaria de enviar outro cheque?    │\n");
    printf("│                                       │\n");
    printf("│   1-Sim                               │\n");
    printf("│   2-Não                               │\n");
    printf("│                                       │\n");
    printf("└───────────────────────────────────────┘\n\n");


    printf("Insira sua escolha: ");
    do
    {
        ret = scanf("%d", &escolha);
        if(ret != 1 || escolha > 2 || escolha < 1)
        {
            printf("\nEscolha inválida.\n");
            printf("Tente novamente: ");
            limpabuffer();
        }
    }while(ret != 1 || escolha > 2 || escolha < 1);

    if(escolha == 1)
    {
        system("clear");
        menu3();
        return 0;
    }
    else
    {
        return 0;
    }



}


 