

int tusal(void) {
	int i=1;
	int a[10]={ };
	
	a[0]=getch();
	while(kbhit())
		a[i++]=getch();
	
	if(a[0]==27 && a[1]==91 && a[2]==65) //YUKARI
		return 741;
	else if(a[0]==27 && a[1]==91 && a[2]==66) //AŞAĞI
		return 742;
	else if(a[0]==27 && a[1]==91 && a[2]==67) //SAĞA
		return 743;
	else if(a[0]==27 && a[1]==91 && a[2]==68) //SOLA
		return 744;
	else if(a[0]==27 && a[1]==79 && a[2]==80) //F1
		return 751;
	else if(a[0]==27 && a[1]==79 && a[2]==81) //F2
		return 752;
	else if(a[0]==27 && a[1]==79 && a[2]==82) //F3
		return 753;
	else if(a[0]==27 && a[1]==79 && a[2]==83) //F4
		return 754;
	else if(a[0]==27 && a[1]==91 && a[2]==49 && a[3]==53 && a[4]==126) //F5
		return 755;
	else if(a[0]==27 && a[1]==91 && a[2]==49 && a[3]==55 && a[4]==126) //F6
		return 756;
	else if(a[0]==27 && a[1]==91 && a[2]==49 && a[3]==56 && a[4]==126) //F7
		return 757;
	else if(a[0]==27 && a[1]==91 && a[2]==49 && a[3]==57 && a[4]==126) //F8
		return 758;
	else if(a[0]==27 && a[1]==91 && a[2]==51 && a[3]==126) //DELETE
		return 772;
	else if(a[0]==27 && a[1]==91 && a[2]==53 && a[3]==126) //PAGE UP
		return 774;
	else if(a[0]==27 && a[1]==91 && a[2]==54 && a[3]==126) //PAGE DOWN
		return 775;
	else if(a[0]==27 && a[1]==91 && a[2]==72) //HOME
		return 776;
	else if(a[0]==27 && a[1]==91 && a[2]==70) //END
		return 777;
	else if(a[0]==10 && a[1]==0) 
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





