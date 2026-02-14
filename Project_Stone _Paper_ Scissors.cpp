#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;
enum enTypeGame { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner {Player = 1 , Computer = 2 , Draw = 3};

struct stGameResults {

    short PlayerWinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    string FinalWinner = "";

};

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;  // Return the generated random number.
}


short HowManyRound()
{
    short Number = 0;
    do {
        cout << "How Many Rounds 1 to 10 ? \n";
        cin >> Number;
    } while (Number < 1 || Number > 10);

    return Number;

}



enWinner GetRoundResult(enTypeGame  User, enTypeGame  Computer) {

    switch (User) {
    case enTypeGame::Stone: 
        if (Computer == enTypeGame::Scissors) { system("color 2F"); return enWinner::Player; }
        if (Computer == enTypeGame::Paper) { system("color 4F"); cout << "\a"; return enWinner::Computer; }
        system("color 6F"); return enWinner::Draw; // The third case (equal) inside the loop

    case enTypeGame::Paper:
        if (Computer == enTypeGame::Stone) { system("color 2F"); return enWinner::Player; }
        if (Computer == enTypeGame::Scissors) { system("color 4F"); cout << "\a"; return enWinner::Computer; }
        system("color 6F"); return enWinner::Draw; // The third case (equal) inside the loop

    case enTypeGame::Scissors:
        if (Computer == enTypeGame::Paper) { system("color 2F"); return enWinner::Player; }
        if (Computer == enTypeGame::Stone) { system("color 4F"); cout << "\a"; return enWinner::Computer; }
        system("color 6F"); return enWinner::Draw; // The third case (equal) inside the loop

      default:
        system("color 6F");
        return enWinner::Draw;
    }
}




stGameResults Numbergeams() {
    int user = 0;
    int Number = HowManyRound();

    stGameResults Result;
   int count1 =0, count2=0, count3=0;

    for (int i = 0; i < Number; i++) {
       
        cout << "\n\nRound " << i+1 << " begins :\n";
        cout << "Your choice: [1]:Stone , [2]:Paper, [3]:Scissors ?\n";
        cout << "\n-------------- Round " << i + 1 << " ------------- :\n";
        cin >> user;
        cout << "---------------------------------------\n";
        cout << "Your choice: "<< user << "\n";
        cout << "\n";
        int computer = RandomNumber(1, 3);
        cout << "Computer choice: "<<computer << "\n";
        cout << "\n";

      enWinner result = GetRoundResult((enTypeGame)user, (enTypeGame)computer); 
  
       if (result == Player) {

           
           Result.PlayerWinTimes++;
           cout << "You Won! :) \n";
       

       }
       else if (result == Computer) {

          
           Result.ComputerWinTimes++;
           cout << "You Lost! :( \n";

       }
       else {

          
           Result.DrawTimes++;
           cout << "No winner \n";
       
       }
       
 
    }//// for loop 
    
   
    cout << "\n--------------- Result ---------------\n";
        cout << "Player won times: " << Result.PlayerWinTimes << "\n";
        cout << "Computer won times: " << Result.ComputerWinTimes << "\n";
        cout << "Draw times: " << Result.DrawTimes << "\n";

        if (Result.PlayerWinTimes < Result.ComputerWinTimes) {

            Result.FinalWinner = "Final Winner: Computer\n";

        }
        else {

            Result.FinalWinner = "Final Winner: Player\n";
        }
        cout << "---------------------------------------\n";


        return Result;


}




void print(stGameResults Results) {
    cout << "Player won times: " << Results.PlayerWinTimes << endl;
    cout << "Computer won times: " << Results.ComputerWinTimes << endl;
    cout << "Draw times: " << Results.DrawTimes << endl;
    cout << "Final Winner: " << Results.FinalWinner << endl;
}





 void StartGame() {
    char playAgain;
    int roundCounter = 0;

    // 1. The "reservoir" is placed outside to collect all the results from all the times you played
    stGameResults FinalSummary;

    do {
        roundCounter++;

        // 2.Run the game and get results "this time" only
        stGameResults CurrentGame = Numbergeams();

        // 3. إضافة نتائج هذه المرة إلى "الخزان" الكلي
        FinalSummary.PlayerWinTimes += CurrentGame.PlayerWinTimes;
        FinalSummary.ComputerWinTimes += CurrentGame.ComputerWinTimes;
        FinalSummary.DrawTimes += CurrentGame.DrawTimes;

        cout << "\nDo you want to play again? (y/n): ";
        cin >> playAgain;

        system("cls");
        system("color 0F");

    } while (playAgain == 'y' || playAgain == 'Y');

    // 4. Here is the "Conclusion"; when the player makes a choice, we print the comprehensive final report.

    cout << "==========================================\n";
    cout << "       G A M E   S U M M A R Y           \n";
    cout << "==========================================\n";
    cout << "Total Times You Played The Game: " << roundCounter << endl;
    // Determining the ultimate winner based on all rounds
    if (FinalSummary.PlayerWinTimes > FinalSummary.ComputerWinTimes)
        FinalSummary.FinalWinner = "Player";
    else if (FinalSummary.ComputerWinTimes > FinalSummary.PlayerWinTimes)
        FinalSummary.FinalWinner = "Computer";
    else
        FinalSummary.FinalWinner = "Draw";
    print(FinalSummary);
    cout << "==========================================\n";
    

}






int main()
{
    srand((unsigned)time(NULL));

    StartGame();

    return 0;
}