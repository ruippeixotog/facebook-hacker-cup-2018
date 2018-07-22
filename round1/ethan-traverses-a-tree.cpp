#include <cstdio>
#include <cstring>
#include <vector>

#define MAXN 2000

using namespace std;

vector<int> adjs[MAXN];

vector<int> pre, post;
int revPre[MAXN], label[MAXN];
bool visited[MAXN];

void dfs(int k) {
  if(visited[k]) return;
  visited[k] = true;

  pre.push_back(k);
  revPre[k] = (int) pre.size() - 1;
  for(int adj : adjs[k]) {
    dfs(adj);
  }
  post.push_back(k);
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, k; scanf("%d %d\n", &n, &k);
    for(int i = 0; i < n; i++) {
      adjs[i].clear();
    }
    for(int i = 0; i < n; i++) {
      int a, b; scanf("%d %d\n", &a, &b);
      if(a) adjs[i].push_back(a - 1);
      if(b) adjs[i].push_back(b - 1);
    }

    pre.clear();
    post.clear();
    memset(visited, false, sizeof(visited));
    dfs(0);

    memset(label, 0, sizeof(label));
    int labelCnt = 0;
    for(int i = 0; i < n; i++) {
      if(label[pre[i]]) continue;
      int newLabel = ++labelCnt;
      int idx = i;
      while(label[post[idx]] != newLabel) {
        label[pre[idx]] = label[post[idx]] = newLabel;
        idx = revPre[post[idx]];
      }
    }

    printf("Case #%d:", tc);
    if(labelCnt < k) printf(" Impossible\n");
    else {
      for(int i = 0; i < n; i++) {
        printf(" %d", min(label[i], k));
      }
      printf("\n");
    }
  }
  return 0;
}
