#include <cstdio>
#include <cstring>

#define MAXN 1000
#define MOD 1000000007

char g[3][MAXN];
int dp[3][MAXN + 1];

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n; scanf("%d\n", &n);
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < n; j++) {
        scanf("%c", &g[i][j]);
      }
      scanf("\n");
    }

    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    for(int j = 1; j <= n; j++) {
      if(g[0][j - 1] == '.' && g[1][j - 1] == '.') {
        dp[1][j] = (dp[1][j] + dp[0][j - 1]) % MOD;
        dp[0][j] = (dp[0][j] + dp[1][j - 1]) % MOD;
      }
      if(g[1][j - 1] == '.' && g[2][j - 1] == '.') {
        dp[1][j] = (dp[1][j] + dp[2][j - 1]) % MOD;
        dp[2][j] = (dp[2][j] + dp[1][j - 1]) % MOD;
      }
    }
    printf("Case #%d: %d\n", tc, dp[2][n]);
  }
  return 0;
}
