#include "card.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

#ifndef HAND_H
#define HAND_H


namespace card_game_api {

	class Hand {

		private:

			int size = 0;

			// Allows random access to the Cards
			std::map <std::pair <int, std::string>, Card> hand;
			// Keeps track of when the Cards were dealt
			std::vector <Card> order;

			// These two functions generate a key for the map
			std::pair <int, std::string> get_key_for (const Card& card) const;
			std::pair <int, std::string> get_key_for (const int rank, const std::string suit) const;
			// These functions throw an out_of_range exception if the card is not in the Hand
			void does_card_exist (const Card& card) const;
			void does_card_exist (const int rank, const std::string) const;

		public:

			Hand ();
			~Hand ();

			// adds a Card to the Hand
			void add_card (const Card& card);
			// removes a Card from the Hand
			const Card& remove_card (const Card& card);
			const Card& remove_card (const int rank, const std::string suit);
			const Card& remove_card ();

		
			// plays a specific Card
			// encapsulate in a try-catch because 
			// it will throw an exception if that
			// Card doesn't exist in your Hand
			const Card& play_card (const Card& card);
			const Card& play_card (const int rank, const std::string suit);
			// plays the first Card
			const Card& play_card ();

			void print_hand () const;

			const int get_size () const;

	};

}


#endif