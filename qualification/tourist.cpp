#include <algorithm>
#include <cstdio>

#define MAXN 50

using namespace std;

typedef long long ll;

char a[MAXN][21];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, k; ll v; scanf("%d %d %lld\n", &n, &k, &v);
    for(int i = 0; i < n; i++) {
      scanf("%s\n", a[i]);
    }
    v = (v - 1) % (n * k);
    int curr = 0;
    while(v--) {
      curr = (curr + k) % n;
    }
    printf("Case #%d:", tc);
    for(int i = 0; i < k - (n - curr); i++) {
      printf(" %s", a[i]);
    }
    for(int i = curr; i < min(n, curr + k); i++) {
      printf(" %s", a[i]);
    }
    printf("\n");
  }
  return 0;
}
