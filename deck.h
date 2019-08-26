#include "card.h"

#include <iostream>
#include <array>
#include <random>
#include <vector>

#ifndef DECK_H
#define DECK_H

namespace card_game_api {

	class Deck {

		private:

			// number of cards in a deck
			static const int NUM_CARDS = 52;
			// number of suits in a deck
			static const int NUM_SUITS =  4;
			// an array to represent the suits
			static const std::array <std::string, NUM_SUITS> suits;
			// this is where the cards are stored.
			std::vector <Card> the_deck;


			// new seed for psuedo-random generator
			const unsigned new_seed ();


			// for making an ordered Deck
			void new_deck ();
			// for making a shuffled Deck
			void new_deck_shuffle ();
			

		public:

			Deck (bool shuffled = true);
			~Deck ();



			// return the Card located at pos in the_deck
			const Card& operator[] (const int pos) const;

			// Removes the first Card from the Deck
			const Card& deal_card ();

			// Adds a card to the Deck
			void add_card (const Card& card);
			// manually shuffle
			void shuffle ();


			// return the number of cards remaining
			const int get_size () const;
			


	};

}

#endif