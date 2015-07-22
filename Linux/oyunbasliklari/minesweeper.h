

int oyunalani[25][70][2];


void sifirla() {
	int i,j;
	for(i=0;i<satir;i++) 
		for(j=0;j<sutun;j++)
			ekran[i][j]=0;
}


void oyunciz() {
	
	int i,j;
	int x=satir*2+1;
	int y=sutun*2+1;
	
	for(i=0;i<x;i++) {
		for(j=0;j<y;j++) {
			ekran[i][j]=0;
		}
	}
	
	ekran[0][0]=604;
	ekran[0][y-1]=602;
	ekran[x-1][0]=605;
	ekran[x-1][y-1]=603;
	
	for(i=1;i<y-3;i+=2) {
		ekran[0][i+1]=606;
		ekran[x-1][i+1]=608;
	}
	
	for(i=1;i<x-3;i+=2) {
		ekran[i+1][0]=610;
		ekran[i+1][y-1]=609;
	}
	
	for(i=0;i<y;i+=2) {
		for(j=1;j<x-1;j+=2) {
			ekran[j][i]=601;
		}
	}
	
	for(i=0;i<x;i+=2) {
		for(j=1;j<y-1;j+=2) {
			ekran[i][j]=600;
		}
	}
	
	for(i=2;i<y-2;i+=2) {
		for(j=2;j<x-2;j+=2) {
			ekran[j][i]=607;
		}
	}
}

int ekranagecir() {
	oyunciz();
	int i,j;
	
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			switch (oyunalani[i][j][0]) {
				case 0:
					if(oyunalani[i][j][1]==1)
						ekran[i*2+1][j*2+1]=0;//801
					break;
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
					if(oyunalani[i][j][1]==1)
						ekran[i*2+1][j*2+1]=oyunalani[i][j][0]+'0';
					break;
				case 10:
					if(oyunalani[i][j][1]==1)
						ekran[i*2+1][j*2+1]=814;
					break;
				case 11:
					if(oyunalani[i][j][1]==1)
						ekran[i*2+1][j*2+1]=813;
					break;
				default:
					if(oyunalani[i][j][1]==1)
						ekran[i*2+1][j*2+1]=oyunalani[i][j][0];
			}
		}
	}
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			if(oyunalani[i][j][1]==2) {
				ekran[i*2+1][j*2+1]=813;
			}
			
			if(oyunalani[i][j][0]==0 && oyunalani[i][j][1]==1) {
				ekran[i*2+1+1][j*2+1]=ekran[i*2+1-1][j*2+1]=ekran[i*2+1][j*2+1+1]=ekran[i*2+1][j*2+1-1]=0;
				
				ekran[i*2+1-1][j*2+1+1]=ekran[i*2+1+1][j*2+1+1]=ekran[i*2+1+1][j*2+1-1]=ekran[i*2+1-1][j*2+1-1]=0;
				
				if(j>0){
					ekran[i*2+1-1][j*2+1-2]=0;
					ekran[i*2+1+1][j*2+1-2]=0;
				}
				if(j+1<sutun) {
				ekran[i*2+1-1][j*2+1+2]=0;
				ekran[i*2+1+1][j*2+1+2]=0;
				}
				if(i>0) {
					ekran[i*2+1-2][j*2+1-1]=0;
					ekran[i*2+1-2][j*2+1+1]=0;
				}
				if(i+1<satir) {
					ekran[i*2+1+2][j*2+1-1]=0;
					ekran[i*2+1+2][j*2+1+1]=0;
				}
			}
			
		}
	}
	for(i=0;i<satir*2+1;i++) {
		for(j=0;j<sutun*2+1;j++) {
			if(ekran[i][j]==607) {
				if(ekran[i][j-1]==0 && ekran[i-1][j]==0) {
					ekran[i][j]=604;
				} else if(ekran[i-1][j]==0 && ekran[i][j+1]==0) {
					ekran[i][j]=602;
				} else if(ekran[i][j+1]==0 && ekran[i+1][j]==0) {
					ekran[i][j]=603;
				} else if(ekran[i+1][j]==0 && ekran[i][j-1]==0) {
					ekran[i][j]=605;
				} else if(ekran[i-1][j]==0) {
					ekran[i][j]=606;
				} else if(ekran[i+1][j]==0) {
					ekran[i][j]=608;
				} else if(ekran[i][j-1]==0) {
					ekran[i][j]=610;
				} else if(ekran[i][j+1]==0) {
					ekran[i][j]=609;
				}
			}
		}
	}
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			if(oyunalani[i][j][1]==0 || oyunalani[i][j][1]==2){
				if(oyunalani[i][j+1][1]==1 && oyunalani[i-1][j+1][1]==1 && oyunalani[i-1][j][1]==1) {
					ekran[i*2+1-1][j*2+1+1]=602;
				} else if(oyunalani[i][j+1][1]!=1 && oyunalani[i-1][j+1][1]==1 && oyunalani[i-1][j][1]==1) {
					ekran[i*2+1-1][j*2+1+1]=606;
				} else if(oyunalani[i][j+1][1]==1 && oyunalani[i-1][j+1][1]==1 && oyunalani[i-1][j][1]!=1) {
					ekran[i*2+1-1][j*2+1+1]=609;
				}
				if(oyunalani[i-1][j][1]==1 && oyunalani[i-1][j-1][1]==1 && oyunalani[i][j-1][1]==1) {
					ekran[i*2+1-1][j*2+1-1]=604;
				} else if(oyunalani[i-1][j][1]!=1 && oyunalani[i-1][j-1][1]==1 && oyunalani[i][j-1][1]==1) {
					ekran[i*2+1-1][j*2+1-1]=610;
				} else if(oyunalani[i-1][j][1]==1 && oyunalani[i-1][j-1][1]==1 && oyunalani[i][j-1][1]!=1) {
					ekran[i*2+1-1][j*2+1-1]=606;
				}
				if(oyunalani[i][j+1][1]==1 && oyunalani[i+1][j+1][1]==1 && oyunalani[i+1][j][1]==1) {
					ekran[i*2+1+1][j*2+1+1]=603;
				} else if(oyunalani[i][j+1][1]!=1 && oyunalani[i+1][j+1][1]==1 && oyunalani[i+1][j][1]==1) {
					ekran[i*2+1+1][j*2+1+1]=608;
				} else if(oyunalani[i][j+1][1]==1 && oyunalani[i+1][j+1][1]==1 && oyunalani[i+1][j][1]!=1) {
					ekran[i*2+1+1][j*2+1+1]=609;
				}
				if(oyunalani[i+1][j][1]==1 && oyunalani[i+1][j-1][1]==1 && oyunalani[i][j-1][1]==1) {
					ekran[i*2+1+1][j*2+1-1]=605;
				} else if(oyunalani[i+1][j][1]==1 && oyunalani[i+1][j-1][1]==1 && oyunalani[i][j-1][1]!=1) {
					ekran[i*2+1+1][j*2+1-1]=608;
				} else if(oyunalani[i+1][j][1]!=1 && oyunalani[i+1][j-1][1]==1 && oyunalani[i][j-1][1]==1) {
					ekran[i*2+1+1][j*2+1-1]=610;
				}
				
				if(oyunalani[i][j+1][1]==1)
					ekran[i*2+1][j*2+1+1]=601;
				if(oyunalani[i+1][j][1]==1)
					ekran[i*2+1+1][j*2+1]=600;
				if(oyunalani[i][j-1][1]==1)
					ekran[i*2+1][j*2+1-1]=601;
				if(oyunalani[i-1][j][1]==1) {
					ekran[i*2+1-1][j*2+1]=600;
				}
			}
			if(oyunalani[i][j][1]==1 && oyunalani[i][j][0]>0 && oyunalani[i][j][0]<9) {
				
				if(oyunalani[i][j+1][1]==1 && oyunalani[i-1][j+1][1]==1 && oyunalani[i-1][j][1]==1) {
					ekran[i*2+1-1][j*2+1+1]=0;
				}
				if(oyunalani[i-1][j][1]==1 && oyunalani[i-1][j-1][1]==1 && oyunalani[i][j-1][1]==1) {
					ekran[i*2+1-1][j*2+1-1]=0;
				}
				if(oyunalani[i][j+1][1]==1 && oyunalani[i+1][j+1][1]==1 && oyunalani[i+1][j][1]==1) {
					ekran[i*2+1+1][j*2+1+1]=0;
				} 
				if(oyunalani[i+1][j][1]==1 && oyunalani[i+1][j-1][1]==1 && oyunalani[i][j-1][1]==1) {
					ekran[i*2+1+1][j*2+1-1]=0;
				} 
				if(oyunalani[i][j+1][1]==1 && oyunalani[i][j+1]!=0)
					ekran[i*2+1][j*2+1+1]=0;
				if(oyunalani[i+1][j][1]==1 && oyunalani[i+1][j]!=0)
					ekran[i*2+1+1][j*2+1]=0;
				if(oyunalani[i][j-1][1]==1 && oyunalani[i][j-1]!=0)
					ekran[i*2+1][j*2+1-1]=0;
				if(oyunalani[i-1][j][1]==1 && oyunalani[i-1][j]!=0)
					ekran[i*2+1-1][j*2+1]=0;
				
			}
		}
	}
	ekran[0][0]=604;
	ekran[0][sutun*2+1-1]=602;
	ekran[satir*2+1-1][0]=605;
	ekran[satir*2+1-1][sutun*2+1-1]=603;

	for(i=1;i<satir*2;i++) {
		ekran[i][0]=ekran[i][sutun*2]=601;
	}
	for(i=1;i<sutun*2;i++) {
		ekran[0][i]=ekran[satir*2][i]=600;
	}
	
	return 0;
}


void bosalanac(int oysa,int oysu) {

	if(oysa>0) {
		if(oyunalani[oysa-1][oysu][1]==0) {
			oyunalani[oysa-1][oysu][1]=1;
			if(oyunalani[oysa-1][oysu][0]==0) {
				bosalanac(oysa-1,oysu);
			}
		}
	}
	
	if(oysa>0 && oysu>0) {
		if(oyunalani[oysa-1][oysu-1][1]==0) {
			oyunalani[oysa-1][oysu-1][1]=1;
			if(oyunalani[oysa-1][oysu-1][0]==0) {
				bosalanac(oysa-1,oysu-1);
			}
		}
	}
	if(oysa>0 && oysu+1<sutun) {
		if(oyunalani[oysa-1][oysu+1][1]==0) {
			oyunalani[oysa-1][oysu+1][1]=1;
			if(oyunalani[oysa-1][oysu+1][0]==0) {
				bosalanac(oysa-1,oysu+1);
			}
		}
	}
	
	if(oyunalani[oysa][oysu][1]==0) {
		oyunalani[oysa][oysu][1]=1;
		if(oyunalani[oysa][oysu][0]==0) {
			bosalanac(oysa,oysu);
		}
	}
	
	if(oysu>0) {
		if(oyunalani[oysa][oysu-1][1]==0) {
			oyunalani[oysa][oysu-1][1]=1;
			if(oyunalani[oysa][oysu-1][0]==0) {
				bosalanac(oysa,oysu-1);
			}
		}
	}
	if(oysu+1<sutun) {
		if(oyunalani[oysa][oysu+1][1]==0) {
			oyunalani[oysa][oysu+1][1]=1;
			if(oyunalani[oysa][oysu+1][0]==0) {
				bosalanac(oysa,oysu+1);
			}
		}
	}
	if(oysa+1<satir) {
		if(oyunalani[oysa+1][oysu][1]==0) {
			oyunalani[oysa+1][oysu][1]=1;
			if(oyunalani[oysa+1][oysu][0]==0) {
				bosalanac(oysa+1,oysu);
			}
		}
	}
	if(oysa+1<satir && oysu>0) {
		if(oyunalani[oysa+1][oysu-1][1]==0) {
			oyunalani[oysa+1][oysu-1][1]=1;
			if(oyunalani[oysa+1][oysu-1][0]==0) {
				bosalanac(oysa+1,oysu-1);
			}
		}
	}
	if(oysa+1<satir && oysu+1<sutun) {
		if(oyunalani[oysa+1][oysu+1][1]==0) {
			oyunalani[oysa+1][oysu+1][1]=1;
			if(oyunalani[oysa+1][oysu+1][0]==0) {
				bosalanac(oysa+1,oysu+1);
			}
		}
	}
	
	
	
}


int cevresiniac(int oysa,int oysu) { // Mayın açmışsa 1 döndür
	
	if(oysa>0) {
		if(oyunalani[oysa-1][oysu][1]==0) {
			if(oyunalani[oysa-1][oysu][0]==10 && oyunalani[oysa-1][oysu][1]!=2)
				return 1;
			oyunalani[oysa-1][oysu][1]=1;
			if(oyunalani[oysa-1][oysu][0]==0) {
				bosalanac(oysa-1,oysu);
			}
		}
	}
	
	if(oysa>0 && oysu>0) {
		if(oyunalani[oysa-1][oysu-1][1]==0) {
			if(oyunalani[oysa-1][oysu-1][0]==10 && oyunalani[oysa-1][oysu-1][1]!=2)
				return 1;
			oyunalani[oysa-1][oysu-1][1]=1;
			if(oyunalani[oysa-1][oysu-1][0]==0) {
				bosalanac(oysa-1,oysu-1);
			}
		}
	}
	if(oysa>0 && oysu+1<sutun) {
		if(oyunalani[oysa-1][oysu+1][1]==0) {
			if(oyunalani[oysa-1][oysu+1][0]==10 && oyunalani[oysa-1][oysu+1][1]!=2)
				return 1;
			oyunalani[oysa-1][oysu+1][1]=1;
			if(oyunalani[oysa-1][oysu+1][0]==0) {
				bosalanac(oysa-1,oysu+1);
			}
		}
	}
	
	if(oyunalani[oysa][oysu][1]==0) {
		if(oyunalani[oysa][oysu][0]==10 && oyunalani[oysa][oysu][1]!=2)
				return 1;
		oyunalani[oysa][oysu][1]=1;
		if(oyunalani[oysa][oysu][0]==0) {
			bosalanac(oysa,oysu);
		}
	}
	
	if(oysu>0) {
		if(oyunalani[oysa][oysu-1][1]==0) {
			if(oyunalani[oysa][oysu-1][0]==10 && oyunalani[oysa][oysu-1][1]!=2)
				return 1;
			oyunalani[oysa][oysu-1][1]=1;
			if(oyunalani[oysa][oysu-1][0]==0) {
				bosalanac(oysa,oysu-1);
			}
		}
	}
	if(oysu+1<sutun) {
		if(oyunalani[oysa][oysu+1][1]==0) {
			if(oyunalani[oysa][oysu+1][0]==10 && oyunalani[oysa][oysu+1][1]!=2)
				return 1;
			oyunalani[oysa][oysu+1][1]=1;
			if(oyunalani[oysa][oysu+1][0]==0) {
				bosalanac(oysa,oysu+1);
			}
		}
	}
	if(oysa+1<satir) {
		if(oyunalani[oysa+1][oysu][1]==0) {
			if(oyunalani[oysa+1][oysu][0]==10 && oyunalani[oysa+1][oysu][1]!=2)
				return 1;
			oyunalani[oysa+1][oysu][1]=1;
			if(oyunalani[oysa+1][oysu][0]==0) {
				bosalanac(oysa+1,oysu);
			}
		}
	}
	if(oysa+1<satir && oysu>0) {
		if(oyunalani[oysa+1][oysu-1][1]==0) {
			if(oyunalani[oysa+1][oysu-1][0]==10 && oyunalani[oysa+1][oysu-1][1]!=2)
				return 1;
			oyunalani[oysa+1][oysu-1][1]=1;
			if(oyunalani[oysa+1][oysu-1][0]==0) {
				bosalanac(oysa+1,oysu-1);
			}
		}
	}
	if(oysa+1<satir && oysu+1<sutun) {
		if(oyunalani[oysa+1][oysu+1][1]==0) {
			if(oyunalani[oysa+1][oysu+1][0]==10 && oyunalani[oysa+1][oysu+1][1]!=2)
				return 1;
			oyunalani[oysa+1][oysu+1][1]=1;
			if(oyunalani[oysa+1][oysu+1][0]==0) {
				bosalanac(oysa+1,oysu+1);
			}
		}
	}
	
	
	return -1;
}


void sonucmayin(int s) {
	
	
	int i;
	
	ekran[9][10]=504;
	ekran[9][60]=502;
	ekran[13][10]=505;
	ekran[13][60]=503;
	
	for(i=11;i<60;i++) {
		ekran[9][i]=ekran[13][i]=500;
		ekran[10][i]=ekran[11][i]=ekran[12][i]=0;
	}
	for(i=10;i<13;i++)
		ekran[i][10]=ekran[i][60]=501;
	
	if(s==1) {
		syaz("TEBRİKLER! KAZANDINIZ  (Çıkmak için ENTER)",11,11);
		
	} else if(s==2) {
		syaz("MAYINA BASTINIZ  (Çıkmak için ENTER)",11,11);
		
	}
	
	
	
}

int mayin() {
	
	/************************************************************
	 * oyunalani[a][b] nin ilki bütün oyunun görüntüsünü içerir.
	 * ikincisi ise o karenin görünür olup olmadığını belirtir.
	 * 
	 * oyunalani[a][b][1]=1 ise görünür 0 ise görünmez,2 ise bayrak.
	 * 
	 * oyunalani[a][b][0]=10 ise mayın, 0 ise boş, herhangi bir rakam
	 * ise o rakamın değeri.
	 ************************************************************/
	 
	/** Mayınları yerleştir ve sayıları belirle */
	int hamlesayisi=0; // ilk hamlede mayına basmamak için.
	int mayinsayisi;
	
	int i,j;
	//int tus;
	int oysa=2,oysu=2;
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			oyunalani[i][j][0]=0;
			oyunalani[i][j][1]=0;
		}
	}
	
	mayinsayisi=85;
	
	int mayinkoy=0;
	
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			if(oyunalani[i][j][0]==0 && mayinkoy<mayinsayisi) {
				if(rand()%400==1) {
					oyunalani[i][j][0]=10;
					mayinkoy++;
				}
			}
		}
		if(i==satir-1 && mayinkoy!=mayinsayisi)
			i=-1;
	}
	int say=0;
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			if(oyunalani[i][j][0]==0) {
				say=0;
				if(i+1<satir) {
					if(oyunalani[i+1][j][0]==10)
						say++;
				}
				if(i+1<satir && j+1<sutun) {
					if(oyunalani[i+1][j+1][0]==10)
						say++;
				}
				if(i+1<satir && j>0) {
					if(oyunalani[i+1][j-1][0]==10)
						say++;
				}
				if(i>0) {
					if(oyunalani[i-1][j][0]==10)
						say++;
				}
				if(i>0 && j+1<sutun) {
					if(oyunalani[i-1][j+1][0]==10)
						say++;
				}
				if(i>0 && j>0) {
					if(oyunalani[i-1][j-1][0]==10)
						say++;
				}
				if(j>0) {
					if(oyunalani[i][j-1][0]==10)
						say++;
				}
				if(j+1<sutun) {
					if(oyunalani[i][j+1][0]==10)
						say++;
				}
				oyunalani[i][j][0]=say;
			}
		}
	}
	/** Hesap işleri sonu */
	//~ for(i=0;i<satir;i++) {
		//~ for(j=0;j<sutun;j++) {
			//~ ekran[i][j]=oyunalani[i][j][0];
		//~ }
	//~ }
	while (1) {
		ekranagecir();
		satir=satir*2+1;
		sutun=sutun*2+1;
		ekran[(oysa*2+1)-1][oysu*2+1]=ekran[(oysa*2+1)+1][oysu*2+1]=500;
		ekran[oysa*2+1][(oysu*2+1)-1]=ekran[oysa*2+1][(oysu*2+1)+1]=501;
		ekran[(oysa*2+1)-1][(oysu*2+1)-1]=504;//550
		ekran[(oysa*2+1)-1][(oysu*2+1)+1]=502;//551
		ekran[(oysa*2+1)+1][(oysu*2+1)-1]=505;//552
		ekran[(oysa*2+1)+1][(oysu*2+1)+1]=503;//553
		
		yazdir();
		satir=(satir-1)/2;
		sutun=(sutun-1)/2;
		
		tus=tusal();
		if(tus==' ' && hamlesayisi<3) hamlesayisi++;
		
		
		if(tus==741) {
			if(oysa>0) 
				oysa--;
		} else if(tus==742) {
			if(oysa<satir-1) {
				oysa++;
			}
		} else if(tus==743) {
			if(oysu<sutun-1) {
				oysu++;
			}
		} else if(tus==744) {
			if(oysu>0) {
				oysu--;
			}
		} else if(tus==770) {
			return 0;
		} else if(tus==' ') {
			if(hamlesayisi==1) {
				while(oyunalani[oysa][oysu][0]!=0) {
					for(i=0;i<satir;i++) {
						for(j=0;j<sutun;j++) {
							oyunalani[i][j][0]=0;
							oyunalani[i][j][1]=0;
						}
					}
					
					mayinsayisi=85;
					
					mayinkoy=0;
					
					for(i=0;i<satir;i++) {
						for(j=0;j<sutun;j++) {
							if(oyunalani[i][j][0]==0 && mayinkoy<mayinsayisi) {
								if(rand()%400==1) {
									oyunalani[i][j][0]=10;
									mayinkoy++;
								}
							}
						}
						if(i==satir-1 && mayinkoy!=mayinsayisi)
							i=-1;
					}
					say=0;
					for(i=0;i<satir;i++) {
						for(j=0;j<sutun;j++) {
							if(oyunalani[i][j][0]==0) {
								say=0;
								if(i+1<satir) {
									if(oyunalani[i+1][j][0]==10)
										say++;
								}
								if(i+1<satir && j+1<sutun) {
									if(oyunalani[i+1][j+1][0]==10)
										say++;
								}
								if(i+1<satir && j>0) {
									if(oyunalani[i+1][j-1][0]==10)
										say++;
								}
								if(i>0) {
									if(oyunalani[i-1][j][0]==10)
										say++;
								}
								if(i>0 && j+1<sutun) {
									if(oyunalani[i-1][j+1][0]==10)
										say++;
								}
								if(i>0 && j>0) {
									if(oyunalani[i-1][j-1][0]==10)
										say++;
								}
								if(j>0) {
									if(oyunalani[i][j-1][0]==10)
										say++;
								}
								if(j+1<sutun) {
									if(oyunalani[i][j+1][0]==10)
										say++;
								}
								oyunalani[i][j][0]=say;
							}
						}
					}
				}
				
				bosalanac(oysa,oysu);
				
			} else {
				if(oyunalani[oysa][oysu][0]>0 && oyunalani[oysa][oysu][0]<9 && oyunalani[oysa][oysu][1]!=2) {
					if(oyunalani[oysa][oysu][1]==0) {
						oyunalani[oysa][oysu][1]=1;
					} else if(oyunalani[oysa][oysu][1]==1) {
					int sayac=0;
					if(oyunalani[oysa][oysu+1][1]==2) 
						sayac++;
					if(oyunalani[oysa+1][oysu+1][1]==2)
						sayac++;
					if(oyunalani[oysa+1][oysu][1]==2)
						sayac++;
					if(oyunalani[oysa+1][oysu-1][1]==2)
						sayac++;
					if(oyunalani[oysa][oysu-1][1]==2)
						sayac++;
					if(oyunalani[oysa-1][oysu-1][1]==2)
						sayac++;
					if(oyunalani[oysa-1][oysu][1]==2)
						sayac++;
					if(oyunalani[oysa-1][oysu+1][1]==2)
						sayac++;
					
					if(sayac==oyunalani[oysa][oysu][0]) {
						if(cevresiniac(oysa,oysu)==1) {
							for(i=0;i<satir;i++) {
								for(j=0;j<sutun;j++) {
									if(oyunalani[i][j][0]==10) {
										oyunalani[i][j][1]=1;
									}
								}
							}
							ekranagecir();
							satir=satir*2+1;
							sutun=sutun*2+1;
							sonucmayin(2);
							yazdir();
							satir=(satir-1)/2;
							sutun=(sutun-1)/2;
							while(tusal() != 778);
							return -1;
						}
					}
				}
				} else if(oyunalani[oysa][oysu][0]==10 && oyunalani[oysa][oysu][1]!=2) {
					
					for(i=0;i<satir;i++) {
						for(j=0;j<sutun;j++) {
							if(oyunalani[i][j][0]==10) {
								oyunalani[i][j][1]=1;
							}
						}
					}
					ekranagecir();
					satir=satir*2+1;
					sutun=sutun*2+1;
					sonucmayin(2);
					yazdir();
					satir=(satir-1)/2;
					sutun=(sutun-1)/2;
					while(tusal() != 778);
					return -1;
					
				} else if(oyunalani[oysa][oysu][0]==0 && oyunalani[oysa][oysu][1]!=2) {
					if(oyunalani[oysa][oysu][1]==0) {
						bosalanac(oysa,oysu);
					}
				}
			}
		} else if(tus=='b' || tus=='B') {
			if(oyunalani[oysa][oysu][1]==0){
				oyunalani[oysa][oysu][1]=2;
			} else if(oyunalani[oysa][oysu][1]==2) {
				oyunalani[oysa][oysu][1]=0;
			}
		}
		
		for(i=0;i<satir;i++) {
			for(j=0;j<sutun;j++) {
				if(oyunalani[i][j][0]>0 && oyunalani[i][j][0]<9 && oyunalani[i][j][1]!=1) {
					break;
				}
			}
			if(j!=sutun)
				break;
			if(i==satir-1 && j==sutun) {
				satir=satir*2+1;
				sutun=sutun*2+1;
		
				sonucmayin(1);
				
				yazdir();
				satir=(satir-1)/2;
				sutun=(sutun-1)/2;
				while(tusal() != 778);
				return 10;
			}
		}
		
	}
	
	return 0;
}

