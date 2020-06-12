---
title: "Reaktive Sicherheit"
subtitle: "Übungsblatt 7"
author: 
	- Balduin Binder [s6babind@uni-bonn.de]
	- Charlotte Mädler [s6chmaed@uni-bonn.de]
	- Bünyamin Sarikaya [s6busari@uni-bonn.de]
lang: de
output: pdf_file
---

1.5 fehlt, 5.1 nicht vollständig, rest von 5 fehlt

# Aufgabe 2
(1) Path Traversal Verwundbarkeit (auch Directory Traversal gennent) ist eine Sicherheitslücke in einem Webserver/einer Webanwendung, wobei unerlaubterweise auf Dateien/Verzeichnisse zugegriffen wird, durch Eingabe von URLs . Normalerweise kann man nicht auf Dateien eines Webservers außerhalb des Web-Verzeichnisses oder dessen Unterverzeichnisse zugreiffen. Bei dem Angriff wird durch eine manipulierte Pfadangabe aber auf Dateien außerhalb dieser Verzeichnisse zuzugreifen. Dies wird meist duch Angeb von ../ bewirkt, da man sich damit im Verzeichnis eine Ebene nach oben bewegt. mit / wäre es gleich zur Wurzel.

(2) Die Vertaulichkeit wird verlezt (eventuelles auslesen von vertraulichen Daten, Passwörter, etc.) 

(3) Man soll, falls es Vorhanden ist, ein Katzenfoto runter laden können. Falls kein Foto vorhanden ist, soll dies auf einer weitergeleiteten Website stehen. 

(4) Die passwd-Datei liegt in der selben Partion wie die webcat.py Datei. Deswegen kann die Path Traversal Verwundbarkeit ausgenutzt werden. In Unterschiedlichen Partitionen geht dies nicht. 

(5)

# Aufgabe 5
(1) Hauptsächlich unterscheiden sich Programme und Prozesse darin, dass das Programm aus einer Gruppe von Anweisungen besteht, die eine bestimme Aufgabe ausführen sollen. Ein Prozess hingegen, ist ein bestimmtes Programm, das aktuell ausgeführt wird, also eine Instanz eines ausgeführten Programmes. Ein Programm kann also auch mehrere Prozesse aufrufen (1 zu n Beziehung). Ein Prozess wird deshalb als aktive Entität betrachtet, ein Programm jedoch als passiv. 
Dadurch entscheiden sicha auch die Lebensdauern und benötigte Resourcen von einander: Ein Programm ist im Speicher bis es manuell gelöscht wird udn benötigt auch nur Speicherplatzt, ein Prozess wird nach Abschluss der Aufgabe beendet, benötigt zur Ausführung jedoch zum Teil Verarbeitungs-, Speicher- oder E/A-Resourcen. 

Dateiformat x64-Linux-Programme: 

Ersten vier Byte des Formats:

Bytes des Headers:

(2)

