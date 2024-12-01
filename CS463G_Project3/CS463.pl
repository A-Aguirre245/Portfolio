% child relation - (child, mother), (child, father)
child(oso, majo).         child(oso, luis).
child(concha, majo).      child(concha, luis).
child(majo, ale).         child(majo, andres).
child(arturo1, pita).     child(arturo1, arturo).
child(ale, pita).         child(ale, arturo).
child(andres1, juanis).   child(andres1, arturo1).
child(antonio, juanis).   child(antonio, arturo1).
child(arturo2, juanis).   child(arturo2, arturo1).
child(ahsoka, nicole).    child(ahsoka, antonio).
child(aero, lauren).      child(aero, arturo2).
child(arturo3, bertha).   child(arturo3, antonio1).
child(kini, bertha).      child(kini, antonio1).
child(juanis, bertha).    child(juanis, antonio1).
child(antonio2, bertha).  child(antonio2, antonio1).
child(angelica, bertha).  child(angelica, antonio1).
child(antonio4, kini).    child(antonio4, antonio3).
child(ceci, kini).        child(ceci, antonio3).
child(camila, kini).      child(camila, antonio3).
child(tadeo, ceci).       child(tadeo, jona).
child(star, ceci).        child(star, jona).
child(monica, yolanda).   child(monica, arturo3).
child(genaro, yolanda).   child(genaro, arturo3).
child(iris, monica).      child(iris, victor).
child(sami, angelica).    child(sami, flocelo).
child(valeria, angelica). child(valeria, flocelo).
child(toto, valeria).     child(toto, luis1).
child(chiquis, valeria).  child(chiquis, luis1).
child(andrea, rosa).      child(andrea, antonio2).
child(ale1, rosa).        child(ale1, antonio2).
child(gimena, andrea).    child(gimena, javier).
child(andres2, andrea).   child(andres2, javier).

% male - female
male(oso).     male(arturo1).    male(andres1).    male(antonio).   male(arturo2).
male(aero).    male(arturo3).    male(antonio2).   male(antonio4).  male(tadeo).
male(star).    male(genaro).     male(toto).       male(andres2).   male(flocelo).
male(andres).  male(arturo).     male(antonio3).   male(jona).      male(victor).
male(luis).    male(luis1).      male(javier).     male(antonio1).

female(ale).   female(bertha).   female(concha).   female(ahsoka).  female(kini).
female(ceci).  female(angelica). female(juanis).   female(camila).  female(iris).
female(sami).  female(monica).   female(valeria).  female(chiquis). female(pita).
female(ale1).  female(gimena).   female(nicole).   female(lauren).  female(rosa).
female(majo).  female(andrea).   female(yolanda).

% Ages of just children
age(oso, 2).
age(concha, 7).
age(majo, 22).
age(arturo1, 53).
age(ale, 55).
age(andres1, 19).
age(antonio, 22).
age(arturo2, 25).
age(ahsoka, 1).
age(aero, 1).
age(arturo3, 48).
age(kini, 50).
age(juanis, 57).
age(antonio2, 59).
age(angelica, 62).
age(antonio4, 22).
age(ceci, 18).
age(camila, 14).
age(tadeo, 5).
age(star, 3).
age(monica, 20).
age(genaro, 9).
age(iris, 3).
age(sami, 23).
age(valeria, 27).
age(toto, 4).
age(chiquis, 5).
age(andrea, 29).
age(ale1, 31).
age(gimena, 6).
age(andres2, 10).

% parent - child(child, parent)    grandparent - parent of parent
% father - male & parent       mother - female & parent
parent(P, X):-child(X, P).
father(F, X):-male(F), parent(F, X).
mother(M, X):-female(M), parent(M, X).
grandparent(G, X):-parent(G, P), parent(P, X).

% sibling - if X and Y have the same father and mother, and X and Y are
% not the same child and in lexigographical order (to avoid duplicates)
sibling(X, Y):-father(F, X), mother(M, X), father(F, Y), mother(M, Y),  X \= Y,
    X @< Y.

%if parent of two people are siblings, they are first cousins,
%else find the common nth-grandparent, they are nth cousins,
nthCousin(X, Y, 1):-parent(F, X), parent(M, Y), sibling(F, M).
nthCousin(X, Y, N):-N > 1; N1 is N - 1, parent(FX, X), parent(MY, Y),
    nthCousin(FX, MY, N1).

%if k is 0, no removal, just nth cousins
%goes up either x or y's parents to find a common ancestor
nthCousinKTimesRemoved(X, Y, N, 0):-nthCousin(X, Y, N).
nthCousinKTimesRemoved(X, Y, N, K):-K1 is K-1, parent(PX, X),
    nthCousinKTimesRemoved(PX, Y, N, K1).
nthCousinKTimesRemoved(X, Y, N, K):- K1 is K-1, parent(PY, Y),
    nthCousinKTimesRemoved(X, PY, N, K1).

%Insert C into empty list
% or insert C into list Y|O, where Y is youngest (head) and O is
% older children (tail). If C is younger than Y, it becomes the new
% head. If C is older, call sortedInsert on the Child again, but
% compare to the head of the tail,
sortedInsert(C, [], [C]).
sortedInsert(C, [Y|O], [C, Y|O]):-age(C, A), age(Y, B),
    A =< B.
sortedInsert(Child, [Y|O], [Y | Older]):-age(Child, A), age(Y, B),
    A > B, sortedInsert(Child, O, Older).

% inserts the head of the children list, C, into SortedC which contains
% the list of all the children of parent P. (Since parents are mother
% and fathers, each list of children appears twice, once for mom/dad.
sortChildren([], []).
sortChildren([C|Children], SortedC):-sortChildren(Children, SortedChildren),
    sortedInsert(C, SortedChildren, SortedC).

kthChild(C, P, K):-setof(Child, child(Child, P), Children),
    sortChildren(Children, SortedChildren), nth1(K, SortedChildren, C).























