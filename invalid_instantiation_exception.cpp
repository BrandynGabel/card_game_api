#include "invalid_instantiation_exception.h"
#include "card.h"
#include "table.h"

#include <iostream>
#include <exception>

namespace card_game_api {





	// Invalid Card instantiation
	InvalidInstantiationException::InvalidInstantiationException (Card& card) noexcept {

		bool bad_suit = false;
		bool bad_rank = false;

		if (card.get_rank () < MIN_RANK) {

			bad_rank = true;

		}

		if (card. get_suit ().compare("Clubs")    != 0 ||
			card. get_suit ().compare("Diamonds") != 0 ||
			card. get_suit ().compare("Hearts")	  != 0 ||
			card. get_suit ().compare("Spades")   != 0) {

			bad_suit = true;

		}

		error_message = bad_card_message (bad_rank, bad_suit);

	}






	// Invalid Table instantiation
	InvalidInstantiationException::InvalidInstantiationException (Table& table) noexcept {

		bool bad_table = false;

		if (table.get_size () < MIN_SIZE || table.get_size () > MAX_SIZE) {

			bad_table = true;

		}

		error_message = bad_table_message (bad_table);

	}






	InvalidInstantiationException::~InvalidInstantiationException () {}




	// Begin private functions




	const std::string InvalidInstantiationException::bad_card_message (bool bad_rank, bool bad_suit) {

		if (bad_rank && bad_suit) {

			error_message = "\nA Card must be instantiated within the proper range of rank [2, 14], and with a valid suit.\nValid suits: Clubs, Diamonds, Hearts, and Spades.\n";

		}

		else if (bad_rank) {

			error_message = "\nA Card must be instantiated within the proper range of rank [2, 14].\n";

		}

		else if (bad_suit) {

			error_message = "\nA Card must be instantiated with a valid suit.\nValid suits: Clubs, Diamonds, Hearts, and Spades.\n";

		}

		else {

			error_message = "\nIt is not clear why the Card instantiation failed.\n";

		}

		return error_message;

	}






	const std::string InvalidInstantiationException::bad_table_message (bool bad_table) {

		if (bad_table) {

			error_message = "\nA table cannot hold more than 52 or negative amount of Cards.\n";

		} else {

			error_message = "\nIt is not clear why the Table instantiation failed.\n";

		}

		return error_message;

	}




	// End private functions
	// Begin public function



	const char* InvalidInstantiationException::what () const noexcept {

		return error_message.c_str ();

	}

	// End public function.

}