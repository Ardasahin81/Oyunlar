
int satir=25;
int sutun=70;

int ekran[25][70];
int tus;
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include "fonksiyonlar/fakeconio.h"
#include "fonksiyonlar/ozelk.h"
#include "fonksiyonlar/yazdir.h"
#include "fonksiyonlar/stringyaz.h"
#include "fonksiyonlar/tusal.h"
#include "oyunbasliklari/snake.h"
#include "oyunbasliklari/ttt.h"
#include "oyunbasliklari/minesweeper.h"

void bostanitim() {
		
	int i,j;
	
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			ekran[i][j]=0;
		}
	}
	
	ekran[0][0]=504;
	ekran[0][sutun-1]=502;
	ekran[satir-1][0]=505;
	ekran[satir-1][sutun-1]=503;
	
	for(i=1;i<satir-1;i++) {
		ekran[i][0]=ekran[i][sutun-1]=501;
	}
	
	for(i=1;i<sutun-1;i++) {
		ekran[0][i]=ekran[satir-1][i]=500;
	}
	
	ekran[5][27]=604;
	ekran[5][61]=602;
	ekran[21][27]=605;
	ekran[21][61]=603;
	
	for(i=6;i<21;i++) {
		ekran[i][27]=ekran[i][61]=601;
	}
	
	for(i=28;i<61;i++) {
		ekran[5][i]=ekran[21][i]=600;
	}
	
	ekran[8][5]=ekran[9][4]=ekran[10][3]=ekran[11][2]=ekran[12][67]=ekran[13][66]=ekran[14][65]=ekran[15][64]=541;
	ekran[8][64]=ekran[9][65]=ekran[10][66]=ekran[11][67]=ekran[12][2]=ekran[13][3]=ekran[14][4]=ekran[15][5]=542;
}


void snaketanitim() {
	
	bostanitim();
	
	syaz("Snake",5,14);
	syaz("xxxxx       ",11,11);
	syaz("x",12,15);
	syaz("x",13,15);
	syaz("xxxx  *",14,15);
	
	syaz("Klasik yılan oyunu.    ",8,30);
	syaz("Yön tuşlarıyla oynanır, ",10,30);
	syaz("'p' tuşu oyunu durdurur.",11,29);
	syaz("ENTER: Oyna    ESC: Oyundan Çık",16,29);
	
	
}

void tictactoetanitim() {
	
	bostanitim();
	
	syaz("Tic Tac Toe",5,10);
	
	int i;
	
	for(i=9;i<20;i++) {
		ekran[i][13]=ekran[i][17]=601;
	}
	for(i=10;i<21;i++) {
		ekran[12][i]=ekran[16][i]=600;
	}
	ekran[12][13]=ekran[12][17]=ekran[16][13]=ekran[16][17]=607;
	
	syaz("X",14,15);
	syaz("X",18,11);
	syaz("O",10,19);
	syaz("O",18,19);
	
	
	syaz("  İki kişi veya bilgisayara      ",7,28);
	syaz(" karşı oynanabilen zeka oyunudur.",8,28);
	syaz("  Kendi harfini 3 tane yan yana, ",10,28);
	syaz(" üst üste veya çapraz koyabilen  ",11,28);
	syaz(" eli kazanır.                ",12,28);
	syaz("  Oyun rakam tuşları ile oynanır.",14,28);
	syaz(" (Oyun içinde kılavuz var.)      ",15,28);
	syaz(" ENTER: Oyna   ESC: Oyundan Çık  ",18,28);
	
}

void mayintarlasitanitim() {
	
	bostanitim();
	
	syaz("Mayın Tarlası",5,9);
	
	syaz("1 1 2 2",10,10);
	syaz("1",12,10);
	syaz("2",14,10);
	syaz("3",12,14);
	
	ekran[12][12]=ekran[12][16]=813;
	
	ekran[11][11]=ekran[11][15]=604;
	
	ekran[11][13]=602;
	
	ekran[11][12]=ekran[11][16]=600;
	
	int i;
	
	for(i=12;i<17;i+=2) {
		ekran[13][i]=ekran[15][i]=600;
		ekran[13][i+1]=ekran[15][i+1]=607;
	}
	
	for(i=11;i<18;i+=2) {
		ekran[12][i]=ekran[14][i]=601;
	}
	ekran[11][17]=606;
	ekran[13][11]=ekran[15][11]=610;
	
	syaz("  Her bir rakam, etrafındaki     ",6,28);
	syaz(" kutularda bulunan toplam mayın  ",7,28);
	syaz(" sayısını belirtir.              ",8,28);
	syaz("  Kutu açmak için boşluk tuşunu, ",10,28);
	syaz(" tespit ettiğiniz mayınların     ",11,28);
	syaz(" yerini işaretlemek için 'b'     ",12,28);
	syaz(" tuşunu kullanınız.              ",13,28);
	syaz("  Eğer rakamın etrafındaki bütün ",15,28);
	syaz(" mayınlar tespit edilmişse raka- ",16,28);
	syaz(" mın üzerinde boşluk tuşuna basa-",17,28);
	syaz(" rak kalan kutuları açabilirsiniz",18,28);
	syaz("  ENTER: Oyna   ESC: Oyundan Çık ",20,28);
	
		
}


void oyunsec() {
	int menu=1,oyunsayisi=3;
	
	while(1) {
		if(menu==0) menu=oyunsayisi;
		
		if(menu==1) {
			snaketanitim();
		} else if(menu==2) {
			tictactoetanitim();
		} else if(menu==3) {
			mayintarlasitanitim();
		}
		
		yazdir();
		
		tus=tusal();
		
		if(tus==743) {
			menu=((menu+1)%oyunsayisi);
		} else if(tus==744) {
			menu=((menu-1)%oyunsayisi);
		} else if(tus==770) {
			exit(1);
		} else if(tus==778) {
			if(menu==1) {
				yilan();
			} else if(menu==2) {
				tictactoe();
			} else if(menu==3) {
				satir=12;
				sutun=34;
				mayin();
				satir=25;
				sutun=70;
			}
		}
		
		
	}
	
	
}


int main() {
	
	
	oyunsec();
	
	
	return 0;
}
