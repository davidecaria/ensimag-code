
/*

 - Run a VSA analysis (by hand) to check if this code is bug free ...

 - Confirm your result with frama-c  ...

 - Intuitively, is this code really bug free or not ???

 - Run WP analysis to get a more complete verdict on this example 

 - Can you explain theses results ?

*/



//@ ensures \result <10 ;
int read();
// no body, may return any int value

void main()
{ int a=read();
  int b=read();
  int t[10] ;
  if (a < b)
	t[b-a] = 0 ;
  else 
	t[a-b] = 0 ;
}
