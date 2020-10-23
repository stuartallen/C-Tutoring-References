/*	I wrote this quick and dirty and would not advise copying and pasting any of it
	
	The main thing I want you to know is that in your hand class you will have to declare
	dynamic memory	*/

#include <iostream>
using namespace std;

class Card {
	/*	This is just an example so for simplicity
		these cards just have a number that is public.
		You will need accessors in a good program	*/
	public:
		int num;

		/*	This is an assignment operator. I go over it
			more in big_three.cpp. All the operator= fanciness
			just means this function is used when you set one
			card equal to another (both cards must be declared
			already). All this operator does is set the num the
			same in both cards, however in other classes it is
			possible you would want to do something more complex*/
		void operator= (Card& c) {
			num = c.num;
		}
};

class Deck {
	/*	Only 10 public cards. Again this is just an example
		please use accessors to get feilds between classes
		
		Also keep in mind when a Deck object is made there are
		10 card objects immediately made on the stack	*/
		public:
			Card cards[10];
			int num_cards = 10;

			Deck() {
				for(int i = 0; i < 10; i++) {
					cards[i].num = i;
				}
			}
};

class Hand {
	private:
		/*	Hand uses a card * so it is intitially empty	*/
		
		int num_cards = 5;
		Card* cards = new Card[num_cards];
	public:
		/*	Hand uses a non default constructor to be filled
			immediately 										*/
		Hand(Deck& d) {
			/*	Calls the function deal from hand	*/
			deal(d);
		}

		/* the hand gets dealt 3 cards	*/
		void deal(Deck& d) {
			/*	This for loop iterates from the last cards on the deck	
				to the last card in the deck minus the number of cards
				that should initially be in a hand							*/
			for(int i = d.num_cards; i > d.num_cards - num_cards; i--) {
				
				/*	uses the card assignment (=) function	*/
				cards[i] = d.cards[i];
				cout << d.cards[i].num << endl;
			}
			d.num_cards-= num_cards;
		}
};

int main() {
	Deck d;
	Hand h(d);
	return 0;
}