#include <iostream>
#include <random>

int main(){
    srand(time(0));

    int player_score = 0;
    int bot_score = 0;
    std::string player_move = "";
    std::string bot_pick = "";

    const std::string moves[3] = {"Rock", "Paper", "Scissor"};

    std::cout << "\n==============================\n";
    std::cout <<   "   Rock  Paper  Scissor\n";
    std::cout <<   "   Win 2 Rounds to win!\n";
    std::cout <<   "==============================\n\n";

    for (int round = 1; round <= 3; round++){

        if (player_score >= 2 || bot_score >= 2) break;

        std::cout << "-- Round " << round << " | You: " << player_score
                  << "  Bot: " << bot_score << " --\n";

        // Input Validation
        while (true){
            std::cout << "Enter move (Rock / Paper / Scissor): ";
            std::cin >> player_move;

            if (player_move == "Rock" || player_move == "Paper" || player_move == "Scissor") break;
            std::cout << "  Invalid input. Please enter Rock, Paper, or Scissor.\n";
        }

        // Bot Pick
        bot_pick = moves[rand() % 3];
        std::cout << "  Bot chose: " << bot_pick << "\n";

        // Score Info
        if (player_move == bot_pick){
            std::cout << "  It's a tie!\n\n";
        }
        else if ((player_move == "Rock"    && bot_pick == "Scissor") ||
                 (player_move == "Paper"   && bot_pick == "Rock")    ||
                 (player_move == "Scissor" && bot_pick == "Paper"))  {
            player_score++;
            std::cout << "  You win this round!\n\n";
        }
        else {
            bot_score++;
            std::cout << "  Bot wins this round!\n\n";
        }
    }

    // Result
    std::cout << "==============================\n";
    std::cout << "  Final Score | You: " << player_score << "  Bot: " << bot_score << "\n";
    std::cout << "==============================\n";

    if      (player_score > bot_score) std::cout << "  You win the game!\n";
    else if (bot_score > player_score) std::cout << "  Bot wins the game!\n";
    else                               std::cout << "  It's a tie!\n";

    std::cout << "==============================\n\n";
}
