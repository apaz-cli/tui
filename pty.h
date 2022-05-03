#include <fcntl.h>
#include <stdlib.h>

// Returns 1 on error, returns 0 and writes master and slave file descriptors on succes.
static inline int tui_pty_open(int* master_fd, int* slave_fd) {
    int masterfd, slavefd;
    char *slavedevice;

    masterfd = posix_openpt(O_RDWR | O_NOCTTY);

    if ( masterfd == -1 ||
         grantpt (masterfd) == -1 ||
         unlockpt (masterfd) == -1 ||
         (slavedevice = ptsname (masterfd)) == NULL)
        return 1;

    slavefd = open(slavedevice, O_RDWR|O_NOCTTY);
    if (slavefd < 0)
        return 1;

    *master_fd = masterfd;
    *slave_fd = slavefd;
    return 0;
}
