#include "dirent.h"
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include <sys/stat.h>
#include <sys/types.h>

#define SIZE 1024
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define PINK "\033[95m"
#define CYAN "\033[96m"
#define YELLOW "\033[93m"
#define GREEN "\033[92m"
#define RED "\033[91m"
#define DIM "\033[2m"

void make_directory(char *folder_name) {
  struct stat st;

  if (stat(folder_name, &st) == -1) {
    mkdir(folder_name, 0755);
  } else {
    printf(YELLOW "  (=^.^=) " RESET "folder already exists: " BOLD "%s" RESET
                  " — no worries~\n",
           folder_name);
  }
}

void move_files(DIR *dir, char *new_path) {
  struct dirent *entry;
  int count = 0;

  printf(PINK BOLD "\n  /\\_/\\\n" RESET);
  printf(PINK BOLD " ( o.o )  purrring through your files...\n" RESET);
  printf(PINK BOLD "  > ^ <\n\n" RESET);

  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;
    char *extExtract = strrchr(entry->d_name, '.');
    if (extExtract != NULL) {
      make_directory(extExtract + 1);
      snprintf(new_path, SIZE, "%s/%s", extExtract + 1, entry->d_name);
      if (rename(entry->d_name, new_path) == -1) {
        printf(RED "  (x_x) " RESET "oopsie! couldn't move " BOLD "%s" RESET
                   " — %s\n",
               entry->d_name, "rename failed");
      } else {
        count++;
        printf(CYAN "  ~(=^‥^) " RESET GREEN "%s" RESET DIM
                    " ──nyoom──► " RESET BOLD "%s/%s\n" RESET,
               entry->d_name, extExtract + 1, entry->d_name);
      }
    }
  }

  printf(DIM "\n  ────────────────────────────────\n" RESET);
  if (count == 0) {
    printf(YELLOW "  (=-.-)zzZ  nothing to move, taking a nap...\n\n" RESET);
  } else {
    printf(GREEN BOLD "  (=^▿^=) done! " RESET "moved " BOLD "%d" RESET
                      " file%s~ nya!\n\n",
           count, count == 1 ? "" : "s");
  }
}

int main() {
  DIR *dir;

  printf(PINK "\n  ૮ ˶ᵔ ᵕ ᵔ˶ ა  kitty file sorter, starting up~\n\n" RESET);

  dir = opendir("./");

  if (dir == NULL) {
    printf(RED "  (T_T) " RESET
               "couldn't open the directory... *sad meow*\n\n");
    return 0;
  }

  char new_path[SIZE];

  move_files(dir, new_path);

  closedir(dir);

  return 0;
}
