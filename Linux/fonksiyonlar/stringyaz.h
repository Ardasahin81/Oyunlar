

void syaz(char *a,int x,int y){ /** int ekran dizisinde x y koordinatlarına yazmak için (Türkçe karakterler) */
	int j,i=0;
	for(j=y;a[i]!=0;j++) {
		if(a[i]==-59) {
			if(a[i+1]==-97)
				ekran[x][j]=704;
			else if(a[i+1]==-98)
				ekran[x][j]=714;
			i++;
		} else if(a[i]==-60) {
			if(a[i+1]==-97)
				ekran[x][j]=701;
			else if(a[i+1]==-98)
				ekran[x][j]=711;
			else if(a[i+1]==-79)
				ekran[x][j]=702;
			else if(a[i+1]==-80)
				ekran[x][j]=712;
			i++;
		} else if(a[i]==-61) {
			if(a[i+1]==-89)
				ekran[x][j]=700;
			else if(a[i+1]==-121)
				ekran[x][j]=710;
			else if(a[i+1]==-74)
				ekran[x][j]=703;
			else if(a[i+1]==-106)
				ekran[x][j]=713;
			else if(a[i+1]==-68)
				ekran[x][j]=705;
			else if(a[i+1]==-100)
				ekran[x][j]=715;
			i++;
		} else{
			ekran[x][j]=a[i];
		}
		i++;
	}
}
