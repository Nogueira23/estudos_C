#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float count_letters(string text);
float count_sentences(string text);
float count_words(string text);

int main(void)
{
    string text = get_string("text: ");
    float n_l = count_letters(text);
    float n_w = count_words(text);
    float n_s = count_sentences(text);

    float L = n_l/n_w*100;
    float S = n_s/n_w*100;
    int index = round(0.0588*L - 0.296*S- 15.8);
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

float count_letters(string text)
{
    int n = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            n += 1;
        }
    }
    return n;
}

float count_sentences(string text)
{
    int n = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            n += 1;
        }
    }
    return n;
}

float count_words(string text)
{
    int n = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63 || text[i] == 32)
        {
            n += 1;
            if (text[i] == 46 && text[i+1] == 32)
            {
                n -= 1;
            }
            if (text[i] == 33 && text[i+1] == 32)
            {
                n -= 1;
            }
            if (text[i] == 63 && text[i+1] == 32)
            {
                n -= 1;
            }
        }
    }
    return n;
}