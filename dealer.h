#include "deck.h"
#include "hand.h"
#include "table.h"

#include <iostream>
#include <map>
#include <string> 
#include <stack>
#include <vector>

#ifndef DEALER_H
#define DEALER_H

namespace card_game_api {

	class Dealer {

		private:

			// A Dealer always has a shuffled Deck
			Deck deck;

		public:

			Dealer ();
			~Dealer ();


			// Deals a Card to a Hand
			void deal_to_player (Hand& hand);
			// Deals a Card to the Table
			void deal_to_table (Table& table, bool visible);

			// Retrieves all the Cards from a Hand
			void collect_cards (Hand& hand);
			// Retrieves all the Cards from the Table
			void clear_table (Table& table);

			const int get_deck_size () const;
			void print_deck () const;

	};

}

#endif






















