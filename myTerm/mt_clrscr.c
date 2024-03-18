#include <myTerm.h>

int
mt_clrscr (void)
{
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = write (fd, "\E[H\E[J", 7);
  close (fd);
  return (result == 7) ? 0 : -1;
}