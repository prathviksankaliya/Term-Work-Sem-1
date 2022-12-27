#include <stdio.h>

int maxOrbitSize(int m, int n) {
  int count = 0;
  int visited[n];
  for (int i = 0; i < n; i++)
  {
    visited[i]= 0;
  }
  

  int x = m;
  while (visited[x] == 0) {
    visited[x] = 1;
    count++;
    x = (2 * x) % n;
  }

  return count;
}

int main() {
  int m, n;
  scanf("%d%d", &m, &n);
  printf("%d\n", maxOrbitSize(m, n));
  return 0;
}