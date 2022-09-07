#include<stdio.h>
#include<stdlib.h>

int menu()
{
    int opcao;

    //Menu inicial
    printf("======================================\n");
    printf("============MENU PRINCIPAL============\n");
    printf("======================================\n");

    printf("Digite uma das opções:\n");
    printf("1. Cadastro de médico\n");
    printf("2. Cadastro de paciente\n");
    printf("3. Buscar paciente\n");
    printf("0. Sair\n");

    scanf("%1d", &opcao);

    // Executa programa correspondente
    switch (opcao) {        
        case 1:
            printf("Carregando cadastro de médicos...\n");
            system("build/registro");
            break;

        case 2:
            printf("Carregando tela de login...\n");
            system("build/login");
            break;

        case 3:
            printf("Carregando tela de busca...\n");
            system("build/busca");
            break;

        case 0:
            printf("Encerrando o programa...\n");
            return 0;
            break;
        
        default:
            printf("O número inserido não corresponde a nenhuma das opcões.\n");
            menu();
            break;
    }
}

int main() {

    menu();    
}