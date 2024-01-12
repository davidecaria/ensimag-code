// basic BoF 
// 

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{ 
  int x ;
  FILE *f = fopen(argv[1], "r") ;
  int t[100] ; 
  int i;

  if (argc != 2) return 1 ;
  fscanf(f, "%d", &x) ;
  for (i=0; i<x; i++)
  	t[i]= 42;
  return 0 ;
}
