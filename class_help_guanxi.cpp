#include <iostream>
using namespace std;

class Student {
	int a, b, c;
	long ID;
public:
	Student(long getID, int x, int y, int z) {
		a = x;
		b = y;
		c = z;
		ID = getID;
	}
	long getID() {
		return ID;
	}
	int sum() {
		int d;
		d = a + b + c;
		return d;
	}
	double avg() {
		int e;
		e = (a + b + c) / 3;
		return e;
	}
};

int main() {
	Student s(201211145, 90, 80, 97);
	cout<<"ID: "<<s.getID()<<endl;
	cout<<"\tThe sum of source: "<<s.sum()<<endl;
	cout<<"\tThe avg of source: "<<s.avg()<<endl;
	return 0;
}