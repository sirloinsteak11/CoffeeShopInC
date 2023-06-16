#include<stdio.h>
#include<string.h>
#include<time.h>

double walletBalance = 10.00;
double coffeePrice = 0.50;

void wallet() {
	printf("Your current wallet balance is $%f\n", walletBalance);
}

void purchaseItem() {
	clock_t start, end;
	start = clock();

	printf("purchasing coffee for $0.50...\n");
	printf("withdrawing $0.50 from wallet with balance of $%f\n", walletBalance);
	if (walletBalance >= coffeePrice) {
		walletBalance -= coffeePrice;
		printf("Success! Your new balance is %f\n", walletBalance);
	} else {
		printf("you're too broke to purchase this!\n");
	}

	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Purchased item or did not in %f seconds!\n", duration);
}

void showPrices() {
	printf("coffee: $%f\n", coffeePrice);
}

int main() {
	char option;

	printf("coffee: $0.50\nWhat would you like to do? Available options are: p for purchase, w for wallet, q for quit, s to show prices... ");

	while(1) {		
		scanf("%c", &option);
		if (option == 'p') {
			purchaseItem();
		} else if(option == 'w') {
			wallet();
		} else if(option == 'q') {
			break;
		}
	}

	return 0;
}
