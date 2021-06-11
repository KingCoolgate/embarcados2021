#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int fd;

    // export GPIO
    fd = open("/sys/class/gpio/export", O_WRONLY);
    write(fd, "50", 2);
    close(fd);

    // Configure as output
    fd = open("/sys/class/gpio/gpio50/direction", O_WRONLY);
    write(fd, "out", 3);
    close(fd);

    // Blink GPIO once
    fd = open("/sys/class/gpio/gpio50/value", O_WRONLY | O_SYNC);
    write(fd, "0", 1);
    usleep(1000000);
    write(fd, "1", 1);
    close(fd);

    return EXIT_SUCCESS;
}
