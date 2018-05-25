
/*================================================*
 * Programa   - Editor de Arquivo                         |
 * Versao - 1.0                                   |
 * Autor  - Israel Santucci                         |
 *================================================*/
 //Biblioteca
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

//Declaracao das Funcoes
void apresentacao();
int menu();
int main();
void criarArquivo();
void abrirArquivo();
void editarArquivo();

int main(HANDLE cor1){
    int escolha=0;;
    HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);
    fflush(stdin);
    while(escolha != 4){
        escolha = menu(cor);
        fflush(stdin);
        //Abrir arquivo
        if(escolha == 1){
            abrirArquivo();
        }

        //Editar arquivo
        if(escolha == 2){
            editarArquivo();
        }

        //Criar
        if(escolha == 3){
            criarArquivo();
        }
    }
    printf("\n\n\n Finalizando ....");
    Sleep(1000);

    //getchar();
    return 0;
}

// Apresentacao do programa
void apresentacao(){
    printf("\n       ============================================\n");
    printf("\n       ************ EDITOR DE ARQUIVO *************\n");
    printf("\n       ============================================\n");

}
//menu do programa,
int menu(HANDLE cor1){
    int escolha;
    system("cls");
    apresentacao();
    SetConsoleTextAttribute(cor1,5);
    printf("\n\t\t       === MENU ===\n\n");
    SetConsoleTextAttribute(cor1,3);
    printf("\n\t\t       1 - Abrir \n");
    printf("\n\t\t       2 - Editar \n");
    printf("\n\t\t       3 - Criar \n");
    printf("\n\t\t       4 - sair \n");

    SetConsoleTextAttribute(cor1,6);
    printf("\n Digite a opcao desejada: ");
    scanf("%d",&escolha);
    if((escolha>=1)&&(escolha<=4)){
        return escolha;
    }else{
        menu(cor1);
    }
}

void criarArquivo(){
    char nomeArquivo[50];
    system("cls");
    printf("\n========= CRIANDO UM ARQUIVO =========\n\n\n");
    FILE *arquivoCriar;
    printf("Digite o nome do Arquivo: ");
    gets(nomeArquivo);
    if(arquivoCriar = fopen(nomeArquivo,"w")){
        printf("\n Arquivo criado com sussesso. \n");
        getchar();
    }else{
        printf("\n nao foi possivel criar o arquivo \n ");
        getchar();

    }
    fclose(arquivoCriar);

}

void abrirArquivo(){
    system("cls"); //limpar a tela
    char nomeArquivo[50];
    FILE *arquivoAbrir;
    char c;
    printf("\n ======= ABRINDO ARQUIVO ======\n\n\n");
    printf("\nInforme o nome do arquivo a ser aberto: ");
    gets(nomeArquivo);
    if(arquivoAbrir = fopen(nomeArquivo,"r")){// Abrindo o arquivo e ja testando se ele vai ser aberto. se aberto ele retorna um numero inteiro qualquer assim sendo verdadeiro, senao retorna 0 , sendo falso pula para o else.
        while((c = getc(arquivoAbrir))!= EOF){//While usado para a funcao getc pegar cada letra salva no arquivo e atribuir a variavel c
            printf("%c",c);                   //para depois ser mostrada na tela ate que seja encontrado o fim do arquivo que  sera indicada pela constante EOF (eng- End of File / pt- fim do arquivo).
        }

    }else{
        printf("\n Arquivo nao encontrado \n.");
    }
    fclose(arquivoAbrir);
    getchar();
}

void editarArquivo(){
    system("cls");
    FILE *arquivo;
    char nome[40],texto[1000];
    printf("\n ======= EDITAR ARQUIVO ======\n\n\n");
    printf("Digite o nome do arquivo: ");
    gets(nome);
    if(arquivo = fopen(nome,"r+")){
        printf("\n Digite o seu texto \n\n");
        fgets(texto,1000,stdin);
        fputs(texto,arquivo);
        printf("\n\nTexto salvo com sussesso.\n\n");
        getchar();
    }else{
        printf("\nArquivo nao encontrado\n");
        getchar();
    }

    fclose(arquivo);
}

