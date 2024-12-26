#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 6

void displayWord(char word[], int guessed[], int len) {
    for (int i = 0; i < len; i++)
        printf("%c ", guessed[i] ? word[i] : '_');
    printf("\n");
}

int main() {
    char word[] = "program";  // Word to guess (fixed for simplicity)
    int len = strlen(word);
    int guessed[len], attempts = 0, correct = 0;
    memset(guessed, 0, sizeof(guessed));
    char guess;

    printf("Welcome to Hangman! Guess the word (%d letters)\n", len);

    while (attempts < MAX_TRIES && correct < len) {
        displayWord(word, guessed, len);
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);
 int found = 0;
        for (int i = 0; i < len; i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = 1;
                correct++;
                found = 1;
            }
        }

        if (!found) {
            attempts++;
            printf("Wrong! Attempts left: %d\n", MAX_TRIES - attempts);
        }
    }

    if (correct == len)
        printf("Congratulations! You guessed the word: %s\n", word);
    else
        printf("Game Over! The word was: %s\n", word);

    return 0;
}


