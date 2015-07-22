
#define versiyon "SNAKE v4"


void cerceveciz(void) { 
	int i;
	
	ekran[0][0]=504;
	ekran[0][sutun-1]=502;
	ekran[satir-1][0]=505;
	ekran[satir-1][sutun-1]=503;

	for(i=1;i<sutun-1;i++)
		ekran[0][i]=ekran[satir-1][i]=500;
	
	for(i=1;i<satir-1;i++)
		ekran[i][0]=ekran[i][sutun-1]=501;
	
}

int tusalsnake(void) {
	int i=1;
	int a[10]={ };
	
	a[0]=getch();
	while(kbhit() && i<2)
		a[i++]=getch();
	
	if(a[0]==224 && a[1]==72) //YUKARI
		return 741;
	else if(a[0]==224 && a[1]==80) //AŞAĞI
		return 742;
	else if(a[0]==224 && a[1]==77) //SAĞA
		return 743;
	else if(a[0]==224 && a[1]==75) //SOLA
		return 744;
	else if(a[0]==0 && a[1]==59) //F1
		return 751;
	else if(a[0]==0 && a[1]==60) //F2
		return 752;
	else if(a[0]==0 && a[1]==61) //F3
		return 753;
	else if(a[0]==0 && a[1]==62) //F4
		return 754;
	else if(a[0]==0 && a[1]==63) //F5
		return 755;
	else if(a[0]==0 && a[1]==64) //F6
		return 756;
	else if(a[0]==0 && a[1]==65) //F7
		return 757;
	else if(a[0]==0 && a[1]==66) //F8
		return 758;
	else if(a[0]==224 && a[1]==83) //DELETE
		return 772;
	else if(a[0]==224 && a[1]==73) //PAGE UP
		return 774;
	else if(a[0]==224 && a[1]==81) //PAGE DOWN
		return 775;
	else if(a[0]==224 && a[1]==71) //HOME
		return 776;
	else if(a[0]==224 && a[1]==79) //END
		return 777;
	else if(a[0]==8 || a[0]==127) //BACKSPACE
		return 773;
	else if(a[0]==9)//TAB
		return 771;
	else if(a[0]==27 && a[1]==0) //ESC
		return 770;
	else if(a[0]==-61 && a[1]==-89) //ç
		return 700;
	else if(a[0]==-60 && a[1]==-97) //ğ
		return 701;
	else if(a[0]==-60 && a[1]==-79) //ı
		return 702;
	else if(a[0]==-61 && a[1]==-74) //ö
		return 703;
	else if(a[0]==-59 && a[1]==-97) //ş
		return 704;
	else if(a[0]==-61 && a[1]==-68) //ü
		return 705;
	else if(a[0]==-61 && a[1]==-121) //Ç
		return 710;
	else if(a[0]==-60 && a[1]==-98) //Ğ
		return 711;
	else if(a[0]==-60 && a[1]==-80) //İ
		return 712;
	else if(a[0]==-61 && a[1]==-106) //Ö
		return 713;
	else if(a[0]==-59 && a[1]==-98) //Ş
		return 714;
	else if(a[0]==-61 && a[1]==-100) //Ü
		return 715;
	else if(a[0]<255)
		return a[0];
	return -1;
}

int yilan() {
	srand(time(NULL));
	int yemsatir=5,yemsutun=5;
	int yb=1;// Yılanın boyu
	int yilan[1680][2]= { };
	yilan[0][0]=10;
	yilan[0][1]=10;
	int i,j;
	int tus='p'; // Girilen tuş
	int otus='p'; //Önceki hamlede girilen tuş
	cerceveciz();
	ekran[satir-3][0]=510;
	ekran[satir-3][sutun-1]=509;
	
	for(i=1;i<sutun-1;i++)
		ekran[satir-3][i]=500;
	syaz(versiyon,satir-2,3);
	syaz("Skor: ",satir-2,sutun-13);
	char skor[5]={ };
	while(1) {
		
		int msec = 0;
		clock_t before = clock(),difference;
		do {
		  difference = clock() - before;
		  msec = difference * 1000 / CLOCKS_PER_SEC;
		} while ( msec < 80 );
		
		for(i=1;i<satir-3;i++) {
			for(j=1;j<sutun-1;j++) {
				ekran[i][j]=0;
			}
		}
		
		ekran[yemsatir][yemsutun]='*';
		
		for(i=0;i<yb;i++) {
			if(yilan[i+1][0]==yilan[i][0]-1 && yilan[i-1][0] == yilan[i][0]+1) {
				ekran[yilan[i][0]][yilan[i][1]]=601; // ust alt
			}else if(yilan[i+1][0]==yilan[i][0]+1 && yilan[i-1][0] == yilan[i][0]-1) {
				ekran[yilan[i][0]][yilan[i][1]]=601; // ust alt
			}
			if(yilan[i+1][0]==yilan[i][0]-1 && yilan[i-1][1]==yilan[i][1]+1) {
				ekran[yilan[i][0]][yilan[i][1]]=605; // ust sag
			} else if(yilan[i-1][0]==yilan[i][0]-1 && yilan[i+1][1]==yilan[i][1]+1) {
				ekran[yilan[i][0]][yilan[i][1]]=605; // ust sag
			}
			if(yilan[i-1][0]==yilan[i][0]-1 && yilan[i+1][1]==yilan[i][1]-1) {
				ekran[yilan[i][0]][yilan[i][1]]=603; // ust sol
			} else if(yilan[i-1][1]==yilan[i][1]-1 && yilan[i+1][0]==yilan[i][0]-1) {
				ekran[yilan[i][0]][yilan[i][1]]=603; // ust sol
			}
			if(yilan[i-1][1]==yilan[i][1]-1 && yilan[i+1][0]==yilan[i][0]+1) {
				ekran[yilan[i][0]][yilan[i][1]]=602; // alt sol
			} else if(yilan[i+1][1]==yilan[i][1]-1 && yilan[i-1][0]==yilan[i][0]+1) {
				ekran[yilan[i][0]][yilan[i][1]]=602; // alt sol
			}
			if(yilan[i-1][0]==yilan[i][0]+1 && yilan[i+1][1]==yilan[i][1]+1) {
				ekran[yilan[i][0]][yilan[i][1]]=604; // alt sag
			} else if(yilan[i-1][1]==yilan[i][1]+1 && yilan[i+1][0]==yilan[i][0]+1) {
				ekran[yilan[i][0]][yilan[i][1]]=604; // alt sag
			}
			if(yilan[i-1][1]==yilan[i][1]-1 && yilan[i+1][1]==yilan[i][1]+1) {
				ekran[yilan[i][0]][yilan[i][1]]=600; // sag sol
			} else if(yilan[i-1][1]==yilan[i][1]+1 && yilan[i+1][1]==yilan[i][1]-1) {
				ekran[yilan[i][0]][yilan[i][1]]=600; // sag sol
			}
			if(i==0)
				ekran[yilan[i][0]][yilan[i][1]]=802;
		}
		
		for(i=yb;i>0;i--) {
			yilan[i][0]=yilan[i-1][0];
			yilan[i][1]=yilan[i-1][1];
		}
		if(kbhit()) {
			tus=tusalsnake();
		}
		tusyeniden:
		if(tus==770) { // ESC
			break;
		} else if(tus==741) { // YUKARI
			if(otus!=742) {
				yilan[0][0]--;
				otus=tus;
			} else {
				yilan[0][0]++;
			}
		} else if(tus==742) { // AŞAĞI
			if(otus!=741) {
				yilan[0][0]++;
				otus=tus;
			} else {
				yilan[0][0]--;
			}
		} else if(tus==743) { // SAĞA
			if(otus!=744) {
				yilan[0][1]++;
				otus=tus;
			} else {
				yilan[0][1]--;
			}
		} else if(tus==744) { // SOLA
			if(otus!=743) {
				yilan[0][1]--;
				otus=tus;
			} else {
				yilan[0][1]++;
			}
		} else if(tus=='p' || tus=='P') {
			syaz("OYUN DURDURULDU",11,23);
			yazdir();
			do {
				tus=tusalsnake();
			} while(tus!=741 && tus!=742 && tus!=743 && tus!=744);
			
			goto tusyeniden;
		} else {
			tus=otus;
			goto tusyeniden;
		}
		
		
		if(yilan[0][0]==yemsatir && yilan[0][1]== yemsutun) {
			tekrar:
				yemsatir=1+rand()%(satir-4);
				yemsutun=1+rand()%(sutun-4);
			for(i=0;i<yb;i++) {
				if(yilan[i][0]==yemsatir && yilan[i][1]==yemsutun) {
					goto tekrar;
				}
			}
			yb++;
		}
		sprintf(skor,"%-4d",yb);
		syaz(skor,satir-2,sutun-7);
		yazdir();
		
		for(i=3;i<yb;i++) {
			if(yilan[0][0]==yilan[i][0] && yilan[0][1]==yilan[i][1]) {
				return 0;
			}
		}
		if(yilan[0][0]<1 || yilan[0][0]>satir-4 || yilan[0][1]<1 || yilan[0][1]>sutun-2) {
			return 0;
		}
		
		
	}
	
	
	
	return 0;
}
