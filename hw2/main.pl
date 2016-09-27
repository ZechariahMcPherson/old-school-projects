%Creator: Gregory Zechariah McPherson

%loads knowlege base
:- [movie].

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

        %1
        write("1. Did Leonardo DiCaprio act in Babel?"), nl,

        print_query_true((acted_in(leonardo_dicaprio,babel))), nl,
        print_query_false((acted_in(leonardo_dicaprio,babel))), nl,

        %2
        write("2. Who directed District 9"), nl,

        print_query_true((directed(Director,district_9))), nl,
        print_query_false((directed(Director,district_9))), nl,

        %3
        write("3. Did anyone act in both Click and The Aviator"), nl,

        print_query_true((acted_in(Actor,click),acted_in(Actor,the_aviator))), nl,
        print_query_false((acted_in(Actor,click),acted_in(Actor,the_aviator))), nl,

        %4
        write("4. Was there a movie released in 2010 that did not star Jennifer Aniston?"), nl,

        print_query_true((released(Movie,2010),acted_in(Actor,Movie), \+ Actor=jennifer_aniston)), nl,
        print_query_false((released(Movie,2010),acted_in(Actor,Movie), \+ Actor=jennifer_aniston)), nl,

        %5
        write("5. Who directed movies released in 2009?"), nl,

        print_query_true((released(Movie,2009),directed(Director,Movie))), nl,
        print_query_false((released(Movie,2009),directed(Director,Movie))), nl,

        %6
        write("6. Has anyone directed more than one movie?"), nl,

        print_query_true((directed(Director,Movie1),directed(Director,Movie2), \+ Movie1=Movie2)), nl,
        print_query_false((directed(Director,Movie1), directed(Director,Movie2), \+ Movie1=Movie2)), nl,

        %7
        write("7. Does any movie have more than one director?"), nl,

        print_query_true((directed(Director1,Movie), directed(Director2,Movie), \+ Director1=Director2)), nl,
        print_query_false((directed(Director1,Movie), directed(Director2,Movie), \+ Director1=Director2)), nl,

        %8
        write("8. Has anyone acted in more than one movie released in 2008"), nl,

        print_query_true((released(Movie1,2008), acted_in(Actor,Movie1),
        released(Movie2,2008), acted_in(Actor,Movie2), \+ Movie1=Movie2)), nl,

        print_query_false((released(Movie1,2008), acted_in(Actor,Movie1),
        released(Movie2,2008), acted_in(Actor,Movie2), \+ Movie1=Movie2)), nl,

        %9
        write("9. Has anyone acted in more than two movies in the same year?"), nl,

        print_query_true((released(Movie1,Year), acted_in(Actor,Movie1), released(Movie2,Year),
        acted_in(Movie3,Year), acted_in(Actor,Movie3),\+ Movie1=Movie2, \+ Movie1=Movie3, \+ Movie2=Movie3)), nl,

        print_query_false((released(Movie1,Year), acted_in(Actor,Movie1), released(Movie2,Year),
        acted_in(Movie3,Year), acted_in(Actor,Movie3),\+ Movie1=Movie2, \+ Movie1=Movie3, \+ Movie2=Movie3)), nl,

        %10
        write("10. Who has worked with the same director in different years?"), nl,

        print_query_true((released(Movie1,Year1), directed(Director,Movie1), acted_in(Actor,Movie1), released(Movie2,Year2),
        directed(Director,Movie2), acted_in(Actor,Movie2), \+ Year1=Year2, \+ Movie1=Movie2)), nl,

        print_query_false((released(Movie1,Year1),directed(Director,Movie1),acted_in(Actor,Movie1),released(Movie2,Year2),
        directed(Director,Movie2),acted_in(Actor,Movie2), \+ Year1=Year2, \+ Movie1=Movie2)), nl.

    %if the user selects option three which is exit the program halts
    run_opt(3) :- write('Goodbye'), nl, halt.

    %a catch all for any input that is not 1,2,3 and exits the program
    run_opt(_) :- write('Invalid option'), nl, halt.

    %menu system that allows for user
    main :-
        nl,
        write('>   Enter a selection followed by a period.'), nl,
        write('>   1. Run a query'), nl,
        write('>   2. Run show homework with answers'), nl,
        write('>   3. Exit'), nl, nl,
        read(Choice),
        run_opt(Choice), main.
