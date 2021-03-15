#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

template<typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair () {
    	
	}
    Pair (const Pair& copied) {
    	first = copied.first;
    	second = copied.second;
	}
    Pair& operator=(const Pair& copied) {
    	(*this).first = copied.first;
    	(*this).second = copied.second;
	}
	bool operator==(const Pair& p1) const{
		if ((*this).first == p1.first && (*this).second == p1.second) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator!=(const Pair& p1) {
		return ((p1 == (*this)) ^ true);
	}
	bool operator<(const Pair& p1) const{
		if ((*this).first < p1.first) {
			return true;
		}
		if ((*this).first > p1.first) {
			return false;
		}
		if ((*this).first < p1.second) {
			return true;
		}
		if ((*this).first > p1.second) {
			return false;
		}
	}
	bool operator>(const Pair& p1) const{
		return (p1 < (*this));
	}
	bool operator<=(const Pair& p1) const{
		return (((*this) < p1) | ((*this) == p1));
	}
	bool operator>=(const Pair& p1) const{
		return (((*this) > p1) | ((*this) == p1));
	}
	void swap (Pair p1, Pair p2) {
		Pair p3 = p2;
		p2 = p1;
		p1 = p3;
	}
};

template<typename T>
void mySort(vector<T>& a) {
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			if (a[i] < a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}

int main() {
    srand(time(NULL));
    int n = 10 + rand() % 10;
    vector<pair<int, double> > a(n);
    vector<Pair<int, double> > b(n);
    for (int i = 0; i < n; ++i) {
        a[i].first = rand() % 100;
        a[i].second = 0.5 + rand() % 100;
        b[i].first = a[i].first;
        b[i].second = a[i].second;
    }
    sort(a.begin(), a.end());
    mySort(b);
    for (int i = 0; i < n; ++i) {
        cout << a[i].first << " " << a[i].second << " " << b[i].first << " " << b[i].second << endl;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i].first != b[i].first) {
            cout << "a[" << i << "].first != b[" << i << "].first: " << a[i].first << " != " << b[i].first << endl;
        }
        if (a[i].second != b[i].second) {
            cout << "a[" << i << "].second != b[" << i << "].second: " << a[i].second << " != " << b[i].second << endl;
        }
    }
}
