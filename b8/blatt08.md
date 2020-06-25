---
title: "Reaktive Sicherheit"
subtitle: "Übungsblatt 8"
author: 
	- Balduin Binder [s6babind@uni-bonn.de]
	- Charlotte Mädler [s6chmaed@uni-bonn.de]
	- Bünyamin Sarikaya [s6busari@uni-bonn.de]
lang: de
output: pdf_file
---

# Aufgabe 2

(1) 

	FakeNet:          simuliert ein Netzwerk wobei jeglicher Netzwerkverkehr an localhost weitergeleitet wird, wodurch keine Daten nach außen gehen können. So kann man Schadsoftware analysieren (Verhalten, etc.). 

    RegShot:          (RegistryShot) ermöglicht es Snapshots von Registries zu machen. Dies ist nützlich um den genauen Ablauf/Verhalten von Schadsoftware weiter zu analysieren.
    
    Process Monitor:  zeichnet alle TCP/IP-Verbindungen auf, wie auch Lese- und Schreibzugriffe auf das Dateiensystem und Registry.
    
    Process Explorer: gibt ein Überblick über alle derzeitig laufende Prozesse, geladene Dateien und Speciehrzugriffe.
    
    strings2 :        extrahiert Unicode (und ASCII) Strings aus Binärdateien.
    
    YaraGUI:          ist eine Benutzeroberfläche zum  Malware identifizieren. 
    
    Wireshark:        stellt den Netzwerkverkehr da
(4)
(5)

# Aufgabe 4
(1) Zur VM zurück kehren aus Aufgabe 2.
(2) Ausführen von malicious.exe
(3)Screenshot 1: CMD öffnen, strings2 eingeben, Usage sehen
Screenshot 2: strings2 malicious.exe: "rinst.exe" wird ausgeführt
(4)In die Conditions kann man bestimmte Eigenschaften einer Datei schreiben (einsehrbar durch stings2). Durch die Yara-Regel kann man auffällige Strings als Malicious erkennbar machen.

"Malicious Yara Regel":
Von https://virustotal.github.io/yara/:

rule silent_banker : banker
{
    meta:
        description = "This is just an example"
        threat_level = 3
        in_the_wild = true

    strings:
        $a = {6A 40 68 00 30 00 00 6A 14 8D 91}
        $b = {8D 4D B0 2B C1 83 C0 27 99 6A 4E 59 F7 F9}
        $c = "UVODFRYSIHLNWPEJXQZAKCBGMT"

    condition:
        $a or $b or $c
}

Umgeschrieben:
rule malicious:
{
    meta:
        description = "Malicious erkennen"
        threat_level = 3
        in_the_wild = true

    strings:
        $a = "cV/ :f ;v5 , U"
        $b = "rinst.exe"
        $c = "GZek"

    condition:
        $a or $b or $c
}

In dem condition fragement wird erkennbar, dass also jede Datei die entweder string a, b, oder c (Logisches oder) enthält, als malicious makiert wird.
(5) Das Ausführen öffnet von "Tweaks.com" das Loginfenster. String2 lässt erkennen, dass 4 weitere Programme gestartet wurden (rinst.exe, bpk.exe, Mr. OoPpSsLogin.exe, inst.exe)
(6)Replikation, Population, Parasitmus: Nein
Es handelt sich um Spyware (es werden Daten aufgenommen und an andere Empfänger ohne Einwilligung des Nutzers geschickt)


