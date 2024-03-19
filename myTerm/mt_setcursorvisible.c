#include <myTerm.h>

int
mt_setcursorvisible (int value)
{
  if (value != 0)
    {
      return -1;
    }
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = 0;
  if (value)
    result = write (fd, "\E[?25l", 6);
  else
    result = write (fd, "\E[?25h", 6);
  if (result != 6)
    {
      close (fd);
      return -1;
    }
  close (fd);
  return 0;
}