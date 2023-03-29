//#define _CRT_SECURE_NO_WARNINGS
#include "Menus.h"
#include "game.h"
#include <stdio.h>
#include <stdbool.h>

///////////////// AREAS ///////////////////
void Apartment(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		char choice = ApartmentMenu();

		switch (choice)
		{
		case '1':
			printf("you go to sleep, you fill energized (plus to next day & energy)");

			//reset energy, time and increase day
			increaseDay(1, arr);
			resetEnergy(arr);

			printStats(arr);

			break;
		case '2':
			printf("you leave your apartment");
			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}



}
void Cafe(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		char choice = CafeMenu();

		switch (choice)
		{
		case '1':

		if (arr[PLAYER].energy <= 0)
		{
			printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
			return;

		}
			printf("you go study for some time, feeling a bit tired but understanding the material more");

			increaseTime(1, arr);

			levelCha(1, arr);

			decreaseEnergy(1, arr);


			printStats(arr);


			break;
		case '2':

			printf("you leave the cafe");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}

}

void School(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		char choice = SchoolMenu();

		switch (choice)
		{
		case '1':
			if (arr[PLAYER].energy <= 0)
			{
				printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
				return;
			}

			printf("you go to your classes incredibly bored about the material but feel a bit more understnading the material");

			decreaseEnergy(5, arr);

			levelIntl(1, arr);

			increaseTime(1, arr);

			printStats(arr);

			break;
		case '2':

			printf("you leave the school");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}

}

void Park(PlayerStats arr[]) {


	bool continueProgram = true;
	while (continueProgram) {

		char choice = ParkMenu();

		switch (choice)
		{
		case '1':
			printf("you go to take a walk in the part feeling much stronger in your legs after the workout");

			if (arr[PLAYER].energy <= 0)
			{
				printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
				return;

			}



			decreaseEnergy(2, arr);

			levelStr(1, arr);

			increaseTime(1, arr);

			printStats(arr);


			break;
		case '2':


			printf("you leave the park");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}
}

void Job(PlayerStats arr[]) {


	bool continueProgram = true;
	while (continueProgram) {

		char choice = JobMenu();

		switch (choice)
		{
		case '1':
			if (arr[PLAYER].energy <= 0)
			{
				printf("you're too tired to continue, you neeed to go back home and get some sleep\n");
				return;
			}

			printf("you work a long tiring shift, but hey at least you get paid yippee!");
			//functions:

			decreaseEnergy(3, arr);

			increaseCASH(5, arr);

			increaseTime(1, arr);

			break;
		case '2':


			printf("you leave your job");

			continueProgram = false;
			break;

		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}
}

///////////////// GAME ///////////////////
void MainGame(PlayerStats arr[]) {

	bool continueProgram = true;
	while (continueProgram) {

		char choice = OverWorld();

		switch (choice)
		{
		case '1':

			Apartment(arr);
			break;

		case '2':
			if (arr[0].time >= 7)
			{
				printf("Its getting late, you should go back home\n");
				return;
			}
			Cafe(arr);



			break;

		case '3':
			if (arr[0].time > 4)
			{
				printf("Classes are over for the day\n");
				return;
			}
			School(arr);
			break;


		case '4':
			if (arr[0].time >= 7)
			{
				printf("Its getting late, you should go back home\n");
				return;
			}
			Park(arr);
			break;


		case '5':
			if (arr[0].time > 6)
			{
				printf("Shift is over for the day\n");
				return;
			}
			Job(arr);
			break;


		case '6':
			continueProgram = false;
			break;


		default:
			printf("\ninvalid entry...\n");
			break;
		}
	}

}
