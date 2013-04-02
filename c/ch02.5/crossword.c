#include <stdio.h>
#include <string.h>

void print_reverse(char *s)
{
    size_t len = strlen(s);
    char *t = s + len - 1;
    while ( t >= s) {
        printf("%c", *t);
        t = t - 1;
    }
    puts("");
}

int main() {
    char *juices[] = {
        "dragonfruit", "waterberry", "sharonfruit", "uglifruit",
        "rumberry", "kiwifruit", "mulberry", "strawberry",
        "blueberry", "blackberry", "starfruit"
    };

    char *a;
    printf("1 Across: %s\n", juices[6]);
    printf("2 Across: ");
    print_reverse(juices[7]);
    a = juices[2];
    juices[2] = juices[8];
    juices[8] = a;
    printf("3 Across: %s\n", juices[8]);
    printf("4 Across: ");
    print_reverse(juices[(18 + 7) / 5]);

    printf("\n");


    printf("5 Down: %s\n", juices[2]);
    printf("6 Down: ");
    print_reverse(juices[9]);
    juices[1] = juices[3];
    printf("7 Down: %s\n", juices[10]);
    printf("8 Down: ");
    print_reverse(juices[1]);

    return 0;
}
