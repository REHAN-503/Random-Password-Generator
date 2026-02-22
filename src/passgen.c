#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LENGTH 128

const char LOWERCASE[] = "abcdefghijklmnopqrstuvwxyz";
const char UPPERCASE[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char DIGITS[]    = "0123456789";
const char SYMBOLS[]   = "!@#$%^&*()-_=+[]{}|;:,.<>?";

int main(int argc, char *argv[]) {
    int length     = 16;
    int use_upper  = 1;
    int use_digits = 1;
    int use_sym    = 1;
    int count      = 1;

    // Args: length use_upper use_digits use_symbols count
    if (argc >= 2) length     = atoi(argv[1]);
    if (argc >= 3) use_upper  = atoi(argv[2]);
    if (argc >= 4) use_digits = atoi(argv[3]);
    if (argc >= 5) use_sym    = atoi(argv[4]);
    if (argc >= 6) count      = atoi(argv[5]);

    if (length < 4)   length = 4;
    if (length > MAX_LENGTH) length = MAX_LENGTH;
    if (count < 1)    count = 1;
    if (count > 20)   count = 20;

    // Build charset
    char charset[200];
    int clen = 0;

    memcpy(charset + clen, LOWERCASE, 26); clen += 26;
    if (use_upper)  { memcpy(charset + clen, UPPERCASE, 26); clen += 26; }
    if (use_digits) { memcpy(charset + clen, DIGITS, 10);    clen += 10; }
    if (use_sym)    { int sl = strlen(SYMBOLS); memcpy(charset + clen, SYMBOLS, sl); clen += sl; }

    srand((unsigned int)time(NULL) ^ (unsigned int)clock());

    for (int p = 0; p < count; p++) {
        char password[MAX_LENGTH + 1];
        // Guarantee at least one char from each required set
        int pos = 0;
        password[pos++] = LOWERCASE[rand() % 26];
        if (use_upper  && pos < length) password[pos++] = UPPERCASE[rand() % 26];
        if (use_digits && pos < length) password[pos++] = DIGITS[rand() % 10];
        if (use_sym    && pos < length) password[pos++] = SYMBOLS[rand() % (int)strlen(SYMBOLS)];

        while (pos < length) {
            password[pos++] = charset[rand() % clen];
        }

        // Shuffle (Fisher-Yates)
        for (int i = length - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            char tmp = password[i];
            password[i] = password[j];
            password[j] = tmp;
        }
        password[length] = '\0';
        printf("%s\n", password);
    }

    return 0;
}
