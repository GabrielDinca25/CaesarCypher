#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 25

char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

void encrypt(char input[], int key)
{
    int i;
    printf("Encrypted message is: ");
	for (i = 0; i < strlen(input); i++)
	{
		if (input[i] != ' ')
		{
			char* letter = strchr(alphabet, input[i]);
			int index = letter - alphabet;
			if (index <= ALPHABET_SIZE - key)
			{
			    printf("%c", alphabet[index + key]);
			}
			else
			{
                printf("%c", alphabet[key - (ALPHABET_SIZE - index) - 1]);

			}

		}
		{
			printf(" ");
		}
	}
	printf("\n");

}

void decrypt(char input[], int key)
{
    int i;
    printf("Decrypted message is: ");
	for (i = 0; i < strlen(input); i++)
	{
		if (input[i] != ' ')
		{
			char* letter = strchr(alphabet, input[i]);
			int index = letter - alphabet;
			if (index >= key)
			{
			    printf("%c", alphabet[index - key]);
			}
			else
			{
                printf("%c", alphabet[ALPHABET_SIZE - key + index + 1]);
			}

		}
		{
			printf(" ");
		}
	}
}

int main()
{

	char encryption_input[] = "ana are xyz";
	int key = 3;

	encrypt(encryption_input, key);

    char decryption_input[] = "dqd duh abc";
    key = 3;

    decrypt(decryption_input, key);



	return 0;
}
