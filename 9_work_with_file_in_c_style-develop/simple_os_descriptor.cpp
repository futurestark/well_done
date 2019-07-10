#include <cstdio>

constexpr unsigned SIZE_BUF = 100;
int main(int argc, char const *argv[]) {
  fprintf(stdout, "Output into stdout\n"); // это равносильно printf
  fprintf(stderr, "Output into stderr\n");
  char buff[100];
  fgets(buff, SIZE_BUF, stdin);
  fprintf(stdout, "You are enter: %d %s\n", stdin, buff);
  return 0;
}
