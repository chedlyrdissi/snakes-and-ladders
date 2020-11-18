#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include"dice.h"
#include"board.h"

int main() {

	printf("----------------------------------------------------------------------------------------------------------\n");
	printf("|                                 ______                 _____        ____                     _____     |\n");
	printf("|  \\                          /  |         |           --            -    -     |\\       /|   |          |\n");
	printf("|   \\                        /   |         |          --            -      -    | \\     / |   |          |\n");
	printf("|    \\          /\\          /    |         |         --            -        -   |  \\   /  |   |          |\n");
	printf("|     \\        /  \\        /     |______   |         --            -        -   |   \\ /   |   |_____     |\n");
	printf("|      \\      /    \\      /      |         |         --            -        -   |         |   |          |\n");
	printf("|       \\    /      \\    /       |         |         --            -        -   |         |   |          |\n");
	printf("|        \\  /        \\  /        |         |          --            -      -    |         |   |          |\n");
	printf("|         \\/          \\/         |______   |______     --_____       -____-     |         |   |_____     |\n");
	printf("|                                                                                                        |\n");
	printf("|          to snakes and ladders                                                                         |\n");
	printf("----------------------------------------------------------------------------------------------------------\n");
	
	int op;

	start: printf("Options: \n\n");
	printf("[0] Start a new Game\n");
	printf("[1] Exit\n");

	scanf("%i", &op);

	printf("You have chosen option: %i\n", op);

	if (op == 0) {
		printf("playing\n");

		int numOfPlayers;
		getPlayer: printf("please input the number of players\n");
		scanf("%i", &numOfPlayers);
		if(!(numOfPlayers > 1 && numOfPlayers < 6)) {
			goto getPlayer;
		}
		printf("%i players are playing\n", numOfPlayers);

		int currentPlayer = 0;
		int winner = -1;

		while (winner == -1) {
			printf("player %i\'s turn\n", currentPlayer);

			scanf("%s");
			int dice = throw();
			printf("Dice landed on %i\n", dice);

			drawBoard();

			currentPlayer = (currentPlayer + 1) % numOfPlayers;
		}
	} else if (op == 1) {
		printf("exiting\n");
	} else {
		printf("unknown option\n");
		goto start;
	}

	return 0;
}                    