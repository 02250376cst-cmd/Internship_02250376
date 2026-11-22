/*
 * =====================================================================================
 * File:         poker_monte_carlo.c
 * Description:  Monte Carlo simulation to estimate the probabilities of 7-card poker 
 *               hands (No Pair, One Pair, Two Pair, Three of a Kind, Full House, 
 *               and Four of a Kind) using dynamic card structures and random shuffling.
 * Course:       C for Everyone, Part 2: Structured Programming
 * Assignment:   Week 2 Honors Assignment
 *
 * Compilation:  gcc -O2 poker_monte_carlo.c -o poker_monte_carlo
 * Execution:    ./poker_monte_carlo
 * =====================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 7
#define NUM_TRIALS 1000000

// Enumerated type for card suits
typedef enum {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} Suit;

// Structure representing a playing card
typedef struct {
    Suit suit;
    short pips; // 1 (Ace) through 13 (King)
} Card;

/*
 * Initializes a standard 52-card deck with sequential suits and pip values.
 */
void initialize_deck(Card deck[]) {
    int count = 0;
    for (int s = CLUBS; s <= SPADES; s++) {
        for (short p = 1; p <= 13; p++) {
            deck[count].suit = (Suit)s;
            deck[count].pips = p;
            count++;
        }
    }
}

/*
 * Shuffles an array of 52 Card structures in-place using the Fisher-Yates algorithm.
 */
void shuffle_deck(Card deck[]) {
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/*
 * Evaluates a 7-card hand strictly focusing on pip frequencies as specified in the prompt.
 * Returns:
 *   0 -> No Pair (Ace high or less)
 *   1 -> One Pair
 *   2 -> Two Pair
 *   3 -> Three of a Kind
 *   4 -> Full House
 *   5 -> Four of a Kind
 */
int evaluate_hand(const Card hand[]) {
    int pips_count[14] = {0}; // Index 1 to 13 for Ace through King

    for (int i = 0; i < HAND_SIZE; i++) {
        pips_count[hand[i].pips]++;
    }

    int pairs = 0;
    int threes = 0;
    int fours = 0;

    for (int p = 1; p <= 13; p++) {
        if (pips_count[p] == 4) fours++;
        else if (pips_count[p] == 3) threes++;
        else if (pips_count[p] == 2) pairs++;
    }

    if (fours > 0) return 5;                           // Four of a Kind
    if ((threes >= 1 && pairs >= 1) || threes >= 2) return 4; // Full House
    if (threes == 1) return 3;                        // Three of a Kind
    if (pairs >= 2) return 2;                         // Two Pair
    if (pairs == 1) return 1;                         // One Pair
    
    return 0;                                         // No Pair
}

int main() {
    // Seed the pseudo-random number generator
    srand((unsigned int)time(NULL));

    Card deck[DECK_SIZE];
    long counts[6] = {0}; // Holds hit counts for categories 0 to 5

    printf("Running Monte Carlo simulation over %d hands...\n\n", NUM_TRIALS);

    // Simulation loop
    for (int trial = 0; trial < NUM_TRIALS; trial++) {
        initialize_deck(deck);
        shuffle_deck(deck);

        Card hand[HAND_SIZE];
        for (int i = 0; i < HAND_SIZE; i++) {
            hand[i] = deck[i];
        }

        int category = evaluate_hand(hand);
        counts[category]++;
    }

    // Output mapping strictly corresponding to the target prompt table
    const char *hand_names[6] = {
        "No Pair",
        "One Pair",
        "Two Pair",
        "Three of a Kind",
        "Full House",
        "Four of a Kind"
    };

    printf("%-20s %-15s %-15s\n", "Hand", "Sim Count", "Probability");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < 6; i++) {
        double prob = (double)counts[i] / NUM_TRIALS;
        printf("%-20s %-15ld %-15.6f\n", hand_names[i], counts[i], prob);
    }

    return 0;
}