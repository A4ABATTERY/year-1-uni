#include <iostream>
#include <string.h>

struct multDivTable{
  double mult;
  double div;
};
void make2D(multDivTable***, int rows,int cols){
  for(int i = 0; i < rows;i++)


}
checkargs(char *rows, char *cols)()
int main(int argc, char *argv[] = '\0'){
  bool redo = 1;
  int rows, cols;
  if(argc == 3){
    checkargs(argv[1], argv[2])

  }

  do{

    multDivTable ** array = new multDivTable[rows];
    make2D(&array, rows, cols)

    std::cout << "Enter 1 or 0, to redo table" << '\n';
    std::cin >> redo;
    if(redo){
      std::cout << "Enter rows: ";
      std::cin >> rows;
      std::cout << "\nEnter cols: ";
      std::cin >> cols;
    }
  }while(Redo)


}
