---
title: "Reaktive Sicherheit"
subtitle: "Übungsblatt 9"
author: 
	- Balduin Binder [s6babind@uni-bonn.de]
	- Charlotte Mädler [s6chmaed@uni-bonn.de]
	- Bünyamin Sarikaya [s6busari@uni-bonn.de]
lang: de
output: pdf_file
---
Es fehlt: 1.3, 1.5,  teile der 1.6, komplette 3
# Aufgabe 1

(1) Eine Umgebungsvaraible sind dynamisch änderbare Werte, die beeinflussen  können wie ein Prozess ausgeführt wird. Hierbei sind sie ein Besatndteil der Umgebung in der der Prozess läuft. Sie beinhalten Pfade zu Programmen/Dateien wie auch ggf. Einstellungen für mehrere Programme.

(2)Man kann die System.Environment class verwenden.

Die beiden Methoden: 
```
var value = System.Environment.GetEnvironmentVariable(variable [, Target])
```
und
```
System.Environment.SetEnvironmentVariable(variable, value [, Target])
```
können dies tun. Hier bei ist der Parameter Target (optional) Machine, Process, or User. Wenn Target weggelassen wird ist es per default der aktuelle Prozess.

Alternativ kann man der main methode den char* envp[] übergeben und mittels while Schleife ausgeben.
```
int main (...,char* envp[]){
int i=0;
while(envp[i]!=NULL]{
printf("[%s]", envp[i]);]}
```

(3)

(4)
```
#include <unistd.h> 
int execve(const char *filename, char *const argv[], char *const envp[]);
```
Execve() führt das Programm aus auf den der Pointer Filename zeigt (const char* filename).
argv ist ein array von argument strings die dem neues programm übermittelt werden (char* const argv[]) Per convention beginnt es mit dem Filenamen.
envp ist ein array von strings die als Umgebung zum neuen Programm übermittelt werden (char* const envp[]) Im normal Fall haben sie die Form key=value.
Bei success, returned execve() nicht und returned -1 bei einem error. 

(5)

(6)
PATH ist die Systemvariable, die das Betriebssystem verwendet, um über die Befehlszeile oder das Terminalfenster nach erforderlichen ausführbaren Dateien zu suchen. Man muss also nicht den geamten Path kennen/eingeben in der command line. In Linux und Mac OS X enthält PATH meist alle bin und sbin directories die für den akutellen nutzer relevant sind. Die varable wird als eine List spezifiziert, wobei die namen mit : getrennt werden. Generel, hat jeder ausgeführte Prozess oder nutzer session eine eigene PATH Einstellung. Sie kann mit dem Systemutility in der Windows-Systemsteuerung bzw. in der Startdatei der Linux-/Solaris-Shell eingerichtet werden. Bei Rechnerrn die auf Windows/Mac OS X laufen sind änderungen an PATH meist nicht erfoderlich.


 absolute (/home/userjoe/bin/script.sh) or relative path (./script.sh) 
 
 # Aufgabe 3
 
 # Aufgabe 4
 (1) Eine verbreitungsmöglichkeit ist via Spammails. Der Bot verschickt maßenweise emails, wobei versucht wird den Empfänger dazu zu bringen das angehängt Programm asuzuführen, welches dann den Bot installiert. Hierbei wird im Betreff/in der e-Mail häufig vorgegeben sie sei von einem Freund, der Familie, Arbeitskollegen oder es hat mit aktuellen Anlässen wie Weihnachten zu tun. Dieses Prinzip heißt "Social Engeneering". Ursprünglich wurde Storm nur so verbreitet. Mittlerweise sind auch häufig links in den Emals die auf eine Seite führen, wo man dann die Malware runterlädt. 
 Eine zweite Methode ist es "exploits" also Schwachstellen vom Browser auszunutzen um so den Bot zu installieren. Wenn der Nutzer nicht von alleine auf den Downlaod Trick reinfällt wird ein sogennanter Drive-by download versucht.  Hierbei werden ätere Exploits benutzt in der Hoffnung dass wenigerer Erfahrene Benutzer, die ihre Betriebssysteme nicht regelmäßif aktualisieren den Bugfix noch nicht haben.
           
