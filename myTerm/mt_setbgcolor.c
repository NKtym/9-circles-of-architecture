#include <myTerm.h>

int
mt_setbgcolor (enum colors color)
{
  char buf[20];
  int len = sprintf (buf, "\E[48:5;%dm", color);
  int tty = open("/dev/tty", O_RDWR);
  if (tty == -1) { 
        perror("Error opening /dev/tty"); 
        return -1; 
  } 
  int bytes_written = write(tty, buf, len); // запись последовательности в терминал 
  if (bytes_written == len) { 
        perror("Error writing to terminal"); 
        close(tty); 
        return -1; 
  } 
  close (tty);
  return 0;
}