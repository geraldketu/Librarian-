
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<stdlib.h>
#include<cctype>
#include<cstring>

#include"GN_Project_11_header.h";

using namespace std;

const int SIZE = 20;



InventoryBook OLDBOOKS[SIZE]{
	 InventoryBook("THE MAN ", "234565", "Daniel ", "The Main Menu ", "63/2/2014", 45, 5.44, 8.54),
	InventoryBook("THE GAME ", "345676", "Zach ", "Loops ", "5/30/2013", 5654, 5.44, 10.45),
	InventoryBook("POTATOES ", "234543", "Ronald ", "Roadss", "68/5/2018", 467, 4.777, 400.777)
};


InventoryBook ALLBOOKS[SIZE];

char filename[20] = "final.dat";
fstream invfile;

long int pos;
int main() {



	invfile.open(filename, ios::out | ios::binary);
	if (invfile.is_open()) {
		for (int i = 0; i < SIZE; i++) {
			invfile.write(reinterpret_cast<char*>(&OLDBOOKS[i]), sizeof(BookData));
		}
	}
	invfile.close();
	mainmenu();
}
int mainmenu() {
	int choice = 0;
	while (choice != 4) {
		cout << endl;
		cout << setw(50);
		cout << "Serendipity Booksellers " << endl;
		cout << setw(40);
		cout << "\tMain Menu\n\n";
		cout << setw(25);
		cout << " \t\t\t  1. Cashier Module\n";
		cout << setw(25);
		cout << " \t\t\t  2. Inventory Database Module\n";
		cout << setw(25);
		cout << " \t\t\t  3. Report Module\n";
		cout << setw(25);
		cout << " \t\t  4. Exit\n";
		cout << setw(25);
		cout << "\t\t\t  Enter your choice : ";
		cin >> choice;
		cout << endl;

		checkRange(&choice, 1, 4);


		switch (choice) {
		case 1:
			cout << setw(25);
			cashier();
			break;
		case 2:
			cout << setw(25);
			invmenu();
			break;
		case 3:
			cout << setw(25);
			reports();
			break;

		case 4:
			cout << setw(25);


			exit(0);
			break;

		default:
			exit(0);


		}

	}
}




void invmenu() {
	int choice = 0;
	do {
		cout << setw(50);
		cout << "Serendipity Booksellers\n";
		cout << setw(47);
		cout << "Inventiry Database\n\n";

		cout << "\t\t\t 1. Look Up a Book\n";

		cout << "\t\t\t 2. Add a Book\n";

		cout << "\t\t\t 3. Edit a book\n";

		cout << "\t\t\t 4. Delete a book\n";

		cout << "\t\t\t 5. Return to the Main Menu\n";

		cout << "\t\t\t Enter your choice : ";
		cin >> choice;
		cout << endl;

		checkRange(&choice, 1, 5);


		cout << endl;
		switch (choice) {
		case 1:
			cout << setw(24);
			lookUpBook();
			break;
		case 2:
			cout << setw(24);
			addBook();
			break;
		case 3:
			cout << setw(24);
			editBook();
			break;

		case 4:
			cout << setw(24);
			deleteBook();
			break;

		case 5:
			cout << setw(24);
			cout << "\t\t\t You Selected Item 5\n";
			mainmenu();
			break;

		default:
			mainmenu();



		}


	} while (choice != 5);



}


void reports() {
	int choice = 0;

	invfile.open(filename, ios::in | ios::binary);
	if (invfile.is_open()) {
		int counter = 0;
		while (!invfile.eof() && counter < SIZE) {
			invfile.read(reinterpret_cast<char*>(&ALLBOOKS[counter]), sizeof(InventoryBook));
			counter++;
		}
		invfile.close();
	}



	/*for (int i = 0; i < SIZE; i++) {
		strUpper(ALLBOOKS[i].bookTitle);
		strUpper(ALLBOOKS[i].author);
		strUpper(ALLBOOKS[i].isbn);
		strUpper(ALLBOOKS[i].publisher);
	}*/

	cout << endl;
	cout << setw(50);
	cout << "Serendipity Booksellers\n";
	cout << setw(43);
	cout << "Reports\n\n";


	cout << "\t\t\t 1. Inventory Listing\n";

	cout << "\t\t\t 2. Inventory Wholesale Value\n";

	cout << "\t\t\t 3. Inventory Retail Value\n";

	cout << "\t\t\t 4. Listing By Quantity\n";

	cout << "\t\t\t 5. Listing By Cost\n";

	cout << "\t\t\t 6. Listing By Age\n";

	cout << "\t\t\t 7. Return to Main Menu\n\n";

	cout << "\t\t\t Enter your choice : ";
	cin >> choice;
	//cout << endl;

	checkRange(&choice, 1, 7);

	cout << endl;
	if (choice == 1) {
		cout << setw(24);
		repListing();
	}
	else if (choice == 2) {
		cout << setw(24);
		repWholesale();
	}
	else if (choice == 3) {
		cout << setw(24);
		repRetail();
	}

	else if (choice == 4) {
		cout << setw(24);
		repQty();
	}

	else if (choice == 5) {
		cout << setw(24);
		repCost();
	}

	else if (choice == 6) {
		cout << setw(24);
		repAge();
	}

	else if (choice = 7) {
		cout << setw(24);
		cout << "\t\t\t You Selected Item 7\n";
		mainmenu();
	}

	else {
		mainmenu();



	}







}

void bookinfo(InventoryBook i) {
	cout << setw(50);
	cout << "Serendipity Booksellers\n";
	cout << setw(47);
	cout << "Book Informantion\n\n";
	cout << "\t\t\t ISBN: " << i.getISBN() << endl;
	cout << "\t\t\t Title: " << i.getTitle() << endl;
	cout << "\t\t\t Author: " << i.getAuthor() << endl;
	cout << "\t\t\t Publisher: " << i.getPub() << endl;
	cout << "\t\t\t Quantity on Hand: " << i.getQty() << endl;
	cout << "\t\t\t Wholesale Cost: " << i.getWholesale() << endl;
	cout << "\t\t\t Retail Price: " << i.getRetail() << endl << endl;
}

void cashier() {
	string date;
	int quant;
	int new_quant;
	int quant_tot = 0;;
	int price_tot = 0;;
	char  ISBN[14] = ("");
	string title;
	double price;
	char choice = 'y';
	double total = 0;
	int contPrice;
	char choice2;
	cin.ignore();
	InventoryBook f_cashier;
	cout << "\tSerendipity Book Sellers\n";
	cout << "\tCashier Module\n\n";
	cout << "\tDate: ";
	getline(cin, date);

	invfile.open(filename, ios::in | ios::binary);
	while (choice == 'y' || choice == 'Y') {
		if (invfile.is_open()) {
			cout << "\tEnter the book's ISBN : ";
			getChar(ISBN, 14);
			for (int i = 0; i < 20 && !invfile.eof(); i++) {
				pos = invfile.tellg();
				invfile.read(reinterpret_cast<char*>(&f_cashier), sizeof(InventoryBook));

				if ((strcmp(f_cashier.getISBN(), ISBN)) == 0) {
					invfile.close();
					cout << endl << "\t Title : " << f_cashier.getTitle() << endl;
					cout << "\t Price : $" << f_cashier.getRetail() << endl;
					cout << "\t Enter the Quantity : ";
					intputnumber(&quant);
					cout << endl;
					if (quant <= f_cashier.getQty()) {
						new_quant = f_cashier.getQty() - quant;
						f_cashier.setQty(new_quant);

						f_cashier.saveToFile(f_cashier, pos);
					}
					else if (quant > f_cashier.getQty()) {
						quant = 0;
						title = "";
						cout << "\tThere are not enough copies of " << f_cashier.getTitle() << " available \n";

					}
					cout << "\tWould you like to buy another book , if so senter Y for yes and N for no  :";
					cin >> choice;
					if (choice == 'y' || choice == 'Y')
						invfile.open(filename, ios::in | ios::binary);

					cout << endl << endl;
					//if (choice == 'y' || choice == 'Y') {
					price_tot += f_cashier.getRetail();
					quant_tot += quant;
					title = f_cashier.getTitle();
					total += (quant * f_cashier.getRetail());
					if (choice == 'y' || choice == 'Y') {
						cin.ignore();
						break;
					}
					else
						i = 20;
				}
				if ((strcmp(f_cashier.getISBN(), ISBN)) != 0 && i == 19) {
					cout << "\n\tWe cannot locate the ISBN you have entered, If you wish to try again  click y : ";
					cin >> choice2;
					if (choice2 == 'y' || choice2 == 'Y') {
						cin.ignore();
					}
					else {
						choice = 'n';
					}
				}
			}
		}
		else {
			cout << "\tFailed to open file  :";
		}

	}
	cout << "\tSerendipity Book Sellers\n\n";
	cout << "\tDate: " << date << endl << endl;
	cout << "\t Quantity \t\t\t ISBN number \t\t\t Title \t\t\t Price \t\t\t Total  \n";
	cout << "\t----------------------------------------------------------------------------------------------------------------------------\n";
	//cout << "\t" << date << "  \t" << quant << "    \t" << isbn << "  " << title << "\t\t" << price << "\t" << quant * price << "\n\n";
	cout << "\t" << quant_tot;
	cout << " \t\t\t\t " << ISBN;
	cout << " \t\t\t " << title;
	cout << " \t\t\t " << price_tot;
	cout << " \t\t\t $" << total;
	cout << endl;
	cout << "\n\tSubtotal : \t\t$" << total << endl;
	double tax = 0.06 * (total);
	cout << setprecision(2) << fixed;
	cout << "\tTax : \t\t\t$" << tax << endl;
	cout << setprecision(2) << fixed;
	cout << "\tTotal :\t\t\t$" << tax + total << endl << endl;
	cout << "\tThanks for Shopping at Serendipity !\n\n";
	//saveAllChanges();
}

void lookUpBook() {
	char choice;
	char  part[51];
	char* partPtr;
	InventoryBook f_lookUpBook;
	cout << "\t\t\t You selected Look Up Book.\n\n";
	cout << "\t\t\t What is part of the title of the book you would like to find : ";
	cin.ignore();
	getChar(part, 5);
	invfile.open(filename, ios::in | ios::binary);
	if (invfile.is_open()) {
		for (int i = 0; i < 20 && !invfile.eof(); i++) {
			invfile.read(reinterpret_cast<char*>(&f_lookUpBook), sizeof(BookData));

			if (f_lookUpBook.bookMatch(f_lookUpBook, part) == true) {
				cout << endl;
				cout << "\t\t\t Is " << f_lookUpBook.getTitle() << " the book you were looking for , if so enter y for yes : ";
				cin >> choice;
				if (choice == 'y' || choice == 'Y') {
					invfile.close();
					bookinfo(f_lookUpBook);
					return;
				}

			}

			if (f_lookUpBook.bookMatch(f_lookUpBook, part) == true && i == 19) {
				cout << "\n\t\t\t The book you are trying to find is not in the inventory \n\n";
				break;
			}
		}

	}
	else {
		cout << "Failed to open file\n";
	}

}
void addBook() {
	int q;
	double r, w;
	InventoryBook f_addBook;
	char new_title[51];
	char  new_isbn[14];
	char  new_author[31];
	char  new_publisher[14];
	char  new_dateAdded[31];
	int qty;
	double wholesale;
	double retail;


	cout << "\t\t\t You selected Add Book.\n\n";
	invfile.open(filename, ios::in | ios::binary);
	if (invfile.is_open()) {

		for (int i = 0; (i < 20 && !invfile.eof()); i++) {
			pos = invfile.tellg();
			invfile.read(reinterpret_cast<char*>(&f_addBook), sizeof(BookData));
			q = f_addBook.isEmpty(f_addBook);

			if (q == 1) {
				invfile.close();
				cin.ignore();
				cout << "\t\t\t Book Title : ";
				getChar(new_title, 51);
				f_addBook.setTitle(new_title);

				cout << "\t\t\t ISBN  number: ";
				getChar(new_isbn, 14);
				f_addBook.setISBN(new_isbn);

				cout << "\t\t\t Author's name : ";
				getChar(new_author, 31);
				f_addBook.setAuthor(new_author);

				cout << "\t\t\t Publisher's name : ";
				getChar(new_publisher, 31);
				f_addBook.setPub(new_publisher);

				cout << "\t\t\t Date Added  : ";
				getChar(new_publisher, 31);
				f_addBook.setDateAdded(new_publisher);

				cout << "\t\t\t Quantity  : ";
				cin >> qty;
				f_addBook.setQty(qty);

				cout << "\t\t\t Wholesale price: ";
				cin >> wholesale;
				f_addBook.setWholesale(wholesale);

				cout << "\t\t\t Retail price: ";
				cin >> retail;
				f_addBook.setRetail(retail);
				cout << endl;

				f_addBook.saveToFile(f_addBook, pos);


				return;
			}
			else if (i == 19 && q == 0) {
				cout << "\n\t\t\t No more Books can be added into this iventory \n\n";
				return;
			}


		}
	}

	else {

		cout << "\n\t\t\t Failed to open file \n\n";
	}




}

void editBook() {
	char book[51];
	char choice2;
	char* bookPtr;
	int choice;
	InventoryBook f_editBook;
	char new_title[51];
	char  new_isbn[14];
	char  new_author[31];
	char  new_publisher[14];
	char  new_dateAdded[31];
	int qty;
	double wholesale;
	double retail;

	cout << "\t\t\t You selected Edit Book.\n\n";
	cout << "\t\t\t What is part of title of the book you would like to edit : ";
	cin.ignore();
	getChar(book, 51);
	cout << endl;

	invfile.open(filename, ios::in | ios::binary);
	if (invfile.is_open()) {

		for (int i = 0; i < 20 && !(invfile.eof()); i++) {

			pos = invfile.tellg();
			invfile.read(reinterpret_cast<char*>(&f_editBook), sizeof(BookData));

			if (f_editBook.bookMatch(f_editBook, book) == true) {
				cout << endl;
				cout << "\t\t\t Is " << f_editBook.getTitle() << " the book you wanted to edit , if so enter y for yes : ";
				cin >> choice2;
				if (choice2 == 'y' || choice2 == 'Y') {
					invfile.close();
					cout << endl;
					bookinfo(f_editBook);
					cout << "\t\t\t What would you like to change  \n\n";
					cout << "\t\t\t  1) Book Title : \n";
					cout << "\t\t\t  2) ISBN  number: \n";
					cout << "\t\t\t  3) Author's name : \n";
					cout << "\t\t\t  4) Publisher's name : \n";
					cout << "\t\t\t  5) The date the book was added to the inventory  : \n";
					cout << "\t\t\t  6) The quantity of the book being added  : \n";
					cout << "\t\t\t  7) The wholesale cost of the book : \n";
					cout << "\t\t\t  8) The retail price of the book : \n\n";
					cout << "\t\t\t  Enter the number respective to your choice :";
					cin >> choice;
					cout << endl;

					checkRange(&choice, 1, 9);
					cin.ignore();
					if (choice == 1) {
						cout << "\t\t\t Enter the new name you would like to change to :";
						getChar(new_title, 51);
						f_editBook.setTitle(new_title);
					}
					else if (choice == 2) {
						cout << "\t\t\t Enter the new ISBN you would like to change to :";
						getChar(new_isbn, 14);
						f_editBook.setISBN(new_isbn);
					}
					else if (choice == 3) {
						cout << "\t\t\t Enter the new Author name you would like to change to :";
						getChar(new_author, 31);
						f_editBook.setAuthor(new_author);
					}

					else if (choice == 4) {
						cout << "\t\t\t Enter the new Publisher name you would like to change to :";
						getChar(new_publisher, 31);
						f_editBook.setPub(new_publisher);
					}
					else if (choice == 5) {
						cout << "\t\t\t Enter the new date you would you like to change to :";
						getChar(new_publisher, 31);
						f_editBook.setDateAdded(new_publisher);
					}

					else if (choice == 6) {
						cout << "\t\t\t Enter the new quantity would you like to change to :";
						cin >> qty;
						f_editBook.setQty(qty);
					}
					else if (choice == 7) {
						cout << "\t\t\t Enter the new wholesale price you would like to change to :";
						cin >> wholesale;
						f_editBook.setWholesale(wholesale);
					}

					else if (choice == 8) {
						cout << "\t\t\t Enter the new retail price you would like to change to :";
						cin >> retail;
						f_editBook.setRetail(retail);
					}

					f_editBook.saveToFile(f_editBook, pos);

					return;

				}



			}
			else if (f_editBook.bookMatch(f_editBook, book) == false && i == 19) {
				cout << "\n\t\t\t The book you are trying to find is not in the inventory \n\n";
				break;
			}

		}
	}



}
void deleteBook() {
	char book[51];
	char choice2;
	char* bookPtr;
	char choice;
	InventoryBook f_deleteBook;
	cout << "\t\t\t You selected Delete Book.\n\n";
	cout << "\t\t\t What is the title of the book you would like to delete : ";
	cin.ignore();
	getChar(book, 51);

	invfile.open(filename, ios::in | ios::binary);
	if (invfile.is_open()) {
		for (int i = 0; i < 20 && !invfile.eof(); i++) {
			pos = invfile.tellg();
			invfile.read(reinterpret_cast<char*>(&f_deleteBook), sizeof(BookData));


			if (f_deleteBook.bookMatch(f_deleteBook, book) == true) {
				cout << endl;
				cout << "\t\t\t Is " << f_deleteBook.getTitle() << " the book you wanted to delete , if so enter y for yes : ";
				cin >> choice2;
				if (choice2 == 'y' || choice2 == 'Y') {
					invfile.close();
					cout << endl;
					bookinfo(f_deleteBook);
					cout << "\t\t\t Are you sure you would like to delete all this book's information \n";
					cout << "\t\t\t Enter 'y' for yes and 'n' for no  : ";
					cin >> choice;
					if (choice == 'y' || choice == 'Y') {

						cout << endl;
						f_deleteBook.removeBook(f_deleteBook, pos);

						return;

					}
					else {
						break;
					}
				}

			}
			else if (f_deleteBook.bookMatch(f_deleteBook, book) == false && i == 19) {
				cout << "\n\t\t\t The book you are trying to find is not in the inventory \n\n";
				break;
			}




		}
	}
	//saveAllChanges();
}


void repListing() {
	char key;
	cout << "\t\t\t You selected Inventory Listing.\n\n";
	cout << "\t          Title \t\t\t ISBN number \t\t\t Author \t\t\t\t Publisher \n";
	for (int i = 0; i < 20; i++) {
		if (strlen(ALLBOOKS[i].getTitle()) > 0) {
			cout << "\t" << i + 1 << "        " << ALLBOOKS[i].getTitle();
			cout << " \t\t\t " << ALLBOOKS[i].getISBN();
			cout << " \t\t\t " << ALLBOOKS[i].getAuthor();
			cout << " \t\t\t\t " << ALLBOOKS[i].getPub();
			cout << endl;
		}

		else {
			continue;
		}

	}
	cout << endl;
	cout << "\t\t Date Added \t\t\t Quantity  \t\t\t Wholesale cost \t\t\t Retail price \n";
	for (int i = 0; i < 20; i++) {
		if (strlen(ALLBOOKS[i].getTitle()) > 0) {
			cout << "\t" << i + 1 << "        " << ALLBOOKS[i].getDateAdded();
			cout << " \t\t\t " << ALLBOOKS[i].getQty();
			cout << "  \t\t\t\t " << ALLBOOKS[i].getWholesale();
			cout << " \t\t\t\t\t " << ALLBOOKS[i].getRetail();
			cout << endl;
		}

		else {
			continue;
		}


	}
	cout << endl;
	cout << "\t\t Enter a key to continue to the next screen ";
	cin >> key;
}
void repWholesale() {
	char key;
	double totalWSV;
	double totalWS = 0;
	double totalQ = 0;
	cout << "\t\t\t You selected Inventory Wholesale Value.\n\n";
	cout << "\t\t Title \t\t\t\t ISBN number \t\t\t Quantity \t\t\t\ Whole sale price \n";
	for (int i = 0; i < 20; i++) {
		if (strlen(ALLBOOKS[i].getTitle()) > 0) {
			cout << "\t" << i + 1 << "        " << ALLBOOKS[i].getTitle();
			cout << " \t\t\t " << ALLBOOKS[i].getISBN();
			cout << " \t\t\t " << ALLBOOKS[i].getQty();
			cout << " \t\t\t\t " << ALLBOOKS[i].getWholesale();
			totalWS += ALLBOOKS[i].getWholesale();
			totalQ += ALLBOOKS[i].getQty();
			cout << endl;
		}

		else {
			continue;
		}

	}
	cout << endl;
	cout << "\t\t Enter a key to continue to the next screen ";
	cin >> key;
	cout << endl;
	cout << "\t\t The total wholesale value of the inventorty is $  " << totalWS * totalQ << endl << endl;

}
void repRetail() {
	char key;
	double totalRSV;
	double totalRS = 0;
	double totalQ = 0;
	cout << "\t\t\t You selected Inventory Retail Value.\n\n";
	cout << "\t\t Title \t\t\t ISBN number \t\t\t Quantity \t\t\t\ Retail Price \n";
	for (int i = 0; i < 20; i++) {
		if (strlen(ALLBOOKS[i].getTitle()) > 0) {
			cout << "\t" << i + 1 << "        " << ALLBOOKS[i].getTitle();
			cout << " \t\t " << ALLBOOKS[i].getISBN();
			cout << " \t\t\t " << ALLBOOKS[i].getQty();
			cout << " \t\t\t\t " << ALLBOOKS[i].getRetail();
			totalRS += ALLBOOKS[i].getRetail();
			totalQ += ALLBOOKS[i].getQty();
			cout << endl;
		}

		else {
			continue;
		}

	}
	cout << endl;
	cout << "\t\t Enter a key to continue to the next screen ";
	cin >> key;
	cout << endl;
	totalRSV = totalRS * totalQ;
	cout << "\t\t The total wholesale value of the inventorty is $  " << totalRSV << endl << endl;
}
void repQty() {
	char key;
	int qty[20];
	int* QTy[SIZE];
	InventoryBook* f_repQty[20];
	InventoryBook* temp;
	for (int x = 0; x < SIZE; x++) {
		f_repQty[x] = &ALLBOOKS[x];
	}

	cout << "\t\t\t You selected Listing By Quantity\n\n";
	int max;


	for (int i = 0; i < SIZE; i++)
	{
		max = i;


		for (int c = i + 1; c < SIZE; c++) {

			if ((*f_repQty[c]).getQty() > ((*f_repQty[max]).getQty())) {
				temp = f_repQty[max];
				f_repQty[max] = f_repQty[c];
				f_repQty[c] = temp;

			}

		}
		f_repQty[i] = f_repQty[max];

	}
	cout << "\t\t Title \t\t\t ISBN number \t\t\t Quantity on Hand \n";
	for (int i = 0; i < 20; i++) {
		if (strlen((*f_repQty[i]).getTitle()) > 0) {
			cout << "\t" << i + 1 << "        " << (*f_repQty[i]).getTitle();
			cout << " \t\t " << (*f_repQty[i]).getISBN();
			cout << " \t\t\t " << (*f_repQty[i]).getQty();


			cout << endl;
		}

		else {
			continue;
		}

	}
	cout << endl;
	cout << "\t\t Enter a key to continue to the next screen ";
	cin >> key;
	cout << endl;
}
void repCost() {
	char key;
	double wsc;
	double* WSc[SIZE];
	InventoryBook* f_wholesale[20];
	InventoryBook* temp;
	for (int x = 0; x < SIZE; x++) {
		f_wholesale[x] = &ALLBOOKS[x];
	}
	cout << "\t\t\t You selected Listing By Cost\n\n";


	int max;


	for (int i = 0; i < SIZE - 1; i++)
	{
		max = i;


		for (int c = i + 1; c < SIZE; c++) {

			if ((*f_wholesale[c]).getWholesale() > ((*f_wholesale[max]).getWholesale())) {
				temp = f_wholesale[max];
				f_wholesale[max] = f_wholesale[c];
				f_wholesale[c] = temp;

			}

		}
		f_wholesale[i] = f_wholesale[max];

	}
	cout << "\t\t Title \t\t\t\t ISBN number \t\t\t Quantity \t\t\t Wholesale Cost \n";
	for (int i = 0; i < 20; i++) {
		if (strlen((*f_wholesale[i]).getTitle()) > 0) {
			cout << "\t" << i + 1 << "        " << (*f_wholesale[i]).getTitle();
			cout << " \t\t\t " << (*f_wholesale[i]).getISBN();
			cout << " \t\t\t " << (*f_wholesale[i]).getQty();
			cout << " \t\t\t\t " << (*f_wholesale[i]).getWholesale();
			cout << endl;
		}

		else {
			continue;
		}

	}
	cout << endl;
	cout << "\t\t Enter a key to continue to the next screen ";
	cin >> key;
	cout << endl;

}
void repAge() {
	char key;
	char* Dt[SIZE];
	InventoryBook* f_repAge[20];
	InventoryBook* temp;
	for (int x = 0; x < SIZE; x++) {
		f_repAge[x] = &ALLBOOKS[x];
	}
	int max;

	for (int i = 0; i < SIZE - 1; i++)
	{
		max = i;


		for (int c = i + 1; c < SIZE; c++) {

			if ((*f_repAge[c]).getDateAdded() > ((*f_repAge[max]).getDateAdded())) {
				temp = f_repAge[max];
				f_repAge[max] = f_repAge[c];
				f_repAge[c] = temp;
			}

		}
		f_repAge[i] = f_repAge[max];

	}

	cout << "\t\t\t You selected Listing By Age \n\n";
	cout << "\t\t Title \t\t\t ISBN number \t\t\t Quantity \t\t\t Date Added \n";
	for (int i = 0; i < 20; i++) {
		if (strlen((*f_repAge[i]).getTitle()) > 0) {
			cout << "\t" << i + 1 << "        " << (*f_repAge[i]).getTitle();
			cout << " \t\t " << (*f_repAge[i]).getISBN();
			cout << " \t\t\t " << (*f_repAge[i]).getQty();
			cout << " \t\t\t\t " << (*f_repAge[i]).getDateAdded();
			cout << endl;
		}

		else {
			continue;
		}

	}
	cout << endl;
	cout << "\t\t Enter a key to continue to the next screen ";
	cin >> key;
	cout << endl;
}

void swap(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void swapint(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void swapdouble(double& x, double& y) {
	double temp = x;
	x = y;
	y = temp;
}
void swapchar(char* x, char* y) {
	char temp[51];
	strcpy(temp, x);
	strcpy(x, y);
	strcpy(y, temp);
}
void  strUpper(char* x) {
	for (int i = 0; i < strlen(x); i++) {
		x[i] = toupper(x[i]);

	}
}
void getChar(char x[], int r) {
	cin.getline(x, r);
	strUpper(x);
}

int checkRange(int* choice, int min, int max) {
	while (*choice < min || *choice> max) {
		cout << "\t\t\t Please enter a number in the range " << min << "-" << max << "  : ";
		cin >> *choice;

	}
	return *choice;
}

int  intputnumber(int* choice) {
	cin >> *choice;
	while (*choice < 0) {
		cout << "\t Please enter a number greater than 0  :";
		cin >> *choice;

	}
	return *choice;
}




InventoryBook::InventoryBook()
{
	strcpy(bookTitle, "\0");
}

void BookData::setTitle(const char* newBookTitle)
{
	strcpy(bookTitle, newBookTitle);
}

void BookData::setISBN(const char* newISBN)
{
	strcpy(isbn, newISBN);
}
void BookData::setAuthor(const char* newAuthor)
{
	strcpy(author, newAuthor);
}
void BookData::setPub(const char* newPublisher)
{
	strcpy(publisher, newPublisher);
}

void InventoryBook::setDateAdded(const char* newDateAdded)
{
	strcpy(dateAdded, newDateAdded);
}
void InventoryBook::setQty(int newQuanityOnHand)
{
	qtyOnHand = newQuanityOnHand;
}
void InventoryBook::setRetail(double newRetail)
{
	retail = newRetail;
}
void InventoryBook::setWholesale(double newWholesale)
{
	wholesale = newWholesale;
}

char* InventoryBook::getTitle()
{
	return bookTitle;
}

char* InventoryBook::getISBN()
{
	return isbn;
}

char* InventoryBook::getAuthor()
{
	return author;
}

char* InventoryBook::getPub()
{
	return publisher;
}

char* InventoryBook::getDateAdded()
{
	return dateAdded;
}

int InventoryBook::getQty()
{
	return qtyOnHand;
}

double InventoryBook::getWholesale()
{
	return wholesale;
}

double InventoryBook::getRetail()
{
	return retail;
}

int InventoryBook::isEmpty(InventoryBook book)
{
	int s;
	if (strcmp(book.getTitle(), "\0") == 0)
	{
		s = 1;	// true
	}
	else
	{
		s = 0;	// false
	}
	return s;
}

void InventoryBook::removeBook(InventoryBook k, int pos) {
	k.setTitle("\0");
	k.setISBN("\0");
	k.setAuthor("\0");
	k.setDateAdded("\0");
	k.setPub("\0");
	k.setQty(0);
	k.setWholesale(0);
	k.setRetail(0);

	invfile.open(filename, ios::out | ios::in | ios::binary);
	if (invfile.is_open()) {
		invfile.seekp(pos, ios::beg);
		invfile.write(reinterpret_cast<char*>(&k), sizeof(BookData));
		invfile.close();
	}

	return;
}

void InventoryBook::saveToFile(InventoryBook k, int s) {

	invfile.open(filename, ios::out | ios::in | ios::binary);
	if (invfile.is_open()) {
		invfile.seekp(s, ios::beg);
		invfile.write(reinterpret_cast<char*>(&k), sizeof(k));
		invfile.close();

	}
	else {
		cout << "\t\t\t File failed to open \n\n";
	}
}




InventoryBook::InventoryBook(const char* new_title, const char* new_isbn, const char* new_author, const char* new_publisher, const char* new_dateAdded, int new_qty, double new_wholesale, double new_retail) {
	strcpy(this->bookTitle, new_title);
	strcpy(this->isbn, new_isbn);
	strcpy(this->author, new_author);
	strcpy(this->publisher, new_publisher);
	strcpy(this->dateAdded, new_dateAdded);
	this->qtyOnHand = new_qty;
	this->wholesale = new_wholesale;
	this->retail = new_retail;

}

bool InventoryBook::bookMatch(InventoryBook k, char* x) {
	char* Bookptr;
	Bookptr = strstr(k.getTitle(), x);
	if (Bookptr != 0) {
		return true;
	}
	else {
		return false;
	}
}