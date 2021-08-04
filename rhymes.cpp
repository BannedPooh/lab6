#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <cctype>
using namespace std;

string last_word(string line);
bool word_end_compare(string w1, string w2);
string word_clean_up(string str);

int main()
{
    ifstream in_stream;
    string filename;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout<<"Enter filename: ";
    cin>>filename;
    // cout<<endl;
    // filename = "MyPoem.txt";
    in_stream.open(filename);
    if (in_stream.fail())
    {
        cerr<<"Input file opening failed.\n";
        exit(1);
    }

    string previous_line, current_line;
    int nu = 0;
    int pairs=0;
    getline(in_stream, previous_line);

    if(!previous_line.empty())
    {
        nu++;
        while (!in_stream.eof())
        {
            getline(in_stream, current_line);
            if (current_line.empty())
            {
                continue;
            }
            // cout<<"L: "<<current_line<<endl;
            string previous_wd = last_word(word_clean_up(previous_line));
            string current_wd = last_word(word_clean_up(current_line));

            if (word_end_compare(previous_wd, current_wd))
            {
                pairs++;
                cout<<previous_wd<<" and "<<current_wd<<endl;
            }

            nu++;
            previous_line = current_line;
        }
    }

    if (pairs > 1)
    {
        cout<<"There are "<<pairs<<" pairs of rhyming words."<<endl;
    }
    else if (pairs == 1)
    {
        cout<<"There is 1 pair of rhyming words."<<endl;
    }
    else
    {
        cout<<"No rhymes found."<<endl;
    }

    if (nu > 1)
    {
        cout<<"There are "<<nu<<" lines in this poem";
    }
    else if (nu == 1)
    {
        cout<<"There is 1 line in this poem";
    }
    else
    {
        cout<<"There is 0 line in this poem";
    }

    if (pairs > 0)
    {
        cout<<", so the rhyme-line density is: "<<double(pairs)/double(nu)<<endl;
    }
    else
    {
        cout<<".\n";
    }

    return 0;
}


string word_clean_up(string str)
{
    string new_str;
    for (int i = 0; i!=str.size(); ++i)
    {
        if(isalpha(str[i]) || isspace(str[i]))
        {
            new_str += str[i];
        }
    }
    return new_str;
}

bool word_end_compare(string w1, string w2)
{
    if (w1.size() <2 || w2.size() <2)
        return false;

    return w1.substr(w1.size()-2, 2) == w2.substr(w2.size()-2, 2);
}

string last_word(string line)
{
    if (line.empty())
    {
        return "";
    }
    string wd;
    int pos;
    bool met_space_before = false;
    for (int i = line.size()-1; i!=0; --i)
    {
        if (!met_space_before && isspace(line[i]))
        {
            continue;
        }
        else if(isspace(line[i]))
        {
            pos = i+1;
            break;
        }
        else{
            met_space_before = true;
        }
    }

    for (int i = pos; i!=line.size(); ++i)
    {
        if (isalpha(line[i]))
            wd+=line[i];
    }
    return wd;
}
