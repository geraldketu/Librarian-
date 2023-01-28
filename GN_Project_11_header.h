#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>



class BookData {
protected:
	char bookTitle[51];
	char isbn[14];
	char author[31];
	char publisher[31];
	

public:
	
	//setters
	void   setTitle(const char*);
	void   setISBN(const char*);
	void   setAuthor(const char*);
	void   setPub(const char*);
	

};


class InventoryBook :public BookData {
private:
	char dateAdded[11];
	int qtyOnHand;
	double wholesale;
	double retail;

public:
	InventoryBook();
	InventoryBook(const char* new_title, const char* new_isbn, const char* new_author, const char* new_publisher, const char* new_dateAdded, int new_qty, double new_wholesale, double new_retail);

	//setters
	void   setQty(int);
	void   setDateAdded(const char*);
	void   setWholesale(double);
	void   setRetail(double);
	bool bookMatch(InventoryBook k, char* x);
	int isEmpty(InventoryBook book);
	void removeBook(InventoryBook k, int pos);
	void saveToFile(InventoryBook k, int s);
	
	//getters
	char* getTitle();
	char* getISBN();
	char* getAuthor();
	char* getPub();
	char* getDateAdded();
	int    getQty();
	double getWholesale();
	double getRetail();
	//others 
	static void assign(InventoryBook& k, int position);

	//Other functions ;
	



};

class SoldBook :private InventoryBook {
private:
	static double taxRate;
	int qtySold;
	double tax;
	int subtotal;
	static int total;

};

int mainmenu();
void invmenu();
void reports();
void cashier();
void lookUpBook();
void addBook();
void editBook();
void deleteBook();
void repListing();
void repWholesale();
void repRetail();
void repQty();
void repCost();
void repAge();
void swapint(int& x, int& y);
void swapdouble(double& x, double& y);
void swapchar(char* x, char* y);
void selectionSort(int* array, int size);
void  strUpper(char* x);
void getChar(char x[], int r);
int  intputnumber(int* choice);
int checkRange(int* choice, int min, int max);
void swapISBN();
void swapTitle();
void swapDateAdded();
void swapQty();

#pragma once
#pragma once
#pragma once
#pragma once
