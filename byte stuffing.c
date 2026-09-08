#include <stdio.h>

int main()
{
    char data[100];
    char stuffed[200];
    char destuffed[200];

    char flag, esc;

    int i, j = 0, k = 0;

    printf("Enter Data: ");
    scanf("%s", data);

    printf("Enter Flag Character: ");
    scanf(" %c", &flag);

    printf("Enter Escape Character: ");
    scanf(" %c", &esc);


    /* BYTE STUFFING */

    for (i = 0; data[i] != '\0'; i++)
    {
        /*
         * If current character is FLAG
         * or ESC, insert ESC before it.
         */
        if (data[i] == flag || data[i] == esc)
        {
            stuffed[j++] = esc;
        }

        stuffed[j++] = data[i];
    }

    stuffed[j] = '\0';


    printf("\nOriginal Data  : %s", data);
    printf("\nFlag Character : %c", flag);
    printf("\nEscape Character: %c", esc);
    printf("\nStuffed Data   : %s", stuffed);


    /* BYTE DESTUFFING */

    k = 0;

    for (i = 0; stuffed[i] != '\0'; i++)
    {
        /*
         * If ESC is found, ignore it
         * and take the next character as data.
         */
        if (stuffed[i] == esc)
        {
            i++;
        }

        destuffed[k++] = stuffed[i];
    }

    destuffed[k] = '\0';

    printf("\nDestuffed Data : %s\n", destuffed);

    return 0;
}