#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 10
// strchr procura um caractere em uma string --> strchr (nome, "@")
    
// strcmp compara duas strings 
typedef struct{
    char nome[50];
    char email[20];
    char sexo[10];
    char endereco[50];
    double altura;
    int vacina;
    int id;
}Usuario;

void cadastrar(Usuario uso[], int indice){
    int achou = 0;
    int achouS = 0;
    printf("\n\n----------CADASTRO----------");
    printf("\nDigite o nome: ");
    fgets(uso[indice].nome, sizeof(uso[indice].nome), stdin);
    fflush(stdin);

    do{
        printf("\nDigite o email: ");
        fgets(uso[indice].email, sizeof(uso[indice].email), stdin);
        fflush(stdin);

        if(strchr(uso[indice].email, '@') == NULL){
            printf("Email invalido, tente novamente");
            achou = 0;
        }else{
            achou = 1;
        }
    }while(achou == 0);

    do{
        printf("\nDigite o sexo: ");
        fgets(uso[indice].sexo, sizeof(uso[indice].sexo), stdin);
        fflush(stdin);

        if(strcmp(uso[indice].sexo, "mas") != 0 ){
            printf("Sexo invalido, tente novamente");
            achouS = 0;
        }else if(strcmp(uso[indice].sexo, "fem") != 0 ){
             printf("Sexo invalido, tente novamente");
            achouS = 0;
        }else if(strcmp(uso[indice].sexo, "ind") != 0){
             printf("Sexo invalido, tente novamente");
             achouS = 0;
        }else{
            achouS = 1;
        }
    }while(achouS == 0 );

    do{
        printf("\nDigite a altura: ");
        scanf("%lf", &uso[indice].altura);
        fflush(stdin);

        if(uso[indice].altura < 1.00 && uso[indice].altura > 2.00){
            printf("Altura invalida, digite novamente");
             achou = 0;
        }else{
            achou = 1;
        }
    }while(achou == 0);

    do{
        printf("\nVacina: [1] Sim [0] Não");
        scanf("%d", uso[indice].vacina);
        if(uso[indice].vacina < 1 && uso[indice].altura > 2){
            printf("Vacina invalida, digite novamente");
             achou = 0;
        }else{
            achou = 1;
        }
    }while(achou == 0);
}

main(){
    Usuario uso[TAM];
    int opcao, total_cadastros=0;

    do{
        printf("\n\n========================");
        printf("\n          MENU          ");
        printf("\n========================");
        printf("\n[1] Cadastrar");
        printf("\n[2] Imprimir usuarios");
        printf("\n[3] Buscar usuario");
        printf("\n[4] Alterar dados");
        printf("\n[5] Excluir usuario");
        printf("\n[0] Sair");
        printf("\nDigite a opcao: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch(opcao){
            case 1:
                if(total_cadastros < TAM){
                    cadastrar(uso, total_cadastros);
                    total_cadastros++;
                }else{
                    printf("\n**LIMITE DE CADASTROS ATINGIDO**");
                }
                break;
        //     case 2:
        //         if(total_cadastros == 0){
        //             printf("\n\nNao existem pessoas na lista");
        //         }else{
        //             printf("\n\n---LISTA DE CADASTROS---");
        //             imprimir_lista(uso, total_cadastros);
        //         }
        //         break;
        //     case 3:
        //         printf("\n-------CAMPO DE BUSCA-------");
        //         printf("\nInforme o id para buscar: ");
        //         scanf("%d", &busca_id);
        //         buscar(uso, total_cadastros, busca_id);
        //         fflush(stdin);
        //         break;
        //     case 4:
        //         printf("\n--ALTERACAO DE DADOS--");
        //         printf("\nDigite um id para alterar: ");
        //         scanf("%d", &busca_id);
        //         break;
        //     case 5:
        //         printf("\n---EXCLUIR USUARIO---");
        //         printf("\nDigite o id para excluir: ");
        //         scanf("%d", &busca_id);
        //         fflush(stdin);
        //         excluir(uso, total_cadastros, busca_id);
        //         total_cadastros--;
        //         break;
        //     default:
        //         printf("\n**SISTEMA ENCERRADO**");
        //         break;
        }
    
    }while(opcao != 0);
}

    
