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
#define ORANGE "\033[38;5;214m"

void make_directory(char *destination_dir, char *folder_name) {
  struct stat st;
  char new_folder_path[SIZE];
  snprintf(new_folder_path, SIZE, "%s/%s", destination_dir, folder_name);

  if (stat(new_folder_path, &st) == -1) {
    if (mkdir(new_folder_path, 0755) == -1) {
      printf(RED "  (x_x) " RESET);
      perror("mkdir failed");
    } else {
      printf(CYAN "  (=^o^=) " RESET "created folder: " BOLD "%s\n" RESET,
             new_folder_path);
    }
  } else {
    printf(YELLOW "  (=^.^=) " RESET "folder already exists: " BOLD "%s" RESET
                  " — no worries~\n",
           new_folder_path);
  }
}

void move_files(DIR *dir, char *source_path, char *destination_dir) {
  struct dirent *entry;
  char old_path[SIZE];
  char new_path[SIZE];
  int count = 0;
  int fail = 0;

  printf(PINK BOLD "\n  /\\_/\\" RESET "\n");
  printf(PINK BOLD " ( o.o )" RESET "  purrring through your files...\n");
  printf(PINK BOLD "  > ^ <" RESET "\n");
  printf(DIM "  from : " RESET BOLD "%s\n" RESET, source_path);
  printf(DIM "  into : " RESET BOLD "%s\n" RESET, destination_dir);
  printf(DIM "  ────────────────────────────────\n\n" RESET);

  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
      continue;
    char *extExtract = strrchr(entry->d_name, '.');
    if (extExtract != NULL) {
      make_directory(destination_dir, extExtract + 1);
      snprintf(old_path, SIZE, "%s/%s", source_path, entry->d_name);
      snprintf(new_path, SIZE, "%s/%s/%s", destination_dir, extExtract + 1,
               entry->d_name);
      if (rename(old_path, new_path) == -1) {
        printf(RED "  (x_x) " RESET);
        perror(entry->d_name);
        fail++;
      } else {
        count++;
        printf(CYAN "  ~(=^‥^) " RESET GREEN "%-30s" RESET DIM
                    " ──nyoom──► " RESET BOLD "%s/%s\n" RESET,
               entry->d_name, extExtract + 1, entry->d_name);
      }
    }
  }

  printf(DIM "\n  ────────────────────────────────\n" RESET);

  if (count == 0 && fail == 0) {
    printf(YELLOW "  (=-.-)zzZ  " RESET "nothing to move, taking a nap...\n\n");
  } else {
    if (count > 0)
      printf(GREEN BOLD "  (=^▿^=) done! " RESET "moved " BOLD "%d" RESET
                        " file%s~ nya!\n",
             count, count == 1 ? "" : "s");
    if (fail > 0)
      printf(RED "  (>_<)   oops! " RESET "failed to move " BOLD "%d" RESET
                 " file%s — check above for details.\n",
             fail, fail == 1 ? "" : "s");
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  DIR *dir;

  if (argc > 1 &&
      (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)) {
    printf(PINK BOLD "\n  /\\_/\\\n" RESET);
    printf(PINK BOLD " ( '^' )  " RESET BOLD "kitty file organizer\n" RESET);
    printf(PINK BOLD "  > ~ <\n\n" RESET);
    printf(DIM "  Usage: " RESET BOLD "%s <source> <destination>\n\n" RESET,
           argv[0]);
    printf(DIM "  Organizes files in <source> into subfolders\n");
    printf("  by extension, placed inside <destination>.\n\n" RESET);
    printf(DIM "  Example:\n");
    printf("    %s ~/Downloads ~/Sorted\n\n" RESET, argv[0]);
    return 0;
  }

  if (argc != 3) {
    printf(YELLOW "\n  (=^-^=) " RESET "usage: " BOLD
                  "%s <source> <destination>\n" RESET,
           argv[0]);
    printf(DIM "          tip: run with --help for more info\n\n" RESET);
    return 1;
  }

  printf(PINK "\n  ૮ ˶ᵔ ᵕ ᵔ˶ ა  " RESET "kitty file sorter, starting up~\n\n");

  char *source_dir = argv[1];
  char *target_dir = argv[2];

  dir = opendir(source_dir);

  if (dir == NULL) {
    printf(RED "  (T_T) " RESET);
    perror(source_dir);
    printf("\n");
    return 0;
  }

  move_files(dir, source_dir, target_dir);

  closedir(dir);

  return 0;
}
