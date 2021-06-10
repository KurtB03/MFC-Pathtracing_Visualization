# OpenGL

> Das "GL" steht für "Good Luck"

## Was ist OpenGL

OpenGL ist eine so genannte Spezifikation, also ein Dokument, das eine Sammlung an Definitionen von Funktionen die existieren sollten, welche Argumente sie entgegen nehmen sollen, was sie tun und zurückgeben sollen.
Die Tatsächliche Implementation findet sich im Grafikkarten-Treiber, weshalb sie üblicherweise nicht eingeshen werden können. Statdessen orientiert man sich beim Programmieren an der Spezifikation, was jedoch für inkonsistente Ergebnisse sorgen Kann. Dafür ist Sicher, das so gut wie jedes Gerät mit Display eine Implementation mitbringt, somit das Programm darstellen kann.
Eben deshalb muss man OpenGL theoretisch auch zum Programmieren nichts installieren, sofern man Funktionsfähige grafik hat.

## Was kann OpenGL

OpenGL erlaubt es Grafikdaten an die Grafikkarte zu übergeben und Shader zu schreiben, die auf der Grafikkarte ausgeführt werden. In den Grafikdaten werden etwa Position, Farbe, Material, Helligkeit und weitere Metadaten hinterlegt.
Die Shader werden mit diesen Daten ausgeführt und nutzen die Pallelitäts Kapazität um den Exakten RGB-Wert jedes Pixels aus Licht, Reflektion, (Semi-)Tranzparenz, Schattenwurf, Euklidischer Geometrie, etc. zu Errechnen.