#include <stdio.h>
#include <math.h>
int main() {
  float x1, x2, y1, y2, r1, r2, s;
  scanf_s("%f%f%f%f%f%f", &x1, &y1, &r1, &x2, &y2, &r2);
  s = sqrtf((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  if ((r1 <= 0) || (r2 <= 0)) {
    printf("nekorrektnyy radius");
    return 1;
  }
  if ((r1 == r2) && (x1 == x2) && (y1 == y2)) {
    printf("sovpadayut ---- Obshchikh tochek: beskontchnost");
    return 0;
  }
  if ((r1 + r2) < s) {
    printf("ne peresekayutsya ---- Obshchikh tochek: 0");
    return 0;
  }
  if ((r1 + r2) == s) {
    printf("kasayutsya vneshne ---- Obshchikh tochek: 1");
    return 0;
  }
  if (fabs(r1 - r2) == s) {
    printf("kasayutsya vnutrenne ---- Obshchikh tochek: 1");
    return 0;
  }
  if ((s < (r1 + r2)) && (s > fabs(r1 - r2))) {
    printf("peresekayutsya ---- Obshchikh tochek: 2");
    return 0;
  }
  printf("odna v drugoy bez kasaniy ---- Obshchikh tochek: 0");
  return 0;
}