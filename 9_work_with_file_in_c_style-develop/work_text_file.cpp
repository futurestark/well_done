#include <cstdio>
#include <unistd.h>

struct People {
  const char* str;
  unsigned age;
};

bool isFileExists(const char *file_name) {
  return access(file_name, F_OK) == 0;
}

void printFile(FILE* pFile) {
  if (pFile != nullptr) {
    fseek(pFile, 0, SEEK_SET);    
    char buff[100];
    while(fgets(buff, 100, pFile)) {
      printf("%s", buff);
    }
  }
}

int main(int argc, char const *argv[]) {
  const char* mode = "w+";
  constexpr const char* file_name = "people_config.txt";
  bool is_file_exist;
  if ((is_file_exist = isFileExists(file_name))) {
    mode = "r+a";
  }

  FILE *pFile = fopen(file_name, mode);
  if (pFile != nullptr) {
    People people{"Ivanov Ivan", 25};
    if (is_file_exist) {
      fseek(pFile, 0, SEEK_END);
    }
    fprintf(pFile, "%s\n%u\n", people.str, people.age);
    printFile(pFile);
    fclose(pFile);
  } else {
    fprintf(stderr, "Can't open file\n");
  }

  return 0;
}
