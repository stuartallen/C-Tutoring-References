#include <iostream>
using namespace std;

class Parent {
	private:
		int age;
	public:
		/*	Default Constructor	*/
		Parent() {
			age = 5;
			cout << "Used default constructor" << endl;
		}

		/*	THE BIG 3	*/
		Parent(Parent& in_p) {
			cout << "Used copy constructor" << endl;
			age = in_p.age;
		}

		/*	Why does this take an argument	*/
		Parent& operator=(const Parent& p) {
			cout << "Assignment operator used" << endl;
			age = p.age;
		}

		~Parent() {
			cout << "destructor has been called" << endl;
		}

		/*	Accessors, modifiers, and others	
			Can you tell me which is which?	*/
		int get_age() {
			return age;	
		}

		void mod_age(int in_a) {
			age = in_a;
		}

		void print_age() {
			cout << "age is: " << age << "\n" << endl;
		}
};

int main() {
	Parent dad;
	cout << "Dad is ";
	dad.print_age();

	Parent mom(dad);
	cout << "Mom is ";
	mom.print_age();

	/*	This is tricky. Why is it the same as above	*/
	Parent dad2 = dad;
	cout << "dad2 is ";
	dad2.print_age();

	mom.mod_age(34);
	dad2 = mom;
	cout << "dad2 is ";
	dad2.print_age();

	return 0;
}