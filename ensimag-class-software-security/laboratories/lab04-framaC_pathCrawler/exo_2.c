
/*

  - This code may contain arithmetic overflows ...
     Run the RTE analysis to see why:
        frama-c-gui -rte exo_2.c

  - Try to correct them (without changing the read function) but by adding 
     conditional statements before each arithmetic expressions 

  - Check with VSA is your result is correct: 
        frama-c-gui -rte -eva exo_2.c

  - Additionally you can also try WP:  
        frama-c-gui -rte -wp exo_2.c
    


*/



#include <limits.h>
  
int read();
// no body, may return any int value

int main()
{ int a=read();
  int b=read();
  unsigned int r;
  r = a+b;
  r = a*2;
  return 0 ;
}
