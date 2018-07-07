#include <cstdio>
#include <iostream>
#include <string>

#define MAXA 2000

using namespace std;

int pi[MAXA];

void kmpPp(string& pattern) {
  pi[0] = 0;
  for(int i = 1; i < pattern.size(); i++) {
    pi[i] = pi[i - 1];
    while(pi[i] > 0 && pattern[i] != pattern[pi[i]])
      pi[i] = pi[pi[i] - 1];
    if(pattern[i] == pattern[pi[i]]) {
      pi[i]++;
    }
    while(pi[i - 1] > 0 && pattern[i] == pattern[pi[i - 1]]) {
      pi[i - 1] = pi[pi[i - 1] - 1];
    }
  }
}

int main() {
  int t; scanf("%d\n", &t);
  for(int tc = 1; tc <= t; tc++) {
    string a; cin >> a;
    kmpPp(a);

    int idx = 0;
    while(idx < a.length() - 1 && pi[idx] == 0) idx++;

    if(idx == a.length() - 1) {
      printf("Case #%d: Impossible\n", tc);
    } else {
      printf("Case #%d: ", tc);
      cout << a.substr(0, idx + 1) << a.substr(pi[idx]) << endl;
    }
  }
  return 0;
}
