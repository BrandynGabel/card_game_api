#include "table.h"
#include "card.h"
#include "invalid_instantiation_exception.h"

#include <sstream>
#include <stdexcept>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>

namespace card_game_api {

	Table::Table () {}






	Table::Table (const int min_cards, const int max_cards) {


		if ((min_cards >= 0 && min_cards <= 52) ||
			(max_cards >= 0 && max_cards <= 52)) {

			min_size = min_cards;
			max_size = max_cards;

		} else {

			throw InvalidInstantiationException (*this);

		}

	}






	Table::~Table () {}




	// Begin private functions



	// Generates a key for the map based on the Card
	std::pair <int, std::string> Table::get_key_for (const Card& card) const {

		return std::make_pair (card.get_rank (), card.get_suit ());

	}





	// Generate a key for the map based on the Card members
	std::pair <int, std::string> Table::get_key_for (const int rank, const std::string suit) const {

		return std::make_pair (rank, suit);

	}





	std::pair <Card, bool> Table::get_value_for (const Card& card, const bool visible) const {

		return std::make_pair (card, visible);

	}





	// Does this Table own this Card?
	void Table::does_card_exist (const Card& card) const {

		does_card_exist (card.get_rank (), card.get_suit ());

	}





	// Does this Table own this Card? If not throw an exception
	void Table::does_card_exist (const int rank, const std::string suit) const {

		if (the_table.find (get_key_for(rank, suit)) == the_table.end ())
			throw std::invalid_argument ("That Card is not in on the Table!\n");

	}



	// End private functions
	// Being public functions





	std::vector <std::pair <Card, bool>> Table::get_cards_vector () {

		return order;

	}








	void Table::add_card (const Card& card, const bool visible) {
		
		if (size + 1 < max_size) {

			the_table.emplace (get_key_for (card), get_value_for (card, visible));
			order.push_back (get_value_for (card, visible));
			size++;

		} else {

			throw std::length_error ("The Table is already full.");

		}
	}






	const Card& Table::remove_card (const Card& card) {

		does_card_exist (card);

		// Erase from the map
		the_table.erase (get_key_for (card));

		// Find the value in the vector
		std::vector<std::pair<Card, bool>>::iterator position_in_vector = 
		std::find (order.begin (), order.end (), the_table.at (get_key_for (card)));
		
		// If it exists
		if (position_in_vector != order.end()){

			// Erase from the vector
			order.erase (position_in_vector);
		
		}

		// Ensure the Vector is the size of how many Cards it holds
		order.shrink_to_fit ();

		// Decrement the size variable
		size--;

		return card;

	}






	const Card& Table::remove_card () {

		Card& temp = std::get <0> (order.back ());
		return remove_card (temp);

	}






	void Table::flip_card (const Card& card) {

		does_card_exist (card);

		// ONE STATEMENT ON TWO LINES
		// position_in_map is an iterator to where the Card was found
		std::map <std::pair <int, std::string> , std::pair <Card, bool>>::iterator position_in_map =
		the_table.find (get_key_for (card.get_rank (), card.get_suit ()));

		if (position_in_map != the_table.end ()) {

			// Create a temp map value from the iterator's second member
			std::pair <Card, bool> temp_value = position_in_map->second;

			// Set the temp value's bool to the opposite of what it was
			std::get  <1> (temp_value) = !(std::get <1> (temp_value));

			the_table [get_key_for(card)] = temp_value;

			
		}
		
		// Find the value in the vector
		for (int i = 0; i < order.size (); i++) {

			if (std::get<0> (order[i]) == card) {

				// Change the bool value to it's opposite
				bool temp = !(std::get<1> (order[i]));
				// Change the value at index i to the new value
				order [i] = get_value_for(card, temp);

			}

		}


	}






	void Table::flip_cards (std::vector <std::pair <Card, bool>> cards) {

		for (auto i = cards.begin (); i != cards.end (); ++i) {

			flip_card (i->first);

		}

	}






	void Table::flip_all_cards () {

		for (auto i = order.begin (); i != order.end (); i++) {
			
			Card temp = i->first;
			flip_card (i->first);

		}

	}






	void Table::clear_table () {

		while (order.size () > 0) {

			remove_card ();

		}

	}







	void Table::print_table () const {

		std::cout << to_string ();

	}






	const std::string Table::to_string () const {

		std::pair <Card, bool> curr;
		std::ostringstream value;
		value << "The Cards on the Table appear in this order:\n";

		for (int i = 0; i < order.size (); i++) {

			curr = order[i];

			// If the Card is visible
			if(std::get<1> (curr)) {

				// We will add the string representation to value;
				value << std::get<0> (curr) << '\n';

			} else {

				value << "Card number " << (i + 1) << " is not visble!\n";

			}

		}

		return value.str ();

	}







	const int Table::get_size () const {

		return size;

	}

}