#pragma once

#include <vector>
#include <map>

#include "Deck.h"

enum HandValue
{
	HighCard,
	Pair,
	TwoPairs,
	ThreeOfAKind,
	Square,
	Full,
	Suit,
	Color,
	Flush
};

std::string ToString(HandValue _value);

HandValue Evaluate(const std::vector<Card>& _Hand);

std::map<Rank, int> RankOccurences(const std::vector<Card>& compoundHand);
std::map<enum Suit, int> SuitOccurences(const std::vector<Card>& compoundHand);

//Initialisation of the Bools for detecting what combo of card there is

bool HasPair(const std::vector<Card>& _compoundHand);
bool HasTwoPairs(const std::vector<Card>& _compoundHand);
bool HasThreeOfAKind(const std::vector<Card>& _compoundHand);
bool HasSquare(const std::vector<Card>& _compoundHand);
bool HasFull(const std::vector<Card>& _compoundHand);
bool HasSuite(const std::vector<Card>& _compoundHand);
bool HasColor(const std::vector<Card>& _compoundHand);
bool HasFlush(const std::vector<Card>& _compoundHand);
