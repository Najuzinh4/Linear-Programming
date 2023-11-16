#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>


double forma_padrao(int restricoes, int qtd){
	 int maior_menor[restricoes];
	 double valores[restricoes+4][50];
	 double resultado[restricoes];
	 int i, j, k, min_max;
	 int resp=0;
	 int cont=1;
	 int var_art=0;
	 for(k=1; k<=restricoes; k++){
			maior_menor[k]==0;
			resultado[k]==0;
			}
	 for(i=1; i<=restricoes+4 ; i++){
	 	for(j=1; j<=50; j++){
	 		valores[i][j]==0;
		 }
	 }

	 printf("\n\nDigite os valores de Xi nas restricoes:\n");
	 for(i=1; i<= restricoes; i++){ //numero de s.a
	 	for(j=1; j<=qtd; j++){ //qtd de x, comeca no 3, pois na matriz ainda vamos adicionar as bases
	 		printf("\nValor de X%d na %d restricao: ", j, i);
	 		if(j==qtd){ // se for o ultimo valor de x, ve se é >= ou <=
	 			scanf("%lf", &valores[i][j]);
	 			
	 			do{
	 				printf("\nMaior igual (1) menor igual (2) ou igual (3)?: ");
					scanf("%d", &resp);
					maior_menor[i]=resp; //vetor que fala se a restriçao eh maior, menor ou igual
	 				if (resp !=1 && resp !=2 && resp !=3){
	 					printf("\nResposta invalida!\n");
	 				} 
				 } while (resp != 1 && resp != 2 && resp !=3);
				 
				 
				 if(maior_menor[i]==1){
				 	printf("\nA inequacao eh maior ou igual a: ");
				 	scanf("%lf", &resultado[i]);

				 	if(resultado[i] < 0){
				 		maior_menor[i]=2;
				 		printf("\nValor negativo, inequacao fica menor ou igual\n");
				 		resultado[i]= -resultado[i];
				 		for(k=1; k<=qtd; k++){ //todos os valores da restrições vezes -1
				 			valores[i][k]= -valores[i][k];
						 }
					 }
					 break;
				 }
				 
				 if(maior_menor[i]==2){
				 	printf("\nA inequacao eh menor ou igual a: ");
				 	scanf("%lf", &resultado[i]);
				 	if(resultado[i] < 0){
				 		maior_menor[i]=1;
				 		printf("\nValor negativo, inequacao fica maior ou igual\n");
				 		resultado[i]= -resultado[i];
				 		for(k=1; k<=qtd; k++){ //todos os valores da restrições vezes -1
				 			valores[i][k]= -valores[i][k];
						 }
					 }
					 break;
				 }
				 
				 if(maior_menor[i] == 3){
				 	printf("\nA inequacao eh igual a: ");
				 	scanf("%lf", &resultado[i]);
				 	if(resultado[i] < 0){
				 		maior_menor[i]=3;
				 		printf("\nValor negativo, inequacao fica igual\n");
				 		resultado[i]= -resultado[i];
				 		for(k=1; k<=qtd; k++){ //todos os valores da restrições vezes -1
				 			valores[i][k]= -valores[i][k];
						 }
					 }
					 break;
				 }
			 }
			else
				scanf("%lf", &valores[i][j]); //se ainda não for o ultimo x, continua
		}
	}
	int var_folga = qtd;
			//adicionar variaveis de folga, e se existir, as variaveis artificiais	
	for (i = 1; i <= 2; i++) {
        for (k = 1; k <= restricoes; k++) {
            if (i == 1) {
                if (maior_menor[k] == 1) {
                    valores[k][qtd + cont] = -1;  
                    cont++;
                    var_folga++;
                } else if (maior_menor[k] == 2) {
                    valores[k][qtd + cont] = 1;  
                    cont++;
                    var_folga++;
                } else if (maior_menor[k] == 3) {
                    valores[k][qtd + cont] = 1;  
                    cont++;
                    var_folga++;
                }
            }
            else{
            	if (maior_menor[k] == 1) {
            		var_art++;
                    valores[k][var_folga + var_art] = 1;
			}
        }
        
		
    }
}		 
	 double z[var_folga+var_art];
	 double za[var_folga+var_art];	 
	 double matriz[restricoes][cont+qtd];
	 for(i=1; i<=restricoes; i++){
	 	for(j=1; j<=var_folga+var_art; j++){
	 		printf("%.4lf ", valores[i][j]);
	 		matriz[i][j]=valores[i][j];
	 		z[i]=0;
	 		za[i]=0;
	 		
		 }
		 printf("\n");
	 }
	 printf("\n\n");
	 
	 do{
	 	printf("\nA funcao objetiva eh min (1) ou max (2)?: ");
		scanf("%d", &min_max);
	 		if (min_max !=1 && min_max !=2){
	 			printf("\nResposta invalida!\n");
	 				} 
		 } while (min_max != 1 && min_max != 2);
	 if(min_max==2){ //forma padrão
	 	printf("\nDe os valores de x na funcao: ");
	 	for(k=1; k<=var_folga+var_art; k++){ // valores da função objetiva com as variaveis artificiais = 0 
	 		if(k<=qtd){
			printf("\nvalor de X%d: ", k);
	 		scanf("%lf", &z[k]);
	 		z[k]= -z[k];
	 	}
	 
	 		else{
	 			z[k] = 0;
			 }
		}
	}
	else{
		for(k=1; k<=var_folga+var_art; k++){ // valores da função objetiva com as variaveis artificiais = 0, quando ja esta na forma padrao
	 		if(k<=qtd){
			printf("\nvalor de X%d: ", k);
	 		scanf("%lf", &z[k]);}
	 		else{
	 			z[k] = 0;
			 }
	}
}
	 		
	 		
		for(k=1; k<=var_folga+var_art; k++){ //valores de z artificial
			if(k<=var_folga){
				za[k]=0;
			}
			else
				za[k]=1; //variaveis artificiais valendo 1
		}
		 
		 
		 printf("\n\n Valor de Z: ");
		 for(k=1; k<=var_folga+var_art; k++){
		 	printf("%.4lf X%d  ", z[k], k);
		 }
		 
		 printf("\n\n Valor de Za: ");
		 for(k=1; k<=var_folga+var_art; k++){
		 	printf("%.4lf X%d  ", za[k], k);
		 }
	
	 //ja temos pra começar o simplex, a matriz do meio, os valores de z e z artificial, que ficam e cima; os resultados das inequações, que ficam do lado direito
	 // agr eh so criar uma função simplex, passar tudo isso como parametro, pegar as bases, e fazer as contas

}


int main(){
	int restricoes, qtd;
	printf("Quantas restricoes existem?: ");
	scanf("%d", &restricoes);
	printf("\n Quantos x existem?: ");
	scanf("%d", &qtd);
	forma_padrao(restricoes, qtd);
}