
int main(void)
{
int sz = 5;
char arr[sz][sz];
char ans[] = ". . . . #. # # . #. # . . .. . . # .# # . . .";
int count = 0;
char currentPos;

for(int y=0; y<sz; y++)
{
        for(int x=0; x<sz; x++)
        {
            arr[y][x] = ans[count];
            count++;
            currentPos = ans[count];
             
            while (ans[count]== '.' || ans[count] == ' ' )
                if (ans[count] == '.' || ans[count] == ' ')
                {
                currentPos;
                }
        }
}
}

   if (cStr[y] == '#' || cStr[y] == 'X') 
            {
               ++acrossCount;
               acrossClueCnt[count] += acrossCount; 
            }
            
           
            if (cStr[x] == '#' || cStr[x] == 'X') 
            {
                ++downCount;
                downClueCnt[count] += acrossCount;       
            }
            ++count;   
            sprintf(ans, "A-%d |D-%d", acrossClueCnt[count], downClueCnt[count]);
