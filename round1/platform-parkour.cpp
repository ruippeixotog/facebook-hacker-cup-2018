#include <algorithm>
#include <cstdio>

#define MAXN 200000
#define MAXM 20
#define MAXUD 1000000

using namespace std;

typedef long long ll;

int h[MAXN], a[MAXM], b[MAXM], u[MAXM], d[MAXM];

int jumpU[MAXN - 1], jumpD[MAXN - 1];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, m, w, x, y, z;
    scanf("%d %d\n", &n, &m);
    scanf("%d %d %d %d %d %d\n", &h[0], &h[1], &w, &x, &y, &z);
    for(int i = 0; i < m; i++) {
      scanf("%d %d %d %d\n", &a[i], &b[i], &u[i], &d[i]);
      a[i]--; b[i]--;
    }
    for(int i = 2; i < n; i++) {
      h[i] = (int) ((w * (ll) h[i - 2] + x * (ll) h[i - 1] + y) % z);
    }

    for(int i = 1; i < n; i++) {
      jumpU[i - 1] = jumpD[i - 1] = MAXUD;

      for(int j = 0; j < m; j++) {
        if(a[j] < b[j] && a[j] <= i - 1 && b[j] >= i) {
          jumpU[i - 1] = min(jumpU[i - 1], u[j]);
          jumpD[i - 1] = min(jumpD[i - 1], d[j]);
        }
        else if(a[j] > b[j] && a[j] >= i && b[j] <= i - 1) {
          jumpU[i - 1] = min(jumpU[i - 1], d[j]);
          jumpD[i - 1] = min(jumpD[i - 1], u[j]);
        }
      }
    }

    int lowT = 0, hiT = MAXUD * 2;
    while(lowT < hiT) {
      int t = (hiT + lowT) / 2;

      int downBound = max(0, h[0] * 2 - t);
      int upBound = min(MAXUD * 2, h[0] * 2 + t);
      bool found = true;
      for(int i = 1; i < n; i++) {
        downBound = max(0, max(downBound - jumpD[i - 1] * 2, h[i] * 2 - t));
        upBound = min(MAXUD * 2, min(upBound + jumpU[i - 1] * 2, h[i] * 2 + t));
        if(downBound > upBound) { found = false; break; }
      }
      if(!found) lowT = t + 1;
      else hiT = t;
    }
    printf("Case #%d: %.6f\n", tc, lowT / 2.0);
  }
  return 0;
}
