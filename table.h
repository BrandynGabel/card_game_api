#include "card.h"

#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <vector>

#ifndef TABLE_H
#define TABLE_H

namespace card_game_api {

	class Table {

		private:

			int   min_size =  0; // No negative Cards on Table
			int   max_size = 52; // Can be redefined
			int   size 	   =  0; // The number of Cards currently on the Table.

			// Maintain the order of the Cards on the Table
			std::vector <std::pair <Card, bool>> order;
			// Allow random access to the Cards
			std::map 	<std::pair <int, std::string>, std::pair <Card, bool>> the_table;

			// First two functions generate a key for the map
			std::pair <int, std::string> get_key_for (const Card& card) const;
			std::pair <int, std::string> get_key_for (const int rank, const std::string suit) const;
			// This function generates a value for either the map or the vector
			std::pair <Card, bool> get_value_for (const Card& card, const bool visible) const;

			// These functions check to see if the Card is actually on the Table
			// An out_of_bounds exception is thrown if the Card is not on the Table
			void does_card_exist (const Card& card) const;
			void does_card_exist (const int rank, const std::string suit) const;
			

		public:

			Table (); // Default
			// You can create a table with a limit on the number of Cards
			Table (const int min_cards, const int max_cards);
			~Table ();

			// Return the order vector
			std::vector <std::pair <Card, bool>> get_cards_vector ();
			// Adds this Card and it's visibility to the Table
			void add_card (const Card& card, const bool visible);
			// Removes this Card from the Table
			const Card& remove_card (const Card& card);
			// Removes first Card from the Table
			const Card& remove_card ();
			// Changes the visibility of this Card provided it exists
			// Will throw an out_of_range exception otherwise
			void flip_card (const Card& card);
			// Changes the visibility of all the Cards in the vector provided it exists
			void flip_cards (std::vector <std::pair <Card, bool>> cards);
			// Changes the visibility of all the Cards on the Table
			void flip_all_cards ();
			//removes all Cards from the Table
			void clear_table ();

			void print_table () const;
			const std::string to_string () const;
			const int get_size () const ;

	};

}

#endif