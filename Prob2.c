#include <stdio.h>
#include <string.h>

/*
C - Pointers

Problem Set #2:

Complete the function PrintSentence to print all the individual words inside the array with a space between them.

*/

/* Array of strings that can support upto 100 words. Total length of all the words cannot exceed 2000 characters. */

#define MAX_WORD_COUNT 100
#define MAX_WORD_LENGTH 20
typedef struct
{
	char buffer[MAX_WORD_COUNT * (MAX_WORD_LENGTH + 1)];
	int start_indices[MAX_WORD_COUNT];
	int num_words;
} WordArray;

void InitializeWordArray(WordArray *warray)
{
	if (warray == NULL)
		return;
	warray->num_words = 0;
    int i;
	for (i = 0; i < MAX_WORD_COUNT; i++)
		warray->start_indices[i] = -1;
	warray->buffer[0] = '\0';
}


int AddWord(WordArray *warray, const char *word)
{
	if (warray == NULL || word == NULL)
		return 0;

	if (warray->num_words == MAX_WORD_COUNT)
		return 0;

	if (strlen(word) >= MAX_WORD_LENGTH)
		return 0;

	int new_word_index = 0;
	if (warray->num_words > 0)
	{ 
		int last_index = warray->start_indices[warray->num_words - 1];
		new_word_index = last_index + strlen(&warray->buffer[last_index]) + 1;
	}
	warray->start_indices[warray->num_words] = new_word_index;
	warray->num_words++;

	strcpy(&warray->buffer[new_word_index], word);
	return 1;
}

void PrintSentence(WordArray *warray)
{
	/* TODO: IMPLEMENT THIS FUNCTION */

	if (warray == NULL)
		return;
	int i ;
	for ( i = 0; i < warray->num_words; i++)
	{
		int word_start_index = warray->start_indices[i];
		printf("%s ", &warray->buffer[word_start_index]);
	}
	printf("\n\n");
}

int main(void)
{
	WordArray warray;
	InitializeWordArray(&warray);
	AddWord(&warray, "This");
	AddWord(&warray, "is");
	AddWord(&warray, "a");
	AddWord(&warray, "word");
	AddWord(&warray, "array");
	AddWord(&warray, "program");

	PrintSentence(&warray);
}

/*
Expected output:
This is a word array program end 

*/
