CC=swipl
FLAGS=--goal=main --stand_alone=true --quiet
EXE=movie
FILE=main.pl

$(EXE): $(FILE)
	$(CC) $(FLAGS) -o $@ -c $^

clean:
	-@$(RM) $(EXE) 2>/dev/null
