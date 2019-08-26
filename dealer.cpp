#include "dealer.h"
#include "hand.h"
#include "table.h"

#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

namespace card_game_api {

	Dealer::Dealer () {}






	Dealer::~Dealer () {}






	void Dealer::deal_to_player (Hand& hand) {

		hand.add_card (deck.deal_card ());

	}






	void Dealer::deal_to_table (Table& table, bool visible) {

		table.add_card (deck.deal_card (), visible);

	}







	void Dealer::collect_cards (Hand& hand) {

		while (hand.get_size () > 0) {

			deck.add_card (hand.remove_card ());

		}

	}






	void Dealer::clear_table (Table& table) {

		while (table.get_size ()) {

			deck.add_card (table.remove_card ());

		}
		
	}






	const int Dealer::get_deck_size () const {

		return deck.get_size ();

	}






	void Dealer::print_deck () const {

		for (int i = 0; i < deck.get_size (); i++) {

			std::cout << deck[i] << std::endl;

		}

	}
	
}
