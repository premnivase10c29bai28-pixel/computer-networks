#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    int code[100] = {0};
    int n, r = 0, m, i, j, p, p_pos, sum, d_idx = 0;

    printf("Enter data bits: ");
    scanf("%s", data);

    m = strlen(data);

    while ((1 << r) < (m + r + 1)) {
        r++;
    }

    n = m + r;

    for (i = n; i >= 1; i--) {
        if ((i & (i - 1)) != 0) {
            code[i] = data[d_idx] - '0';
            d_idx++;
        }
    }

    for (p = 0; p < r; p++) {
        p_pos = 1 << p;
        sum = 0;
        for (j = 1; j <= n; j++) {
            if (j != p_pos && (j & p_pos)) {
                sum ^= code[j];
            }
        }
        code[p_pos] = sum;
    }

    printf("\n--- SENDER ONLY PROGRAM ---\n");
    printf("Number of data bits (m): %d\n", m);
    printf("Redundant bits (r): %d\n", r);
    printf("Length of codeword (n): %d\n", n);

    printf("\nCalculated Parity Bits:\n");
    for (p = 0; p < r; p++) {
        printf("P%d = %d\n", (1 << p), code[1 << p]);
    }

    printf("\nGenerated Codeword:\n");
    for (i = n; i >= 1; i--) {
        printf("%d", code[i]);
    }
    printf("\n");

    return 0;
}
[24bad113@mepcolinux ex12]$./a.out
Enter data bits: 1001

--- SENDER ONLY PROGRAM ---
Number of data bits (m): 4
Redundant bits (r): 3
Length of codeword (n): 7

Calculated Parity Bits:
P1 = 0
P2 = 0
P4 = 1

Generated Codeword:
1001100