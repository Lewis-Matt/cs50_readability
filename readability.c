/*
- Prompt the user for a string of text
- Count the number of letters, words, and sentences. A letter can be any upper/lowercase char, any sequence of chars separated by a space is a word,
the occurence of a period, exclamation, or question mark indicates the end of a sentence
- Print "Grade X" where is is the grade level determined by index = 0.0588 * L - 0.296 * S - 15.8 rounded to nearest int
- If the result is > 16, it should print "16+"", if < 1 it should print "Before Grade 1"
*/

#include <ctype.h> // isalpha, isalnum, isspace
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h> // round

// Prototypes
int count_letters();
int count_words();
int count_sentences();
int count_c = 0; // variable that keeps track of the number of chars
int count_w = 1; // variable that keeps track of the number of words, starts at 1 otherwise the loop will skip 1st word (since it is looking for spaces, and then counting the word)
int count_s = 0; // variable that keeps track of the number of sentences


int main (void)
{

    string text = get_string("Text: ");
    // printf("%s\n", text) - test printf

    // Determine the number of chars in text, call count_letters()
    int letters = count_letters(text);
    printf("%i letter(s)\n", letters);

    int words = count_words(text);
    printf("%i word(s)\n", words);

    int sentences = count_sentences(text);
    printf("%i sentence(s)\n", sentences);

    float L = ((float)count_c / (float)count_w) * 100; // when dividing values of type int in C, the result will also be an int, with any remainder (i.e., digits after the decimal point) discarded.
    float S = ((float)count_s / (float)count_w) * 100;
    int grade = round(0.0588 * L - 0.296 * S - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Functions (callees)
int count_letters(string text)
{
    int n = strlen(text); // length of words
    for (int i = 0; i < n; i++)
    {
        if (isalpha(text[i])) // Function with the input being the "ith" postion of our string "letters". So it is counting the chars of each index
        {
            count_c++;
        }
    }
        return count_c;
}

int count_words(string text)
{
    int n = strlen(text); // length of words
    for (int i = 0; i < n; i++)
    {
        if (isspace(text[i]))
        {
            count_w++;
        }
    }
        return count_w;
}

int count_sentences(string text)
{
    int n = strlen(text); // length of words
    for (int i = 0; i < n; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '?')
        {
            count_s++;
        }
    }
    return count_s;
}


