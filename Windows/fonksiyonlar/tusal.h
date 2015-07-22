

int tusal(void) {
	int i=1;
	int a[10]={ };
	
	a[0]=getch();
	while(kbhit())
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
	else if(a[0]==13 && a[1]==0) //ENTER
		return 778;
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





