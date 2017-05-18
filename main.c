#include "defs.h"

int main(int argc, char *argv[]) {

//  Check command line parameter
    if (!(argc == 2 || argc == 3)) {
        fprintf(stderr, "Usage:./charcnt [OPTION] [FILE_NAME].\n");
        exit(EXIT_FAILURE);
    }

    opterr = 0;

    int opt;
    int optf = 0;
    int debug = 0;

//  Get option and count
    while ((opt = getopt(argc, argv, "adhg")) != -1) {
        optf = 1;
        switch (opt) {
            case 'a':
                count(debug, 'a', argv[2]);
                break;

            case 'd':
                count(debug, 'd', argv[2]);
                break;

            case 'h':
                printf("Usage: %s [-a] [-d] [-h] [FILE_NAME]\n", argv[0]);
                printf("There are some option in this program.\n");
                printf("If you do not specify an option, display results in ASCII code order.\n");
                printf("-g\tDisplay all characters. (Use with other OPTION.)This is debug option.\n");
                printf("-a\tDisplay results in ascending order.\n");
                printf("-d\tDisplay results in descending order.\n");
                printf("-h\tDisplay this help.\n");
                break;

            case 'g':
                debug = 1;
                break;

            default:
                fprintf(stderr, "Usage: %s [-a] [-d] [-h] [FILE_NAME]\n", argv[0]);
                break;
        }
    }

//  No option (ASCII code order)
    if (optf == 0) {
        count(debug, 'm', argv[1]);
    }

    return 0;
}
