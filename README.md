# PATema1
Repository folosit pentru a incarca proiectul LanParty de la PA
# OBIECTIVE:
Înțelegerea conceptului de funcționare și implementare a unor structuri de date(precum liste, stive, cozi, arbori binari de căutare)
Operarea cu aceste structuri de date
Implementarea unei funcționalități practice folosind aceste concepte
# DESCRIERE:
Facultatea de Automatica si Calculatoare prin LSAC organizează in fiecare semestru un LAN Party la care participă toți studenții care vor sa își testeze abilitățile la un anumit joc. 
Se dorește realizarea unei soluții software(program executabil) ce poate automatiza acest proces.
# CERINTE:
1)Se va crea o listă cu informațiile din fișierul d.in(lista se va forma prin adaugarea elementelor la inceput - O(1)).
2)Se vor elimina din lista anterior creată, echipele cu cel mai mic punctaj de echipă astfel incat in lista sa ramana n echipe (unde n maxim si n este putere a lui 2).În cazul în care mai multe echipe au acelasi scor se elimina prima echipă gasita in lista. 
Dupa fiecare eliminare se va relua parcurgerea listei de la cap.
3)Se vor implementa structurile de date necesare pentru a se efectua meciurile:
->Se va crea o coadă în care se vor pune meciurile dintre echipe.
->Echipele vor forma meciuri în ordinea în care se află în lista de la punctul anterior, primele două echipe vor forma primul meci (și așa mai departe).
->Se vor crea două stive - una pentru învinși și una pentru câștigători - ce vor conține echipele ce au pierdut, respectiv, au câștigat meciul anterior.
->Se vor introduce în stivă echipele în funcție de rezultatul obținut și se va adauga un punct la punctajul de echipă al echipelor ce au câștigat.
->In cazul unui meci in care ambele echipe au acelasi punctaj, se va alege prima echipa adaugata in meciul disputat.
->Se vor șterge echipele ce se găsesc în stiva de învinși. (la finalul fiecărei etape; ex: dintr-o runda cu 8 echipe, stergerea se face dupa ce au fost eliminate toate echipele. 
In acest caz, dupa ce au fost eliminate 4 dintre echipe, se vor sterge. In runda urmatoare, pe acest exemplu, se vor adauga 2 echipe in stiva de invinsi, dupa care o sa fie eliberata din nou - stiva de invinsi -.)
->Din stiva de câștigători se vor extrage echipele și se va umple din nou coada de meciuri formându-se meciuri cu echipele consecutive (prima echipă scoasă din stivă va juca cu a doua echipa scoasă din stivă primul meci).
->Se vor repeta pașii enumerați pana la aflarea echipelor de pe primele 8 locuri, care vor fi salvate intr-o alta lista, dupa aflarea acestora se vor continua meciurile pana la aflarea echipei castigatoare.
4)Se va realiza un clasament al ultimelor 8 echipe (salvate la subpunctul anterior) sub forma unui BST(Binary Search Tree). 
Acesta va fi ordonat după punctajul pe echipă și i se va afișa conținutul în ordine descrescătoare(in cazul in care doua echipe au acelasi punctaj se vor ordona in functie de nume, descrescator).
5)Se va realiza un arbore de tip AVL cu ultimele 8 echipe (salvate la subpunctul 3, dar sortate ca la subpunctul 4) si se vor afisa echipele de pe nivelul 2 al arborelui.
# FUNCTIONALITATE:
## 0)main():
-deschid cele 3 fisiere cu argumente in lina de comanda;
-creez un vector care va citi datele din fisierele c.in al fiecarui test(imi spune ce task trebuie facut pentru fiecare test)
-gestionez implementarea fiecarui task
-gestionez eliberarea memoriei pentru structurile create;
## 1)TASK1
-am creeat o functie care citeste elementele din d.in al fiecarui test,creeaza o lista simplu inlantuita si adauga elementele la inceputul listei(citirea elementelor din fisier se face cu ajutorul unor vectori, pe care ii copiez in structura mea);
-in main():apelez functia de creeare a listei, o parcurg si afisez, in ordine, numele echipelor; salvez nr de echipe;
-gestionez eliberarea memoriei pentru structurile create;
## 2)TASK2:
-implementez o functie care calculeaza punctele fiecarei echipe(media aritmetica a punctelor jucatorilor);
-functie care calculeaza numarul de echipe ce trebuie sa ramana in fisier dupa stergere(cea mai mare putere a lui 2, mai mica sau egala cu nr. de echipe din fisier);
-functie care imi calculeaza punctajul maxim al fiecarei echipe;
-functie de eliminare a echipelor:sterge din liosta echipele care au un punctaj minim(calculat cu functia de mai sus);
-in main():apelez functia care imi determina cate echipe raman in fisier si functia de eliminare a echipelor din lista, si afisez lista actualizata;
## 3)TASK3:
-creez structurile specifice stivelor si cozilor si implementez functiile din curs(push,pop,enQueue,deQueue,isEmpty,createQueue,createStack,deleteStack), diferenta constand ca valoarea de tip "Data val" este inlocuita cu un pointer la lista de echipe;
-gestionez separat prima runda:
   ~creez coada meciurilor;
   ~elementele cozii vor fi adaugate din lista de echipe facuta la task-ul 2;
   ~afisez meciurile din prima runda;
   ~compar punctajele celor 2 echipe analizate, si in functie de valori le adaug in stiva de castigatori/invinsi;
   ~afisez castigatorii primei runde(din stiva de castigatori);
   ~sterg stiva invinsilor;
   ~actualizez nr de echipe ramase;
-gestionez celelalte runde, pana ramane o singura echipa in coada(cea castigatoare):
   ~reactualizez coada meciurilor:aceasta va fi creata din stiva de castigatori salvata in prima functie;
   ~afisez meciurile din fiecarte runda;
   ~reactualizez stivele de castigatori/invinsi(similar ca in prima functie);
   ~afisez stivele de castigatori pentru fiecare runda;
   ~sterg stivele invinsilor;
   ~actualizez nr de echipe ramase;
   !DACA MAI EXISTA DOAR 8 ECHIPE-creez o lista numita top8(pe care  o voi folosi mai tarziu);fac acest lucru cu functia din curs addAtBeginning;
-in main():apelez functiile de gestionare a rundelor si salvez lista cu ultimele 8 echipe;
## 4)TASK4:
-creez un arbore BST(Binary Search Treee) cu lista ultimelor 8 echipe ramase salvata la punctul 3;
-afisez elementele in ordine descrescatoare dupa nr de puncte(modific parcurgere in preordine astfel incat sa merg mai intai pe dreapta, apoi sa afisez radacina si in cele din urma sa merg pe ramura stanga);
-in main():apelez functiile pentru a afisa elementele arborelui in ordinea ceruta;
## 5)TASK5:
-folosind lista creeata la task-ul 3 pentru a creea un arbore AVL, si afisez echipele de pe cel de-al doilea nivel al arborelui-afisate in ordine descrescatoare;
-in main():apelez functiile pentru a afisa echipele de pe nivelul 2 al AVL-ului;
# DIFICULTATI:
-lucrul cu WSL;
-lucrul cu checker;
-lucrul cu argumente in linia de comanda;
-implementarea unor functii scurte si exacte;
-inchiderea si deschiderea fisierelor de scriere;
-gestionarea corecta a free-urilor;
-gestionarea spatiilor si a newline-urilor;
-gestionarea arborilor BST si AVL in cazul in care echipele au un nr egal de puncte;
