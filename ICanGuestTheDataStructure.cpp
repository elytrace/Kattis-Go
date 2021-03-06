#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, op, x;
	while (cin >> n) {
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;
		bool isS = true, isQ = true, isPQ = true;

		for (int i = 0; i < n; i++) {
			cin >> op >> x;

			switch (op) {
                case 1:
                    if (isS)
                        s.push(x);
                    if (isQ)
                        q.push(x);
                    if (isPQ)
                        pq.push(x);
                    break;
                case 2:
                    if (isS) {
                        if (s.empty() || s.top() != x)
                            isS = false;
                        else
                            s.pop();
                    }
                    if (isQ) {
                        if (q.empty() || q.front() != x)
                            isQ = false;
                        else
                            q.pop();
                    }
                    if (isPQ) {
                        if (pq.empty() || pq.top() != x)
                            isPQ = false;
                        else
                            pq.pop();
                    }
                    break;
            }
		}

		if (isS && !isQ && !isPQ)
			cout << "stack" << endl;
		else if (!isS && isQ && !isPQ)
			cout << "queue" << endl;
		else if (!isS && !isQ && isPQ)
			cout << "priority queue" << endl;
		else if (!isS && !isQ && !isPQ)
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;
	}
}