#include <stdio.h>

// Função para inicializar o tabuleiro com 0s (água)
void inicializarTabuleiro(int tabuleiro[10][10]) {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para verificar se é possível posicionar um navio
// Retorna 1 se válido, 0 se inválido
int posicaoValida(int tabuleiro[10][10], int linha, int coluna, int horizontal) {
    int tamanho_navio = 3; // Tamanho fixo do navio
    
    // Verifica se está dentro dos limites do tabuleiro
    if (horizontal) {
        if (coluna + tamanho_navio > 10) return 0;
    } else {
        if (linha + tamanho_navio > 10) return 0;
    }

    // Verifica se as posições estão livres (valor 0)
    for (int i = 0; i < tamanho_navio; i++) {
        if (horizontal) {
            if (tabuleiro[linha][coluna + i] != 0) return 0;
        } else {
            if (tabuleiro[linha + i][coluna] != 0) return 0;
        }
    }

    return 1;
}

// Função para posicionar um navio
void posicionarNavio(int tabuleiro[10][10], int linha, int coluna, int horizontal) {
    int tamanho_navio = 3;
    for (int i = 0; i < tamanho_navio; i++) {
        if (horizontal) {
            tabuleiro[linha][coluna + i] = 3; // Navio horizontal
        } else {
            tabuleiro[linha + i][coluna] = 3; // Navio vertical
        }
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[10][10]) {
    printf("\nTabuleiro de Batalha Naval:\n");
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[10][10];
    
    // Inicializa o tabuleiro com água (0s)
    inicializarTabuleiro(tabuleiro);
    
    // Coordenadas dos navios 
    int linha_h = 2, coluna_h = 3; // Navio horizontal
    int linha_v = 5, coluna_v = 7; // Navio vertical
    
    // Posiciona o navio horizontal (verificando antes)
    if (posicaoValida(tabuleiro, linha_h, coluna_h, 1)) {
        posicionarNavio(tabuleiro, linha_h, coluna_h, 1);
    } else {
        printf("Erro: Não foi possível posicionar o navio horizontal nas coordenadas (%d, %d)\n", linha_h, coluna_h);
        return 1;
    }
    
    // Posiciona o navio vertical (verificando antes)
    if (posicaoValida(tabuleiro, linha_v, coluna_v, 0)) {
        posicionarNavio(tabuleiro, linha_v, coluna_v, 0);
    } else {
        printf("Erro: Não foi possível posicionar o navio vertical nas coordenadas (%d, %d)\n", linha_v, coluna_v);
        return 1;
    }
    
    // Exibe o tabuleiro com os navios posicionados
    imprimirTabuleiro(tabuleiro);
    
    return 0;
}