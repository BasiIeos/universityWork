/* transitions for Finite Automaton fa_p */

transition(p1,a,p2).
transition(p1,b,p1).
transition(p2,a,p1).
transition(p2,b,p2).

final(p1).

/* transitions for FA fa_q */

transition(q1, a, q1).
transition(q1, b, q2).

transition(q2, b, q2).
transition(q2, a, q3).

transition(q3, a, q4).
transition(q3, b, q2).

transition(q4, b, q5).
transition(q4, a, q1).

transition(q5, a, q5).
transition(q5, b, q5).

final(q5).

/* transitions for FA fa_r */

transition(r1, a, r1).

transition(r1, b, r2).
transition(r2, a, r3).
transition(r2, b, r3).
transition(r3, b, r2).

final(r1).
final(r3).
