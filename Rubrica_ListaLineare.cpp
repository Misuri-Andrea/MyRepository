/*

Programma realizzato da Andrea Misuri

Data: 18 / 10 / 2015

Classe: 4A Informatica ITIS Leonardo da Vinci

*/

#include "stdafx.h"   /* inclusione libreria dei file standard */
#include <stdio.h>    /* inclusione libreria per le operazioni di input / output */
#include <stdlib.h>   /* inclusione header per funzioni generali */
#include <string.h>   /*inclusione libreria per l'utilizzo delle stringhe */  
using namespace std;   /* dichiarazione dell'utilizzo dello spazio dei nomi standard */

struct Anagrafica   /* definizione della struttura Anagrafica */
{
	char nome[20];   /* campo nome di tipo char formato da 20 caratteri */
	char cognome[20];   /* campo cognome di tipo char formato da 20 caratteri */
	char num_telefonico[10];   /* campo numero telefonico di tipo char formato da 10 caratteri */
	char email[40];   /* campo email di tipo char formato da 40 caratteri */
	Anagrafica *ptr_successivo;   /* puntatore di tipo Anagrafica che punta al nodo successivo */
};

Anagrafica* Aggiungi_Contatto(Anagrafica *testa);   /* definizione del prototipo della funzione Aggiungi Contatto */
int Ricerca_Contatto(Anagrafica *testa, char cognome_cercato[20]);   /* definizione del prototipo della funzione Ricerca Contatto */
void Modifica_Contatto(Anagrafica *testa, char cognome_cercato [20]);   /* definizione del prototipo della funzione Modifica Contatto */
void  Elimina_Contatto(Anagrafica *testa, char cognome_cercato[20]);   /* definizione del prototipo della funzione Elimina Contatto */
void Stampa_Rubrica(Anagrafica *testa);   /* definizione del prototipo della funzione Stampa Rubrica */

Anagrafica contatto_cercato;  /* dichiarazione della variabile globale contatto cercato di tipo Anagrafica */

int main()   /* funzione principale */
{
	int scelta = 0;   /* dichiarazione ed inizializzazione della variabile scelta di tipo intero */
	
    Anagrafica *testa = NULL;   /* dichiarazione ed inizializzazione di un puntatore che punta alla testa della lista */
	char cognome_cercato[20];   /* dichiarazione della variabile cognome cercato */

	do {    /* fai... */
		printf("---------------------RUBRICA TELEFONICA---------------------\n\n");   // menu delle opzioni
		printf("Scegliere una delle seguenti opzioni\n\n");
		printf("Digitare 1 da tastiera per AGGIUNGERE UN NUOVO CONTATTO\n");
		printf("Digitare 2 da tastiera per MODIFICARE UN CONTATTO ESISTENTE\n");
		printf("Digitare 3 da tastiera per ELIMINARE UN CONTATTO DALLA RUBRICA\n");
		printf("Digitare 4 da tastiera per RICERCARE UN CONTATTO\n");
		printf("Digitare 5 da tastiera per STAMPARE LA RUBRICA\n");
		printf("Digitare 0 da tastiera per CHIUDERE LA RUBRICA\n");
		scelta = getchar();    /* input della scelta tramite la getchar */
		
		if (scelta == 49)   /* se l'utente digita 1 (in decimale 49) */
		{
			testa = Aggiungi_Contatto(testa);    /* richiamo della funzione Aggiungi Contatto */
		}

		if (scelta == 50)   /* se l'utente digita 2 (in decimale 50) */
		{
			printf("Inserire il cognome del contatto che si desidera modificare\n");
            Modifica_Contatto(testa, cognome_cercato);   /* richiamo della funzione Modifica Contatto */
		}

		if (scelta == 51)   /* se l'utente digita 3 (in decimale 51) */
		{
			printf("Inserire il cognome del contatto che si desidera eliminare\n");
			scanf("%s", cognome_cercato);   /* input del cognome cercato */
			Ricerca_Contatto(testa, cognome_cercato);   /* richiamo della funzione Ricerca Contatto */

		}

		if (scelta == 52)
		{
			printf("Inserire il cognome del contatto da ricercare\n");
			scanf("%s", cognome_cercato);   /* input del cognome cercato */
			Ricerca_Contatto(testa, cognome_cercato);   /* richiamo della funzione Ricerca Contatto */
			Elimina_Contatto(testa, cognome_cercato);   // richiamo della funzione Elimina Contatto
		}

		if (scelta == 53)   /* se l'utente digita 5 (in decimale 53) */
		{
			Stampa_Rubrica(testa);   /* richiamo della funzione Stampa Rubrica */
		}
	
	  } while (scelta != 48);   /*...finchè la scelta è diversa da 0 (in decimale 48) */

	system("pause");   /* blocco della finestra per rendere leggibile l'output */
	return 0;   /* chiusura programma */
}


/* funzione Aggiungi Contatto: ritorno: Anagrafica; parametri: puntatore che punta alla testa della lista */
/* la funzione prende in input un contatto attraverso un puntatore con il quale si prendono in input i vari campi della struttura Anagrafica */
Anagrafica *Aggiungi_Contatto(Anagrafica *testa)
{
	Anagrafica *p;   /* dichiarazione di un puntatore alla struttura anagrafica */
    p = (Anagrafica*)malloc(sizeof(Anagrafica));    /* allocazione dinamica della struttura */

	printf("---------------------AGGIUNTA CONTATTO---------------------\n");
	printf("Inserire il nome del nuovo contatto\n");
	scanf("%s", p->nome);    /* input del nome del contatto attraverso il puntatore */
	printf("Inserire il cognome del nuovo contatto\n");
	scanf("%s", p->cognome);   /* input del cognome del contatto attraverso il puntatore */
	printf("Inserire il numero telefonico del nuovo contatto\n");
	scanf("%s", p->num_telefonico);   /* input del numero telefonico del contatto attraverso il puntatore */
	printf("Inserire l'email del nuovo contatto\n");
	scanf("%s", p->email);   /* input della email del contatto attraverso il puntatore */
	
	p->ptr_successivo = NULL;    /* il nodo successivo sarà a NULL */
	p->ptr_successivo = testa;   /* il nodo successivo sarà uguale all'inizio della lista (riempimento lista dal basso verso l'alto) */
	return p;   /* ritorno della funzione */
	free(p);   /* disallocazione della memoria */
	p = NULL;    /* puntatore non più utilizzabile  */
}

/* funzione Stampa Rubrica: ritorno: void; parametri: puntatore che punta alla testa della lista */
/* la funzione stampa la lista attarverso un indice che scorre i nodi */
void Stampa_Rubrica(Anagrafica *testa)
{
	int i = 0;   /* dichiarazione ed inizializzazione di un indice che scorrerà i nodi */
	while (testa != NULL)   /* finchè la testa non finisce */
	{
		printf("-----------------------------------------------------------\n");
		printf("Nome: %s \n", testa->nome);   /* ...stampa il nome del contatto */
		printf("Cognome: %s \n", testa->cognome);   /* ...stampa il cognome del contatto */
		printf("Numero telefonico: %s \n", testa->num_telefonico);   /* ...stampa il numero telefonico del contatto */
		printf("E-mail: %s \n", testa->email);   /* ...stampa la email del contatto */
		printf("-----------------------------------------------------------\n");
		testa = testa->ptr_successivo;   /* ...passa al nodo successivo */
		i++;   /* ...incrementa l'indice */
		
	}
}

/* funzione Ricerca Contatto: ritorno: int; parametri: puntatore che punta alla testa della lista ed il cognome cercato dall'utente */
/* la funzione cerca un contatto scelto dall'utente attraverso il cognome del contatto */
int Ricerca_Contatto(Anagrafica *testa, char cognome_cercato[20])
{
	if (testa == NULL)  
	{
		return 0;    // se la testa della lista è NULL allora la lista è vuota e non è possibile modificare i contatti
	}
	
	else   // se la lista non è vuota
	{
		
		for (; testa != NULL; testa = testa->ptr_successivo)   /* ciclo FOR che va dalla testa fino al nodo successivo */
		{
			if (strcmp(testa->cognome, cognome_cercato) == 0)    /* string compare per verificare la corrispondenza dei cognomi */
			{
				printf("CONTATTO TROVATO\n");   /* c'è corrisponedenza, quindi il contatto è stato trovato */
				break;   /* il ciclo si ferma dato che ha trovato il contatto */
			}

			else
			{
				printf("CONTATTO NON TROVATO !\n");
				return -1;   /* contatto non trovato */
			}


		}
	}
}


/* funzione Modifica Contatto: ritorno: void; parametri: puntatore che punta alla testa della lista ed il cognome cercato dall'utente */
/* la funzione cerca un contatto scelto dall'utente attraverso il cognome del contatto e lo modifica a piacimento */
void Modifica_Contatto(Anagrafica *testa, char cognome_cercato[20])
{
	Anagrafica *ptr_modificato = NULL;   // dichiarazione ed inizializzazione di un puntatore utilizzato per modificare il contatto
	
	if (testa == NULL) 
	{
		return;   // se la testa della lista è NULL allora la lista è vuota e non è possibile modificare i contatti
	}
	
	else   // se la lista non è vuota
	{
		scanf("%s", contatto_cercato.cognome);    // input del cognome del contatto da cercare 
		Ricerca_Contatto(testa, cognome_cercato);   // richiamo della funzione Ricerca Contatto per cercare il contatto desiderato dall'utente

		ptr_modificato = (Anagrafica*)malloc(sizeof(Anagrafica));   // allocazione dinamica della struttura

		printf("Inserire il nuovo nome del contatto\n");
		scanf("%s", ptr_modificato->nome);    // input del nuovo nome tramite il puntatore
		printf("Inserire il nuovo cognome del contatto\n");
		scanf("%s", ptr_modificato->cognome);   // input del nuovo cognome tramite il puntatore
		printf("Inserire il nuovo numero telefonico del contatto\n");
		scanf("%s", ptr_modificato->num_telefonico);   // input del nuovo numero telefonico
		printf("Inserire la nuova e-mail del contatto\n");
		scanf("%s", ptr_modificato->email);   // input della nuova e-mail
		free(ptr_modificato);    // disallocazione del puntatore
		ptr_modificato = NULL;   // puntatore non più utilizzabile
	}
}

/*  funzione Modifica Contatto: ritorno: void; parametri: puntatore che punta alla testa della lista ed il cognome cercato dall'utente */
/* la funzione cerca un contatto scelto dall'utente attraverso il cognome del contatto e lo elimina dalla lista */
void Elimina_Contatto(Anagrafica *testa, char cognome_cercato[20])
{
	Anagrafica contatto_da_eliminare;   // dichiarazione della variabile contatto da eliminare di tipo anagrafica

	if (testa == NULL)  
	{
		return;    // se la testa della lista è NULL allora la lista è vuota e non è possibile modificare i contatti
	}
	
	
	else   // se la lista non è vuota
	{
		scanf("%s", contatto_cercato.cognome);   // input del cognome del contatto da cercare 
		Ricerca_Contatto(testa, cognome_cercato);   // richiamo della funzione Ricerca Contatto per cercare il contatto desiderato dall'utente

	}
}