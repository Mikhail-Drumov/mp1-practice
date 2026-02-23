#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main() {
  int mod;
  printf("The game 'Guess the number'!\n");
  printf("Choose a mode ");
  srand(time(0));
  do {
    scanf_s("%d", &mod);
  } while (mod > 2 || mod < 1);
  if (mod == 1) {
    int cnt1 = 1;
    int n;
    int ans;
    n = rand() % 1000 + 1;
    scanf_s("%d", &ans);
    while (ans) {
      if (ans > n) {
        printf("mistery is less\n");
        scanf_s("%d", &ans);
        cnt1++;
      }
      if (ans < n) {
        printf("mistery is bigger\n");
        scanf_s("%d", &ans);
        cnt1++;
      }
      if (ans == n) {
        printf("Number of attempts = %d ", cnt1);
        printf("Mystery number = %d", ans);
        break;
      }
    }
    return 0;
  }
  if (mod == 2) {
    int mis;
    int cnt2 = 1;
    char p;
    do {
      printf("Choose a number ");
      scanf_s("%d", &mis);
      p = getchar();
    } while (mis<1 || mis>1000);
    int at;
    at = rand() % 1000 + 1;
    int mn = 1;
    int mx = 1000;
    while (mis) {
      printf("%d\n", at);
      char flag;
      scanf_s("%c", &flag);
      p = getchar();
      switch (flag) {
      case '>':
        if (at >= mn) {
          mn = at;
          at = rand()%(mx-mn+1)+mn;
          cnt2++;
        }
        break;
      case '<':
        if (at <= mx) {
          mx = at;
          at = rand()%(mx-mn+1)+mn;
          cnt2++;
        }
        break;
      case '=':
        printf("Number of attempts = %d ", cnt2);
        printf("Mystery number = %d", at);
        return 0;
      default:
        printf("Invalid character\n");
      }
    }
  }
  return 0;
}