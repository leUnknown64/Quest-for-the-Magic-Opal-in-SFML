#include "TriviaNight.h"

TriviaNight::TriviaNight(){
    // Set the current question to 0 (first one)
	// Set points to 0
	correctAnswerChosen = false;
    points = 0;
    currentQuestion = 0;
}

TriviaNight::~TriviaNight(){}

// Splits a string in the questions vector
void TriviaNight::splitString(std::string const &stringToSplit, const char delimitation){
	std::stringstream ss(stringToSplit);
    // Split portion of stringToSplit
	std::string splitPortion;

    // Tokenize the string using the delimitation character and store each part in splitQuestion
    while(std::getline(ss, splitPortion, delimitation)){
        splitQuestion.push_back(splitPortion);
    }    
}

// Displays a trivia question to the screen
void TriviaNight::displayQuestion(unsigned int index){
    // Split the current question's string, if needed
	splitString(questions[index], '|');
	// Display the question on the screen
    for(unsigned int portion = 0; portion < splitQuestion.size(); portion++){
        getText(portion)->changeString(splitQuestion[portion]);
    }
	// Clean up splitQuestion
    splitQuestion.clear();

    // Display answers choices on the screen
    getText(3)->changeString(answers[currentQuestion][0]);
    getText(4)->changeString(answers[currentQuestion][1]);
    getText(5)->changeString(answers[currentQuestion][2]);
    getText(6)->changeString(answers[currentQuestion][3]);
}

// Clears the currently displayed question
void TriviaNight::clearQuestion(){
    for(int i = 0; i < 3; i++){
        getText(i)->changeString("");
    }
}

// Display the game over screen
void TriviaNight::showGameOver(sf::RenderWindow* window){
	// Add text to the two reserved text boxes
	getText(9)->changeString("Game Over!");
    getText(10)->changeString("Press ESC to return to the game select screen");
    window->draw(getText(7)->text);
    window->draw(getText(8)->text);
    window->draw(getText(9)->text);
    window->draw(getText(10)->text);    
}

void TriviaNight::loadChildren(sf::Font* font){
    // Set up sprites
    addSprite(new SpriteObj("res/img/gameShowBG.png", sf::Vector2f(0, 0), sf::Vector2f(1, 1)));
    addSprite(new SpriteObj("res/img/imaginaryFriend.png", sf::Vector2f(20, 530), sf::Vector2f(0.7, 0.7)));
    addSprite(new SpriteObj("res/img/podium.png", sf::Vector2f(0, 560), sf::Vector2f(0.8, 0.8)));

    // Set up shapes
    addShape(new RectShapeObj(sf::Vector2f(40, 30), sf::Vector2f(950, 150), sf::Color(0,0,210), sf::Color(0,0,0), 5));
    addShape(new RectShapeObj(sf::Vector2f(220, 200), sf::Vector2f(360, 160), sf::Color(0,0,210), sf::Color(0,0,0), 5));
    addShape(new RectShapeObj(sf::Vector2f(620, 200), sf::Vector2f(360, 160), sf::Color(0,0,210), sf::Color(0,0,0), 5));
    addShape(new RectShapeObj(sf::Vector2f(220, 380), sf::Vector2f(360, 160), sf::Color(0,0,210), sf::Color(0,0,0), 5));
    addShape(new RectShapeObj(sf::Vector2f(620, 380), sf::Vector2f(360, 160), sf::Color(0,0,210), sf::Color(0,0,0), 5));

    // Initialize text (First seven are empty and reserved for a question's text and answer choices)
    addText(new TextObj(*font, "", sf::Vector2f(70, 40), 22, sf::Color(0,0,0)));
    addText(new TextObj(*font, "", sf::Vector2f(70, 90), 22, sf::Color(0,0,0)));
    addText(new TextObj(*font, "", sf::Vector2f(70, 140), 22, sf::Color(0,0,0)));
    addText(new TextObj(*font, "", sf::Vector2f(220, 200), 16, sf::Color(0,0,0)));
    addText(new TextObj(*font, "", sf::Vector2f(620, 200), 16, sf::Color(0,0,0)));
    addText(new TextObj(*font, "", sf::Vector2f(220, 380), 16, sf::Color(0,0,0)));
    addText(new TextObj(*font, "", sf::Vector2f(620, 380), 16, sf::Color(0,0,0)));

    addText(new TextObj(*font, "Points:", sf::Vector2f(400, 650), 30, sf::Color(0,0,0)));
    addText(new TextObj(*font, "0", sf::Vector2f(720, 650), 30, sf::Color(0,0,0)));
    
    // (Next two are reserved for game over screen)
    addText(new TextObj(*font, "", sf::Vector2f(350, 160), 28, sf::Color(240,0,0)));
    addText(new TextObj(*font, "", sf::Vector2f(20, 220), 18, sf::Color(0,0,0)));

    // (Last one reserved for wrong/right answer)
    addText(new TextObj(*font, "", sf::Vector2f(20, 450), 18, sf::Color(0,0,0)));

    // Set up buttons
    addButton("CHOICE_1", new Button(*font, "", sf::Vector2f(360, 160), 22, sf::Color(0,0,240), sf::Color(0,0,0), sf::Vector2f(220, 200)));
    addButton("CHOICE_2", new Button(*font, "", sf::Vector2f(360, 160), 22, sf::Color(0,0,240), sf::Color(0,0,0), sf::Vector2f(620, 200)));
    addButton("CHOICE_3", new Button(*font, "", sf::Vector2f(360, 160), 22, sf::Color(0,0,240), sf::Color(0,0,0), sf::Vector2f(220, 380)));
    addButton("CHOICE_4", new Button(*font, "", sf::Vector2f(360, 160), 22, sf::Color(0,0,240), sf::Color(0,0,0), sf::Vector2f(620, 380)));
}

// Master update function
// Continues to update the game until all questions are answered,
// then Game Over
void TriviaNight::update(sf::RenderWindow* window){
    if(currentQuestion < 12){
        gameLoop(window);
    }
    else{
        showGameOver(window);
    }
}

// Controls and updates game processes
void TriviaNight::gameLoop(sf::RenderWindow* window){
    // Render all objects to the screen
	drawChildren(window);

	// Display a question
    displayQuestion(currentQuestion);

	// Check for a button press
    if(getButton("CHOICE_1")->isPressed() || getButton("CHOICE_2")->isPressed() || getButton("CHOICE_3")->isPressed() || getButton("CHOICE_4")->isPressed()){
		if(getButton("CHOICE_"+std::to_string(correctAnswers[currentQuestion]))->isPressed()){
            correctAnswerChosen = true;
        }
        else{
			// Tell the player their answer was wrong
            getText(11)->changeString("Wrong!");

			// Go to the next question
            currentQuestion++;
            clearQuestion();

			// Deduct 2 points
            points -= 2;
			// Sleep was used to avoid breaking the game bc it updated too fast
            sf::sleep(sf::milliseconds(650));
        }
    }
    if(correctAnswerChosen){
		// Why did I make a flag for the correct choice?

		// Tell the player their answer was correct
        getText(11)->changeString("Correct!");

		// Go the the next question
        currentQuestion++;
        clearQuestion();

		// Award 5 points
        points += 5;
        sf::sleep(sf::milliseconds(650));
    }
    correctAnswerChosen = false;

    // Update points
    getText(8)->changeString(std::to_string(points));
}
