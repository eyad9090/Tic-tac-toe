//------------tic-tac-toe
#include<bits/stdc++.h>
using namespace std;
int get_integer_in_range(int range_start,int range_end);
void choose_position(int &r,int &c);
bool check_left_dig(char player);
bool check_right_dig(char player);
bool check_col(int idx,char player);
bool check_row(int idx,char player);
bool check_win(char player);
void print_grid();
void play(char player);
void initialize_game();

char grid[3][3]{
    {'.','.','.'},
    {'.','.','.'},
    {'.','.','.'}
};
int available_place=9;
int main()
{
    bool again=true;
    while(again)
    {
        char player[]{'X','O'};
        int turn=-1;
        while(available_place>0)
        {
            print_grid();
            turn=(turn+1)%2;
            cout<<"player "<<player[turn]<<" turn\n";
            play(player[turn]);
            available_place--;
            if(check_win(player[turn]))
                break;
        }
        print_grid();
        if(check_win(player[turn]))
            cout<<"Player:"<<player[turn]<<" win\n";
        else
            cout<<"tie\n";
        cout<<"----------new game-----------------------------\n";
        initialize_game();
    }
    return 0;
}


void print_grid()
{
    for(int i=1;i<=3;i++)
    {
        cout<<" "<<i;
    }
    cout<<"\n";
    for(int i=0;i<3;i++)
    {
        cout<<i+1<<" ";
        for(int j=0;j<3;j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int string_to_integer(string number)
{
    int ans=0;
    for(int i=0;i<number.size();i++)
    {
        if(number[i]>='0'&&number[i]<='9')
        {
            ans=ans*10+(number[i]-'0');
        }
        else
            return -1;
    }
    return ans;
}
int get_integer_in_range(int range_start,int range_end)
{
    string choice;
    fflush(stdin);
    getline(cin,choice);
    int ans=-1;
    while(ans==-1)
    {
        ans=string_to_integer(choice);
        if(ans>=range_start&&ans<=range_end)
        {
            return ans;
        }
        else
        {
            cout<<"Invalid\n";
            cout<<"Please enter valid number in range["
            <<range_start<<"-"<<range_end<<"]: ";
            cin>>choice;
            ans=-1;
        }
    }
}
void choose_position(int &r,int &c)
{
    while(true)
    {
        cout<<"Enter row number:";
        r=get_integer_in_range(1,3);
        cout<<"Enter column number:";
        c=get_integer_in_range(1,3);
        r--;
        c--;
        if(grid[r][c]=='.')
        {
            break;
        }
        cout<<"Invalid place already reserved\n";
    }
}

bool check_left_dig(char player)
{
    for(int i=0;i<3;i++)
    {
        if(grid[i][i]!=player)
            return false;
    }
    return true;
}
bool check_right_dig(char player)
{
    for(int i=2;i>=0;i--)
    {
        if(grid[i][i]!=player)
            return false;
    }
    return true;
}
bool check_col(int idx,char player)
{
    for(int i=0;i<3;i++)
    {
        if(grid[i][idx]!=player)
            return false;
    }
    return true;
}
bool check_row(int idx,char player)
{
    for(int i=0;i<3;i++)
    {
        if(grid[idx][i]!=player)
            return false;
    }
    return true;
}



bool check_win(char player)
{
    bool flag=false;
    for(int i=0;i<3;i++)
    {
        flag|=check_row(i,player);
        flag|=check_col(i,player);
    }
    flag|=check_right_dig(player);
    flag|=check_left_dig(player);
    return flag;
}
void play(char player)
{
    int r,c;
    choose_position(r,c);
    grid[r][c]=player;
}
void initialize_game()
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            grid[i][j]='.';
        }
    }
    available_place=9;
}
