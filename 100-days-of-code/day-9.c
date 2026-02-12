#include <stdio.h>
#include <string.h>
int main()
{
    char s[1000];

    printf("Enter a string: ");
    scanf("%s", s);

    int left = 0;
    int right = strlen(s) - 1;
    char temp;

    while (left < right)
    {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    printf("The reversed string is: %s\n", s);
}
