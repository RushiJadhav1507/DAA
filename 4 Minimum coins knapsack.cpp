// Minimun number of Coins required

#include<bits/stdc++.h>
#include<iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;



int getCoins(int coins[], int m, int amount) {

	int count = 0;
	for (int i=0, k=0; i<m;) {
		if (coins[i]<=amount) {
			amount -= coins[i];
			count++;
		}
		else i++;
	}
	return count;
}

void createTable(int coins[], int m, int amount) {

	int table[m+1][1000];

	for (int i=1;i<=m;i++) {
		for (int j=1; j<=amount+1; j++) {
			int C[i];

			for (int k=i, l=0;k>0;k--) {
				C[l++] = coins[m-k];
			}

			table[i][j] = getCoins(C, i, j);
		}
	}
	cout<<"\n      ";
	for (int i=1;i<=amount;i++) {
		cout << setprecision(0) << setw(5) << i;

	}
	cout<<"\n";
	for (int i=1;i<=m;i++) {
		cout <<"\n"<< setprecision(0) << setw(6) << coins[m-i];
		for (int j=1; j<=amount; j++) {
				cout << setprecision(0) << setw(5) << table[i][j];
		}
	}
	cout<<"\n\n";
}


int main()
{
	int coins[] = {10, 5, 2, 1}, amount=0;
	int m = sizeof(coins)/sizeof(coins[0]);

	cout<<"Enter the amount : ";
	cin>>amount;
	int total_coins = getCoins(coins, m, amount);

	cout<<"\nMinimum coins required : "<<total_coins<<endl;
	cout<<"\ntable \n";
	createTable(coins, m, amount);
	
	cout<<endl<<endl;
	return 0;
}
