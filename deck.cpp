#include "deck.h"
#include "invalid_instantiation_exception.h"

#include <iostream>
#include <algorithm>
#include <array>
#include <chrono>
#include <random>
#include <string>
#include <vector>

namespace card_game_api {

	const std::array <std::string, Deck::NUM_SUITS> Deck::suits =
				{"Clubs", "Diamonds", "Hearts", "Spades"};





	Deck::Deck (bool shuffled /* = true */) {

		if (shuffled)

			new_deck_shuffle ();

		else 

			new_deck ();

	}






	Deck::~Deck () {}






	// Begin private functions
	const unsigned Deck::new_seed () {

		return std::chrono::system_clock::now ().time_since_epoch ().count ();

	}






	void Deck::new_deck () {

		for (int i = 0; i < NUM_CARDS / NUM_SUITS; i++) {

			try {

				the_deck.push_back (Card (i + 2, suits [0]));
				the_deck.push_back (Card (i + 2, suits [1]));
				the_deck.push_back (Card (i + 2, suits [2]));
				the_deck.push_back (Card (i + 2, suits [3]));
			
			} catch (InvalidInstantiationException e) {

				std::cout << "Something went wrong making the cards...";
				e.what ();

			}
		}

		the_deck.shrink_to_fit ();

	}






	void Deck::new_deck_shuffle () {

		new_deck ();
		shuffle ();

	}

	// End private functions
	// Begin public functions





	const Card& Deck::operator[] (const int pos) const {

		return the_deck.at(pos);

	}






	const Card& Deck::deal_card () {

		Card& temp = the_deck.at (the_deck.size () - 1);
		the_deck. pop_back ();
		return temp;

	}






	void Deck::add_card (const Card& card) {

		the_deck.push_back (card);

	}






	// shuffle the_deck
	void Deck::shuffle () {

		std::shuffle (the_deck.begin (), the_deck.end (), 
			std::default_random_engine (new_seed ()));

	}






	const int Deck::get_size () const {

		return the_deck.size ();

	}

	// End public functions

}