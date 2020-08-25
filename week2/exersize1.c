#include <stdio.h>
#include <limits.h>

int main(void) {
  int a = INT_MAX;
  float b = __FLT_MAX__;
  double c = __DBL_MAX__;
  printf("int size: %d \nfloat size: %d \ndouble size: %d \n", sizeof(a), sizeof(b), sizeof(c));
  printf("int max: %d\nfloat max: %f\ndouble max: %f\n", a, b, c);
  return 0;
}