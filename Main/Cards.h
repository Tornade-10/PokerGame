#pragma once

#include <string>

enum Rank
{
	Two = 2,
	Three,
	Four,
	Five,
	Six,
	Seven,
	Eight,
	Nine,
	Ten,
	Jack,
	Queen,
	King,
	Ace
};

enum Suit
{
	Hearts,
	Spades,
	Diamonds,
	Clubs
};

struct Card
{
	Rank rank;
	Suit suit;
};


std::string ToString(Card _card);

std::string ToString(Rank _rank);
std::string ToString(Suit _suit);