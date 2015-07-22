
void yazdir() {
	int i,j;
	system("clear");
	for(i=0;i<satir;i++) {
		for(j=0;j<sutun;j++) {
			switch (ekran[i][j]) {
				case 504:
					printf("%s",_ksa);
					break;
				case 604:
					printf("%s",_isa);
					break;
				case 500:
					printf("%s",_kos);
					break;
				case 600:
					printf("%s",_ios);
					break;
				case 501:
					printf("%s",_kua);
					break;
				case 601:
					printf("%s",_iua);
					break;
				case 502:
					printf("%s",_koa);
					break;
				case 602:
					printf("%s",_ioa);
					break;
				case 503:
					printf("%s",_kuo);
					break;
				case 603:
					printf("%s",_iuo);
					break;
				case 505:
					printf("%s",_kus);
					break;
				case 605:
					printf("%s",_ius);
					break;
				case 506:
					printf("%s",_kosa);
					break;
				case 606:
					printf("%s",_iosa);
					break;
				case 507:
					printf("%s",_kosua);
					break;
				case 607:
					printf("%s",_iosua);
					break;
				case 508:
					printf("%s",_kosu);
					break;
				case 608:
					printf("%s",_iosu);
					break;
				case 509:
					printf("%s",_kuao);
					break;
				case 609:
					printf("%s",_iuao);
					break;
				case 510:
					printf("%s",_kuas);
					break;
				case 610:
					printf("%s",_iuas);
					break;
				case 550:
					printf("%s",_ksaiou);
					break;
				case 551:
					printf("%s",_koaisu);
					break;
				case 552:
					printf("%s",_ksuioa);
					break;
				case 553:
					printf("%s",_kuoisa);
					break;
				case 541:
					printf("%s",_sagayatik);
					break;
				case 542:
					printf("%s",_solayatik);
					break;
				case 543:
					printf("%s",_carpi);
					break;
				case 700:
					printf("%s",_tc);
					break;
				case 701:
					printf("%s",_tg);
					break;
				case 702:
					printf("%s",_ti);
					break;
				case 703:
					printf("%s",_to);
					break;
				case 704:
					printf("%s",_ts);
					break;
				case 705:
					printf("%s",_tu);
					break;
				case 710:
					printf("%s",_tC);
					break;
				case 711:
					printf("%s",_tG);
					break;
				case 712:
					printf("%s",_tI);
					break;
				case 713:
					printf("%s",_tO);
					break;
				case 714:
					printf("%s",_tS);
					break;
				case 715:
					printf("%s",_tU);
					break;
				case 801:
					printf("%s",_kara);
					break;
				case 802:
					printf("%s",_karakare);
					break;
				case 811:
					printf("%s",_bayraksiyah);
					break;
				case 812:
					printf("%s",_bayrakbeyaz);
					break;
				case 813:
					printf("%s",_paragrafisareti);
					break;
				case 814:
					printf("%s",_balikgozu);
					break;
				case 815:
					printf("%s",_ouboskure);
				case 0:
					printf(" ");
					break;
				default:
					printf("%c",ekran[i][j]);
				
			}
		}
		
		
		printf("\n");
		
	}
}
