#include <stdio.h>
#include <string.h>

void mirror(char str[], int index) {
    if(index < 0)
        return;

    printf("%c", str[index]);
    mirror(str, index - 1);
}

int main() {
    char str[100];

    printf("Enter code name: ");
    scanf("%s", str);

    int len = strlen(str);

    printf("Mirrored code name: ");
    mirror(str, len - 1);

    return 0;
}
