#include <iostream>

using namespace std;

char space[3][3]={{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

int row, col;
char token = 'x';
bool t=false;
string p1="", p2="";
void functionOne(){
    // cout << p1 <<" is player 1 so he/she will play first. \n";
    // cout << p2 <<" is player 2 so he/she will play first. \n";

    cout << "   |   |   \n";
    cout << " " << space[0][0] << " | " << space[0][1] << " | "<< space[0][2] << "  \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[1][0] << " | " << space[1][1] << " | "<< space[1][2] << "  \n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << space[2][0] << " | " << space[2][1] << " | "<< space[2][2] << "  \n";
    cout << "   |   |   \n";
}

void functionTwo(){
    int digit;
    if(token == 'x')
    {
        cout << p1 << " please Enter ";
        cin >> digit;
    }
    if(token == 'o')
    {
        cout << p2 << " please Enter ";
        cin >> digit;
    }
    if(digit==1)
    {
        row = 0;
        col = 0;
    }
    else if(digit==2)
    {
        row = 0;
        col = 1;
    }
    else if(digit==3)
    {
        row = 0;
        col = 2;
    }
    else if(digit==4)
    {
        row = 1;
        col = 0;
    }
    else if(digit==5)
    {
        row = 1;
        col = 1;
    }
    else if(digit==6)
    { 
        row = 1;
        col = 2;
    }
    else if(digit==7)
    {
        row = 2;
        col = 0;
    }
    else if(digit==8)
    {
        row = 2;
        col = 1;
    }
    else if(digit==9)
    {
        row = 2;
        col = 2;
    }
    
    else if(digit<1 || digit>9)
    {
        cout << "INVALID ";
        functionTwo();
    }
    if(token=='x' && space[row][col] !='x' && space[row][col]!='o')
    {
        space[row][col]='x';
        token='o';
    }
    else if(token=='o' && space[row][col] !='x' && space[row][col]!='o')
    {
        space[row][col]='o';
        token='x';
    }
    else{
        cout << "There is no empty space!!" << endl;
        functionTwo();
    }
}

bool functionThree()
{
    for(int i=0; i<3; i++)
    {
        if(space[i][0]==space[i][1] && space[i][1]==space[i][2])
        {
            return true;
        } 
        else if(space[0][i]==space[1][i] && space[1][i]==space[2][i])
        {
            return true;
        }
        else if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[0][2]==space[2][0])
        {
            return true;
        }
    }
    for(int i=0; i<3; i++)
    {
            for(int j=0; j<3; j++)
            {
                if(space[i][j]!='x' && space[i][j]!='o')
                {
                    return false;
                }
            }
     }

    t = true;
    return true;
}

int main(){

    cout << "Enter the name of the first palyer :\n";
    getline(cin, p1);
    cout << "Enter the name of the second palyer :\n"; 
    getline(cin, p2);

    cout << p1 <<" is player 1 so he/she will play first. \n";
    cout << p2 <<" is player 2 so he/she will play first. \n";
    bool temp = false;
    while(!temp)
    {
        functionOne();
        functionTwo();
        temp = functionThree();
    }

    if(token=='x' && t==false)
    {
        cout << p2 << " Wins!!"<< endl;
    }
    else if(token=='o'&& t==false)
    {
        cout << p1 << " Wins!!" << endl;
    }
    else{
        cout << "It's a DRAW!!" << endl;
    }
    cout << "\nGAME ENDED!!"<<endl;
    system("pause");
}