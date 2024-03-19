#include <myTerm.h>

int
mt_gotoXY (int x, int y)
{
  char buf[100];
  int len = sprintf (buf, "\E[%d;%dH", x, y);
  int tty = open ("/dev/tty", O_RDWR);
  if (tty == -1)
    {
      perror ("Error opening /dev/tty");
      return -1;
    }
  int bytes_written = write (tty, buf, len);
  if (bytes_written == -1)
    {
      perror ("Error writing to terminal");
      close (tty);
      return -1;
    }
  close (tty);
  fflush (stdout);
  return 0;
}