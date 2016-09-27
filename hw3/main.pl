%Creator: Gregory Zechariah McPherson

%loads knowlege base
:- [potter].

%prints true if the query is true
print_query_true(Q) :-
    forall(Q, writeln(true:Q)),nl.

%prints false if the query is false
print_query_false(Q) :-
    forall(\+ Q, writeln(false:Q)),nl.

    %allows user to enter a query and run it against my knowledge base
    run_opt(1) :-
        write('>   Enter a query followed by a period.'), nl,
        read(Query),
        print_query_true((Query)), nl,
        print_query_false((Query)), nl.

    %prints out homework assignments and their answers
    run_opt(2) :-

      %Spouse
      write("spouse(harry_potter, Spouse)"), nl,
      print_query_true(spouse(harry_potter, Spouse)), nl,
      print_query_false(spouse(harry_potter, Spouse)), nl,

      %father
      write("father(ginny_weasley, Father)"), nl,
      print_query_true(father(ginny_weasley, Father)), nl,
      print_query_false(father(ginny_weasley, Father)), nl,

      %mother
      write("mother(hermione_granger, Mother)"), nl,
      print_query_true(mother(hermione_granger, Mother)), nl,
      print_query_false(mother(hermione_granger, Mother)), nl,

      %brother
      write("brother(ron_weasley, Brother)"), nl,
      print_query_true(brother(ron_weasley, Brother)), nl,
      print_query_false(brother(ron_weasley, Brother)), nl,

      %sister
      write("sister(george_weasley, Sister)"), nl,
      print_query_true(sister(george_weasley, Sister)), nl,
      print_query_false(sister(george_weasley, Sister)), nl,

      %child
      write("child(harry_potter, Child)"), nl,
      print_query_true(child(harry_potter, Child)), nl,
      print_query_false(child(harry_potter, Child)), nl,

      %son
      write("son(harry_potter, Son)"), nl,
      print_query_true(son(harry_potter, Son)), nl,
      print_query_false(son(harry_potter, Son)), nl,

      %daughter
      write("daughter(molly_prewett, Daughter)"), nl,
      print_query_true(daughter(molly_prewett, Daughter)), nl,
      print_query_false(daughter(molly_prewett, Daughter)), nl,

      %grandchild
      write("grandchild(molly_prewett, Grandchild)"), nl,
      print_query_true(grandchild(molly_prewett, Grandchild)), nl,
      print_query_false(grandchild(molly_prewett, Grandchild)), nl,

      %grandson
      write("grandson(molly_prewett, Grandson)"), nl,
      print_query_true(grandson(molly_prewett, Grandson)), nl,
      print_query_false(grandson(molly_prewett, Grandson)), nl,

      %granddaughter
      write("granddaughter(lily_evans, Granddaughter)"), nl,
      print_query_true(granddaughter(lily_evans, Granddaughter)), nl,
      print_query_false(granddaughter(lily_evans, Granddaughter)), nl,

      %sibling
      write("sibling(ron_weasley, Sibling)"), nl,
      print_query_true(sibling(ron_weasley, Sibling)), nl,
      print_query_false(sibling(ron_weasley, Sibling)), nl,

      %grandparent
      write("grandparent(james_ii_potter, Grandparent)"), nl,
      print_query_true(grandparent(james_ii_potter, Grandparent)), nl,
      print_query_false(grandparent(james_ii_potter, Grandparent)), nl,

      %grandfather
      write("grandfather(james_ii_potter, Grandfather)"), nl,
      print_query_true(grandfather(james_ii_potter, Grandfather)), nl,
      print_query_false(grandfather(james_ii_potter, Grandfather)), nl,

      %grandmother
      write("grandmother(james_ii_potter, Grandmother)"), nl,
      print_query_true(grandmother(james_ii_potter, Grandmother)), nl,
      print_query_false(grandmother(james_ii_potter, Grandmother)), nl,

      %brother-in-law
      write("brother-in-law(ron_weasley, BrotherInLaw)"), nl,
      print_query_true(brother-in-law(ron_weasley, BrotherInLaw)), nl,
      print_query_false(brother-in-law(ron_weasley, BrotherInLaw)), nl,

      %Sister-in-law
      write("sister-in-law(ron_weasley, SisterInLaw)"), nl,
      print_query_true(sister-in-law(ron_weasley, SisterInLaw)), nl,
      print_query_false(sister-in-law(ron_weasley, SisterInLaw)), nl,

      %Aunt
      write("aunt(rose_weasley, Aunt)"), nl,
      print_query_true(aunt(rose_weasley, Aunt)), nl,
      print_query_false(aunt(rose_weasley, Aunt)), nl.

    %if the user selects option nine the program exits per your instructions
    run_opt(9) :- write('Goodbye'), nl, halt.

    %a catch all for any input that is not 1,2 or 9 and exits the program
    run_opt(_) :- write('Invalid option'), nl, halt.

    %menu system
    main :-
        nl,
        write('>   Enter a selection followed by a period.'), nl,
        write('>   1. Run a query'), nl,
        write('>   2. Run test cases'), nl,
        write('>   9. Exit'), nl, nl,
        read(Choice),
        run_opt(Choice), main.
