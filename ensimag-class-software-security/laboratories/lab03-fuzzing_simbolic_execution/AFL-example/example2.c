// basic BoF 
//


#define L 100

#include <stdio.h>
#include <stdlib.h>


int main (int argc, char *argv[]) 
{ 
  int x ;
  FILE *f = fopen(argv[1], "r") ;
  int t[L] ; 
  int i;

  if (argc != 2) return 1 ;
  fscanf(f, "%d", &x) ;
  if (x>L+20) return 1 ;
  for (i=0; i<=x; i++)
  	t[i]= 42;
  return 0 ;
}
