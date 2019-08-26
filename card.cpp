#include "card.h"
#include "invalid_instantiation_exception.h"

#include <iostream>
#include <string>

namespace card_game_api {


	Card::Card () {}




	
														// data_member (parameter)
	Card::Card (const int rank, const std::string& suit) : rank (rank), suit (suit) {

		if (bad_rank () || bad_suit ()) {

			throw card_game_api::InvalidInstantiationException (*this);

		}

	}






	Card::Card (const Card& card) {

		set_rank (card.get_rank ());
		set_suit (card.get_suit ());

	}






	Card::~Card () {}





	// Begin private functions



	void Card::set_rank (const int new_rank) {

		rank = new_rank;

	}






	void Card::set_suit (const std::string& new_suit) {

		suit = new_suit;

	}






	const bool Card::bad_rank () {

		if (get_rank () >= Card::MIN_RANK && 
			get_rank () <= Card::MAX_RANK) {

			return false;

		}

		return true;

	}






	const bool Card::bad_suit () {

		if (get_suit ().compare("Clubs")   	== 0 ||
			get_suit ().compare("Diamonds") == 0 ||
			get_suit ().compare("Hearts") 	== 0 ||
			get_suit ().compare("Spades")   == 0) {

			return false;

		}

		return true;

	}

	// End private functions


	// Begin public functions



	Card& Card::operator= (const Card& card) {

		set_rank (card.get_rank ());
		set_suit (card.get_suit ());

		return *this; 

	}






	std::ostream& operator<< (std::ostream& out, const Card& card) {

		out << card.to_string ();
		return out;

	}






	std::istream& operator>> (std::istream&  in, Card& card) {
		int _rank;
		std::string _suit;

		in >> _rank >> _suit;

		const int rank = _rank;
		const std::string suit = _suit;

		card.set_rank(rank);
		card.set_suit(suit);

		return in;

	}






	bool operator== (const Card& left, const Card& right) {

		return left.get_rank() == right.get_rank();

	}






	bool operator!= (const Card& left, const Card& right) {

		return left.get_rank() != right.get_rank();

	}






	bool operator>= (const Card& left, const Card& right) {

		return left.get_rank() >= right.get_rank();

	}






	bool operator<= (const Card& left, const Card& right) {

		return left.get_rank() <= right.get_rank();

	}






	bool operator> (const Card& left, const Card& right) {

		return left.get_rank() > right.get_rank();

	}






	bool operator< (const Card& left, const Card& right) {

		return left.get_rank() < right.get_rank();

	}






	const int Card::get_rank () const {

		return rank;

	}






	const std::string Card::get_suit () const {

		return suit;

	}







	const std::string Card::to_string () const {

		std::string rank;

		switch (get_rank ()) {

			case 11: rank = "Jack"; break;
			case 12: rank = "Queen"; break;
			case 13: rank = "King"; break;
			case 14: rank = "Ace"; break;
			default: rank = std::to_string (get_rank ()); break;

		}

		return rank + " of " + get_suit ();

	}
	
}