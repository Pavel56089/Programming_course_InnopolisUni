#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector <string> divide_sentences(string line){
    vector <string> sentences;
    int i = 0;
    while (i < line.size()) {
        if (line[i] == ' ' || line[i] == '\t') {
            i++;
        }else{
            int start = i;
            while (line[i] != '.' && i + 1 < line.size())
                i++;
            int end = i;

            sentences.push_back(line.substr(start, end - start + 1));
            i++;
        }
    }
    return sentences;
}

vector <string> findAndUp(vector <string> sentences, int n, string word){
    vector <string> newsentences;
    string newsentence;
    int countw = 0, counts = 0;
    for (string sentece: sentences){
        string::size_type start_pos = 0;
        newsentence = sentece;
        string upword = word;
        transform(upword.begin(), upword.end(),upword.begin(), ::toupper);
        while( std::string::npos !=
               ( start_pos = sentece.find( word, start_pos ) ) )
        {
            for(int j = 0;j<word.length();j++){
                newsentence[start_pos + j] = upword[j];
            }
            ++start_pos;
            countw++;
        }
        if (countw > 0){
            counts++;
            newsentences.push_back(newsentence);
        }
        countw = 0;
    }
    return newsentences;
}


int main() {
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    vector <string> sentences;
    vector <string> newsentences;
    string word;
    string line;

    int n = 0;


    //Get line
    getline(fin, line, '\n');

    //Get sentences
    sentences = divide_sentences(line);
    fin >> n;

    for (int i=0;i<n;i++){
        fin >> word;
        newsentences = findAndUp(sentences, n, word);
        fout << newsentences.size() << endl;
        for (string news: newsentences){
            fout << news << endl;
        }
        newsentences.clear();
    }
}
