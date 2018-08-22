#include<stdio.h>
#include<stdlib.h>
radix_sort(int array[], int n);
void main(){
	int array[10000],n,i; 
	FILE* Arquivo;
	system("cls");
	printf("Quantidade de elementos a serem organizados: ");
	scanf("%d",&n);
	printf("\nElementos a serem organizados: \n");
 	
 	if((Arquivo=fopen("Entrada.txt", "r+"))==NULL) exit(1);
 	
 	for(i = 0 ; i < n ; i++ ){
  		fscanf(Arquivo,"%d\n",&array[i]);
  		printf("\t %d \n",array[i]);
  		
 	} 
  	fclose(Arquivo);
  	printf("\nVetor antes do Radix Sort:"); 
 	for(i = 0; i < n; i++){
  		printf("%8d", array[i]);
	}
	getchar();
	getchar();
 	printf("\n");
 	radix_sort(array,n);
	printf("\nVetor depois do Radix Sort: ");
 	
	for(i = 0; i < n; i++){
  		printf("%8d", array[i]);
	}
 	
	printf("\n");
 	getch();
}
 
radix_sort(int arr[], int n){
    int i;
    int b[n];
    int maior = arr[0];
    int exp = 1;
 
    for (i = 0; i < n; i++) {
        if (arr[i] > maior)
    	    maior = arr[i];
    }
 
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < n; i++)
    	    bucket[(arr[i] / exp) % 10]++; 
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = n - 1; i >= 0; i--)
    	    b[--bucket[(arr[i] / exp) % 10]] = arr[i];
    	for (i = 0; i < n; i++)
    	    arr[i] = b[i];
    	exp *= 10;
    }
}
