#include <cstdio>
#include <unistd.h>
#include <cstdlib>

struct People {
  unsigned age;
  const char fio[100];
};

bool isFileExists(const char* file_name) {
  return access(file_name, F_OK) == 0;
}

void ReadFromFile(const char* file_name) {
  if (file_name!= nullptr &&
      *file_name          &&
      isFileExists(file_name)) {
    auto pfile = fopen("binary_file.people", "rb");
    if (pfile != nullptr) {
      People people{};
      fread(&people, sizeof(People), 1, pfile);
      printf("people %s %d\n", people.fio, people.age);
      fclose(pfile);
    } else {
      printf("File can't open");
    }
  } else {
    printf("File not exists");
  } 
}

void WriteToFile(const char* file_name) {
  if (file_name!= nullptr &&
      *file_name) {
    auto pfile = fopen("binary_file.people", "wb");
    if (pfile != nullptr) { 
      People people{25, "Ivanov Ivan"};

      fwrite(&people, sizeof(People), 1, pfile);
      fclose(pfile);
    }
  } 
}

int main(int argc, char const *argv[]) {
  constexpr const char* file = "binary_file.people";
  ReadFromFile(file);
  WriteToFile(file);
  return 0;
}
