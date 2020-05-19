# Blatt 4

## Aufgabe 1  

	(1)	returnValue fctName(arg1,... ,argN)  	
			returnValue	: Datentyp der Rückgabe  
			fctName 	: Funktionsname zum aufrufen  
			arg1 - argN	: Argumente mit festen Datentypen welche beim  
						  Aufruf der Funktion mit übergeben werden müssen  

		int funk(int x, char y)  
			returnValue	: int  
			fctName 	: funk  
			arg1 - argN	: (int , char) in genau dieser Reihenfolge  

		Source: http://www.lab4inf.fh-muenster.de/lab4inf/docs/Prog-in-C/04-Funktionen.pdf Folie 5  

	(2) int main(){
			int (*fptr) (int, char);
			fptr = &funk;
			printf("Adr von func: %p\n", fptr); return 0;
		}
	