computation(P, [], P).

computation(P, [H|T], Q):-
	transition(P, H, X),
	computation(X, T, Q).

accept_p(S):-
	computation(p1, S, F),
	final(F).

accept_q(S):-
	computation(q1, S, F),
	final(F).

accept_r(S):-
	computation(r1, S, F),
	final(F).
