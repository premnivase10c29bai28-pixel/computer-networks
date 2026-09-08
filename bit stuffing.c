#include <stdio.h>
#include <string.h>
int main()
{
    char data[100], flag[20];
    char stuffed[200], frame[250], destuffed[200];
    int i, j = 0, k = 0;
    int count = 0;
    printf("Enter Data: ");
    scanf("%s", data);
    printf("Enter FLAG: ");
    scanf("%s", flag);
    /* BIT STUFFING */
    for (i = 0; data[i] != '\0'; i++)
    {
        stuffed[j++] = data[i];

        if (data[i] == '1')
        {
            count++;

            /* Insert 0 after five consecutive 1s */
            if (count == 5)
            {
                stuffed[j++] = '0';
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    stuffed[j] = '\0';
    /* ADD FLAG AT FRONT AND BACK */
    strcpy(frame, flag);
    strcat(frame, stuffed);
    strcat(frame, flag);
    printf("\nOriginal Data : %s", data);
    printf("\nFLAG          : %s", flag);
    printf("\nStuffed Data  : %s", stuffed);
    printf("\nFinal Frame   : %s", frame);
    /* BIT DESTUFFING */
    count = 0;
    k = 0;
    /*
       Remove the starting and ending FLAG.
       Destuff only the data between the flags.
    */
    for (i = strlen(flag); i < strlen(frame) - strlen(flag); i++)
    {
        destuffed[k++] = frame[i];

        if (frame[i] == '1')
        {
            count++;
            /* Remove stuffed 0 after five 1s */
            if (count == 5)
            {
                if (frame[i + 1] == '0')
                {
                    i++;
                }

                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }
    destuffed[k] = '\0';
    printf("\nDestuffed Data: %s\n", destuffed);
    return 0;
}