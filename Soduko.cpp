#include<iostream>
#include<cmath>
using namespace std;

bool isSafe(int mat[][9],int i,int j,int num){
    // checking horizontally
    for(int k=0;k<9;k++){
       if(mat[i][k]==num){
        return false;
       }
       

    }

    //checking vertically
    for(int k=0;k<9;k++){
        if(mat[k][j]==num){
            return false;
        }
    }


    //checking for grid3*3
    int srow=(i/3)*3;
    int scol=(j/3)*3;
      for(int s=srow;s<=srow+2;s++){
        for(int c=scol;c<=scol+2;c++){
            if(mat[s][c]==num){
                return false;
            }
        }
      }
      return true;


}

bool sudokusolver (int mat[][9],int i,int j){
//base condn
    if(i==9){
    return true;
    }


//to go to next row
    if(j==9){
    return sudokusolver(mat,i+1,0);
    }


//if a num present
    if(mat[i][j]!=0){
     return sudokusolver(mat,i,j+1);
    }


//if no number (0) is present
   for(int num=1;num<=9;num++){
       if(isSafe(mat,i,j,num)){
        mat[i][j]=num;
            if(sudokusolver(mat,i,j+1)){             // matlab soduku solver me recurssion se 
                                                    // row =n pahuch gya hai and is true
            return true;           
            }

        mat[i][j]=0;               //BACKTRACK
                                  // here sudoku solver func me false aagya hai 
        }                            // matab kahe isSafe me jaakar num mil gya or kahe koe aur aa sakta hai
                          
    }
     return false;         // if no soln is found

 
 
 }


//now to print our solved matrix

void printmat(int arr [][9]){
    for(int o=0;o<9;o++){
       for(int r=0;r<9;r++){
       cout<< arr [o][r]<<" ";
       }
    cout<<endl;
    }
}


//Driver code
int main(){
   

   int mat[][9]={ {3, 0, 6, 5, 0, 8, 4, 0, 0},
                  {5, 2, 0, 0, 0, 0, 0, 0, 0},
                  {0, 8, 7, 0, 0, 0, 0, 3, 1},
                  {0, 0, 3, 0, 1, 0, 0, 8, 0},
                  {9, 0, 0, 8, 6, 3, 0, 0, 5},
                  {0, 5, 0, 0, 9, 0, 6, 0, 0}, 
                  {1, 3, 0, 0, 0, 0, 2, 5, 0},
                  {0, 0, 0, 0, 0, 0, 0, 7, 4},
                  {0, 0, 5, 2, 0, 6, 3, 0, 0}  };  

                  

        if(sudokusolver(mat,0,0)){  
          printmat(mat);

        }

        else{
           cout<<"no soln exists "<<endl;
        }
        

        return 0;


}