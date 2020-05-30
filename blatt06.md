---
title: "Reaktive Sicherheit"
subtitle: "Übungsblatt 6"
author: 
	- Balduin Binder [s6babind@uni-bonn.de]
	- Charlotte Mädler [s6chmaed@uni-bonn.de]
	- Bünyamin Sarikaya [s6busari@uni-bonn.de]
lang: de
output: pdf_file
---

# Aufgabe 1
  (1)In PHP gibt es die Funktion eval(), die benutzt wird um ein String zu evaluieren. Ein Angreifer würde jetzt teile oder den ganzen String maniuplieren um den String zu kontrollieren. Zum Beispiel:
  ´´´
  <?php
  $name='Charly';
  $string=$_GET['arg'];
  eval("\$name=\"$string\";");
  ?>
  ´´´
  Wenn der Angreifer hier als Input für String 'noname; system("Is")' gibt, wird in der eval() Funktion Is aufgerufen und eine Liste der Dateien im Directory wird offengelegt. Unter umständen kann der Angreifer sesible Dateien sehen, löschen oder updaten.
  
  (2) Das Schutzziel der Verfügbarkeit (Möchliches Löschen von Daten), der Vertraulichkeit (Sichten von sensiblen Daten) und der Integrität (Datenmanipulation) werden verletzt.
  
  (3) 
  
  (4)
  
  (5)Eval() wird benutzt um einen einzigen, dynamisch genereierten Python-Ausdruck zu evaluieren. Exec wird zum ausführen dynamisch generirten Python codes genutzt.
  
  Eval kann also nur ein einziges Argument entgegen nehmen, exec ein code block (loops, class, def, etc.) Eval gibt einen Wert zurück, exec gibt immer None zurück. In python 3 ist exec eine Funktion, die keine Auswirkung auf den compilierten Bytecode der Funktion hat wo exec angewendet wird. 
  
  (6)
  
  ##Aufgabe 2
