#include <pthread.h> 
#include <stdlib.h>
int var = 0; 
//void* child_fn ( void* arg ) { var++;
// return NULL; 
//}

 int main ( void ) { 
//pthread_t child;
 //pthread_create(&child,NULL, child_fn, NULL); 
//var++;  pthread_join(child, NULL);
int* a=(int *)malloc(sizeof (int)*10);
free(a);
 return 0;
 }
