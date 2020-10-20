/*	This is the most basic example of a class */

#include <iostream>
using namespace std;

/*	Use capital letters for classes*/
class Parent {
	private:
		int priv = 1;
	protected:
		int prot = 2;
	public:
		int pub = 3;
		void print() {
			/*	This is just another way to print things. The
				%d will be replaced by the arguments in order	*/
			printf("priv: %d prot: %d pub: %d", priv, prot, pub);
		}
};

class Child : public Parent {
	/*	You can define a function here, but in class
		you should use a different file.			*/
	public:
		/*	Why can't the child print priv?*/
		void print() {
			printf("prot: %d pub: %d", prot, pub);
		}
};

int main() {
	Parent dad;
	Child son;

	/* Why can I do this */
	dad.pub = 7;
	/* But not this? */
	//dad.priv = 4; dad.prot = 8;

	/*	does the parent function	*/
	dad.print();

	/*	does the child function		*/
	son.print();
}