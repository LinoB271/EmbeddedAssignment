# Embedded Assignment:<br>
Dieses Repo soll meine Lösung für die gestellte Aufgabe darstellen.<br>
Im Ordner 'diagrams' ist ein entsprechendes UML-Diagramm als Bild hinterlegt, das der Übersichtlichkeit dienen soll.<br>
Des Weiteren habe ich eine kleine Dummy-Implementierung für den CANTypeA vogenommen, welche in der 'EmbeddedAssignment.cpp'-Datei aufgeufen wird.<br>

Da ich mir bezüglich der Umsetzung des Entwicklungsziels 'Rückmeldung von Fehlern beim Senden und Empfangen. (Synchron und Asynchron)' unsicher bin, möchte ich an dieser Stelle gerne noch ergänzend hinzufügen, dass man die Rückgabetypen der Interface-Funktionen auch so abändern kann, dass ein entsprechende ENUM zurückgegeben wird, das entsprechende Error-Codes darstellt (SUCCESS, INVALID_BAUD_RATE, INITIALIZATION_FAILED, ...).
