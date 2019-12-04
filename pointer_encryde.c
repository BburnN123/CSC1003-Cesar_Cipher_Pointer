#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void crpyto(int key, int choice, char c_message[]);
void main()
{
    char input_message, input_plaintext;
    char c_message[20];
    int len, key, choice;

    printf("Enter the message : ");
    scanf("%s", &input_message); // Get the plaintext

    printf("Enter the key : ");
    scanf("%ld", &key); //Get the key value

    printf("Enter the choice 1)Encryption 2)Decryption : ");
    scanf("%ld", &choice); //Get the choice

    strcpy(c_message, &input_message); //Copy the input string to an array
    crpyto(key, choice, c_message);

    if (choice == 1)
    {
        printf("Plain Text %s\n", &input_message);
        printf("Cipher Text %s\n", &c_message);
    }
    else
    {
        printf("Cipher Text %s\n", &input_message);
        printf("Plain Text %s\n", &c_message);
    }
}

void crpyto(int key, int choice, char c_message[])
{
    char *p_message;
    p_message = c_message;
    while (*p_message != '\0') //If the p_message is not 0
    {
        switch (choice)
        {
        case 1:
            if (*p_message != ' ')
            {
                *p_message = *p_message - 65; //Remove ASCII format
                *p_message = (*p_message + key) % 26; 
                *p_message = *p_message + 65; //Convert back to ASCII
            }
            break;
        case 2:
            if (*p_message != ' ')
            {
                *p_message = *p_message - 65;
                if (*p_message <= key - 1) 
                {
                    *p_message = ((*p_message - key) + 26) % 26; //If C + K is negative
                }
                else
                {
                    *p_message = (*p_message - key) % 26;
                }
                *p_message = *p_message + 65; //Convert back to ASCII
            }
            break;
        }
        p_message++;
    }
}