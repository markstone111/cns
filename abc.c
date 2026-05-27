MONOALPhABETIC






#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(FILE *inputFile, FILE *outputFile, char key[]) {
    int ch;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (isupper(ch)) {
            ch = toupper(key[ch - 'A']);
        } else if (islower(ch)) {
            ch = tolower(key[ch - 'a']);
        }
        fputc(ch, outputFile);
    }
}

void decrypt(FILE *inputFile, FILE *outputFile, char key[]) {
    int ch, i;
    while ((ch = fgetc(inputFile)) != EOF) {
        if (isalpha(ch)) {
            char target = toupper(ch);

            for (i = 0; i < 26; i++) {
                if (toupper(key[i]) == target) {
                    ch = isupper(ch) ? ('A' + i) : ('a' + i);
                    break;
                }
            }
        }
        fputc(ch, outputFile);
    }
}

int main() {
    int choice;
    char key[27];
    FILE *fin;
    FILE *fout;

    printf("1. Encrypt plaintext.txt to ciphertext.txt\n");
    printf("2. Decrypt ciphertext.txt to decrypted.txt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter a 26-letter substitution key: ");
    scanf("%s", key);

    if (choice == 1) {
        fin = fopen("plaintext.txt", "r");
        fout = fopen("ciphertext.txt", "w");
        encrypt(fin, fout, key);
        printf("Success! Encrypted text saved to 'ciphertext.txt'.\n");
    } else if (choice == 2) {
        fin = fopen("ciphertext.txt", "r");
        fout = fopen("decrypted.txt", "w");
        decrypt(fin, fout, key);
        printf("Success! Decrypted text saved to 'decrypted.txt'.\n");
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    fclose(fin);
}
    
    
    
    
    
    
    
    
    
CAESAR CIPHER






#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt(FILE *inputFile, FILE *outputFile, int key) {
    int ch;
    key = key % 26;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (isupper(ch)) {
            ch = ((ch - 'A' + key) % 26) + 'A';
        } else if (islower(ch)) {
            ch = ((ch - 'a' + key) % 26) + 'a';
        }
        fputc(ch, outputFile);
    }
}

void decrypt(FILE *inputFile, FILE *outputFile, int key) {
    int ch;
    key = key % 26;

    while ((ch = fgetc(inputFile)) != EOF) {
        if (isupper(ch)) {
            ch = ((ch - 'A' - key + 26) % 26) + 'A';
        } else if (islower(ch)) {
            ch = ((ch - 'a' - key + 26) % 26) + 'a';
        }
        fputc(ch, outputFile);
    }
}

int main() {
    int choice;
    int key;
    FILE *fin;
    FILE *fout;

    key = 0;
    fin = NULL;
    fout = NULL;

    printf("1. Encrypt plaintext.txt to ciphertext.txt\n");
    printf("2. Decrypt ciphertext.txt to decrypted.txt\n");
    printf("Enter your choice (1 or 2): ");
    
    scanf("%d", &choice);

    printf("\nEnter the shift key (integer): ");
    scanf("%d", &key);

    if (choice == 1) {
        fin = fopen("plaintext.txt", "r");
        fout = fopen("ciphertext.txt", "w");

        encrypt(fin, fout, key);
        printf("Success! Encrypted text saved to 'ciphertext.txt'.\n");

    } else if (choice == 2) {
        fin = fopen("ciphertext.txt", "r");
        fout = fopen("decrypted.txt", "w");

        decrypt(fin, fout, key);
        printf("Success! Decrypted text saved to 'decrypted.txt'.\n");

    } else {
        printf("Invalid choice (You entered: %c). Please choose 1 or 2.\n", choice);
        return 1;
    }

    fclose(fin);
    fclose(fout);

    return 0;
}

    fclose(fout);
    return 0;
}












VIGENRE CIPHER




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void encrypt(FILE *inputFile, FILE *outputFile, char key[]) {
    int ch;
    int i = 0;
    int m = strlen(key);

    while ((ch = fgetc(inputFile)) != EOF) {
        if (isupper(ch)) {
            /* C_i = (P_i + K_(i mod m)) mod 26 */
            ch = ((ch - 'A' + (toupper(key[i % m]) - 'A')) % 26) + 'A';
            i++;
        } else if (islower(ch)) {
            ch = ((ch - 'a' + (tolower(key[i % m]) - 'a')) % 26) + 'a';
            i++;
        }
        fputc(ch, outputFile);
    }
}

void decrypt(FILE *inputFile, FILE *outputFile, char key[]) {
    int ch;
    int i = 0;
    int m = strlen(key);

    while ((ch = fgetc(inputFile)) != EOF) {
        if (isupper(ch)) {
            /* P_i = (C_i - K_(i mod m) + 26) mod 26 */
            ch = ((ch - 'A' - (toupper(key[i % m]) - 'A' - 26)) % 26) + 'A';
            i++;
        } else if (islower(ch)) {
            ch = ((ch - 'a' - (tolower(key[i % m]) - 'a' - 26)) % 26) + 'a';
            i++;
        }
        fputc(ch, outputFile);
    }
}

int main() {
    int choice;
    char key[100];
    FILE *fin;
    FILE *fout;

    printf("1. Encrypt plaintext.txt to ciphertext.txt\n");
    printf("2. Decrypt ciphertext.txt to decrypted.txt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the Vigenere keyword: ");
    scanf("%s", key);

    if (choice == 1) {
        fin = fopen("plaintext.txt", "r");
        fout = fopen("ciphertext.txt", "w");
        encrypt(fin, fout, key);
        printf("Success!\n");
    } else if (choice == 2) {
        fin = fopen("ciphertext.txt", "r");
        fout = fopen("decrypted.txt", "w");
        decrypt(fin, fout, key);
        printf("Success!\n");
    }

    fclose(fin);
    fclose(fout);
    return 0;
}










ViGENERE with IOC








#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* ---------------- VIGENERE ENCRYPTION ---------------- */

void encrypt(FILE *inputFile, FILE *outputFile, char key[]) {

    int ch;
    int i = 0;
    int m = strlen(key);

    while ((ch = fgetc(inputFile)) != EOF) {

        if (isupper(ch)) {

            /* Ci = (Pi + Ki) mod 26 */
            ch = ((ch - 'A' + (toupper(key[i % m]) - 'A')) % 26) + 'A';
            i++;

        } else if (islower(ch)) {

            ch = ((ch - 'a' + (tolower(key[i % m]) - 'a')) % 26) + 'a';
            i++;
        }

        fputc(ch, outputFile);
    }
}

/* ---------------- VIGENERE DECRYPTION ---------------- */

void decrypt(FILE *inputFile, FILE *outputFile, char key[]) {

    int ch;
    int i = 0;
    int m = strlen(key);

    while ((ch = fgetc(inputFile)) != EOF) {

        if (isupper(ch)) {

            /* Pi = (Ci - Ki + 26) mod 26 */
            ch = ((ch - 'A' - (toupper(key[i % m]) - 'A') + 26) % 26) + 'A';
            i++;

        } else if (islower(ch)) {

            ch = ((ch - 'a' - (tolower(key[i % m]) - 'a') + 26) % 26) + 'a';
            i++;
        }

        fputc(ch, outputFile);
    }
}

/* ---------------- INDEX OF COINCIDENCE ---------------- */

double calculateIC(char filename[]) {

    FILE *fp;
    int freq[26] = {0};
    int totalLetters = 0;
    int ch, i;
    double sum = 0.0, ic;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        if (isalpha(ch)) {

            ch = toupper(ch);

            freq[ch - 'A']++;
            totalLetters++;
        }
    }

    fclose(fp);

    for (i = 0; i < 26; i++) {
        sum += freq[i] * (freq[i] - 1);
    }

    ic = sum / (totalLetters * (totalLetters - 1));

    return ic;
}

/* ---------------- MAIN FUNCTION ---------------- */

int main() {

    int choice;
    char key[100];

    FILE *fin;
    FILE *fout;

    double plainIC, cipherIC;

    printf("VIGENERE CIPHER WITH INDEX OF COINCIDENCE\n");

    printf("\n1. Encrypt plaintext.txt to ciphertext.txt");
    printf("\n2. Decrypt ciphertext.txt to decrypted.txt");

    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);

    printf("Enter Vigenere keyword: ");
    scanf("%s", key);

    if (choice == 1) {

        fin = fopen("plaintext.txt", "r");

        if (fin == NULL) {
            printf("plaintext.txt not found.\n");
            return 1;
        }

        fout = fopen("ciphertext.txt", "w");

        encrypt(fin, fout, key);

        fclose(fin);
        fclose(fout);

        printf("\nEncryption completed.");
        printf("\nCiphertext stored in ciphertext.txt\n");

        /* Calculate IC */
        plainIC = calculateIC("plaintext.txt");
        cipherIC = calculateIC("ciphertext.txt");

        printf("\n----- INDEX OF COINCIDENCE -----\n");

        printf("IC of Plaintext  : %.4f\n", plainIC);
        printf("IC of Ciphertext : %.4f\n", cipherIC);

    } else if (choice == 2) {

        fin = fopen("ciphertext.txt", "r");

        if (fin == NULL) {
            printf("ciphertext.txt not found.\n");
            return 1;
        }

        fout = fopen("decrypted.txt", "w");

        decrypt(fin, fout, key);

        fclose(fin);
        fclose(fout);

        printf("\nDecryption completed.");
        printf("\nDecrypted text stored in decrypted.txt\n");

    } else {

        printf("Invalid choice.\n");
    }

    return 0;
}















Vigenere Cipher + Index of Coincidence + Kasiski Test











#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* ---------------- GCD FUNCTION ---------------- */

int gcd(int a, int b) {

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

/* ---------------- VIGENERE ENCRYPTION ---------------- */

void encrypt(FILE *inputFile, FILE *outputFile, char key[]) {

    int ch;
    int i = 0;
    int m = strlen(key);

    while ((ch = fgetc(inputFile)) != EOF) {

        if (isupper(ch)) {

            ch = ((ch - 'A' +
                  (toupper(key[i % m]) - 'A')) % 26) + 'A';

            i++;

        } else if (islower(ch)) {

            ch = ((ch - 'a' +
                  (tolower(key[i % m]) - 'a')) % 26) + 'a';

            i++;
        }

        fputc(ch, outputFile);
    }
}

/* ---------------- VIGENERE DECRYPTION ---------------- */

void decrypt(FILE *inputFile, FILE *outputFile, char key[]) {

    int ch;
    int i = 0;
    int m = strlen(key);

    while ((ch = fgetc(inputFile)) != EOF) {

        if (isupper(ch)) {

            ch = ((ch - 'A' -
                  (toupper(key[i % m]) - 'A') + 26) % 26) + 'A';

            i++;

        } else if (islower(ch)) {

            ch = ((ch - 'a' -
                  (tolower(key[i % m]) - 'a') + 26) % 26) + 'a';

            i++;
        }

        fputc(ch, outputFile);
    }
}

/* ---------------- INDEX OF COINCIDENCE ---------------- */

double calculateIC(char filename[]) {

    FILE *fp;

    int freq[26] = {0};

    int totalLetters = 0;
    int ch, i;

    double sum = 0.0;
    double ic;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        if (isalpha(ch)) {

            ch = toupper(ch);

            freq[ch - 'A']++;

            totalLetters++;
        }
    }

    fclose(fp);

    for (i = 0; i < 26; i++) {

        sum += freq[i] * (freq[i] - 1);
    }

    ic = sum / (totalLetters * (totalLetters - 1));

    return ic;
}

/* ---------------- KASISKI TEST ---------------- */

void kasiskiTest(char filename[]) {

    FILE *fp;

    char text[5000];

    int len, i, j;
    int keyLength = 0;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Cannot open ciphertext file.\n");
        return;
    }

    fscanf(fp, "%s", text);

    fclose(fp);

    len = strlen(text);

    printf("\n----- KASISKI TEST -----\n");

    printf("\nRepeated patterns found:\n\n");

    /* Check repeated patterns of length 3, 4 and 5 */

    for (int patternLength = 3;
         patternLength <= 5;
         patternLength++) {

        for (i = 0; i < len - patternLength; i++) {

            for (j = i + patternLength;
                 j < len - patternLength;
                 j++) {

                if (strncmp(&text[i],
                            &text[j],
                            patternLength) == 0) {

                    int distance = j - i;

                    printf("Pattern: ");

                    for (int k = 0;
                         k < patternLength;
                         k++) {

                        printf("%c", text[i + k]);
                    }

                    printf(" | Positions: %d & %d",
                           i, j);

                    printf(" | Distance: %d\n",
                           distance);

                    /* Calculate GCD */

                    if (keyLength == 0)
                        keyLength = distance;

                    else
                        keyLength =
                        gcd(keyLength, distance);
                }
            }
        }
    }

    if (keyLength != 0)
        printf("\nEstimated Key Length: %d\n",
               keyLength);

    else
        printf("\nNo repeated patterns found.\n");
}

/* ---------------- MAIN FUNCTION ---------------- */

int main() {

    int choice;

    char key[100];

    FILE *fin;
    FILE *fout;

    double plainIC;
    double cipherIC;

    printf("VIGENERE CIPHER + IOC + KASISKI TEST\n");

    printf("\n1. Encrypt plaintext.txt");
    printf("\n2. Decrypt ciphertext.txt");

    printf("\n\nEnter your choice: ");

    scanf("%d", &choice);

    printf("Enter Vigenere keyword: ");

    scanf("%s", key);

    if (choice == 1) {

        fin = fopen("plaintext.txt", "r");

        if (fin == NULL) {

            printf("plaintext.txt not found.\n");

            return 1;
        }

        fout = fopen("ciphertext.txt", "w");

        encrypt(fin, fout, key);

        fclose(fin);
        fclose(fout);

        printf("\nEncryption completed.");
        printf("\nCiphertext stored in ciphertext.txt\n");

        /* IC Calculation */

        plainIC = calculateIC("plaintext.txt");

        cipherIC = calculateIC("ciphertext.txt");

        printf("\n----- INDEX OF COINCIDENCE -----\n");

        printf("IC of Plaintext  : %.4f\n",
               plainIC);

        printf("IC of Ciphertext : %.4f\n",
               cipherIC);

        /* Kasiski Test */

        kasiskiTest("ciphertext.txt");

    }

    else if (choice == 2) {

        fin = fopen("ciphertext.txt", "r");

        if (fin == NULL) {

            printf("ciphertext.txt not found.\n");

            return 1;
        }

        fout = fopen("decrypted.txt", "w");

        decrypt(fin, fout, key);

        fclose(fin);
        fclose(fout);

        printf("\nDecryption completed.");

        printf("\nDecrypted text stored in decrypted.txt\n");
    }

    else {

        printf("Invalid choice.\n");
    }

    return 0;
}


















KASISKI TEST





#include <stdio.h>
#include <string.h>

/* Function to find GCD */
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    char text[1000];
    int len, i, j;
    int keyLength = 0;

    printf("Enter ciphertext:\n");
    scanf("%s", text);

    len = strlen(text);

    printf("\nRepeated 3-letter patterns:\n");

    /* Find repeated 3-letter groups */
    for (i = 0; i < len - 2; i++) {
        for (j = i + 3; j < len - 2; j++) {

            if (text[i] == text[j] &&
                text[i + 1] == text[j + 1] &&
                text[i + 2] == text[j + 2]) {

                int distance = j - i;

                printf("%c%c%c found at %d and %d -> Distance = %d\n",
                       text[i], text[i + 1], text[i + 2],
                       i, j, distance);

                /* Calculate GCD of distances */
                if (keyLength == 0)
                    keyLength = distance;
                else
                    keyLength = gcd(keyLength, distance);
            }
        }
    }

    printf("\nEstimated Key Length: %d\n", keyLength);

    return 0;
}








INDEX OF COINCEDENCE





#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[1000];
    int frequencies[26] = {0};
    int totalLetters = 0;
    double ic = 0.0;
    double sum = 0.0;
    int i;

    printf("Enter the ciphertext:\n");
    fgets(text, sizeof(text), stdin);

    /* Count the frequencies of each letter */
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            int index = toupper(text[i]) - 'A';
            frequencies[index]++;
            totalLetters++;
        }
    }
    /* Calculate the numerator sum: f * (f - 1) */
    for (i = 0; i < 26; i++) {
        sum += frequencies[i] * (frequencies[i] - 1);
    }

    /* Standard IC Formula: Sum( f*(f-1) ) / ( N*(N-1) ) */
    ic = sum / (totalLetters * (totalLetters - 1));

    printf("\nTotal letters counted: %d\n", totalLetters);
    printf("Calculated Index of Coincidence (IC): %.4f\n", ic);

    if (ic >= 0.055) {
        printf("Analysis: Likely a MONOALPHABETIC cipher (or plain English).\n");
    } else {
        printf("Analysis: Likely a POLYALPHABETIC cipher.\n");
    }

    return 0;
}


























PLAY FAIR 5X5





#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char matrix[5][5];

void generateMatrix(char key[]) {
    int alphabet[26] = {0};
    int i, j, k = 0, len;
    
    /* Treat J as I */
    alphabet['J' - 'A'] = 1; 
    len = strlen(key);

    /* Insert keyword letters into matrix */
    for (i = 0; i < len; i++) {
        char c = toupper(key[i]);
        if (c == 'J') c = 'I';
        if (isalpha(c) && !alphabet[c - 'A']) {
            matrix[k / 5][k % 5] = c;
            alphabet[c - 'A'] = 1;
            k++;
        }
    }

    /* Fill the remaining slots with the rest of the alphabet */
    for (i = 0; i < 26; i++) {
        if (!alphabet[i]) {
            matrix[k / 5][k % 5] = 'A' + i;
            k++;
        }
    }
}

/* Finds row and column of a letter in the grid */
void findPosition(char c, int *row, int *col) {
    int i, j;
    if (c == 'J') c = 'I';
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(FILE *inputFile, FILE *outputFile) {
    int a, b;
    int r1, c1, r2, c2;

    while ((a = fgetc(inputFile)) != EOF) {
        /* Skip non-alphabet characters cleanly */
        if (!isalpha(a)) continue; 
        
        /* Get the second letter of the pair */
        while ((b = fgetc(inputFile)) != EOF && !isalpha(b));
        if (b == EOF) b = 'X'; /* Odd-length fallback padding */

        findPosition(toupper(a), &r1, &c1);
        findPosition(toupper(b), &r2, &c2);

        if (r1 == r2) { /* Same Row: Shift Right */
            fputc(matrix[r1][(c1 + 1) % 5], outputFile);
            fputc(matrix[r2][(c2 + 1) % 5], outputFile);
        } else if (c1 == c2) { /* Same Column: Shift Down */
            fputc(matrix[(r1 + 1) % 5][c1], outputFile);
            fputc(matrix[(r2 + 1) % 5][c2], outputFile);
        } else { /* Rectangle swap */
            fputc(matrix[r1][c2], outputFile);
            fputc(matrix[r2][c1], outputFile);
        }
    }
}

void decrypt(FILE *inputFile, FILE *outputFile) {
    int a, b;
    int r1, c1, r2, c2;

    while ((a = fgetc(inputFile)) != EOF) {
        if (!isalpha(a)) continue;
        while ((b = fgetc(inputFile)) != EOF && !isalpha(b));
        if (b == EOF) break;

        findPosition(toupper(a), &r1, &c1);
        findPosition(toupper(b), &r2, &c2);

        if (r1 == r2) { /* Same Row: Shift Left */
            fputc(matrix[r1][(c1 + 4) % 5], outputFile);
            fputc(matrix[r2][(c2 + 4) % 5], outputFile);
        } else if (c1 == c2) { /* Same Column: Shift Up */
            fputc(matrix[(r1 + 4) % 5][c1], outputFile);
            fputc(matrix[(r2 + 4) % 5][c2], outputFile);
        } else { /* Rectangle swap */
            fputc(matrix[r1][c2], outputFile);
            fputc(matrix[r2][c1], outputFile);
        }
    }
}

int main() {
    int choice;
    char key[100];
    FILE *fin;
    FILE *fout;

    printf("1. Encrypt plaintext.txt to ciphertext.txt\n");
    printf("2. Decrypt ciphertext.txt to decrypted.txt\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter the keyword: ");
    scanf("%s", key);

    generateMatrix(key);

    if (choice == 1) {
        fin = fopen("plaintext.txt", "r");
        fout = fopen("ciphertext.txt", "w");
        encrypt(fin, fout);
        printf("Success! Encrypted text saved to 'ciphertext.txt'.\n");
    } else if (choice == 2) {
        fin = fopen("ciphertext.txt", "r");
        fout = fopen("decrypted.txt", "w");
        decrypt(fin, fout);
        printf("Success! Decrypted text saved to 'decrypted.txt'.\n");
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    fclose(fin);
    fclose(fout);
    return 0;
}











PLAYFAIR 5X5 with IOC












#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char matrix[5][5];

/* ---------------- PLAYFAIR MATRIX ---------------- */

void generateMatrix(char key[]) {
    int alphabet[26] = {0};
    int i, k = 0;

    /* Treat J as I */
    alphabet['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++) {
        char c = toupper(key[i]);

        if (c == 'J')
            c = 'I';

        if (isalpha(c) && !alphabet[c - 'A']) {
            matrix[k / 5][k % 5] = c;
            alphabet[c - 'A'] = 1;
            k++;
        }
    }

    /* Fill remaining letters */
    for (i = 0; i < 26; i++) {
        if (!alphabet[i]) {
            matrix[k / 5][k % 5] = 'A' + i;
            k++;
        }
    }
}

/* Find position of character in matrix */
void findPosition(char c, int *row, int *col) {
    int i, j;

    if (c == 'J')
        c = 'I';

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

/* ---------------- PLAYFAIR ENCRYPTION ---------------- */

void encrypt(FILE *inputFile, FILE *outputFile) {
    int a, b;
    int r1, c1, r2, c2;

    while ((a = fgetc(inputFile)) != EOF) {

        if (!isalpha(a))
            continue;

        while ((b = fgetc(inputFile)) != EOF && !isalpha(b));

        if (b == EOF)
            b = 'X';

        findPosition(toupper(a), &r1, &c1);
        findPosition(toupper(b), &r2, &c2);

        if (r1 == r2) {
            /* Same row */
            fputc(matrix[r1][(c1 + 1) % 5], outputFile);
            fputc(matrix[r2][(c2 + 1) % 5], outputFile);

        } else if (c1 == c2) {
            /* Same column */
            fputc(matrix[(r1 + 1) % 5][c1], outputFile);
            fputc(matrix[(r2 + 1) % 5][c2], outputFile);

        } else {
            /* Rectangle rule */
            fputc(matrix[r1][c2], outputFile);
            fputc(matrix[r2][c1], outputFile);
        }
    }
}

/* ---------------- INDEX OF COINCIDENCE ---------------- */

double calculateIC(char filename[]) {

    FILE *fp;
    int freq[26] = {0};
    int totalLetters = 0;
    int ch, i;
    double sum = 0.0, ic;

    fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        if (isalpha(ch)) {

            ch = toupper(ch);

            if (ch == 'J')
                ch = 'I';

            freq[ch - 'A']++;
            totalLetters++;
        }
    }

    fclose(fp);

    for (i = 0; i < 26; i++) {
        sum += freq[i] * (freq[i] - 1);
    }

    ic = sum / (totalLetters * (totalLetters - 1));

    return ic;
}

/* ---------------- DISPLAY MATRIX ---------------- */

void displayMatrix() {
    int i, j;

    printf("\nPlayfair Matrix:\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* ---------------- MAIN FUNCTION ---------------- */

int main() {

    char key[100];
    FILE *fin, *fout;
    double plainIC, cipherIC;

    printf("PLAYFAIR CIPHER WITH INDEX OF COINCIDENCE\n");

    printf("\nEnter keyword: ");
    scanf("%s", key);

    generateMatrix(key);

    displayMatrix();

    /* Open plaintext file */
    fin = fopen("plaintext.txt", "r");

    if (fin == NULL) {
        printf("plaintext.txt not found.\n");
        return 1;
    }

    /* Create ciphertext file */
    fout = fopen("ciphertext.txt", "w");

    encrypt(fin, fout);

    fclose(fin);
    fclose(fout);

    printf("\nEncryption completed.");
    printf("\nCiphertext stored in ciphertext.txt\n");

    /* Calculate IC values */
    plainIC = calculateIC("plaintext.txt");
    cipherIC = calculateIC("ciphertext.txt");

    printf("\n----- INDEX OF COINCIDENCE -----\n");

    printf("IC of Plaintext  : %.4f\n", plainIC);
    printf("IC of Ciphertext : %.4f\n", cipherIC);

    return 0;
}












IMPROVED PLAYFAIR5X5 with IOC











#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char matrix[5][5];

/* ---------------- PLAYFAIR MATRIX ---------------- */

void generateMatrix(char key[]) {

    int alphabet[26] = {0};

    int i, k = 0;

    /* Treat J as I */
    alphabet['J' - 'A'] = 1;

    for (i = 0; key[i] != '\0'; i++) {

        char c = toupper(key[i]);

        if (c == 'J')
            c = 'I';

        if (isalpha(c) && !alphabet[c - 'A']) {

            matrix[k / 5][k % 5] = c;

            alphabet[c - 'A'] = 1;

            k++;
        }
    }

    /* Fill remaining alphabet */

    for (i = 0; i < 26; i++) {

        if (!alphabet[i]) {

            matrix[k / 5][k % 5] = 'A' + i;

            k++;
        }
    }
}

/* ---------------- FIND POSITION ---------------- */

void findPosition(char c, int *row, int *col) {

    int i, j;

    if (c == 'J')
        c = 'I';

    for (i = 0; i < 5; i++) {

        for (j = 0; j < 5; j++) {

            if (matrix[i][j] == c) {

                *row = i;
                *col = j;

                return;
            }
        }
    }
}

/* ---------------- PREPROCESS PLAINTEXT ---------------- */

void preprocessText(FILE *inputFile, char processedText[]) {

    int ch;
    int index = 0;

    char previous = '\0';

    while ((ch = fgetc(inputFile)) != EOF) {

        if (isalpha(ch)) {

            ch = toupper(ch);

            if (ch == 'J')
                ch = 'I';

            /* Handle repeated letters */

            if (previous == ch) {

                processedText[index++] = 'X';
            }

            processedText[index++] = ch;

            previous = ch;
        }
    }

    /* If odd length, append X */

    if (index % 2 != 0) {

        processedText[index++] = 'X';
    }

    processedText[index] = '\0';
}

/* ---------------- PLAYFAIR ENCRYPTION ---------------- */

void encrypt(char text[], FILE *outputFile) {

    int i;

    int r1, c1, r2, c2;

    for (i = 0; text[i] != '\0'; i += 2) {

        char a = text[i];
        char b = text[i + 1];

        findPosition(a, &r1, &c1);

        findPosition(b, &r2, &c2);

        /* Same row */

        if (r1 == r2) {

            fputc(matrix[r1][(c1 + 1) % 5], outputFile);

            fputc(matrix[r2][(c2 + 1) % 5], outputFile);
        }

        /* Same column */

        else if (c1 == c2) {

            fputc(matrix[(r1 + 1) % 5][c1], outputFile);

            fputc(matrix[(r2 + 1) % 5][c2], outputFile);
        }

        /* Rectangle rule */

        else {

            fputc(matrix[r1][c2], outputFile);

            fputc(matrix[r2][c1], outputFile);
        }
    }
}

/* ---------------- PLAYFAIR DECRYPTION ---------------- */

void decrypt(FILE *inputFile, FILE *outputFile) {

    char text[5000];

    int index = 0;

    int ch;

    int r1, c1, r2, c2;

    while ((ch = fgetc(inputFile)) != EOF) {

        if (isalpha(ch)) {

            text[index++] = toupper(ch);
        }
    }

    text[index] = '\0';

    for (int i = 0; text[i] != '\0'; i += 2) {

        char a = text[i];
        char b = text[i + 1];

        findPosition(a, &r1, &c1);

        findPosition(b, &r2, &c2);

        /* Same row */

        if (r1 == r2) {

            fputc(matrix[r1][(c1 + 4) % 5], outputFile);

            fputc(matrix[r2][(c2 + 4) % 5], outputFile);
        }

        /* Same column */

        else if (c1 == c2) {

            fputc(matrix[(r1 + 4) % 5][c1], outputFile);

            fputc(matrix[(r2 + 4) % 5][c2], outputFile);
        }

        /* Rectangle rule */

        else {

            fputc(matrix[r1][c2], outputFile);

            fputc(matrix[r2][c1], outputFile);
        }
    }
}

/* ---------------- INDEX OF COINCIDENCE ---------------- */

double calculateIC(char filename[]) {

    FILE *fp;

    int freq[26] = {0};

    int totalLetters = 0;

    int ch, i;

    double sum = 0.0;

    double ic;

    fp = fopen(filename, "r");

    if (fp == NULL) {

        printf("Cannot open file %s\n", filename);

        return 0;
    }

    while ((ch = fgetc(fp)) != EOF) {

        if (isalpha(ch)) {

            ch = toupper(ch);

            if (ch == 'J')
                ch = 'I';

            freq[ch - 'A']++;

            totalLetters++;
        }
    }

    fclose(fp);

    for (i = 0; i < 26; i++) {

        sum += freq[i] * (freq[i] - 1);
    }

    ic = sum / (totalLetters * (totalLetters - 1));

    return ic;
}

/* ---------------- DISPLAY MATRIX ---------------- */

void displayMatrix() {

    int i, j;

    printf("\nPlayfair Matrix:\n\n");

    for (i = 0; i < 5; i++) {

        for (j = 0; j < 5; j++) {

            printf("%c ", matrix[i][j]);
        }

        printf("\n");
    }
}

/* ---------------- MAIN FUNCTION ---------------- */

int main() {

    int choice;

    char key[100];

    char processedText[5000];

    FILE *fin, *fout;

    double plainIC, cipherIC;

    printf("PLAYFAIR CIPHER (5x5) WITH IOC\n");

    printf("\n1. Encrypt");
    printf("\n2. Decrypt");

    printf("\n\nEnter your choice: ");

    scanf("%d", &choice);

    printf("Enter keyword: ");

    scanf("%s", key);

    generateMatrix(key);

    displayMatrix();

    /* ENCRYPTION */

    if (choice == 1) {

        fin = fopen("plaintext.txt", "r");

        if (fin == NULL) {

            printf("plaintext.txt not found.\n");

            return 1;
        }

        preprocessText(fin, processedText);

        fclose(fin);

        printf("\nProcessed Plaintext:\n%s\n",
               processedText);

        fout = fopen("ciphertext.txt", "w");

        encrypt(processedText, fout);

        fclose(fout);

        printf("\nEncryption completed.");

        printf("\nCiphertext stored in ciphertext.txt\n");

        plainIC = calculateIC("plaintext.txt");

        cipherIC = calculateIC("ciphertext.txt");

        printf("\n----- INDEX OF COINCIDENCE -----\n");

        printf("IC of Plaintext  : %.4f\n",
               plainIC);

        printf("IC of Ciphertext : %.4f\n",
               cipherIC);
    }

    /* DECRYPTION */

    else if (choice == 2) {

        fin = fopen("ciphertext.txt", "r");

        if (fin == NULL) {

            printf("ciphertext.txt not found.\n");

            return 1;
        }

        fout = fopen("decrypted.txt", "w");

        decrypt(fin, fout);

        fclose(fin);

        fclose(fout);

        printf("\nDecryption completed.");

        printf("\nDecrypted text stored in decrypted.txt\n");
    }

    else {

        printf("Invalid choice.\n");
    }

    return 0;
}
















PLAY FAIR 16X16






#include <stdio.h>
#include <string.h>

unsigned char matrix[16][16];

/* Generates a 16x16 matrix using all 256 unique ASCII characters */
void generateMatrix(char key[]) {
    int asciiCheck[256] = {0};
    int i, k = 0, len = strlen(key);

    /* First, place unique characters from the keyword into the matrix */
    for (i = 0; i < len; i++) {
        unsigned char c = key[i];
        if (!asciiCheck[c]) {
            matrix[k / 16][k % 16] = c;
            asciiCheck[c] = 1;
            k++;
        }
    }

    /* Fill the remaining slots with the rest of the 256 ASCII table */
    for (i = 0; i < 256; i++) {
        if (!asciiCheck[i]) {
            matrix[k / 16][k % 16] = (unsigned char)i;
            k++;
        }
    }
}

/* Finds the row and column of any ASCII byte inside the 16x16 grid */
void findPosition(unsigned char c, int *row, int *col) {
    int i, j;
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 16; j++) {
            if (matrix[i][j] == c) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(FILE *fin, FILE *fout) {
    int a, b;
    int r1, c1, r2, c2;

    /* Read exactly two characters at a time */
    while ((a = fgetc(fin)) != EOF) {
        b = fgetc(fin);
        if (b == EOF) b = 'X'; /* Simple fallback padding if text length is odd */

        findPosition((unsigned char)a, &r1, &c1);
        findPosition((unsigned char)b, &r2, &c2);

        if (r1 == r2) { /* Same Row: Shift Right */
            fputc(matrix[r1][(c1 + 1) % 16], fout);
            fputc(matrix[r2][(c2 + 1) % 16], fout);
        } else if (c1 == c2) { /* Same Column: Shift Down */
            fputc(matrix[(r1 + 1) % 16][c1], fout);
            fputc(matrix[(r2 + 1) % 16][c2], fout);
        } else { /* Rectangle intersection swap */
            fputc(matrix[r1][c2], fout);
            fputc(matrix[r2][c1], fout);
        }
    }
}

void decrypt(FILE *fin, FILE *fout) {
    int a, b;
    int r1, c1, r2, c2;

    while ((a = fgetc(fin)) != EOF) {
        b = fgetc(fin);
        if (b == EOF) break;

        findPosition((unsigned char)a, &r1, &c1);
        findPosition((unsigned char)b, &r2, &c2);

        if (r1 == r2) { /* Same Row: Shift Left */
            fputc(matrix[r1][(c1 + 15) % 16], fout);
            fputc(matrix[r2][(c2 + 15) % 16], fout);
        } else if (c1 == c2) { /* Same Column: Shift Up */
            fputc(matrix[(r1 + 15) % 16][c1], fout);
            fputc(matrix[(r2 + 15) % 16][c2], fout);
        } else { /* Rectangle intersection swap */
            fputc(matrix[r1][c2], fout);
            fputc(matrix[r2][c1], fout);
        }
    }
}

int main() {
    int choice;
    char key[100];
    FILE *fin, *fout;

    printf("1. Encrypt plaintext.txt to ciphertext.txt\n");
    printf("2. Decrypt ciphertext.txt to decrypted.txt\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter keyword: ");
    scanf("%s", key);

    generateMatrix(key);

    if (choice == 1) {
        fin = fopen("plaintext.txt", "r");
        fout = fopen("ciphertext.txt", "w");
        encrypt(fin, fout);
        printf("Success! Encrypted text saved to 'ciphertext.txt'.\n");
    } else if (choice == 2) {
        fin = fopen("ciphertext.txt", "r");
        fout = fopen("decrypted.txt", "w");
        decrypt(fin, fout);
        printf("Success! Decrypted text saved to 'decrypted.txt'.\n");
    }

    if (fin) fclose(fin);
    if (fout) fclose(fout);
    return 0;
}










RSA





Step 1 — Choose Two Prime Numbers p and q
Example:
p = 11
q = 13

Step 2 — Compute n=p×q
Example:
n = 11 × 13 = 143

Step 3 — Compute Euler Totient ϕ(n)=(p−1)(q−1)
Example:
φ = 10 × 12 = 120

Step 4 — Choose e
Conditions:
1<e<φ(n)
gcd(e, φ) = 1
Example:
e = 7

Step 5 — Compute d
d×e≡1(modϕ(n))

Find multiplicative inverse.
Example:
d = 103
because:
(103 × 7) mod 120 = 1

Final Keys
Key	Value
Public Key	(e,n)
Private Key	(d,n)










#include <stdio.h>
#include <stdlib.h>

/* Simple Euclidean GCD function to find 'e' */
int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/* Binary Modular Exponentiation: Prevents overflows during dynamic calculations */
long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % mod;
        }
        base = (base * base) % mod;
        exp = exp / 2;
    }
    return res;
}

void encrypt(FILE *fin, FILE *fout, long long e, long long n) {
    int ch;
    while ((ch = fgetc(fin)) != EOF) {
        long long cipherChar = power(ch, e, n);
        fprintf(fout, "%lld ", cipherChar);
    }
}

void decrypt(FILE *fin, FILE *fout, long long d, long long n) {
    long long cipherChar;
    while (fscanf(fin, "%lld ", &cipherChar) != EOF) {
        int plainChar = (int)power(cipherChar, d, n);
        fputc(plainChar, fout);
    }
}

int main() {
    int choice;
    long long p, q, n, phi, e, d;
    FILE *fin, *fout;

    printf("1. Encrypt plaintext.txt to ciphertext.txt\n");
    printf("2. Decrypt ciphertext.txt to decrypted.txt\n");
    printf("Enter choice (1 or 2): ");
    scanf("%d", &choice);

    /* Ask for arbitrary prime numbers during execution to satisfy the teacher */
    printf("Enter first prime number (p): ");
    scanf("%lld", &p);
    printf("Enter second prime number (q): ");
    scanf("%lld", &q);

    /* Dynamic calculations matching standard RSA rules */
    n = p * q;
    phi = (p - 1) * (q - 1);

    /* Automatically find a valid 'e' */
    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1) {
            break;
        }
    }

    /* Automatically find a valid 'd' */
    for (d = 1; d < phi; d++) {
        if ((d * e) % phi == 1) {
            break;
        }
    }

    /* Display the generated keys clearly so your teacher can see the math working */
    printf("\n--- Generated Keys ---\n");
    printf("Calculated n     = %lld\n", n);
    printf("Calculated phi   = %lld\n", phi);
    printf("Public Key (e)   = %lld\n", e);
    printf("Private Key (d)  = %lld\n", d);
    printf("----------------------\n\n");

    if (choice == 1) {
        fin = fopen("plaintext.txt", "r");
        fout = fopen("ciphertext.txt", "w");
        
        if (!fin) {
            printf("Error: Missing plaintext.txt\n");
            return 1;
        }
        
        encrypt(fin, fout, e, n);
        printf("Success! Verification numbers saved to 'ciphertext.txt'.\n");
        
    } else if (choice == 2) {
        fin = fopen("ciphertext.txt", "r");
        fout = fopen("decrypted.txt", "w");
        
        if (!fin) {
            printf("Error: Missing ciphertext.txt\n");
            return 1;
        }
        
        decrypt(fin, fout, d, n);
        printf("Success! Original text safely restored to 'decrypted.txt'.\n");
    } else {
        printf("Invalid choice.\n");
    }

    if (fin) fclose(fin);
    if (fout) fclose(fout);
    return 0;
}







NORMAL EUCLIDIAN






#include <stdio.h>

int euclid(int a, int b) {
    int r;

    while (b > 0) {
        r = a % b;
        /* Step update shift */
        a = b;
        b = r;
    }

    return a;
}

int main() {
    int a = 27;
    int b = 5;

    int gcd = euclid(a, b);

    printf("The GCD of %d and %d is = %d\n", a, b, gcd);

    return 0;
}










EXTENDED EUCLIDIAN





#include <stdio.h>

int extendedEuclid(int a, int n, int *s, int *t) {
    int r1 = n;
    int r2 = a;
    
    /* Initializing coefficients matching standard Extended GCD tables */
    int s1 = 1, s2 = 0;
    int t1 = 0, t2 = 1;

    int q, r, s_temp, t_temp;

    while (r2 > 0) {
        q = r1 / r2;

        /* Core tabular formulas */
        r = r1 - q * r2;
        s_temp = s1 - q * s2;
        t_temp = t1 - q * t2;

        /* Standard step update shift */
        r1 = r2;
        r2 = r;

        s1 = s2;
        s2 = s_temp;

        t1 = t2;
        t2 = t_temp;
    }

    /* Assign back Bezout coefficients */
    *s = s1;
    *t = t1;

    /* If gcd(a, n) is not 1, modular inverse cannot exist */
    if (r1 != 1) {
        return -1;
    }

    /* Make sure the result is mapped to a positive remainder context */
    if (t1 < 0) {
        t1 += n;
    }

    return t1;
}

int main() {
    int a = 5;
    int n = 27;
    int s, t;

    int inverse = extendedEuclid(a, n, &s, &t);

    if (inverse == -1) {
        printf("Inverse does not exist\n");
    } else {
        printf("s = %d\n", s);
        printf("t = %d\n", t);
        printf("Inverse of %d mod %d = %d\n", a, n, inverse);
    }

    return 0;
}








A MOD B MULTIPlicaTIVE INVERSE USING EXTENDED EUclidIAM





#include <stdio.h>

/* Extended Euclidean Algorithm */
/* Returns gcd, and updates x and y via pointers */
int extendedGCD(int a, int n, int *x, int *y) {
    /* Base Case */
    if (a == 0) {
        *x = 0;
        *y = 1;
        return n;
    }

    int x1, y1; /* To store results of recursive call */
    int gcd = extendedGCD(n % a, a, &x1, &y1);

    /* Update x and y using results of recursive call */
    *x = y1 - (n / a) * x1;
    *y = x1;

    return gcd;
}

int main() {
    int a, n;
    int x, y;

    printf("Enter number (a): ");
    scanf("%d", &a);
    printf("Enter modulo (n): ");
    scanf("%d", &n);

    int gcd = extendedGCD(a, n, &x, &y);

    /* Inverse exists only if gcd(a, n) is 1 */
    if (gcd != 1) {
        printf("Modular inverse does not exist because gcd(%d, %d) != 1\n", a, n);
    } else {
        /* Handling negative results to keep the inverse positive within modulo n range */
        int inverse = (x % n + n) % n;
        printf("The modular inverse of %d mod %d is: %d\n", a, n, inverse);
    }

    return 0;
}
















OPENSSL 











AES ECB Encryption

openssl enc -aes-256-ecb -in msg.txt -out cipher.bin -k mypassword

openssl enc -d -aes-256-ecb -in cipher.bin -out decrypted.txt -k mypassword








AES CBC Encryption

openssl enc -aes-256-cbc -in msg.txt -out ciphercbc.bin -k mypassword

openssl enc -d -aes-256-cbc -in ciphercbc.bin -out decryptedcbc.txt -k mypassword







Avalanche Effect

echo "AAAAAAAAAAAAAAAA" > p1.txt
echo "AAAAAAAABAAAAAAA" > p2.txt
openssl enc -aes-128-ecb -in p1.txt -out c1.bin -k pass123
openssl enc -aes-128-ecb -in p2.txt -out c2.bin -k pass123







RSA

Generate Private Key
openssl genrsa -out private.pem 2048

View Private Key
openssl rsa -text -in private.pem

Generate Public Key
openssl rsa -pubout -in private.pem -out public.pem

View Public Key
openssl rsa -pubin -in public.pem -text

Create Plaintext file
echo "AAAAAAAAAAAAAAAA" > p1.txt

Encrypt Message
openssl rsautl -encrypt -inkey public.pem -pubin -in message.txt -out cipher.bin

Decrypt Message
openssl rsautl -decrypt -inkey private.pem -in cipher.bin -out decrypted.txt






Hashing (MD5 & SHA)

Files:
echo "hello" > a.txt
echo "hfllo" > b.txt

Hash:
openssl dgst -sha256 a.txt
openssl dgst -sha256 b.txt





Generate Self-Signed Digital Certificate

openssl req -x509 -newkey rsa:2048 -keyout key.pem -out cert.pem -days 365

View Certificate
openssl x509 -in cert.pem -text -noout







Same message digest using shell program: 

#!/bin/bash
declare -A seen_hashes
attempts=0

echo "Searching for a 16-bit (4 hex chars) MD5 collision via OpenSSL CLI..."

while true; do
    ((attempts++))
    message="test_string_payload_$attempts"
    
    # Pipe string to openssl CLI tool
    hash=$(echo -n "$message" | openssl dgst -md5 | awk '{print $2}')
    
    # Extract the first 4 characters
    truncated=${hash:0:4}
    
    if [[ -n "${seen_hashes[$truncated]}" ]]; then
        echo -e "\n[+] Collision Found after $attempts attempts!"
        echo "Message 1: ${seen_hashes[$truncated]}"
        echo "Message 2: $message"
        echo "Matching Prefix: $truncated"
        break
    fi
    seen_hashes[$truncated]=$message
done










SHA256 Integrity Checker
Detect File Modification


#!/bin/bash

openssl dgst -sha256 file.txt > original.hash

echo "Original Hash:"
cat original.hash

echo "Modify the file now..."
sleep 10

openssl dgst -sha256 file.txt > new.hash

echo "New Hash:"
cat new.hash

diff original.hash new.hash

if [ $? -eq 0 ]; then
    echo "File unchanged"
else
    echo "File modified!"
fi









RSA Encryption-Decryption Automation


#!/bin/bash

echo "Generating RSA keys..."

openssl genrsa -out private.pem 2048

openssl rsa -pubout -in private.pem -out public.pem

echo "Hello Cryptography" > msg.txt

echo "Encrypting..."

openssl rsautl -encrypt \
-inkey public.pem \
-pubin \
-in msg.txt \
-out cipher.bin

echo "Decrypting..."

openssl rsautl -decrypt \
-inkey private.pem \
-in cipher.bin \
-out decrypted.txt







Digital Signature Script

Sign File

#!/bin/bash

openssl genrsa -out private.pem 2048

openssl rsa -pubout -in private.pem -out public.pem

echo "Important Message" > msg.txt

openssl dgst -sha256 \
-sign private.pem \
-out sign.bin \
msg.txt

echo "Message signed"


Verify Signature

#!/bin/bash

openssl dgst -sha256 \
-verify public.pem \
-signature sign.bin \
msg.txt

echo "Decrypted Message:"
cat decrypted.txt













NMAP









TCP

nmap -sT 192.168.1.1 



UDP

nmap -sU 192.168.1.1



SYN Scan

nmap -sS 192.168.1.1



Ping Scan

nmap -sn 192.168.1.0/24



Service Version Detection

nmap -sV 192.168.1.1



OS Detection

nmap -O 192.168.1.1



Aggressive Scan

nmap -A 192.168.1.1

Includes:

OS detection
version detection
script scanning
traceroute



Scan Specific Ports

Single Port
nmap -p 80 192.168.1.1

Multiple Ports
nmap -p 22,80,443 192.168.1.1

Port Range
nmap -p 1-1000 192.168.1.1

Scan All Ports 65535
nmap -p- 192.168.1.1



Save Output

Normal Output
nmap -oN result.txt 192.168.1.1



Firewall Detection

ACK Scan
nmap -sA 192.168.1.1

Used for: firewall rule analysis



port scanning and ip scanning for range

nmap -p 1-1000 127.0.0.1/24 -sT

Port	Service
22	SSH
80	HTTP
443	HTTPS
21	FTP
25	SMTP











WIRESHARK










TCP 3-Way Handshake

first run in the terminal: curl https://example.com

filter: tcp.flags.syn == 1 || tcp.flags.ack == 1



Time between 2 GET requests

first run in the terminal: curl https://example.com

filter: http.request.method == "GET"

then calculate time between 2 get requests






TLS/SSl handshaking 

curl https://self-signed.badssl.com/

wireshark display filter: tcp.stream eq 0















IPTABLES











Block ICMP Packets

iptables -A INPUT -p icmp -j DROP




Allow Only SSH from Outside

Step 1 — Allow SSH
sudo iptables -A INPUT -p tcp --dport 22 -j ACCEPT

Step 2 — Block Everything Else
sudo iptables -A INPUT -j DROP





Allow Everything Except SSH

Step 1 — Block SSH
sudo iptables -A INPUT -p tcp --dport 22 -j DROP

Step 2 — Allow Everything Else
sudo iptables -A INPUT -j ACCEPT





Allow Specific Port

Allow HTTP:
sudo iptables -A INPUT -p tcp --dport 80 -j ACCEPT

HTTPS
sudo iptables -A INPUT -p tcp --dport 443 -j ACCEPT

TCP
sudo iptables -A INPUT -p tcp --dport 80 -j ACCEPT

UDP
sudo iptables -A INPUT -p udp --dport 53 -j ACCEPT







Block Specific IP
sudo iptables -A INPUT -s 192.168.1.5 -j DROP

Block Destination IP
sudo iptables -A OUTPUT -d 192.168.1.5 -j DROP






View Numbered Rules

sudo iptables -L --line-numbers

Delete Rule by Number

sudo iptables -D INPUT 1





Flush All Rules

sudo iptables -F




Flag	Meaning
-A	append rule
-D	delete rule
-L	list rules
-F	flush rules
-P	set policy
-p	protocol
-s	source IP
-d	destination IP
--dport	destination port
-j	jump target







What is NAT?
Converts: Private IP ↔ Public IP

Enable Masquerading
sudo iptables -t nat -A POSTROUTING -o eth0 -j MASQUERADE

NAT Table
-t nat

Port Forwarding
sudo iptables -t nat -A PREROUTING -p tcp --dport 8080 -j DNAT --to-destination 192.168.1.5:80

Logging Packets
sudo iptables -A INPUT -j LOG

Why Logging Important?
Used for:
intrusion detection
monitoring
troubleshooting



