#include<iostream>
#include<string>
using namespace std;

//ф-ия вырезающая из текста кусок от одного указанного индекса до другого
//принимает такие аргументы как обрезаемая строка, начальная позиция обрезки, конечная позиция
string tcut(string line, int start, int end) {
    string res = "";
    
    for (int i = start; i < end; i++) {
        res += line[i];
    }
    
    return res;
}

int main() {
    string sent; //переменная текста
    getline(cin, sent, '\n'); //ввод текста
    
    char marked[] = "bcdfghjklmnpqrstvwxz"; //массив согласных букв
    int len = sizeof(marked) / sizeof(marked[0]); //размер массива согласных букв
    
    int starter = 0; //переменная, хранящая индекс, с которого начинается слово в строке
    for (int i = 0; i < sent.size(); i++) { //цикл обработки текста
        if (sent[i + 1] == ' ' || i + 1 == sent.size()) { //является ли символ пробелом или последним в тексте
            bool flag = false; //переменная-флаг
            
            for (int k = 0; k < len; k++) { //цикл перебора массива согласных букв
                if (marked[k] == sent[i]) { //если буквы из массива равны последней букве в слове
                    
                    cout << tcut(sent, starter, i + 1) << endl; //обрезаем строку и выводим только нужное нам слово
                    
                    starter = i + 2; //смещаем позицию, от куда будет начато следующее слово
                    flag = true; //условие в ифе выполняется, значит это надо отметить флагом
                    break;
                }
            }
            if (!flag) starter = i + 2; //если условие не было выполнено, не делаем ничего, кроме смещения позиции начала слова
        }
    }
    
    return 1;
}