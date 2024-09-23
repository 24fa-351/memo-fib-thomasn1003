#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>



typedef unsigned long long fib_type;



fib_type fib_i_core(int nthNum, fib_type *memo) {

   if (nthNum == 0) {
      return 0;
    }

   if (nthNum == 1) {
      return 1;
   }

   if (memo[nthNum] != 0) {
      return memo[nthNum];
   } 

   fib_type prevprevnum = 0;
   fib_type prevnum = 1;
   fib_type currentnum = 0;

   for (int i = 2; i <= nthNum; i++) {

      currentnum = prevprevnum + prevnum;

      memo[i] = currentnum; 

      prevprevnum = prevnum;

      prevnum = currentnum;

   }

   return currentnum;

}



fib_type fib_i(int nthNum) {

   fib_type *memo = (fib_type *)calloc(nthNum + 1, sizeof(fib_type));

   fib_type result = fib_i_core(nthNum, memo);

   free(memo);

   return result;

}



fib_type fib_r_core(int nthNum, fib_type *memo) {
   if (nthNum == 0) {
      return 0;
   }

   if (nthNum == 1) {
      return 1;
   }

   if (memo[nthNum] != 0) {
      return memo[nthNum];
   } 

   memo[nthNum] = fib_r_core(nthNum - 1, memo) + fib_r_core(nthNum - 2, memo);

   return memo[nthNum];

}



fib_type fib_r(int nthNum) {

   fib_type *memo = (fib_type *)calloc(nthNum + 1, sizeof(fib_type));

   fib_type result = fib_r_core(nthNum, memo);

   free(memo);

   return result;

}



int will_overflow(fib_type a, fib_type b) {
   
   return a > 0 && b > 0 && (a > (ULLONG_MAX - b));

}



int main(int argc, char *argv[]) {

   int num = atoi(argv[1])-1;

   if (num < 0) {
      num = 0;
   }

   char method = argv[2][0];
   fib_type result;

    
   if (method == 'i') {
      result = fib_i(num);
   } 

   else if (method == 'r') {
      result = fib_r(num);
   }

   printf("%lld\n", result);

   return 0;

}
