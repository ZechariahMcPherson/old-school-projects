%Creater: Gregory Zechariah McPherson


%tells swipl that scattered male,female, marrid, and parent around on purpose
:-discontiguous(male/1),discontiguous(female/1),discontiguous(married/2), discontiguous(parent/2).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Potter
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%male
male(fleamont_potter).
male(james_potter).
male(harry_potter).
male(albus_potter).
male(james_ii_potter).


%female
female(euphemia_potter).
female(lily_evans).
female(ginny_weasley).
female(lily_potter).

%married
married(fleamont_potter, euphemia_potter).
married(euphemia_potter, fleamont_potter).
married(james_potter, lily_evans).
married(lily_evans, james_potter).
married(harry_potter, ginny_weasley).
married(ginny_weasley, harry_potter).


%parent(parent, child)
parent(fleamont_potter, james_potter).
parent(euphemia_potter, james_potter).
parent(james_potter, harry_potter).
parent(lily_evans, harry_potter).
parent(harry_potter, albus_potter).
parent(harry_potter, james_ii_potter).
parent(harry_potter, lily_potter).
parent(ginny_weasley, albus_potter).
parent(ginny_weasley, james_ii_potter).
parent(ginny_weasley, lily_potter).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%weasley
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%male
male(arthur_weasley).
male(bill_weasley).
male(charlie_weasley).
male(percy_weasley).
male(george_weasley).
male(fred_weasley).
male(ron_weasley).
male(hugo_weasley).

%female
female(molly_prewett).
%already added ginny weasley above
female(hermione_granger).
female(rose_weasley).

%married
married(arthur_weasley, molly_prewett).
married(molly_prewett, arthur_weasley).
married(ron_weasley, hermione_granger).
married(hermione_granger, ron_weasley).


%parent(parent, child)
parent(arthur_weasley, bill_weasley).
parent(arthur_weasley, charlie_weasley).
parent(arthur_weasley, percy_weasley).
parent(arthur_weasley, george_weasley).
parent(arthur_weasley, fred_weasley).
parent(arthur_weasley, ron_weasley).
parent(arthur_weasley, ginny_weasley).
parent(molly_prewett, bill_weasley).
parent(molly_prewett, charlie_weasley).
parent(molly_prewett, percy_weasley).
parent(molly_prewett, george_weasley).
parent(molly_prewett, fred_weasley).
parent(molly_prewett, ron_weasley).
parent(molly_prewett, ginny_weasley).
parent(ron_weasley, rose_weasley).
parent(ron_weasley, hugo_weasley).
parent(hermione_granger, rose_weasley).
parent(hermione_granger, hugo_weasley).


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%granger
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%male
male(mr_granger).

%female
female(mrs_granger).
%already added hermione above

%married
married(mr_granger, mrs_granger).
married(mrs_granger, mr_granger).

%parent(parent, child)
parent(mr_granger, hermione_granger).
parent(mrs_granger, hermione_granger).

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%predicates
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Spouse is  Persons
spouse(Person, Spouse) :- married(Person, Spouse).

%Father is Persons Father
father(Person, Father) :- male(Father), parent(Father, Person).

%Person is the the child of Mother
mother(Person, Mother) :- female(Mother), parent(Mother, Person).

%Brother is the brother of Person
brother(Person,Brother) :- male(Brother), parent(Parent, Person), parent(Parent, Brother).

%Sister is the sister of Person
sister(Person, Sister) :- female(Sister), parent(Parent, Person), parent(Parent, Sister).

%Child is the child of Person
child(Person, Child) :- parent(Person, Child).

%Son is the son of Person
son(Person, Son) :- male(Son), child(Person, Son).

%Daughter is the daugther of Person
daughter(Person, Daughter) :- female(Daughter), parent(Person, Daughter).

%Grandchild is the grandchild of Person
grandchild(Person, Grandchild) :- parent(Parent, Grandchild), parent(Person, Parent).

%Grandson is the grandson of Person
grandson(Person, Grandson) :-  male(Grandson), grandchild(Person, Grandson).

%Granddaughter is the granddaughter of Person
granddaughter(Person, Granddaughter) :- female(Granddaughter), grandchild(Person, Granddaughter).

%Sibling is the sibling of Person
sibling(Person, Sibling) :- parent(Parent, Person), parent(Parent, Sibling), \+ Sibling=Person.

%Grandparent is the grandparent of Person
grandparent(Person, Grandparent) :- parent(Parent, Person), parent(Grandparent, Parent).

%Grandfather is the grandfather of Person
grandfather(Person, Grandfather) :- grandparent(Person, Grandfather), male(Grandfather).

%Grandmother is the grandmother of Person
grandmother(Person, Grandmother) :- grandparent(Person, Grandmother), female(Grandmother).

%BrotherInLaw is the brother-in-law of Person
brother-in-law(Person, BrotherInLaw) :- male(BrotherInLaw), sibling(Person, Sibling), \+ Person=Sibling,
spouse(BrotherInLaw, Sibling).

%SisterInlaw is the sister-in-law of Person
sister-in-law(Person, SisterInLaw) :- female(SisterInLaw), sibling(Person, Sibling), \+ Person=Sibling,
spouse(SisterInLaw, Sibling).

%Aunt is the aunt of Person
aunt(Person, Aunt) :- female(Aunt), parent(Parent, Person), sibling(Parent, Aunt).

%Uncle is the uncle of Person
uncle(Person, Uncle) :- male(Uncle), parent(Parent, Person), sibling(Parent, Uncle).

%Niece is the niece of Person
niece(Person, Niece) :- female(Niece), parent(Parent, Niece), sibling(Parent, Person).

%Nephew is the nephew of Person
nephew(Person, Nephew) :- male(Nephew), parent(Parent, Nephew), sibling(Parent, Person).
