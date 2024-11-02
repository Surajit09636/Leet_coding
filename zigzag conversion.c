#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1) return s;
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char)); 
    int index = 0;

    for (int r = 0; r < numRows; r++) {
        int step1 = 2 * (numRows - 1 - r); 
        int step2 = 2 * r;                 
        int pos = r;
        if (pos < len) {
            result[index++] = s[pos]; 
        }
        
        while (1) {
            pos += step1;
            if (pos >= len) break;
            if (step1 > 0) result[index++] = s[pos];
            pos += step2;
            if (pos >= len) break;
            if (step2 > 0) result[index++] = s[pos]; 
        }
    }

    result[index] = '\0'; 
    return result;
}
