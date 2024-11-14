#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char *sortString(const char *str) {
    int len = strlen(str);
    char *sorted = malloc(len + 1);
    strcpy(sorted, str);
    qsort(sorted, len, sizeof(char), cmpfunc);
    return sorted;
}


unsigned long hash(const char *str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash;
}

char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes) {
    
    *returnSize = 0;
    *returnColumnSizes = malloc(strsSize * sizeof(int));
    char ***result = malloc(strsSize * sizeof(char **));
    unsigned long *hashes = malloc(strsSize * sizeof(unsigned long));
    int *groupSize = calloc(strsSize, sizeof(int));

    for (int i = 0; i < strsSize; i++) {
        char *sortedStr = sortString(strs[i]);
        unsigned long hashValue = hash(sortedStr);
        free(sortedStr);

        int found = 0;
        for (int j = 0; j < *returnSize; j++) {
            if (hashes[j] == hashValue) {
                result[j] = realloc(result[j], (groupSize[j] + 1) * sizeof(char *));
                result[j][groupSize[j]++] = strs[i];
                (*returnColumnSizes)[j] = groupSize[j];
                found = 1;
                break;
            }
        }

        if (!found) {
            hashes[*returnSize] = hashValue;
            result[*returnSize] = malloc(sizeof(char *));
            result[*returnSize][0] = strs[i];
            groupSize[*returnSize] = 1;
            (*returnColumnSizes)[*returnSize] = 1;
            (*returnSize)++;
        }
    }

    
    free(hashes);
    free(groupSize);
    
    return result;
}
