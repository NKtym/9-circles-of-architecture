#include <myTerm.h>

int
mt_setcursorvisible (int value)
{
  int fd = open ("/dev/tty", O_RDWR);
  size_t result = 0;
  if (value)
    result = write (fd, "\E[?25h", 7);
  else
    result = write (fd, "\E[?25l", 7);
  if (value == 0 && result != 9 || value != 0 && result != 6){
    close (fd);
    return -1;
  }
  close (fd);
  return 0;
}