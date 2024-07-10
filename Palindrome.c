#include <stdio.h>
#include <string.h>
#include <ctype.h>


int isPalindrome(char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    // Continue moving from both ends towards the center
    while (right > left) {
        // Ignore non-alphanumeric characters
        while (!isalnum(str[left]) && left < right)
            left++;
        while (!isalnum(str[right]) && right > left)
            right--;

        // Compare characters ignoring case
        if (tolower(str[left]) != tolower(str[right]))
            return 0;

        left++;
        right--;
    }

    return 1; // It is a palindrome
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    if (isPalindrome(str))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);

    return 0;
}

