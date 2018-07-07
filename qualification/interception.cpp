#include <cstdio>

#define MAXN 50

typedef long long ll;

int p[MAXN + 1];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i <= n; i++)
      scanf("%d\n", &p[i]);

    if(n % 2 == 0) {
      printf("Case #%d: 0\n", tc);
    } else {
      printf("Case #%d: 1\n", tc);
      printf("0.0\n");
    }
  }
  return 0;
}
