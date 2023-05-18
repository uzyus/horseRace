#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"

int main() {
	Game* game = createGame();

	srand(time(0));

	printf("Welcome to the horse betting game!\n");
	printf("You currently have $%d\n", game->balance);

	while (game->balance > 0) {
		printHorses(game);

		printf("\nPlace your bet (minimum $1): ");
		scanf("%d", &(game->betAmount));

		if (game->betAmount < 1 || game->betAmount > game->balance) {
			printf("Invalid bet amount. Please try again.\n");
			continue;
		}

		printf("Choose a horse (1-4): ");
		scanf("%d", &(game->chosenHorse));

		if (game->chosenHorse < 1 || game->chosenHorse > 4) {
			printf("Invalid horse number. Please try again.\n");
			continue;
		}

		// Calculate the range of numbers based on the horse odds
		int totalRange = 0;
		for (int i = 0; i < 4; i++) {
			totalRange += game->horses[i].odds;
		}

		// Generate a random number within the range
		int randomNumber = rand() % totalRange + 1;

		// Find the winning horse based on the generated number
		int winningHorse = 0;
		int currentRange = game->horses[winningHorse].odds;
		while (randomNumber > currentRange) {
			winningHorse++;
			currentRange += game->horses[winningHorse].odds;
		}

		printf("\nThe race begins!\n");
		printf("The winning horse is: %s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", game->horses[winningHorse].name);

		if (game->chosenHorse == winningHorse + 1) {
			int winnings = (game->betAmount*10) / game->horses[winningHorse].odds;
			printf("Congratulations! You won $%d\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", winnings);
			game->balance += winnings;
		}
		else {
			printf("Sorry, you lost.\n");
			game->balance -= game->betAmount;
		}

		printf("Your current balance: $%d\n", game->balance);
	}

	printf("\nGame over! You have run out of money.\n");

	destroyGame(game);

	return 0;
}
