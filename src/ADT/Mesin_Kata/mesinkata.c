#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = NEWLINE */
    while (currentChar == BLANK)
    {
        ADV();
    }
}

void IgnoreBlanksFile()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = NEWLINE */
    while ((currentChar == BLANK || currentChar == NEWLINE) && !endOfFile)
    {
        ADVFile();
    }
}

void STARTWORD()
{
    /* I.S. : currentChar sembarang
       F.S. : endWord = true, dan currentChar = NEWLINE;
              atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
              currentChar karakter pertama sesudah karakter terakhir kata */
    START();
    IgnoreBlanks();
    EndWord = (GetCC() == NEWLINE || GetCC() == BLANK);
    if (!EndWord) {
        ADVWORD();
    }
}

void ADVWORD()
{
    /* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
       F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
              currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
              Jika currentChar = MARK, endWord = true.
       Proses : Akuisisi kata menggunakan procedure CopyWord */
    IgnoreBlanks();
    EndWord = (GetCC() == NEWLINE || GetCC() == BLANK);
    if(!EndWord){
        CopyWord();
    }
}

void CopyWord()
{
    /* Mengakuisisi kata, menyimpan dalam currentWord
       I.S. : currentChar adalah karakter pertama dari kata
       F.S. : currentWord berisi kata yang sudah diakuisisi;
              currentChar = BLANK atau currentChar = MARK;
              currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
              Jika panjang kata melebihi CAPACITY, maka sisa kata terpotong */
    int i = 0;
    while(GetCC()!=NEWLINE && GetCC()!=BLANK && i<NMax){
        currentWord.TabWord[i] = GetCC();
        ADV();
        i++;
    }
    currentWord.TabWord[i] = '\0';
    currentWord.Length = i;
}

boolean isEndWord() {
    return EndWord;
}

void StartFileWord(char* input){
    StartReadFile(input);
    IgnoreBlanksFile();
    if (currentChar == BLANK || currentChar == NEWLINE || endOfFile)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordFileNewLine();
    }
}

void ADVFileWordSpace()
{
    IgnoreBlanksFile();
    for(int i = 0; i < currentWord.Length; i++){
        currentWord.TabWord[i] = ' ';
    }
    currentWord.Length = 0;

    if (currentChar == BLANK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordFileSpace();
    }
}

void ADVFileWordNewLine()
{
    IgnoreBlanksFile();
    for(int i = 0; i < currentWord.Length; i++){
        currentWord.TabWord[i] = ' ';
    }
    currentWord.Length = 0;

    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordFileNewLine();
    }
}

void CopyWordFileSpace()
{
    currentWord.Length = 0;
    while (currentChar != BLANK && !endOfFile)
    {
        if (currentWord.Length < NMax-1)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADVFile();
        }
        else
            break;
    }
    currentWord.TabWord[currentWord.Length] = '\0';
    //printf("==%s %d\n", currentWord.TabWord, currentWord.Length);
}

void CopyWordFileNewLine()
{
    currentWord.Length = 0;
    while (currentChar != NEWLINE && !endOfFile)
    {
        if (currentWord.Length < NMax-1)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADVFile();
        }
        else {
            break;
        }
    }
    currentWord.TabWord[currentWord.Length] = '\0';
    //printf("==%s %d\n", currentWord.TabWord, currentWord.Length);
}

void StartWordNewLine(){
    StartReadNewLine();
    IgnoreBlanks();
    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordNewLine();
    }
}

void StartWordSpace(){
    StartReadNewLine();
    IgnoreBlanks();
    if (currentChar == BLANK || currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordSpace();
    }
}

void ADVWordNewLine()
{
    IgnoreBlanks();
    for(int i = 0; i < currentWord.Length; i++){
        currentWord.TabWord[i] = '\n';
    }
    currentWord.Length = 0;

    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordNewLine();
    }
}

void ADVWordSpace()
{
    IgnoreBlanks();
    for(int i = 0; i < currentWord.Length; i++){
        currentWord.TabWord[i] = ' ';
    }
    currentWord.Length = 0;

    if (currentChar == BLANK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWordSpace();
    }
}

void CopyWordNewLine()
{
    currentWord.Length = 0;
    while (currentChar != NEWLINE)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADVNewLine();
        }
        else
            break;
    }
}

void CopyWordSpace()
{
    currentWord.Length = 0;
    while (currentChar != BLANK)
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADVNewLine();
        }
        else {
            break;
        }
    }
}

int wordToInt(Word word) {
    int number = 0;
    for (int i = 0; i < word.Length; i++) {
        number = number * 10 + (word.TabWord[i] - '0');
    }
    return number;
}

boolean compareWordToString(Word word, char* string) {
    int stringLength = 0;
    char temp[50];

    for (int i = 0; string[i] != '\0'; i++){
        stringLength++;
    }

    for (int i = 0; i < word.Length; i++){
        if (word.TabWord[i] != ' '){    
            if (word.TabWord[i] >= 'a' && word.TabWord[i] <= 'z'){
                temp[i] = word.TabWord[i] - 32;
            }else {
            temp[i] = word.TabWord[i];
            }
        }
        
    }

    if (word.Length == stringLength) {
        for (int i = 0; i < word.Length; i++){
            if(temp[i] != string[i]){
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

void readString(char* buffer, int bufferSize) {
    StartWordNewLine(); 
    int index = 0;

    while (!isEndWord() && index < bufferSize - 1) { 
        for (int i = 0; i < currentWord.Length && index < bufferSize - 1; i++) {
            buffer[index++] = currentWord.TabWord[i];
        }
        ADVWordNewLine(); 

        if (!isEndWord() && index < bufferSize - 1) {
            buffer[index++] = ' '; 
        }
    }

    buffer[index] = '\0';
}