#include <iostream>
using namespace std;

// function declarations
double calcAverage(int scores[], int students);
int highestScore(int scores[], int students);
int lowestScore(int scores[], int students);

// 3.b looping through array and calculating average score
double calcAverage(int scores[], int students)
{
    int totalScores = 0;
    for (int i = 0; i < students; i++)
    {
        totalScores = totalScores + scores[i];
    }
    return static_cast<double>(totalScores) / students; // average is a double in the output image
}
// function for highest score
int highestScore(int scores[], int students)
{
    int highest;
    highest = scores[0];
    for (int i = 1; i < students; i++)
    {
        if (scores[i] > highest)
        {
            highest = scores[i];
        }
    }
    return highest;
}

// function for lowest score
int lowestScore(int scores[], int students)
{
    int lowest;

    lowest = scores[0];

    for (int i = 1; i < students; i++)
    {
        if (scores[i] < lowest)
        {
            lowest = scores[i];
        }
    }

    return lowest;
}

int main()
{
    // 3.a) storing 5 students scores
    const int students = 5;
    int scores[students];
    int i;

    cout << "Enter the scores for " << students << " students:" << endl;
    for (int i = 0; i < students; i++)
    {
        cout << "Enter score for student " << (i + 1) << ": ";
        cin >> scores[i];
    }

    double average = calcAverage(scores, students);
    int highest = highestScore(scores, students);
    int lowest = lowestScore(scores, students);

    // 3.d displaying all the scores
    cout << "\n"
         << endl;

    cout << "Scores entered:" << endl;
    for (i = 0; i < students; i++)
    {
        cout << "Student " << (i + 1) << ": " << scores[i] << endl;
    }
    // 3.c displaying ave, highest and lowest
    cout << "\n"
         << endl;
    cout << "Average score: " << average << endl;
    cout << "Highest score: " << highest << endl;
    cout << "Lowest score: " << lowest << endl;

    cout << "\n"
         << endl;

    return 0;
}
