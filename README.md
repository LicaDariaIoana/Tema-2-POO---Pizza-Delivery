Enunțul Problemei:
Proiectul simulează un sistem prin care un angajat al unei pizzerii poate gestiona meniul și comenzile unei zile. Programul permite angajatului să vizualizeze meniul curent sau să îl modifice (adăugarea sau ștergerea de produse)
In momentul in care un client suna sa plaseze o comanda, angajatul creaza o comanda noua, introduce datele de contact (nume, adresă și un număr de telefon valid), si adaugă sau șterge produsele dorite de client Prețul total și durata de preparare sunt calculate si actualizate pe parcursul interacțiunii.
Daca se comanda o băutură cu alcool, programul avertizează angajatul sa întrebe clientul daca au peste 18 ani înainte de a permite adăugarea produsului (daca spun ca au, curierul va verifica buletinul). De asemenea, programul nu se blochează dacă utilizatorul introduce din greșeală litere în loc de cifre.

Mod de rezolvare și respectarea cerințelor:
Ierarhia claselor și funcții virtuale:
Am creat in fișiere separate (1.a, 1.b) o clasa abstracta numită produse, din care am derivate clasele pizza, bauturi si desert(2.a, 2.b). Clasele derivatele folosesc variabilele din clasa de bază, iar constructorii acestora apelează constructorul bazei pentru inițializarea membrilor (2.d). 
Am evitat folosirea std::char sau std::vector si in loc am folosit string si vec[]()2.e.3). Pentru calculul prețului, am folosit o funcție virtuala pură astfel încât fiecare clasă derivată să își calculeze prețul într-un mod specific (2.c.1). Operatorii << și >>(7), i-am supraîncărcat în clasa de bază. Aceștia apelează funcțiile virtuale citire() și afisare(), care sunt la rândul lor suprascrise în toate derivatele (2.c.2).

Clasa cu atribut de tip pointer la o clasă de bază cu derivate:
In clasa separata comenzi, am utilizat un vector de produse(2.e) si un obiect de tip client(din clasa separata client). Am folosit std::shared_ptr pentru a evita scurgerile de memorie(2.e.4). Această clasă are functii pentru:
-	calcularea prețului total și a timpului de preparare
-	sa retina numărului de comenzi prin variabile statice(4)
-	Interschimbarea a două comenzi (2.e.1)
-	 Adăugarea, ștergerea și afișarea produselor
La afișare și adăugare, am utilizat dynamic_cast pentru a afisa produsele pe categorii (pizza, bautura, desert) și pentru a verifica dacă produsul adăugat este de tip bautura pentru a arunca o excepție (2.e.2).
Tratarea excepțiilor
Am implementat o clasă de excepții custom pentru a gestiona trei scenarii (3.a): 
1) Erori de tip de date: Introducerea unui caracter non-numeric sau a unui număr negativ acolo unde se așteaptă un întreg;
 2) intreruperea comenzii daca se inceraca adăugarea la comanda o bautura alcoolica
3) numarul de telefonul introdus este invalid. 
Aceste au fost implementate folosind try respective catch in main(3.b)
Alte: Am folosit oriunde se putea “const” (5), am citit datele de intrare din fișiere separate(8) si am avut getter și setter doar acolo unde a fost strict necesar.
# Tema-2-POO---Pizza-Delivery
