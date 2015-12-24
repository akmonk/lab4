#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "errno.h"

#define MAX_ENV_SIZE 4096

int envx (char * pid)
{
  int i,len;
  char *path_buf = malloc(MAX_ENV_SIZE);
  char *buf, *s;
  ssize_t buf_len;
  buf_len = 14 + strlen(pid) + 1;
  buf = malloc(buf_len);
  sprintf(buf,"/proc/%s/environ",pid);
  FILE *f;
  f = fopen(buf,"r");
  if (f == NULL)
  {
    s = strerror(errno == ENOENT ? ESRCH : errno);
    fprintf(stderr, "%s: %s\n", pid, s);
    free(path_buf);
    return 1;
  }
  while ((len = fread(path_buf, 1, MAX_ENV_SIZE-1, f)) > 0)
  {
    for (i = 0; i < len; i++)
      if (path_buf[i] == 0) path_buf[i] = 10;
    path_buf[len] = 0;
    printf("%s", path_buf);
  }
  return 0;
}
