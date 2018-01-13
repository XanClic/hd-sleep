#define _FORTIFY_SOURCE 2

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void usage(const char *progname)
{
    fprintf(stderr, "Usage: %s <character>\n", progname);
    fprintf(stderr, "\n");
    fprintf(stderr, "The character is appended to the string /dev/sd to determine the\n");
    fprintf(stderr, "block device to put to sleep (using hdparm -Y).\n");
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        usage(argv[0]);
        return 1;
    }

    if (strlen(argv[1]) != 1) {
        usage(argv[0]);
        return 1;
    }

    char hdd[sizeof("/dev/sd") + 1] = "/dev/sd";
    hdd[sizeof("/dev/sd") - 1] = argv[1][0];

    execlp("hdparm", "hdparm", "-Y", hdd, NULL);

    perror("Failed to execute hdparm");
    return 1;
}
