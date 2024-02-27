#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <stack>

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

bool has_cycle(Node* head) {
    if (head == nullptr) {
        return false;
    }

    Node* parent = head;
    Node* child = head->next;

    while (child != nullptr && child->next != nullptr) {
        if (parent == child) {
            return true; // Found cycle
        }
        parent = parent->next;
        child = child->next->next;
    }

    return false;
}

std::size_t uniqueWordsCount(const std::string& line) {
    std::istringstream iss(line); // Get words list
    std::unordered_set<std::string> uniqueWordsSet; // Collection
    std::string word;

    while (iss >> word) {
        uniqueWordsSet.insert(word);
    }

    return uniqueWordsSet.size();
}

std::string mostOccuredWord(const std::string& line) {
    std::istringstream iss(line);
    std::unordered_map<std::string, int> wordCounts;
    std::string word;

    while (iss >> word) {
        wordCounts[word]++;
    }

    std::string mostOccuredWord;
    int maxCount = 0;

    for (const auto& pair : wordCounts) {
        if (pair.second > maxCount) {
            mostOccuredWord = pair.first;
            maxCount = pair.second;
        }
    }

    return mostOccuredWord;
}

bool isBracketsBalanced(const std::string& line) {
    std::stack<char> brackets;

    for (char ch : line) {
        if (ch == '(' || ch == '[' || ch == '{') {
            brackets.push(ch);
        }

        else if (ch == ')' || ch == ']' || ch == '}') {
            if (brackets.empty()) {
                return false; // Fail
            }

            // Check close
            if ((ch == ')' && brackets.top() == '(') ||
                (ch == ']' && brackets.top() == '[') ||
                (ch == '}' && brackets.top() == '{')) {
                brackets.pop(); // Remove if found
            }
            else {
                return false; // Not equal
            }
        }
    }

    return brackets.empty();
}

int main()
{
    std::cout << "Homework 23!" << std::endl;

    std::string line = "Hello Hey Hello Bye Hey";
    unsigned int count = uniqueWordsCount(line);
    std::cout << "Number of unique words: " << count << std::endl;

    std::string line2 = "Hello Hey Hello Bye Hey Hey";
    std::string mostOccured = mostOccuredWord(line2);
    std::cout << "Most occured word: " << mostOccured << std::endl;

    std::string line3 = "{ [()][ ] }()";
    std::string line4 = "[{]}";

    std::cout << "Line3 is " << (isBracketsBalanced(line3) ? "balanced" : "not balanced") << std::endl;
    std::cout << "Line4 is " << (isBracketsBalanced(line4) ? "balanced" : "not balanced") << std::endl;

    Node* node1 = new Node(5);
    Node* node2 = new Node(5);
    Node* node3 = new Node(5);

    node1->next = node2;
    node2->next = node3;
    node3->next = node1;

    std::cout << "Has cycle: " << (has_cycle(node1) ? "Yes" : "No") << std::endl;
}
