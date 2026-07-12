// Poetry Prompts
// Sage Hardiman
// 1/21/2024
// Randomly generates a list of prompts to help inspire poems
// Inspired by "Thursday Prompt #9: Line by Line" by Mallery
    // https://wewritepoems.wordpress.com/2010/07/01/thursday-prompt-9-line-by-line/

// Includes and using statements
// Useful tools that let parts of the code work
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdlib> 

using std::cout; using std::cin; using std::endl;
using std::vector;
using std::string;
using std::pair; using std::make_pair;
using std::transform;

// Function declarations
// Functions are bit of code the program can repeated jump to and run
// The actual functions will be below main()
// The declarations tell the program they exist
int printPrompt(const vector<pair<string, int>>&, const int&);

// Code starts running here
int main()
{
    // Uses the time this starts for random number generation
    srand(time(nullptr));

    // Vectors hold a list of stuff such as strings (words/sentences)
    vector <pair<string, int>> promptList;

    // Ints hold a number with NO decimal
    // I'm using these to add features to certain prompts
    int defaultPrompt = 0;
    int notFirst = 1;

    ///////////////////////////////////////////////////////////////////////////////
    // Testing!!! Please remove later!
    // pair <vector<int>, char> testPair;
    // vector<int> testVector = {2,3};
    // testPair = make_pair(testVector, 'a');
    ///////////////////////////////////////////////////////////////////////////////

    // Preloaded prompts:
    // Kept in vectors with string, int pairs to prevent repetition
    // Consider keeping these in a function to allow easier repetition of program
    // Pairs with 0 are default and used as is
    // Pairs with 1 are user prompts and get exra weight
    promptList.push_back(make_pair("Use two metaphors", defaultPrompt));
    promptList.push_back(make_pair("Use a metaphor", defaultPrompt));
    promptList.push_back(make_pair("Write about your favorite item", defaultPrompt));
    promptList.push_back(make_pair("Write the first fun fact that comes to mind", defaultPrompt));
    promptList.push_back(make_pair("Lie", defaultPrompt));
    promptList.push_back(make_pair("Write about a time spent with a friend", defaultPrompt));
    promptList.push_back(make_pair("Tell the truth. About anything", defaultPrompt));
    promptList.push_back(make_pair("Mention a work of art and/or an artist", defaultPrompt));
    promptList.push_back(make_pair("Mention an author; they don't have to be famous", defaultPrompt));
    promptList.push_back(make_pair("Write about someone you consider family. You don't have to be related", defaultPrompt));
    promptList.push_back(make_pair("Write four lines where the last word of each rhymes", defaultPrompt));
    promptList.push_back(make_pair("Use a gerund", defaultPrompt));
    promptList.push_back(make_pair("Use the subject line of a recent email", defaultPrompt));
    promptList.push_back(make_pair("Use personification", defaultPrompt));
    promptList.push_back(make_pair("Describe your gender abstractly", defaultPrompt));
    promptList.push_back(make_pair("Complete the phrase \"_____ is stronger than \"_____\"", defaultPrompt));
    promptList.push_back(make_pair("Write about summer", defaultPrompt));
    promptList.push_back(make_pair("Make up something about someone near you", defaultPrompt));
    promptList.push_back(make_pair("Only use words that start with letters in your first name", defaultPrompt));
    promptList.push_back(make_pair("Think of a random word. Now use that as the first word in this line", defaultPrompt));
    promptList.push_back(make_pair("Write about a sport", defaultPrompt));
    promptList.push_back(make_pair("State a fact about a favorite character", defaultPrompt));
    promptList.push_back(make_pair("Ask someone for a random word to use", defaultPrompt));
    promptList.push_back(make_pair("Only use words starting with letters from your last name", defaultPrompt));
    promptList.push_back(make_pair("Choose a random noun to use", defaultPrompt));
    promptList.push_back(make_pair("Choose a random adjective to use", defaultPrompt));
    promptList.push_back(make_pair("Choose a random verb to use", defaultPrompt));
    promptList.push_back(make_pair("Choose a random number to use", defaultPrompt));
    promptList.push_back(make_pair("Choose a random adverb to use", defaultPrompt));
    promptList.push_back(make_pair("Use a pronoun", defaultPrompt));
    promptList.push_back(make_pair("Only use words you already have in your poem", notFirst));
    promptList.push_back(make_pair("Mention a day of the week", defaultPrompt));
    promptList.push_back(make_pair("Mention an animal", defaultPrompt));
    promptList.push_back(make_pair("Write about someone you haven't talked to in a long time", defaultPrompt));
    promptList.push_back(make_pair("Use an idiom", defaultPrompt));
    promptList.push_back(make_pair("Write about a mundane moment", defaultPrompt));
    promptList.push_back(make_pair("Use a line from your favorite song", defaultPrompt));
    promptList.push_back(make_pair("Use alliteration", defaultPrompt));
    promptList.push_back(make_pair("Use a simile", defaultPrompt));
    promptList.push_back(make_pair("Use an onomatopoeia", defaultPrompt));
    promptList.push_back(make_pair("Use a rhyme", defaultPrompt));
    promptList.push_back(make_pair("Use two similes", defaultPrompt));
    promptList.push_back(make_pair("Use a simile and a metaphor", defaultPrompt));
    promptList.push_back(make_pair("Write a different line of the poem in reverse", notFirst));
    promptList.push_back(make_pair("Use your least favorite color", defaultPrompt));
    promptList.push_back(make_pair("Use repetition", defaultPrompt));
    promptList.push_back(make_pair("Describe something you can't currently see", defaultPrompt));
    promptList.push_back(make_pair("Use a hyperbole", defaultPrompt));
    promptList.push_back(make_pair("Repeat a different line in your poem, but change one or two words", defaultPrompt));
    promptList.push_back(make_pair("Personify your favorite food", defaultPrompt));

    // Default number of prompts:
    int numPrompts = promptList.size();

    // Let user input prompts:
    string uPrompts = "";
    int userPrompt = -1;
    while (uPrompts != "DONE") {
        cout << "Insert a prompt you would like to add, or type \"done\". " << endl;
        getline(cin, uPrompts);

        // Check for "DONE"
        transform(uPrompts.begin(), uPrompts.end(), uPrompts.begin(), ::toupper);
        if (uPrompts != "DONE") {
            promptList.push_back(make_pair(uPrompts, userPrompt));
        }
    }

    // If they added their own, ask if they'd only like those ones.
    if(promptList.size() > numPrompts) {
        bool useDefaultLoop = false;
        do { 
            cout << "Would you like to use built in prompts (yes/no)?" << endl;
            uPrompts = "";
            getline(cin, uPrompts);

            transform(uPrompts.begin(), uPrompts.end(), uPrompts.begin(), ::toupper);

            // Check that they input yes/no
            if (uPrompts == "N" || uPrompts == "NO") {
                // Delete default prompts:
                promptList.erase(promptList.begin(), promptList.begin()+numPrompts);
                useDefaultLoop = true;
            }
            else if(!(uPrompts == "Y" || uPrompts == "YES")){
                cout << "Invalid input. Please enter \"yes\" or \"no\"." << endl;
            }
            else {
                useDefaultLoop = true;
            }
        } while(!useDefaultLoop);
        
    }

    // Ask how many prompts they would like to print
    // It cannot be bigger than the total number of prompts or less than 1
    // You should also edit it so they cannot enter invalid input
    numPrompts = 0;
    do {
        cout << "How many lines would you like to write? (Cannot be greater than "
            << promptList.size() << ")\n";
        cin >> numPrompts;

        // Check that they put in a number:
        while (cin.fail()) {
            cout << "Invalid input. Please enter a number in digits" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cout << "How many lines would you like to write? (Cannot be greater than "
                << promptList.size() << ")\n";
            cin >> numPrompts;
        }


        // Tell user that they put in an invalid amount
        if ((numPrompts > promptList.size()) || (numPrompts < 1))
            cout << "Invalid amount. " << endl;

    } while ((numPrompts > promptList.size()) || (numPrompts < 1));

    cout << endl << "Here are your prompts: " << endl;

    // Randomly print unique prompts then delete them from list
    int numPrinted = 0;
    do {
        // Call the function printPrompt() to print it
        // The function prints a prompt then tells the program which prompt was used
        // That is then deleted from the list
        promptList.erase(promptList.begin() + printPrompt(promptList, numPrinted+1));
        ++numPrinted;

    } while (numPrinted < numPrompts);

}

// Function you saw at the top
// It selects and prints each prompt
int printPrompt(const vector<pair<string, int>>& promptList, const int& numPrinted){

    int aPrompt;
    bool canPrint = false;

    do {
        // Codes for what to print:
        // -1 = user input
        // 0 = default
        // 1 = Do NOT use first
        // 2 = N/A

        aPrompt = rand() % (promptList.size());

        // Weight user input heavier than default prompts by rerolling
        if (promptList[aPrompt].second != -1) {
            aPrompt = rand() % (promptList.size());
            canPrint = true;
        }
        // Allow codes -1 and 0 to print
        if (promptList[aPrompt].second == 0 || promptList[aPrompt].second == -1){
            canPrint = true;
        }
        // Code 1 means that if it's the first prompt, it must reroll
        // These ones require other lines written already
        if (numPrinted == 1 && promptList[aPrompt].second == 1){
            canPrint = false;
        }

        // If invalid code, let it know, but still try printing anyways
        // Useful for debugging
        if (promptList[aPrompt].second < -1 || promptList[aPrompt].second > 1) {
            cout << "WARNING! INVALID INPUT CODE " << promptList[aPrompt].second << endl;
            canPrint = true;
        }

    } while(!canPrint);

    // Print then return the index of what got printed
    cout << (numPrinted) << ". " << promptList[aPrompt].first << endl;
    return aPrompt;
}
