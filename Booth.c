#include <stdio.h>
#include <stdlib.h>

//algoritmo de booth de 4 bits

// colocando os valores dentro de vetores
void conversor(int a, int v[]){

    for(int i = 3; i>=0; i--){
        v[i] = a%10;
        a /= 10;
    }
}
// soma de binarios
void soma_bin(int A[], int B[]){
    int b = 0;
    for(int i = 3 ; i >= 0 ; i--){
        if (B[i] == A[i]){
            if (b == 1)
                A[i] = 1;
            else
                A[i] = 0;
            if (B[i] == 1)
                b = 1;
            else
                b = 0;
        }
        else {
            if (b == 1)
                A[i] = 0;
            else
                A[i] = 1;
        }

    }
}
// delocamento a direita
void shift(int A[], int *c){
    *c = A[7];
    for (int i = 6; i >= 0; i--){
        A[i+1] = A[i];
    }
}
int main()
{
    int a, bin_a[4]; // numero multiplicador
    int x, bin_x[4]; // numero mutiplicado
    int c = 0; //numero comparador
    int i, count = 0;// 'i' para funcao for, e count para percorrecer o vetor
    int bin_r[8]; // resultado
    int temp[4]; // vetor negativo de a

    //inicializando o resultado com 0
    for(i = 0 ; i < 8; i++){
        bin_r[i] = 0;
    }
	//leitura das variáveis
    scanf("%d %d",&a,&x);
	//colocando as em vetores cada unidade para utiliza las de forma correta
    conversor(a,bin_a);
    conversor(x,bin_x);
	
	// transformando o multiplicador em negativo que sera utilizado
    for(i = 7; i >= 0  ; i--){

        if (i > 3){
            temp[i-4] = bin_a[i-4];
            if(temp[i-4] == 1)
                temp[i-4] = 0;
            else
                temp[i-4] = 1;
        }
        else{
            if(temp[i] == 1)
                temp[i] = 0;
            else {
                temp[i] = 1;
                break;
            }
        }
    }
	
	// o resultado deve receber o numero multiplicado para realizar a operacao
    for (i = 0; i < 4 ; i++){
        bin_r[i+4] = bin_x[i];
    }

	// a partir do count gerando um loop 4x, irá acontecer a operacao que consiste em comparaçao, soma e deslocamento;
	/*'c' irá comparar o ditito menos sisgnificativo para determinar uma tomada de decisao,
	-- caso 'c' seja 1 e o digito seja 0, ocorrera somente uma soma envolvendo os quatro primeiros vetores do resultado
	-- com o multiplicador, caso contrario, a soma o ocorrera com o negativo deste ultimo com o resultado,
	-- caso na comparacao os valores sejam iguais, somente proceguiremos para a proxima etapa,
	-- apos isso ocrrera um deslocamento de bits a direita (com o digito menos significativo, substituindo o valor de 'c')
	-- exceto o primeiro digito que representa o sinal do resultado
	*/
    while(4>count++){
        if(bin_r[7] != c){
			// condicao para qual soma ocorrera
            if(c == 0) soma_bin(bin_r, temp);
            else soma_bin(bin_r, bin_a);
        }
		//funcao para o deslocamento
        shift(bin_r, &c);
    }
	//print do resultado
    for(i = 0; i < 8; i++){
        printf("%d",bin_r[i]);
    }
    printf("\n");

    return 0;
