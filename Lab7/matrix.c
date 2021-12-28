#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
void *mult(void* argument)
{
	int *data = (int *)argument;
	int k = 0, i = 0;

	int x = data[0];
	for (i = 1; i <= x; i++)
		k += data[i]*data[i+x];

	int *p = (int*)malloc(sizeof(int));
		*p = k;


	pthread_exit(p);
}

int main()
{
int MAX1=0,MAX2,MAX3,MAX4;
	printf("enter the matrix 1 number of rows:\n");
	scanf("%d", &MAX1);
	printf("enter the matrix 1 number of columns:\n");
	scanf("%d", &MAX2);
	printf("enter the matrix 2 number of rows:\n");
	scanf("%d", &MAX3);
	printf("enter the matrix 2 number of columns:\n");
	scanf("%d", &MAX4);
	int matrixA[100][100];
	int matrixB[100][100];


	int row1=MAX1,col1=MAX2,row2=MAX3,col2=MAX4,i,j,k;


	
	for (i = 0; i < row1; i++){
			for (j = 0; j < col1; j++){
				printf("enter the first matrix value\n");
            	scanf("%d", &matrixA[i][j]);
			}
	}
	
	
	for (i = 0; i < row1; i++)
			for (j = 0; j < col1; j++){
				printf("enter the second matrix value\n");
  	            scanf("%d", &matrixB[i][j]);
			}
			
			
	printf("the first matrix values:\n");
	
	for (i = 0; i < row1; i++){
		for(j = 0; j < col1; j++)
			printf("%d ",matrixA[i][j]);
	     	printf("\n");
	}
	
	
	printf("the second matrix values:\n");
	for (i = 0; i < row2; i++){
		for(j = 0; j < col2; j++)
			printf("%d ",matrixB[i][j]);
	    	printf("\n");
	}
	
	int max = row1*col2;
	pthread_t *threads;
	threads = (pthread_t*)malloc(max*sizeof(pthread_t));

	int count = 0;
	int* data = NULL;
	for (i = 0; i < row1; i++)
		for (j = 0; j < col2; j++)
			{
			data = (int *)malloc((20)*sizeof(int));
			data[0] = col1;

			for (k = 0; k < col1; k++)
				data[k+1] = matrixA[i][k];

			for (k = 0; k < row2; k++)
				data[k+col1+1] = matrixB[k][j];
				pthread_create(&threads[count++], NULL,
							mult, (void*)(data));

		}

	printf("RESULTANT MATRIX IS :- \n");
	for (i = 0; i < max; i++)
	{
    	void *k;
	    pthread_join(threads[i], &k);
		int *p = (int *)k;
	    printf("%d ",*p);
	    if ((i + 1) % col2 == 0)
		    printf("\n");
	}
return 0;
}
