#include "card.h"
#include "table.h"

#include <iostream>
#include <exception>

#ifndef INVALIDINSTANTIATIONEXCEPTION_H
#define INVALIDINSTANTIATIONEXCEPTION_H

// An InvalidInsantiationException is thrown when 
// a Card or Table is not instantiated properly.
// A message is developed and can be accessed to describe
// why the object was not instantiated properly via what ().

namespace card_game_api {

	class InvalidInstantiationException : std::exception {

		private:

			std::string error_message;
			static const int MIN_SIZE = 0;
			static const int MAX_SIZE = 52;
			static const int MIN_RANK = 2;
			static const int MAX_RANK = 14;

			const std::string bad_card_message (bool bad_rank, bool bad_suit);
			const std::string bad_table_message (bool bad_table);
			
		public:

			InvalidInstantiationException (Card& card) noexcept;
			InvalidInstantiationException (Table& table) noexcept;
			~InvalidInstantiationException ();

			const char* what () const noexcept;

	};

}

#endif