/*
    EXECUTING WITH -rte option 
    $ sudo frama-c-gui -rte demo_2.c
*/

/*
    RTE OUTPUT:
*/

int main(void)
{
  int __retres;
  int x;
  int y;
  x = 10;
  y = read();
  if (x > y) {
    /*@ assert rte: signed_overflow: -2147483648 ≤ y - 8; */
    y -= 8;
  }
  else {
    /*@ assert rte: signed_overflow: y + 8 ≤ 2147483647; */
    y += 8;
  }
  /*@ assert rte: division_by_zero: y ≢ 0; */
  /*@ assert rte: signed_overflow: x / y ≤ 2147483647; */
  x /= y;
  __retres = 0;
  return __retres;
}

/*  COMMENT

Frama-c is able to dectect the same error set as for demo_1.c

*/

/*
    Performing the value-set-analysis with frama-c 
    $ sudo frama-c-gui -rte -eva demo_2.c
*/

/*
  EVA OUTPUT
*/

/*@ ensures \result > 8;
    assigns \result;
    assigns \result \from \nothing; */
int read(void);

int main(void)
{
  int __retres;
  int x;
  int y;
  x = 10;
  y = read();
  if (x > y) {
    y -= 8;
  }
  else {
    /*@ assert Eva: signed_overflow: y + 8 ≤ 2147483647; */
    y += 8;
  }
  x /= y;
  __retres = 0;
  return __retres;
}



/*  COMMENT

Ensuring that the function read yields a value larger than 8 we are sure that the division by 0 won't occur.
However, frama-c is not able to state that the overflow related to y won't occur.
*/

