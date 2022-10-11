#include "deck.h"

/**
 * sort_deck - sorts a deck of cards
 *
 * @deck: to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *c;
	size_t l;
	deck_node_t *one, *two, *three, *four;

	l = list_len_deck(*deck);

	if (!deck || !*deck || l < 2)
		return;

	c = *deck;
	while (c)
	{
		if (c->prev && card_value(c) < card_value(c->prev))
		{
			one = c->prev->prev;
			two = c->prev;
			three = c;
			four = c->next;

			two->next = four;
			if (four)
				four->prev = two;
			three->next = two;
			three->prev = one;
			if (one)
				one->next = three;
			else
				*deck = three;
			two->prev = three;
			c = *deck;
			continue;
		}
		else
			c = c->next;
	}
}

/**
 * card_value - returns the value of a card
 * @node: card in a deck
 *
 * Return: value 1 - 52.
 */
int card_value(deck_node_t *node)
{
	char *val[13] = {"Ace", "2", "3", "4", "5", "6",
		"7", "8", "10", "Jack", "Queen", "King"};
	char *kinds[4] = {"SPADE", "HEART", "CLUB", "DIAMOND"};
	int i;
	int kindv = 0;

	for (i = 1; i <= 13; i++)
	{
		if (!str_cmp(node->card->value, val[i - 1]))
			kindv = i;
	}

	for (i = 1; i <= 4; i++)
	{
		if (!str_cmp(kinds[node->card->kind], kinds[i - 1]))
			kindv = kindv + (13 * i);
	}
	return (kindv);
}

/**
 * str_cmp - compares two strings
 * @s1: first str
 * @s2: second str
 *
 * Return: 0 or .
 */
int str_cmp(const char *s1, const char *s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * list_len_deck - returns length of list
 * @list: list
 *
 * Return: Length
 */
size_t list_len_deck(deck_node_t *list)
{
	size_t l = 0;

	while (list)
	{
		l++;
		list = list->next;
	}
	return (l);
}
