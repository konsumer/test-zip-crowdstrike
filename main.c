#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "zip.h"

int main(int argc, char *argv[]) {
  struct zip_t* zip = zip_open("test.zip", 0, 'r');

  void *buf = NULL;
  size_t bufsize = 0;

  zip_entry_open(zip, "main.c");
  zip_entry_read(zip, &buf, &bufsize);
  zip_entry_close(zip);

  printf("%s\n", (char*)buf);

  free(buf);
  zip_close(zip);
  return 0;
}