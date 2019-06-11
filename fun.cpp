#include "fun.h"

void fix(string &wor)
{
    std::transform(wor.begin(), wor.end(), wor.begin(), ::tolower);
    wor.erase (std::remove_if (wor.begin (), wor.end (), ispunct), wor.end ());
}
bool ifurl(string wor)
{
    string pattern = "https?:\\/\\/(www\\.)?[-a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)";
    std::regex url_regex(pattern);
    if (std::regex_match(wor, url_regex) == true)
    {
        return true;
    }
    else
    {
        string pattern1 ="[-a-zA-Z0-9@:%._\\+~#=]{2,256}\\.[a-z]{2,6}\\b([-a-zA-Z0-9@:%_\\+.~#?&//=]*)";
        std::regex url_regex(pattern1);
        if (std::regex_match(wor, url_regex) == true)
        {
            return true;
        }
        return false;
    }
}

/*
void lithuanianletters(string &wor)
{
    for(int i=0;i<wor.length();i++)
    {
        if(wor[i]=='Ą')
            wor[i]='à';
        else if(wor[i]=='È')
            wor[i]='è';
        else if(wor[i]=='Æ')
            wor[i]='æ';
        else if(wor[i]=='Ë')
            wor[i]='ë';
        else if(wor[i]=='Á')
            wor[i]='á';
        else if(wor[i]=='Ð')
            wor[i]='ð';
        else if(wor[i]=='Ø')
            wor[i]='ø';
        else if(wor[i]=='Û')
            wor[i]='û';
        else if(wor[i]=='Þ')
            wor[i]='þ';
    }

}*/
void sort(Words &word)
{
    std::sort(word.w.begin(), word.w.end());

}
void read(Words &word)
{
    ifstream fd("text1.txt");
   string line;
    int eil = 1;
    string wor;
    std::getline(fd, line);
    while (std::getline(fd, line))
    {
        std::istringstream reading(line);
        while(reading >> wor)
        {

            if(ifurl(wor)==true)
            {
                word.url.push_back(wor);
            }
            else
            {
                fix(wor);
                //lithuanianletters(wor);
                int n=0;
                if(eil!=0)
                {
                    for(int i=0;i<word.w.size();i++)
                    {
                        if(wor==word.w[i])
                            n++;
                    }
                }

                if(n==0)
                {
                    word.w.push_back(wor);
                }


                word.word_map[wor]++;
                word.where_map[wor].push_back(eil);
            }
        }
        eil++;
    }
    sort(word);
}
void write(Words &word)
{
    ofstream fr("results.txt");
    int d=0;
    for(auto w:word.w)
    {
        if(d<word.word_map[w])
            d=word.word_map[w];
    }

    for(int i=2;i<=d;i++)
    {
        for(auto w: word.w)
        {
            if(word.word_map[w]==i)
            {
                fr << w  << " => " << word.word_map[w] << " |  ";

                for(auto elem: word.where_map[w])
                {
                        fr << elem << " ";
                }
                fr << endl;
            }

        }
    }
    /*
    for(int i=0;i<word.w.size();i++)
    {
        if(word.word_map[word.w[i]]>1)
        {
            fr << word.w[i] << " => " << word.word_map[word.w[i]] << " |  ";

            for(auto elem: word.where_map[word.w[i]])
            {
                    fr << elem << " ";
            }
            fr << endl;
        }
    }*/
    for(auto u: word.url)
        fr << u << endl;

    fr.close();
}

