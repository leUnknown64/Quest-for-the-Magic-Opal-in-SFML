#ifndef TRIVIA_NIGHT_H
#define TRIVIA_NIGHT_H

#include "../GlobalWrapper.h"
#include "Screen.h"

class TriviaNight : public Screen{
private:
    // Each string is the question for each problem (the | marks where to split the string)
    std::vector<std::string> questions = {"In Fight Club, Tyler Durden and the|narrator are not the same person.",
        "She is a wealthy director in New|York, a narcissist, and a|controlling mother.",
        "Which of the following is not a|phrase Tyler uses to describe|himself in Fight Club?",
        "In the film Her, what did|Theodore name his A.I. partner?",
        "Tyler gifted Marla\'s mother a 15|pound box of chocolates to make|soap out of her fat.",
        "In Mouthing the Words, who does|Thelma finally reunite with after|she gets a job at a law firm?",
        "One theory about the book Panther|says that Panther may actually be|the girl\'s father.",
        "Pick the word that does not|describe Calvin in Ruby Sparks.",
        "Calvin\'s family dislikes Ruby when|she comes by to visit them.",
        "In the book Chocky, we are told|where Chocky is from.",
        "Which of the following does|Theodore not do in the film Her?",
        "The third rule of fight club is|every fight lasts ten minutes."};
    
	// Stores the split portions of a string in the questions vector
	std::vector<std::string> splitQuestion;
    
    // Answer choices for each question
    std::vector<std::vector<std::string>> answers = {{"True", "False", "", ""}, {"Corinna", "Marla", "Vivienne", "Jane"},
        {"Hopeless drunk", "A Pawn", "Middle child", "Human Butt-wipe"},
        {"Samantha", "Abby", "Caroline", "Hannah"}, {"True", "False", "", ""}, {"Molly", "Janet", "Douglas", "Corrina"},
        {"True", "False", "", ""}, {"Sluggish", "Intelligent", "Selfless", "Renowned"}, {"True", "False", "", ""},
        {"True", "False", "", ""}, {"Plays games", "Plays volleyball", "Plays an instrument", "Stays at a cabin"},
        {"True", "False", "", ""}};

    // Correct choice number for all questions
    std::vector<int> correctAnswers = {2, 3, 1, 1, 1, 1, 1, 3, 2, 2, 2, 2};
    
    // Game logic variables
    int points, currentQuestion;
	// I have no idea why I used this, probably because the game would break without it
    bool correctAnswerChosen;

    // Function to split a string in the questions vector
    void splitString(std::string const &stringToSplit, const char delimitation);
    
	// Game logic functions
	void displayQuestion(unsigned int index);
    void clearQuestion();
    void showGameOver(sf::RenderWindow* window);
    void gameLoop(sf::RenderWindow* window);

public:
    TriviaNight();
    ~TriviaNight();

    void loadChildren(sf::Font* font);
    void update(sf::RenderWindow* window);
};

#endif
