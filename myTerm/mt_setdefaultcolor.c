#include <myTerm.h>

int
mt_setdefaultcolor (void)
{
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = write (fd, "\E[49;m\E[39;m", 3);
  close (fd);
  return (result == 4) ? 0 : -1;
}