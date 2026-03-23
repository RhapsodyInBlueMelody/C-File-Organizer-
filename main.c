#include "dirent.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include <sys/stat.h>
#include <sys/types.h>

#define SIZE 1024

DIR *dir;
struct dirent *entry;

// string checker for extension of the files
bool check_extension(const char *name, const char *ext) {
  size_t nl = strlen(name), el = strlen(ext);
  return nl >= el && !strcmp(name + nl - el, ext);
}

void make_directory(char *ext[], size_t arr_length) {
  for (int i = 0; i < arr_length; i++) {
    mkdir(ext[i] + 1, 0755);
  }
}

void move_files(DIR *dir, char *ext[], size_t arr_length, char *new_path) {
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;
    for (int i = 0; i < arr_length; i++) {
      if (check_extension(entry->d_name, ext[i])) {
        printf("Moving: %s → %s/%s\n", entry->d_name, ext[i] + 1,
               entry->d_name);
        snprintf(new_path, SIZE, "%s/%s", ext[i] + 1, entry->d_name);
        rename(entry->d_name, new_path);
        break;
      }
    }
  }
}

int main() {
  dir = opendir("./");

  if (dir == NULL) {
    printf("File can't be open\n");
    return 0;
  }

  // read whole directory file names each and detect if the extension exist, and
  // move individual name accordingly.
  char *ext[] = {".exe", ".pdf", ".mp3", ".jpg", ".run",
                 ".iso", ".mp4", ".deb", ".rpm"};
  size_t length = 0;
  char new_path[SIZE];
  length = sizeof(ext) / sizeof(ext[0]);

  make_directory(ext, length);

  move_files(dir, ext, length, new_path);

  closedir(dir);

  return 0;
}
