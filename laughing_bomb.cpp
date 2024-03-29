//19.laughing bomb
//laughing bomb official 
#include <iostream>
using namespace std;
#define MAX_SIZE 101
int citymap[MAX_SIZE][MAX_SIZE];
int visited[MAX_SIZE][MAX_SIZE];
int Answer;
int row_size = 0;
int col_size = 0;
int bomb_row, bomb_col;

void traverse(int row, int col, int cur_value)
{
    if ((row < 1) || (row > row_size) || (col < 1) || (col > col_size))
        return;

    if (citymap[row][col] == 0)
        return;
    
    if (visited[row][col])
    {
        if(citymap[row][col] > cur_value)
            citymap[row][col] = cur_value;
        else
            return;
    }
    else
    {
        visited[row][col] = 1;
        citymap[row][col] = cur_value;
    }

    traverse(row, col+1, cur_value + 1);
    traverse(row+1, col, cur_value + 1);
    traverse(row, col-1, cur_value + 1);
    traverse(row-1, col, cur_value + 1);

    return;
}
void init()
{
    row_size = 0;
    col_size = 0;

    bomb_row = 0;
    bomb_col = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
         	citymap[i][j] = 0;
            visited[i][j] = 0;
        }
    }

    Answer = 0;
}
int main()
{
    int T;
    int i;
    int j;
    cin>>T;
    while(T--)
    {
        init();
        cin>>col_size>>row_size;

        for (i = 1; i <= row_size; i++)
            for (j = 1; j <= col_size; j++)
                cin>>citymap[i][j];

        cin>>bomb_col>>bomb_row; //these coordinates are 1-based index so if you iterate via 0-index kindly minus 1 from each coordinate
        citymap[bomb_row][bomb_col] = 1;
        traverse(bomb_row, bomb_col,1);
       
        for (i = 1; i <= row_size; i++)
            for (j = 1; j <= col_size; j++)
                if (Answer < citymap[i][j])
                    Answer = citymap[i][j];

        cout<<Answer<<endl;
    }

    return 0;//Your program should return 0 on normal termination.
}
