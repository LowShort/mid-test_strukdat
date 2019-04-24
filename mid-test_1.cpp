#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct SLL{
	char nama[20];
	char menu[20];
	int harga;
	int jumlah;
	SLL* next;
};

typedef SLL* pointer;
typedef pointer List;

void createList(List& First) {
	First = NULL;
}

void createElmt(pointer& pBaru) {
	pBaru = new SLL; 
	cout<<"Masukkan nama pembeli : "; cin.ignore();cin.getline(pBaru->nama,20);
	cout<<"Masukkan nama makanan : "; cin.getline(pBaru->menu,20);
	cout <<"Masukkan jumlah makanan : "; cin >> pBaru->jumlah;
	cout<<"Masukkan harga satuan : "; cin >> pBaru->harga;
	pBaru->next = NULL; 
}

void insertFirst(List& First, pointer pBaru) {
	if (First == NULL)
		First = pBaru;
	else {
		pBaru->next = First;
		First = pBaru;
	}
}

void traversal(List First) {
	pointer pBantu;
	int i = 1;
	if (First == NULL) {
		cout << "List kosong" << endl;
	}
	else {
		pBantu = First;
		do {
			cout<<"Nama pemesan : "<<pBantu->nama;
			cout<<setw(4)<<"No"<<setw(20)<<"Nama"<<setw(7)<<"Jumlah"<<setw(12)<<"Harga Satuan";
			cout<<setw(4)<<i<<setw(20)<<pBantu->menu<<setw(7)<<pBantu->jumlah<<setw(12)<<pBantu->harga;
			i++;
			pBantu = pBantu->next;
		} while (pBantu != NULL);
	}
}

/*void linearSearch(List First, char key, int& found, pointer& pCari) {
	found = 0;
	pCari = First;
	while (found == 0 && pCari != NULL)
	{
		if (pCari->info == key)
			found = 1;
		else
			pCari = pCari->next;
	}
}*/

int main() {
	pointer p, pCari;
	List meh;
	//int ketemu;
	int n;
	//char key = 'C';

	createList(meh);
	cout<<"Masukkan banyak jenis makanan : ";cin>>n;
	
	for (int i=0;i<=n;i++){
		createElmt(p);
		insertFirst(meh, p);
	}
	
	traversal(meh);

/*	cout << "Masukkan kunci pencarian : "; cin >> key; //B
	linearSearch(meh, key, ketemu, p);
	if (ketemu) {
		cout << " Ditemukan yang dicari " << endl;
		createElmt(p); //C
		insertAfter(meh, pCari, p); // Sisipkan C sesudah B
		traversal(meh); //A B C D
	}
	else {
		cout << " Tidak Ditemukan yang dicari " << endl;
	}
	
	linearSearch(meh, key, ketemu, pCari);
	if (ketemu) {
		cout << "Ditemukan dengan informasinya : " << p->info;
	}
	else {
		cout << "Tidak Ditemukan " << endl;
	}*/

	return 0;
}
