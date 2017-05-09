#include "defs.h"

int main(int argc, char *argv[]) {

    //check command line parameter
    if (argc == 1) {
        fprintf(stderr, "Usage:./charcnt [OPTION] [FILE_NAME].\n");
        exit(EXIT_FAILURE);
    }

    opterr = 0; //getopt()のエラーメッセージを無効にする

    int opt;

    while ((opt = getopt(argc, argv, "adh:")) != -1) {
        switch (opt) {
            case 'a':
                count(opt, argv[2]);
                break;

            case 'd':
                count(opt, argv[2]);
                break;

            case 'h':
                exit(1);

            default: /* '?' */
                //指定していないオプションが渡された場合
                printf("Usage: %s [-f] [-g] [-h argment] arg1 ...\n", argv[0]);
                break;
        }
    }

    // puts("HELLO");
    //オプション以外の引数を出力する
    int i;
    for (i = optind; i < argc; i++) {
        printf("arg = %s\n", argv[i]);
    }

    return 0;
}
