ismember(X, [X|_]):-!.
ismember(X, [_|T]):- ismember(X, T).

remove(X, [X|T], T):-!.
remove(_, [], []):-!.
remove(X, [H|T], [H|L1]):-
	remove(X, T, L1).

removeAll(_, [], []):-!.
removeAll(X, [X|T], L1):-
	removeAll(X, T, L1).
removeAll(X, [H|T], [H|L1]):-
	removeAll(X, T, L1).

attach(X, [], [X]):-!.
attach(X, [H|T], [H|T1]):-
	attach(X, T, T1).

dp([X], [Y], [T]):-
	number(X);
	number(Y);
	T is X * Y;
	!.

dp([X|T1], [Y|T2], [Z|T3]):-
	number(X);
	number(Y);
	Z is X * Y;
	dp(T1, T2, T3).
