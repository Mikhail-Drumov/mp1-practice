#include <stdio.h>
#include <string.h>
#define D 10
#define S 100
#define P 5
int order() {
  int t;
  scanf("%d", &t);
  scanf("%*c");
  return t;
}
void Case1(char prom[]) {
  scanf("%s", prom);
}
void Case2(char code[][P], char name[][D], float cost[], float dis[], char scan[][P], int h, char prom[]) {
  int j, fl = 0, t;
  for (j = 0; j < D; j++) {
    if (strcmp(code[j], prom) != 0) {
      continue;
    }
    else {
      fl = 1;
      printf("%s", code[j]);
      printf(" ");
      printf("%s", name[j]);
      printf(" %.0f ", cost[j]);
      printf("%.0f%%\n", dis[j]);
      break;
    }
  }
  if (fl == 0) {
    printf("Product not found\n");
  }
  else {
    printf("Add to the receipt?\n");
    printf("11 - Yes\n");
    printf("10 - No\n");
    do {
      scanf("%d", &t);
      scanf("%*c");
    } while (t < 10 || t>11);
    printf("You can continue the purchase\n");
    if (t == 10) {
      return;
    }
    else {
      for (j = 0; j < P; j++) {
        scan[h][j] = prom[j];
      }
      return;
    }
  }
}
void Case3(char scan[][P], char code[][P], char name[][D], float cost[],
  float dis[], float sum1, float sum2, int num[], int h) {
  int j, k, p, fl;
  for (k = 0; k < h; k++) {
    for (j = 0; j < D; j++) {
      if (strcmp(code[j], scan[k]) != 0) {
        continue;
      }
      else {
        fl = 1;
        for (p = 0; p < k; p++) {
          if (strcmp(scan[p], scan[k]) == 0) {
            fl = 0;
            break;
          }
        }
        if (fl == 1) {
          printf("%s", name[j]);
          sum1 += cost[j];
          sum2 += 0.01f * dis[j] * cost[j];
          printf(" %.0f", cost[j]);
          printf(" %d", num[k]);
          printf(" %.0f\n", cost[j] * num[k]);
        }
        else {
          sum1 += cost[j];
          sum2 += 0.01f * dis[j] * cost[j];
        }
        break;
      }
    }
  }
  printf("Total amount = %.2f\n", sum1);
  printf("Total discount = %.2f\n", sum2);
  printf("Amount to be paid = %.2f\n", sum1 - sum2);
}
void Case4() {
  printf("Thank you for your purchase!");
}
void def() {
  printf("Fatal -- Unavailable command\n");
}
void numbers(char scan[][P], int num[], int h) {
  int i, j, u;
  for (i = 0; i < h; i++) {
    u = 0;
    for (j = 0; j < h; j++) {
      if (strcmp(scan[i], scan[j]) == 0) {
        u++;
      }
    }
    num[i] = u;
  }
}
void pri(char code[][P], char name[][D], float cost[], float dis[]) {
  int i, j, k, f;
  for (i = 0; i < D; i++) {
    printf("%s", code[i]);
    printf(" ");
    printf("%s", name[i]);
    printf(" %.0f", cost[i]);
    printf(" %.0f%%\n", dis[i]);
  }
  printf("\n");
  printf("Choose an order:\n");
  printf("1 - Scan the product\n");
  printf("2 - Display the scanned product\n");
  printf("3 - Generate a receipt and amount to be paid\n");
  printf("4 - Complete the purchase\n\n");
}
int main() {
  char name[D][D] = { "apples","peachs","oranges","melons","grape","bread","butter","pears","kiwi","lemons" };
  char code[D][P] = { "1607","0505","1498","2332","6752","1351","0064","2353","9437","1027" }, scan[S][P], prom[P];
  float cost[D] = { 150.0f,220.0f,200.0f,310.0f,230.0f,60.0f,370.0f,180.0f,290.0f,130.0f };
  float dis[D] = { 6.0f,3.0f,3.0f,4.0f,5.0f,7.0f,10.0f,9.0f,9.0f,8.0f };
  int ord, fl = 1, h = 0, num[S];
  float sum2 = 0.0f, sum1 = 0.0f;
  pri(code, name, cost, dis);
  while (fl != 0) {
    ord = order();
    switch (ord) {
    case 1:
      Case1(prom);
      break;
    case 2:
      Case2(code, name, cost, dis, scan, h++, prom);
      break;
    case 3:
      numbers(scan, num, h);
      Case3(scan, code, name, cost, dis, sum1, sum2, num, h);
      break;
    case 4:
      Case4();
      return 0;
    default:
      def();
    }
  }
  return 0;
}