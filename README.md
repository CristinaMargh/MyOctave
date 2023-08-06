# Project2-PCLP1
Copyright Cristina-Andreea Margheanu 313CAb 2022-2023
In cadrul problemei am folosit urmatoarele functii utile pentru
rezolvarea cerintelor si functiilor specificate in main:
-alocarea dinamica a memoriei pentru o matrice: aceasta are ca parametrii 
dimensiunile matricei si aloca memorie pentru fiecare linie in parte. La 
final,in cazul unei erori de alocare, atata timp cat mai avem linii,
aceasta memorie se si elibereaza treptat pana la finalizare.

-citirea elementelor matricei, ce primeste ca parametrii numarul liniilor
si numele matricei. Se citeste fiecare element in parte dupa care se
salveaza in matricea data ca parametru.

-eliberarea memoriei alocate, in cadrul careia parcurgem cu un
for fiecare linie si o eliberam.

In functia principala declaram caracterul ce ne va spune ce operatie
trebuie efectuala, numele vectorului de matrici(denumit colection),
in care vom incarca fiecare matrice pentru stocarea ei ulterioara.
Pentru operatia indicata de caracterul L,folosim functia include,
in cadrul careia alocam memorie si citim matricea pe care vrem sa o
adaugam la uniunea matricelor anterioare, alocand sau realocand
totodata memorie si pentru randuri si coloane, printr-un vector
corespunzator fiecareia, cu ajutorul functiilor malloc si realloc.
Dupa fiecare introducere, variabila index se va modifica
(este de tip pointer) si va creste deoarece am adaugat o noua matrice.
Pentru operatiile de printare si afisare a dimensiunii, retinem numarul
de linii si coloane ale matricei cerute in 2 variabile , m si n si apoi 
afisam dupa caz, dimensiunile sau elementele.
-Pentru functia de redimensionare alocam spatiu pentru vectorii de linii
si coloane ce ne indica indicii dupa care trebuie sa reformam matricea.
Matricea redimensionata trebuie si ea introdusa in memorie, prin 
inlocuirea celei pe care am modificat-o cu cea nou formata.  
-Pentru functia de sortare realizam un subprogram ce calculeaza suma
elementelor matricei date ca parametru si introducem sumele pentru 
fiecare matrice in parte, pana la cea curenta, intr-un vector de sume 
pentru a le retine valoarea si pentru a putea opera mai usor cu ele.
La final folosind metoda de sortare a bulelor interschimbam
matricele, vectorii de linii,coloane si sumele pentru a putea reface 
operatia de sortare si in viitor.
-Pentru inmultirea matricelor folosim algoritmul matematic in care 
elementele se obtin prin inmultirea urmata de adunarea
succesiva a termenilor de pe fiecare rand si coloana ,luati in ordinea
indicilor, din cele 2 matrice. 
Subprogramul multiply urmeaza modelul subprogramului include,
deoarece acum se modifica numarul matricelor din intreaga uniune de matrice,
prin adaugarea produsului. 

-Pentru obtinerea transpusei schimbam intre ei indicii corespunzatori
liniilor si coloanelor si adaugam matricea formata in memorie,in
locul celei vechi. La final modificam indicii corespunzatori matricei
date spre transpunere si in vectorii de linii si coloane.

-In cazul operatiei de ridicare la putere realizam o functie
pentru ridicarea la putere logaritmica. Se disting mai multe
cazuri:-daca puterea este 1 intoarcem aceeasi matrice. 
-daca puterea este para calculam mai intai patratul matricei,
rezultat pe care ramane sa il ridicam la puterea data supra 2,
in mod recursiv.  

-Daca puterea este impara inmultim rezultatul obtinut 
in cazul puterii pare(puterea fara o unitate este numar par)
cu matricea noastra. Rezultatul obtinut
il stocam intr-o matrice auxiliara denumita aux.
Functia power trateaza mai intai cazurile de exceptie si
apoi aloca memorie pentru rezultat pe care mai apoi il adauga
in uniunea noastra de matrice. 

-Pentru operatia indicata de caracterul F.dupa eliberarea memoriei
corespunzatoare unei matrice acoperim golul format atat in uniunea
noastra, cat si in vectorul de linii si coloane
prin mutarea tuturor elementelor cu ajutorul unui for si modificarea
succesiva a indicilor cu cate o unitate.  
-Pentru iesirea din program si dealocarea totala a memoriei folosim 
functia delete. 
