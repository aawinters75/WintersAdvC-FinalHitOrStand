#include <iostream>


using namespace std;

void HitOrStand(int pScore, int dScore) {

    
    int dhandSum = dScore;
    int phandSum = pScore;
    int pHit = 0;
    int pStand = 0;
    bool playerDone = false;
    bool dealerDone = false;

    if (dhandSum == 21)
    {
        cout << "Dealer has blackjack. Dealer wins.\n";
        return;
    }
    else if (phandSum == 21)
    {
        cout << "Player has blackjack. Player wins.\n";
        return;
    }

    while (dealerDone == false || playerDone == false)
    {
        if (playerDone == false)
        {
            cout << "Player Score is: ";
            cout << phandSum << endl;
            cout << "Would you like to hit? (1 - Yes, 2 - No)\n";
            cin >> pHit;

            if (pHit == 1)
            {
                ///////////////////////////////////////////////////////////////////////////////////////////////////////////
                //NEED LOGIC TO ADD CARDS
                int newCard = 2;
                phandSum = phandSum + newCard;
                ////////////////////////////////////////////////////////////////////////////////////////////////////////////
                if (phandSum > 21)
                {
                    cout << "Player's hand exceeded 21. Player loses.\n";
                    return;
                }
            }
        }

        if (playerDone == false)
        {
            cout << "Player Score is: ";
            cout << phandSum << endl;
            cout << "Would you like to stand? (1 - Yes, 2 - No)\n";
            cin >> pStand;
        }

        if (pStand == 1)
        {
            playerDone = true;
        }

        if (dhandSum < 17 && dealerDone != true)
        {
            ///////////////////////////////////////////////////////////////////////////////////////////////////////////
               //NEED LOGIC TO ADD CARDS
            int newCard = 2;
            dhandSum = dhandSum + newCard;
            ////////////////////////////////////////////////////////////////////////////////////////////////////////////

            if (dhandSum > 21)
            {
                cout << "Dealer hand exceeded 21. Dealer loses.\n";
                return;
            }
        }
        else if (dhandSum >= 17)
        {
            dealerDone = true;
        }

        if (phandSum == 21 && dhandSum == 21)
        {
            cout << "Push, player and dealer reached 21.\n";
            return;
        }
        else if (phandSum == 21)
        {
            cout << "Player reached 21. Player wins.\n";
            return;
        }
        else if (dhandSum == 21)
        {
            cout << "Dealer reached 21. Dealer wins.\n";
            return;
        }

        if ((playerDone == true && dealerDone == true))
        {
            if (dhandSum < phandSum)
            {
                cout << "Sum of your hand exceeds the dealer's sum of " << dhandSum << "! You win!";
                return;
            }
            else if (phandSum == dhandSum)
            {
                cout << "Dealer sum of " << dhandSum << " is equal to the sum of your hand. Tie game.";
                return;
            }
            else if (dhandSum > phandSum)
            {
                cout << "Sum of your hand is lower than the dealer's sum of " << dhandSum << ". You lose!";
                return;
            }
        }
    }
}




int main()
{
    int pScore = 14;
    int dScore = 16;
    HitOrStand(pScore, dScore);
}

