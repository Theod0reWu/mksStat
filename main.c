#include "stat.h"

int main(int argc, char const *argv[]) {
  struct stat info;
  stat("README.md", &info);
  printf("%i\n", info.st_size);
  printf("%i\n", info.st_mode);
  printf("%s\n", ctime(info.st_atime));
  return 0;
}