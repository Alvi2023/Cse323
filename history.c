#include "types.h"
#include "user.h"
#include "fcntl.h"

int
main(void)
{
  int fd;
  char c;
  int found = 0;

  fd = open(".history", O_RDONLY);
  if(fd < 0){
    printf(1, "No recent command\n");
    exit();
  }

  while(read(fd, &c, 1) == 1){
    found = 1;
    write(1, &c, 1);
  }

  close(fd);

  if(!found)
    printf(1, "No recent command\n");

  exit();
}
