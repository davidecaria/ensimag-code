/*
    EXECUTING WITH -rte option 
    $ sudo frama-c-gui -rte demo_1.c
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
  y = 8;
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

The frama output allows to spot the varius errors that we may encounter at run time. 
Specifically, there are two sign overflow due tu the add/sub instruction. There we have a potential overflow due to the divition in line 27.
Most importantly, frama-c dedected the potental divition by zero error. 

*/

/*
    Performing the value-set-analysis with frama-c 
    $ sudo frama-c-gui -rte -eva demo_1.c
*/

/*
  EVA OUTPUT
*/

int main(void)
{
  int __retres;
  int x;
  int y;
  x = 10;
  y = 8;
  if (x > y) {
    y -= 8;
  }
  else {
    y += 8;
  }
  /*@ assert Eva: division_by_zero: y ≢ 0; */
  x /= y;
  __retres = 0;
  return __retres;
}

/*  COMMENT

As we can see from the frama-c output, eva is not able to prove that the division by 0 won't occur.
The other errors that RTE detected are discarded. We can be sure that they will not occur.

*/

