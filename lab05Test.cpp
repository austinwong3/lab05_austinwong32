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

    ostringstream t3;
    w2.dumpWordsSortedByWord(t3);

    string s3 = "";
    ASSERT_EQUALS(s3,t3.str());

    ostringstream t4;
    w2.dumpWordsSortedByOccurence(t4);

    string s4 = "";
    ASSERT_EQUALS(s4,t4.str());

    WordCount w3;
    w3.WordCount::addAllWords("      ");

    ASSERT_EQUALS(0,w3.getNumUniqueWords());
    ASSERT_EQUALS(0,w3.getTotalWords());

    WordCount w4;
    w4.WordCount::addAllWords("\n   \n\n\n\n\n    \n");

    ASSERT_EQUALS(0,w4.getNumUniqueWords());
    ASSERT_EQUALS(0,w4.getTotalWords());

    WordCount w5;
    w5.WordCount::addAllWords("with\nI'd words");
 
    ASSERT_EQUALS(3,w5.getNumUniqueWords());
    ASSERT_EQUALS(3,w5.getTotalWords());
    ASSERT_EQUALS(1,w5.getWordCount("i'd"));

    return 0;

}
