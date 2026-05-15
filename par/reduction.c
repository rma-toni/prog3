#include <stdio.h>
#include <omp.h>

int main (int argc, char *argv[]) {
	int i, n, id;
    float x[100], suma;
	n = 10;
	suma = 0.0;
	for (i=0; i < n; i++){
	  x[i] =  rand() % 11; 
      printf("%f\n",x[i]);
	  suma = suma + x[i];
	}
	printf("Suma = %f\n",suma); 
	suma = 0.0;
	#pragma omp parallel for reduction(+:suma) private (id)
	for (i=0; i < n; i++){
		id = omp_get_thread_num();	    
		suma = suma + x[i];
		printf("Thread: %d - suma %f\n", id, suma);
		//if (id == 0){
		//	printf("Y[%d]= %f\n",i,a[i]);	
		//}
	}
	printf("Suma = %f\n",suma); 
}
