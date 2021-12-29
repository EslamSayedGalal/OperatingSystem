
#include <pthread.h>
#include <stdio.h>
#include <conio.h>  
#include <stdlib.h> 
#include <sys/types.h>
#include <sys/wait.h> 
int carryNumber= 0;

//create random thread 
void* Create_Randam_thread( void * parameter )
{   
    int x=rand();
    int myNum = *((int*)parameter);
    printf( "Start thread %i", myNum);
    printf("  >> the random number is %d\n",x%10 + 1);
    carryNumber +=x%10 + 1;
}
//create main thread
void* MainThread( void * parameter )
{   
    printf("the sum  = %i\n" , carryNumber);
}
int main()
{ 
    int * arr;
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    arr[3]=4;
    arr[4]=5;

    
pthread_t threadMain,thread1,thread2,thread3,thread4;

//thread 1
pthread_create( &thread1, 0, Create_Randam_thread, &arr[0] );
pthread_join( thread1, 0 );
//thread 2
pthread_create( &thread2, 0, Create_Randam_thread, &arr[1] );
pthread_join( thread2, 0 );
//thread 3
pthread_create( &thread3, 0, Create_Randam_thread, &arr[2] );
pthread_join( thread3, 0 );
//thread 4
pthread_create( &thread4, 0, Create_Randam_thread, &arr[3]);
pthread_join( thread4, 0 );
//main thread
pthread_create( &threadMain, 0, MainThread, 0);
wait(pthread_join(threadMain,0));


}
