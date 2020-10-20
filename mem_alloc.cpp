#include <iostream>
#include <string.h>
/*  Remember this is bad practice after
    cs162                                  */
using namespace std;

/*  A monkey struct with a number of limbs
    and a noise                             */
struct monkey {
    int num_limbs;
    string noise;
};

/*  Function that makes a list of monkeys   */
monkey* create_monkey_list(int);

/*  Function that changes the list of
    monkeys this has an int because 
    otherwise the monkey list doesn't
    know how many monkeys it contains       */
void change_monkeys(int, monkey*);

int main() {
    /*  Making your constants all caps is a 
        nice thing to do                    */
    const int NUM_MONKEYS = 10;

    /*  Uh oh we made a list of monkeys but
        we didn't assign a variable to it.
        It's lost and memory now with no way
        to access it. This will lead to a 
        memory leak. Go ahead and check 
        valgrind                            */
    create_monkey_list(NUM_MONKEYS);

    /*  This time let's do it right         */
    monkey* list_of_monkeys = create_monkey_list(NUM_MONKEYS);

    /*  Because we saved it into a variable
        now we can pass it into a function  */
    change_monkeys(NUM_MONKEYS, list_of_monkeys);

	for(int i = 0; i < NUM_MONKEYS; i++) {
		cout << list_of_monkeys[i].noise << endl;
	}

	/* 	Each monkey does not allocate memory so we
		do not need to iteratre through the list	*/
	delete [] list_of_monkeys;

    return 0;
}

monkey* create_monkey_list(int num_monk) {
    monkey* monkey_list = new monkey[num_monk];
    return monkey_list;
}

void change_monkeys(int num_monk, monkey* monk_list) {
    /*  Challenge quesiton:
        What data type is noises?           */
    string noises[3] = {"ooh ooh",
                "ahh ahh",
                "uh oh"};
    for(int i = 0; i < num_monk; i++) {
        monk_list[i].num_limbs = 4;
        monk_list[i].noise = noises[i % 3];
    }
}