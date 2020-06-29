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

# Aufgabe 1

(1) Eine Umgebungsvaraible ist ein dynamsich gennanter Wert, der beeinflussen  kann wie ein Prozess ausgeführt wird. Hierbei sind sie ein Besatndteil der Umgebung in der der Prozess läuft. 

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

(3)

(4)
```
#include <unistd.h> 
int execve(const char *filename, char *const argv[], char *const envp[]);
```
Execve() führt das Programm aus auf den der Pointer Filename zeigt (const char *filename).*
argv ist ein array von argument strings die dem neues programm übermittelt werden (char *const argv[])* 
envp ist ein array von strings die als Umgebung zum neuen Programm übermittelt werden (char *const envp[])* Im normal Fall haben sie die Form key=value.
Bei success, execve() returned nicht, und returned -1 bei einem error. 

(5)

(6)
PATH ist die Systemvariable, die das Betriebssystem verwendet, um über die Befehlszeile oder das Terminalfenster nach erforderlichen ausführbaren Dateien zu suchen.
Die Systemvariable PATH kann mit dem Systemutility in der Windows-Systemsteuerung oder in der Startdatei der Linux- oder Solaris-Shell eingerichtet werden.
Änderungen an der Systemvariablen PATH sind in der Regel nicht erforderlich bei Rechnern, auf denen Windows oder Mac OS X ausgeführt wird.
One of the most well-known is called PATH on Windows, Linux and Mac OS X. It specifies the directories in which executable programs* are located on the machine that can be started without knowing and typing the whole path to the file on the command line.On Linux and Mac OS X, it usually holds all bin and sbin directories relevant for the current user.
specifying a set of directories where executable programs are located. In general, each executing process or user session has its own PATH setting.
 $PATH variable is specified as a list of one or more directory names separated by colon (:) characters
 Directories in the PATH-string are not meant to be escaped, making it impossible to have directories with : in their name. 
 absolute (/home/userjoe/bin/script.sh) or relative path (./script.sh) 
 
 # Aufgabe 3
 
 # Aufgabe 4
 (1) Eine verbreitungsmöglichkeit ist via Spammails. Der Bot verschickt maßenweise emails, wobei versucht wird den Empfänger dazu zu bringen das angehängt Programm asuzuführen, welches dann den Bot installiert. Hierbei wird im Betreff/in der e-Mail häufig vorgegeben sie sei von einem Freund, der Familie, Arbeitskollegen oder es hat mit aktuellen Anlässen wie Weihnachten zu tun. Dieses Prinzip heißt "Social Engeneering". Ursprünglich wurde Storm nur so verbreitet. Mittlerweise sind auch häufig links in den Emals die auf eine Seite führen, wo man dann die Malware runterlädt. 
 Eine zweite Methode ist es "exploits" also Schwachstellen vom Browser auszunutzen um so den Bot zu installieren. Wenn der Nutzer nicht von alleine auf den Downlaod Trick reinfällt wird ein sogennanter Drive-by download versucht.  Hierbei werden ätere Exploits benutzt in der Hoffnung dass wenigerer Erfahrene Benutzer, die ihre Betriebssysteme nicht regelmäßif aktualisieren den Bugfix noch nicht haben.
           
