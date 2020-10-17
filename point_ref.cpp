/*  Let's review pointers and references    */

#include <iostream>

/*  This is technically bad practice to 
    using namespace std. Don't do it after  
    cs162                                   */
using namespace std;

/*  All our function headers will go here.  
    Function headers have (from left to     
    right): 
    -   The type of data the function returns 
        (called the return type)
    -   The name of the function
    -   The data types of the arguments IN 
        ORDER (You can also give them names
        in the header but you don't have to */
void func(int, int&, int*);
void print_nums(int, int, int);

int main() {
    /*  This makes 3 ints. We could also do 
        this on seperate lines              */
    int number_1 = 0; 
    int number_2 = 3;
    int number_3 = 6;
    cout << "At the beginning" << endl;
    print_nums(number_1, number_2, number_3);

    /*  Now let's call the function         */
    func(number_1, number_2, &number_3);

    cout << "After calling func. (Back in main's scope)" << endl;
    print_nums(number_1, number_2, number_3);

    /*  Extra mega hard question:
        Why didn't I need to free any 
        memory?                             */
    return 0;
}

/*  Now let's define our function. We can 
    give them different names than we gave 
    them in main.                           */ 
void func(int a, int& b, int* c) {
    a++;
    b++;
    (*c)++;
    cout << "Inside the function's Scope" << endl;
    print_nums(a, b, *c);
}

void print_nums(int first, int second, int third) {
    cout << "\tThe first letter is: " << first << endl;
    cout << "\tThe second letter is: " << second << endl;
    cout << "\tThe third letter is: " << third << endl;
}