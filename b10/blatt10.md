---
title: "Reaktive Sicherheit"
subtitle: "Übungsblatt 10"
author: 
	- Balduin Binder [s6babind@uni-bonn.de]
	- Charlotte Mädler [s6chmaed@uni-bonn.de]
	- Bünyamin Sarikaya [s6busari@uni-bonn.de]
lang: de
output: pdf_file
---
Es fehlt: 1.3 unclean, 1.5, 3.3, 3.5, 3.6, 3.7
# Aufgabe 1
(1)
```
#include <dlfcn.h>
void *dlopen(const char *filename, int flag);
```
dlopen() lädt die dynamische library die ihm mit dem nullterminierten string filename übergeben wird und returned dessen handle. Falls Filename NULL ist, returned es den handle zum main programm. Ein "/" im Filename wird als Path interpretiert. Sonst wird mittels dynamischer Linker für die library gesucht.
Flag muss entweder auf RTLD_LAZY oder RTLD_NOW gesetzt sein. Sie entscheiden ob undefinierte Symbole zwingend resolved werden müssen oder nicht. RTLD_LAZY tut dies nur wenn der code diese referenziert. RTLD_NOW tut dies für alle bevor dlopen() zuende ist. 

(2)

(3)
PLT und GOT sind zusätzlicher Speicher, genutzt vom Compiler und dynamischen Linker.
PLT bedeutet Procedure Linkage Table und wird benutzt um externe funktionen/prozeduren aufzurufen, deren adresse zum zeitpunkt des linkens unbekannt sind. Es wird also für den dynamischen linker überlassen, der das zur Laufzeit resolven soll. 
GOT bedeutet Global Offsets Table.
whenever a global variable of a shared library is accessed by your program load the true address of the variable from the GOT, which the dynamic linker previously set.
Whenever a function from a shared library is called, the linker makes us jump to an address in the PLT.


(4)
The first time the function is called, the PLT code uses offsets stored in the GOT to decide the actual final location of the function, and then:
stores this pre-calculated value
jumps there
The next times the function is called, the value has already been calculated, so it just jumps there directly.
(5)

# Aufgabe 3

(1)Kernelmodule sind codefragmente die nach Bedarf in die Kernel ge- und entladen werden können. Die erweitern die Funktionen der Kernel, ohne ein Systemneustart forauszusetzen. Ein Beispiel wäre der device driver, der dem Kernel erlaubt auf Hardware zuzugreifen welches zum System angeschlossen ist. 

lsmod - Zeigt welche Module aktuell geladen sind.

insmod -Fügt ein Modul der Kernel zu. modprobe wird häufiger benutzt, da es mehr abhängigkeiten haben kann. 

 rmmod - Entfernt Module aus der Kernel.
 
(2) Programmcode im Ring 0 befindet sich im Kernelmodus. 

(3)

(4)printk ist eine C Funktion vom Linux Kernel Interface. Sie druckt Nachrichten zum Kernel Log. Sie akzeptiert ein String Parameter (format sting)
is a C function from the Linux kernel interface that prints messages to the kernel log. It accepts a string parameter called the format string, which specifies a method for rendering an arbitrary number of varied data type parameter(s) into a string. The string is then printed to the kernel log.

It provides a printf-like abstraction and its parsing of the format string and arguments behave exactly the same way. It acts as a debugging tool for kernel programmers who need this function for logging messages from the kernel. C standard library and its printf function is unavailable in kernel mode, hence the need for printk. printk has an optional prefix string: Loglevel.

Loglevel specifies the type of message being sent to the kernel message log. The syntax with loglevel is:
printk(KERN_DEBUG "Debug message shown!\n");
Different Loglevels, along with their numerical values, are shown here:

0	KERN_EMERG	Emergency condition, system is probably dead
1	KERN_ALERT	Some problem has occurred, immediate attention is needed
2	KERN_CRIT	A critical condition
3	KERN_ERR	An error has occurred
4	KERN_WARNING	A warning
5	KERN_NOTICE	Normal message to take note of
6	KERN_INFO	Some information
7	KERN_DEBUG	Debug information related to the program
Loglevels are defined in <linux/kern_levels.h>. Which log levels are printed is configured in the /proc/sys/kernel/printk sysctl file .
(5)
(6)
(7)

# Aufgabe 4

