#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a die and return a random number between 1 and 6
int rollDie() {
    return (rand() % 6) + 1;
}

// Function to display the Ludo board
void displayBoard(int player1Pos, int player2Pos) {
    printf("\n");
    for (int i = 1; i <= 52; i++) {
        if (i == player1Pos) {
            printf("P1");
        } else if (i == player2Pos) {
            printf("P2");
        } else {
            printf("-");
        }

        if (i % 13 == 0) {
            printf("\n");
        } else {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int player1Pos = 1;
    int player2Pos = 1;

    srand(time(NULL)); // Seed for random number generation

    printf("Welcome to Ludo!\n");

    while (1) {
        printf("\nPlayer 1, press enter to roll the die.");
        getchar(); // Wait for the player to press enter
        int roll1 = rollDie();
        printf("Player 1 rolled a %d.\n", roll1);
        player1Pos += roll1;

        if (player1Pos > 52) {
            printf("Player 1 has won!\n");
            break;
        }

        displayBoard(player1Pos, player2Pos);

        printf("\nPlayer 2, press enter to roll the die.");
        getchar(); // Wait for the player to press enter
        int roll2 = rollDie();
        printf("Player 2 rolled a %d.\n", roll2);
        player2Pos += roll2;

        if (player2Pos > 52) {
            printf("Player 2 has won!\n");
            break;
        }

        displayBoard(player1Pos, player2Pos);
    }

    return 0;
}
