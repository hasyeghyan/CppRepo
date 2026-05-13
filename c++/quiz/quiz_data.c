#define MAX_QUESTIONS 5
#define MAX_TEXT_LEN 100
#define MAX_OPTION_LEN 50

char questions[MAX_QUESTIONS][MAX_TEXT_LEN] = {
     "What is the capital of Armenia?",
     "What is 5 * 5?",
     "Which is the highest mountain in the world?",
     "Who is Charles Aznavour?",
     "Who painted Mona Lisa?",
};

char optionsA[MAX_QUESTIONS][MAX_OPTION_LEN] = {"Yerevan", "49", "Aragats", "Painter", "Pablo Picasso"};
char optionsB[MAX_QUESTIONS][MAX_OPTION_LEN] = {"Rome", "16", "Khustup", "Singer", "Michelangelo"};
char optionsC[MAX_QUESTIONS][MAX_OPTION_LEN] = {"Madrid", "4", "Everest", "Dancer", "Leonardo da Vinci"};
char optionsD[MAX_QUESTIONS][MAX_OPTION_LEN] = {"Barcelona", "25", "Elbrus", "Programmer", "Vincent van Gogh"};

char correctAnswers[MAX_QUESTIONS] = {'A', 'D', 'C', 'B', 'C'};


