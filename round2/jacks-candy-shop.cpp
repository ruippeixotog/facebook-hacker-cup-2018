#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

#define MAXN 200000
#define MAXM 1000000

using namespace std;

typedef long long ll;

int c[MAXM];
vector<int> children[MAXN];

int height[MAXN];
priority_queue<int>* bestCandies[MAXN];

void calcHeight(int k, int currHeight = 0) {
  height[k] = currHeight;
  for(int child : children[k]) {
    calcHeight(child, currHeight + 1);
  }
}

void calcBestCandies(int k) {
  if(bestCandies[k]) return;

  if(children[k].empty()) {
    bestCandies[k] = new priority_queue<int>();
    bestCandies[k]->push(k);
    return;
  }

  for(int child : children[k]) {
    calcBestCandies(child);
  }

  sort(children[k].begin(), children[k].end(), [](int c1, int c2) {
    return bestCandies[c1]->size() > bestCandies[c2]->size();
  });

  bestCandies[k] = bestCandies[children[k][0]];
  bestCandies[children[k][0]] = nullptr;
  bestCandies[k]->push(k);

  for(int i = 1; i < children[k].size(); i++) {
    int child = children[k][i];
    while(!bestCandies[child]->empty()) {
      bestCandies[k]->push(bestCandies[child]->top());
      bestCandies[child]->pop();
    }
    delete bestCandies[child];
    bestCandies[child] = nullptr;
  }
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    int n, m, a, b; scanf("%d %d %d %d\n", &n, &m, &a, &b);
    for(int i = 0; i < n; i++) {
      children[i].clear();
    }
    for(int i = 1; i < n; i++) {
      int pi; scanf("%d\n", &pi);
      children[pi].push_back(i);
    }
    for(int i = 0; i < m; i++) {
      c[i] = (int) ((a * (ll) i + b) % n);
    }

    calcHeight(0);
    sort(c, c + m, [](int c1, int c2) {
      return height[c1] > height[c2];
    });

    for(int i = 0; i < n; i++) {
      if(bestCandies[i]) {
        delete bestCandies[i];
        bestCandies[i] = nullptr;
      }
    }

    ll sum = 0;
    for(int i = 0; i < m; i++) {
      calcBestCandies(c[i]);
      if(!bestCandies[c[i]]->empty()) {
        sum += bestCandies[c[i]]->top();
        bestCandies[c[i]]->pop();
      }
    }
    printf("Case #%d: %lld\n", tc, sum);
  }
  return 0;
}
