// Solving Problems with Programming
// Professor Ken Bauer
//
// Sudoku

// Student Juan Francisco
// Student Number
// and
// Student Name
// Student Number

// Standard libraries
#include <iostream>
#include <cmath>
#include <fstream>
#include <Windows.h>
using namespace std;

void display(int sudoku[][9]){

  cout<<"  0 1 2  3 4 5  6 7 8  "<<endl;
  for(int row = 0 ; row<9 ; row++){
    if((row==3)||(row==6)){
      cout<<"-------+------+------"<<endl;
    }
    cout<<row;
    for(int column= 0 ; column < 9 ; column++){
      if((column==3)||(column==6)){
      cout<<"|";
    }
    cout<<" "<<sudoku[row][column];
  }
    cout<<endl;
  }
}
void erase(int sudoku[][9], int sudoku2[][9]){
  int ans;
  while(ans==0){
  cout<<endl;
  cout<<"Please choose the row of the desired number to erase: ";
  int row;
  cin>>row;
  cout<<"Please choose the column of the desired number to erase: ";
  int col;
  cin>>col;
  if(sudoku2[row][col]!=0){
    cout<<"YOU CAN'T ERASE THAT NUMBER"<<endl;
    cout<<endl;
  }
  else{
  sudoku[row][col]=0;
  }
  display(sudoku);
  cout<<"Do you wish to erase another number? (0-yes/1-no):";
  cin>>ans;
}
}
void edit(int sudoku[][9], int sudoku2[][9]){
  int ans;
  while(ans==0){
  cout<<endl;
  cout<<"Please choose the ROW of the desired number to edit: ";
  int row;
  cin>>row;
  cout<<"Please choose the COLUMN of the desired number to edit: ";
  int col;
  cin>>col;
  if(sudoku2[row][col]!=0){
    cout<<"YOU CAN'T CHANGE THAT NUMBER"<<endl;
    cout<<endl;
    display(sudoku);
  }
  else{
  cout<<"Please insert the number: ";
  int num;
  cin>>num;
  int v=0;
  int c=0;
    for(int co=0; co<9; co++){ //Checks if the number exists inside the same row
      v=v+1;
      if(num==sudoku[row][co]){
        cout<<"That # is already in use in the row!"<<endl;
        v=v-1;
      }
    }
    for(int ro=0; ro<9 ; ro++){ // Check if the number exists inside the same column
      c=c+1;
      if(num==sudoku[ro][col]){
        cout<<"That # is already in use in the column!"<<endl;
        c=c-1;
      }
    }
  if((v==9)&&(c==9)){ // If it doesnt exists in the row or column, then the player can use the number 
  sudoku[row][col]=num;
  }
  display(sudoku);
  }
  cout<<"Do you wish to edit another number? (0-yes/1-no):";
  cin>>ans;
}
}
// void square1(int sudoku[][9], int row, int col, int num){
//  int k1=0;
//  int j1=0;
//  for(int co=0; co<3;co++){
//    k1=k1+1;
//    if(num==sudoku[row][co]){
//      cout<<"That # is already in use in the row!"<<endl;
//      k1=k1-1;
//    }
//  }
//  for(int ro=0; ro<3 ; ro++){ // Check if the number exists inside the same column
//    j1=j1+1;
//    if(num==sudoku[ro][col]){
//      cout<<"That # is already in use in the column!"<<endl;
      //j1=j1-1;
    //}
  //}
  ////  
//    }
//  }
//}
void option(int sudoku[][9], int sudoku2[][9]){
  int ans;
  while(ans==0){
  cout<<endl;
  cout<<"Please choose an option you wish do perform:"<<endl;
  cout<<"1-Edit a cell, 2-Erase a cell, 3-Display Board, 4-Quit program: ";
  int opt;
  cin>>opt;
  switch(opt){
    case 1:
      edit(sudoku,sudoku2);
    break;
    case 2:
      erase(sudoku,sudoku2);
    break;
    case 3:
      display(sudoku);
    break;
    case 4:
      cout<<"Thank you for playing!";
      ans=1;
    break;
    default:
      cout<<"That was not a valid option";
      cout<<endl;
      break;
  }
}
}
int main(){
  int sudoku[9][9]= {{5,3,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},{8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},{0,6,0,0,0,0,2,8,0},{0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9}};
  int sudoku2[9][9]= {{5,3,0,0,7,0,0,0,0},{6,0,0,1,9,5,0,0,0},{0,9,8,0,0,0,0,6,0},{8,0,0,0,6,0,0,0,3},{4,0,0,8,0,3,0,0,1},{7,0,0,0,2,0,0,0,6},{0,6,0,0,0,0,2,8,0},{0,0,0,4,1,9,0,0,5},{0,0,0,0,8,0,0,7,9}};

  display(sudoku);
  option(sudoku,sudoku2);

  return 0;
}
