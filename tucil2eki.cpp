#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

/* Prosedur penukaran */
void swap (int *a, int *b)
{
  int temp;

  temp = *a;
  *a = *b;
  *b = temp;
}

/* Prosedur untuk generate array secara random */
void IsiArray(int a[], int n){
	int i;
	for (i=0; i<n; i++){
		a[i] = rand() %1000000 + 1;
	}
}

/* Prosedur pengurutan dengan Selection Sort */
void SelectionSort(int a[], int n) {
	int i, j;
	int min;
	for(i=0; i<n; i++){
		min = i;
		/* mencari nilai array terkecil untuk ditukar dengan a[i] */
		for (j=i+1; j<n; j++){
			if (a[j]<a[min]){
				min = j;
			}
		}
		swap(a[min], a[i]);
	}
}

/* Prosedur pengurutan dengan Insertion Sort */
void InsertionSort(int a[], int n){
	int i;
	int pass, temp;
	for(pass=1; pass<n; pass++){
		temp = a[pass];
		i = pass -1;
		/* penggeseran elemen array mulai dari indeks i ke indeks 
		di depannya selama temp < a[i] dan i > 1*/
		while((temp < a[i]) && (i>1)){
			a[i+1] = a[i];
			i--;
		}

		/* meletakkan elemen temp*/
		if (temp >= a[i]) 
			a[i+1] = temp;
		else{
			a[i+1] = a[i];
			a[i] = temp;
		}
	}
}

/* Prosedur pengurutan dengan Quick Sort */  
void QuickSort(int a[], int l, int r) {
   int i, j, pivot;
 	i = l;
 	j = r;
 	/* menentukan pivot, yang adalah elemen tengah array */
 	pivot = a[(l+r)/2];

   /* partisi */
   while (i <= j) {
      while (a[i] < pivot)
            i++;
      while (a[j] > pivot)
            j--;
      if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
      }
   }
 
   if (l < j)
         QuickSort(a, l, j);
   if (i < r)
         QuickSort(a, i, r);
}

/* Prosedur menggabungkan array a[kiri..tengah] dan a[tengah+1..kanan] */
/* yang masing-masing sudah terurut menjadi 1 array terurut */
/* Untuk Merge Sort */
void Merge(int a[], int kiri, int tengah, int kanan){
	static int b[1000000];
	int i, kidal1, kidal2;

	kidal1 = kiri;
	kidal2 = tengah+1;
	i = kiri;
	while((kidal1 <= tengah) && (kidal2 <= kanan)){
		if (a[kidal1] <= a[kidal2]){
			b[i] = a[kidal1];
			kidal1++;
		}
		else{
			b[i] = a[kidal2];
			kidal2++;
		}
		i++;
	}
	/* apabila semua elemen a[tengah+1..kanan]  sudah dimasukkan sedangkan
	   elemen a[kiri..tengah] belum dimasukkan semua, masukkan semua elemen
	   a[kiri..tengah] ke array b*/
	while(kidal1 <= tengah){
		b[i] = a[kidal1];
		kidal1++;
		i++;
	}
	/* apabila semua elemen a[kiri..tengah]  sudah dimasukkan sedangkan
	   elemen a[tengah+1..kanan]belum dimasukkan semua, masukkan semua elemen
	   a[tengah+1..kanan] ke array b*/
	while(kidal2 <= kanan){
		b[i] = a[kidal2];
		kidal2++;
		i++;
	}

	/* copy array b ke array a*/
	for (i=kiri; i<=kanan; i++){
		a[i] = b[i];
	}
} 

/* Prosedur pengurutan dengan Merge Sort */
void MergeSort (int a[], int l, int r){
	int x;
	
	if (l < r) {
		x = (l+r)/2;
		
		/* Bagi array menjadi 2 bagian */
		MergeSort(a, l, x);
		MergeSort(a, x+1, r);

		/* Gabungkan array */
		Merge(a, l, x, r);
	}
}

/* Prosedur untuk menulis array */
void TulisArray(int a[], int n){
	int i;
	for(i=0; i<n; i++){
		cout<<a[i]<<endl;
	}
}

int main (){
	static int a[1000000];
	
	clock_t tStart = clock();
	IsiArray(a, 1000);
	/* Saat dimulai penghitungan waktu eksekusi */
	

	//InsertionSort(a, 1000000);
	//SelectionSort(a, 1000000);
	//MergeSort(a, 0, 999999);
	QuickSort(a, 0, 999);
	TulisArray(a, 1000);
   cout<<"Waktu eksekusi : "<<(double)(clock() - tStart)/CLOCKS_PER_SEC<<" detik."<<endl;
	return 0;
}
