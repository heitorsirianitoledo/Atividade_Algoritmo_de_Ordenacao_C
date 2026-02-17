#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetorDecrescente(int *vetor, int tamanho) {
    int i;
    for(i=0;i<tamanho;i++){
    	vetor[i] = tamanho - 1 - i;
	}
   
}

void bubbleSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
	*comparacoes = 0;
	*movimentacoes = 0;
    int i,j,temp;
    for(i=0;i<tamanho-1;i++){
    	for(j=0;j<tamanho-i-1;j++){
    		(*comparacoes)++;
    		if(vetor[j] > vetor[j+1]){
    			temp = vetor[j];
    			vetor[j] = vetor[j+1];
    			vetor[j+1] = temp;
    			(*movimentacoes) += 3;
			}
		}
	}
    
}

void selectionSort(int *vetor, int tamanho, int *comparacoes, int *movimentacoes) {
	*comparacoes = 0;
	*movimentacoes = 0;
    int i,j,min_idx,temp;
    for(i=0;i<tamanho-1;i++){
    	min_idx = i;
    	for(j=i+1;j<tamanho;j++){
    		(*comparacoes)++;
    		if(vetor[j] < vetor[min_idx]){
    			min_idx = j;
			}
		}
		if(min_idx != i){
			temp = vetor[min_idx];
			vetor[min_idx] = vetor[i];
			vetor[i] = temp;
            (*movimentacoes) += 3;
		}
	}
}

void executarTeste(const char *algoritmo, void (*sortFunction)(int *, int, int *, int *), int tamanho) {
    int *vetor = (int *)malloc(tamanho * sizeof(int));
    int comparacoes, movimentacoes;
    clock_t inicio, fim;
    double tempo;
    
    preencherVetorDecrescente(vetor, tamanho);
    inicio = clock();
    sortFunction(vetor, tamanho, &comparacoes, &movimentacoes);
    fim = clock();
    tempo = ((double)(fim - inicio)) / (CLOCKS_PER_SEC / 1000);
    
    printf("| %-13s | %-7d | %-10.3f | %-12d | %-12d |\n", algoritmo, tamanho, tempo, comparacoes, movimentacoes);
    free(vetor);
}

int main() {
    printf("| Algoritmo     | Tamanho | Tempo (ms) | Comparacoes  | Movimentacoes  |\n");
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Bubble Sort", bubbleSort, 100);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Selection Sort", selectionSort, 100);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Bubble Sort", bubbleSort, 1000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Selection Sort", selectionSort, 1000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Bubble Sort", bubbleSort, 10000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    executarTeste("Selection Sort", selectionSort, 10000);
    printf("|---------------|---------|------------|--------------|----------------|\n");
    return 0;
}


/* Analisando os resultados, percebe-se que o selection sort apresentou um melhor desempenho, logo que ele realizou menos movimentações e
teve um tempo de execucao menor em relacao ao bubble sort
*/

