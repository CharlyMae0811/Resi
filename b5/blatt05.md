# Blatt 5

## Aufgabe 1

	(1) Bei dem TOC-to-TOU-Problem handelt es sich um ein Multithreadingproblem.  
	Process 1 check ob eine Condition wahr ist (TOC), ist sie wahr bzw. erfüllt oder gegeben,  
	versucht er mit dieser Condition zu arbeiten (TOU). Unterbricht ein anderer Process nun genau  
	nach dem Check der als wahr gewertet wurde und vor dem Benutzen, kann er den von Prozess 1 benötigeten  
	Ressourcen verwenden oder aufbrauchen, wodurch wenn Prozess 1 wieder weiter macht, ausgehend von dem  
	Korrekten Check, kann der Prozess abstürzen.  

	(2) 


## Aufgabe 2
	
	(1) Signatur von printf: int printf(const char *format,...)  
	"..." heißt man kann endlich viele Variablen übergeben welche im format string entsprechend  
	des Datentyps "aufgerufen" werden müssen.

	(2) al: Anzahl floating point Parameter  in Vektor Register  
		__m256 & __m512 Variablenargumente auf den Stack  

	(3) Ein Formatstring enthält informatien wie viele Parameter der  
	Funktion auf dem Stack übergeben wurden und deren Datentypen

	(4) 

	(5) ./main "%x %x %x"

	(6) als erstes wird 1 in den stack geschrieben, dann die adresse von i, dann wird prinf ausgeführt 


## Aufgabe 4

	(1) 
![](A4_1.jpg) 