#include<stdio.h>
#include<string.h>
#include<time.h>

// initial values
double walletBalance = 10.00;

// basis of all shop items, all shop items will have a name and price attached to them
struct shopItem {
	char name[15];
	double price;
};

// this structure creates 7 items
struct shopItem items[7];

// arrays used to initialize the shop items
char itemNames[7][10] = {"Coffee", "Croissant", "Tea", "Muffin", "Donut", "Pastry", "Water"};
double itemPrices[7] = {0.50, 2.00, 1.00, 1.50, 1.25, 2.50, 0.00};

// function declarations
void initItems();
void wallet();
void purchaseItem(int itemNum);
void showPrices();

int main() {
	
	// initialize items by assigning their initial values through itenNames and itemPrices
	initItems();

	// loops through the items and prints their name and price
	for (int i = 0; i<=6; i++) {
		printf("%d %s: $%.2f\n", i, items[i].name, items[i].price);
	}

	char option;
	int desiredItem;

	printf("What would you like to do? Available options are: p for purchase, w for wallet, q for quit, s to show prices... ");

	while(1) {		
		scanf(" %c", &option);

		if (option == 'p') {

			printf("What would you like to purchase? enter the number corresponding to the item. for example, if you would like to buy coffee, press 0 and press enter...\n");
			scanf(" %d", &desiredItem);

			// checks if the number provided is a valid index
			if (desiredItem >= 0 && desiredItem <= 6) {
				purchaseItem(desiredItem);
			} else {
				printf("that item does not exist!\n");
			}

		} else if(option == 'w') {

			// shows wallet balance
			wallet();

		} else if(option == 'q') {

			// quit
			break;

		} else if(option == 's') {

			showPrices();

		} else {
			printf("invalid argument! if you would like to quit, please type q\n");
		}
	}

	return 0;
}

// function definitions

void initItems() {
	for (int i = 0; i<=6; i++) {
		strcpy(items[i].name, itemNames[i]);
		items[i].price = itemPrices[i];
	}
}

void wallet() {
	printf("Your current wallet balance is $%.2f\n", walletBalance);
}

void purchaseItem(int itemNum) {
	// used to measure execution time
	clock_t start, end;
	start = clock();

	switch(itemNum) {
		case 0:
			printf("purchasing %s for $%.2f...\n", items[0].name, items[0].price);
			printf("withdrawing $%.2f from wallet with a balance of $%.2f\n", items[0].price, walletBalance);
			if(walletBalance >= items[0].price) {
				walletBalance -= items[0].price;
				printf("success! your new balance is $%.2f\n", walletBalance);
			} else {
				printf("you are too broke for this!\n");
			}
			break;
		case 1:
			printf("purchasing %s for $%.2f...\n", items[1].name, items[1].price);
			printf("withdrawing $%.2f from wallet with a balance of $%.2f\n", items[1].price, walletBalance);
			if(walletBalance >= items[1].price) {
				walletBalance -= items[1].price;
				printf("success! your new balance is $%.2f\n", walletBalance);
			} else {
				printf("you are too broke for this!\n");
			}
			break;
		case 2:
			printf("purchasing %s for $%.2f...\n", items[2].name, items[2].price);
			printf("withdrawing $%.2f from wallet with a balance of $%.2f\n", items[2].price, walletBalance);
			if(walletBalance >= items[2].price) {
				walletBalance -= items[2].price;
				printf("success! your new balance is $%.2f\n", walletBalance);
			} else {
				printf("you are too broke for this!\n");
			}
			break;
		case 3:
			printf("purchasing %s for $%.2f...\n", items[3].name, items[3].price);
			printf("withdrawing $%.2f from wallet with a balance of %.2f\n", items[3].price, walletBalance);
			if(walletBalance >= items[3].price) {
				walletBalance -= items[3].price;
				printf("success! your new balance is %.2f\n", walletBalance);
			} else {
				printf("you are too broke for this!\n");
			}
			break;
		case 4:
			printf("purchasing %s for $%.2f...\n", items[4].name, items[4].price);
			printf("withdrawing $%.2f from wallet with a balance of %.2f\n", items[4].price, walletBalance);
			if(walletBalance >= items[4].price) {
				walletBalance -= items[4].price;
				printf("success! your new balance is %.2f\n", walletBalance);
			} else {
				printf("you are too broke for this!\n");
			}
			break;
		case 5:
			printf("purchasing %s for $%.2f...\n", items[5].name, items[5].price);
			printf("withdrawing $%.2f from wallet with a balance of %.2f\n", items[5].price, walletBalance);
			if(walletBalance >= items[5].price) {
				walletBalance -= items[5].price;
				printf("success! your new balance is %.2f\n", walletBalance);
			} else {
				printf("you are too broke for this!\n");
			}
			break;
		case 6:
			printf("purchasing %s for $%.2f...\n", items[6].name, items[6].price);
			printf("withdrawing $%.2f from wallet with a balance of %.2f\n", items[6].price, walletBalance);
			if(walletBalance >= items[6].price) {
				walletBalance -= items[6].price;
				printf("success! your new balance is %.2f\n", walletBalance);
			} else {
				printf("you are too broke for this!\n");
			}
			break;
		default:
			printf("that item does not exist!");
	}

	// returns the amount of time it took to execute this entire code block
	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Purchased item or did not in %f seconds!\n", duration);
}

void showPrices() {

	for (int i = 0; i<=6; i++) {
		printf("%d %s: $%.2f\n", i, items[i].name, items[i].price);
	}

}