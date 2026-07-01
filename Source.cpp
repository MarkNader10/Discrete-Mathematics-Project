#include<iostream>;
using namespace std;

int Negation(int x) {
	return 1 - x;
}
// Conjunction (AND)
int Conjunction(int a, int b) {
	return a & b;  // AND
}
// Disjunction (OR)
int Disjunction(int a, int b) {
	return a | b;  // OR
}
int Implication(int a, int b) {
	return (!a) | b;
}
char TF(int x) {
	return x ? 'T' : 'F';
}
int main(void) {
	int p, q, r, LHS, RHS;
	string ST;
	cout << "Welcome to Project Code\n";
	cout << "The equation is NOT [p -> (NOT q AND NOT r)] == p AND [(q -> r) -> r]\n";
	cout << "Enter T for True or false truth table or Enter 1 for 1 or 0 truth table\n";
	cin >> ST;
	cout << "p	q	r	LHS	  RHS\n";
	for (int p = 1; p >= 0; p--) {
		for (int q = 1; q >= 0; q--) {
			for (int r = 1; r >= 0; r--) {
				Negation(q);
				Negation(r);
				Conjunction(Negation(q), Negation(r));
				Implication(p, Conjunction(Negation(q), Negation(r)));
				LHS = Negation(Implication(p, Conjunction(Negation(q), Negation(r))));
				Implication(q, r);
				Implication(Implication(q, r), r);
				RHS = Conjunction(p, Implication(Implication(q, r), r));
				if (ST == "T" || ST == "t") {
					// طباعة T / F
					cout << TF(p) << "\t" << TF(q) << "\t" << TF(r)
						<< "\t " << TF(LHS) << "\t   " << TF(RHS) << endl;
				}
				else {
					// طباعة 0 / 1
					cout << p << "\t" << q << "\t" << r
						<< "\t " << LHS << "\t   " << RHS << endl;
				}

			}
		}
	}
	return 0;
}