// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <vector>

#include "Cards.h"
#include "Deck.h"
#include "ComparHands.h"

//bool  isPlaying = true;
//int playerBalance = 5000;

int main()
{
	std::cout << "Want to play a game? \n" << "[yes] or [no]" << std::endl;

	Card oneCard;
	oneCard.rank = Ace;
	oneCard.suit = Spades;
	std::cout << ToString(oneCard) << std::endl;

	const Card anotherCard = GiveACard();
	std::cout << ToString(anotherCard) << std::endl;

	FillDeck();

	// 1ere donne : 1 carte à chaque joueur
	HandPlayer.push_back(GiveACard());
	HandBot.push_back(GiveACard());

	HandPlayer.push_back(GiveACard());
	HandBot.push_back(GiveACard());

	ToString("Player", HandPlayer);

	// Flop
	Table.push_back(GiveACard());
	Table.push_back(GiveACard());
	Table.push_back(GiveACard());

	// Turn
	Table.push_back(GiveACard());

	// River
	Table.push_back(GiveACard());


	// ToString("Deck", Deck);
	ToString("Table", Table);

	ToString("Bot", HandBot);

	const HandValue playerValue = Evaluate(HandPlayer);
	const HandValue botValue = Evaluate(HandBot);

	if (playerValue > botValue)
	{
		std::cout << "Player Won : " << ToString(playerValue) << std::endl;
	}
	else if (playerValue < botValue)
	{
		std::cout << "Bot Won : " << ToString(botValue) << std::endl;
	}
	else
	{
		std::cout << "SPLIT" << std::endl;
	}

	return EXIT_SUCCESS;

}
