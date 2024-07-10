#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check if a string is a palindrome
int isPalindrome(const char *str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Ignore non-alphanumeric characters from left
        while (!isalnum(str[left]) && left < right)
            left++;
        // Ignore non-alphanumeric characters from right
        while (!isalnum(str[right]) && left < right)
            right--;
        // Compare characters ignoring case
        if (tolower(str[left]) != tolower(str[right]))
            return 0; // Not a palindrome
        left++;
        right--;
    }
    return 1; // Palindrome
}

int main() {
    char str[100];

    // Input string from user
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    // Check if the string is a palindrome
    if (isPalindrome(str))
        printf("'%s' is a palindrome.\n", str);
    else
        printf("'%s' is not a palindrome.\n", str);

    return 0;
}
