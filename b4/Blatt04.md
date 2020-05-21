# Blatt 4

## Aufgabe 1  
### (1)
```
returnValue fctName(arg1,... ,argN)  	
			returnValue	: Datentyp der Rückgabe  
			fctName 	: Funktionsname zum aufrufen  
			arg1 - argN	: Argumente mit festen Datentypen welche beim  
						  Aufruf der Funktion mit übergeben werden müssen  

int funk(int x, char y)  
			returnValue	: int  
			fctName 	: funk  
			arg1 - argN	: (int , char) in genau dieser Reihenfolge
```

Source: http://www.lab4inf.fh-muenster.de/lab4inf/docs/Prog-in-C/04-Funktionen.pdf Folie 5  

### (2)
```
int main(){
			int (*fptr) (int, char);
			fptr = &funk;
			printf("Adr von func: %p\n", fptr); return 0;
		}
```

### (3)
mov rdi, 0
mov rax, 60
syscall

### (4)

## Aufgabe 2
	
gets() schreibt ALLES was sie bekommt in den übergebenen Buffer, auch darüber hinaus, wenn die Eingabe größer ist als der Buffer. Hier liegt der Buffer im Speicher vor den drei Funktionen. Heißt man kann diese überschreiben, indem man den buf[32] voll spammt, wobei der erste Buchstabe ein "J" sein muss, damit die Funktion auch ausgeführt wird! "Jdhdhdhdhdhdhdhdhdhdhdhdhdhdhdhd" Füllt buf[32] komplett. Nun muss man noch die ersten beiden Funktionen so überschreiben, dass sie nicht ausgeführt werden. Da man selber entscheidet welche Funktion ausgeführt wird ist es man einfachsten die erste zu nehmen und dort die Adresse der Funktion 3  hinein zu schreiben. Oder 0x0000 0000 FF10 bis 0x0000 0000 FF20 mit "0" zu überschrieben. (?)

## Aufgabe 4
### (1)
ASLR steht für Address Space Layout Randomization. Wie der nahme schon sagt, sorgt es dafür dass die Adressen für Programme zufällig zugewiesen werden und nicht mehr vorhersehbar sind. Dies soll Angriffe über Bufferoverflow erschweren. (Es gibt natürlich Angriffstechniken die diesen Schutz umgehen).
Eine temporäre Abschaltung lässt sich durch das Interface /proc/sys/kernel/randomize_va_space erreichen. Hier bei ist 0 keine randomizierung, 1 eine teilweise randomizierung (Shared libraries, stack, heap) und 2 eine volle randomizeirung. 
Um ASLR abzuschaltung führt man also folgenden Befehl aus:
echo 0 | sudo tee /proc/sys/kernel/randomize_va_space
und um es wieder zu enablen mit echo 2.

### (2) (change layout because fuck...)
1 #include <stdio.h>
2 #include <stdint.h>
3
4 int main () {
5 uint64_t rip , rbp , rsp;					unsigned long long declaration
6 asm ("lea (%% rip ),%% rax" : "=r" (rip ));			In 64-bit mode you can exploit the RIP-relative addressing, so LEA RAX,	7 asm ("lea (%% rbp ),%% rax" : "=r" (rbp ));			[RIP] will give you the address of itself in EAX
8 asm ("lea (%% rsp ),%% rax" : "=r" (rsp ));
9 printf("rip: %p\n", rip );					Printing of Addresses
10 printf("rbp: %p\n", rbp );
11 printf("rsp: %p\n", rsp );
12 return 0;
13 }
