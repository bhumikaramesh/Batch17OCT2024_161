#include <stdio.h>
#include <string.h>

int countCharactersBetween(char *str, const char *startWord, const char *endWord) {
    char *start = NULL;
    char *end = NULL;
    int count = 0;

    // Find the first occurrence of the word "a"
    start = strstr(str, startWord);
    if (start == NULL) {
        return -2;  // "a" is not found in the string
    }

    // Find the first occurrence of the word "i" after "a"
    end = strstr(start + 1, endWord);
    if (end == NULL) {
        return -2;  // "i" is not found after "a"
    }

    // Calculate the number of characters between "a" and "i"
    count = end - start + strlen(endWord);  // Including the length of the word "i"
    
    return count;
}

int main() {
    fgets(str1[],sizeof(str1),stdin);
	fgets(str2[],sizeof(str2),stdin);
	fgets(str3[],sizeof(str3),stdin);
	
//	char str1[] = "it is a simple program";
  //  char str2[] = "rasberry is sweet";
    //char str3[] = "test";  // Case where 'a' and 'i' are not both present

    const char *startWord = "a";
    const char *endWord = "i";

    printf("%d\n", countCharactersBetween(str1, startWord, endWord));  // Output: 9
    printf("%d\n", countCharactersBetween(str2, startWord, endWord));  // Output: 11
    printf("%d\n", countCharactersBetween(str3, startWord, endWord));  // Output: -2 (since 'a' or 'i' is missing)

    return 0;
}

