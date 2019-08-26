#include "card.h"
#include "hand.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>

namespace card_game_api {

	Hand::Hand () {}






	Hand::~Hand () {}





	// Begin private functions

	// Generates a key for the map based on the Card
	std::pair <int, std::string> Hand::get_key_for (const Card& card) const {

		return std::make_pair (card.get_rank (), card.get_suit ());

	}





	// Generate a key for the map based on the Card members
	std::pair <int, std::string> Hand::get_key_for (const int rank, const std::string suit) const {

		return std::make_pair (rank, suit);

	}





	// Does this hand own this Card?
	void Hand::does_card_exist (const Card& card) const {

		does_card_exist (card.get_rank (), card.get_suit ());

	}





	// Does this hand own this Card? If not throw an exception
	void Hand::does_card_exist (const int rank, const std::string suit) const {

		if (hand.find (get_key_for(rank, suit)) == hand.end ())
			throw std::out_of_range ("That Card is not in your Hand!\n");

	}



	// End private functions
	// Begin public functions




	void Hand::add_card (const Card& card) {

		// Add to the Map
		hand.emplace (get_key_for (card), card);

		// Add to the vector
		order.push_back (card);
		order.shrink_to_fit ();

		// Increment the size variable
		size++;

	}






	const Card& Hand::remove_card (const Card& card) {

		// Erase from the map
		hand.erase (get_key_for (card));

		// Find the Card in the vector
		std::vector<Card>::iterator position = std::find (order.begin (), order.end (), card);
		
		// If it exists
		if (position != order.end()){

			// Erase from the vector
			order.erase (position);
		
		}

		// Ensure the Vector is the size of how many Cards it holds
		order.shrink_to_fit ();

		// Decrement the size variable
		size--;

		return card;
	}






	const Card& Hand::remove_card (const int rank, const std::string suit) {

		return remove_card (Card (rank, suit));

	}






	const Card& Hand::remove_card () {

		Card& temp = order.back ();
		return remove_card (temp);

	}






	const Card& Hand::play_card (const Card& card) {

		// Only play a Card that you have
		does_card_exist (card);

		const Card& temp = card;
		remove_card (temp);

		return temp;

	}






	const Card& Hand::play_card (const int rank, const std::string suit) {

		// Only play a Card you have
		does_card_exist (rank, suit);

		const Card& temp = hand.at (get_key_for (rank, suit));
		remove_card (temp);
		return temp;

	}






	const Card& Hand::play_card () {

		// Play the first Card in the Hand
		const Card& temp = order.back ();
		remove_card (temp);
		return temp;

	}






	void Hand::print_hand () const {

		if (order.size () == 0) {

			std::cout << "No Cards!" << std::endl;

		} else {
	
			for (int i = 0; i < order.size (); i++) {
	
				std::cout << order [i] << std::endl;
	
			}
		}

	}






	const int Hand::get_size () const {

		return order.size ();

	}

	// End public functions

}