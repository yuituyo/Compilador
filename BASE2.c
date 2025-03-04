// C program to illustrate the implementation of lexical
// analyser

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define TEXTOLARGO 600

// this function check for a delimiter(it is a piece of data
// that seprated it from other) to peform some specif case
// on it
bool esDelimitador(char chr)
{
    return (chr == ' ' || chr == '+' || chr == '-'
            || chr == '*' || chr == '/' || chr == ','
            || chr == '%'  );
}

// this function check for a valid identifier eg:- +,-* etc
bool esOperador(char chr)
{
    return (chr == '+' || chr == '-' || chr == '*'
            || chr == '/'
            || chr == '=');
}

// this function check for an valid identifier
bool isValidIdentifier(char* str)
{
    return (str[0] != '0' && str[0] != '1' && str[0] != '2'
            && str[0] != '3' && str[0] != '4'
            && str[0] != '5' && str[0] != '6'
            && str[0] != '7' && str[0] != '8'
            && str[0] != '9' && !esDelimitador(str[0]));
}

// 32 Keywords are checked in this function and return the
// result accordingly
/*
bool isKeyword(char* str)
{
    const char* keywords[]
        = { "auto",     "break",    "case",     "char",
            "const",    "continue", "default",  "do",
            "double",   "else",     "enum",     "extern",
            "float",    "for",      "goto",     "if",
            "int",      "long",     "register", "return",
            "short",    "signed",   "sizeof",   "static",
            "struct",   "switch",   "typedef",  "union",
            "unsigned", "void",     "volatile", "while" };
    for (int i = 0;
         i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}
*/


bool esMayor(char* str)
{
    const char* keywords[] = { ">"};
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esMenor(char* str)
{
    const char* keywords[] = { "<"};
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esDiferente(char* str)
{
    const char* keywords[] = { "!=" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esO(char* str)
{
    const char* keywords[] = {"||" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esY(char* str)
{
    const char* keywords[] = {  "&&" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esComillas(char* str)
{
    const char* keywords[] = { "\"" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esLlaveDer(char* str)
{
    const char* keywords[] = { "}" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esLlaveizq(char* str)
{
    const char* keywords[] = { "{" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esPuntocoma(char* str)
{
    const char* keywords[] = { ";" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esCorder(char* str)
{
    const char* keywords[] = { "]" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esCorizq(char* str)//Por alguna razon maraca el " como corizq
{
    const char* keywords[] = { "[" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esIgual(char* str)
{
    const char* keywords[] = { "=" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esParder(char* str)
{
    const char* keywords[] = { ")" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esParizq(char* str)
{
    const char* keywords[] = { "(" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esCiclo(char* str)
{
    const char* keywords[] = { "while" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esPregunta(char* str)
{
    const char* keywords[] = { "if" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esEntero(char* str)
{
    const char* keywords[] = { "int" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esFlotante(char* str)
{
    const char* keywords[] = { "float" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esLectura(char* str)
{
    const char* keywords[] = { "Read" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esImpresion(char* str)
{
    const char* keywords[] = { "Print" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

bool esOtro(char* str)
{
    const char* keywords[] = { "else" };
    for (int i = 0;i < sizeof(keywords) / sizeof(keywords[0]); i++) 
    {
        if (strcmp(str, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}

// check for an integer value
bool isInteger(char* str)
{
    if (str == NULL || *str == '\0') {
        return false;
    }
    int i = 0;
    while (isdigit(str[i])) {
        i++;
    }
    return str[i] == '\0';
}

// trims a substring from a given string's start and end
// position
char* getSubstring(char* str, int start, int end)
{
    int length = strlen(str);
    int subLength = end - start + 1;
    char* subStr
        = (char*)malloc((subLength + 1) * sizeof(char));
    strncpy(subStr, str + start, subLength);
    subStr[subLength] = '\0';
    return subStr;
}

// this function parse the input
int lexicalAnalyzer(char* input)
{
    int left = 0, right = 0;
    int len = strlen(input);

    while (right <= len && left <= right) {
        if (!esDelimitador(input[right]))
            right++;

        if (esDelimitador(input[right]) && left == right) {
            if (esOperador(input[right]))
                printf("Token: Operator, Value: %c\n",
                       input[right]);

            right++;
            left = right;
        }//Es el orden de chequeo de palabras
        else if (esDelimitador(input[right]) && left != right
                 || (right == len && left != right)) {
            char* subStr
                = getSubstring(input, left, right - 1);

            if (esCiclo(subStr))
                printf("Token: Ciclo, Value: %s\n",subStr);

            else if (esMayor(subStr))
                printf("Token: Mayor, Value: %s\n",subStr);

            else if (esMenor(subStr))
                printf("Token: Menor, Value: %s\n",subStr);

            else if (esDiferente(subStr))
                printf("Token: Diferente, Value: %s\n",subStr);

            else if (esY(subStr))
            printf("Token: AMD, Value: %s\n",subStr);
            
            else if (esO(subStr))
            printf("Token: OR, Value: %s\n",subStr);

            else if (esPregunta(subStr))
                printf("Token: Pregunta, Value: %s\n",subStr);
            
            else if (isInteger(subStr))
            printf("Token: Numero, Value: %s\n",subStr);

            else if (esComillas(subStr))
            printf("Token: Comillas, Value: %s\n",subStr);

            else if (esImpresion(subStr))
            printf("Token: Impresion, Value: %s\n",subStr);

            else if (esLectura(subStr))
            printf("Token: Lectura, Value: %s\n",subStr);

            else if (esFlotante(subStr))
            printf("Token: Flotante, Value: %s\n",subStr);
                    
            else if (esEntero(subStr))
            printf("Token: Entero, Value: %s\n",subStr);
            
            else if (esOtro(subStr))
                printf("Token: Otro, Value: %s\n",subStr);

            else if (esLlaveDer(subStr))
            printf("Token: Llaveder, Value: %s\n",subStr);

            else if (esLlaveizq(subStr))
            printf("Token: Llaveizq, Value: %s\n",subStr);

            else if (esParder(subStr))
            printf("Token: Parder, Value: %s\n",subStr);
                    
            else if (esParizq(subStr))
            printf("Token: Parizq, Value: %s\n",subStr);
            
            else if (esPuntocoma(subStr))
                printf("Token: PuntoComa, Value: %s\n",subStr);
            
            else if (esCorder(subStr))
            printf("Token: Corder, Value: %s\n",subStr);

            else if (esCorizq(subStr))
            printf("Token: CorIzq, Value: %s\n",subStr);

            else if (esIgual(subStr))
            printf("Token: Igual, Value: %s\n", subStr);


            else if (isValidIdentifier(subStr)
                     && !esDelimitador(input[right - 1]))
                printf("Token: Identifier, Value: %s\n",subStr);

            else if (!isValidIdentifier(subStr)
                     && !esDelimitador(input[right - 1]))
                printf("Token: Unidentified, Value: %s\n",subStr);

            left = right;
        }
    }
    return 0;
}

struct tablasymbolos
{
   
    char lexema[MAX_LENGTH];
    char tipo[MAX_LENGTH];
    int Entero;
    float Flotante;
};


struct tablasymbolos tablita[200];
int i =0;

// main function
int main()
{

    FILE *fptr;

    // Open a file in read mode
    fptr = fopen("leer.txt", "r");

    char leido[TEXTOLARGO];


    // Input 01
    while(fgets(leido, 100, fptr)) 
    {
        printf("For Expression \"%s\":\n", leido);
        lexicalAnalyzer(leido);
        printf(" \n");
    
    }





}