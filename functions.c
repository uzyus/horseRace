#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "header.h"

Game* createGame() {
	Game* game = (Game*)malloc(sizeof(Game));
	game->balance = 100;
	game->horses = (Horse*)malloc(4 * sizeof(Horse));

	strcpy(game->horses[0].name, "bura");
	game->horses[0].odds = 2;
	strcpy(game->horses[1].name, "jugo");
	game->horses[1].odds = 3;
	strcpy(game->horses[2].name, "nevera");
	game->horses[2].odds = 4;
	strcpy(game->horses[3].name, "maestral");
	game->horses[3].odds = 4;

	return game;
}

void destroyGame(Game* game) {
	free(game->horses);
	free(game);
}

void printHorses(Game* game) {
	printf("\nAvailable horses:\n");
	for (int i = 0; i < 4; i++) {
		printf("%d. %s (Odds: %d)\n", i + 1, game->horses[i].name, game->horses[i].odds);
	}
}