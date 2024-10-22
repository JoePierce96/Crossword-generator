#include "crossword.h"
#include <assert.h>

bool isValidCharacter(char* s, crossword* c, int sz);
char* getAcrossClues(const crossword* c, char acrossAns[]);
char* getDownClues(const crossword* c, char downAns[]);


// Might be useful to be able to print them
// to help with debugging
void print_crossword(const crossword* c)
{
// creates grid for crossword
    for(int y=0; y<c->sz; y++){
        for(int x=0; x<c->sz; x++){
            printf("%c", c->arr[y][x]);
      }
      printf("\n");
   }
}

bool str2crossword(int sz, char* ip, crossword* cw)
{
        
    int count = 0;
    
    assert(sz < GRID);
    assert(sz > 1);
    ip = "....X.XX.X.X......X.XX...";
    sz = 5;
    
    
    if (isValidCharacter(ip, cw, sz) == true) {
    
        for(int y = 0; y<cw->sz; y++) {
            for(int x = 0; x<cw->sz; x++) {
                cw->arr[y][x] = ip[count];
                count++;
                printf("%c", cw->arr[y][x]);          
            }
         
        
        return true;
        }
    } 
    
/*
   Convert a size (sz) & string (ip) into a crossword*
   White squares are ' ' or '.', black squares 'X' or '#'
*/
}


int getchecked(crossword c)
{
   int sz = GRID;
   int uncheckedCount = 0;
   int checkedCount = 0;
   int count = 0;
   
   int checked2Unchecked;
   
   for (int y; y<c.sz; y++) {
       for (int x; x<c.sz; x++) {
           if ((c.arr[x][y] == ' ' || c.arr[x][y]  == '.'))
           {
               if ((c.arr[x+1][y] == ' ' || c.arr[x+1][y]  == '.') 
                  && (c.arr[x][y+1] == ' ' || c.arr[x][y+1] == '.' ))
               {
                   ++checkedCount;
               
               }
               else if ((c.arr[x+1][y] == ' ' || c.arr[x+1][y]  == '.') 
                       && (c.arr[x][y+1] == '*' || c.arr[x][y+1] == 'X'))
               {
                   ++uncheckedCount;
                   
               }
               else if ((c.arr[x+1][y] == '*' || c.arr[x+1][y]  == 'X') 
                       && (c.arr[x][y+1] == '.' || c.arr[x][y+1] == ' '))
               {
                   ++uncheckedCount;
                   
               }
               
               else if ((c.arr[x][y+1] > c.sz + 1 
                       || c.arr[x][y-1]< c.sz - 1) 
                       || (c.arr[x+1][y] > c.sz + 1 
                       || c.arr[x-1][y]< c.sz - 1 ))
               {
                  checkedCount = checkedCount;
                  uncheckedCount = uncheckedCount;
               }
                
       
           }
       
       }       
   }
   checked2Unchecked = checkedCount / uncheckedCount * 100;
} 

void getcluestring(const crossword* c, char* ans)
{

    char acrossAns[GRID];
    char downAns[GRID];
    getAcrossClues(c, acrossAns);
    getDownClues(c, downAns);

    sprintf(ans, "%s|%s", acrossAns, downAns);

}

char* getAcrossClues(const crossword* c, char acrossAns[]) 
{
     
     int acrossCount = 1;
     acrossAns[GRID];
     int pos = 1;
     acrossAns[0] = 'A';
      
     for(int y=0; y<c->sz; y++) {
         for(int x=0; x<c->sz; x++) {
     
             if ((c->arr[x][y] == ' ' || c->arr[x][y]  == '.')) 
             {
                 acrossAns[pos] = '-';
                 acrossAns[pos+1] = (char)acrossCount;
                 pos+=2;
                
             }
            
             else if ((c->arr[x][y-1] == '*' || c->arr[x][y-1] == 'X') 
                    || (c->arr[x][y+1] == '*' || c->arr[x][y+1] == 'X')) 
             {     
                 acrossCount++;
                    
             }
             else if ((c->arr[x][y+1] > c->sz + 1) 
                     || c->arr[x][y-1]< c->sz - 1)
             {
                 acrossCount = acrossCount;
             }
         }
     }
     return acrossAns;
}

char* getDownClues(const crossword* c, char downAns[]) 
{

    int downCount = 1;
    downAns[GRID];
    int pos = 1;
    downAns[0] = 'D';
     
    
    for(int y=0; y<c->sz; y++) {
        for(int x=0; x<c->sz; x++) {
    
            if ((c->arr[x+1][y] == ' ' || c->arr[x-1][y] == '.') 
                    || (c->arr[x+1][y] == '.' || c->arr[x-1][y] == ' '))
            {        
                downAns[pos] = '-';
                downAns[pos+1] = (char)downCount;
                pos+=2; 
            
            } 
            else if ((c->arr[x+1][y] == '*' || c->arr[x-1][y] == 'X') 
                    || (c->arr[x+1][y] == 'X' || c->arr[x-1][y] == '*')) 
            {        
                downCount++;
                        
            }
            else if ((c->arr[x+1][y] > c->sz + 1) 
                    || c->arr[x-1][y]< c->sz - 1)
            {
                downCount = downCount;
            }
                
        }
    }
    return downAns;
}





bool isValidCharacter(char* s, crossword* c, int sz)
{
    if (strlen(s)== 0); {
        return false;
    }
        
    int count = 0;
    if (strlen(s) > sz) {
        return false;
    }
    
    if (sz > GRID && sz < 1) {
        return false;
    } 
    
    if ((long int)s % (long int)sz != 0)
    {
        return false;
    }
    
    else {
    
        for (int y=0; y<c->sz; y++) {
            for (int x=0; x<c->sz; x++) {
                c->arr[x][y] = s[count];
                count++;
            
                if ((int)s[count] == '0') {
                    return false;
                }
            
                if (s[count] != 'X' || '.' || ' ' || '*') {
                    return false;
                }
            }
        } 
        return true; 
    }  
      
    
}




void test(void)
{
/*
    assert(isValidCharacter("..**....**..*****", &c, 5)==true);
    assert(isValidCharacter("..***...*........", &c, 5)==true);
    assert(isValidCharacter("##..,,##,,,,,,,", &c, 5)==false);
    assert(isValidCharacter(".", &c, 1)==false);
    assert(isValidCharacter("^^$$$$$JOEPPPPPPp", &c, 5)==false);
    assert(isValidCharacter("  X    X XX X X XX X      X  XX XX         XX XX ", &c, 7)==true);
    assert(isValidCharacter("X                                               X", &c, 7)==true);
    assert(isValidCharacter("X.X.....X....X.....X............................X", &c, 7)==true);
    
    assert(getDownClues(&c, "..**....**..*****")=="D-1-2-3-4" );
    assert(getDownClues(&c, "..**....**..*****")=="A-1-3-5-6" );
*/
}

