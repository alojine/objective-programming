# objective-programming
Repository created for objective programming using C++

# v0.1
Šioje versijoje uždavinys buvo sprendžiamas dviem budais:
1. Cmasyvo būdu **Cmasyvas.cpp** faile - Studento duomenys saugomi struktūroje *data*
2. Vektorių būdu **Vektoriai.cpp** faile - Studento duomenys saugomi *data* tipo *vektoriuje*

Programa turi 7 funkcijas: input, output, mediana, vidurkis, select, addmark, genrandom. Programa paklausia vartotojo kiek jis noretų sugeneruoti studentų, paprašo įvesti vardą, pavardę, pažymių kiekį(po įvedimo galime pasirinkti ar norime papildytį kiekį), pasirenkame kaip vesti rezultatą, medianos ar vidurkio metodu.

Į terminalą išvedami šie duomenys: *Vardas*, *Pavardė*, *Galutinis rezultatas*(Vidurkis/Mediana).

# v0.2
Šioje versijoje kodas yra atnaujintas, pridėtas skaitymas ir rašymas į failą. 

Paleidus programa vartotojo paklausiama ar jis nori skaityti studentus iš failo:

Jei **ne**: vyksta praeitos versijos **v0.1** skaitymas iš terminalo.

Jei **taip**: Nuskaitomas failas *studentai.txt*, į failą *kursiokai.txt* išvedamas studento vardas, pavardė, galutinis vidukis ir mediana.

# v0.3
Šioje versijoje atliktas praeitos versijos(v0.2) kodo refactoringas. Programa veikia tuo pačiu principu, tačiau yra išskaidyta į header, resource ir source failus.
1. Pagrindinis failas: *Source.cpp* savyje laiko header failus ir pagrindinę main funkcija kurioje atliktas exception handling skaitymui ir rašymui į failą.
2. Aplanke: *Headers* yra visi programai reikalingi header(.h) failai.
3. Aplanke: *Resources* yra visi programai reikalingi papildomi (.cpp) faila kuriuose aprašytos funkcijos.

# v0.4
Šioje versijoje sukurtas failu generatorius ir matuojami programos vykdymo laikai.
Vartotojas pasirenka generuoti failą automatiškai.
Vartotojas pasirenka naudoti failų generatorių.
Vartotojas iveda failo pavadinimą ir kiekį studentų kuriuos nori sugeneruoti.

Programos kodas yra isskaidytas į tris pagrindinius failus:
1. Pagrindinis failas *Source.cpp* laiko (header) antraštes ir main funkciją.
2. *functions.cpp* laiko savyje funkcijų aprašus.
3. *headers.h* laiko savyje funkcijų antraštes
4. Failo skaitymas vyksta iš ivesto failo. Pvz: studentai100000.txt.
5. Failo išvedimas vyksta į du skirtingus failus: *kietiakai.txt*(studentams kurių galutinis balas >= 5.0) ir *nuskriaustukai.txt* (studentams kurių galutinis balas < 5.0).

Testavimui generuojami 5 atsitiktiniai studentų pažymiai.
Programos laikas nustatomas šiems kriterijams:
1. Failo kūrimui ir jo uždarymui.
2. Duomenų nuskaitymui iš failo.
3. Studentų rušiavimui į grupes.
4. Surušiuotų studentų išvedimą į du failus.
5. Visos programos laikas.

VECTOR
1000
<br>
Failo sudarymas uztruko: 0.0263304 s <br>
Failo nuskaitymas uztruko: 0.0062851 s <br>
Failo skirstymas i grupes uztruko: 0.0001799 s <br>
kietiakai.txt surasymas uztruko: 0.0010151 s <br>
nuskriaustukai.txt surasymas uztruko: 0.0052932 s <br>
Visa programa uztruko 0.0450208 s <br>

10000
<br>
Failo sudarymas uztruko: 0.395983 s <br>
Failo nuskaitymas uztruko: 0.0949548 s <br>
Failo skirstymas i grupes uztruko: 0.0021033 s <br>
kietiakai.txt surasymas uztruko: 0.0077206 s
nuskriaustukai.txt surasymas uztruko: 0.0415379 s <br>
Visa programa uztruko 0.571244 s <br>

100000
<br>
Failo sudarymas uztruko: 2.92119 s <br>
Failo nuskaitymas uztruko: 0.675066 s <br>
Failo skirstymas i grupes uztruko: 0.0210955 s <br>
kietiakai.txt surasymas uztruko: 0.0866178 s <br>
nuskriaustukai.txt surasymas uztruko: 0.389649 s <br>
Visa programa uztruko 4.16463 s <br>

1000000
<br>
Failo sudarymas uztruko: 38.2789 s <br>
Failo nuskaitymas uztruko: 13.4123 s <br>
Failo skirstymas i grupes uztruko: 0.267259 s <br>
kietiakai.txt surasymas uztruko: 0.937183 s <br>
nuskriaustukai.txt surasymas uztruko: 4.50081 s <br>
Visa programa uztruko 58.4967 s <br>

# v0.5
Programa atnaujinta galima rinktis konteinerio tipą į kurį vartotojas nori išsaugoti studentą
Palaidus programą:
1. Ar norite skityti duomenis is failo? (y/n) y
2. Ar norite ivesti faila? (y/n) y
3. Koki konteinerio tipa norite naudoti? vector - 'v', deque - 'd', list - 'l':
studentas išsaugomas į konteinerį tą kurio pirmąją raidę iveda.

Konteinerių spartos lyginimas:
<br>
|                     |       1000      |      10000     |     100000    |   1000000   |   10000000  |
| ------------------- | --------------- | -------------- | ------------- | ----------- | ----------- |
|VECTOR NUSKAITYMAS   |   0.0062851 s   |   0.0949548 s  |  0.675066 s   |  13.4123 s  |   29.3115 s |
|VECTOR RŪŠIAVIMAS    |   0.0001799 s   |   0.0021033 s  |  0.0210955 s  |  0.267259 s |   3.49287 s |
|DEQUE NUSKAITYMAS    |   0.0055681 s   |   0.0612086 s  |  0.913985 s   |  12.7429 s  |   33.2916 s |
|DEQUE RŪŠIAVIMAS     |   0.0001259 s   |   0.0011858 s  |  0.0220048 s  |  0.224872 s |   2.86732 s |
|LIST NUSKAITYMAS     |   0.0066457 s   |   0.0608856 s  |  0.760501 s   |  14.6578 s  |   35.2291 s |
|LIST RŪŠIAVIMAS      |   0.0001457 s   |   0.0014011 s  |  0.0190997 s  |  0.34972 s  |   2.98854 s |


Parametrai:
- CPU: Intel Core i5-10300H 2.5 GHz
- SSD: 476GB SAMSUNG MZVLQ512HALU
- RAM: 8GB 2933MHz

# v1.0
## Testavimai ##

### Naudojant pirmąją strategiją ###

|                     |       1000      |      10000     |     100000    |   1000000   |   10000000  |
| ------------------- | --------------- | -------------- | ------------- | ----------- | ----------- |
|VECTOR RŪŠIAVIMAS    |   0.0001401 s   |   0.0015573 s  |  0.0247494 s  |  0.259231 s |   3.27844 s |
|DEQUE RŪŠIAVIMAS     |   0.0001259 s   |   0.0008211 s  |  0.134224 s   |  0.134224 s |   3.06859 s |
|LIST RŪŠIAVIMAS      |   0.0010098 s   |   0.0014011 s  |  0.228691 s   |  0.228691 s |   2.26937 s |


### Naudojant antrąją strategiją ###

|                     |       1000      |      10000     |     100000    |   1000000   |   10000000  |
| ------------------- | --------------- | -------------- | ------------- | ----------- | ----------- |
|VECTOR RŪŠIAVIMAS    |   0.0001413 s   |   0.0008275 s  |  0.0175047 s  |  0.222046 s |   2.75799 s |
|DEQUE RŪŠIAVIMAS     |   0.0001771 s   |   0.001222 s   |  0.0185876 s  |  0.190788 s |   2.16689 s |
|LIST RŪŠIAVIMAS      |   0.0001098 s   |   0.000711 s  |  0.0170997 s  |  0.18972 s  |   2.08854 s |


### Programos veikomo laikas be generavimo ###

|                     |       1000      |      10000     |     100000    |   1000000   |   10000000  |
| ------------------- | --------------- | -------------- | ------------- | ----------- | ----------- |
|VECTOR               |   0.0797068 s   |   0.083429 s   |  0.54483 s    |  5.3933 s   |   54.824 s  |
|DEQUE                |   0.0978551 s   |   0.087919 s   |  0.55718 s    |  5.9456 s   |   59.228 s  |
|LIST                 |   0.0637336 s   |   0.0711814 s  |  0.5301 s     |  5.6935 s   |   52.579 s  |
