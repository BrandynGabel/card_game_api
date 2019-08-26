#include <iostream>
#include <string>
#ifndef CARD_H
#define CARD_H


// This header file defines the object Card.
// A Card will store two values: int rank and std::string suit
// These values are restricted to [2, 15], and  the standard suits 
//
//
// A Card will have the following public functions:	
// 
// 
// friend bool operator==(const Card& left, const Card& right);
// 		This 



namespace card_game_api {

	class Card {

		private:

			int rank;
			std::string suit;

			// setters for copy constructor
			void set_rank (const int new_rank);
			void set_suit (const std::string& new_suit);

			const bool bad_rank ();
			const bool bad_suit ();
		
		public:

			static const int MIN_RANK =  2;
			static const int MAX_RANK = 14;

			// A Card can have a rank from [2, 14], and can 
			// be of suit Club, Diamond, Heart, or Spade.
			//
			// If a Card is not instantiated with these 
			// values a new exception will be thrown of 
			// type InvalidInstantiationException        
			Card  ();
			Card  (const int rank, const std::string& suit);
			Card  (const Card& card);
			~Card ();

			Card& operator= (const Card& card);
			friend std::ostream& operator<< (std::ostream& out, const Card& card);
			friend std::istream& operator>> (std::istream& in, Card& card);
			friend bool operator== (const Card& left, const Card& right);
			friend bool operator!= (const Card& left, const Card& right);
			friend bool operator>= (const Card& left, const Card& right);
			friend bool operator<= (const Card& left, const Card& right);
			friend bool operator>  (const Card& left, const Card& right);
			friend bool operator<  (const Card& left, const Card& right);

			const int get_rank () const;
			const std::string get_suit () const;
			const std::string to_string () const;

	};

}

#endif



















