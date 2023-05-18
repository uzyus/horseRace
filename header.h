#pragma once
#ifndef HEADER_H
#define HEADER_H
typedef struct {
	char name[20];
	int odds;
} Horse;

typedef struct {
	int balance;
	int betAmount;
	int chosenHorse;
	Horse* horses;
} Game;

Game* createGame();
void destroyGame(Game* game);
void printHorses(Game* game);

#endif