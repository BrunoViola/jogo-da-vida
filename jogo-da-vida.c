#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int geracoes, qtd, retorno,cont;
    char digito;
    cont = 0;
    retorno = 0;

    // ===== Declaracao das funcoes =====
    void delay(int segundos);
    void clear ();
    int **Liberar_matriz (int m, int n, int **pontMatriz);
    int **Liberar_novaMatriz (int m, int n, int **pontNovaMatriz);
    int imprimirGeracao (int matrizEscrita[30][30]);
    //===================================

    printf("Este programa foi criado por: Bruno Henrique Silva Viola - 1 Semestre");
    printf ("\nDigite a quantidade de geracoes a serem simuladas: ");
    scanf ("%d", &geracoes);
    //===== Parte responsavel pela abertura do arquivo =====
    FILE *file;
    file = fopen("quadro.txt","r");
    if (file==NULL){
        printf("Arquivo nao pode ser aberto\n");
        return 0;
    }
    //======================================================

    // ===== Declaracao das matrizes de alocacao dinamica =====
    int i, j;
    int **matriz;
    matriz = malloc(30 * sizeof (int *));
    for (i = 0; i < 30; ++i){
        matriz[i] = malloc( 30 * sizeof (int));
    }
    int **novaMatriz;
    novaMatriz = malloc(30 * sizeof (int *));
    for (i = 0; i < 30; ++i){
        novaMatriz[i] = malloc(30 * sizeof (int));
    }

    // ===== Leitura da matriz do arquivo =====
    for (i=0; i<30; i++){
        for (j=0;j<30;j++){
            fscanf(file," %c",&digito);
            matriz[i][j]= digito - '0';
        }
    }

    printf ("\n");

    //Essa parte serve para imprimir a matriz inicial na tela;
    printf("\nMatriz do arquivo: \n");
    for (i=0; i<30; i++){
        for (j=0;j<30;j++){
            printf ("%d", matriz[i][j]);
        }
        printf ("\n");
    }
//====================================================
while (cont<geracoes) //Laco responssvel por executar a quantidade de geracoes informadas pelo usuario
{
    delay (4.5);//O valor de entrada desta funcao eh a quantidade de segundos entre uma geracao e outra


    for (i=0; i<30; i++){
        for (j=0;j<30;j++){
            if(i == 0 && j ==0){ //canto superior esquerdo
                qtd = matriz[i][j+1] + matriz[i+1][j] + matriz[i+1][j+1];
            }else if (i==29 && j==0){//canto inferior esquerdo
                qtd = matriz[i-1][j] + matriz[i-1][j+1] + matriz[i][j+1];

            } else if (i== 0 && j ==29){ //canto superior direito
                qtd = matriz[i][j-1] + matriz[i+1][j-1] + matriz[i+1][j];

            } else if (i == 29 && j == 29){//canto inferior direito
                qtd = matriz[i][j-1] + matriz[i-1][j-1] + matriz[i-1][j];

            } else if (i==0 && j!=0 && j !=29){ //borda superior
                qtd = matriz[i][j-1] + matriz[i+1][j-1] + matriz[i+1][j]+matriz[i+1][j+1] + matriz[i][j+1];

            } else if (i != 0 && i != 29 && j ==0){//lado esquerdo
                qtd = matriz[i-1][j] + matriz[i-1][j+1] + matriz[i][j+1]+matriz[i+1][j+1] + matriz[i+1][j];

            } else if (i == 29 && j !=0 && j != 29){ //borda inferior
                qtd = matriz[i][j-1] + matriz[i-1][j-1] + matriz[i-1][j]+matriz[i-1][j+1] + matriz[i][j+1];

            } else if (i!=0 && i!= 29 && j == 29){ //lado direito
                qtd = qtd = matriz[i-1][j] + matriz[i-1][j-1] + matriz[i][j-1]+matriz[i+1][j-1] + matriz[i+1][j];

            }
            else{
                qtd = matriz[i-1][j-1] + matriz[i-1][j] + matriz[i-1][j+1] + matriz[i][j-1] + matriz[i][j+1] + matriz[i+1][j-1] + matriz[i+1][j] + matriz[i+1][j+1];
            }

            //Esta parte verifica o valor a ser inserido em cada posi��o da nova matriz (0 ou 1)
            if (matriz[i][j]== 1 && qtd<2){
                retorno = 0;
            } else if(matriz[i][j] == 1 && qtd>3){
                retorno = 0;
            } else if (matriz[i][j] == 1 && qtd== 2){
                retorno = 1;
            } else if (matriz[i][j] == 1 && qtd == 3){
                retorno = matriz[i][j];
            } else if (matriz[i][j] == 0 && qtd == 3){
                retorno = 1;
            } else if (matriz[i][j]==0 && qtd ==2){
                retorno = 0;
            } else if (matriz[i][j]==0 && qtd == 0){
                retorno = 0;
            } else if (matriz [i][j]==0 && qtd ==1){
                retorno = 0;
            } else {
                retorno = matriz[i][j];
            }
            novaMatriz[i][j] = retorno;
        }
    }

    clear();
    printf ("\n%d Geracao: \n", cont+1);
    for (i=0; i<30; i++){
        for (j=0;j<30;j++){
            printf ("%d", novaMatriz[i][j]);
            matriz[i][j] = novaMatriz[i][j];
        }
        printf ("\n");
    }
    cont = cont +1;

}

    Liberar_matriz (30, 30, matriz);
    Liberar_novaMatriz ( 30, 30, novaMatriz);
    fclose(file);
    return 0;
}

void delay(int segundos) //Funcao destinada a criar o delay entre geracoes
{
    int milissegundos = 1000 * segundos;

    clock_t tempoinicial = clock();

    while (clock() < tempoinicial + milissegundos);
}

int **Liberar_matriz (int m, int n, int **pontMatriz) { //Funcao destinada a liberacao da matriz
    int i;
    if (pontMatriz == NULL) return (NULL);
    for (i = 0; i < m; i++) free (pontMatriz[i]);
    free (pontMatriz);
    return (NULL);
}

int **Liberar_novaMatriz (int m, int n, int **pontNovaMatriz) { //Funcao destinada a liberacao da novaMatriz
    int i;
    if (pontNovaMatriz == NULL) return (NULL);
    for (i = 0; i < m; i++) free (pontNovaMatriz[i]);
    free (pontNovaMatriz);
    return (NULL);
}

void clear (){ //Funcao destinada a limpeza do terminal a partir da identificacao do sistema utilizado
   #ifdef _WIN32
        system("cls");
   #elif __linux
        system ("clear");
   #else
    printf("\nSistema nao reconhecido para a limpeza do terminal");

   #endif
}
