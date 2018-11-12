#include "WordCount.h"

#include <iostream>
#include <sstream>
#include "tddFuncs.h"
using namespace std;

int main() {
    WordCount w;
    w.WordCount::addAllWords("sentence is a sentence");

    ASSERT_EQUALS(3,w.getNumUniqueWords());
    ASSERT_EQUALS(4,w.getTotalWords());
    ASSERT_EQUALS(2,w.getWordCount("sentence"));

    ostringstream t1;
    w.dumpWordsSortedByWord(t1);

    string s1 = "A,1\nIS,1\nSENTENCE,2\n";
    ASSERT_EQUALS(s1,t1.str());

    ostringstream t2;
    w.dumpWordsSortedByOccurence(t2);

    string s2 = "SENTENCE,2\nA,1\nIS,1\n";
    ASSERT_EQUALS(s2,t2.str());

    //next word count
    WordCount w1;
    w1.WordCount::addAllWords(" sentence   \n\n  is -- a  \n sentence\n  ");

    ASSERT_EQUALS(3,w1.getNumUniqueWords());
    ASSERT_EQUALS(4,w1.getTotalWords());
    ASSERT_EQUALS(2,w1.getWordCount("sentence"));

    WordCount w2;
    w2.WordCount::addAllWords("");

    ASSERT_EQUALS(0,w2.getNumUniqueWords());
    ASSERT_EQUALS(0,w2.getTotalWords());


    return 0;

}
