#include "ComparHands.h"

#include <map>
#include <set>

std::string ToString(HandValue _value)
{
	switch (_value)
	{
	case HighCard: return "High Card";
		break;

	case Pair: return "Pair";
		break;

	case TwoPairs: return "Two Pairs";
		break;

	case ThreeOfAKind: return "Brelan";
		break;

	case Square: return "Square";
		break;

	case Full: return "Full";
		break;

	case Suit: return "Suit";
		break;

	case Color: return "Color";
		break;

	case Flush: return "Flush";
		break;

	default:
		return "_no_value_";
	}
}

HandValue Evaluate(const std::vector<Card>& _hand)
{

	// Compose Player and table Hands ------------
	std::vector<Card> _compoundHand;

	for (auto c : _hand)
		_compoundHand.emplace_back(c);

	for (auto c : Table)
		_compoundHand.emplace_back(c);

	if (HasFlush(_compoundHand))
	{
		return Flush;
	}
	else if (HasColor(_compoundHand))
	{
		return Color;
	}
	else if (HasSuite(_compoundHand))
	{
		return Suit;
	}
	else if (HasFull(_compoundHand))
	{
		return Full;
	}
	else if (HasSquare(_compoundHand))
	{
		return Square;
	}
	else if (HasThreeOfAKind(_compoundHand))
	{
		return ThreeOfAKind;
	}
	else if (HasTwoPairs(_compoundHand))
	{
		return TwoPairs;
	}
	else if (HasPair(_compoundHand))
	{
		return Pair;
	}
	else
	{
		return HighCard;
	}
}

std::map<Rank, int> RankOccurences(const std::vector<Card>& compoundHand)
{

	std::map<Rank, int> occurences;

	for (auto c : compoundHand)
	{
		if (occurences.find(c.rank) == occurences.end())
		{
			occurences[c.rank] = 1;
		}
		else
		{
			occurences[c.rank]++;
		}
	}

	return occurences;

}
std::map<enum Suit, int> SuitOccurences(const std::vector<Card>& compoundHand)
{

	std::map<enum Suit, int> occurences;

	for (auto c : compoundHand)
	{
		if (occurences.find(c.suit) == occurences.end())
		{
			occurences[c.suit] = 1;
		}
		else
		{
			occurences[c.suit]++;
		}
	}

	return occurences;

}

//all the bodys of the bools

bool HasPair(const std::vector<Card>& compoundHand)
{

	const std::map<Rank, int> occurences = RankOccurences(compoundHand);

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 2)
		{
			return true;
		}
	}

	return false;

}
bool HasTwoPairs(const std::vector<Card>& compoundHand)
{

	const std::map<Rank, int> occurences = RankOccurences(compoundHand);
	Rank firstPair;

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 2)
		{
			firstPair = p.first;
		}
	}
	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 2 && firstPair != p.first)
		{
			return true;
		}
	}


	return false;

}
bool HasSquare(const std::vector<Card>& compoundHand)
{

	const std::map<Rank, int> occurences = RankOccurences(compoundHand);

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 4)
		{
			return true;
		}
	}

	return false;
}
bool HasThreeOfAKind(const std::vector<Card>& compoundHand)
{
	const std::map<Rank, int> occurences = RankOccurences(compoundHand);

	for (std::pair<Rank, int> p : occurences)
	{
		if (p.second == 3)
		{
			return true;
		}
	}
	return false;
}
bool HasSuite(const std::vector<Card>& compoundHand)
{
	std::map<Rank, int> occurrences = RankOccurences(compoundHand);
	int FirstNumber = 2;
	bool IsInOrder = true;

	for (std::pair<Rank, int> p : occurrences)
	{
		if (p.first == FirstNumber)
		{
			FirstNumber++;
		}
		else
		{
			IsInOrder = false;
		}
	}
	if (IsInOrder == true)
	{
		return  true;
	}
	else
	{
		return false;
	}
}
bool HasFlush(const std::vector<Card>& compoundHand)
{
	std::map<enum Suit, int> occurrences = SuitOccurences(compoundHand);

	for (std::pair<enum Suit, int> p : occurrences)
	{
		if (p.second == 5)
		{
			return true;

		}
	}
	return false;
}
bool HasFull(const std::vector<Card>& totalHand)
{
	std::map<Rank, int> occurrences = RankOccurences(totalHand);

	for (std::pair<Rank, int> p : occurrences)
	{
		if (p.second == 3)
		{
			if (p.second == 2)
			{
				return true;
			}
		}
	}
	return false;
}
bool HasColor(const std::vector<Card>& totalHand)
{
	std::map<Rank, int> Rankoccurences = RankOccurences(totalHand);
	std::map<enum Suit, int> Suitoccurrences = SuitOccurences(totalHand);

	int FirstNumber = 2;
	bool IsInOrder = true;

	for (std::pair<Rank, int> p : Rankoccurences)
	{
		if (p.first == FirstNumber)
		{
			FirstNumber++;
		}
		else
		{
			IsInOrder = false;
		}
	}

	for (std::pair<enum Suit, int> p : Suitoccurrences)
	{
		if (IsInOrder == true)
		{
			if (p.second == 5)
			{
				return  true;
			}
		}
	}
	return false;
}