#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define MAXN 2000
#define INF 0x3f3f3f3f

using namespace std;

typedef long long ll;
typedef long double ld;

int x[MAXN], y[MAXN];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, k; scanf("%d %d\n", &n, &k);

    int cycleLen = min(n, k);

    if(cycleLen <= 2) {
      printf("Case #%d: 0\n", tc);
      printf("1\n");
      printf("1 %d 1\n", n);
    } else {
      int path = 0;
      for(int i = 1; i < cycleLen; i++) {
        path += k - i;
      }
      path -= k;

      printf("Case #%d: %d\n", tc, path);
      printf("%d\n", cycleLen);
      printf("1 %d %d\n", n, k);
      for(int i = 1; i < cycleLen; i++) {

        printf("%d %d %d\n", i, i == cycleLen - 1 ? n : i + 1, k - i);
      }
    }
  }
  return 0;
}
