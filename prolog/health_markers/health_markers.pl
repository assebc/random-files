%utente(IdUtente,UtenteName,DataNascimento,Gender)
%ato(IdAto,Date,IdUtente,Age,Colesterol,Pulsacao,Pressao)
%marcador(IdMarcador,Analise,Age,Gender,Minimum,Maximum)

/*
 *
 * DO TO THE NEED OF WORKING AROUND NEGATIVE KNOWLEDGE YOU WILL NEED TO HAD MORE THINGS
 * SAME GOES FOR IMPERFECT KNOWLEDGE
 *
*/

% inserts utente into db file at db/utente.pl
insert_utente(IdUtente,Name,D/M/Y,Gender):- 
    (integer(IdUtente), 
    integer(D), 
    integer(M), 
    integer(Y), 
    gender(Gender)), 
    saveUtente(IdUtente,Name,D/M/Y,Gender).

% inserts ato into db file at db/ato.pl
insert_ato(Id,D/M/Y,IdUtente,Age,Colesterol,Pulsacao,P/P1) :- 
    (integer(D),
    integer(M),
    integer(Y),
    utente(IdUtente,_,_/_/Y1,_), 
    dates_difference(Y1,Y,Age), 
    integer(Colesterol), 
    integer(Pulsacao),
    integer(P),
    integer(P1)), saveAto(Id,D/M/Y,IdUtente,Age,Colesterol,Pulsacao,P/P1).

% inserts marcador into db file at db/marcador.pl
insert_marcador(Id,Analise,[A,A1],Gender,[Minimum,Maximum]):-
    (analise(Analise),
    integer(A),
    integer(A1),
    gender(Gender),
    integer(Minimum),
    integer(Maximum),
    B = [A,A1],
    C = [Minimum,Maximum]),
    saveMarcador(Id,Analise,B,Gender,C).

% check if is a valid gender
gender(Gender):-
    Gender = masculino;
    Gender = feminino.

% check if age is correct, comparing dates (lazy way)
dates_difference(Y1,Y,Age):-
    Age is (Y-Y1);
    Age is (Y-Y1-1).

% check if one of the possible types for analises (more to be added I guess)
analise(Analise):-
    Analise = colesterol;
    Analise = pulsacao;
    Analise = pressao.

% saves utente into file
saveUtente(A,B,C,D):-
    term_to_atom((A,B,C,D),J),
    string_atom(String,J),
    (open_s("db/utente.pl",append,Stream1),
    string_concat("\nutente(", String, Atm),
    string_concat(Atm,").",Final),
    write(Stream1,Final),
    close(Stream1)),!.

% saves ato into file
saveAto(A,B,C,D,E,F,G):-
    term_to_atom((A,B,C,D,E,F,G),J),
    string_atom(String,J),
    (open_s("db/ato.pl",append,Stream1),
    string_concat("\nato(", String, Atm),
    string_concat(Atm,").",Final),
    write(Stream1,Final),
    close(Stream1)),!.

% sabes marcador into file
saveMarcador(A,B,C,D,E):-
    term_to_atom((A,B,C,D,E),J),
    string_atom(String,J),
    (open_s("db/marcador.pl",append,Stream1),
    string_concat("\nmarcador(", String, Atm),
    string_concat(Atm,").",Final),
    write(Stream1,Final),
    close(Stream1)),!.

% open file using string bufferstream method
open_s(File,Mode,Stream) :-
    atom_string(File1,File),
    open(File1,Mode,Stream),!.

% transform atom to string
string_atom(String,Atom) :-
    atom_string(Atom,String),!.

% transform string into list of strings (split in python by some random pattern he finds)
string(String) --> list(String).

% recursivly build a list
list([]) --> [].
list([L|Ls]) --> [L], list(Ls).
      