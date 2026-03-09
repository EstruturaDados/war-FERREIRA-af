#include <stdio.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_TERRITORIOS 5

// --- Definição da Estrutura (struct) ---
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

// --- Função para limpar o buffer de entrada --- 
void limparBufferEntrada() {
    int c;
    while ((c = getchar ()) != '\n' && c != EOF);
}

// --- Função Principal (main) ---
int main() {
    struct Territorio mapa[MAX_TERRITORIOS];
    int totalterritorios = 0;
    int opcoes;
    
    // --- Laço Principal do Menu ---
    do {
        // Exibe o menu de opções.
        printf("=========================================\n");
        printf("   MAPA DO MUNDO \n");
        printf("=========================================\n");
        printf("1 - Cadastrar novo territorio\n");
        printf("2 - Listar todos os territorios\n");
        printf("0 - Sair\n");
        printf("-----------------------------------------\n");
        printf("Escolha uma opção: ");

        // Lê a opção do usuário.
        scanf("%d", &opcoes);
        limparBufferEntrada();

        // --- Procesamento da Opção ---
        switch (opcoes)
        {
        case 1: // CADASTRAR UM TERRITORIO
            printf("--- Cadastro de Novo Territorio --- \n\n");

            if (totalterritorios < MAX_TERRITORIOS) {
                printf("Digite o nome do territorio: ");
                scanf("%s", &mapa[totalterritorios].nome);

                printf("Digite a cor do territorio: ");
                scanf("%s", &mapa[totalterritorios].cor);

                printf("Digite a quantidade de tropas: ");
                scanf("%d", &mapa[totalterritorios].tropas);

                totalterritorios ++;
                printf("\n Territorio cadastrado com sucesso! \n");
            } else {
                printf("Mapa cheio! Não é possivel cadastrar mais territorios. \n");
            }

        case 2: // LISTAGEM DE TERRITORIOS
            printf("--- Lista de Territorios Cadastrados --- \n\n");

            if (totalterritorios == 0) {
                printf("Nenhum territorio cadastrado. \n");
            } else {
                for (int i = 0; i < totalterritorios; i++) {
                    printf("--------------------------------------\n");
                    printf("TERRITORIO %d\n", i + 1);
                    printf("Nome: %s\n", mapa[i].nome);
                    printf("Cor: %s\n", mapa[i].cor);
                    printf("Número de tropas: %d\n", mapa[i].tropas);
                }
                printf("----------------------------------\n");
            }

                printf("\n Precione Enter para continuar...\n");
                getchar();
                break;    

        case 0: // SAIR
            printf("\n Saindo do sistema...");
            break;

        default: //OPÇÃO INVÁLIDA    
            printf("\n Opção invalida! Tente novamente. \n");
            printf("\n Pressione Enter para continuar...");
            getchar();
            break;
        
        }

    } while (opcoes != 0);

    return 0; // Fim do programa
    
}