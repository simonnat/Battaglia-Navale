#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define dim 12
#define nome "\t\t\t\t\t\t\t\tBATTAGLIA NAVALE\t versione beta 2.0\n\n"
//per lo sparo usare carattere 207 per acqua ,255 è quadrato bianco


//variabili locali per funzione sparoC
int counter1=0,counter2=1,counter3=0;
char rigacol,rigacol2;
int colonnacol,colonnacol2;
//fine
int nave6=0,nave4=0,nave3=0,nave2=0,nave22=0,nave32=0;
int difficolta=2;

int affondamento(char arrayC[dim][dim], int riga,int colonna);
int controlloInserimentoC(char array[dim][dim],char rigast,char rigaen,int colonnast,int colonnaen);
void inizializzaArray(char arrayG[dim][dim]);
void inserimentoG(char arrayG[dim][dim]);
int inserimentoC(char arrayC[dim][dim]);
void stampa (char array[dim][dim]);
int difficile (char arrayG[dim][dim],char riga,int colonna);
int facile (char arrayG[dim][dim],char riga,int colonna);
int controlloInserimento(char array[dim][dim],char rigast,char rigaen,int colonnast,int colonnaen);
int sparoC(char arrayG[dim][dim]);
int controlloSparo(char arrayG[dim][dim],char riga,int colonna);
void partita(char arrayG1[dim][dim], char arrayG2[dim][dim], char arrayC[dim][dim]);
int sparoUtente (char i, int j, char arrayC[dim][dim], char arrayG2[dim][dim]);

   
int main (){
	char tabellaG[dim][dim];
	char tabellaG2[dim][dim];
	char tabella[dim][dim];
	int scelta=4,i,numeroDiControllo;
	char scelta1;
//	system("color f0");
	inizializzaArray(tabella);
	inizializzaArray(tabellaG2);
	inizializzaArray(tabellaG);

	do{
     	system("cls");
		printf(nome);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
		printf("%c\tMenu'\t   %c\n",186,186);
		printf("%c1. Inserisci navi.%c\n",186,186);
		printf("%c2. Inizia partita.%c\n",186,186);
		printf("%c3. Come giocare.  %c\n",186,186);
		printf("%c4. Esci dal gioco.%c\n",186,186);
		printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);
		printf("Scelta: ");
		scanf("%i",&scelta);
	fflush(stdin);
	fflush(stdout);
	system("cls");
		switch (scelta){
		case 1:
			inserimentoG(tabellaG);
			
			printf("Attendere che il computer termini");
	    	numeroDiControllo = inserimentoC(tabella);
			
			while(numeroDiControllo != 20){//se numeroDiControllo è diverso da venti vuol dire che si è dimenticato qualche nave
				fflush(stdin);
			fflush(stdout);
				inizializzaArray(tabella);
				numeroDiControllo = inserimentoC(tabella);
			}

			for(i=0;i<6;i++){
				printf(".");
				Sleep(600);
			}
			printf("\nIl computer ha terminato\n");		//funzione di attesa
			Sleep(1000);
			system("cls");
			break;
		case 2:
		    partita(tabellaG,tabellaG2,tabella);
			printf("Vuoi giocare un'altra partita?<s/n>.\n");
	fflush(stdin);
	fflush(stdout);
	scanf("%s",&scelta1);
	fflush(stdin);
	fflush(stdout);
	if(scelta1=='s'){
	inizializzaArray(tabella);					//inizializzo gli array creando la tabella di gioco
	inizializzaArray(tabellaG2);
	inizializzaArray(tabellaG);
	system("cls");
	}
	else 
		scelta=4;
	fflush(stdin);
	fflush(stdout);

			break;
		case 3:
			system ("cls");
			printf("\t\t\t\t\t\t\t\tISTRUZIONI BATTAGLIA NAVALE\n\n");
			printf("Per iniziare a giocare a Battaglia Navale bisogna prima di tutto inserire le navi selezionando la prima opzione nel menu', dopo aver terminato il posizionamento delle proprie navi attendere che il computer abbia finito e quindi selezionare \"Inizia partita\", selezionare la difficolta' di gioco e battere il computer.\n\nBuon divertimento!!!.\n");
			system ("pause");
			break;
	
			fflush(stdin);
	fflush(stdout);
	    }
		
	}while(scelta!=4);

	fflush(stdin);
	fflush(stdout);
	system("pause");
	return 0;
}


void inserimentoG(char arrayG[dim][dim]){
	char rigast,rigaen;
	int colonnast,colonnaen;
	int nave6=1,nave4=1,nave3=2,nave2=2;
	int grandezza,lunghezzaInserita;
	int i,j;
		do{
			do{
				system("cls");
				
	printf (nome);
	printf("Inserimento navi\n");
	stampa(arrayG);
	printf("Le navi a disposizione sono:\n%c%c%c%c%c%c%c%c\n%c%i da 6%c\n%c%i da 4%c\n%c%i da 3%c\n%c%i da 2%c\n%c%c%c%c%c%c%c%c\n\n",201,205,205,205,205,205,205,187,186,nave6,186,186,nave4,186,186,nave3,186,186,nave2,186,200,205,205,205,205,205,205,188);
	printf("Quale nave vuoi inserire? (6,4,3,2)\n");
	printf("Scelta: ");
	scanf("%i",&grandezza);	
	
	if(grandezza==6 && nave6==0){
		printf("Le navi da 6 sono terminate\n");
		grandezza=5;
	}
	if(grandezza==4 && nave4==0){
		printf("Le navi da 4 sono terminate\n");
		grandezza=5;		//grandezza=5 per far rimanere il ciclo while attivo
	}
	if(grandezza==3 && nave3==0){
		printf("Le navi da 3 sono terminate\n");
		grandezza=5;
	}
	if(grandezza==2 && nave2==0){
		printf("Le navi da 2 sono terminate\n");
		grandezza=5;
	}
			}while(grandezza!=6 && grandezza!=4 && grandezza!=3 && grandezza!=2);	//evita che l'utente possa sbagliare con l'inserimento della grandezza

		
			do{
	printf("Inserisci gli estremi per collocare la nave\n");
	printf("Riga iniziale:\t");
	fflush(stdin);
	rigast=getchar();
	printf("Colonna iniziale:\t");
	fflush(stdin);
	scanf("%i",&colonnast);
	printf("Riga finale:\t");
	fflush(stdin);
	rigaen=getchar();
	printf("Colonna finale:\t");
	fflush(stdin);
	scanf("%i",&colonnaen);
}while(rigast==48 || rigaen==48|| colonnast==0 || colonnaen==0 || rigast<97 || rigast>106|| rigaen>106 || rigaen<97 ||11>colonnast<0 ||0<colonnaen>11 ||controlloInserimento(arrayG,rigast,rigaen,colonnast,colonnaen)==0); //controlla che le coordinate siano !=0 e dentro la tabella


	switch (grandezza){		//lo switch si incarica di contare le navi inserite decrementando il numero delle navi a disposizione
	case 6:
			  nave6--;
		break;
	case 4:
			  nave4--;
		break;
	case 3:
			  nave3--;
		break;
	case 2:
			  nave2--;
		break;
	}

	if(rigast==rigaen){					//questo if determina la lunghezza dalle coordinate inserite dagli utenti
		lunghezzaInserita=colonnaen-colonnast;
	}
	else
	{
		if(colonnast==colonnaen){
			lunghezzaInserita=rigaen-rigast;
		}
	}
	
	if(colonnast>colonnaen){
		int temp;
		temp=colonnast;
		colonnast=colonnaen;
		colonnaen=temp;
	}

	if(rigast>rigaen){
		char temp;
		temp=rigast;
		rigast=rigaen;
		rigaen=temp;
	}


	//printf("%i",abs(lunghezzaInserita));

	if(abs(lunghezzaInserita)+1!=grandezza){		//questo if controlla che i dati inseriti dall'utente sono congruenti con la dimensione inserita
		printf("Hai inserito coordinate errate\n");
		if(grandezza==6)
			nave6++;
			if(grandezza==4)
				nave4++;
				if(grandezza==3)
					nave3++;
					if(grandezza==2)
						nave2++;
	}else{
		for(i=rigast-96;i<=rigaen-96;i++){				//inserimento nave sulla griglia,-96 per far diventare il char un numero da uno a dieci
			for(j=colonnast;j<=colonnaen;j++){
				if(arrayG[i][j]!=254 )			//controllo se ci sono navi già presenti
				arrayG[i][j]= 254;	//254 è quadrato nero
	
	system("cls");
	
			}
		}
			}
}while(nave6!=0 ||  nave4!=0 || nave3!=0 || nave2!=0);
//stampa(arrayG);
 printf(nome);
printf("Hai finito le navi a tua disposizione\n");
return;
}

void stampa (char array[dim][dim]){
	int i,j;
	//array[0][0]=177;
	for(i=0;i<dim-1;i++){
				for(j=0;j<dim-1;j++){
					printf("%2c",array[i][j]);
				}
				printf("\n");
	}
	printf("\n");
}


void inizializzaArray(char arrayG[dim][dim]){

int i=0,j=0,k=0,z=0;
int count=1,counta=1;

	for(i=0;i<dim-1;i++){				//inizializzo la tabella con -
		for(j=1;j<dim-1;j++){
			arrayG[i][j]=240;
		}
	}
	arrayG[0][0]=0;
	
	for(k=1;k<=dim-1;k++){				//inizializzo i riferimenti per l'inserimento sulla colonna 0
		arrayG[k][0]=96+count;
	count++;
	}

	
	for(z=1;z<=dim-1;z++){				//inizializzo i riferimenti per l'inserimento sulla riga 0
		arrayG[0][z]=48+counta;
		counta++;
	}
	arrayG[0][10]=48;
}

int controlloInserimento(char array[dim][dim],char rigast,char rigaen,int colonnast,int colonnaen){
		int i,j;

	for(i=rigast-96;i<=rigaen-96;i++){				//inserimento nave sulla griglia,-96 per far diventare il char un numero da uno a dieci
			for(j=colonnast;j<=colonnaen;j++){
			if(array[i][j]== -2 ){					//-2 è ■
					printf("Hai inserito la nave su di un' altra\n");
				return 0;
					}
			}
	}
}

int sparoC(char arrayG[dim][dim]){
	
	int colonna,controllo;
	char riga;
	srand(time(NULL));
	do{
	riga=rand() % dim-1;
	colonna=rand() % dim-1;
	}while(colonna==0 || riga==0 || controlloSparo(arrayG,riga,colonna)==0 );	//finchè riga e colonna non sono !=0 continua a generare numeri, controlloSparo controlla che non ci siano stati altri spari su quella casella 

	switch(difficolta){
		case 1:
			controllo=facile(arrayG,riga,colonna);
			break;
		case 2:
			controllo=difficile(arrayG,riga,colonna);
			
		}
		//printf("%i\n",controllo);
	fflush(stdin);
	fflush(stdout);
	return controllo;
}


int controlloSparo(char arrayG[dim][dim],char riga,int colonna){
	if(arrayG[riga][colonna]!=-49 && arrayG[riga][colonna]!=-79)
		return 1;
	else 
		return 0;
}


int facile (char arrayG[dim][dim],char riga,int colonna){
	int controllo;
			//-49 è lo sparo nella tabella, -79 è acqua
	if(arrayG[riga][colonna]==-2){
			arrayG[riga][colonna]=207;
			controllo=1;
		}else
			arrayG[riga][colonna]=177;
	controllo=0;
	fflush(stdin);
	fflush(stdout);
	return controllo;
}


int sparoColonna(char arrayG[dim][dim],char riga,int colonna){
	int controllo;
	if(colonnacol==10){
		colonnacol=colonnacol-counter1+1;
				counter1=-1;
				}
	
	if (counter1==-1 && colonnacol>0){
		colonnacol--;
		if(arrayG[rigacol][colonnacol]==-2){
		arrayG[rigacol][colonnacol]=207;
			controllo=1;
			counter1=-1;
		}else{
			if(arrayG[rigacol][colonnacol]!=-49 && colonnacol>0){
			arrayG[rigacol][colonnacol]=177;
			counter1=0;
			counter2=0;
			}
			controllo=0;
			counter1=0;
			counter2=0;
		}
	}else{
	if(counter1>0){
		colonnacol++;
		if(arrayG[rigacol][colonnacol]==-2 ){
		arrayG[rigacol][colonnacol]=207;
		counter1++;
		controllo=1;
		}else{
			if(arrayG[rigacol][colonnacol]!=-49){
			arrayG[rigacol][colonnacol]=177;
			colonnacol=colonnacol-counter1;
			counter1=-1;
			controllo=0;
			}
			controllo=0;
		}
	}else
	{
	if(arrayG[riga][colonna]==-2){
		arrayG[riga][colonna]=207;
			counter1++;
			rigacol=riga;
			colonnacol=colonna;
			rigacol2=riga;
			colonnacol2=colonna;
			controllo=1;
		}else{
			arrayG[riga][colonna]=177;
			counter1=0;
			controllo=0;
	}
	}
	}
	fflush(stdin);
	fflush(stdout);
	return controllo;
	
}

int sparoRiga(char arrayG[dim][dim])
{
	
	int controllo;
	
	if(rigacol2==10){
		rigacol2=rigacol2-counter3;
				counter3=-1;
				counter2=0;
			
			}
	if(rigacol2==1){
		counter2=1;
	}
	//printf("%i\n",counter3);
	if(counter3==-1 && rigacol2>1){
		rigacol2--;
		if(arrayG[rigacol2][colonnacol2]==-2){
		arrayG[rigacol2][colonnacol2]=207;
		controllo=1;
			counter3=-1;
		}else{
			if(arrayG[rigacol2][colonnacol2]!=-49){
			arrayG[rigacol2][colonnacol2]=177;
			//colonnacol--;
			counter1=0;
			counter3=0;
			counter2=1;
			controllo=0;
			}
			controllo=0;
			counter1=0;
			counter2=1;
			counter3=0;
		}
	}else{
	if(counter3>0){
		rigacol2++;
		if(arrayG[rigacol2][colonnacol2]==-2 && rigacol2<11){
		arrayG[rigacol2][colonnacol2]=207;
		counter3++;
		controllo=1;
		}else{
			if(arrayG[rigacol2][colonnacol2]!=-49){
			arrayG[rigacol2][colonnacol2]=177;
			rigacol2=rigacol2-counter3-1;
			counter3=-1;
			controllo=0;
			counter2=0;
			}
		//	rigacol2=rigacol2-counter3;
			//counter3=-1;
			counter2=0;
			controllo=0;
		}
	}else
	{
		rigacol2++;
	if(arrayG[rigacol2][colonnacol2]==-2){
		arrayG[rigacol2][colonnacol2]=207;
		counter3=1;
		controllo=1;
		counter2=0;
	}else
	{
		if(arrayG[rigacol2][colonnacol2]!=-49){
		arrayG[rigacol2][colonnacol2]=177;
			counter3=2;
			controllo=0;
	}
		controllo=0;
	}
	}
	}
	fflush(stdin);
	fflush(stdout);
	return controllo;
}
/*
* La funzione difficile contiene al suo interno sparoRiga e sparoColonna, inizialmente viene invocata sparoColonna
* che al suo interno verifica se si è colpita una nave, se una nave è stata colpita memorizza la posizione del colpo e
* continua a sparare verso destra grazie a counter1 che verrà posto=1 e incrementato a ogni "colpito". All'interno dell'if verranno utilizzati i
* riferimenti presi in precedenza con rigacol e colonnacol incrementando solamente la colonna e lasciando invariata
* la riga, se spostandosi a destra manca la nave, allora counter1 verrà utilizzato per tornare al punto di partenza e 
* spostarsi verso sinistra finchè non incontra acqua, a quel punto counter2 viene portato a 0 e da quel momento in poi
* verrà invocata la funzione sparoRiga che dapprima inizierà a colpire da rigacol+1 finchè non incontra acqua o la
* fine della tabella, se incontra una di queste due occorrenze tramite counter3 (che ha la stessa funzione di counter1)
* si ritorna a rigacol2 (rigacol2 é una variabile inizializzata insieme a rigacol ma non viene mai modificata fino
* alla chiamata di sparoRiga) e continuerà a fare fuoco finchè non incontra acqua o fine della tabella.
* Una volta incontrata acqua o fine della tabella counter2 viene riportato a !=0 e la routine ricomincia da sparoColonna.
* Le funzioni sparoRiga e sparoColonna restituiscono un int che viene utilizzato nella funzione partita per determinare
* se il colpo è andato a segno e quindi continuare a far sparare.
*/
int difficile (char arrayG[dim][dim],char riga,int colonna){
	int controllo;
	
	if(counter2==0){
		controllo=sparoRiga(arrayG);
	}else
	controllo=sparoColonna(arrayG,riga,colonna);
	fflush(stdin);
	fflush(stdout);
	return controllo;
	}

int controlloInserimentoC(char array[dim][dim],char rigast,char rigaen,int colonnast,int colonnaen){
		int i,j;
		//controlla che la nave da inserire non si sovrapponga a una nave già inserita
	for(i=rigast;i<=rigaen;i++){
			for(j=colonnast;j<=colonnaen;j++){
			if(array[i][j]== -2 || array[i][j]== -22 || array[i][j]== 63 || array[i][j]== -24 || array[i][j]== -28 || array[i][j]== -32){
				return 0;
					}
			}
	}
}

int inserimentoC (char arrayC[dim][dim])
{
	int i,j = 0, v1, v2, v3, v4;//v1 stabilisce l'orizzontale o il verticale, v2 == numero casuale riga, v3 == numero casuale colonna
	int count = 5, lun = 4, controllo = 0;

	srand((unsigned)clock());
	//inserisce la nave da sei
	do{
       v1= rand() % 2 ;
       v2 = rand() % 10 + 1;
	   v3 = rand() % 10 + 1;
	}while(v2 == 0 && v3 == 0);//continua a generare numeri casuali compresi tra zero e dieci finchè v2 o v3 sono uguali a zero
	if(v1 == 1){//mette la nave in orizzontale
	   	  v4 = v3 + 5;//v4indica la dimensione della nave
	   	  while(v4 > 10){//esegue un controllo affinchè la nave possa essere inserita dentro i limiti della tabella
	   	  	   v4--;
	   	  	   v3--;
	      }
	   	  for(j=v3;j<=v4;j++){//scorre le colonne sulla stessa riga e inserisce il simbolo della nave nella tabella
	   	  	arrayC[v2][j] = 254;
	   	  }
	}
	else{//inserimento nave in verticale
	   	  v4 = v2 + 5;//v4indica la dimensione della nave
	   	  while(v4 > 10){//esegue un controllo affinchè la nave possa essere inserita dentro i limiti della tabella
	   	  	   v4--;
	   	  	   v2--;
	      }
	   	  for(j=v2;j<=v4;j++){//scorre le righe sulla stessa colonna e inserisce i simboli della nave nella tabella
	   	  	arrayC[j][v3] = 254;
	   	  }
	}
	do{//inserimento del resto delle navi con lo stesso meccanismo dell'inserimento della nave da sei
	   do{
	        do{
               v1= rand() % 2 ;
               v2 = rand() % 10 + 1;
	           v3 = rand() % 10 + 1;
	        }while(v2 == 0 && v3 == 0);
	        if(v1 == 1){
	   	        v4 = v3 + (lun-1);
	   	        while(v4 > 10){
	   	  	         v4--;
	   	  	         v3--;
	               }
	            if(controlloInserimentoC(arrayC, v2, v2, v3, v4)){//se la funzione torna 1 inserisco la nave in orizzontale
	            	switch(count){//count che tipo di nave devo inserire. Ogni nave avraà un simbolo diverso
	            		case 5:
					        for(j=v3;j<=v4;j++)
	   	     	                arrayC[v2][j] = 63;
	   	     	            break;
	   	     	        case 4:
	   	     	        	for(j=v3;j<=v4;j++)
	   	     	                arrayC[v2][j] = 234;
	   	     	            break;
	   	     	        case 3:
	   	     	        	for(j=v3;j<=v4;j++)
	   	     	                arrayC[v2][j] = 232;
	   	     	            break;
	   	     	        case 2:
	   	     	        	for(j=v3;j<=v4;j++)
	   	     	                arrayC[v2][j] = 228;
	   	     	            break;
	   	     	        case 1:
	   	     	        	for(j=v3;j<=v4;j++)
	   	     	                arrayC[v2][j] = 224;
	   	     	            break;
	   	     	    }
	            }   
	   	        else{//se controlloInserimentoC mi torna zero provo a inserire la nave in verticale
	   	        	v1 = 0;
	   	        }
	   	    }
			if(v1 == 0){
	   	         v4 = v2 + (lun-1);
	   	         while(v4 > 10){
	   	  	        v4--;
	   	  	        v2--;
	             }
	             if(controlloInserimentoC(arrayC, v2, v4, v3, v3)){//ricontrollo con la chiamata a funzione se posso inserire la nave
	                switch(count){
	            		case 5:
					        for(j=v2;j<=v4;j++)
	   	     	                arrayC[j][v3] = 63;
	   	     	            break;
	   	     	        case 4:
	   	     	        	for(j=v2;j<=v4;j++)
	   	     	                arrayC[j][v3] = 234;
	   	     	            break;
	   	     	        case 3:
	   	     	        	for(j=v2;j<=v4;j++)
	   	     	                arrayC[j][v3] = 232;
	   	     	            break;
	   	     	        case 2:
	   	     	        	for(j=v2;j<=v4;j++)
	   	     	               arrayC[j][v3] = 228;
	   	     	            break;
	   	     	        case 1:
	   	     	        	for(j=v2;j<=v4;j++)
	   	     	                arrayC[j][v3] = 224;
	   	     	            break;
	   	     	    }
	            }
	        }//se la funzione controlloInserimentoC torna anche in questo caso zero allora rigenera nuovi numeri casuali ricominciando il ciclo
	   }while(j!=(v4+1));//il ciclo va avanti finchè non ha inserito correttamente la nave
	   lun--;//decremento la lunghezza della nave
	   count--;//decremento il mio contatore
	   if(count % 2 != 0){//se il contatore è pari reincremento lun per posizionare la nave gemella a quella inserita
		   lun++;
		}
	}while (count != 0);//il ciclo di inserimento finisce quando count arriva a zero
	for(i=1;i<dim-1;i++){//controllo se ha inserito tutte le navi
		for(j=1;j<dim-1;j++){
			if(arrayC[i][j] != -16)
			    controllo++;
		}
	}
    return controllo;
}

void stampaPartita(char arrayG1[dim][dim],char arrayG2[dim][dim]){
int i,j,a;//stampa le tabelle affiancate
	printf("Tabella 1");
	printf("\t\t\t\t");
	printf("Tabella 2\n");
	for(i=0;i<dim-1;i++){
				for(j=0;j<dim-1;j++){
					printf("%2c",arrayG1[i][j]);
				}
				printf("\t\t\t");
				for(a=0;a<dim-1;a++){
				printf("%2c",arrayG2[i][a]);
				}
				printf("\n");
	}
	printf("\n");
	printf("______________________________________________________________________\n");
}
void partita(char arrayG1[dim][dim], char arrayG2[dim][dim], char arrayC[dim][dim]){
    
	char riga;
    int colonna, colpo, i, j;
	int colpoC = 0, colpoU = 0, countC = 0, countU = 0;
	
	printf (nome);
	do{
		printf("Inserire difficolta' gioco.\n\n\n");
		printf ("1.Facile.\n");
		printf ("2.Difficile.\n");
		printf("\n\nScelta: ");
		scanf ("%i", &difficolta);
		fflush(stdin);
	}while(difficolta!= 1 && difficolta!= 2);
	do{
		fflush(stdout);
	   do{
	do{
		   system("cls");
		   fflush(stdin);
		  printf (nome);
          stampaPartita(arrayG1,arrayG2);
		  printf("\n");
		  printf("Legenda\n\n%c colpito.\n%c acqua.\n",207,177);
		  fflush(stdin);
	      printf("\nInserire coordinate sparo\n");
	      printf("Riga: ");
		  fflush(stdin);
	      scanf ("%c", &riga);
	      fflush(stdin);
	      printf("Colonna: ");
	      scanf ("%i", &colonna);
	      fflush(stdin);
	}while( arrayG2[riga-96][colonna]== -49 || riga<97 || riga>106 || colonna<1 || colonna>10);//impedisce che lo sparo colpisca zone proibite
	      colpo=sparoUtente(riga,colonna,arrayC,arrayG2);
		  Sleep(1500);
		  
		  if (nave6+nave4+nave3+nave32+nave2+nave22==20)//se le navi del computer sono finite esce dal ciclo
			  break;
	   }while(colpo == 1);//continua a sparare finchè il colpo va a segno
	   if (nave6+nave4+nave3+nave32+nave2+nave22!=20){
	   do{
		  countC=0;
		  system("cls");
		  printf (nome);
	   	  stampaPartita(arrayG1,arrayG2);
		  printf("\n");
		  printf("Legenda\n\n\n%c colpito.\n%c acqua.\n",207,177);
	      printf("\n\nTurno computer.");
		  for(i=0;i<6;i++){
		  Sleep(300);
		  printf(".");
		  }
		  printf("\n");
	      colpoC=sparoC(arrayG1);
	 	
		  for(i=1;i<dim-1;i++){
	      for(j=1;j<dim-1;j++){
	      	 if(arrayG1[i][j]==-49)//controlla quante navi del giocatore sono state colpite
	      	    countC++;
		  }
	   }
		//if(countC==20)
			//break;
	   }while(colpoC == 1);
	   }
	   	
    }while(nave6+nave4+nave3+nave32+nave2+nave22 != 20 && countC != 20 );//il ciclo finisce quando o il computer o l'utente hanno terminato le navi
    system("cls");
	if(countC==20)
        printf("GAME OVER.\n");
    else
        printf("HAI VINTO.\n");
	system("pause");
	fflush(stdin);
	fflush(stdout);
    return;
}

int sparoUtente (char i, int j, char arrayC[dim][dim], char arrayG2[dim][dim]){
	int controllo; 
	
	i=i-96;//convertire da lettera a numero
	if (arrayC[i][j]== -2 || arrayC[i][j]== -22 || arrayC[i][j]== 63 || arrayC[i][j]== -24 || arrayC[i][j]== -28 || arrayC[i][j]== -32){//se l'utente ha colpito qualche nave
		controllo = affondamento(arrayC,i,j);
		if(controllo == 0){
		    printf("Colpito.\n");
		    arrayG2[i][j] = 207;
		}
		else{
		   printf("Colpito e affondato.\n");
		   arrayG2[i][j] = 207;
	    }
	    return 1;
	}
	else{
		printf ("Mancato\n");
		arrayG2[i][j] = 177;
		return 0;
	}	
}

int affondamento(char arrayC[dim][dim], int riga,int colonna){
	char controllo;
	//se la funzione torna 1 la nave è affondata altrimenti torna zero
	controllo=arrayC[riga][colonna];//estrae il carattere di posto riga colonna
	switch (controllo){
		case -2:
			nave6++;
			if(nave6==6)
				return 1;
			else
				return 0;
			break;
		case 63:
			nave4++;
			if(nave4==4)
				return 1;
			else
				return 0;
			break;
		case -22:
			nave3++;
			if(nave3==3)
				return 1;
			else
				return 0;
			break;
		case -24:
			nave32++;
			if(nave32==3)
				return 1;
			else
				return 0;
			break;
		case -28:
			nave2++;
			if(nave2==2)
				return 1;
			else
				return 0;
			break;
		case -32:
		nave22++;
		if(nave22==2)
				return 1;
		else
				return 0;
		break;
		}
}
