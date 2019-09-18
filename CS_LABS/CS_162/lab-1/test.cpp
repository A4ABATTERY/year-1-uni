#include <iostream>
#include <stdlib.h>
#include <iomanip>

//using namespace multdivTable::operator;

struct multdivTable{
  int mult;
  float div;
};

void free_2D_mem(multdivTable** array, int rows) {
	for(int i = 0; i < rows; i++){
			delete[]array[i];
	}
	(*array) = NULL;
	delete[]array;
	array = NULL;
}

void populateTable (multdivTable** array, int rows, int cols){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      array[i][j].mult = (i+1) * (j+1);
    }
  }
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      array[i][j].div = (float (i+1) / float (j+1));
    }
  }
}
void printtable(multdivTable** array, int rows, int cols) {
  std::cout << "\nMult Table: " << '\n';
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      std::cout << array[i][j].mult << " ";
      if (array[i][j].mult < 10)
        std::cout << " ";
    //  std::cout <<  (int(array[i][0])) * (int(array[0][j]))<< " ";
    }
    std::cout << '\n';
  }
  std::cout << "\nDiv Table: " << '\n';
  for (int i = 0; i < rows; i++){
    for (int j = 0; j < cols; j++){
      std::cout << std::fixed << std::setprecision(2) << array[i][j].div << "  ";
    }
    std::cout << '\n';
  }

}

void Make2d(multdivTable** array, int rows, int cols){
  std::cout << "run make2d" << '\n';
  for(int i = 0; i < rows; i++){
    std::cout << "Run" << i + 1 << '\n';
    array[i] = new multdivTable[cols];


  }
  std::cout << "Made 2d" << '\n';
}

multdivTable** Make_table(multdivTable*** array, int rows, int cols){
	*array = new multdivTable*[rows];
	for (int i = 0; i < rows; i++){
	 	(*array)[i] = new multdivTable[cols];
  }
	return *array;
}
int main(int argc, char* argv[]) {
	int rows; int cols; bool redo = 1;

	if (argc == 3){
		rows = atoi(argv[1]); cols = atoi(argv[2]);
  	}else{
    	std::cout << "Enter rows: ";
    	std::cin >> rows;
    	std::cout << "Enter cols: ";
    	std::cin >> cols;
  }

  do {
    multdivTable **array = new multdivTable*[rows];
    Make2d(array, rows, cols);

    populateTable(array, rows, cols);
    printtable(array, rows, cols);

	free_2D_mem(array, rows);


    std::cout << "Would you like to make a new table?";
	std::cin >> redo;
    if(redo){
      std::cout << "\nEnter rows: ";
      std::cin >> rows;
      std::cout << "\nEnter cols: ";
      std::cin >> cols;
    }
	std::cout << "\n\n\nResetting....\n\n" << '\n';
  } while(redo);

}
