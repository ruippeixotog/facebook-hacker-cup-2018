#include <algorithm>
#include <cstdio>

using namespace std;

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
      int diff = (cycleLen - 1) * (k - 1 + k - cycleLen + 1) / 2 - k;
      printf("Case #%d: %d\n", tc, diff);
      printf("%d\n", cycleLen);
      printf("1 %d %d\n", n, k);
      for(int i = 1; i < cycleLen; i++) {
        printf("%d %d %d\n", i, i == cycleLen - 1 ? n : i + 1, k - i);
      }
    }
  }
  return 0;
}
