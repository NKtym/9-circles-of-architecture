#include <myTerm.h>

int
mt_delline (void)
{
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = write (fd, "\E[M", 3);
  close (fd);
  return (result == 3) ? 0 : -1;
}