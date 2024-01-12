/*
    EXECUTING WITH -rte option 
    $ sudo frama-c-gui -rte copy.c
*/

/*
    RTE OUTPUT:
*/

void copy(int *dst, int *src)
{
  int i = 0;
  while (i < 100) {
    /*@ assert rte: mem_access: \valid(dst + i); */
    /*@ assert rte: mem_access: \valid_read(src + i); */
    *(dst + i) = *(src + i);
    /*@ assert rte: signed_overflow: i + 1 ≤ 2147483647; */
    i ++;
  }
  return;
}

/* COMMENT
Runtime Error Assertions: These assertions are checking for runtime errors at specific points in the code.

mem_access: \valid(dst + i); and mem_access: \valid_read(src + i); ensure that the current dst and src elements are valid memory locations.
signed_overflow: i + 1 ≤ 2147483647; checks for an integer overflow in the increment of i.

We have a total of 3 potential rte, we will have to validate it with the further analysis
*/

/*
    Performing the value-set-analysis with frama-c 
    $ sudo frama-c-gui -rte -eva -main copy copy.c
    The option "-main copy" has to be specified otherwise there would be no way for frama to find the entry point.
*/


