
int h[9]; //0 boş 1 oyuncu 2 bilgisayar

int kontrol[8][3]={{1,2,3},{4,5,6},{7,8,9},{1,4,7},{2,5,8},{3,6,9},{1,5,9},{3,5,7}};
int oyuncu1[15]={ };
int oyuncu2[15]={ };
int zorluk;

void ekranisifirla(void) {
	int i,j;
	
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			ekran[i][j]=0;
		}
	}
}

void harfciz(int tip, int koordinat) {
	int x,y;
	
	switch (koordinat) {
		case 1:
			x=16;
			y=4;
			break;
		case 2:
			x=16;
			y=12;
			break;
		case 3:
			x=16;
			y=20;
			break;
		case 4:
			x=10;
			y=4;
			break;
		case 5:
			x=10;
			y=12;
			break;
		case 6:
			x=10;
			y=20;
			break;
		case 7:
			x=4;
			y=4;
			break;
		case 8:
			x=4;
			y=12;
			break;
		case 9:
			x=4;
			y=20;
			break;
	}
	
	if(tip==1) {
		int i;
		
		for(i=0;i<5;i++) {
			ekran[x+i][y+i+1]=ekran[x+i][y+5-i]='X';
		}
	} else if(tip==2) {
		ekran[x][y+2]=ekran[x][y+3]=ekran[x][y+4]='O';
		ekran[x+1][y+1]=ekran[x+1][y+5]='O';
		ekran[x+2][y]=ekran[x+2][y+6]='O';
		ekran[x+3][y+1]=ekran[x+3][y+5]='O';
		ekran[x+4][y+2]=ekran[x+4][y+3]=ekran[x+4][y+4]='O';
	}
}

void cercevecizttt(void) {
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

	for(i=1;i<sutun-1;i++)
		ekran[0][i]=ekran[satir-1][i]=500;
	
	for(i=1;i<satir-1;i++)
		ekran[i][0]=ekran[i][sutun-1]=501;
}

void tttgiris(void) {
	cercevecizttt();
	
	syaz("xxxxx  x   xxx    xxxxx  xxxxx   xxx    xxxxx   xxx   xxxx",3,5);
	syaz("  x    x  x         x    x   x  x         x    x   x  x   ",4,5);
	syaz("  x    x  x         x    xxxxx  x         x    x   x  xxx ",5,5);
	syaz("  x    x  x         x    x   x  x         x    x   x  x   ",6,5);
	syaz("  x    x   xxx      x    x   x   xxx      x     xxx   xxxx",7,5);
	
	syaz("Kolay",13,15);
	syaz("Normal",14,15);
	syaz("Zor",15,15);
	syaz("İki Oyuncu",16,15);
	
	syaz("ESC: Çıkış - Geri                          ENTER: Seç",20,7);
}

int bitermi(int kim) {//Biterse eksik olan parça, bitmezse -1
	int sayac=0,eksik;
	int i,j;
	for(i=0;i<8;i++) {
		sayac=0;
		for(j=0;j<3;j++) {
			if(h[kontrol[i][j]-1]==kim) {
				sayac++;
			} else {
				eksik=kontrol[i][j];
			}
		}
		if(sayac==2) {
			if(h[eksik-1]==0) 
				return eksik;
			
		}
	}
	return -1;
}

int bitmismi(void) {//Bitmişse bitiren kişi bitmemişse -1
	int i,j;
	for(i=1;i<3;i++) {
		for(j=0;j<8;j++) {
			if(h[kontrol[j][0]-1]==i && h[kontrol[j][1]-1]==i && h[kontrol[j][2]-1]==i) {
				return i;
			}
		}
	}
	return -1;
}

int tttciz(void) {
	
	/** BU FONKSİYON SATIR=25 SUTUN=70 İÇİN YAZILMIŞTIR!!!!!! */
	
	
	// Çerçeve
	
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

	for(i=1;i<sutun-1;i++)
		ekran[0][i]=ekran[satir-1][i]=500;
	
	for(i=1;i<satir-1;i++)
		ekran[i][0]=ekran[i][sutun-1]=501;
	
	// Sağ taraf(Oyuncular, kılavuz vs.
	
	syaz("Skor",2,35);
	syaz("(X)",5,38);
	syaz("(O)",9,38);
	syaz("Berabere",13,38);
	syaz("Kılavuz",15,35);
	
	for(i=3;i<22;i++) {
		ekran[i][31]=601;
	}
	
	for(i=35;i<66;i++) {
		ekran[3][i]=ekran[16][i]=600;
		if(i>37) {
			ekran[7][i]=ekran[11][i]=600;
		}
	}
	
	ekran[18][47]=ekran[20][47]=ekran[22][47]=ekran[18][49]=ekran[20][49]=ekran[22][49]=601;
	ekran[19][46]=ekran[19][48]=ekran[19][50]=ekran[21][46]=ekran[21][48]=ekran[21][50]=600;
	ekran[19][47]=ekran[19][49]=ekran[21][47]=ekran[21][49]=607;
	ekran[22][46]='1';
	ekran[22][48]='2';
	ekran[22][50]='3';
	ekran[20][46]='4';
	ekran[20][48]='5';
	ekran[20][50]='6';
	ekran[18][46]='7';
	ekran[18][48]='8';
	ekran[18][50]='9';
	
	for(i=42;i<56;i++) {
		if(oyuncu1[i-42]==0)
			break;
		ekran[5][i]=oyuncu1[i-42];
	}
	if(zorluk==0) {
		for(i=42;i<56;i++) {
			if(oyuncu2[i-42]==0)
				break;
			ekran[9][i]=oyuncu2[i-42];
		}
	} else { 
		syaz("Bilgisayar",9,42);
	}
	
	// Sol taraf (Oyun alanı)
	
	for(i=4;i<21;i++) {
		if(i!=9 && i!=15 ) {
			ekran[i][11]=ekran[i][19]=501;
		}
	}
	
	for(i=4;i<27;i++) {
		if(i!=11 && i!=19) {
			ekran[9][i]=ekran[15][i]=500;
		} else {
			ekran[9][i]=ekran[15][i]=507;
		}
	}
	
	return 0;
	
}

/*1: Kolay  2: Normal  3: Zor*/

int bilsira(int zorluk) {
	
	if(zorluk==1) {
		int rast=rand()%9;
		while(h[rast]!=0)
			rast=rand()%9;
		h[rast]=2;
		return 3;
		
	} else if(zorluk==2) {
		int bitir1=bitermi(2);
		if(bitir1==-1) {
			bilsira(1);
			return 4;
			
		} else {
			h[bitir1-1]=2;
		}
		
	} else if(zorluk==3) {
		int bitir2=bitermi(2);
		
		if(bitir2==-1) {
			int bitir3=bitermi(1);
			
			if(bitir3!=-1) {
				h[bitir3-1]=2;
				return 5;
			} else {
				if(h[4]==0) {
					h[4]=2;
				} else if(h[0]==1 && h[8]==1) {
					if(h[7]==0) {
						h[7]=2;
						return 11;
					} else if(h[3]==0) {
						h[3]=2;
						return 12;
					} else if(h[5]==0) {
						h[5]=2;
						return 13;
					} else if(h[1]==0) {
						h[1]=2;
						return 14;
					}
				} else if(h[2]==1 && h[6]==1) {
					if(h[7]==0) {
						h[7]=2;
						return 11;
					} else if(h[3]==0) {
						h[3]=2;
						return 12;
					} else if(h[5]==0) {
						h[5]=2;
						return 13;
					} else if(h[1]==0) {
						h[1]=2;
						return 14;
					}
				} else {
					if(h[0]==0 || h[2]==0 || h[4]==0 || h[6]==0 || h[8]==0) {
						int rast=2*(rand()%5);
						while(h[rast]!=0)
							rast=2*(rand()%5);
						h[rast]=2;
					} else {
						bilsira(1);
						return 6;
					}
				}
			}
			
		} else {
			h[bitir2-1]=2;
		}
		
		
		
	}
	
	return 0;
	
}

int tictactoe(void) {
	int i;
	int sira=0;//Çift ise x
	int oyna;
	int tus;
	int menusecim=0;

	int xskor=0,oskor=0,beraber=0;
	tttgiris();
	yazdir();
	while(1) {
		//~ for(i=0;i<4;i++) {
			//~ ekran[13+i][12]=0;
		//~ }
		//~ 
		
		ekranisifirla();
		tttgiris();
		ekran[13+menusecim][12]='>';
		yazdir();
		
		tus=tusal();
		
		if(tus==741) { //YUKARI
			if(menusecim>0)
				menusecim--;
		} else if(tus==742) { //ASAGI
			if(menusecim<3)
				menusecim++;
		} else if(tus==770) { //ESC
			return 0;
		} else if(tus==778) {
			for(i=12;i<18;i++) {
				ekran[i][29]=601;
			}
			if(menusecim<3) {
				int karakter=0;
				
				/** Kutu cizimleri */
				
				syaz("İsim: ",13,33);
				
				ekran[12][42]=604;
				ekran[12][58]=602;
				ekran[14][42]=605;
				ekran[14][58]=603;
				ekran[13][42]=ekran[13][58]=601;
				for(i=43;i<58;i++) {
					ekran[12][i]=ekran[14][i]=600;
				}
				ekran[13][61]='<';
				while(1) {
					yazdir();
					
					tus=tusal();
					
					if( isalpha(tus) || isdigit(tus)) {
						if(karakter<14)
							oyuncu1[karakter++]=tus;
					} else if(tus>=700 && tus <716) {
						if(karakter<14)
							oyuncu1[karakter++]=tus;
					} else if(tus==770) {
						oyuncu1[0]=0;
						break;
					} else if(tus==773) {
						if(karakter>0)
							oyuncu1[--karakter]=0;
							
					} else if(tus==778) {
						if(karakter<1) {
							continue;
						} else {
								zorluk=menusecim+1;
								break;
						}
					}
					syaz("              ",13,43);
					for(i=0;i<=karakter;i++) {
						ekran[13][43+i]=oyuncu1[i];
					}
					yazdir();
				}
				if(oyuncu1[0]!=0) {
					break;
				}
			} else {
				int k1=0,k2=0;
				int altmenu=0;
				syaz("Oyuncu1:",13,33);
				syaz("Oyuncu2:",16,33);
				
				ekran[12][42]=ekran[15][42]=604;
				ekran[12][58]=ekran[15][58]=602;
				ekran[14][42]=ekran[17][42]=605;
				ekran[14][58]=ekran[17][58]=603;
				ekran[13][42]=ekran[13][58]=ekran[16][42]=ekran[16][58]=601;
				for(i=43;i<58;i++) {
					ekran[12][i]=ekran[14][i]=ekran[15][i]=ekran[17][i]=600;
				}
				while(1) {
					ekran[13][61]=ekran[16][61]=0;
					if(altmenu==0)
						ekran[13][61]='<';
					else 
						ekran[16][61]='<';
					
					yazdir();
					
					tus=tusal();
					
					if( isalpha(tus) || isdigit(tus)) {
						if(altmenu==0) {
							if(k1<14)
								oyuncu1[k1++]=tus;
						} else {
							if(k2<14)
								oyuncu2[k2++]=tus;
						}
					} else if(tus>=700 && tus <716) {
						if(altmenu==0) {
							if(k1<14)
								oyuncu1[k1++]=tus;
						} else {
							if(k2<14)
								oyuncu2[k2++]=tus;
						}
					} else if(tus==770) {
						oyuncu1[0]=0;
						oyuncu2[0]=0;
						break;
					} else if(tus==773) {
						if(altmenu==0) {
							if(k1>0)
								oyuncu1[--k1]=0;
						} else {
							if(k2>0)
								oyuncu2[--k2]=0;
						}
							
					} else if(tus==741) {
						if(altmenu>0)
							altmenu--;
					} else if(tus==742) {
						if(altmenu<1)
							altmenu++;
					} else if(tus==778) {
						if(k1<1 || k2<1) {
							continue;
						} else {
							zorluk=0;
							break;
						}
					}
					syaz("              ",13,43);
					syaz("              ",16,43);
					for(i=0;i<=k1;i++) {
						ekran[13][43+i]=oyuncu1[i];
					}
					for(i=0;i<=k2;i++) {
						ekran[16][43+i]=oyuncu2[i];
					}
					yazdir();
				}
				if(oyuncu1[0]!=0 && oyuncu2[0]!=0) {
					break;
				}
				
			}
		}
		
	}
	char skoryaz[6]={ };
	
	while(1) {
		
		for(i=0;i<9;i++) {
			h[i]=0;
		}
		tttciz();
		
		sprintf(skoryaz,"%-5d",xskor);
		syaz(skoryaz,5,61);
		sprintf(skoryaz,"%-5d",oskor);
		syaz(skoryaz,9,61);
		sprintf(skoryaz,"%-5d",beraber);
		syaz(skoryaz,13,61);
		
		yazdir();
		sira%=2;
		while(1) {
			if(sira%2==0) {
				do {
				oyna=tusal();
				if(oyna==770)
					return 0;
				oyna-='0';
				} while(h[oyna-1]!=0 || oyna<1 || oyna>9);
				h[oyna-1]=1;
				

			} else if(sira%2==1) {
				if(zorluk!=0) {
					bilsira(zorluk);
				} else {
					do {
					oyna=tusal();
					if(oyna==770)
						return 0;
					oyna-='0';
					} while(h[oyna-1]!=0 || oyna<1 || oyna>9);
					h[oyna-1]=2;
				}
				
			}
			for(i=0;i<9;i++) {
				harfciz(h[i],i+1);
			}
			ekran[5][35]=ekran[5][36]=ekran[9][35]=ekran[9][36]=0;
			if(sira%2==1)
				syaz(">>",5,35);
			else
				syaz(">>",9,35);
			
			
			sprintf(skoryaz,"%-5d",xskor);
			syaz(skoryaz,5,61);
			sprintf(skoryaz,"%-5d",oskor);
			syaz(skoryaz,9,61);
			sprintf(skoryaz,"%-5d",beraber);
			syaz(skoryaz,13,61);
			
			yazdir();

			if(bitmismi()!=-1) {
				if(bitmismi()==1)
					xskor++;
				else
					oskor++;
				break;
			}
			sira++;
			for(i=0;i<9;i++) {
				if(h[i]==0) {
					break;
				}
			}
			if(i==9) {
				beraber++;
				break;
			}
		}
		
	}

	
	return 0;
}
